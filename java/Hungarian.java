import java.util.*;

/**
 * Hungarian algorithm to find the perfect matching.
 * 
 * Suppose we have a group T, and S and a few edges from T to S. 
 * graph[i][j] = 1 means node i in T has connection to node j in S.
 * 
 * Steps:
 * 1. start from any unmatched item from T and do a DFS to find a argumenting path to some node in S.
 *    A argumenting path refers to a path that connects an unmatched node in T and an unmatched node in S.
 * 2. color the path in interleaving manner.
 * 3. repeat the process until every node is matched.
 */
public class Hungarian {
  public static void main(String[] args) {
    int[][] graph = {
        {1, 0, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1},
        {0, 0, 1, 0}
    };
    hungarian(graph);
  }

  private static int[][] hungarian(int[][] graph) {
    int n = graph.length;
    int[][] connections = new int[n][n];
    boolean[] rowUsed = new boolean[n];
    boolean[] colUsed = new boolean[n];
    for (int i = 0; i < n; i++) {
      if (rowUsed[i]) continue;
      List<Integer> path = new ArrayList<>();
      path.add(i);
      find(graph, i, false, colUsed, path, new HashSet<>(), new HashSet<>());
      colorNodes(connections, rowUsed, colUsed, path);
      System.out.println("i:" + i + "; path:" + path + "; rowUsed:" + Arrays.toString(rowUsed) + "; colUsed:" + Arrays.toString(colUsed));
      System.out.println(toStr(connections));
    }

    return connections;
  }

  private static boolean find(int[][] graph, int start, boolean atCol, boolean[] colUsed,
                              List<Integer> path, Set<Integer> rowVisited, Set<Integer> colVisited) {
    int n = graph.length;
    if (atCol && !colUsed[start]) {
      return true;
    }
    if (atCol) {
      for (int i = 0; i < n; i++) {
        if (graph[i][start] == 0 || colVisited.contains(i)) continue;
        path.add(i);
        colVisited.add(i);
        if (find(graph, i, false, colUsed, path, rowVisited, colVisited)) return true;
        colVisited.remove(i);
        path.remove(path.size()-1);
      }
    } else {
      for (int i = 0; i < n; i++) {
        if (graph[start][i] == 0 || rowVisited.contains(i)) continue;
        path.add(i);
        rowVisited.add(i);
        if (find(graph, i, true, colUsed, path, rowVisited, colVisited)) return true;
        rowVisited.remove(i);
        path.remove(path.size()-1);
      }
    }
    return false;
  }

  private static void colorNodes(int[][] connections, boolean[] rowUsed, boolean[] colUsed, List<Integer> path) {
    int n = path.size(); // we are sure that n is even
    for (int i = 0; i < n; i+=2) {
      int rowNode = path.get(i), colNode = path.get(i+1);
      connections[rowNode][colNode] = 1;
      if (i+2 < n) connections[path.get(i+2)][colNode] = 0;
      rowUsed[rowNode] = true;
      colUsed[colNode] = true;
    }
  }

  private static String toStr(int[][] a) {
    StringBuilder sb = new StringBuilder();
    for (int[] x : a) {
      sb.append(Arrays.toString(x));
      sb.append('\n');
    }
    return sb.toString();
  }
}
