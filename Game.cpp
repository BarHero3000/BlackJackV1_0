/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: Brandon
 * 
 * Created on October 9, 2016, 11:02 AM
 */

#include "Game.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

Game::Game(int x){
    
}



int Game::searchV(std::vector<char>& v, int start, char c){
    for(int i = start; i < v.size(); i++){
        if(v[i] == c)
            return i;
    }
    return v.size();
}


bool Game::aceCheck(char c){
    if(c == 'A')
        return true;
    else
        return false;
}


