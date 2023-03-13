#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include "../../inventoryHolder.hpp"
#include "../DeckCard/deckCard.hpp"
#include "../../../Value/Card/abilityCard.hpp"
#include "../../../Value/Combination/combination.hpp"

using namespace std;

template <class T>
class Player: public InventoryHolder<T>{
    private:
        int id;
        string nickname;
        vector<T> mainDeck;
        static int playersCreated;
    
    public:
        Player();
        Player(string nickname);
        ~Player();
        virtual T getCard(int index) = 0;
        virtual void push(const T& PC) = 0;
        virtual T pop() = 0;
        virtual void printCard() = 0;
        string getNickname();
        int getID();
        vector<T>& getDeckPlayer();
};
template class Player<Card>;
template class Player<AbilityCard>;
template class Player<UnoCard>;
#endif