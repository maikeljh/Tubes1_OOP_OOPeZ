# Compiler
CC = g++

# Directory
SOURCE_FOLDER = src
OUTPUT_FOLDER = bin

run: all
	@$(OUTPUT_FOLDER)/main.exe
all: build

build:
	$(CC) $(SOURCE_FOLDER)/main.cpp -o $(OUTPUT_FOLDER)/main