#include "usr/local/bin/node/27.移除元素.cpp"

#include <iostream>
#include <vector>

using namespace std;

int main () {
    vector<int> test = {0, 1, 2, 2, 3, 0, 4, 2};

    Solution TestSolution;
    TestSolution.removeElement(test, 2);

    for (auto i = test.begin(); i != test.end(); ++i) {
        std::cout << *i << ' ';
    }
}
