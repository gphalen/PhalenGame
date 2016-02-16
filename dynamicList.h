//Kyle Phalen
//Dr. Polack 
//dynamicList.h
//Header file for dynamicList class.
//2/23/2015
//CPSC 230
//I hereby declare upon my word of honor that I have neither given nor received unauthorized help on this work.
const int defmaxlistsize=50;

template <class ITEMTYPE>
class dynamicList

{
public:
    dynamicList();
    dynamicList(int maxnumber);
    ~dynamicList();
    bool Full() const;
    bool Empty() const;
    void Getlast(ITEMTYPE &item, bool &found);
    bool Insert(ITEMTYPE item);
    ITEMTYPE RemoveLast(ITEMTYPE item, bool &found);
    ITEMTYPE RemoveOne(ITEMTYPE item, bool &found);
    bool Search(ITEMTYPE item);
    void Clear();
    void Print() const;
    void BubbleSort();
    bool BinarySearch(ITEMTYPE item);
     //Function to insert item at a given point in array.
    bool InsertAt(ITEMTYPE item, int index);
     //Function to retrieve item from a given point in an array.
    ITEMTYPE getItem(int index);

private:
    ITEMTYPE *element;
    int length;
        int size;
};

#include "dynamicList.cpp"
