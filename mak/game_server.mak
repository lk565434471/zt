TARGET = bin/game_server
SRCS_DIR = game_server
SRCS = \
game_server/game_server.cpp \
game_server/object/game_object.cpp \
game_server/unit/unit.cpp \
game_server/player/player.cpp \
game_server/map/map.cpp \

LINK_TYPE = exec
INCLUDE = -Igame_server -Icommon -Idependencies -Idependencies/boost_1_73_0
BUILD_DIR = build
DEPFILE = \
build/libcommon.a

LIB = \
-Lbuild -lcommon \

include mak/main.mak