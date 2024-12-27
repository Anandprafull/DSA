#include <algorithm> // Include the algorithm header for algorithms like stable_partition
#include <iostream>  // Include the iostream header for input and output operations
#include <vector>    // Include the vector header to use the std::vector container

// Function to push all zeros in the vector to the end while maintaining the order of non-zero elements
void push_zeros_to_end(std::vector<int>& arr)
{
    // Use stable_partition to rearrange the elements in the vector
    // The lambda function returns true for non-zero elements, keeping them in place
    std::stable_partition(arr.begin(), arr.end(), [](int n) { return n != 0; });
}

int main()
{
    // Initialize a vector of integers with some zeros and non-zero values
    std::vector<int> arr{1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
  
    // Call the function to move all zeros to the end of the vector
    push_zeros_to_end(arr);
  
    // Iterate over the modified vector and print each element
    for (const auto& i : arr)
        std::cout << i << ' '; // Print each element followed by a space

    std::cout << "\n"; // Print a newline after the output

    return 0; // Return 0 to indicate successful execution of the program
}
