//Kyle Phalen
//Dr. Polack 
//World.h
//Header file for World class.
//2/23/2015
//CPSC 230
//I hereby declare upon my word of honor that I have neither given nor received unauthorized help on this work.
#include <iomanip>
#include <iostream>
#include <string>
#include "Box.h"
#include "dynamicList.h"
using namespace std;
	class World
	{
	public:
         //Default constructor.
	World();
         //Used to place values at random areas in array.
	void randomRowColumn(int &row, int &column);
         //Declares contents of single box.
	void SetOneBox();
         //Sets contents of "secret passage" character to a single box.
	void setSecretPassage();
         //Sets contents of "Flag" character to a given box.
	void setFlag();
          //Sets contents of "Bowser" character to a given box.
	void setBowser();
          //Contains message to be used in setSecretPassage function.
	string SecretPassageMessage();
          //Reveals item at specified location.
	void revealSelection(int row, int column);
          //Prints current contents of array.
	void printWorld();
          //Sets contents of "Koopla" character to a given box.
        void setKoopla();
          //Retrieves current value of "totalGold" variable.
	int getGold();
	private:
          //Declaration of 2D array used throughout program.
	dynamicList<Box> gm[9];
          //Cumulative value of gold acquired throughout game.
	int totalGold;
	};
