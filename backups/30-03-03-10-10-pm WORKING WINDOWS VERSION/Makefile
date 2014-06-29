#Includes directory
IDIR =  -Isrc/includes -Isrc/main/header -Isrc/init/header -Isrc/command/header -Isrc/object/header -Isrc/map/header -Isrc/entity/header -Isrc/gamestate/header -Isrc/timer/header/ -Isrc/entities/GRID/ -Isrc/entities/SQUARE/ -Isrc/entities/PLAYER -Isrc/entities/DEFAULT -Isrc/entities/STAR -Isrc/glew/
#compiler
CC = g++
#compiler flags
CFLAGS = $(IDIR) -Wall -pipe -m32
#linker flags
LFLAGS = -lglew32s -lboost_system-mgw48-mt-1_55 -lmingw32 -lSDL2main -lSDL2 -lboost_thread-mgw48-mt-1_55 -lglu32 -lopengl32 -static-libgcc -static-libstdc++ -m32
#dependancys
#DEPS = 
#objs directory
ODIR = src\obj
#src files to compile
SRC = src/main/src/main.cpp src/init/src/init.cpp src/command/src/command.cpp src/object/src/object.cpp src/map/src/map.cpp src/entity/src/entity.cpp src/gamestate/src/game_state.cpp src/timer/src/timer.cpp src/entities/GRID/GRID_entity.cpp src/entities/SQUARE/SQUARE_entity.cpp src/entities/PLAYER/PLAYER_entity.cpp src/entities/DEFAULT/DEFAULT_entity.cpp src/entities/STAR/STAR_entity.cpp
#output name
OBJ_NAME = bin\game

all: $(SRC)
	$(CC) -o $(OBJ_NAME) $(SRC) $(CFLAGS) $(LFLAGS)

