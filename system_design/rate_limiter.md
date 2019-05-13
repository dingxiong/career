## Rate limiter
Mysql is bad since time taken for disk seeks is high enough to hamper rate limiter granularity.

**rate limiting algorithms**
- Token bucket/Leaky bucket
    - current industry standard for rate limiter
    - only need a few variables: max_amount, refill_interval, refill_amount, current_count,     last_update_ts;
        ```redis
        SET USERA 15 EX 60 NX // refill_amout = 15, refill_interval = 60s
        DECR USERA
        ```
    - Pros: no fixed window boundary    
- Fixed window counters
    - pros: easy to implement, less memory footprint
        ```redis
        SET USERA:201903232048 15 EX 60 // compound key = key + window start timestamp
        DECR USERA:201903232048  
        ```
    - cons: inaccurate
- Sliding window logs
    - pros: perfect solve the problem
    - cons: high memory footprint, i.e., server stores #client x quota data; high time complexty
- Sliding window counters: compromise of fixed window counter and sliding window logs  

**Scale to a cluster**
1. We need a global counter 
    - Track rate quota on each box => total count will violate the rate policy.
2. [x] Use redis
    - Pros: global counter; faster that db approach
    - Cons: a few ms latency; race condition. The compromise is to use a memory copy of Redis count and sync with Redis periodically. 


**References**
- https://medium.com/smyte/rate-limiter-df3408325846
- https://medium.com/@saisandeepmopuri/system-design-rate-limiter-and-data-modelling-9304b0d18250
- https://konghq.com/blog/how-to-design-a-scalable-rate-limiting-algorithm/
- https://www.1point3acres.com/bbs/thread-456546-2-1.html
