//
//  ChoHan.h
//  Unit3_3
//
//  Created by William Falmerfon on 18/3/2023.
//

#ifndef ChoHan_h
#define ChoHan_h
#include <chrono>
#include <random>
#include <algorithm>
#include <string>

using namespace std;
using namespace chrono;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Die{
    
private:
    int sides {6};
    int value {0};
    
public:
    //random number for value from 1 to 6
    void roll() {
    
        auto seed = static_cast<unsigned int>(high_resolution_clock::now().time_since_epoch().count());
        auto eng = default_random_engine(seed);
        uniform_int_distribution<int> random(1, sides);
        
        value = random(eng);
    }
    
    int getValue(){
        return value;
    }
    
    //default constructors
    Die() = default;
    
    //appropriate overloaded assignment operator
    Die &operator = (const Die &other){
        if(this != &other){
            sides = other.sides;
            value = other.value;
        }
        return *this;
    }
    
    //default deconstructor
    ~Die() = default;
};



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Dialer{
    
    
private:
    Die die1;
    Die die2;
    
public:
    
    void rollDice(){
        die1.roll();
        die2.roll();
    }
    
    int getDie1(){
        return die1.getValue();
    }
    
    int getDie2(){
        return die2.getValue();
    }
    
    
    string getChoOrHan(){
        int sum = die1.getValue() + die2.getValue();
        if(sum %2 == 0){
            return "Cho";}
        else{
            return "Han";
        }
    }
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Player{
    
private:
    
    string name; //stores player's name
    string guess; //stores guess Cho or Han
    int points {0}; //stores total points of player
    
public:
    
    Player() = default;
    
        //rand cho or han from 0 to 1
    void makeGuess(){
        auto seed = static_cast<unsigned int>(high_resolution_clock::now().time_since_epoch().count());
        auto eng = default_random_engine(seed);
        uniform_int_distribution<int> randGuess(0, 1);
        
         int ChoOrHan = randGuess(eng);
        
        if(ChoOrHan == 0){
            guess = "Cho";
        }
        else{
            guess = "Han";
        }
    }
    // add some points
    int addPoints(int points){
        if(points > 0)
            this -> points += points;
        
        return this -> points;
    }
    
    Player(string playerName){
        name = playerName;
    }
 
    
    
    Player &operator = (const Player &other){
        if(this != &other){
            name= other.name;
            guess=other.guess;
            points=other.points;
        }
        return *this;
    }
    
    //deconstructor
    ~Player() = default;
    
    //setters
    void setName(string playerName){
        name = playerName;
    }
    
    string getName(){
        return name;
    }
    
    void setGuess(string guessWhat){
        guess = guessWhat;
    }
    string getGuess(){
        return guess;
    }
    void setpoints(int addpoints){
        points = addpoints;
    }
    int getPoints(){
        return points;
    }
    
    //add points
    friend ostream &operator << (ostream &os, const Player &player){
        os << "Player " << player.name << ", Total points: " << player.points << endl;
        return os;
    }
    
    
    //Overloading the relational operators so that two Player objects can be compared to determine which of the two has won or if we have a draw.
    bool operator > (const Player &other) const{
        return points > other.points;
    }
    
    bool operator < (const Player &other) const{
        return points < other.points;
    }
    
    bool operator == (const Player &other) const{
        return points == other.points;
    }
};

#endif /* ChoHan_h */
 
