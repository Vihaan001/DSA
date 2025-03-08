/*
Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an inversion
if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to count the number
of inversions in an array.
*/
#include <iostream>
using namespace std;
int main()
{
    int arr[5] = {4, 3, 1, 5, 2};
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = i; j < 5; j++)
        {
            if (i < j)
            {
                if (arr[i] > arr[j])
                {
                    cout << '(' << arr[i] << ',' << arr[j] << ')' << endl;
                }
            }
        }
    }
    return 0;
}