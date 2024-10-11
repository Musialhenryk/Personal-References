/*
Author: Henryk Musial
10/1/2024
*/

/*
-----------------------------------------------------------------------------------------------------------------------------------------
>> MERGESORT <<
-----------------------------------------------------------------------------------------------------------------------------------------
This mergesort.cpp file is a personal reference of the MergeSort algorithm. The MergeSort algorithm is a recursive algorithm that is
based on the divide-and-conquer approach. MergeSort works by recursively dividing an unsorted array in half until each sub-array is of
size one, and then merges the sub-arrays back together in sorted order. This merging process is facilitated through the helper function
merge(), which takes a pair of adjacent sub-arrays on the same branch of the recursion tree and merges them into sorted order.
-----------------------------------------------------------------------------------------------------------------------------------------
>> MergeSort: Accepts a pointer to an array, along with the left & right indices of the sub-array to be sorted. When the sub-array has
        more than one element, MergeSort recursively divides the left half into left & right pairs until a pair of adjacent sub-arrays
        are both of size one. At this point, each sub-array is considered sorted. Once the base case of size one is reached for a pair of
        sub-arrays, MergeSort calls the helper method Merge to combine the two adjacent sub-arrays into a single sorted sub-array. As we
        traverse back up the recursion tree, we continue to merge the sorted sub-array pairs until we reach the original call frame of
        the first MergeSort call. This process then repeats for the right half of the array, and stops once the final call to Merge is
        made and the two halves of size (left + right) / 2 are combined. Through this recursive dividing/merging process, the sorted
        property of the array emerges.

>> Merge: Initializes three pointers, (l), (r), & (t), which are set to the starting indices of the left sub-array, the right sub-array,
        and a temporary array respectively. This temporary array is used to store the merged result, and is dynamically allocated based
        on the combined size of the sub-array pair. Starting at the first element in the left sub-array, element [l] is compared against
        element [r], and the smaller of the two elements is stored in the temporary array at index [t]. If the element in the left
        sub-array was smaller, we increment (l), otherwise, we increment (r). In either case, (t) is incremented and the comparison is
        repeated as long as both the left & right sub-arrays have untraversed elements. Any element that was not traversed by its own
        pointer is stored at the next available position in the temporary array. This does not violate the sorted order of the temporary
        array because any untraversed elements from either sub-array were already put into sorted order by prior call/s to Merge. As a
        result, the untraversed element will always be greater than the last element in the temporary array. Through this process, the
        merged sequence of elements in the temporary array have been sorted into increasing (->) order, and the sub-array bounded by the
        [left] and [right] indices is overwritten by the corresponding values in the temporary array.
-----------------------------------------------------------------------------------------------------------------------------------------
>> Stable Algorithm: MergeSort is a stable algorithm, meaning that elements with equal values will always retain their relative order in
                     the sorted array.
-----------------------------------------------------------------------------------------------------------------------------------------
>> Time Complexity:
        All-cases: O(n*log(n)) - The array is recursively divided in half, where each division results in two sub-arrays of size (n/2).
                                 Recursion tree has a depth of log(n) levels before reaching base case of an array of size (1). Because
                                 the left & right halves of the array are processed separately, each recursive call to MergeSort for
                                 either half must process and merge (n/(2^level)) elements on return. Therefore, a total of (n/(2^level))
                                 * (2^level) -> (n) elements must be processed and merged for each level of the recursion tree.
                                    O(n) - Level of recursion tree, n = # of elements in array
                                     * (for-each)
                                    O(log(n)) - Depth (levels) of recursion tree, n = # of elements in array
                                     = O(n*log(n))
-----------------------------------------------------------------------------------------------------------------------------------------
>> Space Complexity:
        All-cases: O(n+log(n)) - Each call of MergeSort requires O(n) auxilliary space to merge and store the sub-array pairs within a
                                 temporary array. Because the left & right halves of the array are processed separately, each recursive
                                 call to MergeSort for either half must allocate a temporary array of size (n/(2^level)). Therefore, a
                                 total of (n/(2^level)) * (2^level) -> (n) auxilliary space is allocated for each level of the recursion
                                 tree. Each temporary array is deallocated after merging, therefore storage does not accumulate across
                                 the call frames. log(n) number of recursive call frames added to the call stack before array of size (1)
                                 (depth of recursion tree).
                                    O(n) - Largest temporary array allocated for merging, n = # of elements in array
                                     + (and)
                                    O(log(n)) - Recursive call frames added to the call stack, n = # of elements in array
                                     = O(n+log(n))
-----------------------------------------------------------------------------------------------------------------------------------------
>> Recursion Tree Diagram:
        Key: () = Maps to Execution Steps Below
        Array = {22, 8, 15, 30, 16};

        * DIVIDE:   (1) [22, 8, 15, 30, 16]---|                 [Level 0]: [Cn]------------------|
                         |                    |                             |                    |
                    (2) [22, 8, 15]--|   (6) [30, 16]-|         [Level 1]: [Cn/2]---------|     [Cn/2]--|
                         |           |        |       |                     |             |      |      |
                    (3) [22, 8]-|    |        |       |         [Level 2]: [Cn/4]--|      |      |      |
                         |      |    |        |       |                     |      |      |      |      |
                        [22]   [8]  [15]     [30]    [16]       [Level 3]: [Cn/8] [Cn/8] [Cn/4] [Cn/4] [Cn/4] <- Base Case

        * CONQUER:      [22]   [8]  [15]     [30]    [16]       Cost per level = Cn
                         |      |    |        |       |         Number of levels = log(n) + 1
                    (4) [8, 22]-|    |        |       |         Total Cost O(n) = (log(n) + 1) * Cn
                         |           |        |       |                    O(n) = (Cn * log(n)) + Cn
                    (5) [8, 15, 22]--|   (7) [16, 30]-|                    O(n) = n * log(n)
                         |                    |
                    (8) [8, 15, 16, 22, 30]---|
-----------------------------------------------------------------------------------------------------------------------------------------
>> Example MergeSort Execution:
        Key: {} = Array, [] = Sub-Array
        Array = {22, 8, 15, 30, 16};

        * UNSORTED: arr[] = {22, 8, 15, 30, 16}

            (1) First-Step: mergeSort(arr[], 0, 4) {}
             |     + --------------------------------------------- + ----------------------------------------------- +
             |     | Before:                                       | After:                                          |
             |     |  * Array State: arr[] = {22, 8, 15, 30, 16}   |  * Array State: arr[] = {22, 8, 15, 30, 16}     |
             |     |  * Sub-Array:   arr[] = {[22, 8, 15, 30, 16]} |  * Sub-Array/s: arr[] = {[22, 8, 15], [30, 16]} |
             |     + --------------------------------------------- + ----------------------------------------------- +
             |     ⮕ The array is split into 2 halves: {22, 8, 15, 30, 16} -> {[22, 8, 15], [30, 16]}
             |
             |  (2) Second-Step: mergeSort(arr[], 0, 2) {} // GOING LEFT
             |   |     + ------------------------------------------- + --------------------------------------------- +
             |   |     | Before:                                     | After:                                        |
             |   |     |  * Array State: arr[] = {22, 8, 15, 30, 16} |  * Array State: arr[] = {22, 8, 15, 30, 16}   |
             |   |     |  * Sub-Array:   arr[] = {[22, 8, 15], ... } |  * Sub-Array/s: arr[] = {[22, 8], [15], ... } |
             |   |     + ------------------------------------------- + --------------------------------------------- +
             |   |     ⮕ The left sub-array is split into 2 halves: {[22, 8, 15], ... } -> {[22, 8], [15], ... }
             |   |        [15] Is sorted (BASE-CASE)
             |   |
             |   |  (3) Third-Step: mergeSort(arr[], 0, 1) {} // GOING LEFT
             |   |   |     + ------------------------------------------- + ------------------------------------------- +
             |   |   |     | Before:                                     | After:                                      |
             |   |   |     |  * Array State: arr[] = {22, 8, 15, 30, 16} |  * Array State: arr[] = {22, 8, 15, 30, 16} |
             |   |   |     |  * Sub-Array:   arr[] = {[22, 8], ... }     |  * Sub-Array/s: arr[] = {[22], [8], ... }   |
             |   |   |     + ------------------------------------------- + ------------------------------------------- +
             |   |   |     ⮕ The left sub-array is split into 2 halves: {[22, 8], ... } -> {[22], [8], ... }
             |   |   |        [22] & [8] Are sorted (BASE-CASE)
             |   |   |
             |   |  (4) Fourth-Step: merge(arr[], 0, 0, 1) {} // MERGE
             |   |         + ------------------------------------------- + ------------------------------------------- +
             |   |         | Before:                                     | After:                                      |
             |   |         |  * Array State: arr[] = {22, 8, 15, 30, 16} |  * Array State: arr[] = {8, 22, 15, 30, 16} |
             |   |         |  * Sub-Array/s: arr[] = {[22], [8], ... }   |  * Sub-Array:   arr[] = {[8, 22], ... }     |
             |   |         + ------------------------------------------- + ------------------------------------------- +
             |   |         ⮕ Merge the adjacent sub-arrays: {[22], [8], ... } -> {[X, X], ... }
             |   |            [22] Compared with [8], [8] is less than [22] -> temp[2] = {8, }
             |   |            [22] Stored at end -> temp[2] = {8, 22} -> temp[2] Copied back into arr[]
             |   |         ⮕ The adjacent sub-arrays are merged: arr[] = {[8, 22], ... }
             |   |
             |  (5) Fifth-Step: merge(arr[], 0, 1, 2) {} // MERGE
             |         + --------------------------------------------- + ------------------------------------------- +
             |         | Before:                                       | After:                                      |
             |         |  * Array State: arr[] = {8, 22, 15, 30, 16}   |  * Array State: arr[] = {8, 15, 22, 30, 16} |
             |         |  * Sub-Array/s: arr[] = {[8, 22], [15], ... } |  * Sub-Array:   arr[] = {[8, 15, 22], ... } |
             |         + --------------------------------------------- + ------------------------------------------- +
             |         ⮕ Merge the adjacent sub-arrays: {[8, 22], [15], ... } -> {[X, X, X], ... }
             |            [8] Compared with [15], [8] is less than [15] -> temp[3] = {8, , }
             |            [22] Compared with [15], [15] is less than [22] -> temp[3] = {8, 15, }
             |            [22] Stored at end -> temp[3] = {8, 15, 22} -> temp[3] Copied back into arr[]
             |         ⮕ The adjacent sub-arrays are merged: arr[] = {[8, 15, 22], ... }
             |
             |  (6) Sixth-Step: mergeSort(arr[], 3, 4) {} // GOING RIGHT
             |   |     + ------------------------------------------- + ------------------------------------------- +
             |   |     | Before:                                     | After:                                      |
             |   |     |  * Array State: arr[] = {8, 15, 22, 30, 16} |  * Array State: arr[] = {8, 15, 22, 30, 16} |
             |   |     |  * Sub-Array:   arr[] = { ... , [30, 16]}   |  * Sub-Array/s: arr[] = { ... , [30], [16]} |
             |   |     + ------------------------------------------- + ------------------------------------------- +
             |   |     ⮕ The right sub-array is split into 2 halves: { ... , [30, 16]} -> { ... , [30], [16]}
             |   |        [30] & [16] Are sorted (BASE-CASE)
             |   |
             |  (7) Seventh-Step: merge(arr[], 3, 3, 4) {} // MERGE
             |         + ------------------------------------------- + ------------------------------------------- +
             |         | Before:                                     | After:                                      |
             |         |  * Array State: arr[] = {8, 15, 22, 30, 16} |  * Array State: arr[] = {8, 15, 22, 16, 30} |
             |         |  * Sub-Array/s: arr[] = { ... , [30], [16]} |  * Sub-Array:   arr[] = { ... , [16, 30]}   |
             |         + ------------------------------------------- + ------------------------------------------- +
             |         ⮕ Merge the adjacent sub-arrays: { ... , [30], [16]} -> { ... , [X, X]}
             |            [30] Compared with [16], [16] is less than [30] -> temp[2] = {16, }
             |            [30] Stored at end -> temp[2] = {16, 30} -> temp[2] Copied back into arr[]
             |         ⮕ The adjacent sub-arrays are merged: arr[] = { ..., [16, 30]}
             |
            (8) Eighth-Step: merge(arr[], 0, 2, 4) {} // MERGE
                   + ----------------------------------------------- + --------------------------------------------- +
                   | Before:                                         | After:                                        |
                   |  * Array State: arr[] = {8, 15, 22, 16, 30}     |  * Array State: arr[] = {8, 15, 16, 22, 30}   |
                   |  * Sub-Array/s: arr[] = {[8, 15, 22], [16, 30]} |  * Sub-Array:   arr[] = {[8, 15, 16, 22, 30]} |
                   + ----------------------------------------------- + --------------------------------------------- +
                   ⮕ Merge the adjacent sub-arrays: {[8, 15, 22], [16, 30]} -> {[X, X, X, X, X]}
                      [8] Compared with [16], [8] is less than [16] -> temp[5] = {8, , , , }
                      [15] Compared with [16], [15] is less than [16] -> temp[5] = {8, 15, , , }
                      [22] Compared with [16], [16] is less than [22] -> temp[5] = {8, 15, 16, , }
                      [22] Compared with [30], [22] is less than [30] -> temp[5] = {8, 15, 16, 22, }
                      [30] Stored at end -> temp[5] = {8, 15, 16, 22, 30} -> temp[5] Copied back into arr[]
                   ⮕ The adjacent sub-arrays are merged: arr[] = {[8, 15, 16, 22, 30]}

        * SORTED: arr[] = {8, 15, 16, 22, 30}
-----------------------------------------------------------------------------------------------------------------------------------------
>> Compile & Run:
        g++ mergesort.cpp || g++ mergesort.cpp -g -o mergesort
        ./a.out || valgrind ./a.out || valgrind ./mergesort || valgrind --leak-check=full ./mergesort
-----------------------------------------------------------------------------------------------------------------------------------------
*/

