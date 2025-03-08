#include <iostream>
#define MAX 100
using namespace std;
void swap(int, int);
class Array
{
private:
    int *arr;
    int size;
    int length;

public:
    Array(int size)
    {
        this->size = size;
        length = 0;
        this->arr = new int[size];
    }
    // Declare a Constructor for Array class

    ~Array()
    {
        delete[] arr;
    }

    void Display()
    {
        int i;
        for (i = 0; i < length; i++)
            cout << arr[i] << endl;
        return;
    }
    // Shows Array till Length

    void Append(int x)
    {
        if (length < size)
        {
            arr[length] = x;
            length++;
        }
        else
            cout << "Array is Full !!" << endl;
        return;
    }
    // Inputs in Array is length<size

    void Insert(int index, int x)
    {
        if (index <= length)
        {
            if (length < size)
            {
                for (int i = length - 1; i >= index; i--)
                {
                    arr[i + 1] = arr[i];
                }
                arr[index] = x;
                length++;
            }
            else
                cout << "Array is Full !!" << endl;
            return;
        }
        else
            cout << "Can't Insert" << endl;
    }
    // Inserts at a particular index

    void Delete(int index)
    {
        if (index < length && index > 0)
        {
            for (int i = index; i < length; i++)
            {
                arr[i] = arr[i + 1];
            }
            length--;
            cout << "Value Deleted !!" << endl;
        }
        else
            cout << "No Value Found at the Given Index" << endl;
        return;
    } // Deletes an Element

    void LinearSearch(int x)
    {
        int i;
        bool flag = 0;
        for (i = 0; i < length; i++)
        {
            if (arr[i] == x)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            cout << "Number Found At Index : " << i << endl;
        else
            cout << "Number Not Found !!!" << endl;
        return;
    }
    void BinarySearch(int x)
    {
        int min = 0, max = length - 1;
        bool flag = 0;
        int index;
        while (min < max)
        {
            int mid = (min + max) / 2;
            if (arr[mid] == x)
            {
                flag = 1;
                index = mid;
                break;
            }
            else if (arr[mid] < x)
                min = mid + 1;
            else if (arr[mid] > x)
                max = mid - 1;
        }
        if (flag == 1)
            cout << "Number Found at index : " << index << endl;
        else
            cout << "Not Found !!!" << endl;
        return;
    }
    void Get(int index)
    {
        if (index <= length)
            cout << arr[index] << endl;
        else
            cout << "No Value Found !!" << endl;
        return;
    }
    void Set(int index, int x)
    {
        arr[index] = x;
        return;
    }
    void Max()
    {
        int max = arr[0];
        for (int i = 0; i < length; i++)
        {
            if (max < arr[i])
            {
                max = arr[i];
            }
        }
        cout << max << endl;
        return;
    }
    void Min()
    {
        int min = arr[0];
        for (int i = 0; i < length; i++)
        {
            if (min > arr[i])
            {
                min = arr[i];
            }
        }
        cout << min << endl;
        return;
    }
    void Reverse()
    {
        for (int i = 0; i < length / 2; i++)
        {
            int temp = arr[i];
            arr[i] = arr[length - i];
            arr[length - i] = temp;
        }
        return;
    }
    int Sum()
    {
        int s = 0;
        for (int i = 0; i < length; i++)
        {
            s = s + arr[i];
        }
        return s;
    }
    // Returns Sum of the elements of Array.
    void LeftShift()
    {
        for (int i = 0; i < length; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[length - 1] = 0;
        return;
    }
    // Shifts the Elements to the Left
    void LeftRotate()
    {
        int temp = arr[0];
        LeftShift();
        arr[length - 1] = temp;
        return;
    }
    // Rotates the Elements to the Left and first one goes to the last
    bool isSorted()
    {
        for (int i = 0; i < length - 1; i++)
        {
            if (arr[i] > arr[i + 1])
                return 0;
        }
        return 1;
    }
    void InsertInSorted(int x)
    {
        if (length < size)
        {
            if (!isSorted())
            {
                cout << "Array is not Sorted !!" << endl;
                return;
            }
            else
            {
                int i;
                for (i = length - 1; arr[i] >= x; i--)
                {
                    arr[i + 1] = arr[i];
                }
                arr[i + 1] = x;
                length++;
                cout << "Inserted !!" << endl;
                return;
            }
        }
        else
        {
            cout << "Array is Full !!" << endl;
            return;
        }
    }
    // Not Insertion Sort, it Just inserts an element in a sorted Array
    void NegativeonLeft(int arr[], int length)
    {
        int i = 0;
        int j = length - 1;
        while (i < j)
        {
            // Move i forward until we find a positive number
            while (i < j && arr[i] < 0)
            {
                i++;
            }
            // Move j backward until we find a negative number
            while (i < j && arr[j] > 0)
            {
                j--;
            }
            // Swap positive number at i and negative number at j
            if (i < j)
            {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
    }

    // Arranges all Negatives on the Left and Positives on the right.
    // This has Time Complexity as O(n)
    void MergeSort(Array a, Array b)
    {
        if (this->size >= a.size + b.size)
        {
            if (a.isSorted() && b.isSorted())
            {
                int i = 0;
                int j = 0;
                int k = 0;
                while (i < a.length && j < b.length)
                {
                    if (a.arr[i] < b.arr[j])
                    {
                        this->arr[k] = a.arr[i];
                        i++;
                        k++;
                    }
                    else
                    {
                        this->arr[k] = b.arr[j];
                        j++;
                        k++;
                    }
                }
                for (; i < a.length; i++)
                {
                    this->arr[k] = a.arr[i];
                    k++;
                }
                for (; j < b.length; j++)
                {
                    this->arr[k] = b.arr[j];
                    k++;
                }

                this->length = k;
            }
            else
            {
                cout << "Arrays are not Sorted !!" << endl;
            }
        }
        else
            cout << "Arrays is too small !!" << endl;
    }
};
void swap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
    return;
}
int main()
{
    Array a(100);
    int expt;
    do
    {
        cout << "Menu" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete (Input Index)" << endl;
        cout << "3. Search" << endl;
        cout << "4. Sum" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter Your Choice : ";
        cin >> expt;
        switch (expt)
        {
        case 1:
            int x, y;
            cout << "Enter Index : ";
            cin >> x;
            cout << "Enter Element : ";
            cin >> y;
            a.Insert(x, y);
            break;
        case 2:
            cout << "Enter The Index : ";
            int x1;
            cin >> x1;
            a.Delete(x1);
            break;
        case 3:
            cout << "Enter The Element to Search : ";
            int x2;
            cin >> x2;
            a.BinarySearch(x2);
            break;
        case 4:
            int x3;
            x3 = a.Sum();
            cout << "The Sum of Array is : " << x3 << endl;
            break;
        case 5:
            a.Display();
        }
    } while (expt < 6);
    return 0;
}