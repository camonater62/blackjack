#pragma once

#include "GenericPlayer.hpp"
#include "Hand.hpp"

class Deck : public Hand {
public:
    Deck();
    virtual ~Deck();

    // create a standard deck of 52 cards
    void Populate();

    // shuffle cards
    void Shuffle();

    // deal one card to a hand
    void Deal(Hand &aHand);

    // number of cards in the deck
    int Size();

    // give additional cards to a generic player
    void AdditionalCards(GenericPlayer &aGenericPlayer);
};
