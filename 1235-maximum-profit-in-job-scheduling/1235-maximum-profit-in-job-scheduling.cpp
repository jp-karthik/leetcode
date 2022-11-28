class Solution {
public:

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        vector<vector<int>> jobs;
        int n = startTime.size();
        
        for (int i = 0; i < n; i++) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        
        map<int, int> dp;
        dp[0] = 0;
        
        for (int i = 0; i < n; i++) {
            auto it = dp.upper_bound(jobs[i][1]); // t >  -> t <= 
            int res = 0;
            if (it != dp.begin()) {
                it--;
                res = max(res, jobs[i][2] + it->second);
            }
            res = max(res, (--dp.end())->second);
            dp[jobs[i][0]] = res;
        }
        
        return (--dp.end())->second;
    }
};