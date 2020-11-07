#include <iostream>
#include <vector>

using namespace std;

/*
 * Average complexity O(N), worse complexity O(N^2).
 * C++ has std::nth_element()
 */
class QuickSelect {
public:
  void kthElement(vector<int> &nums, int k) {
    if (k >= nums.size() || nums.size() == 0)
      return;
    select(nums, 0, nums.size() - 1, k);
  }

  void select(vector<int> &nums, int start, int end, int k) {
    if (start == end)
      return;
    int p = partition(nums, start, end, start);
    if (p > k)
      select(nums, start, p - 1, k);
    else if (p < k)
      select(nums, p + 1, end, k);
  }

  /**
   * group a list into two parts: those less than a certain element, and those
   * greater than or equal to the element.
   */
  int partition(vector<int> &nums, int start, int end, int pivot) {
    int pV = nums[pivot];
    int smallIndex = start;
    swap(nums[end], nums[pivot]);
    for (int i = start; i < end; i++)
      if (nums[i] < pV)
        swap(nums[i], nums[smallIndex++]);
    swap(nums[end], nums[smallIndex]);
    return smallIndex;
  }
};

int main() {
  vector<int> nums = {5, 8, 3, 6, 1, 2};
  QuickSelect qs;
  qs.kthElement(nums, 0);
  for (int i : nums)
    cout << i << ' ';
  cout << endl;
  return 0;
}
