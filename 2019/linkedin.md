2019/2/1 - 2019/5/10
店面：205, implement Arrays.sort(). I chose to implement quick sort algorithm

- TODO
    - [read atlas](https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=510610&extra=page%3D73%26filter%3Dauthor%26orderby%3Ddateline%26sortid%3D311%26sortid%3D311%26orderby%3Ddateline)
- coding
    - [x] LC easy: 53, 69, 100, 136, 170, 198, 256 270, 339, 605 671 716
    - [x] LC medium: 3, 33, 46, 50, 56, 114, 127, 142, 150, 152, 156, 187, 200, 213, 236, 243, 244, 245, 254, 277, 341 364, 366 380, 384 416 516 611 612 698 776
    - [x] LC hard: 23, 42, 65 72, 146, 149, 265, 272, 352, 381, 432 460 715 895 973
    - [x] LC 189(in place)
    - [x] LC 205. follow up: input是 a list of words，考虑两种条件，第一种是存在两个word是isomorphic就返回true，第二种是任意两个word都为isomorphic才返回true
    - [ ] 给一个数组，求有多少子集合等于一个给定值
    - [ ] 实现线程池/ExecutorService，跑需要延时的任务。面试官说答得挺好
    - [ ] Implement Bounded Blocking Queue
    - [x] 写一个多线程safe的queue. put（T t）如果q满了要等在那里直到有空间put. get（）如果q是空的要等在那里直到有东西get. multiput（List<T> t）put多个element 如果任意时刻q满了要等在那里直到有空间put
        ```java
        BlockingQueue<T> que = new ArrayBlockingQueue<>(capacity);
        void put(T t) {
            que.put(t);
        }
        T get() {
            que.take();
        }
        void multiPut(List<T> ts) {
            for (T t : ts) que.put(t);
        }
        ```
    - [x] 在一个递增的数组中，中间有若干数字丢失了，问你第K个不见的数字是多少。。例如【2,3,5,8,9】，k=1 返回4， k=3 返回7
        ```java
        int findK(int[] a, int k) {
            int n = a.length;
            for (int i = 1, mis = 0; i < n; i++) {
                mis += a[i] - a[i-1] - 1;
                if (mis >= k) return a[i] - (mis - k) - 1;
            }
            return a[n-1] + (k - mis);
        }
        ```
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
    - [x] design a class to insert interval [from, to), and get the total covered length. 重复的只能算一次
        ```java
        private TreeMap<Integer, Integer> inters = new TreeMap<>();
        private int totalLen;

        /** Adds an interval [from, to) into an internal structure. */
        void addInterval(int from, int to) {
            Integer low = inters.floorKey(from);
            Map<Integer, Integer> subMap;
            if (low == null) subMap = inters.headMap(to, true);
            else subMap  = inters.subMap(low, true, to, true);
            Set<Integer> keys = new TreeSet<>(subMap.keySet());
            for (int k : keys) {
                int v = inters.get(k);
                if (intersect(k, v, from, to)) {
                    from = Math.min(from, k);
                    to = Math.max(to, v);
                    inters.remove(k);
                    totalLen -= v - k;
                }
            }
            inters.put(from, to);
            totalLen += to - from; System.out.println(inters + "; len:" + totalLen);
        }

        int getTotalCoveredLength() {
            return this.totalLen;
        }
        ```    
- design 
    - [x] [xxxx] [design Top K article shared in 5 mins 1 hour 1 day](https://www.bookstack.cn/read/system-design/cn-bigdata-heavy-hitters.md)
        - step 1: make it work in a single machine with unlimited memory: use a `List<(element, timestamp)>` and `TreeMap<element, count>` 
        - step 2: make it work in a single machine with limited memory:  Lossy counting algorithm, sticky sampling algorithm
    - [x] TinyUrl
    - [x] [Design calendar](https://www.jiuzhang.com/qa/3498/) 可以schedule meeting和invite别人
        - schemas: 
            - users
            - events(id, owner, type(one time, recurrent, etc), event_start_time, event_end_time, location, ....)
            - event_users(id, event, user_id, status(yes/no/maybe), ...)
        - Demon process maintain a priority queue (event_id, event_start_time) storing the events happen in next hour. 
            - demon listens to mutations published by `events` table
            - demon scan events table every 40 minutes.
        - follow up
            - scale PQ: shard it by event_id
            - failure recover: scan events table at reboot
    - Design Hangman Game
    - Design Linkedin
    - [x] Distributed Database System
    - [x] Key Value Store
    - [x] 设计二级好友三级好友. 给定一个int[] getFridend(int user)，O(1) complexity, 求两个users 是不是一级联系，二级联系和三级联系。先在local解，后来问图很大，怎么scale到多个machine上
        - read paper https://engineering.linkedin.com/real-time-distributed-graph/using-set-cover-algorithm-optimize-query-latency-large-scale-distributed
            - key points: greedy set cover algorithm
        - steps
            1. single machine solution: save edges in mysql directly. and do BFS on the db
            2. cluster solution: graph db partitioned on multiple machines; cache to store direct, second connections; 
                - cache initialization/miss: greedy set cover algorithm
    - [x] delay scheduler 
        - https://soulmachine.gitbooks.io/system-design/cn/task-scheduler.html
    - 设计trending linkedin share post
    - [ ] OOD，设计高层电梯调度系统。注意是高层。
    - statistics aggregation system
    - [ ] 对于query 高效的返回某个key在数据库中出现的所有位置, 出现次数是否大于k
    - [x] centralized logging. Log Analyzer. 有很多Machine在跑，有各种Log， 非常多，怎么做一个系统收集这些log 并且进行处理，这里重点考虑scalability 和 performance
    - [x] 给定可用内存的 mini Kafka， 重点考察内存中数据怎么存
        - version 1: single machine in memory: `Map<topic, List<Message>>` and `Map<Consumer, Map<topic, offset>>` producer `add(topic)`, consumer `take(topic)`.
        - version 2: 
    - [x] 设计一个系统监督和管理领英第三方API的流量 收集host的1second，1minute，1hour metrics。如何scale，如果是10000 hosts怎么收集。
        - Log Shipper, Log index, storage, UI,
        - ELK Stack: Elasticsearch, Logstash, Kibana
        - resources
            - http://artemstar.com/2017/03/11/logging-system-pipeline/
            - datadog architecture 
                - https://docs.google.com/presentation/d/1yxcg4DdC-Uss1zh_lhtSWXICn7g-5udJN0XaV2oRaj4/pub?start=false&loop=false&delayms=3000&slide=id.g177c50456_018
                - https://docs.datadoghq.com/graphing/functions/

    - 一个Espresso database设计过程中怎么处理hot point的问题，和key的rebalance有关系
    - 全球有好多个data center，如何检测用户的异常登录（例如今天还在亚洲明天就来美洲了），如何防止DoS攻击，不同center怎么样共享学习到的信息——例如黑名单什么的。
    - [xxxx] Amazon Product Page. 在SQL里面一个产品有多个图片多个价格的话怎么设计数据库。然后后台提取数值render到页面上得时候，class怎么设计，服务器怎么安排之类的。还有如何suggest product。
- behavior
    - 为毛linkedin,有什么linkedin阔以改进的地方。你的简历go back5 year，都干了什么大事。
    - talk about Virtual Memory 
    - https://business.linkedin.com/content/dam/me/business/en-us/talent-solutions/resources/pdfs/linkedin-30-questions-to-identify-high-potential-candidates-ebook-8-7-17-uk-en.pdf