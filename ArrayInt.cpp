//
//  ArrayInt.cpp
//  ArrayInt
//
//  Created by Jim Bailey on 4/1/18 with modifications by Tina Majchrzak
//  This work by Jim Bailey is licensed under a Creative Commons Attribution 4.0
//  International License.
//

#include "ArrayInt.hpp"
#include <iostream>
#include <algorithm>
#include <stdexcept>

// constructor, set up the array
ArrayInt::ArrayInt(int size) : size(size), lastIndex(0)
{
    theArray = new int[size];
}

// destructor, delete the array and go away
ArrayInt::~ArrayInt()
{
    delete[] theArray;
}

// add value at next location
// call resize to resize array if full
void ArrayInt::append(int value)
{
    std::cout << lastIndex << " " << size << std::endl;
    if (lastIndex >= size-1)
    {
        resize(size*2);
    }
    lastIndex++;
    theArray[lastIndex] = value;
}

// get value at last location
// throw exception if empty
int ArrayInt::getLast()
{

    int value;
    if (lastIndex <= 0)
    {
        throw std::out_of_range("Array is empty!");
    }
    else
    {
        value = theArray[lastIndex];
    }

    return value;
}

// remove value at last location
// does nothing if empty
void ArrayInt::deleteLast()
{
    if (lastIndex <= 0)
    {
        throw std::out_of_range("Array is empty!");
    }
    else
    {
        if (lastIndex < 1)
        {
            lastIndex = 1;
        }

        theArray[lastIndex--] = ' ';
    }

}

// create new array of newSize and copy to it
void ArrayInt::resize(int newSize)
{
    int* newArray = new int[newSize];

    for (int i = 0; i < size; i++)
    {
        newArray[i] = theArray[i];
    }

    delete[] theArray;
    theArray = newArray;
    size = newSize;
}

// list the elements from 0 to lastIndex
std::string ArrayInt::listElements()
{
    if (lastIndex <= 0)
    {
        return "Array is empty!";
    }
    for (int i = 1; i <= lastIndex; i++)
    {
        std::cout << " (" << i << ')' << theArray[i];
    }
}

// find a value if present
bool ArrayInt::find(int value)
{
    return false;
}

// remove a value if found
bool ArrayInt::removeVal(int value)
{
    return false;
}

// find and return the largest value
int ArrayInt::findLargest()
{
    return 7;
}

// remove largest value
void ArrayInt::removeLargest()
{
    return;
}

// insert into array at specified location
void ArrayInt::insertAt(int index, int value)
{
    return;
}

// remove an item and compress the array
int ArrayInt::removeAt(int index)
{
    return 7;
}

// use append, remove, and findLargest to arrange values in descending order
void ArrayInt::solveThink(int *values, int numValues)
{
    return;
}

