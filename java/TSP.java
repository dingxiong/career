import java.util.Arrays;
import java.util.Deque;
import java.util.LinkedList;

/**
 * Travelling Salesman Problem (Leetcode 943)
 * Held–Karp algorithm
 * DP relation:
 * D(S, c) = min { D(S - x, x) + d(x, c) }
 * wit base condition S = {c} => D(S, c) = d(1, c)
 */
public class TSP {
  public String shortestSuperstring(String[] A) {
    int[][] graph = buildGraph(A);

    int n = A.length;
    int n2 = 1 << n; // total number of subsets of A
    int[][] dp = new int[n2][n]; // corresponding to D(S, c)
    int[][] path = new int[n2][n];

    int shortest = Integer.MAX_VALUE;
    int last = 0;
    for (int i = 0; i < n2; i++) {
      Arrays.fill(dp[i], Integer.MAX_VALUE);
      for (int j = 0; j < n; j++) {
        if ((i & (1 << j)) == 0) continue; // if c is not in S
        int prevSet = i - (1 << j);
        if (prevSet == 0) {
          dp[i][j] = A[j].length();
        } else {
          for (int k = 0; k < n; k++) {
            if (dp[prevSet][k] < Integer.MAX_VALUE && dp[prevSet][k] + graph[k][j] < dp[i][j]) {
              dp[i][j] = dp[prevSet][k] + graph[k][j];
              path[i][j] = k;
            }
          }
        }

        if (i == n2 - 1 && shortest > dp[i][j]) {
          shortest = dp[i][j];
          last = j;
        }
      }
    }

    // retrieve the path
    Deque<Integer> stack = new LinkedList<>();
    int current = n2 - 1;
    while (current > 0){
      stack.offerFirst(last);
      int tmp = current;
      current -= (1 << last);
      last = path[tmp][last];
    }

    // build final result
    StringBuffer sb = new StringBuffer();
    int i = stack.pollFirst();
    sb.append(A[i]);
    while (!stack.isEmpty()) {
      int j = stack.pollFirst();
      String next = A[j];
      sb.append(next.substring(next.length() - graph[i][j]));
      i = j;
    }

    return sb.toString();
  }

  int[][] buildGraph(final String[] A) {
    int n = A.length;
    int[][] graph = new int[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        graph[i][j] = calDistance(A[i], A[j]);
      }
    }

    return graph;
  }

  private int calDistance(String a, String b) {
    for (int i = 0; i < a.length(); i++) {
      if (b.startsWith(a.substring(i))) return b.length() - (a.length() - i);
    }
    return b.length();
  }
}
