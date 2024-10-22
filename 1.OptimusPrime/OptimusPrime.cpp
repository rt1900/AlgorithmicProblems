
#include <iostream>
#include <vector>

using namespace std;

// Функция для нахождения всех простых чисел до числа n
vector<int> sieveOfEratosthenes(int n) {
    if (n < 2) return vector<int>(); // Если n меньше 2, простых чисел нет

    // Массив для нечетных чисел, размером (n + 1) / 2
    vector<bool> isPrime((n + 1) / 2, true);
    vector<int> primes;

    // Добавляем 2 в список простых чисел, так как это единственное четное простое число
    primes.push_back(2);

    // Цикл для нечетных чисел начиная с 3 (только нечетные числа)
    for (int i = 3; i * i <= n; i += 2) {
        if (isPrime[i / 2]) { // Проверяем только нечетные числа
            // Помечаем кратные i числа как составные
            for (int j = i * i; j <= n; j += 2 * i) {
                isPrime[j / 2] = false; // Помечаем как составное
            }
        }
    }

    // Собираем все простые числа
    for (int i = 1; 2 * i + 1 <= n; ++i) {
        if (isPrime[i]) {
            primes.push_back(2 * i + 1); // Восстанавливаем нечетные числа
        }
    }

    return primes;
}

int main() {
    int x;
    cout << "Enter a number within the range in which you want to find all prime numbers: ";
    cin >> x;

    // Находим все простые числа до x
    vector<int> primes = sieveOfEratosthenes(x);

    // Выводим найденные простые числа
    cout << "Prime numbers up to " << x << " are:" << endl;
    for (size_t i = 0; i < primes.size(); ++i) {
    cout << primes[i] << " ";
    }
 
    cout << endl << endl;

    // Спрашиваем у пользователя, какое по счету простое число он хочет получить
    int target;
    cout << "Enter the ordinal number of the prime you want to get: ";
    cin >> target;

    // Для поиска большого по счету простого числа увеличиваем предел для решета
    int limit = 2000000; // Примерная граница для поиска 10001-го простого числа
    vector<int> largePrimes = sieveOfEratosthenes(limit);

    // Проверяем, есть ли запрошенное простое число
    if (target - 1 < largePrimes.size()) {
        cout << "The " << target << "th prime number is: " << largePrimes[target - 1] << endl;
    } else {
        cout << "The requested prime number is outside the calculated range." << endl;
    }

    return 0;
}