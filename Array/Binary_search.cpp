#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int low = 0, high = (sizeof(arr) / sizeof(int)) - 1;
    int n;
    cout << "Enter The Number to Search : ";
    cin >> n;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == n)
        {
            cout << "Number Found at index : " << mid;
            break;
        }
        if (arr[mid] > n)
        {
            high = mid - 1;
        }
        if (arr[mid] < n)
        {
            low = mid + 1;
        }
    }
    return 0;
}