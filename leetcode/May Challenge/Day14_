// https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3329/
class Trie {
    class TrieNode {
        int endCount;
        TrieNode trieNodes[] = new TrieNode[26];
        public TrieNode next(char c){
            return trieNodes[c - 'a'];
        }
    }
    /** Initialize your data structure here. */
    TrieNode root;
    public Trie() {
           this.root = new TrieNode(); 
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
      TrieNode curr = root;
        for (int i=0; i<word.length(); i++){
            if(curr.trieNodes[word.charAt(i) - 'a'] == null){
                curr.trieNodes[word.charAt(i) - 'a'] = new TrieNode();
            }
            curr = curr.next(word.charAt(i));
        }
        curr.endCount ++;
    }    
    
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
       TrieNode cur = root;
        int n = word.length();
      for (int i=0; i<n; i++){
          if(cur.trieNodes[word.charAt(i) - 'a'] == null){
              return false;
          }
          cur = cur.next(word.charAt(i));
      }
        if(cur.endCount != 0){
            return true;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
         TrieNode cur = root;
        int n = prefix.length();
        for (int i=0; i<n; i++){
            if(cur.trieNodes[prefix.charAt(i) - 'a'] == null){
                return false;
            }
            cur = cur.next(prefix.charAt(i));
        }
        return true;
    }
    }

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
