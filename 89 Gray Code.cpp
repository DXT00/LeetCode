#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int N;
class Solution {//dfs
public:
	std::vector<int> res;
	char qufan(char a){
		if(a=='0')return '1';
		else return '0';
	}
	int stobit(string s){
		int r=1;
		int sum=0;
		for (int i = s.size()-1; i>=0;i--)
		{
			sum+=(s[i]-'0')*r;
			r*=2;
		}
		return sum;
	}
	void dfs(string s,vector<bool> visited,int size,int n){
		if(res.size()==size)return;

		res.push_back(stobit(s));
		visited[stobit(s)]=true;
		string cur=s;
		for (int i = n-1; i >=0; i--)
		{
			cur[i]=qufan(cur[i]);
			if(visited[stobit(cur)]==false){
				dfs(cur,visited,size,n);
				break;
			}
			else
				cur[i]=qufan(cur[i]);
		}

	}

    vector<int> grayCode(int n) {
    	int size=pow(2,n);
        std::vector<bool> visited(pow(2,n),false);
        string s(n,'0');
        dfs(s,visited,size,n);
        return res;
    }
};
class Solution1 {//公式法：二进制转格雷码->Gi = Bi>>1 xor Bi
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for (int i = 0; i < pow(2,n); ++i) {
            res.push_back((i >> 1) ^ i);
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
	cin>>N;
	std::vector<int> result;
	result=Solution().grayCode(N);
	for (int i = 0; i <result.size(); ++i)
		cout<<result[i]<<" ";
	cout<<endl;
	system("pause");
	return 0;
}