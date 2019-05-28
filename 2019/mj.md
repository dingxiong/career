seckcoder
BeAHost2019!
## common 
system design https://www.1point3acres.com/bbs/forum.php?mod=forumdisplay&fid=323&orderby=dateline&orderby=dateline&filter=author&page=1
https://juejin.im/post/5ba63910e51d450e576703a1

## design kafka
Kafka is a distributed streaming platform
1. main concepts: 
    - (topic, partition, offset), producer, consumer, Broker
    - (leader, follower) for fault tolerance
    - 
2. 

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


## Nuro
- coding
    - [ ] LC 64, 778
    - [ ] LC calculator II, 227, 451
    - [ ] 平面上一堆坐标，类型是浮点，要求返回有没有任意两个点之间的距离是小于根号2的. 
        use hashmap ?? if |(x1, y1) - (x2, y2)| < sqrt(2) => at least |x1-x2| < 1 or |y1-y2| < 1 is true.

## Jane Street (All time)
- coding
    - [x] buy and sell stock 
    - [ ] input: char[][] matrix, int i, int j，其中(i, j)相当于matrix上某点，matrix上每char可能是{up, down, right, left, x},其中x有且只有一个 问是否能从（i, j）走到x所在的点. output: boolean

- [Robinhood](robinhood.md)
- [LinkedIn](linkedin.md)
- [citadel](citadel.md)
- [Uber](uber.md)
- [Lyft](lyft.md)
- [Houzz](houz.md)
- [Apple](apple.md)

## script to crawl 一亩三分地
Ruby script to grep 1point3acres
```ruby
TEMPLATE = "https://www.1point3acres.com/bbs/forum.php?mod=forumdisplay&fid=145&orderby=dateline&sortid=311&orderby=dateline&sortid=311&filter=author&page="

def contain_key(keyword, file_name)
    content = File.readlines(file_name)
                .select {|line| line.include?("#666")} ## the color of the date of the label row
                .map {|line| line.encode!('UTF-8', 'binary', invalid: :replace, undef: :replace, replace: '').downcase }
                #.map {|line| line.force_encoding('gb2312').encode('UTF-8').downcase } # correct the encoding
    # content.any? { |line| line.include?(keyword) }
    content.any? { |line| line.include?(keyword) }
end

def get_pages(keyword, from, to)
  page_nums = []
  (from..to).each do |num| 
    url = "\"" + TEMPLATE + num.to_s + "\" " # double quote around string cannot be omitted
    file_name = "out.html"
    cmd = "wget #{url} -O #{file_name} -o log.txt" # view the work progress by `tail -F log.txt`
    `#{cmd}`
    if (contain_key(keyword, file_name))
      puts "found page #{num}" 
      page_nums << num
    end
  end
  page_nums
end

def get_chrome_command(pages)
  webpages = ""
  pages.each do |page| 
    webpages += "\"" + TEMPLATE + page.to_s + "\" "
  end
  print "open -a \"Google Chrome\" " + webpages
end

pages = get_pages("lyft", 1, 10)
get_chrome_command(pages)
```