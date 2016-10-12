/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Deck.h
 * Author: Brandon
 *
 * Created on October 9, 2016, 11:01 AM
 */

#ifndef DECK_H
#define DECK_H

#include <vector>

class Deck {
public:
    Deck();
    Deck(const Deck& orig);
    Deck(int deckSize);
    //virtual ~Deck();
    void printDeck();   //For debugging
    int getNumOfCards(){return numOfCards;}
    int getNextDraw(){return nextDraw;}
    std::vector<char> draw();
private:
    int numOfDecks;
    int numOfCards;
    static const int numOfSuits = 4;
    static const int cardsPerSuit = 13;
    static const int charPerCard = 2;   //3
    static const int cardsPerDeck = 52;
    std::vector<std::vector<char> > vDeck;  //Defaulted for 1 deck, will be resized if necessary for multiple decks
    std::vector<std::vector<char> > vRDeck;  //Defaulted for 1 deck, will be resized if necessary for multiple decks
    int nextDraw;
    void fillDeck();
    void fillDeck2();
    char getSuit(int x);
    char getFace(int x);
    char int2Char(int x);
    void randomizeDecks();
    void printArray(int *ptr, int size, int columns);
};

#endif /* DECK_H */

