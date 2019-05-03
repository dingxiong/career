This is my personal collection of materials for tech interviews.

## Algorithms

### string matching
- core
	- [ ] KMP
	- [ ] Rabin Karp
	- [ ] Boyer Moore
- extended:
	- [x] Manacher: find the longest palindrome substring
	- [x] Ukkonen’s Suffix Tree Construction
		> Very complicated. Only learn it if you have time. [best illustration](https://stackoverflow.com/questions/9452701/ukkonens-suffix-tree-algorithm-in-plain-english/9513423#9513423)
	- 

### graph/tree algorithm
- core
	- [x] cycle detection `LC684`
	- [x] Dijkstra's algorithm `LC743`
	- [x] uniform-cost search  
		> Dijkstra's algorithm searches for shortest paths from root to every other node in a graph, whereas uniform-cost searches for shortest paths in terms of cost to a goal node. 
	- [ ] A* algorithm 
	- [x] Bellman–Ford algorithm  `LC743`
		> Dijkstar's algorithm cannot handle negative weight edges, but Bellman-Ford does. 
	- [ ] Floyd–Warshall algorithm
	- [x] Shortest Path Faster Algorithm (SPFA) `LC743`
		> An improvement on top of Bellman-Ford
	- [ ] Johnson's algorithm
	- [ ] Radix sort
	- [x] Union find `LC 765`
- extended
	- [ ] Morris traversal 
	- [x] Convex hull `LC 587` 

### others
- core
	- [x] Fisher–Yates shuffle `LC 519`


## Data structures  
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
	- [x] Suffix tree
	- [ ] Skip list


## Architecture && Experience
System design steps: 
1. use cases
2. data schemas & Api & tradeoff 
3. data size & scalability

Common techniques:
- [ ] Solr vs Elasticsearch, reverse indexing
- [ ] sharding, partitioning
## Resources
- [How to choose startup](https://www.douban.com/group/topic/4239381/)
- [Guide to Equity & IPOs](https://blog.wealthfront.com/equity-ipo-guide/)  
- [paysa](https://www.paysa.com/); [levels](https://www.levels.fyi/); [ref](https://reffo.us/offers); [repher](https://repher.me/)
- Look up info about startups
	- [crunchbase](https://www.crunchbase.com) 
	- [Angel list](https://angel.co/)
	- search on blind. Follow topic `Startups`
- https://techcrunch.com/

## Misc
[mics](misc.md)