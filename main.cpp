/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Brandon
 *
 * Created on October 8, 2016, 6:54 PM
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Deck.h"
#include "Hand.h"
//#include "Algorithms.cpp"
#include "Game.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Create a deck for testing
    Deck newDeck = Deck(1);
    //Create a hand for testing
    Hand newHand = Hand(1);
    //Test adding cards to the hand
    newHand.addCard(newDeck.draw());
    //newHand.addCard(newDeck.draw());   
    //Fill a test vector with and ACE to test the ACE find.
    std::vector<char> testVector;
    testVector.push_back('D');
    testVector.push_back('A');

    
    //Add ACE to hand to test
    newHand.addCard(testVector);
    
    cout << "Hand total: " << newHand.getHandTotal() << endl;
    if(newHand.getBlackJack())
        cout << "BlackJack!!!" << endl;
    
    cout << endl << endl << endl;
    
    //Test game
    cout << "Let's begin..." << endl;
    bool playing = true;
    bool pHit, dHit;
    bool pStand, dStand;
    bool pBust, dBust;
    bool pBJ, dBJ;
    char hold;
    //Create Deck
    Deck deck = Deck(1);
    while(playing){
         pBJ = false, dBJ = false;
         pBust = false, dBust = false;
         pHit = false, dHit = false;
        //Create instances for the player and dealers hands
        Hand pHand = Hand(1);
        Hand dHand = Hand(1);
        //Draw first cards
        pHand.addCard(deck.draw());
        dHand.addCard(deck.draw());
        //Print cards
        cout << "Dealer: ";
        dHand.printHand(); 
        cout << endl;
        cout << "Player: "; 
        pHand.printHand(); 
        cout << endl;
        //Draw second cards
        pHand.addCard(deck.draw());
        dHand.addCard(deck.draw());
        //Print cards
        cout << "Dealer: "; dHand.printHand();  cout << endl;
        cout << "Player: "; pHand.printHand();  cout << endl;
        //Player hits until he stands
        do{
            if(pHand.getBlackJack()){
                pBJ = true;
                break;
            }
            else if(pHand.getHandTotal() == 21)
                break;
            else if(pHand.getHandTotal() > 21){
                pBust = true;
                break;
            }
            cout << "Hit: (0) <> Stand: (1)  == ";
            cin >> hold;
            if(hold == '0'){
                pStand = false;
                pHand.addCard(deck.draw());
            } else if(hold == '1')
                pStand = true;
            cout << "Player: "; pHand.printHand();  cout << endl;
        }while(!pStand);
        //Dealer draws
        do{
            if(dHand.getBlackJack()){
                dBJ = true;
                break;
            }
            else if(dHand.getHandTotal() == 21)
                break;
            else if(dHand.getHandTotal() > 21){
                dBust = true;
                break;
            }
            if(dHand.getHandTotal() < 17){  //If Dealer has 16 or less he must hit
                dStand = false;
                dHand.addCard(deck.draw());
            } else 
                dStand = true;
            cout << "Dealer: "; dHand.printHand();  cout << endl;
        }while(!dStand);
        cout << endl;
        //Print cards
        cout << "Dealer: "; dHand.printHand();  cout << endl;
        cout << "Player: "; pHand.printHand();  cout << endl;
            
        
        
        playing = false;
    }
    
    
    
    
    
    
    
    return 0;
}

