import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.TreeSet;

/**
 * Leetcode 743. Network Delay Time
 *
 *  There are N network nodes, labelled 1 to N.
 *  Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the
 *  source node, v is the target node, and w is the time it takes for a signal to travel from
 *  source to target.
 *
 *  Now, we send a signal from a certain node K. How long will it take for all nodes to receive the
 *  signal? If it is impossible, return -1.
 *
 */
class Dijkstra {
  /**
   * 1. all nodes are added to tree set (TS) at initialization stage => max queue size = N
   * 2. We choose TS instead of priority queue (PQ) because we have a step to update the distance
   *  `pq.romove(next); pq.add(nextNode)`. PQ has linear complexity of removing an element.
   * 3. TS comparator => you should compare both `distances[x]` and `x`. Otherwise, all nodes with
   *  the same distance will be regarded the same and would not be inserted to the set.
   *  
   * Pro:
   * 1. max queue size = N
   * 
   * Cons:
   * 1. easy to use TS in a wrong way.
   */
  public int algorithmUsingTreeSet(int[][] times, int N, int K) {
    Map<Integer, Map<Integer, Integer>> costs = new HashMap<>();
    for (int[] e: times) {
      costs.putIfAbsent(e[0] - 1, new HashMap<>());
      costs.get(e[0] - 1).put(e[1] - 1, e[2]);
    }

    int[] visited = new int[N];
    int[] distances = new int[N];
    Arrays.fill(distances, Integer.MAX_VALUE);
    distances[K-1] = 0;

    TreeSet<Integer> pq = new TreeSet<>(Comparator.<Integer>comparingInt(x -> distances[x]).thenComparingInt(x-> x));
    for (int i = 0; i < N; i++) pq.add(K - 1);

    while (!pq.isEmpty()) {
      int node = pq.pollFirst();
      if (!costs.containsKey(node)) continue;
      for (Map.Entry<Integer, Integer> next: costs.get(node).entrySet()) {
        int nextNode = next.getKey();
        int d = next.getValue();
        if (distances[nextNode] > distances[node] + d) {
          distances[nextNode] = distances[node] + d;
          pq.remove(nextNode);
          pq.add(nextNode);
        }
      }
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
      result = Math.max(result, distances[i]);
    }

    return result == Integer.MAX_VALUE ? -1 : result;
  }

  /**
   * 1. Only starting node is added in PQ at initialization stage
   * 2. Need a `visited[]` array to record visited nodes
   * 
   * Pros.
   * 1. easy to implement
   * 
   * Cons
   * 1. There are maybe more than N nodes in PQ, which is very inefficient
   */
  public int algorithmUsingPriorityQueue(int[][] times, int N, int K) {
    Map<Integer, Map<Integer, Integer>> costs = new HashMap<>();
    for (int[] e: times) {
      costs.putIfAbsent(e[0] - 1, new HashMap<>());
      costs.get(e[0] - 1).put(e[1] - 1, e[2]);
    }

    int[] visited = new int[N];
    int[] distances = new int[N];
    Arrays.fill(distances, Integer.MAX_VALUE);
    distances[K-1] = 0;

    Queue<Integer> pq = new PriorityQueue<>(Comparator.comparingInt(x -> distances[x]));
    pq.offer(K - 1);

    while (!pq.isEmpty()) {
      int node = pq.poll();
      if (visited[node] == 1) continue;
      visited[node] = 1;
      if (!costs.containsKey(node)) continue;
      for (Map.Entry<Integer, Integer> next: costs.get(node).entrySet()) {
        int nextNode = next.getKey();
        int d = next.getValue();
        if (distances[nextNode] > distances[node] + d) {
          distances[nextNode] = distances[node] + d;
        }
        pq.offer(nextNode);
      }
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
      result = Math.max(result, distances[i]);
    }

    return result == Integer.MAX_VALUE ? -1 : result;
  }
  
}
