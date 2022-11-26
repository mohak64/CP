class Solution {
public:
    
int getNextJob(vector<vector<int>>& jobs, int idx, const int& n)
{
    for(int i=idx+1; i<n; i++)
    {
        if(jobs[idx][1] <= jobs[i][0]) return i;
    }
    return n;
}
unordered_map<int, int> dp;    // Only store for relavent index
int maxProfit(vector<vector<int>>& jobs, int idx, const int& n)
{
	if(idx == n) return 0;

	if(dp.find(idx) != dp.end()) return dp[idx];

	// include current job and find the next job with start > curr end time
	int next = getNextJob(jobs, idx, n);  // Pick any one of the helper function
	int incl = jobs[idx][2] + maxProfit(jobs, next, n);

	// exclude current job
	int excl = maxProfit(jobs, idx+1, n);

	return dp[idx] = max(incl, excl);
}

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

	int n = startTime.size();
	vector<vector<int>> jobs(n, vector<int>(3));

	for(int i=0; i<n; i++)
	{
		jobs[i][0] = startTime[i];
		jobs[i][1] = endTime[i];
		jobs[i][2] = profit[i];
	}

	sort(jobs.begin(), jobs.end());
	return maxProfit(jobs, 0, n);
}
};
