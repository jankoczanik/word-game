# Word Game

A simple C++ word-building game implemented using a Trie data structure and Minimax algorithm.

## Author:

Developed by [Janko](https://github.com/jankoczanik)

## Features:

- Interactive gameplay against an AI bot
- Uses a dictionary of english words to validate moves
- Implements AI decision-making using the Minimax algorithm

## How to Play:

- The game starts with the user entering any **lowercase** letter
- The computer chooses a letter to append to the current word
- The game ends when either the player or the computer is unable to add another letter to form a valid english word

### Example:

You: a\
Bot: p\
You: p\
Bot: l\
You: e\
Bot: s

You are unable to add any more letters while keeping it a valid English word, so you **lose**.

## Requirements:

- A C++ compiler

## How to Compile: (g++ example)

1. Open terminal and navigate to the **project folder**.
2. Compile the source code:

`g++ -Iinclude src/main.cpp src/trie.cpp src/minimax.cpp`

3. Run the executable file:

`./a`

## Credits:

The word list sourced from the [dwyl/english-words](https://github.com/dwyl/english-words) repository