#include "trie.h"

Trie::Trie() {
    root = std::make_shared<TrieNode>();
}

void Trie::addWord(const std::string& word) {
    auto currentNode = root;
    for (char ch : word) {
        if (!currentNode -> children[ch]) {
            currentNode -> children[ch] = std::make_shared<TrieNode>();
        }
        currentNode = currentNode -> children[ch];
    }
    currentNode -> isWord = true;
}

bool Trie::isValidPrefix(const std::string& prefix) const {
    auto currentNode = root;
    for (char ch : prefix) {
        if (!currentNode -> children.count(ch))
            return false;
        currentNode = currentNode -> children.at(ch);
    }
    return true;
}

bool Trie::isValidWord(const std::string& prefix) const {
    auto currentNode = root;
    for (char ch : prefix) {
        if (!currentNode -> children.count(ch))
            return false;
        currentNode = currentNode -> children.at(ch);
    }
    return currentNode -> isWord;
}