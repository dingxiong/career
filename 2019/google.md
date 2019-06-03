## google
- coding
    - [x] LC medium 56 62, 63 139 146 294 399 676 684 750 807 853 855
    - [x] LC hard 489 659 685 815 843 857
    - [ ] LC 115 222 224 315 399 410 59 943
    - [ ] LC 777, 774 334, 659, 41 273 126
    - [ ] [google hot questions](./google/Google_hot_questions.pdf)
    - [x] 高频 https://www.1point3acres.com/bbs/interview/google-software-engineer-429386.html
        - 第五题 => similar to Dijkstra. Use a BFS + PQ to contain traverse all possible routes with preference for smaller distance so far.
            ```java
            // a few main functions
            Holder getNextHolder(List<Holder> int x, int y);
            ```
        - 第六题 => we can project all points to x axis. and find the median of the points. If there are two points exactly at the median, 
            then we should project to y = pi * x. This way, no two points will be projected to the same point.
        - 其中第七题 chttps://www.1point3acres.com/bbs/interview/google-software-engineer-212722.html
    - [ ]移动键盘和求二叉树最大和的层数
    - [ ] 应该是面经题，包装比较多。谷歌有m个data center, data center按顺序连成一串。每个data center都有n个机器，相邻data center之间的机器都是相连的，一个data center内部机器不会互相连接。
        现在有一个job需要完成，job从第一个data center开始，一直传递到最后一个data center。给你两个function, getLatencyTime(machine1, machine2) 代表从一个机器传信息到另一个机器需要的时间，
        getJobTime(machine)代表给定机器处理job需要的时间，问完成job需要最短时间。follow up: 怎么unit test。如果必须花很多时间处理这个job怎么办，好像和原题无关了，我就说了分布式并行处理之类的。LC 743
    - [ ] 建水井。一个村子有很多房子，现在需要建水井让所有的房子都有水用，可以直接在房子上建水井，不同房子建水井有不同开销，也可以在房子之间铺水管对应的也有不同的开销，问怎么弄总开销最小。
        面完才发现是面经题，所以当时还是面试官一步步引导的。首先问我怎么model这个问题，然后如果只是铺水管怎么总开销最小，最后加上可以在房子上直接建水井的条件。总的来说就是用minimum spanning tree，union find，
        还跑了些test case。最后我说用一个virtual node连到每家，连接的edge代表在这家建水井的cost，面试官说是每家都弄一个virtual node，就听他的了吧。
    - [ ] 实现一个iterator class, input是正常的iterator, 这个class可以实现hasNext(), next(), skip(element), skip(element)会跳过正常iterator里next occurence of the given element。
        如果skip call n times, 就跳过下面 n个     given element，iterator里的elements可以有重复。Refer LC 284 for peek support.
    - [ ] give an array of words, construct a prefix tree that contains the words only. [ab, abcd, abee, bcd, bcf, bcfg] => 
                root
        ab bcd bcf
      abcd abee bcfg
    - [ ] LC sliding window
    - [ ] 写一个SkipIt类，要求提前调用skip(int n)，这样iterator中出现n的地方就跳过，而到下面去。要求实现这个SkipIt
    - [ ] 给了一个数组，有如下特点：sorted, 有重复，有且仅有一个数字在数组里的数量超过了25%，找到这个数字。比如1,2,2,6,6,6,6,7,10 那么答案就是6.
    - [ ] OS相关的问题，描述文件读写的detail流程。
    - [ ] find top k min 的分布式实现， 这个YouTube上有视频。
    - [ ] bucket sort的并行实现
    - [ ] insert number into a circular linkedlist，并update head到最小数字, linkedlist 要保证排序好的
    - [ ] 判断一个数组是否为三角数组，三角数组定义是：先递增再递减或者先递减在递增， follow up：在这个数组中 查找一个特定元素
    - [ ] 给一个string, 如果有相邻的同一个字母的大小写pair，把这两个char都删掉，follow up是如果新的string里面又出现了这种pair继续删掉，
        直到string里不含这种Pair为止。这道题看起来简单，要特别注意corner case。
    - [ ] 骰子拼字
    - [ ] 有一个 List<String>, 每个 String 是一个电影名字(全小写), "i love you", "you are smart", "you awesome", "smart baby" 这样
        如果规则是, String A 的最后一词和 B的第一词match, 则可以合并, 求全合并后最长(总 String最长)的合并结果, 返回这个结果. 用上面的例子就是 "i love you are smart baby".
    - [ ] 商人有一些商品，这些商品在cityA和cityB每天的物价都不一样，商人从cityA travel到cityB也有cost，所以要考虑每天在哪个city卖商品才能使收益最大化。每天只能卖一件商品，卖完为止
    - [x] 一个无重复数字的数组，假如[1,2,50,100]，要求只要把最大的数字in place的变成最小，且比其他数字要大，这里的话就是变成[1,2,3,4]。
        然后followup1是变成一个二维数组，同样规则。followup2是二维数组里面要求compress时，只要同一行里满足第一问的条件，同一列里也满足就可以，也就是说，满足这个条件的话，
        哪怕这个数在整个二维数组里是第5大的，但是如果把它变成4也可以满足，那就把它变成4，同时只要当前的数不是数组中最大的一个，它是几都无所谓。
        解法大概是keep一个数组作为col max，再keep一个常量作为row max，然后循环，比较，只有在比当前值大的时候才更新。
    - [x] 有很多街区，每个街区各自有商店， 餐馆或超市， 让你根据自己的preference选择一个街区居住，使得你离你prefrence的最远距离最小.
            比如 blocks = [[safeway, thai resataurant], [starbucks, walmat], [chinese restaurant, costco, starbucks]，[Indian resataurant]].
           preference = [starbucks, Safeway, Indian restaurant] 
           => step 1: 找出所有preference 的 block, 比如 { starbucks => {1, 3, 5}, Safeway => {2, 5, 6}, Indian restaurant => {2, 3,4} } 
            step 2: 搞一个priorityQueue, 把每个 preference 最小的地址push 进去 {1, 2, 2} 并且记录 max 很 min, 那么 best location 就是 min 和 max 的中间某点。
            然后不停的pop最小的loc 并且放进下一个loc. 同时跟新min, max, best_loc.
    - [x] expiration hashMap 
        ```java
        class Node {int value, long ttl}
        Map<Key, Node> map 
        Map<TTL, Set<Key>> 
        ```
    - [x] 说模拟Google Map中一个一维路段的车流，最后设计并表示出所有车流的平均速度，比如有[0,14,90mph]表示有一个车流从位置0到14，速度为90mph，
        然后有[3,15,80mph]，那相当于分成了3个车流，[0,3,90mph]，[3,14,85mph]，[14,15,80mph]，考虑到有overlap要算平均值，所有这个车流的class设计的时候得加个count表示由多少车流汇合。
        => sorting + process.
    - [x] 给一个数组A，找到i,j, 使得A == A[j] 并且sum[i:j] 最大
        => `Map<value, smallest_pre_sum>` for example [1, 2, 2, -10, 1, 6], then `1 -> -5, 2 -> 1`.
    - [x] 设计一个Iterator的next和hasNext，input是一个数组[a，b，c]和一个int n，每次next()输出一个可能的组合。比如说，n如果是2，
        可能的组合是ab，ac和bc，next第一次输出ab，第二次ac，第三次bc 
        => use `int[n] pos` to record the process state, then continue DFS.
    - [x] 棋盘上看有没有3个棋子连成一线，包括横竖对角
        => Use 3 maps `Map<x, count>`, `Map<y, count>` and `Map<x+y, count>`. 
    - [x] Say you have a web server and a logging component. The component has two functions as below. When a request come in to the web server, 
        started(string, int) get called first, then completed(string, int) get called. You are required to print out a logging statement for each 
        request Sorted by the started time.
        ```java
        Queue<Request> queue; 
        HashMap<String, Request> byId; 
        void started(timestamp, requestId) { 
            Request req = new Request(id=requestId, tStarted=timestamp); 
            queue.enqueue(req); 
            byId[requestId] = req; 
        } 
        void completed(timestamp, requestId) { 
            byId[requestId].tFinished = timestamp; 
            while(queue.peek().tFinished != null) { 
                byId.remove(queue.peek().id); 
                LOGGING STATEMENT
            } 
        }
        ```
    - [x] source和target，求问最少需要repeat source几次才可以得到target，repeat完的string可以删除任意character
        ```java
        private static int construct(String source, String target) {
            if (target.length() == 0) return 0;
            
            Map<Character, List<Integer>> locs = new HashMap<>();
            for (int i = 0; i < source.length(); i++) {
                locs.putIfAbsent(source.charAt(i), new ArrayList<>());
                locs.get(source.charAt(i)).add(i);
            }
            int result = 0;
            int n = target.length();
            for (int i = 0, prev = -1; i < n; i++) {
                char c = target.charAt(i);
                if (!locs.containsKey(c)) return -1;
                List<Integer> indices = locs.get(c);
                int nextLoc = Collections.binarySearch(indices, prev+1);
                if (nextLoc < 0) {
                    nextLoc = -nextLoc - 1;
                    if (nextLoc == indices.size()) {
                        result++;
                        prev = indices.get(0);
                    } else {
                        prev = indices.get(nextLoc);
                    }
                } else {
                    prev = indices.get(nextLoc);
                }
            }
            return result + 1;
        }
        ```
    - [x] 国际象棋跳马，棋盘无限大，有障碍物，问能否吃掉指定棋子。
    - [x] 手上一些扑克牌，判断能否组成n组straight（一个straight=五张连续的卡片，一张不能多也不能少），比如12345，1234455678都是valid的
        => `Map<next_num, List<counts>>` for example, 1223344 => `{5->{4, 3}}`.
    - [x] 给一个二维网格，每一个格子都有一个值，2 代表墙，1 代表僵尸，0 代表人类(数字 0, 1, 2)。僵尸每天可以将上下左右最接近的人类感染成僵尸，
        但不能穿墙。将所有人类感染为僵尸需要多久，如果不能感染所有人则返回 -1。
    - [x] 一个b tree，找到和最大的path，可以从任何node到任何node，但不能往回走，也就是一个node只能经过一次，用递归可以做
    - [x] 一个树，有一些多余的边使得出现了环，让去掉他们，bfs+set做
    - [x] binary tree，节点的值是一个char，现在要判断2棵树的inorder traversal输出是否一致，题目很简单但是最后发现其实考的是design。
        一开始有个warm up 写inorder traversal, 写了recursion版的和stack版。和面试官各种讨论时间空间复杂度，最后发现他想要的是我自己实现一个tree iterator class
    - [x] 输入两堆二维点坐标。一堆是自行车的坐标，一堆是人的坐标，把这车和人匹配。
        => 2 for loops to generate all (people, bike) pair and then sort and then pop out
    - [x] 一个api每次可以读取1024个字符，实现一个class可以读取任意长度字符
    - [x] given a list of integer ranges and a query interger range, return the list of missing ranges, i.e. the range that is within the query but not in 
        the given list. follow up, to 2-dimensional rectangle query, the missing areas.
    - [x] 给一个基本的iterator，可以返回是否有下一个，以及返回下一个值。要求在这个基础上实现一个skip iterator，这个iterator可以记录一些要求跳过的记录
        （python用dictionary记录，因为记录次数有用），如果下一个记录是要被跳过的，就是要跳过这个值，第n次遇到这个记录就不用跳过（如果这个记录在dictionary里面被记录了n次）
    - [x] 一个高频题，历史版本记录。一个数组（或者字符串），需要支持一下操作。1，更新某个位置上的值。2，snapshot，记录现在这个版本，并且把版本号加一。3，找到某个版本号对应的记录。
        实现起来有几个点，只记录差值可以优化空间。每个位置上更改的记录可以用一个数组（数组按照修改的版本号排序）来记录，这样搜索历史记录的时候可以用二分搜索加速。
        ```java
        int currentVersion = 0;
        int[] arr;
        History[] histories;

        class History {
            List<Integer> versions, values;
        }
        void update(int i, int val) {
            arr[i] = val;
        }

        void snapshot() {
            for (int i = 0; i < arr.length; i++) {
                List<Integer> vals = histories[i].values;
                if (vals.size() == 0 || vals.get(vals.size()-1) != arr[i]) {
                    histories[i].versions.add(currentVersion);
                    histories[i].values.add(arr[i]);
                }
            }
            currentVersion++;
        }
        ```
- system design
    - [ ] rate limiter
    - [ ] uuid generator
    - [ ] 设计一个分布式计费管理服务
    - [ ] 设计一分布式配置系统。 有很多micro servers跑在很多数据中心，每个server有很多config，比如service A 有配置是 最大内存 = 100mb, 
        用户发一个请求给这个配置系统，把这个设置改成200. 要求这个config change出去后尽可能快的被server pick up。
- BQ
    - [ ] 比如怎么带新人，怎么处理组内同事关系，有人突然离职或者受伤了，导致deadline之前活完不成了怎么办? 
    - [ ] 有没有什么工作是你commit了但没有完成的
    - [ ]  有没有什么工作是别人给你commit了但没有完成的
    - [ ] 如果你新加入一个team，但team里的productivity很低，你准备怎么办
    - [ ] 一些自己做项目的例子
    - [ ] 最看重的manager应有的素质. 最看重的组员应有的素质
    - [ ] 有没有什么是自己坚持的无法放弃的目标
    - [ ] 你怎么收集用户需求
    - [ ] 你怎么advocate你的teammate
    - [ ] struggle ddl
    - [ ] teammates 互相吵架 你怎么办？
    - [ ] 你如何和remote的人沟通