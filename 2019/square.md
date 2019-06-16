## square
2018/6/27 - 2019/6/14
- coding
    - [x] LC easy 415
    - [x] LC medium 13 15 17 79 91 98 105 139 210 211 271 284 288 289 355 573 635 981
    - [x] LC hard 57 68 72 282 465 588
    - [ ] LC 128 146 621 127 699 969   
    - [x] 个组合, 里面是[A, B], [B, A], [C, D], [D, E], [E, C] 这样的一对对, 让找所有能环起来的组合:  ([A, B], [B, A] 能环起来,  [C, D], [D, E], [E, C] 也能环起来)
    - [x] 第一轮写程序按7段数码管格式打印出数字, 例如7就要输出
        --
         |
    - [x] 实现简单的画板程序，比如画布是二维矩阵， 实现drawLine （可以是斜着的），然后实现undo操作之类的
        ```java
        input: int mat[][]
        Map<Integer, Map<Integer, Integer>> counts // (x, y) => counts.  how many times a cell has been painted
        void draw(int x1, int y1, int x2, int y2) {
            // calculate slop first, and then scan the line to find out which cells should be painted.
            // update `counts`
        }
        void undo(int x1, int y1, int x2, int y2) {
            // reverse the process of draw
        }
        ```
    - [x] 給定以下example
        patent1 : jim : patent2
        patent 2 : john, jack, lisa
        patent 3 : jim, lisa : patent 2, patent 1
        patent 5 : jack : patent 3

        [patent 3 : jim, lisa : patent 2 ] 這行表示, patent3的作者是jim和lisa, 同時, patent 3 參考了patent 2

        問題 : 如果給出兩個人名, 請把這兩個人之間的patent關係列出來
        ex : [jim, lisa] => patent 3,    [jack, lisa] => [patent 5, patent 3], [patent 5, patent 3, patent 2]
        ```java
        Map<Integer, Set<String>> patentToPeopleMap;
        Map<String, Set<Integer>> peopleToPatentMap;
        Map<String, Set<String>>> patentDependency; 
        ```
    - [x] 设计一个class twitter(object)，比如给你一句话：
        # "it was the best of times it was the worst of times"
        你需要让code学会was这个词是跟在it后面的
        ex：
        # "it" -> "was"
        # "was" -> "the"
        # "the" -> "best" 50%
        # "the" -> "worst" 50% （这个例子中the后面跟的词有两种情况，因此你的代码要记住这俩词，一会生成自己的句子的时候要随机生成）
        本人建了一个hashmap，然后被要求写了三个func：
        1.  def insert(self, string): （#insert all single words into hashmap）
        2.  def getWord(self, search): （ # 就是比如输入"it" -> 我get出"was"； 分两种情况讨论，一种是只有一个固定答案，另一种就是上面说的需要随机生成）
        3. def formSentence(self, string, num): （#num是你想生成一个有几个词的句子，string是句子的第一个词是啥；return一个长句子，不过不care真正的英语语法，不care标点）
    - [x] 写一个可以查看各种version的map。input：（x，a, 10）, (y, b, 20), remove(x, 30). 这个操作就是先放了一个key为x的文件a在time=10的时候；然后呢在time=20的时候放了key为y的文件b；
        然后在time=30的时候remove掉x这个key。所以当你在get（x，15），15是时间点，你就可以得到文件a，但是get（x，35）就返回null因为已经删除了 同理get(y, 10) = null, get(y, 25) = b
        ```java
        class File {
            Long startTs, endTs;
            String fileContent;
        }
        Map<Integer, List<File>> versionMap;

        String get(int key, long ts) {
            if (!versionMap.containsKey(key)) return null;
            List<File> files = versionMap.get(key);
            int k = Collections.binarySearch(files, Comparator.comparingLong(f -> f.startTs));
            if (k > 0) return files.get(k).fileContent;
            else {
                k = - k - 1;
                if (k == 0 || files.get(k-1).endTs < ts) return null;
                else return files.get(k-1).fileContent;
            }
        }

        void put(int key, String file, long ts) {
            versionMap.putIfAbsent(key, new ArrayList<>());
            List<File> files = versionMap.get(key);
            if (files.size() > 0 && files.get(files.size()-1).endTs == null) {
                files.get(files.size()-1).endTs = ts;
            }
            files.add(new File(ts, null, file));
        }

        void remove(int key, long ts) {
            if (!versionMap.containsKey(key) || versionMap.get(key).size() == 0) return;
            List<File> files = versionMap.get(key);
            if (files.get(files.size()-1).endTs == null) files.get(files.size()-1).endTs = ts;
        }
        ```
    - [x] The 2-player game of Drawdown is played with a board made up of N groups of stones. The stones at index 0 belong to player 1, the stones at index N - 1 belong to player 2, 
        and the stones at indices [1..N-2] have no owner. At the start of each game a board and a list of k moves are provided. Each move is a list of N integers, which represent the
        number of stones the move adds/removes from the board at each index. All moves reduce the total number of stones on the board. Moves can be re-used, but a move can no longer 
        be performed if doing so would reduce the number of stones in any group below 0.
        After no more moves can be completed, the player with more of their own stones on the board is the winner. In the case of a tie, player 2 wins.
        题目；. From 1point 3acres bbs
        1. 给定一个board, 判断是不是player one win. 
        2. 给定board 和List<int[]> moves,  enumerate all the possible board moves and then print out the number of times Player 1 wins and Player 2 wins
        ```java
        boolean win(int[] stones, int[][] moves) {
            return winHelper(stones, moves, true);
        }

        private boolean winHelper(int[] stones, int[][] moves, boolean isPlayerA) {
            int n = stones.length;
            boolean canMove = false;
            for (int[] m: moves) {
            if (canUseMove(stones, m)) {
                canMove = true;
                makeOrRestoreMove(stones, m, true);
                boolean otherWin = winHelper(stones, moves, !isPlayerA);
                makeOrRestoreMove(stones, m, false); // important. should restore board before return
                if (!otherWin) return true;
            }
            }
            if (!canMove) return isPlayerA ? stones[0] > stones[n-1] : stones[0] <= stones[n-1];
            return false;
        }

        private boolean canUseMove(int[] stones, int[] move) {
            int n = stones.length;
            for (int i = 0; i < n; i++) {
            if (stones[i] + move[i] < 0) return false;
            }
            return true;
        }

        private void makeOrRestoreMove(int[] stone, int[] move, boolean isMove) {
            int n = stone.length;
            for (int i = 0; i < n; i++) {
            stone[i] = isMove ? stone[i] + move[i] : stone[i] - move[i];
            }
        }
        ```
- System design
    - [ ] 设计 cache, 各种 policy(LRU, LFU...)
    - [ ] x6: hotel booking system, support booking, room searching
        - schemas
            - `hotels` (id, ..)
            - `rooms` (id, hotel_id, root_type, status)
            - `reservations` (id, user_id, hotel_id, room_id, check_in, check_out)
                1. in order to support booking multiple rooms at once, we can add a new `reservation_rooms` table
        - Api
            - `List<Room> search(area/city)`
            - `Reservation book(user_id, root_id, check_in, check_out)`
            - 
