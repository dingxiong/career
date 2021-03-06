2019/5/19 - ..
店面： 矩阵找最大 1 block
- coding
    - [x] LC easy: 3, 17, 20, 22, 33, 34, 35, 36, 88, 101, 122, 160, 349 359 427 438 706
    - [x] LC medium: 40, 49, 56, 62, 75, 79, 86, 98, 127, 138, 139, 173, 200, 206, 207, 208, 210, 221, 227, 253, 267, 279, 287, 289 300 304 332 
        341 353 362 380, 385, 399, 450, 528 529 625 636 640 658 694 785 921 947 986 1014,
    - [x] LC hard: 4 37, 42，68, 72, 76, 126, 128, 140, 158 159 212, 239, 295 297 305 329 381 403 407 410 465 679 730 741 759 772 773 805 815 895
    - [ ] LC 32 164 745 301 518 978 979   
    - [ ] ** LC 736
    - [ ] LC next permutation, calculator I, intersect/untion two lists of intervals, merge interval, skyline, alien dictionary, 
    - [ ] LC hit count, surrounded region, Design Hit Counter, coin change 2
    - [ ] LC 给一个almost sorted array，求index i,j 使得如果i,j 之间的元素全排序好了，那整个array也排序好了
    - [ ] Reconstruct itinerary. Follow up: return deepest path in DAG with different starting nodes
    - [ ] 打印所有的不小于某个数的Jumping Number.   Jumping Number 就是相邻位数之间差绝对值为1. 比如打印所有不小105的Jumping Number就是  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 21, 23, 32, 34, 43, 45, 54, 56, 65, 67, 76, 78, 87, 89, 98, 101 其实就是BFS/DFS 遍历二叉树. Follow up 是打印某个区别的Jumping Numbers
    - [ ] 判断围棋一个棋子有没有被围 - 第一问写个helper function. follow up: 判断围棋的一片棋子有没有被围 - 用BFS就可以了.
    - [ ] find all meetings that conflicts. Ex. input = [[2,3, 'a'], [1,4,'b'], [3,5,'c']], output = [['a', 'b'], ['b', 'c']]
    - [ ] 给一个pattern 一个input string，pattern里面有若干问号表明前一个字母可有可无，然后返回boolean看input符不符合这个pattern
    - [ ] 给一个matrix, 一个初始点和一个终止点。每次可以走（x+y,y）或者（x,x+y）。问能否到最终点。（Assume 都是正数）
    - [ ] 类似于coin，给定几种规格的单程票，日票，周票，月票，根据日历标定是否乘车，来确定成本最小的方案
    - [ ] give a list of edges[(a,b)],让你建个graph, 不停的删除graph里的node，最后要求不存在某个node是有两条边的。还要求删除的node最少。让你return最少删除几个node。
    - [ ] 给你一个integer, 可以把其中两个digit位置交换一次, 返回操作后的最大数字: E.g. 5831 -> 8531, 777 -> 777 (已经是最大了)
    - [x] 收尾相接的排好序的循环单链表，实现两个方法，1. findNode(int val，Node startNode)   2. insertNode(int val, Node startNode) 要保持排好序， 因为首尾相接，startNode可以是任意其中的Node。
        => part 2: 三种情况分别考虑: val = currtNode.val, val > currtNode.val, val < currtNode.val. 每种情况会有好几个branch.
    - [x] 实现一个数据结构 以下操作都要O(1). put(k, v), get(k), get_random() -> 随机返回key value pair, delete(k)
        => similar to LC 380. Use swap for deletion
    - [ ] 造n-ary tree, 给一系列turple, 无序的， 不仅ancestor和直系的children是一对turple， 且ancestor和任何非直系的children也是一对turple 
        打比方说 1-2 1-3 2-4这样一个树 那么输入就是[(1,1)(1,2)(1,3)(2,2)(3,3)(1,4)(2,4)(4,4)]然后把这个恢复成树， 注意这些turple不是根据ancester-children的任何顺序排好的，是无序的
    - [ ] Design Rate Limiter API, 说是有个function a, 设计 Rate Limiter class，保证每秒内call a的次数不能超过100次
    - [ ] 一维公车站问题，给一个list e.g [0,1,2,4,6,7], 里面都是乘客的一维坐标位置， 问给一个M, 就是公交车最多停的次数，问你停在那几个点可以是乘客上车的距离和最少
        https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=515959&extra=page%3D48%26filter%3Dauthor%26orderby%3Ddateline%26sortid%3D311%26sortid%3D311%26orderby%3Ddateline
    - [x] Range Minimum Query
        ```java
        private Node root;

        int query(int from, int to) {
            return queryHelper(root, from , to);
        }

        int queryHelper(Node node, int from, int to) {
            if (node.from == from && node.to == to) return node.min;

            int mid = (node.from + node.to) / 2;
            if (from > mid) return queryHelper(node.right, from, to);
            else if (to <= mid) return queryHelper(node.left, from, to);
            else return Math.min(queryHelper(node.left, from, mid), queryHelper(node.right, mid+1, to));
        }

        void buildTree(int[] nums) {
            int n = nums.length;
            root = new Node(0, n-1);
            for (int i = 0; i < n; i++) add(root, i, nums[i]);
        }

        private int add(Node node, int index, int num) {
            if (node.from == node.to) {
                node.min = num;
                return num;
            }

            int mid = (node.from + node.to) / 2;
            if (index <= mid) {
                if (node.left == null) node.left = new Node(node.from, mid);
                node.min = Math.min(node.min, add(node.left, index, num));
            } else {
                if (node.right == null) node.right = new Node(mid+1, node.to);
                node.min = Math.min(node.min, add(node.right, index, num));
            }

            return node.min;
        }

        class Node {
            int min;
            Node left, right;
            int from, to;

            Node(int from, int to) {
                this.from = from;
                this.to = to;
                min = Integer.MAX_VALUE;
            }
        }
        ```
    - [x] 给两个array，分别在两个array中找到一个数，交换之后使得两个array的和相同
        => use a map
    - [x] 是给两堆Interval {start, end},  每一堆里面的Interval是没intersection.  第一个问题是 求两堆 的交集。第二个问题是  求两堆的合集。 要求返回的结果里的Interval是没intersection。
        ```java
        private static List<int[]> intersection(int[][] a, int[][] b) {
            int na = a.length, nb = b.length;
            Arrays.sort(a, Comparator.comparingInt(e -> e[0]));
            Arrays.sort(b, Comparator.comparingInt(e -> e[0]));

            List<int[]> inters = new ArrayList<>();
            int i = 0, j = 0;
            while (i < na || j < nb) {
                if (i == na) {
                    j++; break;
                } else if (j == nb) {
                    i++; break;
                }
                int[] curra = a[i], currb = b[j];
                if (curra[1] < currb[0]) {
                    i++;
                } else if (curra[1] <= currb[1]){
                    int left = Math.max(curra[0], currb[0]);
                    int right = Math.min(curra[1], currb[1]);
                    inters.add(new int[]{left, right});
                    i++;
                } else if (curra[0] > currb[1]) {
                    j++;
                } else {
                    int left = Math.max(curra[0], currb[0]);
                    int right = Math.min(curra[1], currb[1]);
                    inters.add(new int[]{left, right});
                    j++;
                }
            }
            return inters;
        }

        private static List<int[]> union(int[][] a, int[][] b) {
            int na = a.length, nb = b.length;
            Arrays.sort(a, Comparator.comparingInt(e -> e[0]));
            Arrays.sort(b, Comparator.comparingInt(e -> e[0]));

            List<int[]> merge = new ArrayList<>();
            int i = 0, j = 0;
            int[] curr = a[0];
            while (i < na || j < nb) {
                if (i < na && curr[1] >= a[i][0]) {
                    curr[1] = Math.max(a[i++][1], curr[1]);
                } else if (j < nb && curr[1] >= b[j][0]){
                    curr[1] = Math.max(b[j++][1], curr[1]);
                } else {
                    merge.add(curr);
                    curr = (j == nb || i < na && a[i][0] < b[j][0]) ? a[i] : b[j];
                }
            }
            merge.add(curr);
            return merge;
        }
        ```
    - [x] Given an array, return kth most frequent element
         => use a Map: num -> count, and then squash them into a priority queue.
    - [x] N 个朋友去饭店吃饭，结账时需要平摊吃饭的开销，然而每个人实际付的钱是不平均的，比如，输入是每个人实际付的钱array [5, 10, 12, 15, 3], 求写代码，算出来每个人要给其他人多少钱，才能平摊开销。
        按照我上面的例子，每个人的平均开销应该是（5+10+12+15+3）/5 =9，如果这五个人分别用A，B，C，D，E表示。那么，A要付1刀给B. A要付3刀给C，E要付6刀给D. 
        Follow Up 求最少transaction使得互相之间不欠钱 => LC 465
        ```java
        List<int[]> split(int[] pay) {
            int n = pay.length;
            int sum = 0;
            for (int i = 0; i < n; i++) sum += pay[i];
            int each = sum / n;
            for (int i = 0; i < n; i++) pay[i] -= each;

            List<int[]> result = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if (pay[i] == 0) continue;
                int j = i + 1;
                while (pay[j] * pay[i] > 0) j++;
                result.add(new int[]{i, j, pay[i]});
                pay[j] += pay[i];
                pay[i] = 0;
            }
            return result;
        }
        ```   
    - [x] 序列化去序列化二叉树，要求越省空间越好，value是26个字母，用Byte存，5个bit就够存，剩下用2个bit存是否有左子树柚子树
        ```java
        private int pos = 0;
        private List<Byte> serialize(TreeNode root) {
            if (root == null) return new ArrayList<>();

            byte val = (byte)(root.val - 'a');
            if (root.left != null) val |= 0b100000;
            if (root.right != null) val |= 0b1000000;

            List<Byte> result = new ArrayList<>();
            result.add(val);
            result.addAll(serialize(root.left));
            result.addAll(serialize(root.right));
            return result;
        }

        private TreeNode deserialize(List<Byte> data) {
            if (data.isEmpty()) {
                return null;
            }
            byte val = data.get(pos++);
            TreeNode root = new TreeNode((char)((val & 0b11111) + 'a'));
            if ((val & (1<<5)) > 0) root.left = deserialize(data);
            if ((val & (1<<6)) > 0) root.right = deserialize(data);
            return root;
        }

        public static class TreeNode {
            char val;
            TreeNode left;
            TreeNode right;
            TreeNode(char x) { val = x; }
        }
        ```  

