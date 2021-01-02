import java.util.Arrays;

public class RainbowSort {
  public static void main(String[] args) {
    RainbowSort rs = new RainbowSort();
    int[] nums = {3, 2, 1, 1, 2, 2, 3, 1};
    rs.sort(nums, 3);
    System.out.println(Arrays.toString(nums));
  }

  /**
   * Given a list whose members are numbers range from 1 to k. How to sort this list without
   * counting them
   *
   * Time complexity: O(n*logk)
   */
  private void sort(int[] nums, int k) {
    helper(nums, 0, nums.length-1, 1, k);
  }

  private void helper(int[] nums, int from, int to, int colorFrom, int colorTo) {
    if (from >= to || colorFrom >= colorTo) return;

    int l = from, r = to;
    int colorMid = (colorFrom + colorTo) / 2;
    while (l < r) {
      if (nums[l] <= colorMid) l++;
      else if (nums[r] > colorMid) r--;
      else swap(nums, l++, r--);
    }

    helper(nums, from, l-1, colorFrom, colorMid);
    helper(nums, r+1, to, colorMid+1, colorTo);
  }

  private void swap(int[] nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
  }
}
