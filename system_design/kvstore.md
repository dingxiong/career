## distributed KV store
1. single machine
    - in memory HashMap.
    - failure recover: WAL (write ahead log)
2. single machine but memory is not enough
    - Similar to design of [LevelDB](https://soulmachine.gitbooks.io/system-design/cn/key-value-store.html).
    - have sstable (string sorted table), immutable sstable on disk.
    - B-tree vs Log-structured merge-tree (LSM)
        - LSM trees are designed to provide better write throughput than traditional B+ tree
        - b-tree is popular in relational databases.
        - b-tree is slow for update operation because 
            1. update moves data around on disk especially slow if there are node splits/merges.
            2. update needs locks.
    - references
        - http://www.benstopford.com/2015/02/14/log-structured-merge-trees/

3. multiple machines
    - tradeoff: It is hard to achieve availability and strong consistency at the same time.
    - good example: [DynamoDB](https://www.allthingsdistributed.com/files/amazon-dynamo-sosp2007.pdf)
    - key concept: 
        - consistent hashing + replicas
            - The essential part of consistent hashing is a `SortedMap<key, machine>`. There are multiple places to store this it.
                see https://redis.io/topics/partitioning
        - p2p architecture (gossip protocol), eg. Cassandra VS master-slave architecture
            - p2p: no single point of failure, no leader election, 
            - cons: only eventual consistency
        - versions and version conflict resolution (lock vector)
        - write ahead log used in failure recover.
