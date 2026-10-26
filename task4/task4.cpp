#include <iostream>

int main() {

//Наша задача в том, что мы хотим хранить трехмерный массив данных, для этого используем int***
//Элементы таблицы это квартиры, и про каждую есть инфомрация, которую передают разные типы данных
//Для записи их в таблицу используем *void, чтобы на вводе не заморачиваться с типами данных,
//а уже при обращении разыименовываем под каждый тип, так как нам надо.
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