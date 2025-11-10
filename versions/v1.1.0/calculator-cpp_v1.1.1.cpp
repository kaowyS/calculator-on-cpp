#include <iostream>
#include <cmath>
#include <limits>
#include <stdlib.h>
using namespace std;

// Данная функция проверяет, является ли введенное значение числом
int isIntOrNot (long long num) {
    if (cin.fail()){
        cout << "Ошибка: введен нечисловой символ!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return 0;
    }

    if (num != static_cast<long long>(num)) {
        cout << "Ошибка: введено нецелое число!\n";
        return 1;
    }
    return static_cast<long long>(num);
}

//Выбор действия с числами
double selectActionWithNumbers (char action, double firstNum, double secondNum) {
    if (action != '+' && action != '-' && action != '*' && action != '/') {
        cout << endl;
        cout << "Неверное действие! Разрешены только +, -, *, /" << endl;
        return 0;
    }

    switch (action) {
        case '+': return firstNum + secondNum;
        case '-': return firstNum - secondNum;
        case '/':
            if (secondNum == 0) {
                cout << "На 0 делить нельзя!";
            } return firstNum / secondNum;
        case '*': return firstNum * secondNum;
    }
    return 0;
}

//Функция выбора действия работы программы
int selectStartAcion (int temp){
    if (cin.fail()) {
        cout << "Ошибка: введён нечисловой символ!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return 0;
    }

    // Проверка, что число целое
    if (temp != static_cast<int>(temp)) {
        cout << "Ошибка: введено нецелое число!\n";
        return 0;
    }
    return static_cast<int>(temp);
}

// Главная функция
int main() {
    int programAction, temp;
    char action;
    long long firstNum, secondNum, result, lastAnswer = 0;

    cout << endl;
    cout << "Это простой консольный калькулятор на языке C++" << endl;

    // Запрос действия от пользователя
    cout << "Выберите действие: 1,2 - Калькулятор, 3 - выход.\n";
    cout << "Действие: ";

    cin >> programAction;
    programAction = selectStartAcion(programAction);

    // Чтобы избежать конфликта с работой с последним ответом
    if (programAction == 2){
        programAction = 1;
    }

    if (programAction == 3) {
        cout << "Спасибо что воспользовались моей программой. Пока!";
        return 0;
    }

    do {
        if (programAction > 3 || programAction < 1) {
            cout << "Неверно выбрано действие, повторите выбор (1 - начать заново, 2 - продолжить, 3 - выход из программы)." << endl;
            cout << "Действие: ";
            cin >> programAction;
            programAction = selectStartAcion(programAction);
            continue;
        }

    if (programAction == 1) {
        cout << "Введите первое число: ";
        cin >> firstNum;
        while (!isIntOrNot(firstNum)) {
            cout << "Введите первое число: ";
            cin >> firstNum;
        }

        cout << "Введите второе число: ";
        cin >> secondNum;
        while (!isIntOrNot(secondNum)) {
            cout << "Введите второе число: ";
            cin >> secondNum;
        }

        cout << "Выберите действие (+, -, *, /): ";
        cin >> action;

        result = selectActionWithNumbers(action, firstNum, secondNum);
        cout << "Результат: " << result << endl;
        lastAnswer = result;

    } else if (programAction == 2) {
        cout << "Введите число: ";
        cin >> secondNum;
        while (!isIntOrNot(secondNum)) {
            cout << "Введите число: ";
            cin >> secondNum;
        }

        cout << "Выберите действие: ";
        cin >> action;

        firstNum = lastAnswer; // Используем последний ответ в качестве первого числа
        result = selectActionWithNumbers(action, firstNum, secondNum);

        lastAnswer = result;
        cout << "Результат: " << result << endl;
    }

        cout << "Хотите ли вы продолжить работу с данным ответом?\n";
        cout << endl;
        cout << "1 - начать заново, 2 - продолжить, 3 - выход из программы. \n";        
        cout << "Действие: ";
        cin >> programAction;
        programAction = selectStartAcion(programAction); // Повторная проверка действия с программой

    } while (programAction != 3); // Пока не выбрано действие "выход"

    cout << "Спасибо что воспользовались моей программой. Пока! \n" << endl;
    return 0;
}