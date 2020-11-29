#include <vector>
#include <iostream>
#include <list>

using namespace std;

class Solution {
public:

void test() {
    std::list<int> x = {1, 2, 3, 4, 5};
    auto iter = x.begin();
    std::cout << *iter << std::endl;
    iter++;
}
    
};

int main(int argc, char* argv[]) {
    Solution solution;
    solution.test();
    return 0;
}