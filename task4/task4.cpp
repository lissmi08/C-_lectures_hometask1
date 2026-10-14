#include <iostream>

int main() {
  // int*** хранит жильцов: подъезд -> этаж -> квартира.
  // void* объединяет адреса полей разных типов в одной таблице.
  // Новые поля карточки добавляются в таблицу без изменения
  // цикла печати. Поддерживаются int и double.
// Для выбранной квартиры создаём карточку с адресами разных данных:
// количество жильцов — int, площадь — double, квартплата — int.
// void* хранит адреса, а массив types отдельно описывает их типы.
// Общий цикл печатает поля карточки, восстанавливая нужный тип указателя.
  int*** residents = new int**[2];

  for (int i = 0; i < 2; i++) {
    residents[i] = new int*[3];

    for (int j = 0; j < 3; j++) {
      residents[i][j] = new int[4]{};
    }
  }

  residents[0][1][2] = 3;
  double area = 42.5;
  int payment = 3500;

  void* data[] = {
      &residents[0][1][2],
      &area,
      &payment
  };

  const char types[] = {'i', 'd', 'i'};

  const char names[][20] = {
      "Residents",
      "Area",
      "Payment"
  };

  const int count = sizeof(data) / sizeof(data[0]);

  for (int i = 0; i < count; i++) {
    std::cout << names[i] << ": ";

    if (types[i] == 'i') {
      int* value = static_cast<int*>(data[i]);
      std::cout << *value;
    } else if (types[i] == 'd') {
      double* value = static_cast<double*>(data[i]);
      std::cout << *value;
    }

    std::cout << '\n';
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      delete[] residents[i][j];
    }

    delete[] residents[i];
  }
  delete[] residents;

  return 0;
}