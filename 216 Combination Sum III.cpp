#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int n,k;
class Solution {
public:
	vector<vector<int> >res;
  	void dfs(int k,int n,vector<int> cur){
  		if(cur.size()==k&&n==0){
  			res.push_back(cur);
  			return;
  		}
  		for (int i = (cur.size()==0)?1:cur.back()+1; i <=9; ++i)
  		{
  				if(i>n)break;
  			
  				cur.push_back(i);
  				dfs(k,n-i,cur);
  				cur.pop_back();
  				
  		}

  	}
    vector<vector<int> > combinationSum3(int k, int n) {
        std::vector<int> cur;  
        int sum=0;
        dfs(k,n,cur);
        return res;
    }
};
int main(int argc, char const *argv[])
{
	cin>>k>>n;
	vector<vector<int> >result=Solution().combinationSum3(k,n);
	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
		{
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	system("pause");
	return 0;
}