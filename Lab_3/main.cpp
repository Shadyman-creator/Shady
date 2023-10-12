#include <iostream>
#include "FixedCapacityStack.h"

int main() {
    FixedCapacityStack<int> mystack(5);
    for (int i = 1; i <= 5; ++i) {
        mystack.push(i);
    }

    std::cout << mystack << std::endl;

    mystack.push(6);

    while (!mystack.empty()) {
        mystack.pop();
    }

    std::cout << mystack << std::endl;

    return 0;
}
