seckcoder
BeAHost2019!
## common 
system design https://www.1point3acres.com/bbs/forum.php?mod=forumdisplay&fid=323&orderby=dateline&orderby=dateline&filter=author&page=1

## Facebook 
- coding
    - [FB Onsite 2019](https://docs.google.com/spreadsheets/d/1-9Jx6rgUj40xxEtJzRqmGkXoW1QBgsO4CipRMQV2mA8/edit#gid=1531713026)
    - LC 726, 314, 463, 
    - LC 246, 247
    - LC 3, 463
    - LC 158
    - LC 简易版 65（只允许数字 小数点 正负号）
    - 两两交换链表的node
    - For a cycle-linked list, which is sorted, given a node from this list and a target value,
        insert a new node after given node, to make sure the new list is still sorted. example1: 
        -> 1 -> 2 -> 3, given 2 and target value 3, insert 3 after 2, 
        new list is: -> 1 -> 2 -> 3 -> 3
    example2: -> 1 -> 2 -> 3, given 2 and target value 1, new list is: -> 1 -> 1-> 2 -> 3
    https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=517238&extra=page%3D24%26filter%3Dauthor%26orderby%3Ddateline%26sortid%3D311%26sortid%3D311%26orderby%3Ddateline
- system design
    - design instagram
    - 设计100K的web服务器到10K(1000qps)搜索服务器的最佳通讯方式，利用load balancer或者message queue来做
    - 设计类似利口的做题网站，每天可以提供若干次竞赛，用户需要注册之后登陆然后提交代码，关键是要快速列出ranking page



## Google
- coding
    - LC 777, 56, 334, 659, 41
    - 移动键盘和求二叉树最大和的层数
    - [x] 给一个字符串比如"a{b,c}{d,e}"，可能的输出有"abd","abe","acd","ace", 写一个function来实现。follow up 1：如果有"{}"嵌套的情况怎么处理，比如{b,d,{e,f}}, follow up 2: 如果括号不是成对出现怎么处理，比如 "a{b, d, {, c}", 结果有"ab","ad","a{","ac"。
    - [x] 给一个只有0和1的matrix, 1代表可以走，0代表blocked, 问从第一行任意位置开始走能不能走到最后一行。follow up 1: output the path, can be any path，follow up 2: 如果现在matrix里都是大于0的integer, 一开始的cost是0，每走到一个cell当前cost就加上那个cell里的数字，问从第一行走到最后一行最小cost。
    - [x] 一个boolean matrix, true代表可以走，false代表blocked，给定start point, end point，求从start到end的任意path
    - [ ] 应该是面经题，包装比较多。谷歌有m个data center, data center按顺序连成一串。每个data center都有n个机器，相邻data center之间的机器都是相连的，一个data center内部机器不会互相连接。现在有一个job需要完成，job从第一个data center开始，一直传递到最后一个data center。给你两个function, getLatencyTime(machine1, machine2) 代表从一个机器传信息到另一个机器需要的时间，getJobTime(machine)代表给定机器处理job需要的时间，问完成job需要最短时间。follow up: 怎么unit test。如果必须花很多时间处理这个job怎么办，好像和原题无关了，我就说了分布式并行处理之类的。LC 743
    - [ ] 建水井。一个村子有很多房子，现在需要建水井让所有的房子都有水用，可以直接在房子上建水井，不同房子建水井有不同开销，也可以在房子之间铺水管对应的也有不同的开销，问怎么弄总开销最小。面完才发现是面经题，所以当时还是面试官一步步引导的。首先问我怎么model这个问题，然后如果只是铺水管怎么总开销最小，最后加上可以在房子上直接建水井的条件。总的来说就是用minimum spanning tree，union find，还跑了些test case。最后我说用一个virtual node连到每家，连接的edge代表在这家建水井的cost，面试官说是每家都弄一个virtual node，就听他的了吧。
    - [ ] 实现一个iterator class, input是正常的iterator, 这个class可以实现hasNext(), next(), skip(element), skip(element)会跳过正常iterator里next occurence of the given element。如果skip call n times, 就跳过下面 n个given element，iterator里的elements可以有重复。Refer LC 284 for peek support.
- system design

## LinkedIn (2019/2/1 - 2019/4/29)
Note: pay more attention to LC 33
- coding
    - [x] LC 03, 
    - [x] LC 23, 33, 42, 46, 50, 53, 56, 69, 72, 100, 114, 127, 142, 149, 150, 152, 187
    - [x] LC 189(in place)
    - [x] LC 198, 200,
    - [x] LC 205. follow up: input是 a list of words，考虑两种条件，第一种是存在两个word是isomorphic就返回true，第二种是任意两个word都为isomorphic才返回true
    - [x] LC 213, 236, 
    - [x] LC 352,
    - [ ] LC 341(不准用额外空间), 460, 156, 170, 245, 244, 254, 270, 272, 277, 
    - [ ] LC 671, 416,
    - [ ] LC 973, 339, 895, 265,
    - [ ] LC 256 followup， 如果是k种颜色呢？
    - [ ] LC 776, 698, 364, 380, 381, 384, 432, 605, 716, 611, 366, 612
    - [ ] LC find the celebrity
    - [ ] LC 381 follow up 多线程
    - [ ] LC Nested List Weight Sum
    - [ ] LC shortest word distance I, II, III
    - [ ] LC Factor Combinations
    - [ ] LC shortest word distance II
    - [ ] MAX STACK，注意两种方法都要会
    - [ ] LRU Cache
    - [ ] LC 68 输入的除了行宽还有一组字体大小，要求选择最大可用的字体，并输出排版结果。最大可用字体的意思就是，例如有一个单词特别长，abcdefghijklmn，这个单词不能拆到两行里面去
    - [x] 打印二叉树每一层的叶子节点
    - [x] 给一个类，创建时给个字符串，要求类里写一个方法，给两个字母，算在字符串中最短距离
    - [ ] 给了3个java class， 一个streamer reader class, 一个stream object class, stream object 有rank. 写一个cache, 如果reach一定capacity，pop出rank最小的。
    - [ ] 给一个string返回最长回文子串
    - [ ] 给一个数组，求有多少子集合等于一个给定值
    - [ ] 在一个递增的数组中，中间有若干数字丢失了，问你第K个不见的数字是多少。。例如【2,3,5,8,9】，k=1 返回4， k=3 返回7
    - [ ] 给个String，判断是不是个valid number。看着很简单，但edge case还挺多的
    - [ ] 写一个数据结构 支持 add(key), remove(key), removeRandomKey() 并且每个操作都是 O(1)
    - [ ] 实现一个interface 支持两个method addNumber(int from, int to) 会create一个Interval; getTotalLength: return current cover length 重复的只能算一次; 有点像range module.
    - [ ] 写一个多线程safe的queue. put（T t）如果q满了要等在那里直到有空间put. get（）如果q是空的要等在那里直到有东西get. multiput（List《T》 t）put多个element 如果任意时刻q满了要等在那里直到有空间put
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


## Robinhood (2018/9/19 - 2019/5/1)
- coding
    - [ ] LC 140, 54, 418, 59, 224 Basic Calculator 3,
    - [ ] 给一个数组，找这个数组的某个区间使得区间的中位数最大
    - [ ] 写一个function来算input的mean max min等等
    - [ ] 打印矩阵
    - [ ] 简化版的calculator，只含有括号，加和乘
    - [ ] [bank account transfer problem](http://web.mit.edu/6.005/www/fa15/classes/23-locks/#locking)
- System design
    - message app for families。需要考虑产品功能，UI设计，API设计以及后台的Data Model
    - implement Publisher Subscriber
    - robinhood有一个股票价格变动幅度5%就发一个push notification给关注这个股票的用户， 要求设计一个系统完成这个功能
    - 假设exchange有一个异步的API来post market order和查询order状态 要求做一个robinhood的交易功能，要求任何情况都不能挂。这轮被考到了，需要考虑exchange的API timeout和server crash的情况。面试官让你写实现功能的flow然后考虑哪一步会挂。主要是local db会有一个state，exchange那边会有一个state，在上述情况有可能out of sync。思路是先commit local db的transaction再去call exchange API，然后用aync job来verify和fix inconsitency
    - 一个API service的load banlancer后面会有很多个server，每个server都会有一个log，如何将这些log merge起来，并且设置monitor，alert之类的。楼主的答案是基于Kafka的。
    - design一个family messaging app，从database，到API，到front-end


## Jane Street (All time)
- coding
    - [ ] buy and sell stock 
    - [ ] input: char[][] matrix, int i, int j，其中(i, j)相当于matrix上某点，matrix上每char可能是{up, down, right, left, x},其中x有且只有一个 问是否能从（i, j）走到x所在的点. output: boolean

## Uber
- coding
    - LC 332
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

## Microsoft
    - lc 752   
    - lc 361. Bomb Enemy
    - lc 81. Search in Rotated Sorted Array


1. 设计一个洗衣房系统（亚麻）
2. 设计一个停车场推荐系统（根据client所在位置，推荐一个附近的停车场，使得停车场效率比较高） 
3. poll 模式与 push模式的区别？ 我是从 数据一致性、latency、cash命中效率等方面解答的，供参考。 （亚麻）
4. 设计一个比较通用的监控系统    