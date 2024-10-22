
#include <iostream>
#include <vector>

using namespace std;

// Function to find all prime numbers up to number n
vector<int> sieveOfEratosthenes(int n) {
    if (n < 2) return vector<int>(); // If n is less than 2, there are no prime numbers

    // Array for odd numbers, size (n + 1) / 2
    vector<bool> isPrime((n + 1) / 2, true);
    vector<int> primes;

    // Adding 2 to the list of prime numbers since it's the only even prime number
    primes.push_back(2);

    // Loop for odd numbers starting from 3 (only odd numbers)
    for (int i = 3; i * i <= n; i += 2) {
        if (isPrime[i / 2]) { // Check only odd numbers
            // Mark multiples of i as composite
            for (int j = i * i; j <= n; j += 2 * i) {
                isPrime[j / 2] = false; // Mark as composite
            }
        }
    }

    // Collect all prime numbers
    for (int i = 1; 2 * i + 1 <= n; ++i) {
        if (isPrime[i]) {
            primes.push_back(2 * i + 1); // Restoring odd numbers
        }
    }

    return primes;
}

int main() {
    int x;
    cout << "Enter a number within the range in which you want to find all prime numbers: ";
    cin >> x;

    // Find all prime numbers up to x
    vector<int> primes = sieveOfEratosthenes(x);

    // Output the found prime numbers
    cout << "Prime numbers up to " << x << " are:" << endl;
    for (size_t i = 0; i < primes.size(); ++i) {
    cout << primes[i] << " ";
    }
 
    cout << endl << endl;

    // Ask the user which prime number (ordinal) they want to get
    int target;
    cout << "Enter the ordinal number of the prime you want to get: ";
    cin >> target;

    // To find a large ordinal prime number, increase the limit for the sieve
    int limit = 2000000; // Approximate limit for finding the 10001st prime number
    vector<int> largePrimes = sieveOfEratosthenes(limit);

    // Check if the requested prime number exists
    if (target - 1 < largePrimes.size()) {
        cout << "The " << target << "th prime number is: " << largePrimes[target - 1] << endl;
    } else {
        cout << "The requested prime number is outside the calculated range." << endl;
    }

    return 0;
}