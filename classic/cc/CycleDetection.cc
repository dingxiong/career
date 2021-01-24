/**
 * There are 3 popular ways to find cycles in a graph: Union-Find, DFS, BFS
 * 
 * 1. BFS can be used to detech the existence of a cycle, but not good to 
 *  construct the cycle. See example below,
 *  1 -> 2 -> 3 -> 4
 *     |           |
 *     > 5 -> 6 -> 7
 *  If we start from node 1, then BFS stops at 4 & 7. and we have the parents info
 *  for both 4 and 7, but it is little hassle to construct the cycle starting from 
 *  4 and 7.
 * 
 *  2. DFS
 *  code see https://cp-algorithms.com/graph/finding-cycle.html
 * 
 * /