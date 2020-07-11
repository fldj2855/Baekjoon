#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

bool visited[10005];

typedef struct Data{
	int reg;
	string command;
}Data;

int D(int r);
int S(int r);
int L(int r);
int R(int r);
Data BFS(int A, int B);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	int A, B;

	cin >> t;

	while(t--)
	{
		cin >> A >> B;
		cout << BFS(A, B).command << endl;
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}

int D(int r)
{
	return (2*r)%10000;
}

int S(int r)
{
	return (r == 0 ? 9999 : r - 1);
}

int L(int r)
{
	int tmp = r/1000;
	r = (10 * r)%10000 + tmp;
	return r;
}

int R(int r)
{
	int tmp = r%10;
	r = r/10 + tmp*1000;
	return r;
}

Data BFS(int A, int B)
{
	Data ret, tmp;
	int ret_command_size = ret.command.size();
	int tmp_command_size;
	queue<Data> q;
	q.push({A, ""});

	int vD;
	int vS;
	int vL;
	int vR;

	while(!q.empty())
	{
		tmp = q.front();
		tmp_command_size = tmp.command.size();
		q.pop();

		visited[tmp.reg] = true;
		if(tmp.reg == B)
		{
			if(ret_command_size == 0 || tmp_command_size < ret_command_size)
			{
				ret = tmp;
				ret_command_size = tmp_command_size;
			}
		}
		else if(tmp_command_size < ret_command_size || ret_command_size == 0)
		{
			if(visited[vD = D(tmp.reg)] == false)
			{
				visited[vD] = true;
				q.push({vD, tmp.command + "D"});
			}
			if(visited[vS = S(tmp.reg)] == false)
			{
				visited[vS] = true;
				q.push({vS, tmp.command + "S"});
			}
			if(visited[vL = L(tmp.reg)] == false)
			{
				visited[vL] = true;
				q.push({vL, tmp.command + "L"});
			}
			if(visited[vR = R(tmp.reg)] == false)
			{
				visited[vR] = true;
				q.push({vR, tmp.command + "R"});
			}
		}
	}

	return ret;
}