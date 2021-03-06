#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

//------------------------------------------------------------------------------------------------------------------------------------------------------
//어떤 자연수 p와 q가 있을 때, 만일 p를 q로 나누었을 때 나머지가 0이면 q는 p의 약수이다.
//6을 예로 들면
//6 / 1 = 6 ... 0
//6 / 2 = 3 ... 0
//6 / 3 = 2 ... 0
//6 / 4 = 1 ... 2
//6 / 5 = 1 ... 1
//6 / 6 = 1 ... 0
//그래서 6의 약수는 1, 2, 3, 6, 총 네개이다.
//두 개의 자연수 N과 K가 주어졌을 때, N의 약수들 중 K번째로 작은 수를 출력하는 프로그램을 작성하시오.
//입력
//첫째 줄에 N과 K가 빈칸을 사이에 두고 주어진다. N은 10000 이하이다.
//K는 1 이상 N 이하이다.
//출력
//첫째 줄에 N의 약수들 중 K번째로 작은 수를 출력한다.
//만일 N의 약수의 개수가 K개보다 적어서 K번째 약수가 존재하지 않을 경우에는 0을 출력하시오.
//------------------------------------------------------------------------------------------------------------------------------------------------------
void Question2501()
{
	int Array[10000];
	int Index = 0;
	int Position;
	
	memset(Array, 0, sizeof(Array));
	int Number;

	scanf_s("%d", &Number);
	scanf_s("%d", &Position);

	for (int i = 1; i <= Number; i++)
	{
		//입력받은 Number를 i(1) 부터 나눳을때 0으로 떨어지면 약수로 판단해준다.
		if (Number % i == 0)
		{
			Array[Index] = i;
			Index++;
		}
	}	

	if (Index != 0)
	{
		printf("%d", Array[Position - 1]);
	}
	else
	{
		printf("0");
	}
}

//------------------------------------------------------------------------------------------------------------------------------------------------------
//양의 정수 n이 주어졌을 때, 이를 이진수로 나타냈을 때 1의 위치를 모두 찾는 프로그램을 작성하시오.
//최하위 비트의 위치는 0이다.
//입력
//첫째 줄에 테스트 케이스의 개수 T가 주어진다.
//각 테스트 케이스는 한 줄로 이루어져 있고, n이 주어진다. (1 <= T <= 10 , 1 <= n <= 10^6)
//출력
//각 테스트 케이스에 대해서, 1의 위치를 공백으로 구분해서 줄 하나에 출력한다.
//위치가 낮은 것부터 출력한다.
//------------------------------------------------------------------------------------------------------------------------------------------------------
void Question3460()
{
	int TestNumber;
	int Number;
	int Remain;
	
	scanf_s("%d", &TestNumber);	
	
	while (TestNumber > 0)
	{
		int i = 0;

		scanf_s("%d", &Number);		

		TestNumber--;

		while (Number > 0)
		{
			Remain = Number % 2;
			if (Remain == 1) //나머지가 1이면 i위치를 출력해준다.
			{
				printf("%d ", i);
			}

			Number /= 2;
			i++;
		}
		printf("\n");
	}	
}

//------------------------------------------------------------------------------------------------------------------------------------------------------
//최소 최대
//N개의 정수가 주어진다.
//이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.
//입력
//첫째 줄에 정수의 개수 N(1 <= N <= 1000000)이 주어진다.
//둘째 줄에는 N개의 정수를 공백으로 구분해서 주어진다.
//모든 정수는 -1,000,000보다 크거나 같고, 1,000,000보다 작거나 같은 정수이다.
//출력
//첫째 줄에 주어진 정수 N개의 최솟값과 최댓값을 공백으로 구분해 출력한다.
//------------------------------------------------------------------------------------------------------------------------------------------------------
void Question10818()
{
	int Number;
	int Data;

	int Max = -1000000;
	int Min = 1000000;

	scanf_s("%d", &Number);
	
	//Number만큼 반복하면서 최댓값, 최솟값을 구한다.
	for (int i = 0; i < Number; i++)
	{
		scanf_s("%d", &Data);

		if (Data > Max)
		{
			Max = Data;
		}

		if (Data < Min)
		{
			Min = Data;
		}
	}

	printf("%d %d", Min, Max);
}

