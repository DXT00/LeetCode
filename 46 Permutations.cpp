#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int> > res;
    int N;
    void dfs(vector<int> nums,vector<bool> visited,vector<int> cur){
        if(cur.size()==N){
            res.push_back(cur);
            return ;
        }
        for(int i=0;i<N;i++){
            if(visited[i]==false){
                visited[i]=true;
                cur.push_back(nums[i]);
                dfs(nums,visited,cur);
                cur.pop_back();
                visited[i]=false;
            }
            
        }
    }
    vector<vector<int> > permute(vector<int>& nums) {
        vector<int> cur;
        N=nums.size();
        vector<bool> visited(N,false);
        dfs(nums,visited,cur);
        return res;
    }
};
class Solution1 {//记得使用next_permutation函数前先要排序！
public:
    vector<vector<int> > permute(vector<int>& nums) {
        std::vector<int> numss(nums);
        vector<vector<int> > result;
        sort(numss.begin(), numss.end());
        do{
              result.push_back(numss);
        }while(next_permutation(numss.begin(), numss.end()));
        
        return result;
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

    result = Solution().permute(nums);

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