#include <iostream>
#include <string>
#include <sstream>

#include "QS.h"

/*
* sortAll()
*
* Sorts elements of the array.  After this function is called, every
* element in the array is less than or equal its successor.
*
* Does nothing if the array is empty.
*/
void QS:: sortAll(){
    cout << "insertPos start of sort: " << insertPos << endl;
    cout << "Sum: " << (9/2) << endl;
    //return;
    quicksort(0, (insertPos - 1));
    cout << "SORT FUNCTION" << endl;
}

void QS:: quicksort(int left, int right){
    //cout << "First quick line" << endl;
    if((right - left) == 0){
        return;
    }
    int firstPivot = medianOfThree(left, right);
    if(firstPivot == -1){
        return;
    }
    int myPivot = partition(left, right, firstPivot);
    if(myPivot == -1){
        return;
    }
    quicksort(left, myPivot - 1); //left side
    quicksort(myPivot + 1, right); //right side
    //return;
}

/*
* medianOfThree()
*
* The median of three pivot selection has two parts:
*
* 1) Calculates the middle index by averaging the given left and right indices:
*
* middle = (left + right)/2
*
* 2) Then bubble-sorts the values at the left, middle, and right indices.
*
* After this method is called, data[left] <= data[middle] <= data[right].
* The middle index will be returned.
*
* Returns -1 if the array is empty, if either of the given integers
* is out of bounds, or if the left index is not less than the right
* index.
*
* @param left
* 		the left boundary for the subarray from which to find a pivot
* @param right
* 		the right boundary for the subarray from which to find a pivot
* @return
*		the index of the pivot (middle index); -1 if provided with invalid input
*/
int QS:: medianOfThree(int left, int right){
    int middle = (left + right)/2;
    int tmp;
    if((insertPos == 0) || (left < 0) || (right > insertPos - 1) || (left >= right) ){
        return -1;
    }
    if(table[left] > table[middle]){
        tmp = table[left];
        table[left] = table[middle];
        table[middle] = tmp;
    }
    if(table[right] < table[middle]){
        tmp = table[middle];
        table[middle] = table[right];
        table[right] = tmp;
    }
    if(table[middle] < table[left]){
        tmp = table[left];
        table[left] = table[middle];
        table[middle] = tmp;
    }
    return middle;
}

/*
* Partitions a subarray around a pivot value selected according to
* median-of-three pivot selection.  Because there are multiple ways to partition a list,
* we will follow the algorithm on page 611 of the course text when testing this function.
*
* The values which are smaller than the pivot should be placed to the left
* of the pivot; the values which are larger than the pivot should be placed
* to the right of the pivot.
*
* Returns -1 if the array is null, if either of the given integers is out of
* bounds, or if the first integer is not less than the second integer, or if the
* pivot is not within the sub-array designated by left and right.
*
* @param left
* 		the left boundary for the subarray to partition
* @param right
* 		the right boundary for the subarray to partition
* @param pivotIndex
* 		the index of the pivot in the subarray
* @return
*		the pivot's ending index after the partition completes; -1 if
* 		provided with bad input
*/
int QS:: partition(int left, int right, int pivotIndex){
    if((insertPos == 0) || (left < 0) || (right > insertPos -1) || (left >= right) || (pivotIndex > right) ){
        return -1;
    }
    //int middle = medianOfThree(left, right);
    //right = right -1;

    int tmp = table[pivotIndex];
    table[pivotIndex] = table[left];
    table[left] = tmp;
    
    int up = left + 1;
    int down = right;
    
    int newPivotIndex = left;
    
    int tempcounter = 10;
    int temp = 0;
    //cout << "Current Table: ";
    /*
    for (int i = 0; i < myCapacity; ++i){
        cout << table[i] << ",";
    }
    cout << endl;
    */
    do{
        while((up < right) && (table[up] <= table[newPivotIndex])){ // since we are moving it to the far left
            /*
            for (int i = 0; i < myCapacity; ++i){
                cout << table[i] << ",";
            }
            cout << endl;
            cout << "while up: " << up << endl;
            cout << "while pivot: " << newPivotIndex << endl;
            cout << "while down: " << down << endl;
            cout << "While table[up]: " << table[up] << endl;
            cout << "While table[pivot]:" << table[newPivotIndex] << endl << endl;
            */
            up = up + 1;
        }
        while((table[down] > table[newPivotIndex]) && (down > left)){
            /*
            cout << "Down: " << down << endl;
            cout << "up: " << up << endl;
            cout << "Left: " << left << endl;
            cout << "pivotIndex: " << newPivotIndex << endl << endl;
            */
            down = down - 1;
        }
        if(up < down){
            //cout << "if statement " << endl;
            tmp = table[down];
            table[down] = table[up];
            table[up] = tmp;
           
        }
    }while(up < down);
    //cout << "FINISHED do" << endl;
    tmp = table[left];
    table[left] = table[down];
    table[down] = tmp;
    
    
    return down;
}

/*
* Produces a comma delimited string representation of the array. For example: if my array
* looked like {5,7,2,9,0}, then the string to be returned would look like "5,7,2,9,0"
* with no trailing comma.  The number of cells included equals the number of values added.
* Do not include the entire array if the array has yet to be filled.
*
* Returns an empty string, if the array is NULL or empty.
*
* @return
*		the string representation of the current array
*/
string QS:: getArray() const{
    stringstream ss;
    if(insertPos != 0 ){
        for(int i = 0; i < insertPos; ++i){
            if(i < (insertPos - 1)){
                ss << table[i] << ",";
            }else{
                ss << table[i];
            }
        }
    }else{ // if we haven't reached capacity
        ss << "";
    }
     return ss.str();   
}

/*
* Returns the number of elements which have been added to the array.
*/
int QS:: getSize() const{
    return insertPos;
}

bool QS:: addToArray(int value){
 if(insertPos < myCapacity){
     table[insertPos] = value;
     insertPos = insertPos + 1;
     
     //cout << "TEST: addToArray TRUE" << endl; // FIXME
     return true;
 }else{
     cout << "TEST: addToArray FALSE" << endl; // FIXME
     return false;
 }
}

/*
* Dynamically allocates an array with the given capacity.
* If a previous array had been allocated, delete the previous array.
* Returns false if the given capacity is non-positive, true otherwise.
*
* @param
*		size of array
* @return
*		true if the array was created, false otherwise
*/
bool QS::createArray(int capacity){
    myCapacity = capacity;
    if(capacity < 0){ // or can it be 0??
        return false;
    }
    if(table != 0){
        delete [] table;
        table = 0;
    }
    table = new int[capacity];
    insertPos = 0;
    return true;
}

/*
* Resets the array to an empty or NULL state.
*/
void QS:: clear(){
    
    delete [] table;
    table = 0;
    myCapacity = 0;
    insertPos = 0;

    cout << "CLEAR FUNCTION";
}

	
