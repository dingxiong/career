XXXX - 2019/6/22
- TODO
    - read https://www.1point3acres.com/bbs/interview/dropbox-software-engineer-307607.html
    - delay method call 用 delay queue 实现一下
- coding
    - [x] LC easy 38
    - [x] LC medium 17 139 289 322 379 622 362
    - [x] LC hard 140 924
    - [x] LC 379 => use segment tree & bitset to get lgN time/space complexity
        ```java
        private BitSet heap;
        private int depth;
        private int counts;
        private int maxNums;
        
        public PhoneDirectory(int maxNumbers) {
            this.maxNums = maxNumbers;
            depth = (int) Math.ceil(Math.log(maxNumbers) / Math.log(2));
            heap = new BitSet((int) Math.pow(2, depth+1) - 1 );
            counts = (int) (Math.pow(2, depth)) - 1;
        }
        
        public int get() {
            if (heap.get(0)) return -1;
            int index = 0;
            for (int i = 0; i < depth; i++) {
                if (heap.get(2*index+1)) index = 2*index+2;
                else index = 2*index+1;
            }

            if (index >= maxNums + counts) return -1;

            flip(index);
            return index - counts;
        }

        public boolean check(int number) {
            if (number >= maxNums) return false;
            return !heap.get(counts + number);
        }

        public void release(int number) {
            if (heap.get(number + counts)) flip(counts + number);
        }

        private void flip(int index) {
            heap.flip(index);
            for (int i = 0; i < depth; i++) {
                index = (index - 1) / 2;
                if (heap.get(2*index+1) && heap.get(2*index+2)) {
                    heap.set(index);
                } else {
                    heap.clear(index);
                }
            }
        }
        ```
    - [x] LC LFU
    - [x] implement read/write lock
    - [x] 问的Nasa， 给了一个section(int x, int y) 和Image class， 求storeImage(section, Image) 和 Image fetch(section). follow up 是 section getstalest(section)
        similar to LRU cache
        ```java
        /**
        * NASA selects Dropbox as its official partner, and we’re tasked with managing
        * a panorama for the universe. The Hubble telescope (or some other voyager we
        * have out there) will occasionally snap a photo of a sector of the universe,
        * and transmit it to us. You are to help write a data structure to manage this.
        * For the purpose of this problem, assume that the observable universe has been
        * divided into 2D sectors. Sectors are indexed by x- and y-coordinates.
        */
        public File {
            public File(String path) {}
            public Boolean exists() {}
            public byte[] read() {}
            public void write(bytes[] bytes) {}
        }
        public Image {
            public Image(byte[] bytes) {}
            byte[] getBytes() {} // no more than 1MB in size.
        }
        public Sector {
            public Sector(int x, int y) {}
            int getX() {}
            int getY() {}
        }
        /**
        * row-major indexing to be consistent.
        */
        public class SpacePanorama {
            /**
            * initializes the data structure. rows x cols is the sector layout.
            * width, height can be as large as 1K each.
            */
            public SpacePanorama(int rows, int cols) {}
            /**
            * The Hubble will occasionally call this (via some radio wave communication)
            * to report new imagery for the sector at (y, x)
            * Images can be up to 1MB in size.
            */
            public void update(int y, int x, Image image) {}
            /**
            * NASA will occasionally call this to check the view of a particular sector.
            */
            public Image fetch(int y, int x) {}
            /**
            * return the 2D index of the sector that has the stalest data.
            * the idea is that this may help the telescope decide where to aim next.
            */
            public Sector getStalestSector() {}
        }
        ```
    - [ ] delay method call: 让你写一个API，可以传进去一个function和一个时间，然后这个function会被延迟这么多时间被执行。 这个API可以被反复call， 相当于可以schedule不止一个
    要被延迟处理的function。
        ```java
        ScheduledExecutorService executorService  = Executors.newScheduledThreadPool(10);
        executorService.schedule(() -> function(), time, TimeUnit.SECONDS)
        ```
    - [x] 照片每次被view就會call View(photo id), 給top-k view photo.
        1. PriorityQueue + HashMap => update O(logN), top-k O(k*logN)
        2. similar to LFU : `HashMap<id, Node>` + double linked list 
            ```java
            class Node {
                Node prev, next;
                int count;
                Set<Integer> photoIds;
            }
            ```
    - [x] BitTorrent那一题。给一堆下载好的chunk的起始byte和结束byte，给File的大小，看看chunk有没有覆盖从0到file大小的所有byte。
        Similar to LC 715
    - [x] 给一个list 里面存放file system里面folder的parent-child tuple, 以及一个access_right的set，里面是有explicit access权限的folder。 
        拥有explicit access的folder, 底下的children folders就会有implicit access，实现一个function, input是folder, 返回这个folder是否有access (either explicit or implicit)
    - [x] 2-d array of "sharpness" values. Fine the path from left to right which has the highest minimum sharpness. 路径必须是从左往右，先有个起始点，然后每次要往右上，正右或右下跳一步。
        也就是说，路径长度是列数n，假设路径为(i1,1),(i2,2),...,(in,n)，路径必须满足每对i_k与i_{k-1}的距离不能大于1.
        .5 .7 .2
        .7 .5 .8
        .9 .1 .5
        在这个例子中，理想路径是.7->.7->.8因为这条路径中的最小值.7在所有路径中最大。只需要返回这个值，不需要返回路径。这是道dp问题
        follow up: 如果图片是1million*1million的怎么办，整张图片读不进内存
    - [x] 判断一个byte[]是否在一个文件中
        ```java
        boolean doesContain(String fileName, byte[] target) throws Exception {
            int n = target.length;
            long base = 7, high = (long) Math.pow(base, n-1);
            long targetHash = getHash(target, base);

            Queue<Byte> buf = new LinkedList<>();
            long hash = 0;

            InputStream in =  new BufferedInputStream(Files.newInputStream(Paths.get(fileName)));
            while (true) {
                int next = in.read();
                if (next == -1) break;
                buf.offer((byte)next);
                if (buf.size() > n) {
                    long head = buf.poll();
                    hash = (hash - head * high) * base + next;
                } else {
                    hash = hash * base + next;
                }

                if (buf.size() == n && hash == targetHash) {
                    if (isSame(target, new ArrayList<>(buf))) return true;
                }
            }

            return false;
        }

        private long getHash(byte[] arr, long base) {
            int n = arr.length;
            long hash = 0;
            long b = 1;
            for (int i = 0; i < n; i++) {
                hash += arr[n-1-i] * b;
                b *= base;
            }
            return hash;
        }

        private boolean isSame(byte[] target, List<Byte> buf) {
            int n = target.length;
            for (int i = 0; i < n; i++) {
                if (target[i] != buf.get(i)) return false;
            }
            return true;
        }
        ```
    - [x] LC 609 follow up: how to quickly know the file exist not. We need a good hash function. 1) use file size 2) take a first 20 chars and hash
        ```java
        public static List<List<Path>> getDuplicatedFiles(String folder) {
            List<List<Path>> dupFiles = new ArrayList<>();
            try {
                // get all files with full path
                Map<Long, List<Path>> files = Files.walk(Paths.get(folder))
                    .filter(Files::isRegularFile)
                    .collect(Collectors.groupingBy(HelloWorld::getFileSize));

                for (long size : files.keySet()) {
                    List<Path> paths = files.get(size);
                    if (paths.size() == 1) continue;
                    dupFiles.addAll(getDuplicated(paths));
                }
            } catch (Exception e) {
                throw new RuntimeException();
            }

            return dupFiles;
        }

        private static List<List<Path>> getDuplicated(List<Path> paths) {
            Map<Integer, List<Path>> parts =
                paths.stream().collect(Collectors.groupingBy(path -> readFile(path).orElse("").hashCode()));
            List<List<Path>> dups = new ArrayList<>();
            for (int hash : parts.keySet()) {
                List<Path> dup = parts.get(hash);
                if (dup.size() > 1) dups.add(dup);
            }
            return dups;
        }

        private static Optional<String> readFile(Path path) {
            try {
                String content = Files.lines(path).collect(Collectors.joining("\n"));
                return Optional.of(content);
            } catch (Exception e) {
                return Optional.empty();
            }
        }

        private static long getFileSize(Path path) {
            try {
                return Files.size(path);
            } catch (Exception e) {
                return 0;
            }
        }
        ```
    - [x] multithread token bucket
    - [ ] KV Store这道题的问题是设计一个transaction， 有一个start() 方法， 返回一个transaction id. 有一个put(transactionId, String key, int value),
         有一个get(transactionId, String key), 和一个commit(transactionID)

