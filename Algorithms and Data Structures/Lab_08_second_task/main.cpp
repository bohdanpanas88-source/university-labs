#include <iostream>

void decToBin(int n) {
    if (n == 0) {
        return;
    }

    decToBin(n / 2);

    std::cout << n % 2;
}

int main() {
    int number;

    std::cout << "Enter decimal number: ";
    std::cin >> number;

    if (number == 0) {
        std::cout << "Binary number: 0" << "\n";
    }
    else {
        std::cout << "Binary number: ";
        decToBin(number);
        std::cout << "\n";
    }

    return 0;
}
