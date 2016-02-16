//Kyle Phalen
//Dr. Polack 
//Box.cpp
//File to implement Box class.
//2/23/2015
//CPSC 230
//I hereby declare upon my word of honor that I have neither given nor received unauthorized help on this work.
#include "Box.h"

	Box::Box(){
	selected=true;
        gold=0;
}


	void Box::setVisited(bool visited) {
                    //Changes value of "selected" to value of "visited."
	         if (visited==true)
                   selected=true;
                 if (visited==false)
                   selected=false;
	}
        bool Box::getVisited() const {
           return selected;
        }

	char Box::getCharacter() const{
		return character;
                
	}

	void Box::setCharacter(char special){
                  //Changes value of "character" to value of "special."
		character=special;
	}



	void Box::setGoldLost(int amount){
         //Sets value of "gold" to value of "amount."
        gold=amount;
	}

int Box:: getGoldWon() const{
        return gold;
}

