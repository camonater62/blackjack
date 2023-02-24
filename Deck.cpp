#include "Deck.hpp"

#include <random>
#include <algorithm>
#include <thread>

using namespace std;

Deck::Deck() {
    m_Cards.reserve(4 * 52);
    for (int i = 0; i < 4; i++) {
        Populate();
    }
}

Deck::~Deck() {
}

void Deck::Populate() {
    Clear();
    // create standard deck
    for (int s = Card::CLUBS; s <= Card::SPADES; s++) {
        for (int r = Card::ACE; r <= Card::KING; r++) {
            Add(new Card(static_cast<Card::rank>(r),
                         static_cast<Card::suit>(s)));
        }
    }
}

void Deck::Shuffle() {
    random_device rd;
    mt19937 g(rd());
    shuffle(m_Cards.begin(), m_Cards.end(), g);
}

void Deck::Deal(Hand &aHand) {
    if (!m_Cards.empty()) {
        aHand.Add(m_Cards.back());
        m_Cards.pop_back();
    } else {
        cout << "Out of cards. Unable to deal.";
    }
}

void Deck::AdditionalCards(GenericPlayer &aGenericPlayer) {
    cout << endl;
    // continue to deal a card as long as generic isn't busted and
    // wants another hit
    while (!aGenericPlayer.IsBusted() && aGenericPlayer.IsHitting()) {
        Deal(aGenericPlayer);
        cout << aGenericPlayer << endl;
        if (aGenericPlayer.IsBusted()) {
            aGenericPlayer.Bust();
        }
    }
}

int Deck::Size() {
    return m_Cards.size();
}
