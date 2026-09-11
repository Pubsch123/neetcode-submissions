class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        int n = strs.size();
        for(int i=0;i<n;i++)
        {
            int k = strs[i].size();
            s += to_string(k);
            s += "#";
            s += strs[i];
        }
        cout<<s;
        return s;
    }

    vector<string> decode(string s) {
        int n = s.size(),i = 0;
        vector<string> ans;
        while(i<n)
        {
            int j = i;
            while(s[j] != '#')
            j++;
            int k = stoi(s.substr(i,j-i));
            ans.push_back(s.substr(j+1,k));
            i = j+k+1;
        }
        return ans;
    }
};
