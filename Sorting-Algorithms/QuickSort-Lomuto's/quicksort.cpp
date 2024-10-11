/*
Author: Henryk Musial
08/17/2024
*/

/*
-----------------------------------------------------------------------------------------------------------------------------------------
>> QUICKSORT - LOMUTO'S PARTITIONING SCHEME <<
-----------------------------------------------------------------------------------------------------------------------------------------
This quicksort.cpp file is a personal reference of the QuickSort algorithm implementing Lomuto's partitioning scheme. The QuickSort
algorithm is a recursive algorithm that is based on the divide-and-conquer approach. QuickSort works by recursively partitioning the
array into sub-arrays bounded by a pivot element. Elements smaller than the pivot are placed to its left, and elements greater than the
pivot are positioned to its right. This partitioning process is facilitated through the helper function partitionFunction(), which swaps
elements into sorted order and establishes new partition boundaries.
-----------------------------------------------------------------------------------------------------------------------------------------
>> QuickSort (Lomuto's Partitioning Scheme): Accepts a pointer to an array, along with the low & high indices of the sub-array to be
        sorted. When the sub-array has more than one element, QuickSort calls the helper method PartitionFunction (Lomuto's) in order to
        partition the array around a pivot. During this partitioning process, elements less than the pivot are moved to the left of the
        pivot, and elements greater than the pivot are moved to the right of the pivot. QuickSort then recursively calls itself for the
        left & right sub-arrays defined by the pivot indices returned by the partition function. The pivotIndex returned by the partition
        function represents one more than the rightmost boundary for the sub-array to the left of the pivot, and one less than the
        leftmost boundary for the sub-array to the right of the pivot. Each recursive call partitions the array into smaller and smaller
        segments and stops once the base case is reached, where the sub-arrays contain either one or zero elements. Through this
        recursive process, the sorted property of the array emerges.

>> PartitionFunction (Lomuto's Partitioning Scheme): Initializes one pointer, (i), that traverses the input array starting at index
        [low], and increments toward index [high - 1]. A counter, pivotIndex, is also initialized - This counter will store the new
        position of the pivot element after partitioning. A pivot element is chosen (In this implementation, we are choosing the last
        element of the array, [high]), where elements less than the pivot will be swapped to the left, and elements greater than the
        pivot will be swapped to the right. Pointer (i) begins its traversal at the first index of the sub-array, and increments toward
        [high - 1] until an element pointed to by [i] is found to be less than the element stored at the [pivotIndex] counter. When this
        occurs, the element pointed at by [i] is swapped with the element stored at the [pivotIndex] counter, and the pivotIndex is
        incremented by one. Once the sub-array has been traversed by pointer (i), the pivot element is swapped with the element stored at
        the [pivotIndex] counter. This places the pivot in its correct position, where: {left elements} < pivot < {right elements}.
-----------------------------------------------------------------------------------------------------------------------------------------
>> Unstable Algorithm: QuickSort is an unstable algorithm, meaning that elements with equal values are not guaranteed to retain their
                       relative order in the sorted array.
-----------------------------------------------------------------------------------------------------------------------------------------
>> Time Complexity (Lomuto's):
        Worst-case: O(n^2) - Unbalanced partitions, where each sub-array returned by partition function is of size (n-1). This occurs
                             when the pivot of each sub-array is the smallest/largest element in the sub-array. Recursion tree has a
                             depth of (n) levels, where (n-1) recursive calls are made before reaching base case of an array of size (1).
                             This is because each recursive call only reduces the size of the sub-array by just one element. Each level
                             of the recursion tree performs (n) work to partition the sub-array and process the elements, as every
                             element needs to be compared to the pivot.
                                O(n) - Level of recursion tree, n = # of elements in partition (sub-array)
                                 * (for-each)
                                O(n) - Depth (levels) of recursion tree, n = # of elements in array
                                 = O(n^2)

        Best-case: O(n*log(n)) - Balanced partitions, where each sub-array is partitioned into nearly equal pieces of size ~(n/2).
                                 Recursion tree has a depth of log(n) levels before reaching base case of an array of size (1). Each
                                 level of the recursion tree performs (n) work to partition the sub-array and process the elements, as
                                 every element needs to be compared to the pivot.
                                    O(n) - Level of recursion tree, n = # of elements in partition (sub-array)
                                     * (for-each)
                                    O(log(n)) - Depth (levels) of recursion tree, n = # of elements in array
                                     = O(n*log(n))

        Average-case: O(n*log(n)) - Reasonably balanced partitions, where each sub-array is partitioned into roughly equal pieces ~(n/2).
                                    Recursion tree has a depth of log(n) levels before reaching base case of an array of size (1). Each
                                    level of the recursion tree performs (n) work to partition the sub-array and process the elements, as
                                    every element needs to be compared to the pivot.
                                       O(n) - Level of recursion tree, n = # of elements in partition (sub-array)
                                        * (for-each)
                                       O(log(n)) - Depth (levels) of recursion tree, n = # of elements in array
                                        = O(n*log(n))
 -----------------------------------------------------------------------------------------------------------------------------------------
>> Space Complexity (Lomuto's):
        Worst-case: O(n) - Unbalanced partitions, where each sub-array returned by partition function is of size (n-1). Each nested
                           recursive call requires O(1) auxilliary space to process the elements of the sub-array, (n) number of
                           recursive call frames added to the call stack before array of size (1) (depth of recursion tree).
                              O(1) - Temporary variables for each recursive call, 1 = constant space
                               * (for-each)
                              O(n) - Recursive call frames added to the call stack, n = # of elements in array
                               = O(n)

        Best-case: O(log(n)) - Balanced partitions, where each sub-array is partitioned into nearly equal pieces ~(n/2). Each nested
                               recursive call requires O(1) auxilliary space to process the elements of the sub-array, log(n) number of
                               recursive call frames added to the call stack before array of size (1) (depth of recursion tree).
                                  O(1) - Temporary variables for each recursive call, 1 = constant space
                                   * (for-each)
                                  O(log(n)) - Recursive call frames added to the call stack, n = # of elements in array
                                   = O(log(n))

        Average-case: O(log(n)) - Reasonably balanced partitions, where each sub-array is partitioned into roughly equal pieces ~(n/2).
                                  Each nested recursive call requires O(1) auxilliary space to process the elements of the sub-array,
                                  log(n) number of recursive call frames added to the call stack before array of size (1) (depth of
                                  recursion tree).
                                     O(1) - Temporary variables for each recursive call, 1 = constant space
                                      * (for-each)
                                     O(log(n)) - Recursive call frames added to the call stack, n = # of elements in array
                                      = O(log(n))
-----------------------------------------------------------------------------------------------------------------------------------------
>> Recursion Tree Diagram (Lomuto's):
        Key: () = Maps to Execution Steps Below, ❰❱ = Pivot Element
             {} = Before partitionFunction(), [] = After partitionFunction()
        Array = {22, 8, 15, 30, 16};

        * DIVIDE:   (1) {22, 8, 15, 30, ❰16❱}
                        [8, 15, ❰16❱, 30, 22]--------|
                         |                           |
                    (2) {8, ❰15❱}               (5) {30, ❰22❱}
                        [❰8❱, 15]---|               [❰22❱, 30]---|
                         |          |                |           |
                    (3) {8}    (4) {X}          (6) {X}     (7) {30}

        * CONQUER:  Through the helper function partitionFunction(), the sorted property of the array emerges once the base case is
                    reached for each branch of the recursion tree.
-----------------------------------------------------------------------------------------------------------------------------------------
>> Example QuickSort Execution (Lomuto's):
        Key: {} = Array, [] = Partition, ❰❱ = Pivot Element, (+) = Swap
        Array = {22, 8, 15, 30, 16};

        * UNSORTED: arr[] = {22, 8, 15, 30, 16}

            (1) First-Step: quickSort(arr[], 0, 4) {}
             |     + --------------------------------------------- + ----------------------------------------------- +
             |     | Before:                                       | After:                                          |
             |     |  * Array State: arr[] = {22, 8, 15, 30, 16}   |  * Array State: arr[] = {8, 15, 16, 30, 22}     |
             |     |  * Partition:   arr[] = {[22, 8, 15, 30, 16]} |  * Partition:   arr[] = {[8, 15, ❰16❱, 30, 22]} |
             |     + --------------------------------------------- + ----------------------------------------------- +
             |     ⮕ A call to partitionFunction(arr[], 0, 4) is made
             |        Pivot is set as the last element ❰16❱ -> [22, 8, 15, 30, ❰16❱]
             |         [22] Compared with ❰16❱, [22] is not less than ❰16❱, Continue
             |         [8] Compared with ❰16❱, [8] is less than ❰16❱, Swap
             |     (+) [8] & [22] are swapped -> [8, 22, 15, 30, ❰16❱]
             |         [15] Compared with ❰16❱, [15] is less than ❰16❱, Swap
             |     (+) [15] & [22] are swapped -> [8, 15, 22, 30, ❰16❱]
             |         [30] Compared with ❰16❱, [30] is not less than ❰16❱, Continue
             |     (+) Pivot element is swapped with [22] -> [8, 15, ❰16❱, 30, 22] -> pivotIndex = 2
             |     ⮕ Return: pivotIndex = 2
             |
             |--(2) Second-Step: quickSort(arr[], 0, 1) {} // GOING LEFT
             |   |     + ------------------------------------------- + ------------------------------------------- +
             |   |     | Before:                                     | After:                                      |
             |   |     |  * Array State: arr[] = {8, 15, 16, 30, 22} |  * Array State: arr[] = {8, 15, 16, 30, 22} |
             |   |     |  * Partition:   arr[] = {[8, 15], ... }     |  * Partition:   arr[] = {[❰8❱, 15], ... }   |
             |   |     + ------------------------------------------- + ------------------------------------------- +
             |   |     ⮕ A call to partitionFunction(arr[], 0, 1) is made
             |   |        Pivot is set as the last element ❰15❱ -> [8, ❰15❱]
             |   |         [8] Compared with ❰15❱, [8] is less than ❰15❱, Swap
             |   |     (+) [8] & [15] are swapped -> [❰15❱, 8]
             |   |     (+) Pivot element is swapped with [8] -> [❰8❱, 15] -> pivotIndex = 1
             |   |     ⮕ Return: pivotIndex = 1
             |   |
             |   |--(3) Third-Step: quickSort(arr[], 0, 0) {} // GOING LEFT
             |   |         + ------------------------------------------- + ------------------------------------------- +
             |   |         | Before:                                     | After:                                      |
             |   |         |  * Array State: arr[] = {8, 15, 16, 30, 22} |  * Array State: arr[] = {8, 15, 16, 30, 22} |
             |   |         |  * Partition:   arr[] = {[8], ... }         |  * Partition:   arr[] = {[8], ... }         |
             |   |         + ------------------------------------------- + ------------------------------------------- +
             |   |         ⮕ Array of size 1 [8] (BASE-CASE)
             |   |
             |   |--(4) Fourth-Step: quickSort(arr[], 2, 1) {} // GOING RIGHT
             |             + ------------------------------------------- + ------------------------------------------- +
             |             | Before:                                     | After:                                      |
             |             |  * Array State: arr[] = {8, 15, 16, 30, 22} |  * Array State: arr[] = {8, 15, 16, 30, 22} |
             |             |  * Partition:   arr[] = [X] Invalid Range   |  * Partition:   arr[] = [X] Invalid Range   |
             |             + ------------------------------------------- + ------------------------------------------- +
             |             ⮕ Invalid Range [X] (BASE-CASE)
             |
             |--(5) Fifth-Step: quickSort(arr[], 3, 4) {} // GOING RIGHT
                 |     + ------------------------------------------- + ------------------------------------------- +
                 |     | Before:                                     | After:                                      |
                 |     |  * Array State: arr[] = {8, 15, 16, 30, 22} |  * Array State: arr[] = {8, 15, 16, 22, 30} |
                 |     |  * Partition:   arr[] = { ... , [30, 22]}   |  * Partition:   arr[] = { ... , [❰22❱, 30]} |
                 |     + ------------------------------------------- + ------------------------------------------- +
                 |     ⮕ A call to partitionFunction(arr[], 3, 4) is made
                 |        Pivot is set as the last element ❰22❱ -> [30, ❰22❱]
                 |         [30] Compared with ❰22❱, [30] is not less than ❰22❱, Continue
                 |     (+) Pivot element is swapped with [30] -> [❰22❱, 30] -> pivotIndex = 3
                 |     ⮕ Return: pivotIndex = 3
                 |
                 |--(6) Sixth-Step: quickSort(arr[], 3, 2) {} // GOING LEFT
                 |         + ------------------------------------------- + ------------------------------------------- +
                 |         | Before:                                     | After:                                      |
                 |         |  * Array State: arr[] = {8, 15, 16, 22, 30} |  * Array State: arr[] = {8, 15, 16, 22, 30} |
                 |         |  * Partition:   arr[] = [X] Invalid Range   |  * Partition:   arr[] = [X] Invalid Range   |
                 |         + ------------------------------------------- + ------------------------------------------- +
                 |         ⮕ Invalid Range [X] (BASE-CASE)
                 |
                 |--(7) Seventh-Step: quickSort(arr[], 4, 4) {} // GOING RIGHT
                           + ------------------------------------------- + ------------------------------------------- +
                           | Before:                                     | After:                                      |
                           |  * Array State: arr[] = {8, 15, 16, 22, 30} |  * Array State: arr[] = {8, 15, 16, 22, 30} |
                           |  * Partition:   arr[] = { ... , [30]}       |  * Partition:   arr[] = { ... , [30]}       |
                           + ------------------------------------------- + ------------------------------------------- +
                           ⮕ Array of size 1 [30] (BASE-CASE)

        * SORTED: arr[] = {8, 15, 16, 22, 30}, Total # of Swaps: 6
-----------------------------------------------------------------------------------------------------------------------------------------
>> Note: Unlike Hoare's partitioning scheme, the time complexity of Lomuto's partitioning scheme degrades to O(n^2) if the array is
         already sorted. Otherwise they share identical time & space complexities. This degradation occurs because Lomuto's pivot choice
         (the last element) in a sorted array will always be the largest or smallest element. This will create unbalanced partitions
         identical to the worst-case time complexity scenario.
-----------------------------------------------------------------------------------------------------------------------------------------
>> Compile & Run:
        g++ quicksort.cpp || g++ quicksort.cpp -g -o quicksort
        ./a.out || valgrind ./a.out || valgrind ./quicksort || valgrind --leak-check=full ./quicksort
-----------------------------------------------------------------------------------------------------------------------------------------
*/

#include <iostream> // cout
#include <fstream>  // ifstream
#include <sstream>  // stringstream
#include <string>   // string

using namespace std;

/*
-----------------------------------------------------------------------------------------------------------------------------------------
The partitionFunction() partitions the dataArray segment using Lomuto's partitioning scheme. All elements that are less than the pivot
are moved to the left of the pivot, and all elements greater than the pivot are moved to the right of the pivot.
    >> Parameters:
            int dataArray[] - Pointer to array of integers
            int low - Index of the first element in sub-array to be sorted
            int high - Index of the last element in sub-array to be sorted
    >> Return:
            int pivotIndex - Index of the pivot element's new position
-----------------------------------------------------------------------------------------------------------------------------------------
*/
int partitionFunction(int dataArray[], int low, int high)
{
    int i = low;                 // Initialize i to low (lowest index of the sub-array)
    int pivot = dataArray[high]; // Set pivot = dataArray[high] (element stored in highest index of the sub-array)
    int pivotIndex = low;        // Counter to store new position of pivot element

    while (i < high) // Traverse the sub-array from low to high - 1
    {
        if (dataArray[i] < pivot) // If the element at the current index is less than the pivot
        {
            // Swap that element that was less than the pivot with the element stored at dataArray[pivotIndex]
            int temp = dataArray[i];              // Temp becomes element @ index [i]
            dataArray[i] = dataArray[pivotIndex]; // Element @ index [i] overwritten by element @ index [pivotIndex]
            dataArray[pivotIndex] = temp;         // Element @ index [pivotIndex] now = temp
            pivotIndex++;                         // Increment the pivot index for the next swap.
        }

        i++; // [i] Moves toward higher index [->]
    }

    // Swap the pivot element with the element stored at dataArray[pivotIndex]
    int temp = dataArray[high];              // Temp becomes element @ dataArray[high] (Last element in sub-array)
    dataArray[high] = dataArray[pivotIndex]; // Last element in sub-array overwritten by element @ index[pivotIndex]
    dataArray[pivotIndex] = temp;            // Element @ index [pivotIndex] now = temp

    return pivotIndex; // Return the index of the pivot element's new position
}

/*
-----------------------------------------------------------------------------------------------------------------------------------------
The quickSort() function recursively sorts the segment of the array between the low & high indicies. Uses a helper function
"partitionFunction()" which implements Lomuto's partitioning scheme.
    >> Parameters:
            int dataArray[] - Pointer to array of integers
            int low - Index of the first element in sub-array to be sorted
            int high - Index of the last element in sub-array to be sorted
-----------------------------------------------------------------------------------------------------------------------------------------
*/
void quickSort(int dataArray[], int low, int high)
{
    // Base-case: low = high (sub-array of size 1)
    // Recursive-case: low < high (sub-array of size 2 or more)
    // Error Condition: low > high

    if (low < high) // If the dataArray segment has more than 1 element
    {
        int pivotIndex = partitionFunction(dataArray, low, high); // Get the index of the pivot (partition boundary)
        quickSort(dataArray, low, (pivotIndex - 1));              // Recursive call for left partition
        quickSort(dataArray, (pivotIndex + 1), high);             // Recursive call for right partition
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
terminal before and after the QuickSort algorithm is performed.
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
         << "Running QuickSort - Lomuto's Partitioning Scheme..." << endl;
    // Call the quickSort() function to sort the array
    quickSort(dataArray, 0, (arraySize - 1));

    // Print the sorted array
    cout << endl
         << "Array after sorting:";
    printArray(dataArray, arraySize);
    cout << endl;

    return 0;
}
