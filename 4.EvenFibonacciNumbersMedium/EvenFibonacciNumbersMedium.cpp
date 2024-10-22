#include <iostream>
using namespace std;

long long largestPrimeFactor(long long n) {
    long long largestFactor = 1;

    // Remove all factors of two
    while (n % 2 == 0) {
        largestFactor = 2;
        n /= 2;
    }

    // Check odd factors
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            largestFactor = i;
            n /= i;
        }
    }

    // If n is greater than 2, it is the largest prime factor
    if (n > largestFactor) {
        return n; } else 
         return largestFactor;
    
    return largestFactor;
}

int main() {

    long long number;
    cout<< "Which Number: "<<endl;
    cin>>number;
    
    cout << "The largest prime factor of " << number << " is: " << largestPrimeFactor(number) << endl;
    return 0;
}
