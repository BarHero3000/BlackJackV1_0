/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hand.h
 * Author: Brandon
 *
 * Created on October 9, 2016, 11:02 AM
 */

#ifndef HAND_H
#define HAND_H

#include <vector>

class Hand {
public:
    Hand();
    Hand(const Hand& orig);
    //virtual ~Hand();
    Hand(int test);
    void addCard(std::vector<char> newCard);
    
    int getHandTotal(){return handTotal;}
    bool getBlackJack(){return blackJack;}
    void printHand();
    
private:
    std::vector<std::vector<char> > hand;
    int numOfCards;
    int handTotal;
    static const int charPerCard = 2;
    bool blackJack;
    int calcHand(std::vector<std::vector<char> > &vHand);
    int cardValue(char c);
    bool checkBlackJack(std::vector<std::vector<char> > &vHand);

};

#endif /* HAND_H */

