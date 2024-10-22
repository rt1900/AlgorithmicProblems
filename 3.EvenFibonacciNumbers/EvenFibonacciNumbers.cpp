#include <iostream>
using namespace std;

int main(){

int firstNumber = 1;
int secondNumber = 2; 
int nextNumber = firstNumber + secondNumber;
int sumFibonacci = 0;

while(secondNumber <= 4000000){

        if(secondNumber % 2 == 0) {
            sumFibonacci += secondNumber;
        }
    firstNumber = secondNumber;
    secondNumber = nextNumber; 
    nextNumber = firstNumber + secondNumber;

}
cout<<"The last element in the Fibonacci sequence is:\n "<<firstNumber<<endl;
cout<<"The sum of all even numbers in the Fibonacci sequence whose values do not exceed four million\n"<<sumFibonacci<<endl; 
    return 0;
}