#include <iostream>
#include <string>
#include <clocale>

// Задание 1. Методы

double fraction(double x) {
  int integer_part = static_cast<int>(x);
  return x - integer_part;
}

int charToNum(char x) {
  return x - '0';
}

bool is2Digits(int x) {
  if (x < 0) {
    x = -x;
  }
  return x >= 10 && x <= 99;
}

bool isInRange(int a, int b, int num) {
  int left = a < b ? a : b;
  int right = a > b ? a : b;
  return num >= left && num <= right;
}

bool isEqual(int a, int b, int c) {
  return a == b && b == c;
}

// Задание 2. Условия

int abs(int x) {
  if (x < 0) {
    return -x;
  }
  return x;
}

bool is35(int x) {
  bool div3 = (x % 3 == 0);
  bool div5 = (x % 5 == 0);
  return (div3 || div5) && !(div3 && div5);
}

int max3(int x, int y, int z) {
  int result = x;
  if (y > result) {
    result = y;
  }
  if (z > result) {
    result = z;
  }
  return result;
}

int sum2(int x, int y) {
  int sum = x + y;
  if (sum >= 10 && sum <= 19) {
    return 20;
  }
  return sum;
}

std::string day(int x) {
  switch (x) {
    case 1: return "понедельник";
    case 2: return "вторник";
    case 3: return "среда";
    case 4: return "четверг";
    case 5: return "пятница";
    case 6: return "суббота";
    case 7: return "воскресенье";
    default: return "это не день недели";
  }
}

// Задание 3. Циклы

std::string listNums(int x) {
  std::string result;
  for (int i = 0; i <= x; ++i) {
    if (i > 0) {
      result += " ";
    }
    result += std::to_string(i);
  }
  return result;
}

std::string chet(int x) {
  std::string result;
  for (int i = 0; i <= x; i += 2) {
    if (i > 0) {
      result += " ";
    }
    result += std::to_string(i);
  }
  return result;
}

int numLen(long x) {
  if (x < 0) {
    x = -x;
  }
  if (x == 0) {
    return 1;
  }
  int count = 0;
  while (x > 0) {
    x /= 10;
    ++count;
  }
  return count;
}

void square(int x) {
  for (int row = 0; row < x; ++row) {
    for (int col = 0; col < x; ++col) {
      std::cout << '*';
    }
    std::cout << '\n';
  }
}

void rightTriangle(int x) {
  for (int row = 1; row <= x; ++row) {
    int spaces = x - row;
    for (int i = 0; i < spaces; ++i) {
      std::cout << ' ';
    }
    for (int i = 0; i < row; ++i) {
      std::cout << '*';
    }
    std::cout << '\n';
  }
}

// Задание 4. Массивы

int findFirst(const int arr[], int size, int x) {
  for (int i = 0; i < size; ++i) {
    if (arr[i] == x) {
      return i;
    }
  }
  return -1;
}

int maxAbs(const int arr[], int size) {
  int best = arr[0];
  for (int i = 1; i < size; ++i) {
    if (abs(arr[i]) > abs(best)) {
      best = arr[i];
    }
  }
  return best;
}

int* reverseBack(const int arr[], int size) {
  int* result = new int[size];
  for (int i = 0; i < size; ++i) {
    result[i] = arr[size - 1 - i];
  }
  return result;
}

int* findAll(const int arr[], int size, int x) {
  int count = 0;
  for (int i = 0; i < size; ++i) {
    if (arr[i] == x) {
      ++count;
    }
  }
  int* result = new int[count + 1];
  result[0] = count;
  int pos = 1;
  for (int i = 0; i < size; ++i) {
    if (arr[i] == x) {
      result[pos++] = i;
    }
  }
  return result;
}

int* add(const int arr[], int arr_size, const int ins[], int ins_size,
         int pos) {
  int result_size = arr_size + ins_size;
  int* result = new int[result_size + 1];
  result[0] = result_size;
  int k = 1;
  for (int i = 0; i < pos; ++i) {
    result[k++] = arr[i];
  }
  for (int i = 0; i < ins_size; ++i) {
    result[k++] = ins[i];
  }
  for (int i = pos; i < arr_size; ++i) {
    result[k++] = arr[i];
  }
  return result;
}

// Вспомогательные функции для ввода

void ClearInput() {
  std::cin.clear();
  std::cin.ignore(10000, '\n');
}

double ReadDouble(const char* prompt) {
  double value;
  while (true) {
    std::cout << prompt;
    if (std::cin >> value) {
      return value;
    }
    std::cout << "Ошибка: введите число.\n";
    ClearInput();
  }
}

int ReadInt(const char* prompt) {
  int value;
  while (true) {
    std::cout << prompt;
    if (std::cin >> value) {
      return value;
    }
    std::cout << "Ошибка: введите целое число.\n";
    ClearInput();
  }
}

