
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

// �ּ��� ��� �뿩 ��� 
double RockFestival(vector<int> &CostPerDay, int TeamCnt)
{
	double MinCost;
	// �����ؼ� �뿩���� �� �ּ� ����� ���Ѵ�. 

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
		int N;	// �뿩�� �� �ִ� ���� �� 
		int L;	// �̹� ������ ���� ���� ��  
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


