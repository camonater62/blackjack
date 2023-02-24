#include "Card.hpp"

#include <iostream>

using namespace std;

Card::Card(rank r, suit s, bool ifu)
    : m_Rank(r)
    , m_Suit(s)
    , m_IsFaceUp(ifu) {
}

int Card::GetValue() const {
    // if a card is face down, its value is 0
    int value = 0;
    if (m_IsFaceUp) {
        // value is number showing on card
        value = m_Rank;
        // value is 10 for face cards
        if (value > 10) {
            value = 10;
        }
    }
    return value;
}

void Card::Flip() {
    m_IsFaceUp = !m_IsFaceUp;
}

Card::rank Card::GetRank() const {
    return m_Rank;
}

Card::suit Card::GetSuit() const {
    return m_Suit;
}

// overloads << operator so Card object can be sent to cout
ostream &operator<<(ostream &os, const Card &aCard) {
    const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7",
                             "8", "9", "X", "J", "Q", "K" };
    const string SUITS[] = { "♣", "♦", "♥", "♠" };

    if (aCard.m_IsFaceUp) {
        os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
    } else {
        os << "XX";
    }

    return os;
}
