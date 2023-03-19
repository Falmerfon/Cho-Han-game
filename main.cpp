//
//  main.cpp
//  Unit3_3
//
//  Created by William Falmerfon on 18/3/2023.
//

#include <iostream>
#include <string>
#include "ChoHan.h"


using namespace std;

int main() {
    
    
    cout<< "Game Cho-Han is started!"<< endl << endl;
    
    
    Dialer dealer;
   
    
    Player player1("Pudge");
    Player player2("Slark");
    
    cout<<"There two players: "<< player1.getName()<< " and "<<player2.getName()<<endl<<"----------------------------------"<< endl<<endl;
    
    for(int i = 0; i < 5; i++){
        
        dealer.rollDice();
        player1.makeGuess();
        player2.makeGuess();
        
        cout<<"Round "<< i+1 <<" and we have... first number is "<< dealer.getDie1()<<" and second is "<<dealer.getDie2()<<" "<< dealer.getChoOrHan()<< endl;
        cout << player1.getName() << " choosed " <<player1.getGuess() <<" || "<< player2.getName() << " choosed "<<player2.getGuess()<<endl;
        
        if(player1.getGuess() == dealer.getChoOrHan()){
            player1.addPoints(1);
            cout<< player1.getName() << " got a point"<<endl;
        }
        
        if(player2.getGuess() == dealer.getChoOrHan()){
            player2.addPoints(1);
            cout<< player2.getName() << " got a point"<<endl;
        }
        
        cout<<"--------------------------------------"<<endl<<endl;
    }
    
    cout<< "that was EPIC fight!"<<endl;
    
    if(player1.getPoints() > player2.getPoints()){
        cout<<player1.getName()<< "'s VICTORY! He got "<< player1.getPoints()<< " points" <<endl;
    }
    
    if(player1.getPoints() < player2.getPoints()){
        cout<<player2.getName()<< "'s VICTORY! He got " <<player2.getPoints()<< " points" << endl;
    }
    
    if(player1.getPoints() == player2.getPoints()){
        
        cout<<"DRAW!"<<endl<<player1.getName()<< " got " <<player1.getPoints()<< " points and " << player2.getName()<< " got " <<player2.getPoints()<< " points" <<endl;
    }
}
