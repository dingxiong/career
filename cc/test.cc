#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        int idx = getMedian(arr, 0, n-1, (n-1)/2);
        std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, ","));
        std::cout << std::endl;
        std::cout << idx << ", " << arr[idx] << std::endl;
        select(arr, 0, n-1, k, arr[idx], idx);
        vector<int> result(k);
        std::copy_n(arr.begin(), k, result.begin());
        return result;
    }
    
    int getMedian(vector<int>& arr, int from, int to, int k) {
        int i = from, j = to -1;
        int pivot = arr.at(to);
        while (i <= j) {
            if (arr[i] < pivot) i++;
            else {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                j--;
            }
        }
        int tmp = arr[i];
        arr[i] = arr.at(to);
        arr[to] = tmp;
        int len = i - from;
        if (len > k) return getMedian(arr, from, i-1, k);
        else if (len == k) return i;
        else return getMedian(arr, i+1, to, k - len - 1);
    }
    
    void select(vector<int>& arr, int from, int to, int k, int median, int midx) {
        int i = from, j = to - 1;
        int pivot = std::abs(arr.at(to) - median);
        while (i <= j) {
            int diff = std::abs(arr[i] - median);
            if (diff > pivot or (diff == pivot && arr[i] > arr.at(to))) i++;
            else {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                j--;
            }
        }
        int tmp = arr[i];
        arr[i] = arr.at(to);
        arr[to] = tmp;
        // std::cout << from << "," << to << "," << k << "," << median << std::endl;
        // std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, ","));
        // std::cout << std::endl;
        int len = i - from + 1;
        if (len > k) select(arr, from, i-1, k, median, midx);
        else if (len == k or len == k + 1) return;
        else select(arr, i+1, to, k - len, median, midx);
    }
    
};

int main(int argc, char* argv[]) {
    std::vector<int> arr = 
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
    int k = 76603;
    Solution solution;
    auto v = solution.getStrongest(arr, k);
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ","));
    return 0;
}