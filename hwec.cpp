// hwec.cpp
// Sorting

/*************************************************************************
 * AUTHOR     : Joshua Yang
 * hwec       : Sorting
 * CLASS      : CS 1C
 * SECTION    : May 13th 2019
 *************************************************************************/

#include <list>
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <algorithm>
#include <exception>
using namespace std;

void bubble_sorting(int *array, int n)
{
    // Print out 10 first and 10 last element before sorting
    int totalComparison = 0;
    int totalAssignment = 0;
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }
    cout << "...";
    for (int i = n - 10; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    bool swapped = true;
    int j = 0;
    int temp;
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    while (swapped)
    {
        swapped = false;
        j++;
        for (int i = 0; i < n - j; ++i)
        {
            totalComparison++;
            if (array[i] > array[i + 1])
            {
                totalAssignment++;
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = true;
            }
        }
    }
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    // Print after sorting
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }
    cout << "...";
    for (int i = n - 10; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "Total comparisons: " << totalComparison << endl;
    cout << "Total assignment: " << totalAssignment << endl;
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    cout << "It took me " << time_span.count() * 1000000000 << " nanoseconds." << endl;
}

void insertion_sorting(int* array, int n)
{
    // Print out 10 first and 10 last element before sorting
    int totalComparison = 0;
    int totalAssignment = 0;
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }
    cout << "...";
    for (int i = n - 10; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    int i, key, j;
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    for (i = 1; i < n; i++)
    {
        key = array[i];
        j = i - 1;
        totalComparison++;
        while (j >= 0 && array[j] > key)
        {
            totalAssignment++;
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    // Print after sorting
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }
    cout << "...";
    for (int i = n - 10; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "Total comparisons: " << totalComparison << endl;
    cout << "Total assignment: " << totalAssignment << endl;
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    cout << "It took me " << time_span.count() * 1000000000 << " nanoseconds." << endl;
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selection_sorting(int array[], int n)
{
    // Print out 10 first and 10 last element before sorting
    int totalComparison = 0;
    int totalAssignment = 0;
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }
    cout << "...";
    for (int i = n - 10; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            totalComparison++;
            if (array[j] < array[min_idx])
                min_idx = j;
        }
        // Swap the found minimum element with the first element
        totalAssignment++;
        swap(&array[min_idx], &array[i]);
    }
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    // Print after sorting
    for (i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }
    cout << "...";
    for (i = n - 10; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "Total comparisons: " << totalComparison << endl;
    cout << "Total assignment: " << totalAssignment << endl;
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    cout << "It took me " << time_span.count() * 1000000000 << " nanoseconds." << endl;
}

/* This function takes last element as pivot, places
 the pivot element at its correct position in sorted
 array, and places all smaller (smaller than pivot)
 to left of pivot and all greater elements to right
 of pivot */
int partition(int arr[], int low, int high, int &compare, int &assignment)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        compare++;
        if (arr[j] <= pivot)
        {
            assignment++;
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    assignment++;
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int &compare, int &assignment)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
         at right place */
        int pi = partition(arr, low, high, compare, assignment);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1, compare, assignment);
        quickSort(arr, pi + 1, high, compare, assignment);
    }
}

void quick_sorting(int array[], int n)
{
    // Print out 10 first and 10 last element before sorting
    int totalComparison = 0;
    int totalAssignment = 0;
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }
    cout << "...";
    for (int i = n - 10; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    int i, key, j;
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();

    quickSort(array, 0, n - 1, totalComparison, totalAssignment);

    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    // Print after sorting
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }
    cout << "...";
    for (int i = n - 10; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "Total comparisons: " << totalComparison << endl;
    cout << "Total assignment: " << totalAssignment << endl;
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    cout << "It took me " << time_span.count() * 1000000000 << " nanoseconds." << endl;
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r, int &compare, int &assignment)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        compare++;
        if (L[i] <= R[j])
        {
            assignment++;
            arr[k] = L[i];
            i++;
        }
        else
        {
            assignment++;
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
     are any */
    while (i < n1)
    {
        assignment++;
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
     are any */
    while (j < n2)
    {
        assignment++;
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
 sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r, int &compare, int &assignment)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m, compare, assignment);
        mergeSort(arr, m + 1, r, compare, assignment);

        merge(arr, l, m, r, compare, assignment);
    }
}

void merge_sorting(int array[], int n)
{
    // Print out 10 first and 10 last element before sorting
    int totalComparison = 0;
    int totalAssignment = 0;
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }
    cout << "...";
    for (int i = n - 10; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    int i, key, j;
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();

    mergeSort(array, 0, n - 1, totalComparison, totalAssignment);

    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    // Print after sorting
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }
    cout << "...";
    for (int i = n - 10; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "Total comparisons: " << totalComparison << endl;
    cout << "Total assignment: " << totalAssignment << endl;
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    cout << "It took me " << time_span.count() * 1000000000 << " nanoseconds." << endl;
}

int list1[100];
int list2[100];
int list3[100];

void shuffle(int *arr, size_t n)
{
    if (n > 1)
    {
        size_t i;
        srand(time(NULL));
        for (i = 0; i < n - 1; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = arr[j];
            arr[j] = arr[i];
            arr[i] = t;
        }
    }
}

void initialList()
{
    // list1 is initially in ascending order
    for (int i = 0; i < 100; i++)
    {
        list1[i] = i + 1;
    }

    // list2 is initially in descending order
    for (int i = 100; i > 0; i--)
    {
        list2[i] = i;
    }
    // list3 is initially in random order
    for (int i = 0; i < 100; i++)
    {
        list3[i] = i + 1;
    }
    shuffle(list3, 100);
}

int main(int agrc, char* argv[])
{
    // initially the list
    for (int i = 0; i < 5; i++)
    {
        cout << endl << "==========RUN TIME " << i + 1 << " =======================" << endl << endl;
        initialList();
        cout << "========BUBBLE SORT:========" << endl;
        cout << "\tList1: " << endl;
        bubble_sorting(list1, 100);
        cout << "\tList2: " << endl;
        bubble_sorting(list2, 100);
        cout << "\tList3: " << endl;
        bubble_sorting(list3, 100);
        initialList();
        cout << endl << "========INSERTION SORT ========" << endl << endl;
        cout << "\tList1: " << endl;
        insertion_sorting(list1, 100);
        cout << "\tList2: " << endl;
        insertion_sorting(list2, 100);
        cout << "\tList3: " << endl;
        insertion_sorting(list3, 100);
        initialList();
        cout << endl << "========SELECTION SORT ========" << endl << endl;
        cout << "\tList1: " << endl;
        selection_sorting(list1, 100);
        cout << "\tList2: " << endl;
        selection_sorting(list2, 100);
        cout << "\tList3: " << endl;
        selection_sorting(list3, 100);
        initialList();
        cout << endl << "========QUICK SORT========" << endl << endl;
        cout << "\tList1: " << endl;
        quick_sorting(list1, 100);
        cout << "\tList2: " << endl;
        quick_sorting(list2, 100);
        cout << "\tList3: " << endl;
        quick_sorting(list3, 100);
        initialList();
        cout << endl << "========MERGE SORT ========" << endl << endl;
        cout << "\tList1: " << endl;
        merge_sorting(list1, 100);
        cout << "\tList2: " << endl;
        merge_sorting(list2, 100);
        cout << "\tList3: " << endl;
        merge_sorting(list3, 100);
    }

    return 0;
}
