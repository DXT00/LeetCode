#include <map>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
	set<vector<int> >s;
	set<vector<int> >::iterator it;
	vector<vector<int> > res;
	void dfs(vector<int> cur, vector<bool> visited, vector<int>& nums, int N){
		if (cur.size() == N){
			res.push_back(cur);
			return;
		}
		for (int i = 0; i<nums.size(); i++){
			if (i != 0 && nums[i] == nums[i - 1] && visited[i - 1])continue;

			if (visited[i] == false){

				visited[i] = true;
				cur.push_back(nums[i]);

				dfs(cur, visited, nums, N);

				cur.pop_back();
				visited[i] = false;
			}

		}

	}
	vector<vector<int> > permuteUnique(vector<int>& nums) {

		int N = nums.size();
		sort(nums.begin(), nums.end());

		vector<int> cur;
		vector<bool>visited(N, false);
		dfs(cur, visited, nums, N);

		return res;
	}
};

int M;
int main(int argc, char const *argv[])
{

	vector<vector<int> > result;
	cin >> M;
	std::vector<int> nums(M);
	for (int i = 0; i <M; ++i)
		scanf("%d", &nums[i]);

	result = Solution().permuteUnique(nums);

	for (int i = 0; i < result.size(); i++){
		for (int j = 0; j < result[i].size(); j++)
		{
			if (j != 0)cout << " ";
			cout << result[i][j];
		}
		cout << endl;
	}
	getchar();
	system("pause");
	return 0;
}