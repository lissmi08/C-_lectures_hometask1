#include <iomanip>
#include <iostream>

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

bool Inside(int x, int y) {
  return x >= 0 && x < 10 && y >= 0 && y < 5;
}


void Clear(char tablo[][10]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            tablo[i][j] = ' ';
        }
    }
    return;
}

bool Put(int x, int y, char c, char tablo[][10]) {
    if (Inside(x, y)) {
        tablo[y][x] = c;
        return true;
    } else {
        return false;
    }
}

bool Text(int x, int y, const char word[], char tablo[][10]) {
    int length = 0;
    while (word[length] != '\0') {
        length++;
    }
    if (Inside(x, y) && Inside(x + length - 1, y)) {
        int numm = 0; 
        while (word[numm] != '\0') {
            tablo[y][x + numm] = word[numm];
            numm++;
        }
        return true;
    } else {
        return false;
    }
}

void Print(const char tablo[][10]) {
    for (int i  = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << tablo[i][j];
        }
        std::cout << "\n";
    }
}


int main() {
    char tablo[5][10]{};
    Clear(tablo);
    while(true) {
        char cmd[20];
        std::cin >> std::setw(20) >> cmd;
        if (EqualCommands(cmd, "quit")) {
            return 0;
        }
        if (EqualCommands(cmd, "clear")) {
            Clear(tablo);
            continue;
        }
        if (EqualCommands(cmd, "put")) {
            int x, y;
            char c;
            std::cin >> x >> y >> c;
            if (!Put(x, y, c, tablo)){ 
                std::cout << "error" << "\n";
            }
            continue;
        }

        if (EqualCommands(cmd, "text")) {
            int x, y;
            char word[20];
            std::cin >> x >> y >> std::setw(20) >> word;
            if (!Text(x, y, word, tablo)) {
                std::cout << "error" << "\n";
            }
            continue;
        }

        if (EqualCommands(cmd, "print")) {
            Print(tablo);
        }
    }

}