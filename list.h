/*
* Programmer: George Mausshardt
* 
* FileName: list.h
* Purpose: Header file for the List class
*/

#ifndef LIST_H
#define LIST_H

#include <cstdlib>
#include <iostream>
#include <cmath>

#include "templates.h"
#include "list_node.h"

using std::cout;
using std::cin;
using std::ostream;
using std::istream;
using std::endl;
using std::size_t;

/* CLASS: List
     PURPOSE: Provide an easy-to-use vector, a common structure used in linear
       algebra, as well as defining a number of function to operate on multiple
       vectors.  To avoid conflicts with the C++ vectors, these are named 
       Lists. 
     MEMBER VARIABLES:
       nsize m_size - The number of elements in the List
       T* m_data[] - A pointer to the data contained in the List
*/
template <class T>
class List
{
  public:
    /*
      CONSTRUCTOR: List()
      PRE: None
      POST: Creates an empty, 0-sized List
      PURPOSE: Default constructor. Creates a List of size 0.
        This means there is no data in a List created by default!
        Be careful when using this constructor!
    */
    List();
   
    /*
      CONSTRUCTOR: List(nsize const vector_size)
        Input: vector_size - the number of elements in
          the newly created List
      PRE: vector_size must be greater than 0. A vector with size less than
        zero is undefined!
      POST: Creates a List of size vector_size, filled with 0's
      PURPOSE: Size-fed constructor. Creates a List of size 
        vector_size. Every element in this vector will be a 0.  Make sure
        to fill it with data before using it or errors may be thrown!
    */
    List(T input_value);
    
    /*
      CONSTRUCTOR: List(const List<T>& right_hand_side)
        Input: right_hand_side - the List to which this new instance
          will be set equal.
      PRE: Note that element-by-element assignment will occur.  Only use this
        constructor on a List that stores scalar element or elements
        that otherwise have an assignment operator (=) defined!
      POST: Constructs a new List identical to right_hand_side. Every
        element will be the same and their sizes will be set to the same value.
      PURPOSE: Copy Constructor. Used to create an identical copy to a
        List that already exists in a program.  All aspects of the 
        new List will be equal to the copied version.
    */
    List(const List<T>& input_list);

    /*
      DESTRUCTOR: ~List()
      PRE: None
      POST: Deletes the pointer to the m_data array
      PURPOSE: Called when a List leaves scope. Automatically
        returns memory to the freestore. A STORE WHERE THINGS ARE FREE? COOL!
    */
    ~List();

    /*
      FUNCTION: void copy(const List<T>& right_hand_side)
        Input: right_hand_side - the List to which this new instance
          will be set equal.
      PRE: Note that element-by-element assignment will occur.  Only use this
        function on a List that stores scalar element or elements
        that otherwise have an assignment operator (=) defined!
      POST: Constructs a new List identical to right_hand_side. Every
        element will be the same and their sizes will be set to the same value.
      PURPOSE: Copier Function. Used to create an identical copy to another
        List in the same program.  All aspects of the 
        new List will be equal to the copied version.
    */
    void copy(const List<T>& right_hand_side);

    /*
      OPERATOR: T& operator[](nsize const data_location)
        Input: nsize data_location - the integer index of 
          a specific number in the List. Zero indexed.
        Output: The numeric at the position defined by data_location
      PRE: data_location between 0 and List_size - 1, inclusive
      POST: Returns the data at data_location, as defined above
      PURPOSE: Indexing operator. Make the List able to be referenced
        the same as a array. 
      NOTE: This version of the function is called on assignment. The
        original List is changed!
    */
    T& operator[](nsize const data_location);

    /*
      OPERATOR: T& operator[](nsize const data_location) const
        Input: nsize data_location - the integer index of 
          a specific number in the List. Zero indexed.
        Output: The numeric at the position defined by data_location
      PRE: data_location between 0 and List_size - 1, inclusive
      POST: Returns the data at data_location, as defined above
      PURPOSE: Indexing operator. Make the List able to be referenced
        the same as a array. 
      NOTE: This version of the function is called for reference. The
        original List is NOT changed!
    */
    T& operator[](nsize const data_location) const;

    ListNode<T>* getNode(nsize const data_location) const;

    
    /* 
      OPERATOR List<T>& operator=(
                                       const List<T>& right_hand_side)
        Input: right_hand_side - the List to be set equal to
        Output: *this, after being set equal to right_hand_side
      PRE: None
      POST: This List is set equal to right_hand_side
      PURPOSE: Assignment operator - makes this List a replica of
        right_hand_side.
    */
    List<T>& operator=(const List<T>& right_hand_side);
          
    /*
      OPERATOR: bool operator==(const List<T>& right_hand_side) const
        Input: const List<T>& right_hand_side - the List to
          compare to the List stored in this class
        Output: True if the two Lists are replicas of each other.
          False otherwise.
      PRE: Comparisons between each individual element are executed. Do not
        call this function unless the elements in this List are scalar
        or have their equal operator (==) defined!
      POST: Returns true or false as defined above. No side effects.
      PURPOSE: Equality operator - Tests if two Lists are the same
    */
    bool operator==(const List<T>& right_hand_side) const;
      
    /*
      OPERATOR: bool operator!=(const List<T>& right_hand_side) const
        Input: const List<T>& right_hand_side - the List to
          compare to this List
        Output: True if the two Lists are NOT replicas of each other.
          False if they are exactly the same.
      PRE: Comparisons between each individual element are executed. Note that 
           this function invokes the == operator on individual elements, but
           does NOT invoke the != operator on individual elements.  Therefore,
           do not  call this function unless the elements in this List 
           are scalar or have their equal operator (==) defined!
      POST: Returns true or false as defined above. No side effects.
      PURPOSE: Equality operator - Tests if two Lists are different
    */
    bool operator!=(const List<T>& right_hand_side) const;

    /*
      OPERATOR: ostream& operator<<(ostream& out, 
                                const List<U>& calling_List);
        Input: ostream& out - the stream used to display information about
          the List to the screen
               const List<U> calling_List - the List
          to be displayed to the screen in proper format
        Output: Functions like a cout statement.  The List is output
          to the screen in the format [e1, e2, e3 ... ek]
      PRE: Note that this function attempts to output each element in turn.
        Ensure that complex or programmer-defined objects have an output 
        operator defined!
      POST: Outputs the List to the screen in the foramt defined
        above. 
      PURPOSE: Allow "cout << List" to function correctly. Called
        when the List must be output.
    */
    template <class U>
    friend ostream& operator<<(ostream& out, 
                               const List<U>& calling_List);

      void clear();
      
      void append(nsize inputData);
      
      void removeAtIndex(nsize inputIndex);
      
      /* TO DO: 
       * --removeByValue
       * --addAtLocation
       * --sort
       * 
    
      /* 
      	FUNCTION: nsize size() const
        	Output: Finds and returns m_size, the number of elements in this vector
      	PRE: None
      	POST: Returns m_size.  This value represents the size, or number of
        	elements in this Maatrix_Vector
      	PURPOSE: Serve as the accessor for the variabale m_size. Commonly
        	used in for-loops to determine the length of the List
       */
      nsize size() const;

  private:
    ListNode<T> * m_root; // A pointer to the data stored in the List
    nsize m_size; // The number of elements in the List
};

#include "list.hpp"
#endif // LIST_H