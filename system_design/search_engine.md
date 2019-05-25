## How to design a search engine
We need to solve 3 problems. The first is how to store the documents. The second is how to query the
stored documents. And the third is before a query result is returned, how do we sort the document ids
in the result.
1. index store
    - create reverse index => Map<Word, Set<Document Id>>
        - Map Reduce for scalable processing
        - Sharded Trie tree for scalable storage
    - Stemming and lemmatization
2. search query
    Query types
    1. single word query
    2. multiple works query. there are two uses cases
        - `or` relation: any word shows up in the doc
        - `and` relation: all words must show up
    3. phrase query: search the phrase as it is.
        Two ways to achieve it
        - When building the reverse index, we also record the position of the work in the doc
        - load the doc content and do a full scan.
3. search result ranking
    - tf–idf
    - google PageRank

### References
- http://www.ardendertat.com/2012/01/11/implementing-search-engines/