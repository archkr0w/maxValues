#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Function to calculate the maximum value using Method 1: m! / (m - n)!n!
 *
 * @param n The value of n.
 * @param k The value of k.
 * @return The maximum value calculated as an unsigned 64-bit integer (unsigned long long).
 */
unsigned long long calculateMaximumMethod1(int n, int k) {
    unsigned long long result = 1; // Initialize the result to 1.

    // This loop calculates the maximum value using the formula m! / (m - n)!n!.
    for (int i = 1; i <= k; i++) {
        result *= (n - k + i); // Multiply the result by (n - k + i).
        result /= i;           // Divide the result by i.
    }

    return result; // Return the maximum value calculated as an unsigned 64-bit integer (unsigned long long).
}

/**
 * Function to calculate the maximum value using Method 2 without recursion.
 *
 * @param n Value n used in the calculation.
 * @param k Value k used in the calculation.
 * @return The calculated maximum value.
 */
double calculateMaximumMethod2WithoutRecursion(int n, int k) {
    double result = 0.0; // Initialize the result to 0.

    // Iterate from 1 to k.
    for (int i = 1; i <= k; i++) {
        // In each iteration, calculate a fraction and add it to the result.
        // The fraction is calculated as (n - i) / (k + i), and it is added to the current result.
        result += (double)(n - i) / (k + i);
    }

    return result; // Return the calculated maximum value.
}

/**
 * Function to perform a base conversion of a number.
 *
 * @param number The number to be converted to a different base.
 * @param base The new desired base for the number (e.g., 2 for binary, 16 for hexadecimal).
 * @return The number converted to the specified base as an unsigned 64-bit integer (unsigned long long).
 */
unsigned long long baseConversion(unsigned long long number, int base) {
    unsigned long long result = 0; // Initialize the result to 0.
    unsigned long long power = 1; // Initialize the power to 1.

    // While the original number is greater than 0, continue the process.
    while (number > 0) {
        // Get the digit in the new base as the remainder of dividing the number by the base.
        // Then, multiply this digit by the appropriate power and add it to the result.
        result += (number % base) * power;

        // Divide the original number by the base to continue with the next digit.
        number /= base;

        // Increment the multiplying power, which depends on the base (default is 10 for base 10).
        power *= 10;
    }

    return result; // Return the number converted to the specified base as an unsigned 64-bit integer.
}

/**
 * Main function of the program.
 *
 * @param argc The number of arguments passed from the command line.
 * @param argv An array of strings containing the arguments passed from the command line.
 * @return Returns 0 if the execution is successful; otherwise, it may return 1 to indicate an error.
 */
int main(int argc, char *argv[]) {
    // Check if the number of arguments passed from the command line is equal to 5.
    if (argc != 5) {
        printf("Usage: %s [1 or 2] n k base\n", argv[0]);
        return 1; // Return 1 to indicate an error in the execution.
    }

    // Convert the arguments passed from the command line into integers and assign them to variables.
    int method = atoi(argv[1]); // Method for calculating the maximum value
    int n = atoi(argv[2]);      // Value n
    int k = atoi(argv[3]);      // Value k
    int base = atoi(argv[4]);   // Base for the base conversion

    double result = 0.0; // Variable to store the calculation result.

    // Check the value of the selected method.
    if (method == 1) {
        result = calculateMaximumMethod1(n, k); // Calculate the maximum value using Method 1.
    } else if (method == 2) {
        result = calculateMaximumMethod2WithoutRecursion(n, k); // Calculate the maximum value using Method 2 without recursion.
    } else {
        printf("Invalid option. Select 1 or 2.\n");
        return 1; // Return 1 to indicate an error in the execution if an invalid method is selected.
    }

    double resultBase10 = result; // Preserve the calculated value in base 10.
    double resultBase = baseConversion(result, base); // Perform the base conversion.

    // Print the results to the screen.
    printf("The maximum value in base 10 is: %.2f\n", resultBase10);
    printf("The maximum value in base %d is: %.6f\n", base, resultBase);

    return 0; // Return 0 to indicate a successful execution.
}