- system design
    - [x] Web Crawler 单线程+多线程版 
        - see `WebCrawlerMultithread.java` in `system_design` folder.
    - [ ] 设计一个调度器，会有很多的任务进来，然后会有很多的worker, 怎么样去判断process 已经成功完成了
    - [ ] 设计一个图片处理系统 && 设计图片上传后生成缩略图的服务
    - [ ] 给你一些producer，发送不同的image url到你的service，你的service需要有consumer，来读取image的url，然后把image download下来。
        其实就是想让你design 一个mesasge queue。follow up有咱们scale，consumer machine down掉了怎么办，如果message queue down掉了怎么办，
        down掉后重新开启有什么问题。最开始还让写了一下service的各个API。
    - [ ] 给定两个module，一个发送图片，一个处理图片，需要设计中间这个接受的模块（将图片从前一个module接收到，然后出送给后续的处理部分）
    - [x] Design Dropbox
    - [x] 设计一个类似于电话簿的APP， 从设计API, 页面 到怎么scale ，pagination 都要聊一下。
        - schema
            - `contacts` (user_id, contact_name, contact_phone, status(blocked...))
        - api
            - add_contact / delete_contact

    - [x] 设计log系统
    - [x] 设计Twitter 主页feeds. daily active user 1M2    
- BQ
    - [ ] 怎么处理意见不同的冲突，怎么去说服别人同意你的观点，你工作过的最喜欢的组或者公司是什么，为什么喜欢啦
