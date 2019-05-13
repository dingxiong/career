## Tiny URL
**Components**
1. schema & api
    - schema: `tiny_urls(id, long_url, short_url, created_at, expired_at)` index on long_url and short_url
    - api: `getShortUrl(long_url)` => for client;  `getLongUrl(short_url)` => for browser
2. Base62 encoding (26*2+10)
3. Add cache for read path (e.g. some links gone viral)

**Scalability**
- Single machine
    - id generator : just map the primary key to the corresponding Base62 code.
    - Mysql to store the `tiny_urls` table
2. Distributed service
    - id generator:
        - random: 
            Use a hash function. For example, use the first 7 chars of the MD5 value (assuming the tiny url has length 7). If collision happens, we can increment the hash one by one until we get a unused tiny url.
        - auto increasing:
            - option1: assign two-digit id range to each machine. For example, machine1 is assigned to 00xxxx, machine2 is assigned to 01xxxx. 
                Then each machine has a local mysql db to create incremental ids. The url is  `xxyyyyy` where `xx` is id range and 
                `yyyyy` is the db primary key. We can use consistent hashing here to add/remove node.
            - option2: Use centralized redis. `incr` will create unique ids => have no idea about the performance/throughput. Also what if redis cluster failed?     
            - option3: Use Zookeeper to register each service box to a id range. 
    - Storage:
        We can estimate the that `tiny_urls` table is too large, we turn to nosql solution.
        
**References**
- https://medium.com/@narengowda/url-shortener-system-design-3db520939a1c
- https://leetcode.com/discuss/interview-question/124658/design-a-url-shortener-tinyurl-system
- https://soulmachine.gitbooks.io/system-design/cn/distributed-id-generator.html
