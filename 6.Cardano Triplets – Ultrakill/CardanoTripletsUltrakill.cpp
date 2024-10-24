#include <iostream>
#include <cmath>
using namespace std;

bool сardanoTriplet(int a, int b, int c);

int main() {
    cout<<"hello world"<<endl;
    int count = 0;
    long long limit = 1500;

    
    for (int a = 1; a <= limit; ++a) {      // Outer loop to iterate over values of a
        for (int b = 1; a + b <= limit; ++b) {        // Inner loop to iterate over values of b
            for (int c = 1; a + b + c <= limit; ++c) {      // Внутренний цикл для перебора значений c
                if (сardanoTriplet(a, b, c)) {                 // Check if it is a Cardano triplet
                    count++; 
                }
                if (a + b + c > limit) {  // If the sum a + b + c exceeds the limit, exit the innermost loop
                    break;
                }
            }
            if (a + b >= limit) {    // If the sum a + b already exceeds the limit, exit the inner loop
                break;
            }
        }
        if (a >= limit) {
            break;
        }
    }

    cout << "Total Cardano triplets where a + b + c <= 110,000,000: " << count << endl;

    return 0;
}



bool сardanoTriplet(int a, int b, int c) { // Function to check if (a, b, c) is a Cardano triplet
    double termFirst = cbrt(a + b * sqrt(c));
    double termSecond = cbrt(a - b * sqrt(c));
    return (termFirst + termSecond) == 1.0;
}