class Solution {
public:
    string smallestSubsequence(string s) {
         int last_occ[26] = {};
        for (int i = 0; i < s.size(); i++) {
            last_occ[s[i] - 'a'] = i;
        }
        
        bool used[26] = {};
        string stack = "";
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (used[c - 'a']) continue;
            
            while (!stack.empty() && c < stack.back() && last_occ[stack.back() - 'a'] > i) {
                used[stack.back() - 'a'] = false;
                stack.pop_back();
            }
            
            stack.push_back(c);
            used[c - 'a'] = true;
        }
        
        return stack;
        
    }
};