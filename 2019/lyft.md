2018/11/17 - 2019/5/28 (page 1-600)
- TODO
    - read pdf mj
- coding
    - [x] LC easy: 42, 53, 157
    - [x] LC medium: 8 133 200, 238, 287, 300 347 735 935
    - [x] LC hard: 158 239 642 759
    - [ ] Regex match: 包括 `. ? * +`
    - [ ] post-order 遍历，非递归 
    - [ ] You are given a sorted without any duplicate integer array, can you write code to tell me what is the Nth missing integer.
    - [ ] 给你两个iterators， 实现一个iterator, 返回两个中的共同元素
    - [ ] 设计excel，先讲思路，其实主要是处理dependency的问题，比如A1=B1+C1, B1=D1+1这种情况如何处理
        => topological sort. 需要自己 parse string
    - [ ] N个string合并成一个，要保留原来string里面字符的顺序。求所有可能组合. merge(['AB', 'C']) => ['ABC', 'ACB', 'CAB']. merge(['AB', 'CD']) => ['ABCD', 'ACBD', 'ACDB', 'CABD', 'CADB', 'CDAB']
    - [ ] LC 158 变形
        ```cpp
        vector<int> fetch(int pageId): this function returns the items in given page, page size is fixed (say 5).

        Implement a Fetcher class which has a function:
            vector<int> fetch(numOfItems): returns number of items.
        using above api.

        sample:
        fetch(0): return [0,1,2,3,4]
        fetch(1): return [5,6]
        Fetcher class:
        fetch(2): return [0,1]
        fetch(1): return [2]
        fetch(4): return [3,4,5,6]
        ```
    - [x] 实现一个有版本的key-value store. 类似于下面的实现
        ```cpp
        // 这是网上看到的，用 unordered_map<string, vector<int, string>> 会更好一些
        class VersionKeyValueStore {
            std::unordered_map<std::string, std::map<int, std::string>> m_map;
            void SetValue(const std::string& key, const std::string& value) {
                if(m_map.find(key) == m_map.end()) m_map[key][0] = value;
                else {
                    int version = m_map[key].size();
                    m_map[key][version] = value;
                }
            }
            
            std::string GetValue(const std::string& key) {
                if (m_map.find(key) != m_map.end()) {
                    int latestVersion = m_map[key].size();
                    return m_map[key][latestVersion-1];
                }
                return "";
            }
            
            std::string GetValueWithVersion(const std::string& key, int version) {
                if (m_map.find(key) != m_map.end()) {
                    if (m_map[key].count(version) == 1 ) {
                        return m_map[key][version];
                    }
                }
                return "";
            }
        };
        ```   
- system design
    - [x] 设计web crawler.
    - [x] 设计delay queue
    - [ ] Design music sharing system
    - [ ] 设计一个Lyft 的coupon 系统
    - [x] design job scheduler
    - [ ] 设计google和lyft两个的叫车服务，主要是eta, 和价格。 先设计google的，怎么连接到lyft，然后是设计lyft方面自己的服务。
        狗哥地图搜索，有一个功能，显示红车的价格和估计时间。问如何设计狗哥的这个功能，然后又问如何设计红车的系统支持这个功能
    - [x] design twitter
    - [ ] 实现yelp的typeahead recommendation
    - [ ] Design Lyft driver and rider matching system
    - [ ] design donation website
        主要是看如何不多次 收信用卡上的钱
    - [ ] 设计一个wikipedia的爬虫，把所有page都存下来. 站点内容会变
- behavior
    - [ ] 介绍the most proud project
