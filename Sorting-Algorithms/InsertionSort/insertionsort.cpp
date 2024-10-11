/*
Author: Henryk Musial
09/3/2024
*/

/*
-----------------------------------------------------------------------------------------------------------------------------------------
>> INSERTIONSORT <<
-----------------------------------------------------------------------------------------------------------------------------------------
This insertionsort.cpp file is a personal reference of the InsertionSort algorithm that works by iteratively inserting the elements of an
unsorted array into their correct positions within a sorted sub-array. InsertionSort is a comparison based algorithm, and works by
building a sorted sub-array section within the unsorted array one element at a time without requiring any additional storage space.
-----------------------------------------------------------------------------------------------------------------------------------------
>> InsertionSort: This algorithm starts its traversal at the element stored at index [1]. It assumes the element stored at index [0] to
        be the first element of the sorted sub-array. Starting at index [1], we compare the element stored at index [1] with the elements
        in the sorted portion of the array. This is done by traversing the sorted sub-array, starting at the current index minus one
        [index - 1], and decrementing toward index [0]. Elements in the sorted sub-array that are encountered and are greater than (>)
        our current element are shifted one position to the right in order to make space for our insertion. Once the correct position to
        insert our element is found, the element is inserted, and we then move to the next element to repeat this process until the
        entirety of the array is sorted (sub-array size = original array size).
-----------------------------------------------------------------------------------------------------------------------------------------
>> Stable Algorithm: InsertionSort is a stable algorithm, meaning that elements with equal values will always retain their relative order
                     in the sorted array.
-----------------------------------------------------------------------------------------------------------------------------------------
>> Time Complexity:
        Worst-case: O(n^2) - The array is in reverse sorted order. Each element encountered in the array is compared to every single
                             element in the sorted sub-array before being inserted at the lowest possible index. In this case, we must
                             traverse over (n) elements in the sorted sub-array and shift each element to make room for insertion. (n)
                             number of elements in the given array must also be traversed.
                                O(n) - Sorted sub-array traversal, n = # elements in sub-array
                                 * (for-each)
                                O(n) - Traversal of given array, n = # elements in array
                                 = O(n^2)

        Best-case: O(n) - The array is already sorted. Each element traversed in the array fails the while loop test, therefore no
                          sub-array traversals occur. (n) number of elements in the given array must be traversed.
                            O(n) - Traversal of given array, n = # elements in array
                              = O(n)

        Average-case: O(n^2) - The array is unsorted. Some elements encountered in the array pass the while loop test, therefore we must
                               traverse over (n) elements in the sorted sub-array and shift each element to make room for insertion. (n)
                               number of elements in the given array must also be traversed.
                                  O(n) - Sorted sub-array traversal, n = # elements in sub-array
                                   * (for-each)
                                  O(n) - Traversal of given array, n = # elements in array
                                   = O(n^2)
-----------------------------------------------------------------------------------------------------------------------------------------
>> Space Complexity:
        All-cases: O(1) - Each call of InsertionSort requires O(1) auxilliary space to traverse and sort the elements in the array.
                          Auxilliary storage usage is proportional to the size of the given unsorted array.
                             O(1) - Temporary variables for each iteration of loop, 1 = constant space
                              = O(1)
-----------------------------------------------------------------------------------------------------------------------------------------
>> Example InsertionSort Execution:
        Key: {} = Array, [] = Sub-Array
        Array = {23, 1, 10, 5, 2};

        * UNSORTED: arr[] = {23, 1, 10, 5, 2}

            (1) First-Step: insertionSort(arr[], 5) {}
                   + ------------------------------------------- + ------------------------------------------- +
                   | Before:                                     | After:                                      |
                   |  * Array State: arr[] = {23, 1, 10, 5, 2}   |  * Array State: arr[] = {23, 1, 10, 5, 2}   |
                   |  * Sub-Array:   arr[] = {[23], 1, 10, 5, 2} |  * Sub-Array:   arr[] = {[23], 1, 10, 5, 2} |
                   + ------------------------------------------- + ------------------------------------------- +
                   ⮕ Begin array traversal, starting at index (i) = 1
                      Element at index [0] assumed to be sorted -> {[23], 1, 10, 5, 2}

            (2) Second-Step: (i) = 1
                   + ------------------------------------------- + ------------------------------------------- +
                   | Before:                                     | After:                                      |
                   |  * Array State: arr[] = {23, 1, 10, 5, 2}   |  * Array State: arr[] = {1, 23, 10, 5, 2}   |
                   |  * Sub-Array:   arr[] = {[23], 1, 10, 5, 2} |  * Sub-Array:   arr[] = {[1, 23], 10, 5, 2} |
                   + ------------------------------------------- + ------------------------------------------- +
                   ⮕ {1} Compared with [23] -> {1} is less than [23]
                      {1} Inserted before [23] -> {[1, 23], 10, 5, 2}

            (3) Third-Step: (i++), (i) = 2
                   + ------------------------------------------- + ------------------------------------------- +
                   | Before:                                     | After:                                      |
                   |  * Array State: arr[] = {1, 23, 10, 5, 2}   |  * Array State: arr[] = {1, 10, 23, 5, 2}   |
                   |  * Sub-Array:   arr[] = {[1, 23], 10, 5, 2} |  * Sub-Array:   arr[] = {[1, 10, 23], 5, 2} |
                   + ------------------------------------------- + ------------------------------------------- +
                   ⮕ {10} Compared with [1], [23] -> {10} is greater than [1], {10} is less than [23]
                      {10} Inserted before [23] -> {[1, 10, 23], 5, 2}

            (4) Fourth-Step: (i++), (i) = 3
                   + ------------------------------------------- + ------------------------------------------- +
                   | Before:                                     | After:                                      |
                   |  * Array State: arr[] = {1, 10, 23, 5, 2}   |  * Array State: arr[] = {1, 5, 10, 23, 2}   |
                   |  * Sub-Array:   arr[] = {[1, 10, 23], 5, 2} |  * Sub-Array:   arr[] = {[1, 5, 10, 23], 2} |
                   + ------------------------------------------- + ------------------------------------------- +
                   ⮕ {5} Compared with [1],[10],[23] -> {5} is greater than [1], {5} is less than [10]
                      {5} Inserted before [10] -> {[1, 5, 10, 23], 2}

            (5) Fifth-Step: (i++), (i) = 4
                   + ------------------------------------------- + ------------------------------------------- +
                   | Before:                                     | After:                                      |
                   |  * Array State: arr[] = {1, 5, 10, 23, 2}   |  * Array State: arr[] = {1, 2, 5, 10, 23}   |
                   |  * Sub-Array:   arr[] = {[1, 5, 10, 23], 2} |  * Sub-Array:   arr[] = {[1, 2, 5, 10, 23]} |
                   + ------------------------------------------- + ------------------------------------------- +
                   ⮕ {2} Compared with [1], [5], [10], [23] -> {2} is greater than [1], {2} is less than [5]
                      {2} Inserted before [5] -> {[1, 2, 5, 10, 23]}

        * SORTED: arr[] = {1, 2, 5, 10, 23}
-----------------------------------------------------------------------------------------------------------------------------------------
>> Compile & Run:
        g++ insertionsort.cpp || g++ insertionsort.cpp -g -o insertionsort
        ./a.out || valgrind ./a.out || valgrind ./insertionsort || valgrind --leak-check=full ./insertionsort
-----------------------------------------------------------------------------------------------------------------------------------------
*/

