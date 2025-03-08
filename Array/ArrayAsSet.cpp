#include <iostream>
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
    }
    // Deletes an Element
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
    void NegativeonLeft()
    {
        int i = 0;
        int j = length - 1;
        while (i < j)
        {
            while (arr[i] < 0)
            {
                i++;
            }
            while (arr[j] > 0)
            {
                j--;
            }
            if (i < j)
            {
                swap(arr[i], arr[j]);
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
                        this->arr[k++] = a.arr[i++];
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
    // Merges a Sorted Array
    void UnionSort(Array a, Array b)
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
                    else if (a.arr[i] > b.arr[j])
                    {
                        this->arr[k] = b.arr[j];
                        j++;
                        k++;
                    }
                    else
                    {
                        this->arr[k] = a.arr[i];
                        i++;
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
    // Gives Union of Two Sorted Arrays
    void IntersectionSort(Array a, Array b)
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
                    i++;
                }
                else if (a.arr[i] > b.arr[j])
                {
                    j++;
                }
                else
                {
                    this->arr[k] = a.arr[i];
                    i++;
                    j++;
                    k++;
                }
            }

            this->length = k;
        }
        else
        {
            cout << "Arrays are not Sorted !!" << endl;
        }
    }

    // Gives Intersection of Two Sorted Arrays;
    void DifferenceSort(Array a, Array b)
    {
        if (a.isSorted() && b.isSorted())
        {
            int i = 0;
            int j = 0;
            int k = 0;
            while (i < a.length)
            {
                if (a.arr[i] == b.arr[j])
                {
                    i++;
                    j++;
                }
                else if (a.arr[i] < b.arr[j])
                {
                    this->arr[k] = a.arr[i];
                    i++;
                    k++;
                }
                else
                    j++;
            }
            for (; i < a.length; i++)
            {
                this->arr[k] = a.arr[i];
                k++;
            }
            this->length = k;
        }
        else
        {
            cout << "Arrays are not Sorted !!" << endl;
        }
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
    Array a(5), b(5), c(10);
    a.Append(2);
    a.Append(6);
    a.Append(10);
    a.Append(15);
    a.Append(25);
    b.Append(3);
    b.Append(6);
    b.Append(7);
    b.Append(15);
    b.Append(20);
    c.DifferenceSort(a, b);
    c.Display();
    return 0;
}