#include "../../../headers/Command/children/seeCards.hpp"

SeeCards::SeeCards() : Command() {}

void SeeCards::executeAction(UnoGame &unogame) {
    unogame.getPlayer(0).printCard();
}