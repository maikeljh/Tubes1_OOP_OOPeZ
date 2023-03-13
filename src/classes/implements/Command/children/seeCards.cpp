#include "../../../headers/Command/children/seeCards.hpp"

SeeCards::SeeCards() : Command() {}

void SeeCards::executeActionUNO(UnoGame &unogame) {
    unogame.getPlayer(0).printCard();
}