- system design
    - [设计uber](https://www.youtube.com/watch?v=umWABit-wbk&t=1293s)
    - [x] design youtube
    - [x] 设计Instagram, ex. upload photo,  get feeds等等
    - 设计一个expedia
    - 设计monitor(比如cloudwatch)系统
    - DesignDropbox 所有的System Design会问的都会问 (storage/scale/requirements etc) 会特别问如何解决 conflicts/concurrency (记得看看lamport clock) 然后要想想存data本身跟存储meta data之间怎么协调
    - heatmap service. 自己定义输入输出，然后就是返回当前driver在地图上的密度。    
    - design Amazon 商品详情页下的 people also brough these items
    - 设计一个uber eats的menu storage system。当然还设计一些如何把这个system应用在整个product中的问题。
    - 设计一个高并发的在线售票系统，从user case，QPS，前端，到database全说了一遍。followup：如果售票系统还要加个新功能，用户选座位时候可以hold 5分钟，在这个时间段其他用户看这张票是sold out，整个系统该怎么改？
    - design ticket master，问题很多。关键点应该就是如何支持秒杀
    - [x] design rate limiter.
    - [x] tiny url
    - [x] Design Whatsapp
    - [x] 设计一个即时通讯系统，类似于微信这样。
    - [x] design uber
    - [x] hotel booking system
    - [ ] best seller page of Amazon. 
    - [ ] design heat map
    - [ ] design uber eat app. 打开以后显示地图与附近n个商家。讨论app跟server应有哪些api，一次传送多少商家比较合理，如何分地理区，资料库table该如何设计，如何scale，single point failure。面官应该就是做这的，特别熟，节奏都是他主动带着走，他问一个功能或情境，我回答。最后问我如果server全挂了怎么办，我说不管配置多少master-slave全挂嘛？他说是，我说那无解啦。他说没错，他们前几周才刚遇到过.
    - design 一个online 游戏，自己任意选一个游戏，聊infra，聊software设计，给state转换，给server的proto
    - 设计地图, 你可以滑动地图, 你可以放大/缩小地图.
    - 设计一套一个车子和总台的消息交换系统
    - 设计twitter
    - design a system generate dashboard for showing uber driver conversation rate
    - design 一个飞机撞预测预警系统
    - design request id generator
    - 实现星际争霸网络版
- Behavior
    - 怎么带junior
        - 1:1 meeting: project progress, his interest, his career path
            - info upside decision, new opportunities 
        - a few stages: 
            1. a well defined mid-size tasks to get familiar with code base and tools & review code
            2. solicit ideas from him & critical thinking
            3. help him collect with other people related to this project & set up his image with other groups, ie. service owner.
    - 怎么解决conflict
        - 
    - 如何处理建设性意见
    - 做过最难的project
        - Ebert2.0
            - downstream/upstream difficulty
                1. migrate 340m reviews + 1B review category: data consistency, no down time
                2. data pipeline SLA
                3. mutation publisher reformulate 
                4. support old api and rails ActiveRecord model
            - part of work depend on other team
                - sync with mussel way earlier before traffic switch
                - push ML infra to migrate
    - 过去得到的负面反馈 后来怎么解决
    - 我给别人批代码的时候一般看中什么
    - 2个你喜欢做的工作 2个你不喜欢做的工作
    - 为什么uber，为什么要跳槽，平常用什么
    - what's the biggest challenge in your daily job
    - most challenging project
    - how to mentor junior engineer
    - example of product failed before deadline
    - teamwork
    - weakness