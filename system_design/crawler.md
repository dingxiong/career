## Design
1. How to distributed URLs to different workers? I think a good way is consistent hashing, so there is no centralized node to keep track of the assignment.

## Reference
1. [distributed crawler design](dcrawler.pdf)
2. https://github.com/donnemartin/system-design-primer/tree/master/solutions/system_design/web_crawler