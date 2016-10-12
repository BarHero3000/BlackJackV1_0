/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Deck.cpp
 * Author: Brandon
 * 
 * Created on October 9, 2016, 11:01 AM
 */

#include "Deck.h"
#include <iostream>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
using namespace std;
//Deck::Deck() {
//}
//Deck::Deck(const Deck& orig) {
//}
//
//Deck::~Deck() {
//}

Deck::Deck(int deckSize) {
    nextDraw = 0;
    numOfDecks = deckSize;  //Number of decks to be played with
    numOfCards = deckSize * cardsPerDeck; //Total number of cards with combined decks
    
    //Resize 2D vector if necessary for multiple decks
    vDeck.resize( numOfDecks * cardsPerDeck, vector<char>(charPerCard) );
    //Resize 2D random vector if necessary for multiple decks
    vRDeck.resize( numOfDecks * cardsPerDeck, vector<char>(charPerCard) );

    //Fill deck
    fillDeck();
    
//    //Print deck
//    printDeck();
    
    //Randomize deck
    randomizeDecks(); 
}

void Deck::fillDeck2(){
    
    //4 suits (H,D,S,C)
    //13 cards per suit (A,2,3,4,5,6,7,8,9,10,J,Q,K)
    //disregard d for number of decks for the time, lets start with one deck
    for(int d = 0; d < numOfDecks; d++){
        for(int suits = 0; suits < numOfSuits; suits++){
            for(int card = 0; card < cardsPerSuit; card++){
                for(int i = 0; i < charPerCard; i++){
                    switch(i){
                        case 0:{
                            vDeck[(d*cardsPerDeck)+(suits*cardsPerSuit)+card][i] = getSuit(suits);
                            break;
                        }
                        case 1:{
                            if(card == 0)
                                vDeck[(d*cardsPerDeck)+(suits*cardsPerSuit)+card][i] = 'A';
                            else if(card == 9)
                                vDeck[(d*cardsPerDeck)+(suits*cardsPerSuit)+card][i] = '1';
                            else if(card > 9)
                                vDeck[(d*cardsPerDeck)+(suits*cardsPerSuit)+card][i] = getFace(card - 10);
                            else
                                vDeck[(d*cardsPerDeck)+(suits*cardsPerSuit)+card][i] = '0';
                            break;
                        }
                        case 2:{
                            if(card > 9 || card < 1)
                                vDeck[(d*cardsPerDeck)+(suits*cardsPerSuit)+card][i] = ' ';
                            else if (card == 9)
                                vDeck[(d*cardsPerDeck)+(suits*cardsPerSuit)+card][i] = '0';
                            else
                                vDeck[(d*cardsPerDeck)+(suits*cardsPerSuit)+card][i] = int2Char(card + 1);
                            break;
                        }
                    }
                }
            }
        }
    }
}
void Deck::fillDeck(){
    
    //4 suits (H,D,S,C)
    //13 cards per suit (A,2,3,4,5,6,7,8,9,10,J,Q,K)
    //disregard d for number of decks for the time, lets start with one deck
    for(int d = 0; d < numOfDecks; d++){
        for(int suits = 0; suits < numOfSuits; suits++){
            for(int card = 0; card < cardsPerSuit; card++){
                for(int i = 0; i < charPerCard; i++){
                    switch(i){
                        case 0:{
                            vDeck[(d*cardsPerDeck)+(suits*cardsPerSuit)+card][i] = getSuit(suits);
                            break;
                        }
                        case 1:{
                            if(card == 0)
                                vDeck[(d*cardsPerDeck)+(suits*cardsPerSuit)+card][i] = 'A';
                            else if(card == 9)
                                vDeck[(d*cardsPerDeck)+(suits*cardsPerSuit)+card][i] = '1';
                            else if(card > 9)
                                vDeck[(d*cardsPerDeck)+(suits*cardsPerSuit)+card][i] = getFace(card - 10);
                            else
                                vDeck[(d*cardsPerDeck)+(suits*cardsPerSuit)+card][i] = int2Char(card + 1);
                            break;
                        }
                    }
                }
            }
        }
    }
}

void Deck::printDeck(){
    for(int i = 0; i < numOfCards; i++){
        cout << vDeck[i][0] <<vDeck[i][1] << vDeck[i][2] << " ";
        if(i%cardsPerSuit == (cardsPerSuit - 1))
            cout << endl;
    }
    cout << endl;
}

char Deck::getSuit(int x){
    switch(x)
    {
        case 0:{    //Hearts
            return 'H';
            break;
        }
        case 1:{    //Diamonds
            return 'D';
            break;
        }
        case 2:{    //Spades
            return 'S';
            break;
        }
        case 3:{    //Clubs
            return 'C';
            break;
        }
    }
}

char Deck::getFace(int x){
    switch(x)
    {
        case 0:{    //Hearts
            return 'J';
            break;
        }
        case 1:{    //Diamonds
            return 'Q';
            break;
        }
        case 2:{    //Spades
            return 'K';
            break;
        }
    }
}

char Deck::int2Char(int x){
    switch(x){
        case 0: return '0';
        case 1: return '1';
        case 2: return '2';
        case 3: return '3';
        case 4: return '4';
        case 5: return '5';
        case 6: return '6';
        case 7: return '7';
        case 8: return '8';
        case 9: return '9';
        
    }
}

void Deck::randomizeDecks(){
    //Array of numbers the size of the total deck to be randomized.
    int randArray[numOfCards];
    //Fill randArray from 0 to numOfCards - 1
    for(int i = 0; i < numOfCards; i++){
        randArray[i] = i;
    }   
//    //Print number array before it's been randomized
//    cout << "Number array before randomizing..." << endl;
//    printArray(&randArray[0], numOfCards, cardsPerSuit);
    
    //Randomize the randArray
    std::srand ( unsigned ( std::time(0) ) );   //So that cards are actually random for every game.
    std::random_shuffle(&randArray[0], &randArray[numOfCards - 1]);
//    //Print number array before it's been randomized
//    cout << "Number array after randomizing..." << endl;
//    printArray(&randArray[0], numOfCards, cardsPerSuit);
    
    //Randomize Deck
    for(int i = 0; i < numOfCards; i++){
        for(int x = 0; x < charPerCard; x++){
            vRDeck[i][x] = vDeck[randArray[i]][x];
        }
    }        
    
//    //Print Random Deck after its been randomized
//    cout << "Deck after randomizing..." << endl;
//    for(int i = 0; i < numOfCards; i++){
//        cout << vRDeck[i][0] << vRDeck[i][1] << vRDeck[i][2] << " ";
//        if(i%cardsPerSuit == (cardsPerSuit -1 ))
//            cout << endl;
//    }   
}

void Deck::printArray(int *ptr, int size, int columns){
    for(int i = 0; i < size; i++){
        cout << ptr[i] << " ";
        if(i%columns == (columns - 1))
            cout << endl;
    } 
    cout << endl;
}

std::vector<char> Deck::draw(){  
    nextDraw += 1;
    return (vRDeck[nextDraw - 1]);    
}



/*
 * Clean up code, doing overload functions for printing 1d and 2D arrays.
 * Overload functions for copying arrays
 * Get rid of testing and debugging code.
 * Randomizing the deck is finished. Next is to create the player class,
 * then the game class (aka the fun part).
 */
