#include <iostream>
using namespace std;

long long largestPrimeFactor(long long n) {
    long long largestFactor = 1;

    // Удаляем все множители двойки
    while (n % 2 == 0) {
        largestFactor = 2;
        n /= 2;
    }

    // Проверяем нечетные множители
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            largestFactor = i;
            n /= i;
        }
    }

    // Если n больше 2, то это и есть самый большой простой множитель
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
