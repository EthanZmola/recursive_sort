#include <iostream>
#include <cmath>

using namespace std;



//Recursive sort of integer array of any size.
void sortRec(int sorting[], int iteration, int size, int compare)
{


    //cout << "it:" <<iteration << " "<< ((size*(size-1))/2)<< " ";
    int temp = 0;

    // double topFact = tgamma(size+1);
    // double botFact = tgamma(size-compare);
    // double combined = topFact/botFact;
    // cout << topFact << " " << botFact << " " << combined << " " << iteration/combined << " " << endl;

    // if ((iteration)/combined == 1)
    // {
    //     compare++;
    // }

    int newComp = size- compare -2;
    int compareSum = (newComp*(newComp+1))/2;
    int sizeSum = (size*(size-1))/2;
    int checker = sizeSum-compareSum;
    cout << newComp <<" " << compareSum << " " << sizeSum << " " << checker << endl;
    if ((iteration)/checker == 1)
    {
        compare++;
    }


    //compare (+ iter% size- compare?)

    //cout << "Compare val " <<compare << ": " << sorting[compare] << " Compare val "<<compare+1 +(iteration%(size-compare-1)) << ": " <<sorting[compare+1 +(iteration%(size-compare-1))] << endl;

    //int compareVal = 
    //Reordering elements.
    if (sorting[compare] > sorting[compare+1 + (iteration%(size-compare-1))])
    {
        int temp = sorting[compare+1 + (iteration%(size -compare-1))];

        sorting[compare +1+ (iteration%(size -compare-1))] = sorting[compare];
        sorting[compare] = temp;
    }

    //end case ceil(((size-1)*size)/2.0)
    if ((iteration == size*(size-1)) || compare==(size-2))
    {
        return;
    }

    iteration++;


    sortRec(sorting, iteration, size, compare);
}


int main() 
{

    int sortArray[7] = {1000000,2,1,3,55,77,-9};

    sortRec(sortArray, 0, 7, 0);

    cout << endl << "Check" << endl;

    //Print to check if array sorted.
    for (int i =0; i <7; i++)
    {
        cout << sortArray[i] << " ";
    }
    cout << endl;

    return 0;
}