import java.util.HashMap;
import java.util.Map;

/**
 * Given a grid of 0s and 1s. try to find the islands of 1s.
 * derived from leetcode 827. Making A Large Island
 */
class UnionFind2 {
  Map<Integer, Integer> fathers;
  Map<Integer, Integer> sizes;
  int n;

  /***
   * Data structure could be used: Map or int[][] depending on the easiness
   */
  public void unionFind(int[][] grid) {
    n = grid.length;
    fathers = new HashMap<>();
    sizes = new HashMap<>();

    initilize(grid);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) { // only need to consider two directions
          if (i > 0 && grid[i-1][j] == 1) union(i, j, i-1, j);
          if (j > 0 && grid[i][j-1] == 1) union(i, j, i, j-1);
        }
      }
    }

    System.out.println(fathers);
    System.out.println(sizes);

  }

  /**
   * common mistakes:
   * 1. forget to initialize sizes
   */
  private void initilize(int[][] grid) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          int key = i * n + j;
          fathers.put(key, key);
          sizes.put(key, 1);
        }
      }
    }
  }


  /**
   * common mistakes:
   * 1. fathers.put(i1*n+j1, f2) => we should put (f1, f2)
   * 2. int f1 = fathers.get(i1*n+j1) => we should use find() because 
   *    fathers map may not be the ultimate representative of this set
   */
  private void union(int i1, int j1, int i2, int j2) {
    int f1 = find(i1, j1);
    int f2 = find(i2, j2);
    if (f1 != f2) {
      fathers.put(f1, f2);
      sizes.put(f2, sizes.get(f1) + sizes.get(f2));
    }
  }

  /**
   * just remember:
   * if current != current.father
   *    father.put(current, find(current.father))
   *
   * common mistakes:
   * 1. decode x, y coordinate f / n and f % n, not f % n and then f / n
   * 2. if not while
   */
  private int find(int i, int j) {
    int key = i*n + j;
    int f = fathers.get(key);
    if (f != key) {
      fathers.put(key, find(f / n, f % n));
    }
    return fathers.get(key);
  }
}
