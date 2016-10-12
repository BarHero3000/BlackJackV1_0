/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: Brandon
 *
 * Created on October 9, 2016, 11:02 AM
 */

#ifndef GAME_H
#define GAME_H
#include<vector>

class Game {
public:
    Game();
    Game(const Game& orig);
    //virtual ~Game();
    
    Game(int x);
    
    int searchV(std::vector<char>& v, int start, char c);
    int cardValue(char c);
    bool aceCheck(char c);
private:
    

};

#endif /* GAME_H */

