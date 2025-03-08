#include <iostream>
using namespace std;
void Single_Missing(int *arr, int n)
{
    int d = arr[0] - 0;
    int i = 0;
    for (; i < n; i++)
    {
        if (arr[i] - i != d)
        {
            cout << "Missing Element is : " << d + i << endl;
            break;
        }
    }
    return;
}
// Prints Single Missing Element in a Sorted Array.

void Multiple_Missing(int *arr, int n)
{
    int d = arr[0] - 0;
    int i = 0;
    for (; i < n; i++)
    {
        if (arr[i] - i != d)
        {
            while (d < arr[i] - i)
            {
                cout << "Missing Element is : " << d + i << endl;
                d++;
            }
        }
    }
    return;
}
// Prints Multiple Missing ELements in a Sorted Array.

int Max(int *arr, int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}
// Returns Maximum of an Array.

int Min(int *arr, int n)
{
    int min = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}
// Retiurns Minimum of an Array.
void Hash_Missing(int *arr, int n)
{
    int max = Max(arr, n);
    int min = Min(arr, n);
    int *brr;
    brr = new int[max + 1];
    for (int i = 0; i <= max; i++)
    {
        brr[i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        brr[arr[i]]++;
    }
    for (int i = min; i <= max; i++)
    {
        if (brr[i] == 0)
        {
            cout << "Missing Element is : " << i << endl;
        }
    }
    return;
}
// Prints Multiple Missing Elements of an UnSorted Array.
void Sort_Dupe(int *arr, int n)
{
    int last_dupe = 0;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] == arr[i + 1]) && last_dupe != arr[i])
        {
            cout << arr[i] << " is a Duplicate Element." << endl;
            last_dupe = arr[i];
        }
    }
    return;
}
// Prints the Duplicate Elements in a Sorted Array.
void Sort_Dupe_Count(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if ((arr[i] == arr[i + 1]))
        {
            int j = i + 1;
            while (arr[j] == arr[i])
                j++;
            cout << arr[i] << " is a Appearing " << j - i << " times" << endl;
            i = j - 1;
        }
    }
    return;
}
// Prints the Number of Times Duplicates are appearing in a Sorted Array.
void Hash_Dupe_Finder(int *arr, int n)
{
    int max = Max(arr, n);
    int min = Min(arr, n);
    int *brr;
    brr = new int[max + 1];
    for (int i = 0; i <= max; i++)
    {
        brr[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        brr[arr[i]]++;
    }
    for (int i = min; i <= max; i++)
    {
        if (brr[i] > 1)
        {
            cout << "Duplicate Element " << i << " is Appearing " << brr[i] << " times" << endl;
        }
    }
    return;
}
// Prints the Number of Times Duplicates are appearing in a Sorted / UnSorted Array.
void UnSorted_Dupe_Finder(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] != -1 && arr[i] == arr[j])
            {
                count++;
                arr[j] = -1;
            }
        }
        if (count > 1)
        {
            cout << arr[i] << " is Appearing " << count << " Times in the Array" << endl;
        }
    }
    return;
}
// Prints Number of Times Duplicates are appearing in an UnSorted Array.
void SumOfPair_Hash(int *arr, int n, int sum)
{
    int *H;
    int max = Max(arr, n);
    H = new int[max + 1];
    for (int i = 0; i < max; i++)
    {
        H[i] = 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (H[sum - arr[i]] > 0)
        {
            cout << "(" << sum - arr[i] << "," << arr[i] << ")" << endl;
            H[arr[i]]--;
        }
        H[arr[i]]++;
    }
}
// Prints The Pairs that Give the Sum using Hash.
void SumOfPair_Sort(int *arr, int n, int sum)
{
    for (int i = 0, j = n - 1; i < j;)
    {
        if (arr[i] + arr[j] == sum)
        {
            cout << "(" << arr[i] << "," << arr[j] << ")" << endl;
            i++;
            j--;
        }
        else if (arr[i] + arr[j] > sum)
            j--;
        else
            i++;
    }
    return;
}
// Prints the Pairs that give the sum using sorted Array.
int main()
{
    int arr[10] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
    SumOfPair_Sort(arr, 10, 10);
    return 0;
}