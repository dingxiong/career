2018/11/19 - 2019/5/23
- coding
    - [x] LC easy 225 387 706
    - [x] LC medium 96 139 238 297 314 384 394
    - [x] LC hard 97 340
    - [ ] LC 8 10 351 356 724
    - [ ] LRU
    - [ ] sliding game
    - [ ] 求出N以内的所有质数，并优化存储空间。
    - [ ] 判断图bipartite
    - [ ] cvs parser
    - [ ] median of a stream
    - [ ] 24点
    - [ ] frog jump river
    - [ ] reverse words in a string
    - [ ] search in rotated sorted array
    - [ ] four sum
    - [ ] 设计个大整数的类。主要内容都在constructor里。功能上只要做了个自增1. 需要考虑负数的情况。
    - [ ] implement a deadlock
    - [ ] random pick with weight
    - [ ] longest increasing path in matrix
    - [ ] Given an array of integers, those integers are increasing first and then decreasing. Find the pivot point.
    - [ ] implement merge sort from scratch. follow up: when you should consider merge sort over quicksort?
    - [ ] convert a binary tree to a list (double linked list) in place. after conversion. the left child of each node points to the prevous node, and right child points to the next node.
    - [ ] 类似于猜词，给一个api，public char[] higherPriority(), 会返回两个字母，比如说“abcd”，这个api会随机返回ab，ac，ad，bc，cd，前一个char在后一个char的左边，
        然后问你如何call这个api最少的次数来得到原始的单词，给出原始单词的长度为N 这个题跟面试官讨论了好久，我一开始说可以用类似拓扑排序来做，把api的返回值看成是边，然后每次做一个dfs，
        如果能够从起点开始走，走的点的数量是单词的长度，就可以停止了。面试官说这样子还不够精简，还有别的办法可以使api call次数更少，后来又扯到了union find说公共祖先，后来讨论半天也没讨论出来，
        小姐姐全程没给提示只是在我提出想法后举出反例来说还有更优解 
    - [x] 有一堆机器，每个机器只有boolean receiveLeft, boolean receiveRight, void sendToLeft, void sendToRight四个方法，问的是要你针对每个机器实现startUp方法来计算出一共有多少台机器
        => every machine count left and right => get total number
        ```java
        rightCount = 0;
        while (receiveLeft() ! = null) {
            rightCount++;
            sendToLeft();
        }
        ```
- system design
    - [ ] design tiny url
    - [ ] distributed metrics collector
    - [ ] design apple store
    - [ ] 设想你打开一个folder，然后可以单选，多选，想想如何用data structure和Api来维护这个操作。。。
    - [ ]  设计throttling
    - [ ]  design a sports website
    - [ ] Design a twitter.
    - [ ] 设计一个分布存储的service
- BQ
    - [ ] 请形容一下你遇到的最大的bug，并说出是如何解决的
    - [ ] 介绍你觉得自己做得最好的项目，你在这个项目里遇到的最大的问题， 你从中获得的最有成就感的东西

    