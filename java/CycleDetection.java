import java.util.Arrays;

public class CycleDetection {
  public static void main(String[] args) {
    CycleDetection cd = new CycleDetection();
    System.out.println(Arrays.toString(cd.detectUndirectedCycleByUnionFind(5, new int[][]{{1,2}, {2,3}, {3,4}, {1,4}, {1,5}})));
    System.out.println(Arrays.toString(cd.detectDirectedCycleByUnionFind(4, new int[][]{{2,1}, {3,1}, {4,2}, {1,4}})));
  }

  /**
   * cycle detection in undirected graph (LC 684)
   *
   * Given a set of nodes 1, 2, ..., n. and a set of edges, find the edge that creates a cycle.
   * There are multiple ways to do it.
   * 1. Union find
   * 2. BFS based topological sorting
   * 3. DFS based topological sorting
   *
   * I think Union Find is the easiest one.
   */
  public int[] detectUndirectedCycleByUnionFind(int n, int[][] edges) {
    int[] fathers = new int[n+1];
    for (int i = 0; i < n+1; i++) fathers[i] = i;

    for (int[] edge: edges) {
      int f1 = find(fathers, edge[0]);
      int f2 = find(fathers, edge[1]);
      if (f1 == f2) return edge;
      else {
        fathers[f1] = f2;
      }
    }
    return new int[]{};
  }

  /**
   * cycle detection in directed graph (LC 685)
   *
   * Given a set of nodes 1, 2, ..., n. and a set of edges, find the edge that creates a cycle.
   *
   * Imagine there is a valid tree or a forest. Now you add a edge (A, B) to it.
   * There are three cases
   * 1. B is the root node. Then this edge creates a cycle.
   * 2. B is a non-root node
   *    1) B is child of A, then we create a cycle and A has two parents now.
   *      Ex: 3->1->4->2, we add 2->1
   *    2) B is not a child of A, then A has two parents now.
   *      Ex: 3->1->4, 3->2, we add 4->2
   *
   * So case 1 and 2.1 create cycle. Case 2.1 and 2.2 create two parents.
   *
   * So our approach has two steps.
   * 1. Find a node which has two parents.
   *    1) If not found. then we are sure there is a cycle
   *    2) If found, denoted the two edges as cand1 and cand2 and we remove edge cand2.
   * 2. Perform a normal UF.
   *    1) If not cycle found, then return cand2.
   *    2) If a cycle found.
   *      a) If the two-parent node exists, return cand1
   *      b) otherwise, we know that we are done if we just break this cycle, So return the current edge.
   */
  public  int[] detectDirectedCycleByUnionFind(int n, int[][] edges) {
    int[] fathers = new int[n+1];
    int[] cand1 = new int[2], cand2 = new int[2];
    for (int[] e : edges) {
      if (fathers[e[1]] == 0) { // father not exist before
        fathers[e[1]] = e[0];
      } else {
        cand1[0] = fathers[e[1]];
        cand1[1] = e[1];
        cand2[0] = e[0];
        cand2[1] = e[1];
        cand2[0] = -1; // remove candidate 2
      }
    }

    for (int i = 0; i < n+1; i++) fathers[i] = i;

    for (int[] edge: edges) {
      int f1 = find(fathers, edge[0]);
      int f2 = find(fathers, edge[1]);
      if (f1 == f2) {
        return cand1[0] > 0 ? cand1 : edge;
      } else {
        fathers[f1] = f2;
      }
    }
    return cand2;
  }


  private int find(int[] fathers, int i) {
    if (fathers[i] != i) {
      fathers[i] = find(fathers, fathers[i]);
    }
    return fathers[i];
  }
}
