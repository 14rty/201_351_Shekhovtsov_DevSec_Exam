// 201_351_Shekhovtsov.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>

std::vector<std::pair<std::string, std::string>> userAccounts;

void generateRandomAccounts(int numAccounts) {
    for (int i = 0; i < numAccounts; i++) {
        std::string login, password;
        int length = rand() % 5 + 4; // случайная длина строки от 4 до 8 символов
        for (int j = 0; j < length; j++) {
            login += (char)(rand() % 26 + 'a'); //добавление случайного символа к строке
            password += (char)(rand() % 26 + 'a');
        }
        userAccounts.push_back(std::make_pair(login, password));
    }
}


int main() {
    srand(time(0)); // инициализация генератора псевдослучайных чисел

    const std::string correctPinCode = "1234"; //пин-код задается константой в исходном коде
    generateRandomAccounts(5); // генерация набора пользовательских записей

    std::string pinCode;
    std::cout << "Please enter your pin code: ";
//    std::cin >> pinCode;

    while ((pinCode = getch()) != '\n') {   // '\n' - код перевода строки
        std::cout << '*';                  // отображение * вместо введенных символов
    }
    std::cout << "\n";

    if (pinCode == correctPinCode) {
        std::cout << "Welcome!" << std::endl;

        int accountNumber;
        while (true) {
            std::cout << "Please enter your account number (or -1 to exit): ";
            std::cin >> accountNumber;

            if (accountNumber == -1) {
                std::cout << "Exiting the application..." << std::endl;
                break;
            }

            if (accountNumber < 0 || accountNumber >= userAccounts.size()) {
                std::cout << "Account not found!" << std::endl;
            }
            else {
                std::cout << "Login: " << userAccounts[accountNumber].first << std::endl;
                std::cout << "Password: " << userAccounts[accountNumber].second << std::endl;
            }
        }
    }
    else {
        std::cout << "Incorrect pin code! Exiting the application..." << std::endl;
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
