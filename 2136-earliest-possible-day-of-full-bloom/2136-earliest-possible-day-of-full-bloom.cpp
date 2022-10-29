class Solution {
public:
    static bool comp(pair<int,int> a, pair<int,int> b) {
        if (a.first > b.first) return true;
        else return false;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> flowers;
        int n = plantTime.size();
        for (int i = 0; i < n; i++) {
            flowers.push_back({growTime[i], plantTime[i]});
        }
        sort(flowers.begin(), flowers.end(), comp);
        int startingTime = 0;
        int result = 0;
        for (int i = 0; i < n; i++) {
            startingTime += flowers[i].second;
            result = max(result, startingTime + flowers[i].first);
        }
        return result;
    }
};