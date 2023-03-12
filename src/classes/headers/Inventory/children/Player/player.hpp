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
        virtual T getCard(int index);
        void push(const T& PC);
        T pop();
        virtual void printCard() = 0;
        string getNickname();
        vector<T>& getDeckPlayer();
};

#endif