#include <iostream> // cout
#include <fstream>  // ifstream
#include <sstream>  // stringstream
#include <string>   // string

using namespace std;

/*
-----------------------------------------------------------------------------------------------------------------------------------------
The insertionSort() function sorts an unsorted array by maintaining a sorted sub-array, and comparing each element of the unsorted array
to the elements in the sorted sub-array. The unsorted element is then inserted into its proper sorted location in the sub-array.
    >> Parameters:
            int dataArray[] - Pointer to array of integers
            int arraySize - Size of the array
-----------------------------------------------------------------------------------------------------------------------------------------
*/
void insertionSort(int dataArray[], int arraySize)
{
    // Starting array traversal at index 1, assume element at index [0] is already sorted
    for (int i = 1; i < arraySize; i++)
    {
        int element = dataArray[i]; // Get the element stored at current index, starting @ index [1]
        int index = i;              // Set index = to the index of the selected element

        // While the index is > 0 and the previous element [index - 1] is greater than the selected element
        while ((index > 0) && (dataArray[index - 1] > element)) // Traverse the sorted sub-array starting at its end [index - 1]
        {
            // Shift the previous element 1 position to the right
            dataArray[index] = dataArray[index - 1]; // Set the current element [i] = to the previous element [i - 1] (Shift)
            index--;                                 // Move toward the first element [0] of the sorted sub-array
        }
        // Sorted sub-array traversal completed

        dataArray[index] = element; // Insert the current element at its correct position within the sorted sub-array
        // Repeat this process (arraySize - 1) number of times
    }
}

