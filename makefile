# Compiler
CC = g++

# Directory
SOURCE_FOLDER = src
OUTPUT_FOLDER = bin

run: all
	@$(OUTPUT_FOLDER)/main.exe
all: build

build:
	$(CC) $(SOURCE_FOLDER)/main.cpp $(SOURCE_FOLDER)/classes/implements/game.cpp $(SOURCE_FOLDER)/classes/implements/Inventory/deckCard.cpp $(SOURCE_FOLDER)/classes/implements/Card/card.cpp $(SOURCE_FOLDER)/classes/implements/Inventory/player.cpp $(SOURCE_FOLDER)/classes/implements/Inventory/inventoryHolder.cpp $(SOURCE_FOLDER)/classes/implements/Card/abilityCard.cpp $(SOURCE_FOLDER)/classes/implements/CardGenerator/cardGenerator.cpp $(SOURCE_FOLDER)/classes/implements/Combination/combination.cpp $(SOURCE_FOLDER)/classes/implements/Card/tableCard.cpp $(SOURCE_FOLDER)/classes/implements/Value/value.cpp -o $(OUTPUT_FOLDER)/main