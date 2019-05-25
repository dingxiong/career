- 2019/4/24
- coding
    OA
    - [x] LC easy: 937
    - [ ] LC 
    - subsets
    - implement trie
    - 26进制转换
    - next greater element
    - 给定从0到999999的数字，要求翻译成英文表达，比如12，翻译为“twelve”
    - [ ] 有多少个 长度为num 且 不同char数量也为num的substring. input: String s. output: int, 输出数量
    - 实现一个heap
    - [ ] What happens when your request is https /tls instead of http?
    - [ ] 一堆城市被铁路连着，然后铁路断了几个，修每个铁路的cost不一样，问最小cost连起来所有的城市。minmum spanning tree, union find + heap解。
    onsite
    - [ ] LC 545 716 160 20 322 273 472 1029 138 49 73 642 36 653 36 206 261
    - [ ] LC word break, word break II, max stack, Intersection of Two Linked Lists, LRU,
    - [ ] longest palindrome substring 、most common words
    - 有一个map，存着歌曲名和播放量，现在在开派对，每来一个人，要把ta的歌单加到map里去，每个人的歌单也是歌曲名和播放量组成，要求实现下一首的功能，
        下一首要找出当前播放量最多的歌 说白了就是会不断更新map，然后还要根据map的value排序，只想出用heap做出O(N)的方案，不知道有没有更好的
    - [ ] 一个array（姑且称为MyArray），支持两个API，set(index, value)，get(index)，已知输入中会有很多连续的值出现（例子：[7, 7, 7, 5, 5]），
        需要这个MyArray内部将连续的值都用更小的空间表示（比如三个7只占用一个空间）。答得不太好 总想用Map去存外部坐标和内部坐标的对应关系，后来小哥说没必要get是O(1)时间，
        最后就只用了一个linkedlist of Pair(start, end, value)去存的.
    - [x] 给一个输入字母的stream，然后写一个支持返回第一个没重复过的char
        ```java
        Optional<Character> nonRepeat(Stream<Character> input) {
            Map<Character, Integer> counts = new LinkedHashMap<>();
            input.forEach(c -> {
                counts.put(c, counts.getOrDefault(c, 0) + 1);
            });
            return counts.entrySet().stream().filter(e -> e.getValue() == 1).first();
        }
        ```    
- system design
    - 只设计一个功能，follow/unfollow一个歌手
    - 设计文件系统
    - 设计停车场
    - 设计一个股票系统 输入：无限正整数stream 每秒输入一个 求当前时间前n秒的最大最小值
    - 提前输入设计 google suggestion
- BQ
    - [ ] [x2] 赶deadline的经历，
    - [ ] [x3] challenge project
    - [ ] 跳出comfort zone的经历
    - [ ] 帮助别人
    - 最挑战的事情，队友不符合期望的事情，信息不够的事情
    - something you have done