/*
-----------------------------------------------------------------------------------------------------------------------------------------
The printArray() function traverses the given array and prints the contents out to the terminal. Prints the output in a reader friendly
format.
    >> Parameters:
            int dataArray[] - Pointer to array of integers
            int arraySize - Size of the array to be printed
-----------------------------------------------------------------------------------------------------------------------------------------
*/
void printArray(int dataArray[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        if ((i % 25) == 0) // New line every 25 elements printed
        {
            cout << endl
                 << "   "; // Indent each new line
        }
        if (i == (arraySize - 1)) // Last element
        {
            if (dataArray[i] < 10) // If single-digit & last
            {
                cout << " " << dataArray[i] << endl; // Add extra space
            }
            else // Otherwise just print the element
            {
                cout << dataArray[i] << endl;
            }
        }
        else // Element is not last
        {
            if (dataArray[i] < 10) // If single-digit & not last
            {
                cout << " " << dataArray[i] << ", "; // Pad element with space " " & trailing comma
            }
            else // Otherwise just add a trailing comma
            {
                cout << dataArray[i] << ", ";
            }
        }
    }
}

/*
-----------------------------------------------------------------------------------------------------------------------------------------
main() reads a data.txt file containing integers whose values have no specified limitation. The first line of the data file contains the
# of integers to be sorted, and the following lines contain the data to be populated to the array. The array is then printed to the
terminal before and after the InsertionSort algorithm is performed.
-----------------------------------------------------------------------------------------------------------------------------------------
*/
int main()
{
    // Read the data from file
    ifstream infile("data1.txt");

    if (!infile)
    {
        cerr << "ERROR - File Not Found" << endl;
        return 1;
    }

    int arraySize = 0;        // Number of integers to be sorted (Size of array)
    infile >> arraySize;      // Size is first line of data file
    int dataArray[arraySize]; // To hold our data to be sorted

    if (arraySize <= 0) // Check valid # of integers
    {
        cerr << "ERROR - Invalid Number Of Integers" << endl;
        return 1;
    }

    int index = 0; // Index to insert element into dataArray
    string line;

    while (getline(infile, line)) // Get the next line of data after arraySize
    {
        if (line == "")
        {
            continue; // Skip empty lines
        }

        stringstream ss(line); // To parse each line
        int element;           // To store each integer delimited by a space " "

        // While there is a next integer and there are more integers's to store
        while ((ss >> element) && (index < arraySize))
        {
            dataArray[index++] = element; // Store the integer @ index, then increment the index
        }
    }

    // Print unsorted array
    cout << endl
         << "Array before sorting:";
    printArray(dataArray, arraySize);

    cout << endl
         << "Running InsertionSort..." << endl;
    // Call the insertionSort() function to sort the array
    insertionSort(dataArray, arraySize);

    // Print the sorted array
    cout << endl
         << "Array after sorting:";
    printArray(dataArray, arraySize);
    cout << endl;

    return 0;
}
