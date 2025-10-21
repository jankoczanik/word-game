#ifndef TRIE_H
#define TRIE_H

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
        bool isValidPrefix(const std::string&) const;
        bool isValidWord(const std::string&) const;
};

#endif