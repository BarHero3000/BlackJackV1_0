/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: Brandon
 *
 * Created on October 9, 2016, 11:02 AM
 */

#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player();
    Player(const Player& orig);
    virtual ~Player();
    Player(char* name, int chips);
    
    char * getPlayerName(){return &playerName[0];}
    int getHandChips(){return chipsInHand;}
    int getChipsBet(){return chipsBet;}
    int setChips(bool outcome); //Regular bet
    int setChips(bool outcome1, bool outcome2); //Doubled Bet
    int placeBet(int bet, bool increase);
    int doubleBet(){chipsBet *= chipsBet;return chipsBet;}
    //int play(bool double);
private:
    char playerName[15];
    int chipsInHand;
    int chipsBet;
    bool stand;
    bool bust;
    bool blackJack;
    
    

};

#endif /* PLAYER_H */

