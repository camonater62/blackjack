#include "GenericPlayer.hpp"

#include <sstream>

using namespace std;

GenericPlayer::GenericPlayer(const string &name)
    : m_Name(name) {
}

GenericPlayer::~GenericPlayer() {
}

bool GenericPlayer::IsBusted() const {
    return (GetTotal() > 21);
}

void GenericPlayer::Bust() const {
    cout << m_Name << " busts.\n";
}

// overloads << operator so a GenericPlayer
// object can be sent to cout
ostream &operator<<(ostream &os,
        const GenericPlayer &aGenericPlayer) {
    os << aGenericPlayer.m_Name << ":\n";

    vector<Card *>::const_iterator pCard;
    if (!aGenericPlayer.m_Cards.empty()) {
        stringstream cards[5];
        for (pCard = aGenericPlayer.m_Cards.begin();
             pCard != aGenericPlayer.m_Cards.end();
             ++pCard) {
            //    os << *(*pCard) << "\t";
            char t = '\t';
            const static string RANKS[]
                = { "0", "A", "2", "3", "4", "5", "6",
                    "7", "8", "9", "X", "J", "Q", "K" };
            const static string SUITS[]
                = { "♣", "♦", "♥", "♠" };

            string rank = RANKS[(*pCard)->GetRank()];
            string suit = SUITS[(*pCard)->GetSuit()];
            cards[0] << "┌─────┐" << t;
            cards[4] << "└─────┘" << t;
            if ((*pCard)->GetValue() != 0) {
                cards[1] << "│" << rank << "    │" << t;
                cards[2] << "│  " << suit << "  │" << t;
                cards[3] << "│    " << rank << "│" << t;
            } else {
                cards[1] << "│ ~ ~ │" << t;
                cards[2] << "│~ ~ ~│" << t;
                cards[3] << "│ ~ ~ │" << t;
            }
        }
        // if (aGenericPlayer.GetTotal() != 0) {
        for (auto &s : cards) {
            os << s.str() << "\n";
        }
        os << "(" << aGenericPlayer.GetTotal() << ")";
        // }
    } else {
        os << "<empty>";
    }
    return os;
}
