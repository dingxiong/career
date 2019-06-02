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

- [Google](google.md)
- [Robinhood](robinhood.md)
- [LinkedIn](linkedin.md)
- [citadel](citadel.md)
- [Uber](uber.md)
- [Lyft](lyft.md)
- [Houzz](houz.md)
- [Apple](apple.md)
- [Nuro](nuro.md)

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
    content.any? { |line| line.include?(keyword) && line.include?("onsite") }
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