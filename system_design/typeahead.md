## requirements/metrics
- auto-complement a single word and a sentence
- latency
- relevance accuracy => ranking problem
## Architecture
- Trie tree
    - preprocessing word tries. assign 2 or 3 top works for each prefix => prefix hash tree
    - preprocessing sentence. the children are the next words shown in a sentence.
    - distributed  Trie : sharded by prefix
- how to get user specific history + how to use trending keyword


## References
- https://medium.com/@prefixyteam/how-we-built-prefixy-a-scalable-prefix-search-service-for-powering-autocomplete-c20f98e2eff1