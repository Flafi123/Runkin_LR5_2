#ifndef _RUNKIN_MATHTASK_H_
#define _RUNKIN_MATHTASK_H_
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// проверка корректности вводимых данных
bool UserInput(string input) {
  // если строка пустая - ввод некорректен
  if (input.empty())
    return false;
  // попытаться
  try {
    // преобразование введенного значения в тип int
    int number = stoi(input);
    // если введенное значение отрицательное - ввод некорректен
    if (number < 1)
      return false;
  } catch (...) // если возникла ошибка в блоке try
  {
    return false;
  }
  return true;
}

// вычисление площади прямоугольника
int CalcRectangleArea(int NumberA, int NumberB) {
  return NumberA * NumberB + 10;
}
#endif