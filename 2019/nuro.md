## Nuro
2018/7/26 - 2019/5/28
- coding
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
    - [ ] point cloud: give several points, classify them in groups such that the distance of point in each each is smaller than d.
    - [ ] 平面上一堆坐标，类型是浮点，要求返回有没有任意两个点之间的距离是小于根号2的. 
        use hashmap ?? if |(x1, y1) - (x2, y2)| < sqrt(2) => at least |x1-x2| < 1 or |y1-y2| < 1 is true.