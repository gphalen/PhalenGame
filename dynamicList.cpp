//Kyle Phalen
//Dr. Polack 
//dynamicList.cpp
//File to implement dynamicList class.
//2/23/2015
//CPSC 230
//I hereby declare upon my word of honor that I have neither given nor received unauthorized help on this work.
#include <iostream>
using namespace std;
template <class ITEMTYPE>
          //Default constructor.
dynamicList<ITEMTYPE>::dynamicList()            
{     
     length = 0;
        size = defmaxlistsize;
        element = new ITEMTYPE [defmaxlistsize];
}
        //Constructor.
template <class ITEMTYPE>
dynamicList<ITEMTYPE>::dynamicList(int maxnumber)
{
    length = 0;
        size = maxnumber;
        element = new ITEMTYPE [maxnumber];
}
      //Deconstructor.
template <class ITEMTYPE>
dynamicList<ITEMTYPE>::~dynamicList()
 {
        //Deletes all items in array.
      delete [] element;
          length = 0;
}
    //Prints items in array.
  template <class ITEMTYPE>
void dynamicList<ITEMTYPE>::Print() const
{             
        for (int i=0; i<length;i++)
        {
                cout<<"\tLocation "<<i<<" = "<<element[i]<<endl;

        }
}
         //Determines if list is full.
template <class ITEMTYPE>
bool dynamicList<ITEMTYPE>::Full() const

 {       //If "length" matches "size," list is full.
         if (length==size)
                         return true;
                                 else
                                                 return false;
                                                 }
 
        //Determines if list is empty.
template <class ITEMTYPE>
bool dynamicList<ITEMTYPE>::Empty() const
 {
         if (length==0)
                         return true;
                                 else
                                                 return false;
                                                 }


    //Function to search for item in array.
template <class ITEMTYPE>
bool dynamicList<ITEMTYPE>::Search(ITEMTYPE item)
{
    bool moreToSearch;
        int location=0;


    moreToSearch = true;

    while ((moreToSearch) && (location < size))
    {
        if (item == element[location])

        {    //Search ends when "item" is equivalent to element in array.
            return true;
        }
        else
        {
            location++;
        }
    }
        return false;
}

      //Function to insert item into array.
template <class ITEMTYPE>
bool dynamicList<ITEMTYPE>::Insert(ITEMTYPE item)

{

    if (!Full())
        {
            element[length]=item;
                length++;
                return true;
        }
        else
        {
                cout<<"Error: Cannot Insert.  List is Full.\n";
                return false;
        }

}

    //Function to remove last item in array.
template <class ITEMTYPE>
ITEMTYPE  dynamicList<ITEMTYPE>::RemoveLast(ITEMTYPE item, bool &found)
{
  if (!Empty())
    {                        //Stores value in variable before removing.
                            item=element[length];
                            length--;
                            found = true;
                            return item ;
            }
    else
    {
                cout<<"Error: List is Empty.  Cannot Delete.\n";
                found = false;
    }
    found = false;
    return item;

}
   //Clears all values from array.
template <class ITEMTYPE>
void dynamicList<ITEMTYPE>::Clear()
{
    length=0;
}

   //Returns last item from array.
template <class ITEMTYPE>
void dynamicList<ITEMTYPE>::Getlast(ITEMTYPE &item, bool &found)
{
    if (!Empty())
    {
                item=element[length-1];
                found = true;
    }
    else
    {
                cout<<"Error: List is Empty.  Cannot Get Top Element.\n";
                found = false;
    }
}
     //Sorts values in array with a bubble sort.
template <class ITEMTYPE>
void dynamicList<ITEMTYPE>::BubbleSort()
{   
    int endIndex = length-1;
    for (int current = 0; current < endIndex; current++)
    {    
        for (int index = endIndex; index > current; index--)
                if (element[index] < element[index-1])
                        {        
                                ITEMTYPE  temp=element[index];
                                element[index]=element[index-1];
                                element[index-1]=temp;
                        }
    }
}
  //Searches array with a binary search.
template <class ITEMTYPE>
bool dynamicList<ITEMTYPE>::BinarySearch(ITEMTYPE item)
{
        int mid;
        int lowerbound = 0;
        int upperbound = length;
       int      position = ( lowerbound + upperbound) / 2;

       while((element[position] != item) && (lowerbound <= upperbound))
        {
                if (element[position] > item){
                        upperbound = position - 1;
                } else  {
                        lowerbound = position + 1;
                }
                position = (lowerbound + upperbound);
        }
        if (lowerbound <= upperbound)
                return true;
        else
                return false;
}

    //Function to remove specified item from list.
template<class ITEMTYPE>
ITEMTYPE dynamicList<ITEMTYPE>::RemoveOne(ITEMTYPE item, bool &found){

bool moreToSearch;
int location=0;
moreToSearch=true;

ITEMTYPE thing; 
 while ((moreToSearch) && (location < size))
    {     
        if (item == element[location])
        {
            item=element[location];
            for(int i=location;location<length+1;location++)
             element[location]=element[location+1];
            length--; 
            found=true;
            return item;
        }
        else
        {
            location++;
        }
    }

}        //Function to insert item at a specified place in array.
	template <class ITEMTYPE>
	bool dynamicList<ITEMTYPE>::InsertAt(ITEMTYPE item, int index){
                   //Changes value of place in array to specified item.
		element[index]=item;
	}
          //Function retrieve item from a specified place in array.
	template<class ITEMTYPE>
	ITEMTYPE dynamicList<ITEMTYPE>::getItem(int index){
                  //Produces item at specified location.
		return element[index];
		}		
