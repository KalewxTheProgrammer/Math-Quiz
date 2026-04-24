#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>
#include <stdexcept>
// MathQuiz // This program generates two random numbers and asks the user to solve a simple math problem 
// (addition, subtraction, multiplication, or division). The user inputs their answer, and the program checks if it is correct.

// Function definitions
void generateQuestion(int& num1, int& num2, char& operation) {
    num1 = rand() % 100 + 1;
    num2 = rand() % 100 + 1;
    int op = rand() % 4;
    switch (op) {
        case 0: operation = '+'; break;
        case 1: operation = '-'; break;
        case 2: operation = '*'; break;
        case 3: operation = '/'; break;
    }
} 

bool checkAnswer(int num1, int num2, char operation, double userAnswer) {
    double correctAnswer;
    switch (operation) {
        case '+': correctAnswer = num1 + num2; break;
        case '-': correctAnswer = num1 - num2; break;
        case '*': correctAnswer = num1 * num2; break;
        case '/':
            if (num2 == 0) {
                std::cout << " Division by zero is not allowed!" << std::endl;
                return false;
            }
            correctAnswer = static_cast<double>(num1) / num2;
            break;
    }
    return userAnswer == correctAnswer;  


}

// Greet the user and explain the quiz
int main() {
    srand(time(0));

    std::cout << " Welcome to this simple math quiz?" << std::endl;
    std::cout << " If you can't solve any of these problems, then you should probably go back to school." << std::endl;

    int num1, num2;
    char operation;
    generateQuestion(num1, num2, operation);
    std::cout << " What is " << num1 << " " << operation << " " << num2 << "? ";
    double userAnswer;
    std::cin >> userAnswer; 

    if (checkAnswer(num1, num2, operation, userAnswer)) {
        std::cout << " Congratulations! You definitely know your math!" << std::endl;
    } else {
        std::cout << " Go back to school and learn your math!" << std::endl;
    }

    return 0; 
}