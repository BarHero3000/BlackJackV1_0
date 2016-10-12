/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.cpp
 * Author: Brandon
 * 
 * Created on October 9, 2016, 11:02 AM
 */

#include "Player.h"
#include <iostream>
using namespace std;

//Player::Player() {
//}
//
//Player::Player(const Player& orig) {
//}
//
//Player::~Player() {
//}

int Player::setChips(bool outcome){
    //Outcome is a win(1) or lose(0)
    switch(outcome){
        case true:{
            chipsInHand += chipsBet * 2;   //Player's total chips is now equal to their (bet * 2) plus what chips they had.
            break;
        }
//        case false:{
//            chipsInHa
//            break;
//        }
    }
        return chipsInHand;   //Return the players new total chip amount
}
    
int Player::placeBet(int bet, bool increase){
    switch(increase){
        case true:{
            chipsBet += bet;
            break;
        }
        case false:{
            chipsBet -= bet;
            break;
        }
    }
    return chipsBet;
}
    
    
    


