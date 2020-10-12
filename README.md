# Linked-list-implementation-of-a-card-game
Alice and Bob are playing a game a bit like Go Fish, although neither of them is very good at it. Rather than randomly guessing what card the other person has, they take turns to find a matching card. Each player goes through their list of cards in order and asks the other player to list all of their cards in order until a match is found. The game ends once they do not have any cards in common. Note that they do not draw any new cards during this process.  You have pointed out to Alice and Bob that this game is completely deterministic. They’re not sure what you mean, so you decide to demonstrate by showing that a computer can predict how a game will play out. To do this, you’ll be using a linked list!

Approach Overview

At the start of the program, you will read in Alice and Bob’s starting hands from two files. The names of these files are provided as command line arguments with Alice’s file in argv[1] and Bob’s in argv[2]. The starter code opens the files for you as ifstream objects, which you can treat much like cin. You should read Alice and Bob’s cards into two linked lists, making sure to maintain the order in the file, that is the first card in the file should be at the head of the list.

Once you have the lists of cards, the game begins. Alice goes first (Important! Alice’s file is in argv[1]) and iterates over each card in her hand, checking whether Bob has that card. Once a matching card is found, you should print the line “Alice picked matching card <card value as a number/character>". The card should then be removed from both players hands. Make sure to delete any dynamically allocated memory when removing the cards from your lists!

The process then repeats, except this time, Bob looks through his cards for the first one that Alice also has. Each player should begin their search where they left off in a previous round. Once there are no matching cards, you should print out the final hands of both players with the matching cards removed.

You should write your own Makefile for this lab so that running make builds an executable called game. Also, it should build an executable called testcards which runs all your unit tests.
