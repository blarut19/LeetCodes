struct TrieNode {

    // pointer array for child nodes of each node
    TrieNode* child[26];

    // Used for indicating ending of string
    bool wordEnd;

    // Used for how many words share the node
    int count;
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {

        // Initialize score vector and root of the trie
        vector<int> scores;
        TrieNode* root = new TrieNode();

        // Insert all of the words into the trie
        for (int i = 0; i < words.size(); i++)
            insertKey(root, words[i], i);

        for (string word: words)
            scores.push_back(calculateScore(root, word, 0));

        return scores;
    }
    // Method to insert a key into the Trie
    void insertKey(TrieNode* root, const string& key, int i) {
    
        // Initialize the curr pointer with the root node
        TrieNode* curr = root;

        // Iterate across the length of the string
        for (char c : key) {
        
            // Check if the node exists for the 
            // current character in the Trie
            if (curr->child[c - 'a'] == nullptr) {
            
                // If node for current character does 
                // not exist then make a new node
                TrieNode* newNode = new TrieNode();
            
                // Keep the reference for the newly
                // created node
                curr->child[c - 'a'] = newNode;

            }
        
            // Move the curr pointer to the
            // newly created node
            curr = curr->child[c - 'a'];

            curr->count++;
        }

        // Mark the end of the word
        curr->wordEnd = true;
    }
    int calculateScore(TrieNode* curr, string& word, int score) {
        // Add all the scores from the trie
        for(char letter: word){
            curr = curr->child[letter - 'a'];
            score += curr->count;
        }
        return score;
    }
};