class TrieNode {
public:
    char c;
    bool end;
    vector<TrieNode*> childs;
    TrieNode(char c) {
        this->c = c;
        end = false;
        childs.resize(26, NULL);
    }
};

class Trie {
public:
    TrieNode* root = NULL;
    Trie() {
        root = new TrieNode('#');
    }
    
    void insert(string& word) {
        int n = word.length();
        TrieNode* T = root;
        for (int i = 0; i < n; i++) {
            if (T->childs[word[i] - 'a']) {
                T = T->childs[word[i] - 'a'];
            } else {
                TrieNode* node = new TrieNode(word[i]);
                T->childs[word[i] - 'a'] = node;
                T = T->childs[word[i] - 'a'];
            }
            if (i == n - 1) T->end = true;
        }
    }
};

class WordDictionary {
public:
    Trie* T;
    TrieNode* root = NULL;
    
    WordDictionary() {
        T = new Trie();
        root = T->root;
    }
    
    void addWord(string word) {
        T->insert(word);
    }
    
    bool helper(string& word, int i, TrieNode* T) {
        for (int j = i; j < word.length(); j++) {
            
            if (word[j] != '.') {
                
                if (T->childs[word[j] - 'a']) {
                    T = T->childs[word[j] - 'a'];
                } else {
                    return false;
                }
                
            } else {
                
                for (int x = 0; x < 26; x++) {
                    
                    if (j == word.length() - 1) {
                        if (T->childs[x]) {
                            if (T->childs[x]->end) return true;
                        }
                    } else if (T->childs[x]) {
                        if (helper(word, j + 1, T->childs[x])) {
                            return true;
                        }
                    }
                    
                }
                
                return false;
            }
        }
        if (T->end) return true;
        else return false;
    }
                        
    // bool helper(string& word, int i, TrieNode* T) {
    //     if (i == word.length()) {
    //         if (T->end) return true;
    //         else return false;
    //     }
    //     if (word[i] != '.') {
    //         if (T->childs.count(word[i])) {
    //             return helper(word, i + 1, T->childs[word[i]]);
    //         } else return false;
    //     } else {
    //         bool result = false;
    //         for (auto& e : T->childs) {
    //             result = result || helper(word, i + 1, e.second);
    //         }
    //         return result;
    //     }
    // }
    
    bool search(string word) {
        return helper(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */