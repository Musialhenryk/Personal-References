/*
Author: Henryk Musial
08/25/2024
*/

/*
-----------------------------------------------------------------------------------------------------------------------------------------
>> QUICKSORT - HOARE'S PARTITIONING SCHEME <<
-----------------------------------------------------------------------------------------------------------------------------------------
This quicksort.cpp file is a personal reference of the QuickSort algorithm implementing Hoare's partitioning scheme. The QuickSort
algorithm is a recursive algorithm that is based on the divide-and-conquer approach. QuickSort works by recursively partitioning the
array into sub-arrays bounded by a pivot element. Elements smaller than the pivot are placed to its left, and elements greater than the
pivot are positioned to its right. This partitioning process is facilitated through the helper function partitionFunction(), which swaps
elements into sorted order and establishes new partition boundaries.
-----------------------------------------------------------------------------------------------------------------------------------------
>> QuickSort (Hoare's Partitioning Scheme): Accepts a pointer to an array, along with the low & high indices of the sub-array to be
        sorted. When the sub-array has more than one element, QuickSort calls the helper method PartitionFunction (Hoare's) in order to
        partition the array around a pivot. During this partitioning process, elements less than the pivot are moved to the left of the
        pivot, and elements greater than the pivot are moved to the right of the pivot. QuickSort then recursively calls itself for the
        left & right sub-arrays defined by the pivot indices returned by the partition function. The pivotIndex returned by the partition
        function represents the rightmost boundary for the sub-array to the left of the pivot, and one less than the leftmost boundary
        for the sub-array to the right of the pivot. Each recursive call partitions the array into smaller and smaller segments and stops
        once the base case is reached, where the sub-arrays contain either one or zero elements. Through this recursive partitioning
        process, the sorted property of the array emerges.

>> PartitionFunction (Hoare's Partitioning Scheme): Initializes two pointers, (i) & (j), that traverse the input array from both ends. A
        pivot element is chosen (In this implementation, we are choosing the middle element of the array, [low + (high - low) / 2]),
        where elements less than the pivot are swapped to the left, and elements greater than the pivot are swapped to the right. Pointer
        (i) begins its traversal at the first index of the sub-array minus 1 [low - 1] and increments toward a higher index until it
        points to an element greater than or equal to the element stored at the [pivot] index. Pointer (j) begins its traversal at the
        last index of the array plus 1 [high + 1], and decrements toward a lower index until it points to an element less than or equal
        to the element stored at the [pivot] index. If an inversion occurs (The element pointed at by [i] is greater than the [pivot]
        element, and the element pointed at by [j] is less than the [pivot] element) then the elements pointed at by [i] & [j] are
        swapped with one another. Pointers (i) & (j) continue to move toward each other until they cross paths (i >= j), indicating that
        the sub-array is sorted relative to the current pivot. The partition function then returns the index [j], which serves as the new
        boundary for the partitioned sub-arrays.
-----------------------------------------------------------------------------------------------------------------------------------------
>> Unstable Algorithm: QuickSort is an unstable algorithm, meaning that elements with equal values are not guaranteed to retain their
                       relative order in the sorted array.
-----------------------------------------------------------------------------------------------------------------------------------------
>> Time Complexity (Hoare's):
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
>> Space Complexity (Hoare's):
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
>> Recursion Tree Diagram (Hoare's):
        Key: () = Maps to Execution Steps Below, ❰❱ = Pivot Element
             {} = Before partitionFunction(), [] = After partitionFunction()
        Array = {22, 8, 15, 30, 16};

        * DIVIDE:   (1) {22, 8, ❰15❱, 30, 16}
                        [15, 8, ❰22❱, 30, 16]--------|
                         |                           |
                    (2) {❰15❱, 8}               (5) {22, ❰30❱, 16}
                        [❰8❱, 15]---|               [22, ❰16❱, 30]--------|
                         |          |                |                    |
                    (3) {8}    (4) {15}         (6) {❰22❱, 16}       (9) {30}
                                                    [❰16❱, 22]---|
                                                     |           |
                                                (7) {16}    (8) {22}

        * CONQUER: Through the helper function partitionFunction(), the sorted property of the array emerges once the base case is
                   reached for each branch of the recursion tree.
-----------------------------------------------------------------------------------------------------------------------------------------
>> Example QuickSort Execution (Hoare's):
        Key: {} = Array, [] = Partition, ❰❱ = Pivot Element, (+) = Swap
        Array = {22, 8, 15, 30, 16};

        * UNSORTED: arr[] = {22, 8, 15, 30, 16}

            (1) First-Step: quickSort(arr[], 0, 4) {}
             |     + --------------------------------------------- + ----------------------------------------------- +
             |     | Before:                                       | After:                                          |
             |     |  * Array State: arr[] = {22, 8, 15, 30, 16}   |  * Array State: arr[] = {15, 8, 22, 30, 16}     |
             |     |  * Partition:   arr[] = {[15, 8, 22, 30, 16]} |  * Partition:   arr[] = {[15, 8, ❰22❱, 30, 16]} |
             |     + --------------------------------------------- + ----------------------------------------------- +
             |     ⮕ A call to partitionFunction(arr[], 0, 4) is made
             |        Pivot is set as the middle element ❰15❱ -> [22, 8, ❰15❱, 30, 16]
             |        Pointers Initialized -> (i) = 0 - 1, (j) = 4 + 1
             |         (i++) -> (i) = 0 -> [22] Compared with ❰15❱, [22] is not less than ❰15❱, Stop here
             |         (j--) -> (j) = 4 -> [16] Compared with ❰15❱, [16] is greater than ❰15❱, Continue
             |         (j--) -> (j) = 3 -> [30] Compared with ❰15❱, [30] is greater than ❰15❱, Continue
             |         (j--) -> (j) = 2 -> [15] Compared with ❰15❱, [15] is not greater than ❰15❱, Stop here
             |     (+) [15] & [22] are swapped -> [15, 8, ❰22❱, 30, 16]
             |         (i++) -> (i) = 1 -> [8] Compared with ❰22❱, [8] is less than ❰22❱, Continue
             |         (i++) -> (i) = 2 -> [22] Compared with ❰22❱, [22] is not less than ❰22❱, Stop here
             |         (j--) -> (j) = 1 -> [8] Compared with ❰22❱, [8] is not greater than ❰22❱, Stop here
             |         (i) has moved past (j) -> pivotIndex = (j) = 1
             |     ⮕ Return: pivotIndex = 1
             |
             |--(2) Second-Step: quickSort(arr[], 0, 1) {} // GOING LEFT
             |   |     + ------------------------------------------- + ------------------------------------------- +
             |   |     | Before:                                     | After:                                      |
             |   |     |  * Array State: arr[] = {15, 8, 22, 30, 16} |  * Array State: arr[] = {8, 15, 22, 30, 16} |
             |   |     |  * Partition:   arr[] = {[15, 8], ... }     |  * Partition:   arr[] = {[❰8❱, 15], ... }   |
             |   |     + ------------------------------------------- + ------------------------------------------- +
             |   |     ⮕ A call to partitionFunction(arr[], 0, 1) is made
             |   |        Pivot is set as the middle element ❰15❱ -> [❰15❱, 8]
             |   |        Pointers Initialized -> (i) = 0 - 1, (j) = 1 + 1
             |   |         (i++) -> (i) = 0 -> [15] Compared with ❰15❱, [15] is not less than ❰15❱, Stop here
             |   |         (j--) -> (j) = 1 -> [8] Compared with ❰15❱, [8] is not greater than ❰15❱, Stop here
             |   |     (+) [15] & [8] are swapped -> [❰8❱, 15]
             |   |         (i++) -> (i) = 1 -> [8] Compared with ❰8❱, [8] is not less than ❰8❱, Stop here
             |   |         (j--) -> (j) = 0 -> [8] Compared with ❰8❱, [8] is not greater than ❰8❱, Stop here
             |   |         (i) has moved past (j) -> pivotIndex = (j) = 0
             |   |     ⮕ Return: pivotIndex = 0
             |   |
             |   |--(3) Third-Step: quickSort(arr[], 0, 0) {} // GOING LEFT
             |   |         + ------------------------------------------- + ------------------------------------------- +
             |   |         | Before:                                     | After:                                      |
             |   |         |  * Array State: arr[] = {8, 15, 22, 30, 16} |  * Array State: arr[] = {8, 15, 22, 30, 16} |
             |   |         |  * Partition:   arr[] = {[8], ... }         |  * Partition:   arr[] = {[8], ... }         |
             |   |         + ------------------------------------------- + ------------------------------------------- +
             |   |         ⮕ Array of size 1 [8] (BASE-CASE)
             |   |
             |   |--(4) Fourth-Step: quickSort(arr[], 1, 1) {} // GOING RIGHT
             |             + ------------------------------------------- + ------------------------------------------- +
             |             | Before:                                     | After:                                      |
             |             |  * Array State: arr[] = {8, 15, 22, 30, 16} |  * Array State: arr[] = {8, 15, 22, 30, 16} |
             |             |  * Partition:   arr[] = { ... , [15], ... } |  * Partition:   arr[] = { ... , [15], ... } |
             |             + ------------------------------------------- + ------------------------------------------- +
             |             ⮕ Array of size 1 [15] (BASE-CASE)
             |
             |--(5) Fifth-Step: quickSort(arr[], 2, 4) {} // GOING RIGHT
                 |     + --------------------------------------------- + ----------------------------------------------- +
                 |     | Before:                                       | After:                                          |
                 |     |  * Array State: arr[] = {8, 15, 22, 30, 16}   |  * Array State: arr[] = {8, 15, 22, 16, 30}     |
                 |     |  * Partition:   arr[] = { ... , [22, 30, 16]} |  * Partition:   arr[] = { ... , [22, ❰16❱, 30]} |
                 |     + --------------------------------------------- + ----------------------------------------------- +
                 |     ⮕ A call to partitionFunction(arr[], 2, 4) is made
                 |        Pivot is set as the middle element ❰30❱ -> [22, ❰30❱, 16]
                 |        Pointers Initialized -> (i) = 2 - 1, (j) = 4 + 1
                 |         (i++) -> (i) = 2 -> [22] Compared with ❰30❱, [22] is less than ❰30❱, Continue
                 |         (i++) -> (i) = 3 -> [30] Compared with ❰30❱, [30] is not less than ❰30❱, Stop here
                 |         (j--) -> (j) = 4 -> [16] Compared with ❰30❱, [16] is not greater than ❰30❱, Stop here
                 |     (+) [30] & [16] are swapped -> [22, ❰16❱, 30]
                 |         (i++) -> (i) = 4 -> [30] Compared with ❰16❱, [30] is not less than ❰16❱, Stop here
                 |         (j--) -> (j) = 3 -> [16] Compared with ❰16❱, [16] is not greater than ❰16❱, Stop here
                 |         (i) has moved past (j) -> pivotIndex = (j) = 3
                 |     ⮕ Return: pivotIndex = 3
                 |
                 |--(6) Sixth-Step: quickSort(arr[], 2, 3) {} // GOING LEFT
                 |   |     + ----------------------------------------------- + ------------------------------------------------- +
                 |   |     | Before:                                         | After:                                            |
                 |   |     |  * Array State: arr[] = {8, 15, 22, 16, 30}     |  * Array State: arr[] = {8, 15, 16, 22, 30}       |
                 |   |     |  * Partition:   arr[] = { ... , [22, 16], ... } |  * Partition:   arr[] = { ... , [❰16❱, 22], ... } |
                 |   |     + ----------------------------------------------- + ------------------------------------------------- +
                 |   |     ⮕ A call to partitionFunction(arr[], 2, 3) is made
                 |   |        Pivot is set as the middle element ❰22❱ -> [❰22❱, 16]
                 |   |        Pointers Initialized -> (i) = 2 - 1, (j) = 3 + 1
                 |   |         (i++) -> (i) = 2 -> [22] Compared with ❰22❱, [22] is not less than ❰22❱, Stop here
                 |   |         (j--) -> (j) = 3 -> [16] Compared with ❰22❱, [16] is not greater than ❰22❱, Stop here
                 |   |     (+) [22] & [16] are swapped -> [❰16❱, 22]
                 |   |         (i++) -> (i) = 3 -> [22] Compared with ❰16❱, [22] is not less than ❰16❱, Stop here
                 |   |         (j--) -> (j) = 2 -> [16] Compared with ❰16❱, [16] is not greater than ❰16❱, Stop here
                 |   |         (i) has moved past (j) -> pivotIndex = (j) = 2
                 |   |     ⮕ Return: pivotIndex = 2
                 |   |
                 |   |--(7) Seventh-Step: quickSort(arr[], 2, 2) {} // GOING LEFT
                 |   |         + ------------------------------------------- + ------------------------------------------- +
                 |   |         | Before:                                     | After:                                      |
                 |   |         |  * Array State: arr[] = {8, 15, 16, 22, 30} |  * Array State: arr[] = {8, 15, 16, 22, 30} |
                 |   |         |  * Partition:   arr[] = { ... , [16], ... } |  * Partition:   arr[] = { ... , [16], ... } |
                 |   |         + ------------------------------------------- + ------------------------------------------- +
                 |   |         ⮕ Array of size 1 [16] (BASE-CASE)
                 |   |
                 |   |--(8) Eighth-Step: quickSort(arr[], 3, 3) {} // GOING RIGHT
                 |             + ------------------------------------------- + ------------------------------------------- +
                 |             | Before:                                     | After:                                      |
                 |             |  * Array State: arr[] = {8, 15, 16, 22, 30} |  * Array State: arr[] = {8, 15, 16, 22, 30} |
                 |             |  * Partition:   arr[] = { ... , [22], ... } |  * Partition:   arr[] = { ... , [22], ... } |
                 |             + ------------------------------------------- + ------------------------------------------- +
                 |             ⮕ Array of size 1 [22] (BASE-CASE)
                 |
                 |--(9) Ninth-Step: quickSort(arr[], 4, 4) {} // GOING RIGHT
                           + ------------------------------------------- + ------------------------------------------- +
                           | Before:                                     | After:                                      |
                           |  * Array State: arr[] = {8, 15, 16, 22, 30} |  * Array State: arr[] = {8, 15, 16, 22, 30} |
                           |  * Partition:   arr[] = { ... , [30]}       |  * Partition:   arr[] = { ... , [30]}       |
                           + ------------------------------------------- + ------------------------------------------- +
                           ⮕ Array of size 1 [30] (BASE-CASE)

        * SORTED: arr[] = {8, 15, 16, 22, 30}, Total # of Swaps: 4
-----------------------------------------------------------------------------------------------------------------------------------------
>> Note: While having otherwise identical time & space complexities to QuickSort implementing Lomuto's partitioning scheme, Hoare's
         partitioning scheme is more efficient due to using an average of 3x less swaps than Lomuto's. This is because Hoare's selects
         the pivot as the middle element, and by using a two pointer approach to traverse the sub-array, swaps are only done when
         necessary (# of swaps is proportional to # of elements that need to be rearranged). On the other hand, Lomuto's selects the
         pivot as the last element, and uses a single pointer to traverse the sub-array. This can lead to redundant swaps because it may
         require multiple passes to position elements correctly relative to the pivot (# of swaps is proportional to # of elements in the
         sub-array segment).
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
The partitionFunction() partitions the dataArray segment using Hoare's partitioning scheme. All elements that are less than the pivot
element are moved to the left of the pivot, and all elements greater than the pivot element are moved to the right of the pivot.
    >> Parameters:
            int dataArray[] - Pointer to array of integers
            int low - Index of the first element in sub-array to be sorted
            int high - Index of the last element in sub-array to be sorted
    >> Return:
            int j - Index of the partition boundary
-----------------------------------------------------------------------------------------------------------------------------------------
*/
int partitionFunction(int dataArray[], int low, int high)
{
    int middleIndex = low + (high - low) / 2; // Calculate the middle index of the sub-array
    int pivot = dataArray[middleIndex];       // Set the pivot = middle element of sub-array [middleIndex]

    int i = (low - 1);  // Initialize i to (-1)
    int j = (high + 1); // Initialize j size of array (arraySize + 1)

    while (true)
    {
        // First we increment [i] until [i] points to an element greater than the element at index [middle] (pivot)
        do
        {
            i++; // [i] Moves toward higher index [->]

            // Continue moving right towards the highest index...
        } while (dataArray[i] < pivot); // ...While the element at index [i] is LESS than the pivot

        // Next we decrement [j] until [j] points to an element less than the element at index [middle] (pivot)
        do
        {
            j--; // [j] Moves toward lower index index [<-]

            // Continue moving left towards the smallest index...
        } while (dataArray[j] > pivot); // ...While the element at index [j] is GREATER than the pivot

        // If the termination condition is met(i >= j)
        if (i >= j) // [i] has moved past [j]
        {
            return j; // Return j as the new partition boundary
        }

        // Otherwise condition not met - Swap the element in dataArray[i] with the element in dataArray[j] & loop again
        int temp = dataArray[i];     // Temp becomes element @ index [i]
        dataArray[i] = dataArray[j]; // Element @ index [i] overwritten by element @ index [j]
        dataArray[j] = temp;         // Element @ index [j] now = temp
    }
}

/*
-----------------------------------------------------------------------------------------------------------------------------------------
The quickSort() function recursively sorts the segment of the array between the low & high indices. Uses a helper function
"partitionFunction()" which implements Hoare's partitioning scheme.
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

        quickSort(dataArray, low, pivotIndex);        // Recursive call for left partition
        quickSort(dataArray, (pivotIndex + 1), high); // Recursive call for right partition
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
         << "Running QuickSort - Hoare's Partitioning Scheme..." << endl;
    // Call the quickSort() function to sort the array
    quickSort(dataArray, 0, (arraySize - 1));

    // Print the sorted array
    cout << endl
         << "Array after sorting:";
    printArray(dataArray, arraySize);
    cout << endl;

    return 0;
}
