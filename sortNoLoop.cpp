#include <iostream>

using namespace std;

bool testOrder(int sorted[], int iter, int size)
{
    if (iter == size-1)
    {
        return true;
    }

    if (sorted[iter] > sorted[iter+1])
    {
        return false;
    }

    return testOrder(sorted, iter+1, size);
}


void sortRec(int sorting[], int iteration, int size)
{
    int temp = 0;
    if (iteration == size-1)
    {
        iteration = 0;
    }
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


    for (int i =0; i <10; i++)
    {
        cout << sortArray[i] << " ";
    }
    cout << endl;

    return 0;
}