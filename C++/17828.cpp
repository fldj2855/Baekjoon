#include<bits/stdc++.h>

int main(void)
{
	int idx=0,k;
	long long int N,X,B[26]={0};
	std::cin>>N>>X;
	
	if(X<1*N||26*N<X){printf("!");return 0;}
	X-=B[0]=N;

	while(X)
	{
		B[0]-=B[25-idx]=k=X/(25-idx);
		X%=(25-idx++);
	}

	for(int i=0;i<26;++i)	while(B[i]--)	printf("%c",'A'+i);

	return 0;
}