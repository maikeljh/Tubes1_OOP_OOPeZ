#include "../../../headers/Command/children/seeCards.hpp"

/* Ctor */
SeeCards::SeeCards(){}

/* See the current player's cards */
void SeeCards::executeAction(UnoGame &unogame) {
    unogame.getPlayer(0).printCard();
}