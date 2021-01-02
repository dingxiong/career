import java.util.*;

/**
* leetcode 947
*/
class UnionFind {
  private int numOfUnions;
  private Map<String, String> fathers;

  public static void main(String[] args) {
  	UnionFind unionFind = new UnionFind();
  	System.out.println(unionFind.removeStones(new int[][] {{0,0},{0,2},{1,1},{2,0}, {2,2}}));
	}
  
  public int removeStones(int[][] stones) {
      int n = stones.length;
      fathers = new HashMap<>();
      numOfUnions = n;

      for (int[] stone: stones) {
          String reprentation = getStr(stone);
          fathers.put(reprentation, reprentation);
      }
      
      for (int i = 0; i < n; i++) {
          int[] current = stones[i];
          for (int j = i + 1; j < n; j++) {
              if (current[0] == stones[j][0] || current[1] == stones[j][1]) {
                  union(getStr(current), getStr(stones[j]));
              }
          }
      }
      return n - numOfUnions;
  }
  
  public void union(String a, String b) {
      String fatherOfA = find(a);
      String fatherOfB = find(b);
      if (!fatherOfA.equals(fatherOfB)) {
          fathers.put(fatherOfA, fatherOfB);
          numOfUnions--;
      }
  }
  
  private String find(final String rep) {
      if (!fathers.get(rep).equals(rep)) {
          fathers.put(rep, find(fathers.get(rep)));
      }
      return fathers.get(rep);
  }
  
  private String getStr(int[] pos) {
      return pos[0] + ":" + pos[1];
  }
}