#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

//Выбор действия с числами
double selectActionWithNumbers (char action, double a, double b) {
    switch (action) {
        case '+': return a + b;
        case '-': return a - b;
        case '/':  
            if (b == 0) {
                cout << "На 0 делить нельзя!";
            } return a / b;
        case '*': return a * b;
        
        default:
        cout << "Неверное действие" << endl;
        return 0;
    }
}

//Функция выбора действия работы программы
int selectStartAcion (int temp){
    if (cin.fail()) {
        cout << "Ошибка: введён нечисловой символ!\n";
        cin.clear();
        return 0;
    }

    // Проверка, что число целое
    if (temp != static_cast<int>(temp)) {
        cout << "Ошибка: введено нецелое число!\n";
        return 0;
    }
    return static_cast<int>(temp);
}

int main() {
    int p, k;
    char action;
    double a, b, result, lastAnswer = 0, temp;

    // Запрос действия от пользователя
    cout << "Выберите действие: 1,2 - Калькулятор, 3 - выход.\n";
    cout << "Действие: ";

    cin >> temp;
    p = selectStartAcion(temp);
    
    // Чтобы избежать конфликта с работой с последним ответом
    if (p == 2){
        p = 1;
    }
    if (p == 3 || p == char()) {
        cout << "Спасибо что воспользовались моей программой. Пока!";
        return 0;
    }

    do {
        if (p > 3) {
            cout << "Неверно выбрано действие, повторите выбор.";
            cin >> p;
        }
    
    if (p == 1) {
        cout << "Введите первое число: ";
        cin >> a;
        cout << "Введите второе число: ";
        cin >> b;
        cout << "Выберите действие (+, -, *, /): ";
        cin >> action;

       result = selectActionWithNumbers(action,a,b);
       cout << "Результат: " << result << endl;
       lastAnswer = result;
    } 
    else if (p == 2) {
        cout << "Введите число: ";
        cin >> b;
        cout << "Выберите действие: ";
        cin >> action;

        a = lastAnswer;
        result = selectActionWithNumbers(action,a,b);

        lastAnswer = result;
        cout << "Результат: " << result << endl; 
    }

        cout << "Хотите ли вы продолжить работу с данным ответом?\n";
        cout << "1 - начать заново, 2 - продолжить, 3 - выход из программы. \n";
        cout << "Действие: ";
        cin >> p;

    } while (p != 3);

    cout << "Спасибо что воспользовались моей программой. Пока!";
    return 0;
}