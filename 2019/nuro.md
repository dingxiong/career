## Nuro
2018/7/26 - 2019/6/15
- hint from recruiter
    - multithreading + IO
    - communication is important
    - show interest in nuro. why it is different from its competitor.
- coding
    - [x] LC 53
    - [x] LC medium 64 96 227 451
    - [x] LC hard 778
    - [ ] 实现一个cuckoo hashing
    - [x] 写一个自己的Vector类，要求在如下2个条件下，空间更效率：
        1. 只有3个或者更少的元素时
        2. 所有元素在1-100之间
        要用尽可能少的空间，但是要保证对于所有情况的正确性。（比如也会有1000）
        写出operator[]和push_back，可以用std::vector
        => 
        1. use `List<Byte>` to store the numbers. If int [1, 100], then store it normally. Otherwise, store `1<<7` and put 
            the `(position, number)` to `Map<Long, Long>` 
            For [i] => if list[i] highest bit is not set, then just return this byte. Otherwise, return `map.get(i)`.
        2. for n < 3 => ??? 
    - [x] 类似小岛那个题，但是让数最多的那个岛的岛屿个数
    - [x] Frog jump in a grid. Given grid size m, n, frog initial position x, y,  How many ways to jump out of the grid, within K steps?
        => 类似LC688. dp[m][n][k+1]
    - [ ] 给定一些 robot，和一些 target，已知所有的点（也就是已知每个 robot 到各个 target 的距离）要求安排一个方案: 一个 robot 到 一个 target。然后这个总的距离最小。
        比如 robot 有 a, b 两个，target 有 1， 2 两个。一个方案是 a 到 1，b 到 2，另一个方案是 a 到 2，b 到 1，答案是取这两个方案中移动距离最小的那个。先假设没有 tie。
        => follow up  然后是 假设上题中一个 robot 可以到多个 target，比如 a 可以先到 1，然后再到 2，而 b 则什么也不做。
    - [ ] point cloud: give several points, classify them in groups such that the distance of point in each each is smaller than d.
    - [ ] 平面上一堆坐标，类型是浮点，要求返回有没有任意两个点之间的距离是小于根号2的. 
        use hashmap ?? if |(x1, y1) - (x2, y2)| < sqrt(2) => at least |x1-x2| < 1 or |y1-y2| < 1 is true.
    - [ ] C++ 中 shared pointer 和 unique pointer 的区别
    - [x] Design and implement a data structure that support efficient insert/delete/read operations on a large in-memory mutable string (~Gb) 
        e.g. a text editor 
        ```c++
        void LargeString::insert(char c, size_t i);
        void LargeString::delete(size_t i);
        std::string LargeString::read(size_t start, size_t end);
        ```
        => use Rope https://en.wikipedia.org/wiki/Rope_(data_structure) or segment tree
- system design
    - [ ] Design Netflix
