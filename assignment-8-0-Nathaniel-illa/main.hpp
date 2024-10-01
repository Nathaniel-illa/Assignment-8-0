#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <cstdlib> // For rand() and srand()

using namespace std;
using namespace std::chrono;

// Function declarations
void fillvector(vector<int> &, int size);
int insertion(vector<int> &);
int bubble(vector<int> &);
void print(const vector<int> &);

// Function to fill the vector with N random numbers
void fillvector(vector<int> &numbers, int N) {
    numbers.clear(); // Clear the vector to ensure it is empty before filling
    for (int i = 0; i < N; i++) {
        // Generate a random number between 0 and 999 and add to the vector
        numbers.push_back(rand() % 1000);
    }
}

// Insertion sort implementation
int insertion(vector<int> &numbers) {
    int swapCount = 0; // Initialize swap counter
    int n = numbers.size(); // Get the size of the vector
    // Iterate over each element starting from the second one
    for (int i = 1; i < n; i++) {
        int key = numbers[i]; // The current element to be positioned
        int j = i - 1; // Index for comparing elements before the key
        // Move elements of numbers[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && numbers[j] > key) {
            numbers[j + 1] = numbers[j]; // Shift element to the right
            j--; // Move to the previous element
            swapCount++; // Count the number of shifts (similar to swaps)
        }
        numbers[j + 1] = key; // Place the key in its correct position
        // One assignment without an actual swap
    }
    return swapCount; // Return the total number of shifts
}

// Bubble sort implementation
int bubble(vector<int> &numbers) {
    int swapCount = 0; // Initialize swap counter
    int n = numbers.size(); // Get the size of the vector
    // Outer loop for each pass
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // Flag to track if any swaps occurred
        // Inner loop to compare adjacent elements
        for (int j = 0; j < n - i - 1; j++) {
            // If the current element is greater than the next one
            if (numbers[j] > numbers[j + 1]) {
                swap(numbers[j], numbers[j + 1]); // Swap the elements
                swapCount++; // Increment the swap counter
                swapped = true; // Set the swapped flag to true
            }
        }
        // If no elements were swapped in this pass, the array is sorted
        if (!swapped) {
            break; // Exit the loop early
        }
    }
    return swapCount; // Return the total number of swaps
}

// Function to print the elements of the vector
void print(const vector<int> &numbers) {
    for (auto v : numbers) // Iterate over each element
        cout << v << "\t"; // Print the element followed by a tab
    cout << endl; // Move to the next line after printing all elements
}