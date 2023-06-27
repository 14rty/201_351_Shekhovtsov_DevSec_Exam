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
            login += (char)(rand() % 26 + 'a'); //добавляем случайные символы к строке
            password += (char)(rand() % 26 + 'a');
        }
        userAccounts.push_back(std::make_pair(login, password));
    }
}


int main() {
    setlocale(LC_ALL, "Russian");


    const std::string correctPinCode = "1234";


    std::string pinCode;
    std::cout << "Введите пик-код: ";
    
    char cha;
    while ((cha = _getch()) != '\r') { // Считываем ввод из консоли без знаков
        if (cha == '\b') { // Обработка Backspace
            if (pinCode.size() > 0) {
                pinCode.erase(pinCode.size() - 1);
                std::cout << "\b \b"; // Удаляем последней символ из консоли
            }
        }
        else {
            pinCode += cha;
            std::cout << "*";
        }
    }


    if (pinCode == correctPinCode) {
        srand(time(0)); // генератор псевдослучайных чисел
        generateRandomAccounts(5); // создаем аккаунты
        std::cout << std::endl;
        std::cout << "Успех!" << std::endl;

        int accountNumber;
        while (true) {
            std::cout << "Введите номер аккаунта (или -1 для выхода): ";
            std::cin >> accountNumber;

            if (accountNumber == -1) {
                std::cout << "Выход..." << std::endl;
                break;
            }

            if (accountNumber < 0 || accountNumber >= userAccounts.size()) {
                std::cout << "Аккаунт не найден!" << std::endl;
            }
            else {
                std::cout << "Login: " << userAccounts[accountNumber].first << std::endl;
                std::cout << "Password: " << userAccounts[accountNumber].second << std::endl;
            }
        }
    }
    else {
        std::cout << std::endl;
        std::cout << "Неверный пин-код! Выход..." << std::endl;
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
