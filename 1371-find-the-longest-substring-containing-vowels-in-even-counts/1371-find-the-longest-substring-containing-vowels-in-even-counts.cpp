class Solution {
public:
    int findTheLongestSubstring(string s) {
        for(int i = s.length(); i > 0; i--) {
            if(checkSubstrings(s, i))
                return i;
        }
        return 0;
    }
    bool checkSubstrings(string s, int length) {
        int vowelParity = 0b00000; // Stores parity of each vowel in a substring.
        for(int i = 0; i < length; i++) {
            characterXOR(s[i], vowelParity);
        }
        for(int i = 0; i <= s.length() - length; i++) {
            if(vowelParity == 0b00000)
                return true;
            characterXOR(s[i], vowelParity);
            characterXOR(s[i+length], vowelParity);
        }
        return false;
    }
    void characterXOR(char c, int &vowelParity) {
        switch(c) {
            case 97:
                vowelParity ^= 0b10000;
                break;
            case 101:
                vowelParity ^= 0b01000;
                break;
            case 105:
                vowelParity ^= 0b00100;
                break;
            case 111:
                vowelParity ^= 0b00010;
                break;
            case 117:
                vowelParity ^= 0b00001;
                break;
            default:
                break;
        }
    }
};