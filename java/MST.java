import java.util.*;
import java.util.stream.Collectors;

public class MST {
  public static void main(String[] args) {
    int n = 9;
    int[][] edges = {
        {0, 1, 4},
        {0, 7, 8},
        {1, 7, 11},
        {1, 2, 8},
        {7, 8, 7},
        {8, 6, 6},
        {7, 6, 1},
        {8, 2, 2},
        {2, 5, 4},
        {2, 3, 7},
        {5, 6, 2},
        {3, 5, 14},
        {3, 4, 9},
        {4, 5, 10}};
    // List<int[]> result = MST.findMstByPrim(n, edges);
    List<int[]> result = MST.findMstByKruskal(n, edges);
    System.out.println(result.stream().map(Arrays::toString).collect(Collectors.toList()));
  }
  /**
   * Prim's algorithm uses a heap to store all remaining vertices and grow a single tree.
   * 
   * Time complexity: O(|E|log|V|)
   *
   * @param n total number of vertices, from 0 to n-1
   * @param edges an array of [from, to, weight]
   * @return minimal set of edges [from, to] containing all vertices
   */
   private static List<int[]> findMstByPrim(int n, int[][] edges) {
    Map<Integer, Map<Integer, Integer>> neighbors = new HashMap<>();
    for (int[] e: edges) {
      neighbors.putIfAbsent(e[0], new HashMap<>());
      neighbors.putIfAbsent(e[1], new HashMap<>());
      neighbors.get(e[0]).put(e[1], e[2]);
      neighbors.get(e[1]).put(e[0], e[2]);
    }
    int[] costs = new int[n];
    Arrays.fill(costs, Integer.MAX_VALUE);
    costs[0] = 0;
    int[] parents = new int[n];
    Arrays.fill(parents, -1);
    boolean[] visited = new boolean[n];

    // TreeSet is different from PQ, in order to store duplicated element, we should also compare itself.
    TreeSet<Integer> pq = new TreeSet<>(Comparator.<Integer>comparingInt(id -> costs[id]).thenComparingInt(id->id));
    for (int i = 0; i < n; i++) pq.add(i);

    List<int[]> result = new ArrayList<>();
    while (!pq.isEmpty()) {
      int v = pq.pollFirst();
      visited[v] = true;
      result.add(new int[]{parents[v], v});
      for (int child : neighbors.get(v).keySet()) {
        if (!visited[child] && costs[child] > neighbors.get(v).get(child)) {
          // We should remove first then update the costs, otherwise remove's behavior is not what you want.
          pq.remove(child);
          costs[child] = neighbors.get(v).get(child);
          parents[child] = v;
          pq.add(child);
        }
      }
    }

    return result;
  }

  /**
   * Kruskal's algorithm to grow MST by a union set algorithm
   * 
   * Time complexity: O(|E|log|V|)
   */
  private static List<int[]> findMstByKruskal(int n, int[][] edeges) {
     List<int[]> result = new ArrayList<>();
     int[] fathers = new int[n];
     for (int i = 0; i < n; i++) fathers[i] = i;
     Arrays.sort(edeges, Comparator.comparingInt(e -> e[2]));
     for (int[] e : edeges) {
       union(result, fathers, e[0], e[1]);
     }
     return result;
  }

  private static int find(int[] fathers, int i) {
     if (fathers[i] != i) {
       fathers[i] = find(fathers, fathers[i]);
     }
     return fathers[i];
  }

  private static void union(List<int[]> mstSet, int[] fathers, int i, int j){
     int fi = find(fathers, i), fj = find(fathers, j);
     if (fi != fj) {
       mstSet.add(new int[]{i, j});
       fathers[fi] = fj;
     }
  }
}
