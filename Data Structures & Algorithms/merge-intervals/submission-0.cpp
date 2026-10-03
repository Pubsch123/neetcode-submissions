class Solution {
public:
    bool static comp(vector<int>& v1, vector<int>& v2){
        return v1[0] == v2[0]? v1[1] < v2[1] : v1[0] < v2[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int n = intervals.size();
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(ans.back()[1] >= intervals[i][0]){
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
