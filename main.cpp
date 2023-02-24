#include "Card.hpp"
#include "Deck.hpp"
#include "Game.hpp"
#include "GenericPlayer.hpp"
#include "Hand.hpp"
#include "House.hpp"
#include "Player.hpp"
#include "System.hpp"

#include <iostream>
#include <vector>

using namespace std;

int main() {

    cout << "\t\tWelcome to BlackJack!\n\n";

    // int numPlayers = 0;
    // while (numPlayers < 1 || numPlayers > 7) {
    //     cout << "How many players? (1 - 7): ";
    //     cin >> numPlayers;
    // }

    vector<string> names;
    string name;
    // for (int i = 0; i < numPlayers; i++) {
    //     cout << "Enter player name: ";
    //     cin >> name;
    //     names.push_back(name);
    // }
    // cout << endl;
    names.push_back(getUserName());

    // the game loop
    Game aGame(names);
    char again = 'y';

    while (again != 'n' && again != 'N') {
        clear();
        aGame.Play();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;
    }

    return 0;
}
