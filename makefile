# Compiler
CC = g++

# Directory
SOURCE_FOLDER = src
OUTPUT_FOLDER = bin

run: all
	@$(OUTPUT_FOLDER)/main.exe
all: build

build:
	$(CC) $(SOURCE_FOLDER)/main.cpp $(SOURCE_FOLDER)/classes/implements/Game/game.cpp $(SOURCE_FOLDER)/classes/implements/Game/candyGame.cpp $(SOURCE_FOLDER)/classes/implements/Game/unoGame.cpp $(SOURCE_FOLDER)/classes/implements/Inventory/deckCard.cpp $(SOURCE_FOLDER)/classes/implements/Card/card.cpp $(SOURCE_FOLDER)/classes/implements/Card/baseCard.cpp $(SOURCE_FOLDER)/classes/implements/Inventory/player.cpp $(SOURCE_FOLDER)/classes/implements/Inventory/inventoryHolder.cpp $(SOURCE_FOLDER)/classes/implements/Card/abilityCard.cpp $(SOURCE_FOLDER)/classes/implements/CardGenerator/cardGenerator.cpp $(SOURCE_FOLDER)/classes/implements/Combination/combination.cpp $(SOURCE_FOLDER)/classes/implements/Card/tableCard.cpp $(SOURCE_FOLDER)/classes/implements/Value/value.cpp $(SOURCE_FOLDER)/classes/implements/Command/commandParser.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/next.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/double.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/half.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/reRoll.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/reverse.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/quadruple.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/quarter.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/swapCard.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/switch.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/abilityLess.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/checkCard.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/checkTableCard.cpp -o $(OUTPUT_FOLDER)/main