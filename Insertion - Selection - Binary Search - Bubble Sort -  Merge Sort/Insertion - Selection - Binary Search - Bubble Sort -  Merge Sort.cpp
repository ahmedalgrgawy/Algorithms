#include <iostream>
#include <algorithm>
using namespace std;



void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void enterArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int ele;
        cin >> ele;
        arr[i] = ele;
    }
}

// Insertion Sort Algorithm + best o(n) , average - worst o(n^2)
void insertionSort(int arr[], int size)
{
    int ele, index;
    for (int i = 1; i < size; i++)
    {
        ele = arr[i];  // 50
        index = i - 1; // 0

        while (index >= 0 && arr[index] > ele) // arr[index] < ele
        {
            arr[index + 1] = arr[index];
            index = index - 1;
        }

        arr[index + 1] = ele;
    }
}

// Selection Sort Algorithm + best o(n) , average - worst o(n^2)
void selectionSort(int arr[], int size)
{
    int minIndex;
    for (int i = 0; i < size - 1; i++)
    {
        minIndex = i; // 0
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex]) // arr[j] > arr[minIndex] - max not min
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}

// Bubble Sort Algorithm + best - average - worst o(n^2)
void bubbleSort(int arr[], int size)
{
    bool statue = true;
    int passesCounter = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]) // arr[j] < arr[j + 1]
            {
                swap(arr[j], arr[j + 1]);
                statue = false;
            }
            passesCounter++;
        }
        if (statue == true)
            break;
    }

    cout << "Passes Number: " << passesCounter << endl;
}

// Merge Sort Algorithm + best - average - worst o(n log(n))
void merge(int arr[], int l, int m, int r)
{

    int leftArrSize = m - l + 1;
    int rightArrSize = r - m;

    int *leftArr = new int[leftArrSize],
        *rightArr = new int[rightArrSize];

    for (int i = 0; i < leftArrSize; i++) // adding the left sub array elements
    {
        leftArr[i] = arr[l + i];
    }
    for (int j = 0; j < rightArrSize; j++) // adding the right sub array elements
    {
        rightArr[j] = arr[m + 1 + j];
    }

    // i,j,k are references to the arrays
    int i, j, k;
    i = 0;
    j = 0;
    k = l;

    while (i < leftArrSize && j < rightArrSize)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < leftArrSize)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < rightArrSize)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int binarySearch(int arr[], int l, int r, int k)
{
    while (l <= r)
    {
        int m = (l + r) / 2;

        if (arr[m] == k)
            return m;

        if (arr[m] > k)
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}

int main()
{
    int size;

    cout << "Enter Array Size" << endl;
    cin >> size;
    int arr[size];

    int algoChoice;

    string anotherSort = "yes";

    do
    {
        cout << "Enter Elements" << endl;
        enterArr(arr, size);
        cout << "Choose Your Algorithm To Sort: (1) Insertion - (2) Selection - (3) Bubble - (4) Merge" << endl;
        cin >> algoChoice;
        switch (algoChoice)
        {
        case 1:
            insertionSort(arr, size);
            print(arr, size);
            break;
        case 2:
            selectionSort(arr, size);
            print(arr, size);
            break;
        case 3:
            bubbleSort(arr, size);
            print(arr, size);
            break;
        case 4:
            mergeSort(arr, 0, size - 1);
            print(arr, size);
            break;
        }

        cout << "Do U Need Another Sort Method? (yes/no)" << endl;
        cin >> anotherSort;

    } while (anotherSort == "yes");

    return 0;
}
