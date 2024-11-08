



#include <iostream>
#include <chrono>

using namespace std;

int main() {
    chrono::time_point<chrono::high_resolution_clock> start = chrono::high_resolution_clock::now();

    long long count = 0;
    const long long limit = 200000;

    for (long long a = 1; a <= limit; ++a) {
        long long N = 8 * a * a * a + 15 * a * a + 6 * a - 1;

        // Добавляем проверку a * a < N / 27
        if (a * a >= N / 27) {
            continue;
        }

        for (long long b = 1; b <= limit - a; ++b) {
            long long denominator = 27 * b * b;

            if (N % denominator == 0) {
                long long c = N / denominator;

                if (c > 0 && a + b + c <= limit) {
                    ++count;
                }
            }

            if (a + b + 1 > limit) {
                break;
            }
        }

        if (a + 2 > limit) {
            break;
        }
    }

    cout << "Total Cardano triplets where a + b + c <= " << limit << ": " << count << endl;

    chrono::time_point<chrono::high_resolution_clock> end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;
    cout << "Execution time: " << duration.count() << " seconds" << endl;

    return 0;
}
