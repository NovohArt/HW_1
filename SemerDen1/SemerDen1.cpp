#include <iostream>
#include <chrono>
#include <ctime>
#include <fstream>



using namespace std;

void fill(int* b, int size) {
    for (int i = 0; i < size; i++)
        *(b++) = rand() % 201;
}

void print(int* b, int size) {
    for (int i = 0; i < size; i++)
        cout << *(b++) << ' ';
    cout << endl;
}

void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root Since we are using 0 based indexing
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void merge(int array[], int const left, int const mid,
    int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne
        = 0, // Initial index of first sub-array
        indexOfSubArrayTwo
        = 0; // Initial index of second sub-array
    int indexOfMergedArray
        = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
        && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int partition(int* arr, int first, int last) {
    int i = first, j = last;
    int pivot = arr[(first + last) / 2];

    while (true) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i >= j)
            break;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    return j;
}
void quickSort(int* arr, int first, int last) {
    if (first < last) {
        int p = partition(arr, first, last);
        quickSort(arr, first, p);
        quickSort(arr, p + 1, last);
    }
}


void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {

        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            // put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void insertSort(int* a, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && a[j - 1] > a[j]; j--) {
            std::swap(a[j - 1], a[j]);
        }
    }
}

void gnomeSort(int arr[], int n)
{
    int index = 0;

    while (index < n) {
        if (index == 0)
            index++;
        if (arr[index] >= arr[index - 1])
            index++;
        else {
            swap(arr[index], arr[index - 1]);
            index--;
        }
    }
    return;
}


void selectionSort(int arr[], int size)
{
    int i, j, minIndex;
    // loop to iterate over the entire array
    for (i = 0; i < size - 1; i++)
    {
        // set minIndex equal to the first unsorted element
        minIndex = i;

        //iterate over unsorted sublist
        for (j = i + 1; j < size; j++)

            // helps in finding the minimum element
            if (arr[j] < arr[minIndex])
                minIndex = j;

        // swapping the minimum element with the element at minIndex to place it at its correct position 
        // using std::swap() method for swapping
        swap(arr[minIndex], arr[i]);
    }
}

int main() {
    ofstream fout;
    fout.open("Time.txt");
    void (*sorts[6])(int* arr, int size) = {selectionSort, shellSort, bubbleSort, insertSort, heapSort, gnomeSort};
    const char *sortName[6] = { "selectionSort", "shellSort", "bubbleSort", "insertSort", "heapSort", "gnomeSort"};
    int sort = 0;
    while (sort < 6) {
        cout << sort + 1 << endl;
        int size = 10;
        fout << "# " << sortName[sort] << endl;
        while (size <= 10000000) {
            int* arr = new int[size];
            fill(arr, size);
            auto start = std::chrono::high_resolution_clock::now();
            sorts[sort](arr, size);
            auto end = std::chrono::high_resolution_clock::now();
            if (chrono::duration_cast<chrono::seconds>(end - start).count() < 20) {
                if (chrono::duration_cast<chrono::seconds>(end - start).count() > 1)
                    fout << size << ' ' << 1 << endl;
                else
                    fout << size << ' ' << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;
            }
            else 
                break;
            size = size * 10;
            delete[] arr;
        }
        size = 10;
        fout << endl << endl;
        sort++;
    }
    void (*sorts2[2])(int arr[], int low, int high) = {quickSort, mergeSort};
    const char *sortName2[2] = { "quickSort", "mergeSort"};
    int sort2 = 0;
    while (sort2 < 2) {
        cout <<  sort2 + 1 << endl;
        int size = 10;
        fout << "# " << sortName2[sort2] << endl;
        while (size <= 10000000) {
            int* arr = new int[size];
            fill(arr, size);
            auto start = std::chrono::high_resolution_clock::now();
            sorts2[sort2](arr, 0, size-1);
            auto end = std::chrono::high_resolution_clock::now();
            if (chrono::duration_cast<chrono::seconds>(end - start).count() < 20) {
                if (chrono::duration_cast<chrono::seconds>(end - start).count() > 1)
                    fout << size << ' ' << 1 << endl;
                else
                    fout << size << ' ' << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;
            }
            else 
                break;
           
            size = size * 10;
            delete[] arr;
        }
        fout << endl << endl;
        size = 10;
        sort2++;
    }
    cout << "All sorts there used";
    fout.close();
    return 0;
}

