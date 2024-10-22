#include <iostream>
using namespace std;


bool isPalindrome(int num) { // Функция для проверки, является ли число палиндромом
    int originalNumber = num;
    int reversedNumber = 0;

    
    while (num > 0) { // Разворачиваем число
        reversedNumber = reversedNumber * 10 + num % 10;
        num = num / 10;
    }

    
    return originalNumber == reversedNumber;  // Сравниваем оригинальное число с перевёрнутым
}

int main() {
    int largestPalindrome = 0;
    int multiplicand = 0, multiplier = 0;

    cout << "The largest palindrome number that is the result of multiplying two three-digit numbers:" << endl;

   
    for (int i = 999; i >= 100; i--) {  // Начинаем с самых больших трёхзначных чисел
        for (int j = i; j >= 100; j--) { // Внутренний цикл также идёт вниз
            int number = i * j;

         
            if (isPalindrome(number) && number > largestPalindrome) {     // Проверяем, является ли произведение палиндромом
                largestPalindrome = number;
                multiplicand = i;
                multiplier = j;
            }
        }
    }

    
    cout << "The largest palindrome is: " << largestPalindrome << " (from " << multiplicand << " * " << multiplier << ")" << endl; // Выводим результат

    return 0;
}
