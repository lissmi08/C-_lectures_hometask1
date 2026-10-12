#include <algorithm>
#include <iomanip>
#include <iostream>

double sred_tempreture(const int n, const int* tempreture) {
  double ans = 0;
  for (int i = 0; i < n; i++) {
    ans += tempreture[i];
  }
  ans /= n;
  return ans;
}

int* min_and_max(const int n, const int* tempreture) {
  int mn = tempreture[0];
  int mx = tempreture[0];
  for (int i = 0; i < n; i++) {
    mn = std::min(mn, tempreture[i]);
    mx = std::max(mx, tempreture[i]);
  }
  int* ans = new int[2]{mn, mx};
  return ans;
}

int zero(const int n, const int* tempereture) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (tempereture[i] < 0) {
      cnt++;
    }
  }
  return cnt;
}
int main() {
  int n;
  std::cin >> n;
  int* tempreture = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> tempreture[i];
  }
  std::cout << std::fixed << std::setprecision(1)
            << sred_tempreture(n, tempreture) << std::endl;

  int* ans = min_and_max(n, tempreture);
  std::cout << ans[0] << " " << ans[1] << std::endl;
  std::cout << zero(n, tempreture) << std::endl;
  delete[] ans;
  delete[] tempreture;
}
