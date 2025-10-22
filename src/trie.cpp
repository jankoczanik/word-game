#include <fstream>
#include <iostream>

#include "../include/trie.h"

Trie::Trie() {
    root = std::make_shared<TrieNode>();
    loadWords();
}

std::shared_ptr<TrieNode> Trie::getRoot() const {
    return root;
}

void Trie::loadWords() {
    std::ifstream file("data/words.txt");
    std::string word;

    if (!file.is_open()) {
        std::cout << "Error: Could not open data/words.txt";
        exit(EXIT_FAILURE);
    }

    while (file >> word) {
        addWord(word);
    }
}

void Trie::addWord(const std::string& word) {
    auto currentNode = root;
    for (char ch : word) {
        if (!currentNode -> children.count(ch)) {
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