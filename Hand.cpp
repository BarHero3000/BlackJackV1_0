///*
// * To change this license header, choose License Headers in Project Properties.
// * To change this template file, choose Tools | Templates
// * and open the template in the editor.
// */
//
///* 
// * File:   Hand.cpp
// * Author: Brandon
// * 
// * Created on October 9, 2016, 11:02 AM
// */
//
#include "Hand.h"
#include <iostream>
#include <vector>

using namespace std;

Hand::Hand(int test) {
    numOfCards = 0;
    blackJack = false;
    //Resize 2D vector to accommidate card character format
    hand.resize( 0, vector<char>(charPerCard) ); //Start Vector with size of two, for two cards.
}
////Hand::Hand(const Hand& orig) {
////}
////
////Hand::~Hand() {
////}
void Hand::addCard(std::vector<char> newCard){
    numOfCards++;
    hand.push_back(newCard);
    
//    cout << endl;
//    cout << hand[0][0] << hand[0][1] << endl;
    
    //Adjust Hand Total
    handTotal = calcHand(hand);
    //Check if BlackJack
    blackJack = checkBlackJack(hand);
    
    
}

int Hand::calcHand(std::vector<std::vector<char> > &vHand){
    bool ace;
    int totalAce = 0;
    int handTotal = 0;
    int cardTotals[vHand.size()];
    int hold;
    
    //Check if Hand has an ACE
    for(int i = 0; i < vHand.size(); i++){
        //if(Game::searchV(hand[i], 0, 'A') != hand[i].size()){
            ace = true;
            totalAce += 1;
        //}            
    }
    
    //Calculate hand total
    for(int i = 0; i < vHand.size(); i++){
        cardTotals[i] = Hand::cardValue(vHand[i][1]);   //index 1 is where the value of the card is held.
        //If the card is an ACE worth 11 and puts the hand over 21, then put the ACE worth 1 instead.
        if((handTotal + cardTotals[i]) > 21){
            if(cardTotals[i] == 11)
                cardTotals[i] = 1;
        }
        //Add card value to hand total
        handTotal += cardTotals[i];
    }
    return handTotal;
}

int Hand::cardValue(char c){
    switch(c){
        case 'A':{
            return 11;
        }
        case '2':{
            return 2;
        }
        case '3':{
            return 3;
        }
        case '4':{
            return 4;
        }
        case '5':{
            return 5;
        }
        case '6':{
            return 6;
        }
        case '7':{
            return 7;
        }
        case '8':{
            return 8;
        }
        case '9':{
            return 9;
        }
        case '1':{
            return 10;
        }
        case 'J':{
            return 10;
        }
        case 'Q':{
            return 10;
        }
        case 'K':{
            return 10;
        }
    }
}

bool Hand::checkBlackJack(std::vector<std::vector<char> > &vHand){
    //The only way to have 21 with 2 cards is and ace and a face or 10 card.
    if((vHand.size() == 2) &&(Hand::calcHand(vHand) == 21))
        return true;
    else
        return false;        
}

void Hand::printHand(){
    for(int i = 0; i < hand.size(); i++){
        cout << hand[i][0] << hand[i][1] << " ";
    }
    cout << "= " << handTotal;
}


