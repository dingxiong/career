This is my personal collection of materials for tech interviews.

[Read this goddam list](https://cp-algorithms.com/)
[Chinese resource](https://oi-wiki.org/)

## Algorithms

### Array related
- core
	- [x] quick select `LC1471`
	- [x] rainbow sort

### String matching
- core
	- [ ] KMP
	- [ ] Rabin Karp
	- [ ] Boyer Moore
- extended:
	- [x] Manacher: find the longest palindrome substring
	- [x] Ukkonen’s Suffix Tree Construction
		> Very complicated. Only learn it if you have time. [best illustration](https://stackoverflow.com/questions/9452701/ukkonens-suffix-tree-algorithm-in-plain-english/9513423#9513423)
	- 

### Graph/tree algorithm
- core
	- [x] tree traversal `LC1457`, 
	- [x] cycle detection `LC684`, `LC207`
	- [x] minimal spanning tree
	- [x] Dijkstra's algorithm `LC743`
	- [x] uniform-cost search  
		> Dijkstra's algorithm searches for shortest paths from root to every other node in a graph, whereas uniform-cost searches for shortest paths in terms of cost to a goal node. 
	- [ ] A* algorithm 
	- [x] Bellman–Ford algorithm  `LC743`
		> Dijkstar's algorithm cannot handle negative weight edges, but Bellman-Ford does. 
	- [x] Floyd–Warshall algorithm `LC1462`
	- [x] Shortest Path Faster Algorithm (SPFA) `LC743`
		> An improvement on top of Bellman-Ford
	- [ ] Johnson's algorithm
	- [ ] Radix sort
	- [x] Union find `LC 765`
	- [ ] 
	- [ ] Hungarian algorithm (perfect matching in bipartite graph), KM algorithm
- extended
	- [ ] Morris traversal 
	- [x] Convex hull `LC 587` 

### Others
- core
	- [x] Fisher–Yates shuffle `LC 519`
	- [x] Reservoir sampling
	- [x] Boyer-Moore algorithm
	- [x] Knapsack problem 
- others
    - 

## Data structures
- basic
    - [x] stack `LC1475, LC1081`
    - [ ] 
- core
	- [ ] Red black tree 
	- [ ] AVL
	- [x] Trie tree (radix tree, prefix tree) `LC720, LC754, LC677`
		- Understand `compressions`
	- [ ] Segment tree
		- [Lazy Propagation](https://www.geeksforgeeks.org/lazy-propagation-in-segment-tree/)
		- [Coordinate Compression](https://leetcode.com/articles/falling-squares/)
		- array representation similar to heap
- extended
	- [x] B-Tree
	- [x] Log-structured merge-tree (LSM)
	- [x] Suffix tree
	- [ ] Skip list
	- [ ] [Rope](https://en.wikipedia.org/wiki/Rope_(data_structure))

## Architecture && Experience
System design steps: 
1. use cases
2. data schemas & Api & tradeoff 
3. data size & scalability

Common techniques:
- [ ] Solr vs Elasticsearch, reverse indexing
- [ ] sharding, partitioning
- [x] push vs pull
- [x] consistent hashing (cassandra), p2p vs master-slave

## [Coding tips](coding_tips.md)
## [Company list](companies.md)
## [System design](system_design/README.md)

## Resources
- [How to choose startup](https://www.douban.com/group/topic/4239381/)
- [Guide to Equity & IPOs](https://blog.wealthfront.com/equity-ipo-guide/)  
- [paysa](https://www.paysa.com/); [levels](https://www.levels.fyi/); [ref](https://reffo.us/offers); [repher](https://repher.me/)
- Look up info about startups
	- [crunchbase](https://www.crunchbase.com) 
	- [Angel list](https://angel.co/)
	- https://breakoutlist.com/
	- search on blind. Follow topic `Startups`
- https://techcrunch.com/
- [全球最知名的十五大高频交易公司](https://zhuanlan.zhihu.com/p/56510796)

## [2019 interview result](./2019/README.md)

## C++ material
1. Effective Modern C++: 42 Specific Ways to Improve Your Use of C++11 and C++14
2. C++ Templates: The Complete Guide, 2nd Edition


