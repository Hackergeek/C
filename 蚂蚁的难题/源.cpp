#include<iostream>
#include<vector>
#include<utility>
#include<memory.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
int len;
int num;
vector< pair<int,int> > v;
int a[1000][10000];
bool cmp(pair<int,int> v1,pair<int,int> v2)
{
	return v1.second<v2.second;
}
int calc()
{
	memset(a,0,sizeof(a));
	for(int i=1;i<=num;i++)
	{
		for(int j=1;j<=len;j++)
		{
			if(j<v[i-1].second) a[i][j]=a[i-1][j];
			else a[i][j]=max(a[i-1][j],a[i-1][j-v[i-1].first]+v[i-1].first);
		}
	}
	return a[num][len];
}
void init()
{
	while(scanf_s("%d%d",&num,&len)!=EOF)
	{
		v.clear();
		int l1,l2;
		int m=num;
		while(m--)
		{
			scanf_s("%d%d",&l1,&l2);
			v.push_back(make_pair(l1,l2));
		}
		sort(v.begin(),v.end(),cmp);
		printf("%d\n",calc());
	}
}
int main()
{
	init();
	return 0;
}