//------------------------------------------------------------------------------------------------------------------------------------------------------
//지능형 기차 2
//최근에 개발된 지능형 기차가 1번역(출발역)부터 10번역(종착역)까지 10개의 정차역이 있는 노선에서 운행되고 있다.
//이 기차에는 타거나 내리는 사람 수를 자동으로 인식할 수 있는 장치가 있다.
//이 장치를 이용하여 출발역에서 종착역까지 가는 도중 기차 안에 사람이 가장 많을 때의 사람 수를 계산하려고 한다.
//단, 이 기차를 이용하는 사람들은 질서 의식이 투철하여, 역에서 기차에 탈 때, 내릴 사람이 모두 내린 후에 기차에 탄다고 가정한다.
//				 내린 사람 탄 사람
//1번역(출발역)		0		32
//2번역				3		13
//3번역				28		25
//4번역				17		5
//5번역				21		20
//6번역				11		0
//7번역				12		12
//8번역				4		2
//9번역				0		8
//10번역(종착역)	21		0
//예를 들어, 위와 같은 경우 기차 안에 사람이 가장 많은 때는 2번역에서 3명의 사람이 기차에서 내리고,
//13명의 사람이 기차에 탔을 때로, 총 42명의 사람이 기차 안에 있다.
//이 기차는 다음 조건을 만족하면서 운행된다고 가정한다.
//1. 기차는 역 번호 순서대로 운행한다.
//2. 출발역에서 내린 사람 수와 종착역에서 탄 사람 수는 0이다.
//3. 각 역에서 현재 기차에 있는 사람보다 더 많은 사람이 내리는 경우는 없다.
//4. 기차의 정원은 최대 10,000명이고, 정원을 초과하여 타는 경우는 없다.
//10개의 역에 대해 기차에서 내린 사람 수와 탄 사람 수가 주어졌을 때, 기차에 사람이 가장 많을 때의 사람 수를 계산하는 프로그램을 작성하시오.
//입력
//각 역에서 내린 사람 수와 탄 사람 수가 빈칸을 사이에 두고 첫째 줄부터 열 번째 줄까지 역 순서대로 한 줄에 하나씩 주어진다.
//출력
//첫째 줄에 최대 사람 수를 출력한다.
//------------------------------------------------------------------------------------------------------------------------------------------------------
void Question2460()
{
	int Sum = 0;
	int LetDownPeople;
	int ToRidePeople;
	int Max = -999999;

	//10번 반복하면서 내린사람, 탄사람의 합을 구하고 그 중 가장 큰 합을 구해준다.
	for (int i = 0; i < 10; i++)
	{
		scanf_s("%d %d", &LetDownPeople, &ToRidePeople);

		Sum = Sum - LetDownPeople + ToRidePeople;

		if (Sum > Max)
		{
			Max = Sum;
		}
	}

	printf("%d", Max);
}

//------------------------------------------------------------------------------------------------------------------------------------------------------
//피보나치 수
//피보나치 수는 0과 1로 시작한다. 
//0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다.
//그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.
//이를 식으로 써보면 Fn = Fn-1+Fn-2(n>=2)가 된다.
//n=17일때 까지 피보나치 수를 써보면 다음과 같다.
//0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597
//n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.
//입력
//첫째 줄에 n이 주어진다. n은 20보다 작거나 같은 자연수 또는 0이다.
//출력
//첫째 줄에n번째 피보나치 수를 출력한다.
//------------------------------------------------------------------------------------------------------------------------------------------------------
void Question10870()
{
	int Number;

	scanf_s("%d", &Number);

	int* Array = (int*)malloc(sizeof(int)*(Number + 1));
	
	//첫번째와 두번째 피보나치 수 0 과 1 저장
	Array[0] = 0;
	Array[1] = 1;

	//3번째 부터 피보나치 수열을 구해주는데 전전과 전 값을 더해서 저장해준다.
	for (int i = 2; i < Number + 1; i++)
	{
		Array[i] = Array[i - 2] + Array[i - 1];
	}

	printf("%d",Array[Number]);

	free(Array);
}

