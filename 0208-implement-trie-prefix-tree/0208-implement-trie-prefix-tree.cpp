class TrieNode {
public:
    char c;
    bool end;
    map<char, TrieNode*> childs;
    TrieNode(char c) {
        this->c = c;
        this->end = false;
    }
};

class Trie {
public:
    TrieNode* root = NULL;
    
    Trie() {
        root = new TrieNode('#');    
    }
    
    void insert(string word) {
        int n = word.length();
        TrieNode* T = root;
        for (int i = 0; i < n; i++) {
            if (T->childs.count(word[i])) { // if the character already exits in the child 
                T = T->childs[word[i]];
                if (i == n - 1) T->end = true;
            } else {
                TrieNode* node = new TrieNode(word[i]);
                T->childs[word[i]] = node;
                T = T->childs[word[i]];
                if (i == n - 1) T->end = true;
            }
        }
    }
    
    bool search(string word) {
        int n = word.length();
        TrieNode* T = root;
        for (int i = 0; i < n; i++) {
            if (T->childs.count(word[i])) {
                T = T->childs[word[i]];
            } else {
                return false;
            }
        }
        if (T->end) return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.length();
        TrieNode* T = root;
        for (int i = 0; i < n; i++) {
            if (T->childs.count(prefix[i])) {
                T = T->childs[prefix[i]];
            } else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */