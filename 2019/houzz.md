- coding
    - [x] LC easy 572
    - [x] LC medium 33, 49, 200, 227
    - [x] LC hard
    - [ ] LC 4, 10, 24, 25, 31, 43 48 123 174, 188, 743 65, 304, 341 759, 767 785
    - [ ] LRU follow up 問了假如 input很大怎麼辦
    - [ ] 写 quick sort
    - [ ] 给一个二叉树，每次print所有leaf，然后delete所有leaf，直到删掉root
    - [ ] [rainbow sort](https://starllap.space/2017/06/23/LintCode-Rainbow-Sort/)
    - [ ] 给一个string  a_b_c 或者 (a_b_c)_d_(e_f_g) 转换成binary tree
    - [ ] 给你一串字母string(lower case letter)，求出他在所有permutation里按字母顺序排列的序号，允许有duplication
    - [ ] 给一个range 1-n,如果n=5给出a = [2,3,1,4,5],b由a得出，从位于当前数字index后面的数中，数出比当前数字小的个数，所以b = [1,1,0,0,0]。然后现在知道b反推a
    - [ ] zigzag print out matrix
        [ 1 2 3   
          4 5 6 
          7 8 9] 
        result ==> 1 2 4 7 5 3 6 8 9
    - [x] 给n个字符数组，比如：
        {
        {'a', 'b', 'c'},
        {'d'},
        {'e', 'f'}
        }
        每次从每个数组取一个字符，生成一个combination
        比如上面例子的结果就是：ade, adf, bde, bdf, cde, cdf。
        然后next() function会被call输出这个combination
        上来说dfs生成所有结果，然后面试官说不行，内存会爆；
        ```java
        public class Iter {
            int[] pos;
            String[] words;
            int curr;

            public Iter(String[] words) {
                int n = words.length;
                pos = new int[n];
                this.words = words;
                curr = n-1;
            }

            public boolean hasNext() {
                return curr >= 0;
            }

            public String next() {
                int n = pos.length;
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < n; i++) {
                    sb.append(words[i].charAt(pos[i]));
                }
                curr = n - 1;
                pos[curr]++;
                while (curr >= 0 && pos[curr] == words[curr].length()) {
                    pos[curr] = 0;
                    if (--curr < 0) break;
                    pos[curr]++;
                }

                return sb.toString();
            }
        }
        ```   
- system design
    - [ ] Shorten URL System Design    
    - [ ] design一个search
    - 设计一个notify system. 给你一个API notify，call的时候会直接notify，然后给一大堆request，要求延时notify. 先设计整个Amazon alexa系统，然后做notification的OOD