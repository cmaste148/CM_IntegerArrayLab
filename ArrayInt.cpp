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

    if (lastIndex >= size)
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
    std::cout << "before newArray";
    int* newArray = new int[newSize];
    std::cout << "after newArray";
    for (int i = 0; i <= size; i++)
    {
        std::cout << i;
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
        std::cout << ' ' <<theArray[i];
    }
    return " ";
}

// find a value if present
bool ArrayInt::find(int value)
{
    bool found = false;
    for (int i = 0; i <= lastIndex; i++)
    {
        if (theArray[i] == value)
        {
            found = true;
        }
    }
    return found;
}

// remove a value if found
bool ArrayInt::removeVal(int value)
{
    bool found = false;
    if (find(value))
    {
        found = true;
        bool reached = false;
        for (int i = 0; i <= lastIndex; i++)
        {
            if (theArray[i] == value)
            {
                reached = true;
                lastIndex--;
            }
            if (reached)
            {
                theArray[i] = theArray[i+1];
            }
        }
    };
    return found;
}

// find and return the largest value
int ArrayInt::findLargest()
{
    if (lastIndex <= 0)
    {
        throw std::out_of_range("Attempt to read from empty array.");
    }
    int largest = -999;
    for (int i = 1; i <= lastIndex; i++)
    {
        if (theArray[i] > largest)
        {
            largest = theArray[i];
        }
    }
    return largest;
}

// remove largest value
void ArrayInt::removeLargest()
{
    if (lastIndex <= 0)
    {
        throw std::out_of_range("Attempt to remove from empty array.");
    }
    bool reached = false;
    for (int i = 0; i <= lastIndex; i++)
    {
        if (theArray[i] == findLargest())
        {
            reached = true;
            lastIndex--;
        }
        if (reached)
        {
            theArray[i] = theArray[i+1];
        }
    }
}

// insert into array at specified location
void ArrayInt::insertAt(int index, int value)
{
    std::cout << "lastIndex / size :" << lastIndex << " : " << size << std::endl;
    if (index < 0 || index > lastIndex || index > size) // Error throw
    {
        throw std::out_of_range("Attempt to write at invalid location.");
    }

    std::cout << "lastIndex / size :" << lastIndex << " : " << size << std::endl;
    if (lastIndex >= size)
    {
        resize(size*2);
    }
    std::cout << "lastIndex / size :" << lastIndex << " : " << size << std::endl;

    lastIndex++;
    for (int i = lastIndex; i > 0; i--)
    {
        if (i >= index)
        {
            theArray[i] = theArray[i-1];
        }
        if (i == index)
        {
            theArray[i] = value;
            break;
        }
    }
}

// remove an item and compress the array
int ArrayInt::removeAt(int index)
{

    /*if (lastIndex <= 0)
    {
        throw std::out_of_range("Attempt to remove from empty array.");
    }
    if (index < 0 || index > lastIndex || index > size)
    {
        throw std::out_of_range("Attempt to remove from invalid location.");
    }

    bool reached = false;
    for (int i = 0; i < lastIndex; i++)
    {
        if (i == index)
        {
            reached = true;
            lastIndex--;
        }
        if (reached)
        {
            theArray[i] = theArray[i+1];

        }
    }*/
    return index;
}

// use append, remove, and findLargest to arrange values in descending order
void ArrayInt::solveThink(int *values, int numValues)
{

}

