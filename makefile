# Compiler
CC = g++

# Directory
SOURCE_FOLDER = src
OUTPUT_FOLDER = bin

run: all
	@$(OUTPUT_FOLDER)/main.exe
all: build

build:
	$(CC) $(SOURCE_FOLDER)/main.cpp $(SOURCE_FOLDER)/classes/implements/game.cpp -o $(OUTPUT_FOLDER)/main