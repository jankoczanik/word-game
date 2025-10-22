#pragma once

#include <string>
#include <memory>
#include "trie.h"

int minimax(const std::shared_ptr<TrieNode>&, const std::string&, bool, int);
char bestMove(const std::shared_ptr<TrieNode>&, const std::string&);