//------------------------------------------------------------------------------------------------------------------------------------------------------
//일곱 난쟁이
//왕비를 피해 일곱 난쟁이들과 함께 평화롭게 생활하고 있던 백설공주에게 위기가 찾아왔다.
//일과를 마치고 돌아온 난쟁이가 일곱 명이 아닌 아홉 명이었던 것이다.
//아홉 명의 난쟁이는 모두 자신이 "백설 공주와 일곱 난쟁이"의 주인공이라고 주장했다.
//뛰어난 수학적 직관력을 가지고 있던 백설공주는, 다행스럽게도 일곱 난쟁이의 키의 합이 100이 됨을 기억해 냈다.
//아홉 난쟁이의 키가 주어졌을 때, 백설공주를 도와 일곱 난쟁이를 찾는 프로그램을 작성하시오.
//입력
//아홉 개의 줄에 걸쳐 난쟁이들의 키가 주어진다.
//주어지는 키는 100을 넘지 않는 자연수이며, 아홉 난쟁이의 키는 모두 다르며, 가능한 정답이 여러 가지인 경우에는 아무거나 출력한다.
//출력
//일곱 난쟁이의 키를 오름차순으로 출력한다.
//일곱 난쟁이를 찾을 수 없는 경우는 없다.
//------------------------------------------------------------------------------------------------------------------------------------------------------
void Question2309()
{	
	int Sum = 0;
	bool Flag = false;	

	int* Array = (int*)malloc(sizeof(int)*9);

	for (int i = 0; i < 9; i++)
	{
		scanf_s("%d", &Array[i]);
		//키 총합을 구해둔다.
		Sum += Array[i];
	}

	//미리 정렬해둔다.		
	sort(Array, Array + 9);

	//9명중 7명의 키가 100이 되는 말은 
	//9명의 총합 키에서 2명의 키를 뺏을때 그 값이 100이 된다는 말과 같다.
	for (int i = 0; i < 8; i++)
	{
		for (int j = 1; j < 9; j++)
		{			
			//총합키에서 2 항목의 값을 뺏을때 100이 되면
			//해당 인덱스를 제외하고 출력해준다.
			if (Sum - (Array[i] + Array[j]) == 100)
			{
				Flag = true;
				for (int k = 0; k < 9; k++)
				{
					if (k != i && k != j)
					{
						printf("%d\n", Array[k]);
					}
				}
				break;
			}
		}

		if (Flag == true)
		{
			break;
		}
	}
}

//------------------------------------------------------------------------------------------------------------------------------------------------------
//최대공약수와 최소공배수
//두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.
//입력
//첫째 줄에는 두 개의 자연수가 주어진다.
//이 둘은 10000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.
//출력
//첫째 줄에는 입력으로 주어진 두 수의 최대공약수를,
//둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.
//------------------------------------------------------------------------------------------------------------------------------------------------------
void Question2609()
{
	int Array[10001];
	int NumberOne;
	int NumberTwo;
	//최대 공약수
	int Max = 1;
	//최소 공배수
	int Min;

	memset(Array, 0, sizeof(Array));
	
	scanf_s("%d %d", &NumberOne, &NumberTwo);
	
	//첫번째 수 약수 구하기
	for (int i = 1; i <= NumberOne; i++)
	{
		if (NumberOne % i == 0)
		{
			Array[i]++;
		}
	}

	//두번째 수 약수 구하기
	for (int i = 1; i <= NumberTwo; i++)
	{
		if (NumberTwo % i == 0)
		{
			Array[i]++;
		}
	}
	
	//최대 공약수 구하기
	for (int i = 1; i <= 10000; i++)
	{
		if (Array[i] == 2)
		{
			if (i > Max)
			{
				Max = i;
			}
		}
	}	

	//최대 공약수로 수 나누기
	int NumberOneMin = NumberOne / Max;
	int NumberTwoMin = NumberTwo / Max;
	
	//최대 공약수로 나눈 몫과 최대 공약수 곱해서 최소 공배수 구하기
	Min = NumberOneMin * NumberTwoMin * Max;

	printf("%d\n%d", Max, Min);
}

