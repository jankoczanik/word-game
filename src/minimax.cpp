#include <memory>
#include <limits>
#include <iostream>
#include "../include/minimax.h"

int minimax(const std::shared_ptr<TrieNode>& node, const std::string& prefix, bool isTurn, int depth) {
    
    if (!node) return -1;

    if (node -> children.empty()) return isTurn ? -1 : 1;

    int bestScore = isTurn ? std::numeric_limits<int>::min() 
                           : std::numeric_limits<int>::max();

    for (const auto& [ch, child] : node -> children) {
        int score = minimax(child, prefix + ch, !isTurn, depth + 1);
        bestScore = isTurn ? std::max(bestScore, score)
                           : std::min(bestScore, score);
    }

    return bestScore * 1000 + depth;
    
}

char bestMove(const std::shared_ptr<TrieNode>& root, const std::string& prefix) {
    auto currentNode = root;

    for (char ch : prefix) {
        if (!currentNode -> children.count(ch))
            return '?';
        currentNode = currentNode -> children.at(ch);
    }

    int bestScore = std::numeric_limits<int>::min();
    char bestChar = '?';

    // 1/2 chance for bot to pick completely random move
    if (!currentNode -> children.empty() && rand() % 2 < 1) {
        int index = rand() % currentNode -> children.size();
        auto iterator = currentNode -> children.begin();
        std::advance(iterator, index);
        return iterator -> first;
    }

    for (const auto& [ch, child] : currentNode -> children) {
        int score = minimax(child, prefix + ch, false, 1);
        if (score > bestScore) {
            bestScore = score;
            bestChar = ch;
        }
    }

    return bestChar;
}