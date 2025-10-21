#include <minimax.h>
#include <memory>
#include <limits>

int minimax(std::shared_ptr<TrieNode> node, const std::string& prefix, bool isTurn) {
    
    if (!node) return -1;

    if (node -> children.empty()) return isTurn ? -1 : 1;

    int bestScore = isTurn ? std::numeric_limits<int>::max() 
                           : std::numeric_limits<int>::min();

    for (const auto& [ch, child] : node -> children) {
        int score = minimax(child, prefix + ch, !isTurn);
        bestScore = isTurn ? std::max(bestScore, score)
                           : std::min(bestScore, score);
    }

    return bestScore;
    
}

char bestMove(std::shared_ptr<TrieNode> root, const std::string& prefix) {
    auto currentNode = root;

    for (char ch : prefix) {
        if (!currentNode -> children.count(ch))
            return '?';
        currentNode = currentNode -> children.at(ch);
    }

    int bestScore = std::numeric_limits<int>::min();
    char bestChar = '?';

    for (const auto& [ch, child] : currentNode -> children) {
        int score = minimax(child, prefix + ch, false);
        if (score > bestScore) {
            bestScore = score;
            bestChar = ch;
        }
    }

    return bestChar;
}