#include <iostream> // cout
#include <fstream>  // ifstream
#include <sstream>  // stringstream
#include <string>   // string

using namespace std;

/*
-----------------------------------------------------------------------------------------------------------------------------------------
The merge() function takes two sorted sub-arrays bounded by the indices (left -> middle) & (middle + 1 -> right) and merges them into a
single sorted array. The smallest element is inserted into the lowest available index, and the largest is inserted into the highest
available index.
    >> Parameters:
            int dataArray[] - Pointer to array of integers containing the sub-arrays to be merged
            int left - Starting index of the left sub-array bounded by [left] & [middle]
            int middle - Index where the array is divided (The ending index of the left sorted sub-array)
            int right - Starting index of the right sub-array bounded by [middle] & [right]
-----------------------------------------------------------------------------------------------------------------------------------------
*/
void merge(int dataArray[], int left, int middle, int right)
{
    int l = left;       // Starting index for the left sub-array
    int r = middle + 1; // Starting index for the right sub-array
    int t = left;       // Starting index for the temp sub-array

    int size = (right - left) + 1; // Calculate the dynamic size of the temporary array to hold the merged result
    int *temp = new int[size];     // Dynamically allocated temporary array to store the merged elements

    // Merge the two sorted sub-arrays into the temp array
    while (l <= middle && r <= right) // While there are elements in both sub-arrays
    {
        // Check if the element in left sub-array is (<=) the element in the right sub-array
        if (dataArray[l] <= dataArray[r])
        {
            // The element in the left sub-array was smaller (or equal)
            temp[t - left] = dataArray[l]; // Store the smaller left element in the temp array
            l++;                           // Move to the next element in the left sub-array
        }
        else
        {
            // The element in the right sub-array was smaller
            temp[t - left] = dataArray[r]; // Store the smaller right element in the temp array
            r++;                           // Move to the next element in the right sub-array
        }

        t++; // Move to the next position in the temporary array
    }

    // Copy the remaining left elements into the temporary array
    while (l <= middle) // While there are still elements in the left sub-array
    {
        temp[t - left] = dataArray[l]; // Store the element in the left sub-array in the temp array

        l++; // Move to the next element in the left sub-array
        t++; // Move to the next position in the temporary array
    }

    // Copy the remaining right elements into the temporary array
    while (r <= right) // While there are still elements in the right sub-array
    {
        temp[t - left] = dataArray[r]; // Store the element in the right sub-array in the temp array

        r++; // Move to the next element in the right sub-array
        t++; // Move to the next position in the temporary array
    }

    // Copy the merged sub-arrays back into the dataArray
    for (int i = left; i <= right; i++)
    {
        dataArray[i] = temp[i - left]; // Overwrite the elements at index [i]
    }

    delete[] temp; // Free dynamically allocated memory (*temp array)
}

