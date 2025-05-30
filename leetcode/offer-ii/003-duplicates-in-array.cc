#include <iostream>

bool duplicate(int numbers[], int n, int& duplicatation) {
    if (numbers == nullptr || n <= 0) {
        return false;
    }

    for (int i = 0; i < n; ++i) {
        int num = numbers[i];
        if (num < 0 || num > n - 1) {
            return false;
        }
    }

    for (int i = 0; i < n; ++i) {
        while (numbers[i] != i) {
            if (numbers[i] == numbers[numbers[i]]) {
                duplicatation = numbers[i];
                return true;
            }

            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }

    return false;
}

int main() {
    int numbers[] = { 2, 3, 1, 0, 2, 5, 3 };

    int duplicatation = -1;
    if (duplicate(numbers, sizeof(numbers) / sizeof(int), duplicatation)) {
        std::cout << "duplication is: " << duplicatation << std::endl;
    }
}
