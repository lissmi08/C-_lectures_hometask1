#include <iomanip>
#include <iostream>
#include <limits>

bool EqualCommands(const char* first, const char* second) {
  int numm = 0;
  while (first[numm] != '\0' && second[numm] != '\0') {
    if (first[numm] != second[numm]) {
      return false;
    }
    numm++;
  }
  if (first[numm] == second[numm]) {
    return true;
  } else {
    return false;
  }
}

void Deposit(int& summ) {
  int k;
  std::cin >> k;
  if (k <= 0) {
    std::cout << "error" << "\n";
    return;
  }
  summ += k;
  return;
}

void Withdraw(int& summ) {
  int k;
  std::cin >> k;
  if (k <= 0 || k > summ) {
    std::cout << "error" << "\n";
    return;
  }
  summ -= k;
  return;
}

void Balance(int& summ) {
  std::cout << summ << "\n";
  return;
}

void Reset(int& summ) {
  summ = 0;
  return;
}

void Double(int& summ) {
  summ *= 2;
  return;
}

int main() {
  int summ = 0;
  const char command[][9]{
      "deposit", "withdraw", "balance", "reset", "double",
  };
  const char stop[5]{"stop"};

  void (*opperation[])(int&){
      &Deposit, &Withdraw, &Balance, &Reset, &Double,
  };
  while (true) {
    const int command_count = sizeof(command) / sizeof(command[0]);
    char cmd[20];
    std::cin >> std::setw(20) >> cmd;
    if (EqualCommands(stop, cmd)) {
      return 0;
    }
    bool found = false;
    for (int i = 0; i < command_count; i++) {
      if (EqualCommands(command[i], cmd)) {
        opperation[i](summ);
        found = true;
        break;
      }
    }
    if (!found) {
      std::cout << "error" << "\n";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}