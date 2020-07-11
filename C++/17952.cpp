#include <iostream>
#include <algorithm>

using namespace std;

class sub{
	private:
		int time;
		int score;

	public:
		void DO(int *len, int *total)
		{
			time--;
			if(time == 0)
			{
				(*len)--;
				(*total) += score;
				
			}
		}

		void input()
		{
			cin >> score >> time;
		}
};

int main(void)
{
	int n;
	cin >> n;

	int flag;
	int len = 0;
	int score, minute;

	int fianl_score = 0;

	sub *arr = new sub[n];
	
	for(int i = 0; i < n; ++i)
	{
		cin >> flag;
		if(flag == 1)
		{
			len++;
			arr[len].input();
			arr[len].DO(&len, &fianl_score);
		}
		else
		{
			arr[len].DO(&len, &fianl_score);
		}
	}

	delete[] arr;

	cout << fianl_score;

	return 0;
}