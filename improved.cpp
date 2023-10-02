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


    cout << "it:" <<iteration << " "<< ((size*(size-1))/2)<< " ";
    int temp = 0;

    cout << "f";
    int topFact = tgamma(size);
    int botFact = tgamma(size-compare);
    int combined = topFact/botFact;
    cout << "in" << " ";
    cout << topFact << " " << botFact << " " << combined << " " << iteration/combined << " ";

    if ((iteration)/combined == 1)
    {
        compare++;
    }


//cpompare (+ iter% size- compare?)

    //Reordering elements.
    if (sorting[compare] > sorting[compare + (iteration%(size -compare))])
    {
        int temp = sorting[compare + (iteration%(size -compare))];
        sorting[compare + (iteration%(size -compare))] = sorting[compare];
        sorting[compare] = temp;
    }

    //end case
    if (iteration == (((size*(size-1))/2))-1)
    {
        return;
    }

    iteration++;


    sortRec(sorting, iteration, size, compare);
}


int main() 
{
    int sortArray[3] = {5,3,2};

    sortRec(sortArray, 0, 3, 0);

    cout << endl << "Check" << endl;

    //Print to check if array sorted.
    for (int i =0; i <3; i++)
    {
        cout << sortArray[i] << " ";
    }
    cout << endl;

    return 0;
}