//------------------------------------------------------------------------------------------------------------------------------------------------------
//N번째 큰 수
//배열 A가 주어졌을 때, N번째 큰 값을 출력하는 프로그램을 작성하시오.
//배열 A의 크기는 항상 10이고, 자연수만 가지고 있다.
//N은 항상 3이다.
//입력
//첫째 줄에 테스트 케이스의 개수 T(1<= T <=1000)가 주어진다.
//각 테스트 케이스는 한 줄로 이루어져있고, 배열 A의 원소 10개가 공백으로 구분되어 주어진다. 
//이 원소는 1보다 크거나 같고, 1000보다 작거나 같은 자연수이다.
//출력
//각 테스트 케이스에 대해 한 줄에 하나씩 배열 A에서 3번째 큰 값을 출력한다.
//------------------------------------------------------------------------------------------------------------------------------------------------------
void Question2693()
{
	int TestNumber;
	int Array[10];

	scanf_s("%d", &TestNumber);

	int AnswerPrint = TestNumber;

	int* AnswerArray = (int*)malloc(sizeof(int)*TestNumber);
	int AnswerCount = 0;

	//TestNumber만큼 반복하면서
	for (; TestNumber > 0; TestNumber--)
	{
		//수를 받는다.
		for (int i = 0; i < 10; i++)
		{
			scanf_s("%d", &Array[i]);
		}		

		//오름 차순으로 정렬하고
		sort(Array, Array + 10);

		//3번째로 큰수를 저장해둔다.
		AnswerArray[AnswerCount] = Array[7];
		AnswerCount++;
	}

	//저장해둔 수를 출력해준다.
	for (int i = 0; i < AnswerPrint; i++)
	{
		printf("%d\n", AnswerArray[i]);
	}

	free(AnswerArray);
}

//------------------------------------------------------------------------------------------------------------------------------------------------------
//소수 찾기
//주어진 수 n개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.
//입력
//첫 줄에 수의 개수 N이 주어진다.
//N은 100이하이다.
//다음으로 N개의 수가 주어지는데 수는 1000 이하의 자연수이다.
//출력
//주어진 수들 중 소수의 개수를 출력한다.
//------------------------------------------------------------------------------------------------------------------------------------------------------
void Question1978()
{
	int Number;
	int CheckNumber;
	bool IsPrimeNumber; //소수 인지 판단
	int PrimeNumberCount = 0;

	scanf_s("%d", &Number);

	for (int i = 0; i < Number; i++)
	{
		IsPrimeNumber = true;

		scanf_s("%d", &CheckNumber);

		for (int j = 2; j < CheckNumber; j++)
		{
			//1과 자기자신을 제외하고 0으로 나누어떨어지면 소수 아니라고 판단
			if (CheckNumber % j == 0)
			{
				IsPrimeNumber = false;
				break;
			}
		}

		//1 제외
		if (IsPrimeNumber && CheckNumber != 1)
		{
			PrimeNumberCount++;
		}
	}	

	printf("%d", PrimeNumberCount);
}

