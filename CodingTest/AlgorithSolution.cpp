
//#define ALGORITHM_SOLUTION_
#ifdef ALGORITHM_SOLUTION_


#include <iostream>
#include <vector>
using namespace		std;

void main()
{


}

//#define ROCK_FESTIVAL_
#ifdef ROCK_FESTIVAL_

// 최소의 평균 대여 비용 
double RockFestival(vector<int> &CostPerDay, int TeamCnt)
{
	double MinCost;
	// 연속해서 대여했을 때 최소 비용을 구한다. 

	/*
		1 2 3 1 2 3

		3 

		3 <= answerDays <= N
	
	*/

	return MinCost;
}

int main(void)
{
	vector<int> CostPerDay;
	int CaseNum;
	cin >> CaseNum;
	for (int i = 0; i < CaseNum; ++i)
	{
		int N;	// 대여할 수 있는 날의 수 
		int L;	// 이미 섭외한 공연 팀의 수  
		::cin >> N >> L;
		for (int j = 0; j < N; ++j)
		{
			CostPerDay.clear();
			int Cost;
			::cin >> Cost;
			CostPerDay.push_back(Cost);
		}

		double Output = RockFestival(CostPerDay, L);
		::cout << Output << ::endl;

	}


	return 0;
}
#endif // ROCK_FESTIVAL_

#endif // ALGORITHM_SOLUTION_


