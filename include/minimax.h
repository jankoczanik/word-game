#pragma once

#include <string>
#include <memory>
#include <include/trie.h>

int minimax(std::shared_ptr<TrieNode>, const std::string&, bool);
char bestMove(std::shared_ptr<TrieNode>, const std::string&);