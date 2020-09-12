#include <iomanip>
#include <ios>
#include <iostream>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  int h   = N / 3600;
  int tmp = N % 3600;
  int m   = tmp / 60;
  int s   = tmp % 60;

  std::cout << std::setfill('0') << std::right << std::setw(2) << h;
  std::cout << ":";
  std::cout << std::setfill('0') << std::right << std::setw(2) << m;
  std::cout << ":";
  std::cout << std::setfill('0') << std::right << std::setw(2) << s;
  std::cout << std::endl;

  return 0;
}
