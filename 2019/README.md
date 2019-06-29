## Candidate list:
- offer: 
	- Google
	- Brex 275k
	- Citadel 225k + 175k + 50k + 30k 
	- Houzz 165K, 515k/4 rsu, 25k sign on
	- LinkedIn 175K, 300k/4, 50k sign on
  - Quip: 156k, 20% yearly bonus, 200k/4 stock, 25k sign on
- onsite interview : Robinhood Square dropbox Uber
- failed : Facebook, Netflix, Jane street Lyft apple stripe
- no response : snapchat Twitter Pintrest two sigma, jump trading, DE shaw
- cancelled: Nuro amazon

## mj
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
    content.any? { |line| line.include?(keyword) && line.include?('onsite') }
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

## Summary
1. 金融公司特别喜欢问netword, multithreading, c++ 的问题。所以千万不要在简历里面写自己会这些。
2. java 的 concurrency 代码库其实写的很好，是一个很好的学习资源。自己应该看看 implementation.
3. networking 这一块真的不熟悉。可以找本书仔细学习一下。

- left work
	- two week notice
	- airbnb credit transfer to personal account
  - visit phd adviser

- 律师：
	1. 问清楚律师 H1B transfer: 多久时间
	2. 问清楚 priority day 有没有影响

- startup 面试的时候问的问题：
	1. 有没有competitor, 如果big player介入，如何survive?
	2. option 的 percentage
- Java mics
	1. output int[] : Arrays.toString()
	1. array initialize int[] a = {1, 2, 3, 4};
	3. Arrays.sort()
	5. List.toString(T[] a) 
	6. Arrays.stream()
	7. IntStream.range()
	8. Comparator.comparing().reversed().naturalOrder()
	9. OptionalInt.getAsInt()
	10. Arrays.asList(...) is immutable
