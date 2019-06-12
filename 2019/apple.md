2018/11/19 - 2019/6/11
- coding
    - [x] LC easy 225 387 706 724
    - [x] LC medium 8 18 33 96 139 151 230 238 297 314 351 356 384 394 886
    - [x] LC hard 10 97 295 340 773
    - [x] LC LRU
    - [ ] 求出N以内的所有质数，并优化存储空间。
    - [ ] cvs parser
    - [ ] 24点
    - [ ] 如何rebalance一个BST
    - [ ] frog jump river
    - [ ] 设计个大整数的类。主要内容都在constructor里。功能上只要做了个自增1. 需要考虑负数的情况。
    - [x] implement a deadlock
        ```java
        Lock lock1 = new ReentrantLock();
        Lock lock2 = new ReentrantLock();
        int var1 = 0, var2 = 0;

        private void worker1() {
            lock1.lock();
            try {
                var1 = 1;
                while (var2 == 0); // make sure worker2 get lock2
                System.out.println("worker1 waiting for lock 2");
                lock2.lock();
                try{
                    System.out.println("worker1 gets lock 2");
                } finally {
                    lock2.unlock();
                }
            } finally {
                lock1.unlock();
            }
        }

        private void worker2() {
            lock2.lock();
            try {
                var2 = 1;
                while (var1 == 0); // make sure worker1 get lock1
                System.out.println("worker2 waiting for lock 1");
                lock1.lock();
                try {
                    System.out.println("worker2 gets for lock 1");
                } finally {
                    lock1.unlock();
                }
            } finally {
                lock2.unlock();
            }
        }
        ```
    - [ ] random pick with weight
    - [ ] longest increasing path in matrix
    - [x] Given an array of integers, those integers are increasing first and then decreasing. Find the pivot point.
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
    - [ ] 设计throttling
    - [ ] design a sports website
    - [ ] Design a twitter.
    - [ ] design Venmo
    - [ ] 设计一个分布存储的service
- BQ
    - [ ] 请形容一下你遇到的最大的bug，并说出是如何解决的
    - [ ] 介绍你觉得自己做得最好的项目，你在这个项目里遇到的最大的问题， 你从中获得的最有成就感的东西

    