#pragma once

#include <string>
#include <unordered_map>
#include <memory>

struct TrieNode {
    bool isWord = false;
    std::unordered_map<char, std::shared_ptr<TrieNode>> children;
};

class Trie {
    private:
        std::shared_ptr<TrieNode> root;
    public:
        Trie();
        void addWord(const std::string&);
        void loadWords();
        bool isValidPrefix(const std::string&) const;
        bool isValidWord(const std::string&) const;
        std::shared_ptr<TrieNode> getRoot() const;
};