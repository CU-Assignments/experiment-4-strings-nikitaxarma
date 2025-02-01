class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        for(int i=0;i<s.size();i++){
            char p=s[0];
            s.erase(s.begin());
            s.push_back(p);
            if(s==goal) return true;
        }
        return false;
        
    }
};
