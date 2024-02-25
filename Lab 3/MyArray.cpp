#include "MyArray.h"
#include <iostream>
using namespace std;

    // Create empty array.
    // PROMISES: size() == 0.
  MyArray::MyArray(){
    
    storageM = new EType[0];
  }
  
    // Create object by copying a built-in array.
    // REQUIRES
    //   sizeA >= 0. Elements builtin[0] ... builtin[sizeA - 1] exist.
    // PROMISES
    //   size() == sizeA.
    //   For i from 0 to sizeA-1, element i of object == builtin[i]. 
  MyArray::MyArray(const EType *builtin, int sizeA){
     if (sizeA < 0) {
        cerr << "Error: Cannot create an array with a negative size." << endl;
        // Handle the error as per your application requirements
    }

    sizeM = sizeA;
    storageM = new EType[sizeM];

    for (int i = 0; i < sizeM; ++i) {
        storageM[i] = builtin[i];
    }
}
  
    

  MyArray::MyArray(const MyArray& source){
    sizeM = source.sizeM;
    storageM = new EType[sizeM];
    for (int i = 0; i < sizeM; ++i) {
        storageM[i] = source.storageM[i];
    }
  }

  MyArray& MyArray::operator =(const MyArray& rhs){
    if (this == &rhs) {
        return *this; // Self-assignment, no action needed
    }
    // Deallocate the old storageM
    delete[] storageM;
    
    // Copy size and create new storageM
    sizeM = rhs.sizeM;
    storageM = new EType[sizeM];
    
    // Copy elements
    for (int i = 0; i < sizeM; ++i) {
        storageM[i] = rhs.storageM[i];
    }
    
    return *this;
}
  MyArray::~MyArray(){
    delete[] storageM;
  }
    // PROMISES: Return value is number of elements stored.
  int MyArray::size() const{
     return sizeM;
  }
  
    // REQUIRES: 0 <= i && i < size().
    // PROMISES: Return value is a reference to element i of array.
  EType MyArray::at(int i) const{
    if (i < 0 || i >= sizeM) {
        cerr << "Error: Index out of bounds." << endl;
        exit(1);
    }
    return storageM[i];
  }
  
    // REQUIRES: 0 <= i && i < size().
    // PROMISES: assigns new_value to the ith element of storageM 
  void MyArray::set(int i, EType new_value){
    if (i < 0 || i >= sizeM) {
        cerr << "Error: Index out of bounds." << endl;
        // Handle the error as per your application requirements
    }
    storageM[i] = new_value;
}
  
    // REQUIRES: new_size >= 0.
    // PROMISES
    //   size() == new_size.
    //   If the operation shrinks the array or does not change the size,
    //   values of elements 0, 1, ... new_size - 1 are preserved.
    //   If the operation increases the size,
    //   values of elements 0, 1, ... one less than the old size
    //   are preserved.
  void MyArray::resize(int new_size){
    if (new_size < 0) {
        cerr << "Error: Cannot resize to a negative size." << endl;
        // Handle the error as per your application requirements
    }

    // Create a new temporary array with the new size
    EType* newStorage = new EType[new_size];

    // Copy elements from the old array to the new array
    int minSize = (new_size < sizeM) ? new_size : sizeM;
    for (int i = 0; i < minSize; ++i) {
        newStorage[i] = storageM[i];
    }

    // Deallocate the old storageM
    delete[] storageM;

    // Update the size and storageM pointer
    sizeM = new_size;
    storageM = newStorage;
  }
  


// MEMORY MANAGEMENT STRATEGY
// 
//   storageM should point to a dynamic array of exactly sizeM elements.
//   constructors must allocate the array, and the destructor must deallocate it.
//   To change the size of the array, resize must allocate a new array,
//   copy elements from the old array, and deallocate the old array.
//
// NOTE
//   It may seem bizarre, but it's possible to allocate a dynamic
//   array with zero elements.  For example, the statement
//      storageM = new EType[0];
//   gives storageM the address of an array of size 0.
//   The advantage of this is that you don't have to write code
//   to handle empty arrays differently from non-empty arrays.