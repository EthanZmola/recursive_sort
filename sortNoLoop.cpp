#include <iostream>

using namespace std;

//Recursive check if array is sorted
bool testOrder(int sorted[], int iter, int size)
{   
    //Reaches end of array and all in order so return true.
    if (iter == size-1)
    {
        return true;
    }

    //If first element is greater than second element is not ordered yet.
    if (sorted[iter] > sorted[iter+1])
    {
        return false;
    }

    //Recursive portion
    return testOrder(sorted, iter+1, size);
}

//Recursive sort of integer array of any size.
void sortRec(int sorting[], int iteration, int size)
{
    int temp = 0;

    //May want to switch to modulo with divison to do a more proper bubble sort. Think this is O(n^3) currently.
    if (iteration == size-1)
    {
        iteration = 0;
    }
    //Reordering elements.
    if (sorting[iteration] > sorting[iteration +1])
    {
        int temp = sorting[iteration +1];
        sorting[iteration +1] = sorting[iteration];
        sorting[iteration] = temp;
    }

    iteration++;

    //End case
    //sorting[0] < sorting[1] && sorting[1] < sorting[2] && sorting[2] < sorting[3] && sorting[3] < sorting[4]
    if (testOrder(sorting, 0, size))
    {
        return;
    }
    else{
        sortRec(sorting, iteration, size);
    }
}


int main() 
{
    int sortArray[10] = {5,3,2,1,4,6,43,56,2,-56};

    sortRec(sortArray, 0, 10);


    //Print to check if array sorted.
    for (int i =0; i <10; i++)
    {
        cout << sortArray[i] << " ";
    }
    cout << endl;

    return 0;
}