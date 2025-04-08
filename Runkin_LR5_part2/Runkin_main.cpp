#include <functional>
#include <iostream>
#include <map>
#include <string>

using namespace std;

// Функция для ввода числа
// глобальные переменные - стороны прямоугольника
int Q, P;
// функция ввода данных
bool isValidNumber(const string &input) {
  if (input.empty())
    return false; // Пустая строка не является корректным числом
  for (char c : input) {
    if (!isdigit(c))
      return false; // Разрешаем только положительные числа
  }
  return true;
}

// Функция для ввода числа
void EnterNumber(int &varLink, const string &label) {
  string raw_input;
  cout << label;
  getline(cin, raw_input);

  // Цикл для повторного запроса числа, пока не будет введено корректное
  // значение
  while (!isValidNumber(raw_input)) {
    cout << "Invalid input. " << label;
    getline(cin, raw_input);
  }

  varLink = stoi(raw_input); // Преобразуем строку в целое число
}
// Функция для ввода числа
// глобальные переменные - стороны прямоугольника

void calculateRemainder() {
  if (P > 0) {
    int remainder = Q % P;
    cout << "Remainder of Q divided by P: " << remainder << endl;
  } else {
    cout << "Error: P should be greater than 0.\n";
  }
}
void inputP() {
  do {
    EnterNumber(P, "Enter natural number P (less than Q): ");
    if (P <= 0 || P >= Q) {
      cout << "Error: P should be a natural number and less than Q.\n";
    }
  } while (P <= 0 || P >= Q);
}

void inputQ() {
  EnterNumber(Q, "Enter natural number Q: ");
  // ИЗМЕНЕНИЯ - Ветка branch_fun_2
}
void calculateQuotient() {
  if (P > 0) {
    int quotient = Q / P;
    cout << "Integer part of Q divided by P: " << quotient << endl;
  } else {
    cout << "Error: P should be greater than 0.\n";
  }
}
// структра меню
struct MenuItem {
  string title;
  function<void()> action;
};
string title;
int main() {
  map<int, MenuItem> menu = {
      {1, {"Enter integer Q", inputP}},
      {2, {"Enter natural number P (less than Q)", inputQ}},
      {3, {"Calculate remainder of Q divided by P", calculateRemainder}},
      {4, {"Calculate integer part of Q divided by P", calculateQuotient}},
  };
  int choice = 0;
  //
  while (true) {
    cout << "Menu: " << endl;
    for (const auto &item : menu) {
      cout << "Task " << item.first << ". " << item.second.title << endl;
    }
    cout << "0. Exit" << std::endl;
    cout << "Enter the number of the task: ";
    cin >> choice;
    //
    if (choice == 0) {
      cout << "  2025 FirstName LastName" << endl;
      break;
    }
    cout << endl;
    if (menu.find(choice) != menu.end()) {
      menu[choice].action();
    } else {
      cout << " .";
    }
    cout << endl;
  }
  return 0;
}