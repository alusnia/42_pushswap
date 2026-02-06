🔄 Push_swap
Push_swap is a highly efficient sorting algorithm project developed at 42 School. The goal is to sort a stack of integers using a limited set of instructions (push, swap, rotate) with the lowest possible number of operations.

This implementation utilizes data indexing and the Turk Sort algorithm to achieve optimized performance.

🧠 The Algorithm

My approach divides the problem into two distinct phases: Pre-processing and Sorting.

1. Indexing & Pre-processing
   
-Before sorting the stack, the program simplifies the data:
		
-The input numbers are copied to an integer array.
		
-This array is sorted using a custom implementation of Quicksort.
		
-The raw values in the stack are replaced by their ranks (indices from 0 to N-1).
		
-Example: Input [500, -20, 10] becomes [2, 0, 1].
		
-This abstraction allows the main algorithm to work purely on relative positions rather than arbitrary integer values.

2. Turk Sort

The main sorting logic is based on the Turk Sort strategy

-Push elements from Stack A to Stack B, intelligently checking if they can be placed in sorted order or if they need to be rotated.

-Calculate the "cost" (number of operations) to push elements back from B to A in the correct position.

-Execute the cheapest move iteratively until Stack A is sorted.


🛠️ Installation
To compile the project, simply run:

Bash
make
This will generate the push_swap executable.


🧪 Automated Testing Suite
This project includes a robust testing environment to ensure accuracy and efficiency across various input sizes.

The test Directory
I have included a set of pre-generated test cases in the test/ folder (files: test5, test50, test100, test500).

-Size 5: Contains all 120 possible permutations (5!) to ensure the algorithm handles every edge case perfectly.

-Sizes 50, 100, 500: Each file contains 100 random combinations to benchmark average operation counts.

Running the Tests
After compiling the program with make, you can execute the full test suite using the provided bash script. This script validates that the output is sorted and checks the operation count.

	bash test.sh
	
The script will output the results for each category (OK/KO and operation count).

🚀 Usage
You can also run the program manually by providing a list of integers as arguments:

	./push_swap 2 1 3 6 5 8
	
To verify the result using the checker (if installed):

	ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