/*
-----------------------------------------------------------------------------------------------------------------------------------------
The mergeSort() function recursively divides the array into smaller and smaller sub-arrays until each sub-array is considered sorted
(sub-array of size one). Once the left half has been divided into sub-arrays of size one, a helper function "merge()" merges the
sub-arrays back together in sorted order. This process is then repeated for the right half of the array.
    >> Parameters:
            int dataArray[] - Pointer to array of integers
            int left - Starting index of the sub-array to be sorted
            int right - Ending index of the sub-array to be sorted
-----------------------------------------------------------------------------------------------------------------------------------------
*/
void mergeSort(int dataArray[], int left, int right)
{
    // Base-case: left = right (sub-array of size 1)
    // Recursive-case: left < right (sub-array of size 2 or more)
    // Error Condition: left > right

    if (left < right) // If the dataArray segment has more than 1 element
    {
        int middle = (left + right) / 2;           // Calculate the middle index of the array
        mergeSort(dataArray, left, middle);        // Recursively divide & sort the left half of the array
        mergeSort(dataArray, (middle + 1), right); // Recursively divide & sort the right half of the array
        merge(dataArray, left, middle, right);     // Merge the two sorted halves into a single sorted segment
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
terminal before and after the MergeSort algorithm is performed.
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
         << "Running MergeSort..." << endl;
    // Call the mergeSort() function to sort the array
    mergeSort(dataArray, 0, (arraySize - 1));

    // Print the sorted array
    cout << endl
         << "Array after sorting:";
    printArray(dataArray, arraySize);
    cout << endl;

    return 0;
}
