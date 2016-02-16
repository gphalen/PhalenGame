//Kyle Phalen
//Dr. Polack 
//Box.h
//Header file for Box class.
//2/23/2015
//CPSC 230
//I hereby declare upon my word of honor that I have neither given nor received unauthorized help on this work.
	class Box
	{

	public:
	Box();
          //Function to return value of "selected" variable to World class.
	bool getVisited() const;

         //Function to set "selected" variable to either true or false.
	void setVisited(bool visited);

	 //Function to return quantity of "gold" variable to World class.
        int getGoldWon() const;

         //Function to set value of "gold" variable.
         //Should be "setGoldWon;" encountered compiler difficlties
         //if I tried to change.
	void setGoldLost(int amount);

         //Function to return value of "character" value to World class.
	char getCharacter() const;

         //Function to set value of "character" variable.
	void setCharacter(char special);

	private:
         //Variable to distinguish names of characters in World class.
	char character;

         //Holds quantity of gold being added or subtracted from totalGold
         //variable in World class.
	int gold;

         //Indicates if item in World class has been visited.
	bool selected;
	};

