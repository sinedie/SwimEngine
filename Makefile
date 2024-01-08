#OBJS specifies which files to compile as part of the project
OBJS = ./src/*.cpp main.cpp 

#CC specifies which compiler we're using
CC = g++

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -I ./src -I ./src/systems/ -I ./src/components

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = 
SHARED = -fpic -shared 

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w #-Wl,-subsystem,windows

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2main -lSDL2 -lSDL2_image

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = main

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

dll :
	$(CC) ./src/systems/*.cpp  $(INCLUDE_PATHS) $(SHARED) -o ./plugins/systems/test
	$(CC) ./src/components/*.cpp $(INCLUDE_PATHS) $(SHARED) -o ./plugins/components/test