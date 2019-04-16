package com.abc.edf;

import java.util.*;

/**
 * Algorithms to find the convex hull of a set of points
 *
 * See https://en.wikipedia.org/wiki/Convex_hull_algorithms
 */
public class ConvexHull {
  public static void main(String[] args) {
    ConvexHull ch = new ConvexHull();

    System.out.println(
        ch.giftWrappingWithoutCollinear(new int[][]{{1,1}, {2,2}, {2,3}, {2,0}, {2,4}, {4,2}}));

    System.out.println(
        ch.giftWrapping(new int[][]{{1,1}, {2,2}, {2,0}, {2,4}, {3,3}, {4,2}}));

    System.out.println(
        ch.giftWrapping(new int[][]{{0,0}, {0,1}, {0,2}, {1,2}, {2,2}, {3,2}, {3,1}, {3,0}, {2,0}}));
  }

  /**
   * Gift wrapping algorithm is also known as Jarvis march
   *
   * Pseudocode
   *
   * jarvis(S)
   *   // S is the set of points
   *   pointOnHull = leftmost point in S // which is guaranteed to be part of the CH(S)
   *   i = 0
   *   repeat
   *     P[i] = pointOnHull
   *     endpoint = S[0]      // initial endpoint for a candidate edge on the hull
   *     for j from 1 to |S|
   *       if (endpoint == pointOnHull) or (S[j] is on left of line from P[i] to endpoint)
   *           endpoint = S[j]   // found greater left turn, update endpoint
   *     i = i+1
   *     pointOnHull = endpoint
   *   until endpoint == P[0]      // wrapped around to first hull point
   *
   * @param points N x 2 dimensional
   * @return indices of points on the convext hull
   */
  private List<Integer> giftWrappingWithoutCollinear(int[][] points) {
    int n = points.length;
    int leftMostIndex = findLeftMost(points);

    List<Integer> hullIndices = new ArrayList<>();
    hullIndices.add(leftMostIndex);

    while(true) {
      int curr = hullIndices.get(hullIndices.size()-1);
      int next = 0;
      for (int i = 1; i < n; i++) {
        if (next == curr || isOnLeft(points[curr], points[next], points[i])) {
          next = i;
        }
      }
      if (next == leftMostIndex) break;
      hullIndices.add(next);
    }

    return hullIndices;
  }

  /**
   * Similar to {@link #giftWrappingWithoutCollinear}, but this function handles collinear cases
   *
   * A few differences in order to deal with collinear cases.
   * 1. We use a set to store hull indices because there may be duplicates
   * 2. We use distance to distinguish collinear points, which will cause the loop to jump forward and backward a few times.
   *  You can draw this scenario in a piece of paper
   */
  private Set<Integer> giftWrapping(int[][] points) {
    int n = points.length;
    int leftMostIndex = findLeftMost(points);

    Set<Integer> hullIndices = new HashSet<>();
    hullIndices.add(leftMostIndex);

    int curr = leftMostIndex;
    while(true) {
      int next = 0;
      for (int i = 1; i < n; i++) {
        if (i == curr) continue;
        int cross = getCrossProduct(points[curr], points[next], points[i]);
        if (next == curr || cross > 0 || (cross == 0 && d2(points[curr], points[i]) > d2(points[curr], points[next]))) {
          next = i;
        }
      }

      // Handle collinear points. May add duplicated indices
      for (int i = 0; i < n; i++) {
        if (i == curr) continue;
        int cross = getCrossProduct(points[curr], points[next], points[i]);
        if (cross == 0) {
          hullIndices.add(i);
        }
      }

      if (next == leftMostIndex) break;
      hullIndices.add(next);
      curr = next;
    }

    return hullIndices;
  }

  /**
   * test whether c is on the left side of ab
   */
  private boolean isOnLeft(int[] a, int[] b, int[] c) {
    return getCrossProduct(a, b, c) > 0;
  }

  /**
   * ab x ac
   *
   * @return  only the z coordinate of cross product
   */
  private int getCrossProduct(int[] a, int[] b, int[] c) {
    int abx = b[0] - a[0];
    int aby = b[1] - a[1];
    int acx = c[0] - a[0];
    int acy = c[1] - a[1];

    return abx * acy - aby * acx;
  }

  private int findLeftMost(int[][] points) {
    int n = points.length;
    int leftMostPos = Integer.MAX_VALUE, leftMostIndex = 0;
    for (int i = 0; i < n; i++) {
      if (points[i][0] < leftMostPos) {
        leftMostPos = points[i][0];
        leftMostIndex = i;
      }
    }

    return leftMostIndex;
  }

  private int d2(int[] a, int [] b) {
    int dx = a[0] - b[0];
    int dy = a[1] - b[1];
    return dx * dx + dy * dy;
  }
}
