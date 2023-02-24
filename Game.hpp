#pragma once

#include "Deck.hpp"
#include "House.hpp"
#include "Player.hpp"

#include <vector>

class Game {
public:
    Game(const std::vector<std::string> &names);
    ~Game();

    // plays the game of blackjack
    void Play();

private:
    Deck m_Deck;
    House m_House;
    std::vector<Player> m_Players;
};
