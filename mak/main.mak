CC_ ?= gcc
CXX_ ?= g++
LINKER_ ?= g++
AR_ ?= ar crv
RM_ ?= rm -f
SED_ ?= sed

CFLAGS ?= -Wall -c -std=c++11 -D_POSIX_C_SOURCE=2 $(C_FLAG)
CPPFLAGS ?= -Wall -c -D_GLIBCXX_USE_CXX11_ABI=0 $(CPP_FLAG)
ELFLAGS ?= $(EL_FLAG)
DLFLAGS ?= -shared -fPIC
INCLUDES += $(INCLUDE)
LIBS += $(LIB)
DEPFILES += $(DEPFILE)

define ECHO
	@printf "\033[;32m"; printf $1; printf "\033[0m\n"
endef

define make_c_rule
$(addprefix $(BUILD_DIR), $(subst /,_, $(addsuffix .o, $(basename $1)))): $1
	@$(call ECHO, "[compiling] $$@ ...]")
	@$(CC_) -o $$@ $$(CFLAGS) $$(INCLUDES) $$<
$(addprefix $(BUILD_DIR), $(subst /,_, $(addsuffix .d, $(basename $1)))): $1
	@$(CC_) -M $$(CFLAGS) $$(INCLUDES) $$< | $(SED_) 's,^.*:,$$@ $$@:,g' | $(SED_) 's/\.d/\.o/' >$$@
	if [ ! -s $$@ ]; then rm -f $$@; fi
endef

define make_cc_rule
$(addprefix $(BUILD_DIR), $(subst /,_, $(addsuffix .o, $(basename $1)))): $1
	@$(call ECHO, "[compiling] $$@ ...]")
	@$(CXX_) -o $$@ $$(CPPFLAGS) $$(INCLUDES) $$<
$(addprefix $(BUILD_DIR), $(subst /,_, $(addsuffix .d, $(basename $1)))): $1
	@$(CXX_) -M $$(CPPFLAGS) $$(INCLUDES) $$< | $(SED_) 's,^.*:,$$@ $$@:,g' | $(SED_) 's/\.d/\.o/' >$$@
	if [ ! -s $$@ ]; then rm -f $$@; fi
endef

ifeq ($(LINK_TYPE), exec)
	ifeq ($(OS), Windows_NT)
		FINAL_TARGET = $(TARGET).exe
	else
		FINAL_TARGET = $(TARGET)
	endif
endif

ifeq ($(LINK_TYPE), dynamic)
	ifeq ($(OS), Windows_NT)
		FINAL_TARGET = $(TARGET).dll
	else
		FINAL_TARGET = $(TARGET).so
	endif
	CFLAGS += -fPIC
	CPPFLAGS += -fPIC
endif

ifeq ($(LINK_TYPE), static)
	FINAL_TARGET = $(TARGET).a
endif

.PHONY: debug release profile clean

debug: CFLAGS += -g
debug: CPPFLAGS += -g
debug: $(FINAL_TARGET)

release: CFLAGS += -g -O2 -fno-strict-aliasing
release: CPPFLAGS += -g -O2
release: $(FINAL_TARGET)

profile: CFLAGS += -g -pg
profile: CPPFLAGS += -g -pg
profile: DLFLAGS += -pg
profile: ELFLAGS += -pg
profile: $(FINAL_TARGET)

ifeq ($(BUILD_DIR),)
BUILD_DIR = ./
else
BUILD_DIR := $(BUILD_DIR)/
endif

OBJS = $(addprefix $(BUILD_DIR), $(subst /,_, $(addsuffix .o, $(basename $(SRCS)))))
DEPS = $(addprefix $(BUILD_DIR), $(subst /,_, $(addsuffix .d, $(basename $(SRCS)))))

DEL_OBJS = $(addprefix $(BUILD_DIR), $(addsuffix *.o, $(SRCS_DIR)))
DEL_DEPS = $(addprefix $(BUILD_DIR), $(addsuffix *.d, $(SRCS_DIR)))

$(FINAL_TARGET): $(OBJS) $(DEPFILES)
ifeq ($(LINK_TYPE), exec)
	@$(call ECHO, "[linking exec $(TARGET) ...]")
	@$(LINKER_) -o $(FINAL_TARGET) $(ELFLAGS) $(OBJS) $(LIBS)
else ifeq ($(LINK_TYPE), static)
	@$(call ECHO, "[linking static $(FINAL_TARGET) ...]")
	@$(AR_) $(FINAL_TARGET) $(OBJS)
else ifeq ($(LINK_TYPE), dynamic)
	@$(call ECHO, "[linking dynamic $(FINAL_TARGET) ...]")
	@$(LINKER_) -o $(FINAL_TARGET) $(DEPFILES) $(OBJS) $(LIBS)
endif

$(foreach SRC, $(filter %.c, $(SRCS)), $(eval $(call make_c_rule, $(SRC))))
$(foreach SRC, $(filter %.cpp, $(SRCS)), $(eval $(call make_cc_rule, $(SRC))))

ifneq ($(MAKECMDGOALS), clean)
	-include $(DEPS)
endif

clean:
	@$(call ECHO, "[cleaning $(FINAL_TARGET)...]")
	@$(RM_) $(OBJS) $(DEPS) $(FINAL_TARGET) $(DEL_OBJS) $(DEL_DEPS);
