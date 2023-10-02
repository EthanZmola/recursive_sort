#include <iostream>
#include <cmath>

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
void sortRec(int sorting[], int iteration, int size, int compare)
{
    int temp = 0;

    int topFact = tgamma(size);
    int botFact = tgamma(size-compare-1);
    int combined = topFact/botFact;

    if (iteration/topFact == 1)
    {
        compare++;
    }


    //Reordering elements.
    if (sorting[compare] > sorting[iteration +1])
    {
        int temp = sorting[iteration +1];
        sorting[iteration +1] = sorting[compare];
        sorting[compare] = temp;
    }

    iteration++;

    //End case
    //sorting[0] < sorting[1] && sorting[1] < sorting[2] && sorting[2] < sorting[3] && sorting[3] < sorting[4]
    if (testOrder(sorting, 0, size))
    {
        return;
    }
    else{
        sortRec(sorting, iteration, size, compare);
    }
}


int main() 
{
    int sortArray[10] = {5,3,2,1,4,6,43,56,2,-56};

    sortRec(sortArray, 0, 10, 0);


    //Print to check if array sorted.
    for (int i =0; i <10; i++)
    {
        cout << sortArray[i] << " ";
    }
    cout << endl;

    return 0;
}