- coding
    - [ ] LC 34, 128, 164, 200, 206, 332, 465, 694,
    - [ ] LC next permutation, calculator I + II, number of islands, intersect/untion two lists of intervals, merge interval, skyline, alien dictionary, 
    - [ ] LC 2D Trapping Rainwater, 3D Trapping Rainwater
    - [ ] Reconstruct itinerary. Follow up: return deepest path in DAG with different starting nodes
    - [ ] N 个朋友去饭店吃饭，结账时需要平摊吃饭的开销，然而每个人实际付的钱是不平均的，比如，输入是每个人实际付的钱array [5, 10, 12, 15, 3], 求写代码，算出来每个人要给其他人多少钱，才能平摊开销。按照我上面的例子，每个人的平均开销应该是（5+10+12+15+3）/5 =9，如果这五个人分别用A，B，C，D，E表示。那么，A要付1刀给B. A要付3刀给C，E要付6刀给D
    - [ ] 打印所有的不小于某个数的Jumping Number.   Jumping Number 就是相邻位数之间差绝对值为1. 比如打印所有不小105的Jumping Number就是  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 21, 23, 32, 34, 43, 45, 54, 56, 65, 67, 76, 78, 87, 89, 98, 101 其实就是BFS/DFS 遍历二叉树. Follow up 是打印某个区别的Jumping Numbers
    - [ ] 给一个pattern 一个input string，pattern里面有若干问号表明前一个字母可有可无，然后返回boolean看input符不符合这个pattern
    - [ ] 给一个matrix, 一个初始点和一个终止点。每次可以走（x+y,y）或者（x,x+y）。问能否到最终点。（Assume 都是正数）
    - [ ] give a list of edges[(a,b)],让你建个graph, 不停的删除graph里的node，最后要求不存在某个node是有两条边的。还要求删除的node最少。让你return最少删除几个node。
    - [ ] 给你一个integer, 可以把其中两个digit位置交换一次, 返回操作后的最大数字: E.g. 5831 -> 8531, 777 -> 777 (已经是最大了)
    - [ ] 实现一个数据结构 以下操作都要O(1). put(k, v), get(k), get_random() -> 随机返回key value pair, delete(k)
    - [ ] 是给两堆Interval {start, end},  每一堆里面的Interval是没intersection.  第一个问题是 求两堆 的交集。第二个问题是  求两堆的合集。 要求返回的结果里的Interval是没intersection。
        ```java
        
        ```
    - [x] Given an array, return kth most frequent element
         => use a Map: num -> count, and then squash them into a priority queue.
    - [x] 给出一个有序数组，找target的出现次数
        ```java
        private static int countTarget(int[] a, int target) {
            int k = Arrays.binarySearch(a, target);
            if (k < 0) return 0;

            return leftEndHelper(a, k, a.length - 1, target) + rightEndHelper(a, 0, k, target) - 1;
        }

        private static int leftEndHelper(int[] a, int left, int right, int target) {
            if (left == right) return 1;
            if (left == right - 1) return 1 + (a[right] == target ? 1 : 0);

            int mid = left + (right - left) / 2;
            if (a[mid] == target) return leftEndHelper(a, mid, right, target) + mid - left;
            else return leftEndHelper(a, left, mid-1, target);
        }

        // right end equals target
        private static int rightEndHelper(int[] a, int left, int right, int target) {
            if (left == right) return 1;
            if (left == right - 1) return 1 + (a[left] == target ? 1 : 0);

            int mid = left + (right - left) / 2;
            if (a[mid] == target) return rightEndHelper(a, left, mid, target) + right - mid;
            else return rightEndHelper(a, mid+1, right, target);
        }
        ```
- system design
    - [设计uber](https://www.youtube.com/watch?v=umWABit-wbk&t=1293s)
    - design chat service
    - design youtube
    - DesignDropbox 所有的System Design会问的都会问 (storage/scale/requirements etc) 会特别问如何解决 conflicts/concurrency (记得看看lamport clock) 然后要想想存data本身跟存储meta data之间怎么协调
    - heatmap service. 自己定义输入输出，然后就是返回当前driver在地图上的密度。    
    - design Amazon 商品详情页下的 people also brough these items
    - 设计一个高并发的在线售票系统，从user case，QPS，前端，到database全说了一遍。followup：如果售票系统还要加个新功能，用户选座位时候可以hold 5分钟，在这个时间段其他用户看这张票是sold out，整个系统该怎么改？
- Behavior
    - 怎么带junior，怎么解决conflict
    - 做过最难的project
    - 过去得到的负面反馈 后来怎么解决
    - 2个你喜欢做的工作 2个你不喜欢做的工作




    - 找岛的个数和返回一个数的质数因子
    - 给定一串字符，以及每行的长度限制，输出每行内容。
e.g. 20 Hey Joey, your uber is arriving soon!
Hey Joey, your uber 
is arriving soon!

Follow-up
1. 什么edge case要考虑？答单个单词长度超过每行限制。要求实现当下一个字符的长度超过限制时，从中截断输出。
e.g. 11 Hey Joey, your uber is abcdefghijklmnopqrstuvwxyz soon!
Hey Joey, 
your uber
is abcdefghijklmnopqrs
tuvwxyz
soon!

2. 又问了如果你来测试，会给出哪些test case
3. 现在想要在每一行后加上标记这是第几行 （i/N）i是当前行，N是总行数
e.g. 15 Hey Joey, your uber is abcdefghijklmnopqrstuvwxyz soon!
Hey Joey,(1/6)
your uber(2/6)
is abcdefg(3/6)
hijklmnopq(4/6)
rstuvwxyz(5/6)
soon!(6/6)

用了先估计每行需要省出多少字符来做标记的方法。用input长度除去行宽的位数加一来估计N的字符数，然后用估计的字符数来限制新的每行行宽。之后将每一行的字符写入，最后再在每一行后加上标记即可。

https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=516826&extra=page%3D29%26filter%3Dauthor%26orderby%3Ddateline%26sortid%3D311&page=1

- 电面是给定一个transaction list代表一系列银行之间转账的交易，比如[Chase, BOA, 100]代表Chase给BOA打了100刀，简化这个transaction list。不需要简化到最简，只要相同一对银行的转账记录压缩到一个就行了，比如transaction list包含[Chase, BOA, 100]，[BOA, Chase, 200], [BOA, Chase, -100], 就可以简化成[BOA, Chase, 0]，谁在前面都可以。题目不难，还是很直观的。
- LC 140. Word Break II
- Kth Most Frequent Element in array. Given an array, return kth most frequent element, like:
example1: array:[1,5,5,4,4,5], k = 1, return 5 (5's has 1st most frequency)
example2: array:[1,

    
    第一轮-bar-raiser：主要聊了工程师相关的一些问题，全程都在BQ，比如leadership啊mentoringship之类的
第二轮Design：一个俄罗斯美女和一个美国经理，DesignInstgram，老题目了。主要是结合了Feed+CDN的设计
第三轮Design：一个土耳其大哥，Design Whatsapp，在登录认证上有很多的讨论
第四轮Coding：一个欧洲帅哥，手机短信切分的问题，要考虑一下part大于10个的情况，一定要run出正确的结果，还问了一些testing的问题。应该说讨论的还是蛮开心的
第五轮Coding：一个俄罗斯美女，GameOfLife，主要问了是否有一些优化的方法，还问了时间复杂度的问题。

- system design
    - DesignDropbox 所有的System Design会问的都会问 (storage/scale/requirements etc) 会特别问如何解决 conflicts/concurrency (记得看看lamport clock) 然后要想想存data本身跟存储meta data之间怎么协调
    -     