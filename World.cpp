//Kyle Phalen
//Dr. Polack 
//World.cpp
//File to implement world class.
//2/23/2015
//CPSC 230
//I hereby declare upon my word of honor that I have neither given nor received unauthorized help on this work.
#include <cstdlib>
#include <ctime>
#include <climits>
#include "World.h"
using namespace std;
        



	World::World(){
                //Initializes random values throughout program.
              	 srand(time(0)% INT_MAX);
         //Contains contents of "Box" class.
        	Box temp;

          //Increments for each row in array.
	for (int row=0;row<9;row++)
                                    {
           //Increments for each column in array.
        for (int column=0;column<9;column++){
                         //Stores contents of character representing gold.
                        char G='-';

                          //Sets all items in "temp" to character G.
                        temp.setCharacter(G);
                        temp.getCharacter();
                          //By default, not visited until selected by user.
                        temp.setVisited(false);
                          //Inserted into array.
                        gm[row].InsertAt(temp,column);
                	}
                }


}
	void World::printWorld(){
//Numbering of columns.
cout<<setw(9)<<"0"<<setw(8)<<"1"<<setw(8)<<"2"<<setw(8)<<"3"<<setw(8)<<"4"<<setw(8)<<"5"<<setw(8)<<"6"<<setw(8)<<"7"<<setw(8)<<"8"<<endl;
                
		for( int row=0;row<9;row++){
                      cout<<row<<setw(8);
                                for (int column=0;column<9;column++){
                                Box temp;
                                temp=gm[row].getItem(column);
                               //Produces each value in array.
                            cout<< temp.getCharacter()<<setw(8);
			}
                        }
        }                
	
        
  
      void World::randomRowColumn(int &row, int &column){
Box temp;
   //Reinitialization of array. Used to create new values for new games.
   //Comments in default constructor also pertinent here.
  for (int r=0;r<9;r++)
                                   {
                for (int c=0; c<9; c++)
               {		
               temp.setCharacter('-');
               int num=((rand()%50)+50);
               temp.setGoldLost(num);
               totalGold=((rand()%50)+50);
               temp.setVisited(false);
               gm[r].InsertAt(temp,c);
}
}
		temp=gm[row].getItem(column);
           
      for (int i=0;i<1;i++){ 
           //Sets item to "Koopla character
           //unless it is a gold character.
	 if (temp.getCharacter()=='-'){

                  setKoopla(); 
           }
      } 
       for (int i=0;i<1;i++){    
 	if (temp.getCharacter()=='-'){

                  setSecretPassage();
          }
       }
       for (int i=0;i<1;i++){
	if (temp.getCharacter()=='-'){
           setFlag();

          } 
        }        
       for (int i=0;i<1;i++){
	 if (temp.getCharacter()=='-'){

                  setBowser();
           }

}

}
     void World::setKoopla(){
     //Increments eight times
     //once for each Koopla placed
     //in array.
 for (int i=0;i<8;i++){  
                int I=rand()%9; 
                int J=rand()%9;
                char K='K';
                        //Contents of "Box" class
                        //unique to Koopla function.
                        Box Koop;
                         //Variable to hold 25%-50%
                         //of current totalGold value.
                        int num;
                        Koop.setCharacter(K);
                        Koop.getCharacter();
                        Koop.getGoldWon();
                          //Equation to produce 25%-50%
                          //of totalGold.
                        num=((rand()%(totalGold+Koop.getGoldWon())*.25)+(totalGold+Koop.getGoldWon())*.50);
                         //Value in "num" produced for each selection
                         //of "Koopla" item.
                        Koop.setGoldLost(num);
                        Koop.setVisited(false);
                        gm[I].InsertAt(Koop,J);
                      }
} 
                       

	void World::setBowser(){
                for (int i=0;i<1;i++){
		int I=rand()%9;
		int J=rand()%9;
		Box Bows;
		char B='B';
                       Bows.setCharacter(B);
      			Bows.getCharacter();
                        Bows.setVisited(false);
      			gm[I].InsertAt(Bows, J);
}

  
                      }
    



	void World::setSecretPassage(){
             for (int i=0;i<2;i++){
             int I=rand()%9;
             int J=rand()%9; 
	     Box SecPas;
			char S='S';
         		SecPas.setCharacter(S);
        		 SecPas.getCharacter();
                        SecPas.setVisited(false);
        		gm[I].InsertAt(SecPas,J);
                        }  
                       }
                 


	void World::SetOneBox(){
         int c;
	 int  d;
         c=rand()%9;
         d=rand()%9;
           //Places Koopla, Secret Passage, Flag, and Bowser
           //items randomly throughout array,
           //up to this point only containing gold.
          for (int i=0;i<1;i++){
          randomRowColumn(c,d);
          }
}


 	string World::SecretPassageMessage(){
	string message;
	message="The flag is located in ";
	return message;
		
}
               
		void World::setFlag(){
                
        	char F='F';
     			Box Flag;
                        Box temp;
    			int I=rand()%9;
    			int J=rand()%9; 
                                
     				Flag.setCharacter(F);
     				Flag.getCharacter();
                                Flag.setVisited(false);
     				gm[I].InsertAt(Flag,J);
	
    
}
 
        void World::revealSelection(int row, int column){
	Box thing;
        Box thing1;
        Box thing2;
        Box thing3;
        Box thing4;
        thing=gm[row].getItem(column);                                                                         
    
            //Items not accepted if already visited.
         if(thing.getVisited()==true)
           cout<<"Error";
          
          else{
           //Items set as "visited"
           //as soon as passed through function.
          (thing.setVisited(true));
       
            //Items to be printed
            //if user selects "flag" variable.
         if (thing.getCharacter()=='F'){            
           cout<<"You Win!"<<endl;
          totalGold=totalGold+8000;
           }

     	if (thing.getCharacter()=='-'){
            //Value of totalGold
            //increments upward for each gold character selected.
          totalGold+=thing.getGoldWon();
          cout<< "You win " << thing.getGoldWon() << " pieces of gold!"<<endl;
       }

     	if (thing.getCharacter()=='B'){
           totalGold=0;
           cout<<"Bowser got you! You lose :(."<<endl; 
             }

     	if (thing.getCharacter()=='K'){
          totalGold-=thing.getGoldWon();
          cout<<"The koopla stole " << thing.getGoldWon()<< " pieces of gold from you."<<endl;
         }
     	if (thing.getCharacter()=='S'){
            //Goes through first 5 rows of array.
         for (int r=0;r<5;r++){
                 //Goes through first 5 columns of first 5 arrays.
        	 for    (int c=0;c<5;c++){
         		thing1=gm[r].getItem(c);
                           //Returns message if
                           //this portion of array
                           //contains Flag variable.
        		if (thing1.getCharacter()=='F')
            		cout<< SecretPassageMessage() << "in the top left."<<endl;
         }
         }
         for (int r=0;r<5;r++){
         for    (int c=5;c<9;c++){
         thing2=gm[r].getItem(c);
        if (thing2.getCharacter()=='F')
            cout<< SecretPassageMessage() << "in the top right."<<endl;
                        

         }
         }

       for (int r=5;r<9;r++){
         for    (int c=0;c<5;c++){
         thing3=gm[r].getItem(c);
        if (thing3.getCharacter()=='F')
            cout<< SecretPassageMessage() << "in the bottom left."<<endl;
         }
         }

      for (int r=5;r<9;r++){
         for    (int c=5;c<9;c++){
         thing4=gm[r].getItem(c);
        if (thing4.getCharacter()=='F')
            cout<< SecretPassageMessage() << "in the bottom right."<<endl;
         }
	}


	}
	}

          //Saves changes made to items
          //which have passed through function. 
	gm[row].InsertAt(thing,column);
cout<<setw(9)<<"0"<<setw(8)<<"1"<<setw(8)<<"2"<<setw(8)<<"3"<<setw(8)<<"4"<<setw(8)<<"5"<<setw(8)<<"6"<<setw(8)<<"7"<<setw(8)<<"8"<<endl;
                
			for( int row=0;row<9;row++){
                      cout<<row<<setw(8);
                                for (int column=0;column<9;column++){
                                Box temp;
                                temp=gm[row].getItem(column);
                                if (temp.getVisited()==false)
                                 //Prints asteriks
                                 //for unvisited values.
                                cout<<"*"<<setw(8);
                               else
                              //Prints actual value
                              //once visited.
                            cout<< temp.getCharacter()<<setw(8);
	}
	}
	cout<<setw(10)<<endl;
          //Running counters to display
          //most recent character selection and totalGold value.
	cout<<"Character selected: "<<thing.getCharacter()<<endl;
	cout<<"Current gold: "<<totalGold<<endl;
	}
        


	int World::getGold()
	{
      return totalGold;
	}

