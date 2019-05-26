1-600
- TODO
    - read docx file
    - 
- coding
    - [ ] LC easy
    - [x] LC medium 289, 379, 609 622
    - [x] LC hard 924
    - [ ] LC 379 => use segment tree & bitset to get lgN time/space complexity
    - [x] LC 609 Find duplicate file. Follow up: use file size as first key, use first 10 bytes as second key. If there is soft link?
    - [ ] LC 289
    - [ ] LC LFU
    - [ ] 问的Nasa， 给了一个section(int x, int y) 和Image class， 求storeImage(section, Image) 和 Image fetch(section). follow up 是 section getstalest(section)
        
    - [ ] delay method call: 让你写一个API，可以传进去一个function和一个时间，然后这个function会被延迟这么多时间被执行。 这个API可以被反复call， 相当于可以schedule不止一个要被延迟处理的function。
        ```java
        ScheduledExecutorService executorService  = Executors.newScheduledThreadPool(10);
        executorService.schedule(() -> function(), time, TimeUnit.SECONDS)
        ```
    - [ ] 给一个list 里面存放file system里面folder的parent-child tuple, 以及一个access_right的set，里面是有explicit access权限的folder。 
        拥有explicit access的folder, 底下的children folders就会有implicit access，实现一个function, input是folder, 返回这个folder是否有access (either explicit or implicit)
    - [ ] 写一个算法来实现callback + timeout, 要先发现penalty 然后再写一个算法去分配谁先执行，涉及到 notify() 和 sleep()
    - [x] 2-d array of "sharpness" values. Fine the path from left to right which has the highest minimum sharpness. 路径必须是从左往右，先有个起始点，然后每次要往右上，正右或右下跳一步。
        也就是说，路径长度是列数n，假设路径为(i1,1),(i2,2),...,(in,n)，路径必须满足每对i_k与i_{k-1}的距离不能大于1.
        .5 .7 .2
        .7 .5 .8
        .9 .1 .5
        在这个例子中，理想路径是.7->.7->.8因为这条路径中的最小值.7在所有路径中最大。只需要返回这个值，不需要返回路径。这是道dp问题
        follow up: 如果图片是1million*1million的怎么办，整张图片读不进内存

- system design
    - [x] Web Crawler 单线程+多线程版 
        - see `WebCrawlerMultithread.java` in `system_design` folder.
    - [ ] 设计一个调度器，会有很多的任务进来，然后会有很多的worker, 怎么样去判断process 已经成功完成了
    - [ ]  给你一些producer，发送不同的image url到你的service，你的service需要有consumer，来读取image的url，然后把image download下来。
        其实就是想让你design 一个mesasge queue。follow up有咱们scale，consumer machine down掉了怎么办，如果message queue down掉了怎么办，
        down掉后重新开启有什么问题。最开始还让写了一下service的各个API。
    - [ ] Design Dropbox
    - [ ] 设计一个类似于电话簿的APP， 从设计API, 页面 到怎么scale ，pagination 都要聊一下。
        - schema
            - `contacts` (user_id, contact_name, contact_phone, status(blocked...))
        - api
            - add_contact / delete_contact

    - [ ]  设计log系统
    - [ ] 设计Twitter 主页feeds. daily active user 1M2    
- BQ
    - [ ] 怎么处理意见不同的冲突，怎么去说服别人同意你的观点，你工作过的最喜欢的组或者公司是什么，为什么喜欢啦
