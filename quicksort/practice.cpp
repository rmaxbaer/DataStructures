sortAll(){

    
    //quicksort(first, pivot - 1);
    //quicksort(pivot + 1, last);
}


quicksort(left, right){ // should I give this function parameters? probably
    if((last - first) == 0){
        return;
    }
    int myMiddle = medianOfThree(left, right);
    int myPivot = partition(left, right, myMiddle); // how do I change these?
    quicksort(left, myPivot - 1); //left
    quicksort(left, myPivot + 1); //right
    
    //partition(first, pivot - 1);
}


/// I can't hear you