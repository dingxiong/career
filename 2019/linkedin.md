2019/2/1 - 2019/4/29
- TODO
    - [read atlas](https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=510610&extra=page%3D73%26filter%3Dauthor%26orderby%3Ddateline%26sortid%3D311%26sortid%3D311%26orderby%3Ddateline)
- coding
    - [x] LC easy: 53, 69, 100, 170, 198, 270, 339, 716
    - [x] LC medium: 3, 33, 46, 50, 56, 114, 127, 142, 150, 152, 156, 187, 200, 213, 236, 243, 244, 245, 254, 277, 
    - [x] LC hard: 23, 42, 72, 149, 265, 272, 352, 715,
    - [x] LC 189(in place)
    - [x] LC 205. follow up: input是 a list of words，考虑两种条件，第一种是存在两个word是isomorphic就返回true，第二种是任意两个word都为isomorphic才返回true
    - [ ] LC 341(不准用额外空间), 460, 
    - [ ] LC 671, 416, 973, 895, 776, 698, 364, 380, 381, 384, 432, 605, , 611, 366, 612
    - [ ] LC 256 followup， 如果是k种颜色呢？
    - [ ] LC 381 follow up 多线程
    - [ ] LRU Cache
    - [ ] LC 68 输入的除了行宽还有一组字体大小，要求选择最大可用的字体，并输出排版结果。最大可用字体的意思就是，例如有一个单词特别长，abcdefghijklmn，这个单词不能拆到两行里面去
    - [x] 打印二叉树每一层的叶子节点
    - [x] 给一个类，创建时给个字符串，要求类里写一个方法，给两个字母，算在字符串中最短距离
    - [ ] 给一个string返回最长回文子串
    - [ ] 给一个数组，求有多少子集合等于一个给定值
    - [ ] 在一个递增的数组中，中间有若干数字丢失了，问你第K个不见的数字是多少。。例如【2,3,5,8,9】，k=1 返回4， k=3 返回7
    - [ ] 给个String，判断是不是个valid number。看着很简单，但edge case还挺多的
    - [ ] 写一个数据结构 支持 add(key), remove(key), removeRandomKey() 并且每个操作都是 O(1)
    - [ ] 实现一个interface 支持两个method addNumber(int from, int to) 会create一个Interval; getTotalLength: return current cover length 重复的只能算一次; 有点像range module.
    - [ ] 写一个多线程safe的queue. put（T t）如果q满了要等在那里直到有空间put. get（）如果q是空的要等在那里直到有东西get. multiput（List《T》 t）put多个element 如果任意时刻q满了要等在那里直到有空间put
    - [x] 给了3个java class， 一个streamer reader class, 一个stream object class, stream object 有rank. 写一个cache, 如果reach一定capacity，pop出rank最小的。
        ```java
        public class RetainBestCache<K, T extends Rankable> {
            int entriesToRetain;
            HashMap<K, T> map = new HashMap<K,T>();
            DataSource<K,T> ds;
            TreeMap<T, List<K>> rankMap = new TreeMap<>();
            
            /* Constructor with a data source (assumed to be slow) and a cache size */
            public RetainBestCache(DataSource<K,T> ds, int entriesToRetain) {
                this.ds = ds;
                this.entriesToRetain = entriesToRetain;
            }
            /* Gets some data. If possible, retrieves it from cache to be fast. If the data is not cached,
            * retrieves it from the data source. If the cache is full, attempt to cache the returned data,
            * evicting the T with lowest rank among the ones that it has available
            * If there is a tie, the cache may choose any T with lowest rank to evict.
            */
            public T get(K key) {
                if (map.containsKey(key)) return map.get(key);
                else {
                T data = ds.get(key);
                long rank = data.getRank();
                map.put(key, data);
                rankMap.putIfAbsent(rank, new ArrayList<>());
                rankMap.get(rank).offer(key);
                if (map.size() > entriesToRetain) {
                    List<K> lowestRank = rankMap.firstEntry().getValue();
                    int n = lowestRank.size();
                    K k = lowestRank.get(n-1);
                    map.remove(k);
                    if (n > 1) {
                    lowestRank.remove(n-1);
                    } else {
                    rankMap.popFirstEntry();
                    }
                }
                }
            }

            /*
            * For reference, here are the Rankable and DataSource interfaces.
            * You do not need to implement them, and should not make assumptions
            * about their implementations.
            */
            public interface Rankable {
                /**
                * Returns the Rank of this object, using some algorithm and potentially
                * the internal state of the Rankable.
                */
                long getRank();
            }

            public interface DataSource<K, T extends Rankable> {
                T get(K key);
            }
        }
        ```
- design 
    - [design Top K article shared in 5 mins 1 hour 1 day](https://www.bookstack.cn/read/system-design/cn-bigdata-heavy-hitters.md)   
    - TinyUrl
    - [Design calendar](https://www.jiuzhang.com/qa/3498/) 可以schedule meeting和invite别人
    - Design Hangman Game
    - Distributed Database System 
    - Key Value Store
    - 设计二级好友三级好友
    - delay scheduler
    - 设计trending linkedin share post
    - statistics aggregation system
    - Log Analyzer. 有很多Machine在跑，有各种Log， 非常多，怎么做一个系统收集这些log 并且进行处理，这里重点考虑scalability 和 performance
    - 给定可用内存的 mini Kafka， 重点考察内存中数据怎么存
    - 设计一个系统监督和管理领英第三方API的流量
    - 一个Espresso database设计过程中怎么处理hot point的问题，和key的rebalance有关系
    - 全球有好多个data center，如何检测用户的异常登录（例如今天还在亚洲明天就来美洲了），如何防止DoS攻击，不同center怎么样共享学习到的信息——例如黑名单什么的。
    - [高频] Amazon Product Page. 分析表之间的关系
- behavior
    - 为毛linkedin,有什么linkedin阔以改进的地方。你的简历go back5 year，都干了什么大事。
    - talk about Virtual Memeory 
    - https://business.linkedin.com/content/dam/me/business/en-us/talent-solutions/resources/pdfs/linkedin-30-questions-to-identify-high-potential-candidates-ebook-8-7-17-uk-en.pdf