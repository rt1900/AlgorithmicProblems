#include <iostream>
using namespace std;

bool isPalindrome(int num) { // Function to check if a number is a palindrome
    int originalNumber = num;
    int reversedNumber = 0;

    while (num > 0) { // Reverse the number
        reversedNumber = reversedNumber * 10 + num % 10;
        num = num / 10;
    }
    return originalNumber == reversedNumber;  // Compare the original number with the reversed one
}

int main() {
    int largestPalindrome = 0;
    int multiplicand = 0, multiplier = 0;

    cout << "The largest palindrome number that is the result of multiplying two three-digit numbers:" << endl;

    for (int i = 999; i >= 100; i--) {  // Start with the largest three-digit numbers
        for (int j = i; j >= 100; j--) { // The inner loop also goes downwards
            int number = i * j;

            if (isPalindrome(number) && number > largestPalindrome) {     // Check if the product is a palindrome
                largestPalindrome = number;
                multiplicand = i;
                multiplier = j;
            }
        }
    }
    cout << "The largest palindrome is: " << largestPalindrome << " (from " << multiplicand << " * " << multiplier << ")" << endl; // Output the result
    return 0;
}
