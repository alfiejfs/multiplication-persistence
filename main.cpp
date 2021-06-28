#include <iostream>
#include <vector>
#include <cmath>

u_long persistence(u_long number, int count) {
  u_long result = 1;

  int iters = (int) log10(number) + 1;
  if (iters == 1) {
    return count;
  }

  for (int i = 0; i < iters; i++) {
    u_long digit = number % 10;

    if (digit == 0) {
      return count + 1;
    }

    if (count == 0 && i < iters - 2) {
      if (digit != 7 && digit != 8 && digit != 9) {
        return 0;
      }
    }

    result *= digit;
    number /= 10;
  }

  return persistence(result, count + 1);
}

int main() {

  u_long record = 0;
  u_long number = 1;

  while (true) {
    int amount = persistence(number, 0);
    if (amount > record) {
      record = amount;
      std::cout << "New record: " << record << std::endl << "Value: " << number
                << std::endl;
    }

    number++;
  }

    return 0;
}
