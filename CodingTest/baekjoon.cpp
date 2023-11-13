

//#define BAEKJOON
#ifdef BAEKJOON

#pragma region BAEKJOON_REGION


// Dynamic Programming

// 백준 2579번 - 계단 오르기 
 

/*
* 총 점수의 최댓값을 구하는 프로그램
* 
	계단 오르는 데는 다음과 같은 규칙이 있다.

	1.계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 
	즉, 한 계단을 밟으면서 이어서 다음 계단이나, 
	다음 다음 계단으로 오를 수 있다.
	
	2.연속된 세 개의 계단을 모두 밟아서는 안 된다. 
	단, 시작점은 계단에 포함되지 않는다.
	
	3.마지막 도착 계단은 반드시 밟아야 한다.
*/


#define DYNAMIC_PROGRAMMING_2579_DP
#ifdef DYNAMIC_PROGRAMMING_2579_DP

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct StairInfo
{
	int W    = 0;
	int Step = 0;
	void Init(int _w, int _step) { W = _w; Step = _step; }

};
StairInfo Memo[303];
vector<int> Stairs;

int DP()
{
	Memo[1].Init(Stairs[1], 1);
	Memo[2].Init(Stairs[2], 1);

	int StairsNum = Stairs.size();
	for (int i = 0; i < StairsNum; ++i)
	{
		int W1 = 0;
		if(i + 1 <= StairsNum - 1)
			W1 = Stairs[i + 1];
		int W2 = 0;
		if(i + 2 <= StairsNum - 1)
			W2 = Stairs[i + 2];

		int W = 0;
		int S = 0;

		if (Memo[i + 1].W <= Memo[i].W + W1)
		{
			if (Memo[i].Step == 1)
			{
				Memo[i + 1].Init(Memo[i].W + W1, 2);
			}
		}

		if (Memo[i + 2].W <= Memo[i].W + W2)
		{
	
			Memo[i + 2].Init(Memo[i].W + W2, 1);
			
		}

	
	}

	return Memo[StairsNum - 1].W;
}

int main()
{
	int StairsNum = 0;
	cin >> StairsNum;

	Stairs.push_back(0);			// 시작 지점  
	for (int i = 0; i < StairsNum; ++i)
	{
		int StepNum = 0;
		cin >> StepNum;
		Stairs.push_back(StepNum); // 계단  
	}

	int output = DP();
	cout << output;

	return 0;
}

#endif // DYNAMIC_PROGRAMMING_2579_DP


/* 시간초과 */
//#define DYNAMIC_PROGRAMMING_2579_DFS
#ifdef DYNAMIC_PROGRAMMING_2579_DFS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> Stairs;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
int step = 1;

int DFS(int idx, int step, int acc)
{
	if (idx <= 0)
		return acc;

	int Acc       = acc;			// 누적값 
	int MyWeight  = Stairs[idx];	// 현재 가중치값  
	int result[2] = { 0, 0 };		// 결과값 저장  

	if (step == 1)
	{
		result[0] = DFS(idx - 1, 2, Acc + MyWeight);
		result[1] = DFS(idx - 2, 1, Acc + MyWeight);
	}

	if (step == 2)
	{
		result[1] = DFS(idx - 2, 1, Acc + MyWeight);
	}

	int output = max(result[0], result[1]);
	return output;


}

int main()
{
	int StairsNum = 0;
	cin >> StairsNum;

	Stairs.push_back(0);			// 시작 지점  
	for (int i = 0; i < StairsNum; ++i)
	{
		int StepNum = 0;
		cin >> StepNum;
		Stairs.push_back(StepNum); // 계단  
	}
	int output = DFS(StairsNum, 1, 0);
	cout << output;

	return 0;

}

#endif // DYNAMIC_PROGRAMMING_2579_DFS


// 백준 1463번 - 1로 만들기

/*
	정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

		1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
		2. X가 2로 나누어 떨어지면, 2로 나눈다.
		3. 1을 뺀다.
*/
//#define DYNAMIC_PROGRAMMING
#ifdef DYNAMIC_PROGRAMMING

#include <iostream>
using namespace std;

int g_Memo[1'000'001] = { 0, };
int DP(int n)
{
	int input = n;
	int output;

	for (int i = 2; i <= input; ++i)
	{

		int result = 0;

		result = g_Memo[i - 1] + 1;
		if (i % 3 == 0)
		{
			if(g_Memo[i / 3] + 1 < result)
				result = g_Memo[i / 3] + 1;
		}

		if (i % 2 == 0)
		{
			if(g_Memo[i / 2] + 1 < result)
				result = g_Memo[i / 2] + 1;
		}
		g_Memo[i] = result;
	}

	output = g_Memo[input];
	return output;
}


int main(void)
{
	int input;
	int output;

	cin >> input;
	output = DP(input);
	cout << output;


	return 0;
}


#endif // DYNAMIC_PROGRAMMING


//#define DFS_TIME_OUT
#ifdef DFS_TIME_OUT
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int g_memoization[1'000'001] = { 0, };

int DFS(int num, int cnt)
{
	int input  = num;
	

	if (input  == 1)
		return cnt ;
	
	vector<int> output;
	output.push_back(INT_MAX);	
	output.push_back(INT_MAX);
	output.push_back(INT_MAX);

	if (input % 3 == 0)
		output[0] = DFS(input / 3, cnt + 1);

	output[1] = DFS(input - 1, cnt + 1);

	if (input % 2 == 0)
		output[2] = DFS(input / 2, cnt + 1);

	int MinCnt = *min_element(output.begin(), output.end());
	return MinCnt;

}
int main()
{
	int input  = 0;
	int output = 0;
	int Cnt    = 0;

	cin >> input;
	if (1 <= input && output <= 1'000'000)
		output = DFS(input, Cnt);
	cout << output;
	return 0;
}
#endif // DFS_TIME_OUT


//#define WRONG_ANSWER
#ifdef WRONG_ANSWER

#include <iostream>
using namespace std;
/*
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
*/

static int g_Cnt = 0;
void MakeOne(int n)
{
	cout << n << endl;

	int input = n;
	if (input == 1)
		return;

	if (input % 3 == 0)
	{
		g_Cnt++;
		MakeOne(input / 3);
	}
	else if (input % 3 == 1)
	{
		g_Cnt++;
		if (input % 2 == 0)
			MakeOne(input / 2);
		else
			MakeOne(input - 1);
	}
	else if (input % 3 == 2)
	{
		g_Cnt++;

		if (input % 2 == 0)
			MakeOne(input / 2);
		else
			MakeOne(input - 1);

	}

	return;
}

int main()
{
	int input = 0;
	int output = 0;

	cin >> input;
	MakeOne(input);
	output = g_Cnt;
	cout << output;

	return 0;
}
#endif // WRONG_ANSWER




#pragma endregion // BEAKJOON_REGION
#endif // BAEKJOON

