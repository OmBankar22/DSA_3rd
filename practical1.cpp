#include <iostream>
using namespace std;

//heapify function to maintain heap property
// n is the size of heap ,i is the every elements in array
void heapify(int arr[], int n, int i) {
    int largest = i;     // initialize largest as a root since we are using 0 based indexig 
    int left = 2 * i + 1; //left = 2*i+1
    int right = 2 * i + 2; // right = 2*i+2

    if (left < n && arr[left] > arr[largest]) //if left child is larger than root 
        largest = left;

    if (right < n && arr[right] > arr[largest]) //if right child is larger than root
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);   // swap elemntss largest element stored into sorted list
        heapify(arr, n, largest);     //recursively heapify affect the sub tree 
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)  // divide aray into left and right subtree 
        heapify(arr, n, i);                // call function maintain heap property

    for (int i = n - 1; i > 0; i--) {   //one by one extract an element from heap
        swap(arr[0], arr[i]);           //move current root to end
        heapify(arr, i, 0);             // call max heafiy on the reduced heap
    }
}

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap >  0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
}

void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void getUserInput(int arr[], int n) {
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

int main() {
    int choice;
    cout << "Choose sorting algorithm:\n";
    cout << "1. Heap Sort\n";
    cout << "2. Shell Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    getUserInput(arr, n);

    cout << "Original array: ";
    printArray(arr, n);

    switch (choice) {
        case 1:
            heapSort(arr, n);
            cout << "Array after Heap Sort: ";
            printArray(arr, n);
            break;

        case 2:
            shellSort(arr, n);
            cout << "Array after Shell Sort: ";
            printArray(arr, n);
            break;

        default:
            cout << "Invalid choice. Exiting...";
            break;
    }

    return 0;
}