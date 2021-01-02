class Trie {
    Node root;
    
    Trie(String[] words) {
        root = new Node();
        buildTrie(words);
    }
    
    void buildTrie(String[] words) {
        for (String word: words) insert(word);
    }
    
    void insert(String s) {
        Node curr = root;
        for (char c : s.toCharArray()) {
            int pos = c - 'a';
            if (curr.next[pos] == null) curr.next[pos] = new Node(); 
            curr = curr.next[pos];
        }
        curr.isWord = true;
        curr.word = s;
    }

    class Node {
        boolean isWord;
        String word; // this field is optional determine by the problem you solve
        Node[] next;
        
        Node() {
            isWord = false;
            next = new Node[26];
        }
    }
}

    
