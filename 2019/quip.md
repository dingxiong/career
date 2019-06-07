- coding
    - [x] LC easy 746
    - [x] LC medium 240 362 740
    - [x] LC 354
    - [ ] LC course schedule 螺旋打印 good number, 761 17 285
    - [ ] exam room 那道 LC 855. 有两个api add student 和remove student
    - [ ] auto complete. follow up可以添加很多feature，比如apple juice, 怎么输入jui就返回apple juice。
        怎么根据input "lun pla" return "lunch plan", 甚至怎么设计 input "pla" return "lunch plan"
    - [x] 用Node class写个class 叫 sorted circular singular linked list 然后写一下append method. 
        follow up 如果append的时候不能改原来的任何Node改怎么做（Head的corner case)
        ```java
        Node insert(Node root, int val) {
            Node curr = root;
            while ((curr.next.val < val || root.val > val) && curr.next != root) {
                curr = curr.next;
            }
            Node tmp = curr.next;
            curr.next = new Node(val);
            curr.next.next = tmp;
            return curr.next.val < root.val ? curr.next : root;
        }
        ```
    - [x] 给你一个排序好了的circular linked-list 的其中一个node（这个可以是任何node），请你insert一个新的node并返回这个node
    - [ ] json转dict, dict转json
    - [ ] json 转 string
    - [x] RW lock
    - [ ] Good number (a^3+b^3=c^3+d^3 where (a,b) != (c,d)). Find all GNs <= N (lc article?)
    - [x] "011000101101" find min length that contains k 1s
    - [x] Given a list of numbers containing duplicates, return if you can sum any of them equal to k. Each number can only use once.
        => if all numbers are positive => dp; otherwise, DFS.
    - [x] BST二叉树给一个节点返回下一个比它大的节点
        ```java
        private Integer prev, curr;

        private Integer nextNode(TreeNode root, TreeNode node) {
            prev = null;
            curr = null;
            helper(root, node);
            return curr;
        }

        private void helper(TreeNode root, TreeNode node) {
            if (root == null) return;

            helper(root.left, node);
            if (curr != null) return;
            if (prev != null) {
            curr = root.val;
            return;
            }
            if (root.val == node.val) prev = root.val;
            helper(root.right, node);
        }
        ```
    - [x] 检查有向图找环
    - [x] 就是给你一堆rectangle 只有包含或者分离，求最多几个叠在一起. 
        1. 类似 LC skyline. 1. sort in x coordinate. 2 scan from left, maintain a pq of PQ(y1,y2), then scan this pq => O(n^2).
        2. sort in x coordinate. DP relation: f(i) = max{f(j) + 1} if s_i contains s_j => O(n^2)
    - [x] 翻转字符串，和利扣要唔要类似，但是字符串的分隔符不只是空格，eg. "cat_dog/bird" -> "bird_dog/cat", 输入是（String str, List<Character> dilimiters），
        => 因为dilimiter顺序不变，所以我先遍历了一遍找出dilimiter的顺序，然后从后往前遍历字符串并依次添加dilimiter
    - [x] 二叉树的上下左右view
        => 用一个2d map: (x, y) -> val. 然后BFS。比如从上看就是对于x相同的点，y小的应该覆盖y大的。但是，对于 (x,y)相同的node,到底该怎么取呢？
    - [x] 上机，给一个很大的文件，有一些文件名和id，根据搜索次数排序输出top5，要求速度快，并给这个系统想出一些别的新功能
        => scan this file and get a `map<file, count>`, then use a size=5 pq.
    - [x] 给好多个list，找到所有list中只出现在一个list里的元素，返回含有这样元素的list
        => build a reverse index: `Map<Item, Set<list_id>>`.
    - [x] 斐波那契。。就是换成三个数 1, 1, 1, 3, 5, 9
    - [x] given a list of words, and for each word, find the prefix substring of each word, which is not a prefix substring of other words.
    - [x] 给你一个string,形式是b*a*c，然后让你找a的个数. 比如 bbbbbaaaaaccccc, 那么个数就是5 
        => if mid = b, low = mid + 1. if mid = c, high = mid -1; if mid = a, then solve left part in lgN and right part lgN. 
    - [x] 给一大堆英文单词dictionary，从所有2个字母的单词，每次可以在它前面或者后面加一个字母，新的单词也要在dictionary里，找到最长的链。
        因为dictionary里有25w个单词，我跑的时候codepad就报内存不足，但是java的garbage collection应该不会耗用太多内存。面试官让我就从"at"开始搜，很快就返回了结果。
        ```java
        int findLongestChain(Set<String> words) {
            Set<String> starts = words.stream().filter(s -> s.length() == 2).collect(Collectors.toSet());
            int maxLen = 0;
            Map<String, Integer> cache = new HashMap<>();
            for (String s : starts) maxLen = Math.max(maxLen, helper(new StringBuilder(s), words, cache));
            return maxLen;
        }

        int helper(StringBuilder start, Set<String> words, Map<String, Integer> cache) {
            if (cache.containsKey(start.toString())) return cache.get(start.toString());
            int len = 1;
            for (char c = 'a'; c <= 'z'; c++) {
                start.insert(0, c);
                if (words.contains(start.toString())) len = Math.max(len, 1 + helper(start, words, cache));
                start.deleteCharAt(0);
            }
            for (char c = 'a'; c <= 'z'; c++) {
                start.append(c);
                if (words.contains(start.toString())) len = Math.max(len, 1 + helper(start, words, cache));
                start.deleteCharAt(start.length()-1);
            }

            cache.put(start.toString(), len);
            return len;
        }
        ```