long ReadLong(const char* prompt) {
  long value;
  while (true) {
    std::cout << prompt;
    if (std::cin >> value) {
      return value;
    }
    std::cout << "Ошибка: введите целое число.\n";
    ClearInput();
  }
}

char ReadDigit(const char* prompt) {
  char value;
  while (true) {
    std::cout << prompt;
    std::cin >> value;
    if (value >= '0' && value <= '9') {
      return value;
    }
    std::cout << "Ошибка: введите одну цифру (0-9).\n";
  }
}

void ReadArray(int arr[], int size) {
  std::cout << "Введите " << size << " элементов через пробел:\n";
  for (int i = 0; i < size; ++i) {
    arr[i] = ReadInt("  элемент: ");
  }
}

void PrintArray(const int arr[], int size) {
  std::cout << "[";
  for (int i = 0; i < size; ++i) {
    if (i > 0) {
      std::cout << ", ";
    }
    std::cout << arr[i];
  }
  std::cout << "]";
}

int main() {
  std::setlocale(LC_ALL, "Russian");

  while (true) {
    std::cout << "\n========================================\n";
    std::cout << "          Выбор задачи\n";
    std::cout << "========================================\n";
    std::cout << "Задание 1. Методы:\n";
    std::cout << "  1  - Дробная часть\n";
    std::cout << "  2  - Букву в число\n";
    std::cout << "  3  - Двузначное\n";
    std::cout << "  4  - Диапазон\n";
    std::cout << "  5  - Равенство\n";
    std::cout << "Задание 2. Условия:\n";
    std::cout << "  6  - Модуль числа\n";
    std::cout << "  7  - Тридцать пять\n";
    std::cout << "  8  - Тройной максимум\n";
    std::cout << "  9  - Двойная сумма\n";
    std::cout << "  10 - День недели\n";
    std::cout << "Задание 3. Циклы:\n";
    std::cout << "  11 - Числа подряд\n";
    std::cout << "  12 - Чётные числа\n";
    std::cout << "  13 - Длина числа\n";
    std::cout << "  14 - Квадрат\n";
    std::cout << "  15 - Правый треугольник\n";
    std::cout << "Задание 4. Массивы:\n";
    std::cout << "  16 - Поиск первого значения\n";
    std::cout << "  17 - Поиск максимального\n";
    std::cout << "  18 - Возвратный реверс\n";
    std::cout << "  19 - Все вхождения\n";
    std::cout << "  20 - Добавление массива в массив\n";
    std::cout << "----------------------------------------\n";
    std::cout << "  0  - Выход\n";
    std::cout << "========================================\n";

    int choice = ReadInt("Введите номер задачи (0 - выход): ");

    if (choice == 0) {
      std::cout << "Выход из программы.\n";
      break;
    }

    switch (choice) {
      case 1: {
        std::cout << "\n--- Задание 1.1. Дробная часть ---\n";
        double x = ReadDouble("Введите вещественное число x: ");
        std::cout << "Результат: " << fraction(x) << "\n";
        break;
      }
      case 2: {
        std::cout << "\n--- Задание 1.2. Букву в число ---\n";
        char c = ReadDigit("Введите цифру (0-9): ");
        std::cout << "Результат: " << charToNum(c) << "\n";
        break;
      }
      case 3: {
        std::cout << "\n--- Задание 1.3. Двузначное ---\n";
        int n = ReadInt("Введите число x: ");
        std::cout << "Результат: " << (is2Digits(n) ? "true" : "false")
                  << "\n";
        break;
      }
      case 4: {
        std::cout << "\n--- Задание 1.4. Диапазон ---\n";
        int a = ReadInt("Введите границу a: ");
        int b = ReadInt("Введите границу b: ");
        int num = ReadInt("Введите число num: ");
        std::cout << "Результат: " << (isInRange(a, b, num) ? "true" : "false")
                  << "\n";
        break;
      }
      case 5: {
        std::cout << "\n--- Задание 1.5. Равенство ---\n";
        int a = ReadInt("Введите a: ");
        int b = ReadInt("Введите b: ");
        int c = ReadInt("Введите c: ");
        std::cout << "Результат: " << (isEqual(a, b, c) ? "true" : "false")
                  << "\n";
        break;
      }
      case 6: {
        std::cout << "\n--- Задание 2.1. Модуль числа ---\n";
        int x = ReadInt("Введите x: ");
        std::cout << "Результат: " << abs(x) << "\n";
        break;
      }
      case 7: {
        std::cout << "\n--- Задание 2.2. Тридцать пять ---\n";
        int x = ReadInt("Введите x: ");
        std::cout << "Результат: " << (is35(x) ? "true" : "false") << "\n";
        break;
      }
      case 8: {
        std::cout << "\n--- Задание 2.3. Тройной максимум ---\n";
        int x = ReadInt("Введите x: ");
        int y = ReadInt("Введите y: ");
        int z = ReadInt("Введите z: ");
        std::cout << "Результат: " << max3(x, y, z) << "\n";
        break;
      }
      case 9: {
        std::cout << "\n--- Задание 2.4. Двойная сумма ---\n";
        int x = ReadInt("Введите x: ");
        int y = ReadInt("Введите y: ");
        std::cout << "Результат: " << sum2(x, y) << "\n";
        break;
      }
      case 10: {
        std::cout << "\n--- Задание 2.5. День недели ---\n";
        int d = ReadInt("Введите номер дня (1-7): ");
        std::cout << "Результат: " << day(d) << "\n";
        break;
      }
      case 11: {
        std::cout << "\n--- Задание 3.1. Числа подряд ---\n";
        int x = ReadInt("Введите x: ");
        std::cout << "Результат: " << listNums(x) << "\n";
        break;
      }
      case 12: {
        std::cout << "\n--- Задание 3.2. Чётные числа ---\n";
        int x = ReadInt("Введите x: ");
        std::cout << "Результат: " << chet(x) << "\n";
        break;
      }
      case 13: {
        std::cout << "\n--- Задание 3.3. Длина числа ---\n";
        long x = ReadLong("Введите x: ");
        std::cout << "Результат: " << numLen(x) << "\n";
        break;
      }
      case 14: {
        std::cout << "\n--- Задание 3.4. Квадрат ---\n";
        int x = ReadInt("Введите сторону x: ");
        std::cout << "Результат:\n";
        square(x);
        break;
      }
      case 15: {
        std::cout << "\n--- Задание 3.5. Правый треугольник ---\n";
        int x = ReadInt("Введите высоту x: ");
        std::cout << "Результат:\n";
        rightTriangle(x);
        break;
      }
      case 16: {
        std::cout << "\n--- Задание 4.1. Поиск первого значения ---\n";
        const int kSize = 7;
        int arr[kSize];
        ReadArray(arr, kSize);
        int target = ReadInt("Введите x для поиска: ");
        std::cout << "Результат: " << findFirst(arr, kSize, target) << "\n";
        break;
      }
      case 17: {
        std::cout << "\n--- Задание 4.2. Поиск максимального ---\n";
        const int kSize = 7;
        int arr[kSize];
        ReadArray(arr, kSize);
        std::cout << "Результат: " << maxAbs(arr, kSize) << "\n";
        break;
      }
      case 18: {
        std::cout << "\n--- Задание 4.3. Возвратный реверс ---\n";
        const int kSize = 5;
        int arr[kSize];
        ReadArray(arr, kSize);
        int* reversed = reverseBack(arr, kSize);
        std::cout << "Результат: ";
        PrintArray(reversed, kSize);
        std::cout << "\n";
        delete[] reversed;
        break;
      }
      case 19: {
        std::cout << "\n--- Задание 4.4. Все вхождения ---\n";
        const int kSize = 7;
        int arr[kSize];
        ReadArray(arr, kSize);
        int target = ReadInt("Введите x для поиска: ");
        int* found = findAll(arr, kSize, target);
        int count = found[0];
        std::cout << "Результат: [";
        for (int i = 1; i <= count; ++i) {
          if (i > 1) {
            std::cout << ", ";
          }
          std::cout << found[i];
        }
        std::cout << "]\n";
        delete[] found;
        break;
      }
      case 20: {
        std::cout << "\n--- Задание 4.5. Добавление массива в массив ---\n";
        const int kArrSize = 5;
        const int kInsSize = 3;
        int arr[kArrSize];
        int ins[kInsSize];

        std::cout << "Массив arr (5 элементов):\n";
        ReadArray(arr, kArrSize);

        std::cout << "Массив ins (3 элемента):\n";
        ReadArray(ins, kInsSize);

        int pos = ReadInt("Введите позицию вставки pos (0-5): ");
        while (pos < 0 || pos > kArrSize) {
          std::cout << "Ошибка: pos должен быть от 0 до " << kArrSize
                    << ".\n";
          pos = ReadInt("Введите позицию вставки pos (0-5): ");
        }

        int* result = add(arr, kArrSize, ins, kInsSize, pos);
        int result_size = result[0];
        std::cout << "Результат: ";
        PrintArray(result + 1, result_size);
        std::cout << "\n";
        delete[] result;
        break;
      }
      default:
        std::cout << "Неверный номер задачи.\n";
    }

    std::cout << "\nНажмите Enter, чтобы вернуться в меню...";
    std::cin.ignore(10000, '\n');
    std::cin.get();
  }

  std::cout << "\nВсе задания выполнены.\n";
  return 0;
}
