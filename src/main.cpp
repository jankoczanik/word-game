#include <iostream>
#include <string>

#include "../include/trie.h"
#include "../include/minimax.h"

char promptPlayer();
char promptBot(const Trie&, const std::string&);

int main() {

    srand(time(NULL));

    Trie trie;

    std::string prefix = "";
    
    bool playerTurn = true;

    while (true) {
        prefix += playerTurn ? promptPlayer() : promptBot(trie, prefix);

        if (!trie.isValidPrefix(prefix)) {
            if (playerTurn)
                std::cout << "Invalid letter! You lose!";
            else
                std::cout << "Bot is stuck! You win!";
            break;
        }

        std::cout << "Current Word: " << prefix << std::endl;

        playerTurn = !playerTurn;
    }

}

char promptBot(const Trie& trie, const std::string& prefix) {
    char move = bestMove(trie.getRoot(), prefix);
    std::cout << "Bot: " << move << std::endl;
    return move;
}

char promptPlayer() {

    char move = ' ';

    while (move < 'a' || 'z' < move) {
        std::cout << "You: ";
        std::cin >> move;
        std::cin.clear();
    }

    return move;
}