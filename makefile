# Compiler
CC = g++

# Directory
SOURCE_FOLDER = src
OUTPUT_FOLDER = bin

run: all
	@$(OUTPUT_FOLDER)/main.exe
all: build

build:
	@$(CC) $(SOURCE_FOLDER)/main.cpp $(SOURCE_FOLDER)/classes/implements/Game/game.cpp $(SOURCE_FOLDER)/classes/implements/Game/candyGame.cpp $(SOURCE_FOLDER)/classes/implements/Game/unoGame.cpp $(SOURCE_FOLDER)/classes/implements/Inventory/deckCard.cpp $(SOURCE_FOLDER)/classes/implements/Value/Card/card.cpp $(SOURCE_FOLDER)/classes/implements/Inventory/player.cpp $(SOURCE_FOLDER)/classes/implements/Value/Card/abilityCard.cpp $(SOURCE_FOLDER)/classes/implements/CardGenerator/cardGenerator.cpp $(SOURCE_FOLDER)/classes/implements/Combination/combination.cpp $(SOURCE_FOLDER)/classes/implements/Inventory/tableCard.cpp $(SOURCE_FOLDER)/classes/implements/Command/commandParser.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/next.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/double.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/half.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/reRoll.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/reverse.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/quadruple.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/quarter.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/swapCard.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/switch.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/abilityLess.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/checkCard.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/checkTableCard.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/endGame.cpp $(SOURCE_FOLDER)/classes/implements/Inventory/children/candyPlayer.cpp $(SOURCE_FOLDER)/classes/implements/Inventory/children/unoPlayer.cpp $(SOURCE_FOLDER)/classes/implements/Value/Card/unoCard.cpp $(SOURCE_FOLDER)/classes/implements/Command/commandParserUNO.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/draw.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/pass.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/sayUno.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/pickCard.cpp $(SOURCE_FOLDER)/classes/implements/Exception/exception.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/plus2.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/plus4.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/skip.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/unoReverse.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/changeColor.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/seeCards.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/help.cpp $(SOURCE_FOLDER)/classes/implements/Command/children/helpUno.cpp -o $(OUTPUT_FOLDER)/main