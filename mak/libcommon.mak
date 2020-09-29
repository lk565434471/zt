TARGET = build/libcommon
SRCS_DIR = common
SRCS = \
common/rapidjson/rapid_json_value.cpp \
common/rapidjson/rapid_json_node.cpp \
common/rapidjson/rapid_json_reader.cpp \
common/rapidjson/rapid_json_writer.cpp \
common/entity/object_base.cpp \
common/util/vector2d.cpp \

LINK_TYPE = static
INCLUDE = -Icommon -Idependencies
BUILD_DIR = build

include mak/main.mak