//------------------------------------------------------------------------------------------------------------------------------------------------------
//쉽게 푸는 문제
//동호는 내년에 초등학교를 입학한다.
//그래서 동호 어머니는 수학 선행 학습을 위해 쉽게 푸는 문제를 동호에게 주었다.
//이 문제는 다음과 같다.
//1을 한 번, 2를 두 번, 3을 세 번, 이런 식으로 1 2 2 3 3 3 4 4 4 4 5 ... 이러한 수열을 만들고 어느 일정한 구간을 주면 그 구간의 합을 구하는 것이다.
//하지만 동호는 현재 더 어려운 문제를 푸느라 바쁘기에 우리가 동호를 도와주자.
//입력
//첫째 줄에 구간의 시작과 끝을 나타내는 정수 A, B(1 <= A <= B <= 1000)가 주어진다.
//즉, 수열에서 A번째 숫자부터 B번째 숫자까지 합을 구하면 된다.
//출력
//첫 줄에 구간에 속하는 숫자의 합을 출력한다.
//------------------------------------------------------------------------------------------------------------------------------------------------------
void Question1292()
{
	int StartNumber;
	int EndNumber;
	int Input = 0;
	int Sum = 0;

	//배열 시작 끝 인덱스 입력 받음
	scanf_s("%d %d", &StartNumber, &EndNumber);

	//동적으로 배열 잡아줌
	int* Array = (int*)malloc(sizeof(int)*EndNumber);
	memset(Array, 0, sizeof(int)*EndNumber);

	for (int i = 1; EndNumber > Input; i++)
	{
		//숫자 넣을때 몇번 넣을건지 
		int InputNumber = i;

		while (InputNumber > 0)
		{
			Array[Input] = i;
			InputNumber--;
			Input++;

			if (Input >= EndNumber)
			{
				break;
			}
		}
	}

	for (int i = StartNumber - 1; i < EndNumber; i++)
	{
		Sum += Array[i];
	}

	printf("%d", Sum);

	free(Array);
}

//------------------------------------------------------------------------------------------------------------------------------------------------------
//소수
//자연수 M과 N이 주어질 때 M이상 N이하의 자연수 중 소수인 것을 모두 골라 이들 소수의 합과 최솟값을 찾는 프로그램을 작성하시오.
//예를 들어 M=60, N=100인 경우 60이상 100이하의 자연수 중 소수는 61, 67, 71, 73, 79, 83, 89, 97 총 8개가 있으므로,
//이들 소수의 합은 620이고, 최솟값은 61이 된다.
//입력
//입력의 첫째 줄에 M이, 둘째 줄에 N이 주어진다.
//M과 N은 10000이하의 자연수이며, M은 N보다 작거나 같다.
//출력
//M이상 N이하의 자연수 중 소수인 것을 모두 찾아 첫째 줄에 그 합을, 둘째 줄에 그 중 최솟값을 출력한다.
//단, M이상 N이하의 자연수 중 소수가 없을 경우는 첫째 줄에 -1을 출력한다.
//------------------------------------------------------------------------------------------------------------------------------------------------------
void Question2581()
{
	int MNumber;
	int NNumber;
	int PrimeNumberSum = 0;
	int MinPrimeNumber = 999999;
	bool IsPrimeNumber;
	bool IsPrimeCheck = false;

	scanf_s("%d %d", &MNumber,&NNumber);

	for (int i = MNumber; i <= NNumber; i++)
	{
		IsPrimeNumber = true;

		
		//소수 판단
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				IsPrimeNumber = false;
			}
		}

		if (IsPrimeNumber == true)
		{
			IsPrimeCheck = true;

			//최소값 저장
			if (MinPrimeNumber > i)
			{
				MinPrimeNumber = i;
			}

			//소수 합 구함
			PrimeNumberSum += i;
		}
	}

	if (IsPrimeCheck)
	{
		printf("%d\n%d", PrimeNumberSum, MinPrimeNumber);
	}
	else
	{
		printf("-1");
	}	
}

int main()
{
	Question2581();
	return 0;
}