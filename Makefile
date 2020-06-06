#!/bin/bash

# Makefile for 64bit build of Epsilon Engine, by Imanol Fotia
# Dependencies need to be downloaded under Windows
# For my build I'm using g++ 9.2.0

# Dependencies: 
# Bullet Physics 3
# Glew
# GLFW
# inih
# OpenAL Soft
# Lua 5.3.5
# SOIL (soon to be replaced)

CXX= g++

OBJS_DIR_RELEASE:= ./obj/Release
OBJS_DIR_DEBUG:= ./obj/Debug
SOURCE_DIR:= ./core/src
INCLUDE_DIR:= ./core/include
LIB:= thirdparty
BIN:= ./bin

ifeq "$(OS)" "Windows_NT"
EXEC := Epsilon_Engine.exe
else
EXEC := Epsilon_Engine
endif

#recursive wildcard to include all files
rwildcard=$(wildcard $(addsuffix $2, $1)) $(foreach d,$(wildcard $(addsuffix *, $1)),$(call rwildcard,$d/,$2))

SOURCES:= $(call rwildcard,$(SOURCE_DIR)/,*.cpp) #$(wildcard $(SOURCE_DIR)/**.cpp) 
INCLUDES:= $(call rwildcard,$(INCLUDE_DIR)/,*.hpp *.h)#$(wildcard $(INCLUDE_DIR)/**.hpp $(INCLUDE_DIR)/**.h)
OBJECTS_DEBUG := $(patsubst $(SOURCE_DIR)/%.cpp,$(OBJS_DIR_DEBUG)/%.o,$(SOURCES))
OBJECTS_RELEASE := $(patsubst $(SOURCE_DIR)/%.cpp,$(OBJS_DIR_RELEASE)/%.o,$(SOURCES))
RES_OBJECTS := $(OBJS_DIR)/resources.o

#- sudo add-apt-repository http://ppa.launchpad.net/keithw/glfw3/ubuntu -y
#includes for windows and linux combined

ifeq "$(OS)" "Windows_NT"
INCLUDE_LIBS:= -I$(LIB)/glm \
-I$(LIB)/bullet3/src \
-I$(LIB)/glew/include -I$(LIB)/glfw/include \
-I$(LIB)/soil/Simple\ OpenGL\ Image\ Library/src \
-I$(LIB)/openal-soft/include \
-I$(LIB)/inih/cpp \
-I$(LIB)/lua-5.3.5/src \
-I$(LIB)/stb-master
else
INCLUDE_LIBS:=  -I$(LIB)/inih/cpp \
-I$(LIB)/glm \
-I/core/include \
-I/usr/include \
-I/usr/include/bullet \
-I/usr/include/glew \
-I/usr/include/glfw \
-I/usr/include/stb \
-I/usr/include/SOIL \
-I/usr/include/inih \
-I/usr/include/lua5.3 
endif

ifeq "$(OS)" "Windows_NT"
LIBS_DIR := -L$(LIB)/soil/lib \
-L$(LIB)/glfw/build/src \
-L$(LIB)/inih \
-L$(LIB)/glew/lib \
-L$(LIB)/lua-5.3.5/src \
-L$(LIB)/openal-soft/build \
-L$(LIB)/bullet3/build/lib
else 
LIBS_DIR := -L$(LIB)/inih \
-L/usr/lib/x86_64-linux-gnu 
endif

ifeq "$(OS)" "Windows_NT"
LIBS:= -lSOIL -lglfw3dll -lopengl32 -linih -lglew32.dll -lgdi32 -lOpenAL32.dll -fopenmp -lgomp -llua -lBulletSoftBody -lBulletDynamics -lBulletCollision -lLinearMath
else 
LIBS:= -lSOIL -lglfw -linih -lGLEW -lGLU -lGL -lopenal -fopenmp -lgomp -llua5.3 -lBulletSoftBody -lBulletDynamics -lBulletCollision -lLinearMath
endif

LD_FLAGS := -fopenmp
CPPFLAGS := --std=c++17

DEBUG_FLAGS := -g -DDEBUG -ggdb -g3 -gdwarf-4 -fvar-tracking-assignments

RELEASE_FLAGS :=

RES := ./core/src/resources.rc

all: clean resource epsilon-release

epsilon-debug: resource $(BIN)/Debug/$(EXEC)

epsilon-release: resource $(BIN)/Release/$(EXEC)


ifeq "$(OS)" "Windows_NT"
resource:
	-@mkdir -p ./obj
	@windres -i $(RES) -o ./objs/resources.o
else 
resource:
	-@mkdir -p ./obj
	@objcopy --input binary --output pe-x86-64 --binary-architecture i386:x86-64 $(RES) ./objs/resources.o
endif

$(OBJS_DIR_DEBUG)/%.o: $(SOURCE_DIR)/%.cpp
	-@mkdir -p $(@D)/Debug
	$(CXX) $(INCLUDE_LIBS) -I$(INCLUDE_DIR) $(CPPFLAGS) -o $@ -c $^  $(LD_FLAGS) $(DEBUG_FLAGS)
	
$(OBJS_DIR_RELEASE)/%.o: $(SOURCE_DIR)/%.cpp
	-@mkdir -p $(@D)/Release
	$(CXX) $(INCLUDE_LIBS) -I$(INCLUDE_DIR) $(CPPFLAGS) -o $@ -c $^  $(LD_FLAGS)

$(BIN)/Release/$(EXEC): $(OBJECTS_RELEASE)
	-@mkdir -p $(@D)/Release
	$(CXX) $(CPPFLAGS) $(RELEASE_FLAGS) $(RES_OBJECTS) -o $@ $^ $(LIBS_DIR) $(LIBS) $(LD_FLAGS)

$(BIN)/Debug/$(EXEC): $(OBJECTS_DEBUG)
	-@mkdir -p $(@D)/Debug
	$(CXX) $(CPPFLAGS) $(DEBUG_FLAGS) $(RES_OBJECTS) -o $@ $^ $(LIBS_DIR) $(LIBS) $(LD_FLAGS)

clean:
	-@rm -rf ./obj/*

