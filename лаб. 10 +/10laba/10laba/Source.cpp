#include <iostream>

int S(int x) {
    if (x > 100) {
        return x + 10;
    }
    else {
        return S(x + 4);
    }
}

int main() {
    int x;
    std::cout << "VVEDITE x: ";
    std::cin >> x;
    std::cout << "S(x) = " << S(x) << std::endl;
    return 0;
}
