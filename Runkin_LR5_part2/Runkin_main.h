#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValidNumber(const std::string &input);
void EnterNumber(int &varLink, const std::string &label);
int calculateRemainder(int Q, int P);
int calculateQuotient(int Q, int P);

int calculateQuotient(int Q, int P) {

  int quotient = Q / P;
  return quotient;
}

int calculateRemainder(int Q, int P) {

  int remainder = Q % P;
  return remainder;
}

bool UserInput(const std::string &input) {
  // Если строка пустая - ввод некорректен
  if (input.empty())
    return false;

  // Проверяем, состоит ли строка только из цифр
  for (char c : input) {
    if (!isdigit(c)) {
      return false; // Если есть хотя бы один нецифровой символ, возвращаем
                    // false
    }
  }

  // Попытаться преобразовать введенное значение в тип int
  try {
    int number = stoi(input);
    // Если введенное значение отрицательное - ввод некорректен
    if (number < 1)
      return false;
  } catch (...) { // Если возникла ошибка в блоке try
    return false;
  }

  return true; // Если все проверки пройдены, возвращаем true
}
#endif // CALCULATOR_H