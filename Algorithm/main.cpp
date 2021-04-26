#include <stdio.h>
#include <string>

//---------------------------------------------------------------------------
//1부터 N까지 M의 배수 합
//자연수 N이 입력되면 1부터 N까지의 수 중 M의 배수합을 출력하는 프로그램 작성
//---------------------------------------------------------------------------
//나의 풀이 : N과 M을 입력받고 for문으로 반복하면서 M의 배수를 구한다.
//i를 M으로 나누엇을때 0으로 떨어진다면 i는 M의 배수라고 할 수 있다.
//따라서 Sum(합)에 나누어 떨어진 i값을 더하여 Sum값을 구한다.
//---------------------------------------------------------------------------
void Question1()
{
	int N, M;
	int Sum = 0;

	scanf_s("%d %d", &N, &M);

	for (int i = 0; i <= N; i++)
	{
		if (i % M == 0)
		{
			Sum += i;
		}
	}

	printf("%d", Sum);
}

//---------------------------------------------------------
//자연수의 합
//자연수 A,B가 주어지면 A부터 B까지의 합을 수식과 함께 출력
//---------------------------------------------------------
//나의 풀이 : A와 B를 입력받고 A부터 B까지의 합을 Sum에 누적시켜준다.
//---------------------------------------------------------
void Question2()
{
	int A;
	int B;
	int i;
	int Sum = 0;

	scanf_s("%d %d", &A, &B);

	for (i = A; i < B; i++)
	{
		Sum += i;
		printf("%d+", i);
	}

	printf("%d=%d", i, Sum);
}

//--------------------------------------------------------------------------------------
//진약수의 합
//자연수 N이 주어지면 자연수 N의 진약수(자기 자신을 제외한 약수)의 합을 수식과 함께 출력
//--------------------------------------------------------------------------------------
//나의 풀이 : N을 입력받고 반복하면서 N의 약수를 구한다.
//N을 i로 나누엇을대 0으로 떨어진다면 i는 N의 약수라고 할수 있다.
//진약수이므로 자기자신은 제외하고 약수를 구하고 약수의 합을 Sum에 누적시킨다.
//--------------------------------------------------------------------------------------
void Question3()
{
	int N;
	int i;
	int Sum = 0;

	scanf_s("%d", &N);
	printf("1");
	Sum += 1;
	for (i = 2; i < N; i++)
	{
		if (N % i == 0)
		{
			printf(" + %d", i);
			Sum += i;
		}
	}

	printf(" = %d", Sum);
}

//----------------------------------------------------------------------------------------------
//나이 차이
//N(2<=N<=100)명의 나이가 입력된다. 이 N명의 사람 중 가장 나이차이가 많이 나는 경우는 몇살일까요?
//최대 나이 차이를 출력
//----------------------------------------------------------------------------------------------
//나의 풀이 : N명을 입력받는다. 반복문을 돌리면서 나이를 입력받고
//각각의 나이에 대해 Max와 Min값을 구하여 반복문이 끝나고 난 후 해당 차이를 구하면
//최대 나이 차이를 구한것과 같다.
//----------------------------------------------------------------------------------------------
void Question4()
{
	int Max = -9999999;
	int Min = 99999999;
	int Count;
	int Number;

	scanf_s("%d", &Count);

	for (int i = 0; i < Count; i++)
	{
		scanf_s("%d", &Number);		
		if (Number > Max)
		{
			Max = Number;
		}

		if (Number < Min)
		{
			Min = Number;
		}
	}
		
	int Answer = Max - Min;
	printf("%d", Answer);	
}

//------------------------------------------------------------------------------------------------------------------------
//나이 계산
//주민등록증의 번호가 주어지면 주민등록증 주인의 나이와 성별을 판단하여 출력하는 프로그램
//을 작성하세요.주민등록증의 번호는 - 를 기준으로 앞자리와 뒷자리로 구분된다.
//뒷자리의 첫 번째 수가 1이면 1900년대생 남자이고, 2이면 1900년대생 여자, 3이면 2000년대생 남자, 4이면 2000년대생 여자이다. 
//올해는 2019년입니다.해당 주민등록증 주인의 나이와 성별을 출력하세요
//------------------------------------------------------------------------------------------------------------------------
//나의 풀이 : 주민번호를 문자열로 입력받는다. 000000-0000000 7번째 자리의 값이 무엇인지 우선 판단하고
// 1 or 2라면 2019에서 birthYear을 빼고 1900년대 생이므로 1900을 뺀후 한국 나이 + 1을 더해 나이를 구한다.
// 3 or 4라면 2019에서 birthYear을 빼고 2000년대 생이므로 2000을 뺀후 한국 나이 + 1을 더해 나이를 구한다.
// [7] 값이 1 or 3이면 남성 2 or 4이면 여성으로 표시한다.
//------------------------------------------------------------------------------------------------------------------------
//다른 풀이 : 나이 값을 구하는 부분에서 아스키코드 값을 이용하여 구하는 방법
//ex) 문자열 910407 -> [0] = 9 [1] = 1 -> [0] * 10 + [1] -> 9 * 10 + 1 -> 91
//문자열로 저장했으니까 48값을 빼줘야 실제 수값이 나온다.
//따라서 ([0] - 48 ) *10 + ( [1] - 48 ) 이렇게 계산해야 91의 값이 정확하게 나온다.
//------------------------------------------------------------------------------------------------------------------------
void Question5()
{
	int Age;
	char HumanNumber[255];
	char BirthYear[2];

	scanf_s("%s", HumanNumber, sizeof(HumanNumber));
	memcpy(BirthYear, HumanNumber, 2);

	if (HumanNumber[7] == '1' || HumanNumber[7] == '2')
	{
		Age = 2019 - atoi(BirthYear) - 1900 + 1;
	}
	else
	{
		Age = 2019 - atoi(BirthYear) - 2000 + 1;
	}

	//나이 아스키 값으로 계산
	//int Askey = 1900 + (HumanNumber[0] - 48) * 10 + (HumanNumber[1] - 48);	

	printf("%d", Age);

	if (HumanNumber[7] == '1' || HumanNumber[7] == '3')
	{
		printf(" M\n");
	}
	else
	{
		printf(" W\n");
	}
}

//------------------------------------------------------------------------------------------------------------------------
//숫자만 추출
//문자와 숫자가 섞여있는 문자열이 주어지면 그 중 숫자만 추출하여 그 순서대로 자연수를 만듭니다.
//만들어진 자연수와 그 자연수의 약수 개수를 출력합니다. 
//만약 “t0e0a1c2her”에서 숫자만 추출하면 0, 0, 1, 2이고 이것을 자연수를 만들면 12가 됩니다.
//즉 첫 자리 0은 자연수화 할 때 무시합니다.출력은 12를 출력하고, 다음 줄에 12의 약수의 개수를 출력하면 됩니다.
//추출하여 만들어지는 자연수는 100, 000, 000을 넘지 않습니다.
//------------------------------------------------------------------------------------------------------------------------
//나의 풀이 : 문자와 숫자가 섞여잇는 문자열을 받는다. 문자열중에서 '0' ~ '9' 범위안에 문자가 있으면 뽑아서 새로운 배열에 담는다.
//담은 배열을 문자열로 만들어주고 완성된 문자열 배열을 atoi를 이용해 수로 변환시켜준다.
//변환한 수를 반복문으로 돌리면서 약수의 개수를 구해준다.
//------------------------------------------------------------------------------------------------------------------------
//다른 풀이 : 수를 뽑아서 담는 부분에서 나는 atoi를 이용해 수로 변환시켯지만
//다른 풀이 방법으로는 발견되는 수를 누적시켜 가며 수를 발견하는 방법이 있는데, 다음과 같다.
//우선 입력받은 문자열에서 '0' ~ '9'가 있는지 확인한다.
//발견 되면 Sum = Sum * 10 + (Str[i]-48) 식을 사용해 값을 누적시켜간다.
//(Str[i]-48) 이 식은 위에서 언급한 아스키 코드값에 따라 문자에 해당하는 수를 구하기 위한 식
//ex) 문자열에서 0 2 8 이라는 수가발견되면
//위의 식에 따라 
//0 = 0 * 10 + ('0'-48) -> 0
//2 = 0 * 10 + ('2'-48) -> 2
//28 = 2 * 10 + ('8'-48) -> 28  28의 값 출력
//------------------------------------------------------------------------------------------------------------------------
void Question6()
{
	char Str[255];
	char NumStr[255];

	int Count = 0;

	scanf_s("%s", Str, sizeof(Str));

	for (int i = 0; i < strlen(Str); i++)
	{
		if (Str[i] >= '0' && Str[i] <= '9')
		{
			NumStr[Count] = Str[i];
			Count++;
		}
	}

	NumStr[Count] = '\0';

	int AnswerNum = atoi(NumStr);
	int AliquotCount = 0;

	printf("%d", AnswerNum);

	for (int i = 1; i <= AnswerNum; i++)
	{
		if (AnswerNum % i == 0)
		{
			AliquotCount++;
		}
	}

	printf("\n%d", AliquotCount);

	int res = 0;
	//다른 풀이
	for (int i = 0; i < strlen(Str); i++)
	{
		if (Str[i] >= '0' && Str[i] <= '9')
		{
			//0 = 0 * 10 + 0
			//2 = 0 * 10 + 2
			//28 = 2 * 10 + 8
			res = res * 10 + (Str[i] - 48);
		}
	}
}

//---------------------------------------------------------------------------------------------------------
//영어단어 복구
//현수의 컴퓨터가 바이러스에 걸려 영어단어가 뛰어쓰기와 대소문자가 혼합되어 표현된다.
//예를 들면 아름다운 이란 뜻을 가지고 있는 beautiful 단어가 “bE au T I fu L” 과 같이
//컴퓨터에 표시되고 있습니다.위와 같이 에러로 표시되는 영어단어를 원래의 표현대로 공백을
//제거하고 소문자화 시켜 출력하는 프로그램을 작성하세요.
//---------------------------------------------------------------------------------------------------------
//나의 풀이 : 문자열을 입력받는다. 문자열을 반복문을 돌려서 검사한다.
//공백 부분은 제외하고 공백이 아니라면 발견된 수가 대문자 일시 32를 더해줘서 소문자로 변경해준 후 저장한다.
//---------------------------------------------------------------------------------------------------------
void Question7()
{
	char Str[255];
	char AnswerStr[255];
	int AnswerCount = 0;

	gets_s(Str, sizeof(Str));

	for (int i = 0; i < strlen(Str); i++)
	{
		if (Str[i] != ' ')
		{
			if (Str[i] >= 'A' && Str[i] <= 'Z')
			{
				AnswerStr[AnswerCount] = Str[i] + 32;
			}
			else
			{
				AnswerStr[AnswerCount] = Str[i];
			}

			AnswerCount++;
		}
	}

	AnswerStr[AnswerCount] = '\0';

	printf("%s", AnswerStr);
}

//-----------------------------------------------------------------------------------------------
//올바른 괄호
//괄호가 입력되면 올바른 괄호이면 “YES", 올바르지 않으면 ”NO"를 출력합니다.
//(())() 이것은 괄호의 쌍이 올바르게 위치하는 거지만, (()()))은 올바른 괄호가 아니다.
//-----------------------------------------------------------------------------------------------
//나의 풀이 : 문자열을 입력받고 (이 발견되면 Count를 ++ )가 발견되면 Count를 -- 해줘서 판단해준다.
//-----------------------------------------------------------------------------------------------
void Question8()
{
	char Str[255];
	int Count = 0;

	scanf_s("%s", Str, sizeof(Str));

	for (int i = 0; i < strlen(Str); i++)
	{
		if (Str[i] == '(')
		{
			Count++;
		}

		if (Str[i] == ')')
		{
			Count--;
		}
	}

	if (Count == 0)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
}

//----------------------------------------------------------------------------------------------------------------------------------
//모두의 약수
//자연수 N이 입력되면 1부터 N까지의 각 숫자들의 약수의 개수를 출력하는 프로그램을 작성하세요.
//만약 N이 8이 입력된다면 1(1개), 2(2개), 3(2개), 4(3개), 5(2개), 6(4개), 7(2개), 8(4개) 와 같이 각 숫자의 약수의 개수가 구해집니다.
//출력은 다음과 같이 1부터 차례대로 약수의 개수만 출력하면 됩니다.
//1 2 2 3 2 4 2 4 와 같이 출력한다.
//----------------------------------------------------------------------------------------------------------------------------------
//나의 풀이 : N을 입력받고 이중 for문을 사용해 약수의 개수를 구한다. 이렇게 하면 n^2만큼 속도가 나와서 속도가 너무 느리다.
//----------------------------------------------------------------------------------------------------------------------------------
//다른 풀이 : 이중 for문을 도는데 두번째 for문의 j의 값이 i값에 따라 달라지는 i의 배수를 의미하도록 해주것이 핵심
//N만큼의 크기 배열을 준비하고 0 값으로 초기화해준다. 
//N이 8일 경우
//[1][2][3][4][5][6][7] 8 크기만큼의 배열 준비 [0]은 의미 없으므로 제외
//각각의 인덱스를 수로 인식해준다. 
//i가 1일때 j를 1의 배수로 움직이고
//i가 2일때 j를 2의 배수로 움직이면서 i가 n일때 j를 n의 배수로 움직여준다.
//i가 2면 j가 2의 배수로 움직이니까
//[2]에서 카운트가 하나 증가하고 [4]에서 카운트 증가 [6]에서 카운트 증가 이런식으로 i가 N - 1까지 증가하면서 판단해주면
//[1][2][3][4][5][6][7]에 있는 수의 값이 각 숫자들의 약수의 개수가 되는 것
//j가 배수만큼 이동하니까 검사하는 수가 현저히 줄어든다.
//----------------------------------------------------------------------------------------------------------------------------------
void Question9()
{
	int Number;
	int Count;

	scanf_s("%d", &Number);
	Number += 1;
	int* Numbers = (int*)malloc(sizeof(int) * Number);

	memset(Numbers, 0, sizeof(int)*Number);

	//1번째 방법 n^2 만큼 속도가 나옴
	/*for (int i = 1; i <= Number; i++)
	{
		Count = 0;

		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0)
			{
				Count++;
			}
		}
		printf("%d ", Count);
	}	*/

	for (int i = 1; i < Number; i++)
	{
		for (int j = i; j < Number; j += i/* j가 배수로 가는 것이 핵심 ex) i가 2면 2씩 증가함*/)
		{
			Numbers[j]++;
		}
	}

	for (int i = 1; i < Number; i++)
	{
		printf("%d ", Numbers[i]);
	}

	free(Numbers);
}

//----------------------------------------------------------------------------------------------------------------
//자릿수의 합
//N개의 자연수가 입력되면 각 자연수의 자릿수의 합을 구하고, 그 합이 최대인 자연수를 출력하는 프로그램을 작성하세요.
//각 자연수의 자릿수의 합을 구하는 함수를 int digit_sum(int x)를 꼭 작성해서 프로그래밍 하세요.
//----------------------------------------------------------------------------------------------------------------
//나의 풀이 : N을 입력받고  DigitSum 함수에 N을 넘겨서 자릿수의 합을 구한다.
//자릿수의 합이 이전 수의 자릿수의 합보다 크다면 Max 값을 갱신해준다.
//자릿수가 동일한 값이 나오면 두 수중에서 더 큰 값을 저장해둔다.
//----------------------------------------------------------------------------------------------------------------
int DigitSum(int Number)
{
	int Sum = 0;

	for (int i = 0; Number > 0; i++)
	{
		Sum += Number % 10;
		Number = Number / 10;
	}

	return Sum;
}
void Question10()
{
	int Count;
	int Number;
	int NumberSum;
	int Max = -999999;
	int CompareNum = 0;

	scanf_s("%d", &Count);

	for (int i = 0; i < Count; i++)
	{
		scanf_s("%d", &Number);

		NumberSum = DigitSum(Number);

		//자릿수 합이 이전 Max 값보다 크면 Max 값 갱신
		if (NumberSum >= Max)
		{
			CompareNum = Number;
			Max = NumberSum;
		}
		else if (Max == NumberSum) // 그 이전 최댓값과 같다면
		{
			if (Number > CompareNum) // 두수를 비교해서 더 큰 값을 저장해둠
			{
				CompareNum = Number;
			}
		}
	}

	printf("%d", CompareNum);
}

//---------------------------------------------------------------------------------------------
//숫자의 총 개수
//자연수 N이 입력되면 1부터 N까지의 자연수를 종이에 적을 때 각 숫자는 몇 개 쓰였을까요?
//예를 들어 1부터 15까지는 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5으로
//총 21개가 쓰였음을 알 수 있습니다.
//자연수 N이 입력되면 1부터 N까지 각 숫자는 몇 개가 사용되었는지를 구하는 프로그램을 작성하세요.
//3<=N<=100000
//---------------------------------------------------------------------------------------------
//나의 풀이 : 수를 입력받고 1부터 입력받은 수까지 자릿수(10으로 나눠가면서 구하기)를 구해준다.
//---------------------------------------------------------------------------------------------
void Question11()
{
	int Number;
	int CountNumber = 0;
	int Count = 0;

	scanf_s("%d", &Number);

	for (int i = 1; i <= Number; i++)
	{
		CountNumber = i;

		while (CountNumber > 0)
		{
			Count++;
			CountNumber = CountNumber / 10;
		}
	}

	printf("%d", Count);
}

//---------------------------------------------------------------------------------------------
//숫자의 총 개수
//자연수 N이 입력되면 1부터 N까지의 자연수를 종이에 적을 때 각 숫자는 몇 개 쓰였을까요?
//예를 들어 1부터 15까지는 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5으로
//총 21개가 쓰였음을 알 수 있습니다.
//자연수 N이 입력되면 1부터 N까지 각 숫자는 몇 개가 사용되었는지를 구하는 프로그램을 작성하세요.
//3<=N<=100,000,000
//---------------------------------------------------------------------------------------------
//나의 풀이 : 
//---------------------------------------------------------------------------------------------
void Question12()
{

}

//---------------------------------------------------------------------------------------------
//가장 많이 사용된 자릿수
//N자리의 자연수가 입력되면 입력된 자연수의 자릿수 중 가장 많이 사용된 숫자를 출력하는 프로그램을 작성하세요.
//예를 들어 1230565625라는 자연수가 입력되면 5가 3번 상용되어 가장 많이 사용된 숫자입니다.
//답이 여러 개일 경우 그 중 가장 큰 수를 출력하세요.
//---------------------------------------------------------------------------------------------
//나의 풀이 : 수를 입력받고 배열을 준비한다.
//배열의 인덱스를 수에 매칭하여 생각한다. [0] (실제 0) [1] (실제 1) [2] (실제 2) [3] (실제 3) [4] (실제 4)... 
//수를 자릿수마다 검사하여 해당하는 인덱스에 수를 증가시켜준다.
//ex) 0이 검사 되면 [0] 인덱스의 값을 1 증가 시켜줌
//검사가 완료되면 가장 많이 사용된 숫자를 출력하는데 값이 같으면 그 중 가장 큰 수를 뽑는다.
//---------------------------------------------------------------------------------------------
void Question13()
{
	char Number[100];
	int CheckNumber[10] = { 0 };
	int Max = -9999;
	int AnswerNumber;

	scanf_s("%s", Number, sizeof(Number));

	for (int i = 0; i < strlen(Number); i++)
	{
		if (Number[i] >= '0' && Number[i] <= '9')
		{
			CheckNumber[Number[i] - 48]++;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (CheckNumber[i] > Max)
		{
			Max = CheckNumber[i];
			AnswerNumber = i;
		}
		else if (CheckNumber[i] == Max)
		{
			if (i > AnswerNumber)
			{
				AnswerNumber = i;
			}
		}
	}

	printf("%d", AnswerNumber);
}

//----------------------------------------------------------------------------------------------------------------------
//뒤집은 소수
//N개의 자연수가 입력되면 각 자연수를 뒤집은 후 그 뒤집은 수가 소수이면 그 수를 출력하는 프로그램을 작성하세요.
//예를 들어 32를 뒤집으면 23이고, 23은 소수이다.그러면 23을 출력한다.
//단 910를 뒤집으면 19로 숫자화 해야 한다.첫 자리부터의 연속된 0은 무시한다.
//뒤집는 함수인 int reverse(int x) 와 소수인지를 확인하는 함수 bool isPrime(int x)를 반드시 작성하여 프로그래밍 한다.
//----------------------------------------------------------------------------------------------------------------------
//나의 풀이 : 수를 입력받고 우선 뒤집은 수를 구한다.
//나머지를 구하고 나머지를 누적시키고 그 이전값에 10을 곱하여 뒤집은 수를 구한다.
//뒤집은수에 대해 소수인지 판단해주는데 만약 뒤집은 수가 2부터 나누어 떨어지는 수가 있으면 소수가 아닌것으로 판단해준다.
//----------------------------------------------------------------------------------------------------------------------
int Reverse(int X)
{
	int ReverseNumber = 0;
	int Remainder;	

	while (X > 0)
	{
		Remainder = X % 10;
		ReverseNumber = ReverseNumber * 10 + Remainder;
		X = X / 10;
	}

	return ReverseNumber;
}
bool IsPrime(int X)
{
	for (int i = 2; i < X; i++)
	{
		if (X % i == 0)
		{
			return false;
		}		
	}

	return true;
}
void Question14()
{
	int Number;
	int PrimeCheckNumber;
	bool IsPrimeNumber;

	scanf_s("%d", &Number);

	for (int i = 0; i < Number; i++)
	{
		scanf_s("%d",&PrimeCheckNumber);

		int ReverseNumber = Reverse(PrimeCheckNumber);
		IsPrimeNumber = IsPrime(ReverseNumber);

		if (IsPrimeNumber)
		{
			printf("%d ", ReverseNumber);
		}
	}
}
//-----------------------------------------------------------------------------------
//1부터 입력받은 n까지 소수 개수 구하기
//자연수 N이 입력되면 1부터 N까지의 소수의 개수를 출력하는 프로그램을 작성하세요.
//만약 20이 입력되면 1부터 20까지의 소수는 2, 3, 5, 7, 11, 13, 17, 19로 총 8개입니다.
//제한시간은 1초입니다.
//-----------------------------------------------------------------------------------
//나의 풀이 : 자연수 N을 입력받고 반복하면서 소수를 판단해준다.
//0으로 나누어 떨어지는게 만약 있으면 소수가 아니니까 다음 수가 소수인지 아닌지 판단한다.
//-----------------------------------------------------------------------------------0
void Question15()
{
	int Number;
	int Count = 0;
	bool IsPrimeNumber;

	scanf_s("%d", &Number);

	//1은 소수 제외니까 2부터 시작
	for (int i = 2; i <= Number; i++)
	{
		IsPrimeNumber = true;

		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				//j가 i의 약수로 판단 되니까 소수 아니라고 판단해줌
				IsPrimeNumber = false;
				break;
			}
		}

		if (IsPrimeNumber == true)
		{
			Count++;
		}
	}

	printf("%d", Count);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
//Anagram(아나그램)
//Anagram이란 두 문자열이 알파벳의 나열 순서를 다르지만 그 구성이 일치하면 두 단어는 아나그램이라고 합니다.
//예를 들면 AbaAeCe 와 baeeACA 는 알파벳을 나열 순서는 다르지만 그 구성을 살펴보면 A(2), a(1), b(1), C(1), e(2)로 알파벳과 그 개수가 모두 일치합니다.
//즉 어느 한 단어를 재배열하면 상대편 단어가 될 수 있는 것을 아나그램이라 합니다.
//길이가 같은 두 개의 단어가 주어지면 두 단어가 아나그램인지 판별하는 프로그램을 작성하세요.
//아나그램 판별시 대소문자가 구분됩니다.
//---------------------------------------------------------------------------------------------------------------------------------------------------
//나의 풀이 : 아스키코드를 이용해서 풀엇는데, A~Z a~z에 해당하는 수에서 아스키코드값에 해당하는 값을 빼서 각각의 알파벳이 인덱스에 매칭되게 만들어준다.
//A~Z - 65 -> 0 ~ 25 a~z -> a~z - 71 -> 26 ~ 51
//두 문자열을 각 자리를 검사하면서 위에 해당하는 값이 있으면 해당 인덱스 값 자리를 1씩 늘려준다.
//검사를 마치고 난 후 비교 하여 자리의 수가 모두 같으면 아나그램으로 판단해준다.
//---------------------------------------------------------------------------------------------------------------------------------------------------
void Question16()
{
	char LeftStr[100];
	char RightStr[100];

	bool IsAnagram = true;

	int LeftCheck[100];
	int RightCheck[100];

	scanf_s("%s", LeftStr, sizeof(LeftStr));
	scanf_s("%s", RightStr, sizeof(RightStr));

	for (int i = 0; i < strlen(LeftStr); i++)
	{
		if (LeftStr[i] >= 'A' && LeftStr[i] <= 'Z')
		{
			LeftCheck[LeftStr[i] - 65]++;
		}

		if (LeftStr[i] >= 'a' && LeftStr[i] <= 'z')
		{
			LeftCheck[LeftStr[i] - 71]++;
		}

		if (RightStr[i] >= 'A' && RightStr[i] <= 'Z')
		{
			RightCheck[RightStr[i] - 65]++;
		}

		if (RightStr[i] >= 'a' && RightStr[i] <= 'z')
		{
			RightCheck[RightStr[i] - 71]++;
		}
	}

	for (int i = 0; i < 50; i++)
	{
		if (LeftCheck[i] != RightCheck[i])
		{
			IsAnagram = false;
			break;
		}
	}

	if (IsAnagram == true)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
}

//-----------------------------------------------------------------------------------------------------------------------
//선생님 퀴즈
//현수네 반은 학생이 N명 있습니다.
//수업도중 선생님이 잠깐 자리를 비워야 하는데 그 동안 학생들이 떠들거나 놀지 않도록 각 학생들에게 퀴즈를 냈습니다.
//선생님은 각 학생들에게 숫자가 적힌 카드를 줬습니다.각 학생들은 1부터 자기 카드에 적힌 숫자까지의 합을 구하는 퀴즈입니다.
//선생님이 돌아와서 각 학생들의 답이 맞았는지 확인을 하려고 하는데 너무 힘들어서 여러분에게
//자동으로 채점을 하는 프로그램을 부탁했습니다.여러분이 선생님을 도와주세요.
//-----------------------------------------------------------------------------------------------------------------------
//나의 풀이 : 입력받은 학생수 만큼 반복하면서 학생별로 적힌 숫자끼리 합을 구해준다.
//-----------------------------------------------------------------------------------------------------------------------
void Question17()
{
	int StudentNumber;
	int FindNumber;
	int AnswerNumber;
	int Sum;
	int Find;

	scanf_s("%d", &StudentNumber);

	for (int i = 0; i < StudentNumber; i++)
	{
		scanf_s("%d", &FindNumber);
		scanf_s("%d", &AnswerNumber);

		Sum = 0;

		for (int j = 1; j <= FindNumber; j++)
		{
			Sum += j;
		}

		if (Sum == AnswerNumber)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}

//-----------------------------------------------------------------------------------------------------------------------
//층간소음
//T편한 세상 아파트는 층간소음 발생 시 윗집의 발뺌을 방지하기 위해 애초 아파트를 지을 때
//바닥에 진동센서를 설치했습니다.이 센서는 각 세대의 층간 진동소음 측정치를 초단위로 아파트 관리실에 실시간으로 전송합니다.
//그리고 한 세대의 측정치가 M값을 넘으면 세대호수와 작은 경보음이 관리실 모니터에서 울립니다.
//한 세대의 N초 동안의 실시간 측정치가 주어지면 최대 연속으로 경보음이 울린 시간을 구하세요.
//경보음이 없으면 - 1를 출력합니다.
//-----------------------------------------------------------------------------------------------------------------------
//나의 풀이 : 측정치와 최대 측정치 값을 입력받고 측정값들을 입력받는다.
//측정값이 최대 측정치 값을 넘으면 카운트를 늘려주고 다음 측정값이 넘지 않는다면 0으로 초기화한다.
//위처럼 반복하면서 카운트가 최대 몇인지 저장해둔다.
//-----------------------------------------------------------------------------------------------------------------------
void Question18()
{
	int Count;
	int Check;
	int Max = -999999;
	int Answer;
	int CountCheck = 0;

	scanf_s("%d", &Count);
	scanf_s("%d", &Check);

	for (int i = 0; i < Count; i++)
	{
		scanf_s("%d", &Answer);

		if (Answer > Check)
		{
			CountCheck++;
		}
		else
		{
			CountCheck = 0;
		}

		if (CountCheck > Max)
		{
			Max = CountCheck;
		}
	}

	if (Max == 0)
	{
		printf("-1");
	}
	else
	{
		printf("%d", Max);
	}
}

//------------------------------------------------------------------------------------------------------------------------------------------------------
//분노 유발자
//오늘은 수능이 끝난 다음날로 교장선생님은 1, 2학년 재학생들에게 강당에 모여 어벤져스 영화를 보여준다고 하여 학생들이 강당에 모였습니다.
//강당의 좌석은 영화관처럼 계단형이 아니라 평평한 바닥에 의자만 배치하고 학생들이 앉습니다.
//그런데 만약 앞자리에 앉은 키가 큰 학생이 앉으면 그 학생보다 앉은키가 작은 뒷자리 학생은 스크린이 보이지 않습니다.
//한 줄에 앉은키 정보가 주어지면 뒷사람 모두의 시야를 가려 영화 시청이 불가능하게 하는 분노유발자가 그 줄에 몇 명이 있는지 구하는 프로그램을 작성하세요.
//------------------------------------------------------------------------------------------------------------------------------------------------------
//나의 풀이 : 학생수를 입력받고 학생들의 키를 배열에 따로 저장해둔다.
//저장한 키들을 가지고 검사를 한다.
//기준이 되는 키 뒤에 있는 키들이 기준키보다 크다면 카운트를 늘려가다가 작은 것이 있으면 반복문을 빠져나와서
//늘려준 카운트가 기준 키 뒤에 있는 키들의 개수와 같다면 분노 유발자로 판단해준다.
//------------------------------------------------------------------------------------------------------------------------------------------------------
void Question19()
{
	int StudentNumber;
	int TallValue[100];
	int Tall;
	int Count;
	int Answer = 0;

	scanf_s("%d", &StudentNumber);

	for (int i = 0; i < StudentNumber; i++)
	{
		scanf_s("%d", &Tall);

		TallValue[i] = Tall;
	}

	for (int i = 0; i < StudentNumber - 1; i++)
	{
		Count = 0;

		for (int j = i + 1; j < StudentNumber; j++)
		{
			if (TallValue[i] > TallValue[j])
			{
				Count++;
			}
			else
			{
				break;
			}
		}

		if (Count == StudentNumber - i - 1)
		{
			Answer++;
		}
	}

	printf("%d", Answer);
}

//--------------------------------------------------------------------------------------
//가위 바위 보
//A, B 두 사람이 가위바위보 게임을 합니다. 총 N번의 게임을 하여 A가 이기면 A를 출력하고,
//B가 이기면 B를 출력합니다.비길 경우에는 D를 출력합니다.
//가위, 바위, 보의 정보는 1:가위, 2 : 바위, 3 : 보로 정하겠습니다.
//--------------------------------------------------------------------------------------
//나의 풀이 : N번 동안 A , B가 낸 가위 바위 보를 각각의 배열에 저장하고
//저장한 배열 값을 비교해준다.
//--------------------------------------------------------------------------------------
void Question20()
{
	int GameNumber;
	int AAnswer;
	int BAnswer;
	int AAnswers[100];
	int BAnswers[100];

	scanf_s("%d", &GameNumber);

	for (int i = 0; i < GameNumber; i++)
	{
		scanf_s("%d", &AAnswer);
		AAnswers[i] = AAnswer;
	}

	for (int i = 0; i < GameNumber; i++)
	{
		scanf_s("%d", &BAnswer);
		BAnswers[i] = BAnswer;
	}

	for (int i = 0; i < GameNumber; i++)
	{
		if (AAnswers[i] == BAnswers[i])
		{
			printf("D\n");
		}
		else if (AAnswers[i] == 1 && BAnswers[i] == 3)
		{
			printf("A\n");
		}
		else if (AAnswers[i] == 2 && BAnswers[i] == 1)
		{
			printf("A\n");
		}
		else if (AAnswers[i] == 3 && BAnswers[i] == 2)
		{
			printf("A\n");
		}
		else
		{
			printf("B\n");
		}
	}
}

//--------------------------------------------------------------------------------------------------
//카드 게임
//0부터 9까지의 숫자가 표시된 카드를 가지고 두 사람 A와 B가 게임을 한다. 
//A와 B에게는 각각 0에서 9까지의 숫자가 하나씩 표시된 10장의 카드뭉치가 주어진다.
//두 사람은 카드를 임의의 순서로 섞은 후 숫자가 보이지 않게 일렬로 늘어놓고 게임을 시작한다.
//단, 게임 도중 카드의 순서를 바꿀 수는 없다. 
//A와 B 각각이 늘어놓은 카드를 뒤집어서 표시된 숫자를 확인하는 것을 한 라운드라고 한다.
//게임은 첫 번째 놓인 카드부터 시작하여 순서대로 10번의 라운드로 진행된다.
//각 라운드에서는 공개된 숫자가 더 큰 사람이 승자가 된다.
//승자에게는 승점 3점이 주어지고 패자에게는 승점이 주어지지 않는다.
//만약 공개된 두 숫자가 같아서 비기게 되면, A, B 모두에게 승점 1점이 주어진다.
//10번의 라운드가 모두 진행된 후, 총 승점이 큰 사람이 게임의 승자가 된다.
//만약, A와 B의 총 승점이 같은 경우에는, 제일 마지막에 이긴 사람을 게임의 승자로 정한다.
//그래도 승부가 나지 않는 경우는 모든 라운드에서 비기는 경우뿐이고 이 경우에 두 사람은 비겼다고 한다.
//---------------------------------------------------------------------------------------------------
//나의 풀이 : 20번 문제와 마찬가지로 A B가 낸 카드 값들을 각각의 배열에 저장해둔다.
//저장한 배열의 값을 비교하면서 승점을 계산해준다.
//승점이 같을때 마지막에 이긴사람을 판단해주기 위해 bool 변수를 이용해서 기록해둔다.
//---------------------------------------------------------------------------------------------------
void Question21()
{
	int AAnswers[10];
	int AAnswer;
	int BAnswers[10];
	int BAnswer;

	int AScore = 0;
	int BScore = 0;

	bool AWin = false;
	bool BWin = false;

	for (int i = 0; i < 10; i++)
	{
		scanf_s("%d", &AAnswer);
		AAnswers[i] = AAnswer;
	}

	for (int i = 0; i < 10; i++)
	{
		scanf_s("%d", &BAnswer);
		BAnswers[i] = BAnswer;
	}

	for (int i = 0; i < 10; i++)
	{
		if (AAnswers[i] > BAnswers[i])
		{
			AScore += 3;

			AWin = true;
			BWin = false;
		}
		else if (BAnswers[i] > AAnswers[i])
		{
			BScore += 3;

			AWin = false;
			BWin = true;
		}
		else
		{
			AScore += 1;
			BScore += 1;
		}
	}

	printf("%d %d", AScore, BScore);

	if (AScore == BScore && AWin == true)
	{
		printf("A\n");
	}
	else if (AScore == BScore && BWin == true)
	{
		printf("B\n");
	}
	else if (AScore > BScore)
	{
		printf("A\n");
	}
	else if (BScore > AScore)
	{
		printf("B\n");
	}
	else
	{
		printf("D\n");
	}
}

//------------------------------------------------------------------------------------------------------------------------------------
//온도의 최대값
//매일 아침 9시에 학교에서 측정한 온도가 어떤 정수의 수열로 주어졌을 때, 연속적인 며칠 동안의 온도의 합이 가장 큰 값을 알아보고자 한다.
//예를 들어, 다음과 같이 10일 간의 온도가 주어졌을 때, 
//3 -2 -4  -9  0  3  7  13  8 - 3 모든 연속적인 이틀간의 온도의 합은 다음과 같다.
// 1  -6 -13 -9  3  10 20 21  5
//이때, 온도의 합이 가장 큰 값은 21이다. 
//매일 측정한 온도가 정수의 수열로 주어졌을 때, 연속적인 며칠 동안의 온도의 합이 가장 큰 값을 계산하는 프로그램을 작성하시오.
//------------------------------------------------------------------------------------------------------------------------------------
//나의 풀이 : 온도의 갯수와 연속구간 기준값을 받아준다.
//배열에 온도들을 담고 기준값만큼 배열항목들의 합을 구한다.
//온도 갯수가 10만이 넘어가고 검사 갯수가 30000만정도가 되면 속도가 현저히 떨어지는데, n^2 의 속도가 나와서
//------------------------------------------------------------------------------------------------------------------------------------
//다른 풀이 : n의 속도로 나오게끔 해줘야하는데 다음과 같다.
//3 -2 -4  -9  0  3  7  13  8 - 3
//위와 같이 수가 입력되고 검사 구간이 2일때
//첫번째 값은  3  -2 =  1 
//두번째 값은 -2  -4 = -6 두번째 값은 이렇게도 표현 할 수 있다. 
//         (3 -2) -4 -(3) = -6 
//즉, 이전값에 다음 값을 더하고나서 맨처음 값을 빼주면 다음 구간의 합이 되는 것
//이런식으로 밀고 나가면 n의 속도로 해답을 구할 수 있다.
//------------------------------------------------------------------------------------------------------------------------------------
void Question22()
{
	int TemperatureCount;
	int Countinue;
	int* Temperatures;
	int Max = -9999999;
	int Sum = 0;

	int Temperature;

	scanf_s("%d", &TemperatureCount);
	scanf_s("%d", &Countinue);

	Temperatures = (int*)malloc(sizeof(int)*TemperatureCount);

	for (int i = 0; i < TemperatureCount; i++)
	{
		scanf_s("%d", &Temperature);
		Temperatures[i] = Temperature;
	}

	//속도가 안나옴
	/*for (int i = 0; i < TemperatureCount - Countinue; i++)
	{
		Sum = 0;

		for (int j = i; j < i + Countinue; j++)
		{
			Sum += Temperatures[j];
		}

		if (Sum > Max)
		{
			Max = Sum;
		}
	}*/

	for (int i = 0; i < Countinue; i++)
	{
		Sum += Temperatures[i];
	}

	Max = Sum;

	for (int i = Countinue; i < TemperatureCount; i++)
	{
		Sum += Temperatures[i] - Temperatures[i - Countinue];

		if (Sum > Max)
		{
			Max = Sum;
		}
	}

	printf("%d", Max);
	free(Temperatures);
}

//------------------------------------------------------------------------------------------------------------------------------------
//연속 부분 증가수열
//N개의 숫자가 나열된 수열이 주어집니다.
//이 수열 중 연속적으로 증가하는 부분 수열을 최대 길이를 구하여 출력하는 프로그램을 작성하세요.
//만약 N = 9이고 5 7 3 3 12 12 13 10 11 이면 “3 3 12 12 13”부분이 최대 길이 증가수열이므로 그 길이인
//5을 출력합니다. 값이 같을 때는 증가하는 걸로 생각합니다.
//------------------------------------------------------------------------------------------------------------------------------------
//나의 풀이 : 수를 입력받고 해당 수와 그 이전 수를 비교하여 크기가 같거나 큰지 비교해준다.
//------------------------------------------------------------------------------------------------------------------------------------
void Question23()
{
	int Number;
	int CheckNumber;
	int PreviousNumber = 0;
	int CurrentNumber = 0;
	int Max = -999999;
	int Length = 0;

	scanf_s("%d", &Number);

	for (int i = 0; i < Number; i++)
	{
		scanf_s("%d", &CheckNumber);
		CurrentNumber = CheckNumber;

		if (CurrentNumber >= PreviousNumber)
		{
			Length++;
		}
		else
		{
			Length = 1;
		}

		if (Length > Max)
		{
			Max = Length;
		}

		PreviousNumber = CurrentNumber;
	}

	printf("%d", Max);
}

//------------------------------------------------------------------------------------------------------------------------------------
//Jolly Jumpers
//N개의 정수로 이루어진 수열에 대해 서로 인접해 있는 두 수의 차가 1에서 N-1까지의 값을 모두 가지면 그 수열을 유쾌한 점퍼(jolly jumper)라고 부른다.
//예를 들어 다음과 같은 수열에서 1 4 2 3 앞 뒤에 있는 숫자 차의 절대 값이 각각 3, 2, 1이므로 이 수열은 유쾌한 점퍼가 된다.
//어떤 수열이 유쾌한 점퍼인지 판단할 수 있는 프로그램을 작성하라.
//------------------------------------------------------------------------------------------------------------------------------------
//나의 풀이 : 수를 입력받고 배열을 준비해둔다.
//배열 인덱스를 활용해서 문제를 풀엇는데, 두수의 차를 구하고 두수의 차에 해당하는 인덱스 값을 증가시켜준다.
//만약 그 값이 0이 아니라면 이미 이전에서 기록된것이니까 Jolly Jumpers라고 할 수없다.
//------------------------------------------------------------------------------------------------------------------------------------
void Question24()
{
	int Number;
	int CheckNumber;
	int PreviousNumber;
	int CurrentNumber;
	int* CheckArray;
	int Index;
	bool JollyJumperCorrect = true;

	scanf_s("%d", &Number);

	CheckArray = (int*)malloc(sizeof(int) * Number);
	memset(CheckArray, 0, sizeof(int) * Number);

	scanf_s("%d", &PreviousNumber);

	for (int i = 1; i < Number; i++)
	{
		scanf_s("%d", &CheckNumber);
		CurrentNumber = CheckNumber;

		Index = abs(CurrentNumber - PreviousNumber);
		
		if (Index >= 1 && Index <= Number - 1 && CheckArray[Index] == 0)
		{
			CheckArray[Index]++;			
		}
		else
		{
			JollyJumperCorrect = false;
			break;
		}

		PreviousNumber = CurrentNumber;
	}

	if (JollyJumperCorrect)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}

	free(CheckArray);
}

//------------------------------------------------------------------------------------------------------------------------------------
//석차 구하기
//N명 학생의 수학점수가 입력되면 각 학생의 석차를 입력된 순서대로 출력하는 프로그램을 작성하세요.
//------------------------------------------------------------------------------------------------------------------------------------
//나의 풀이 : 학생수를 입력받고 수학점수를 점수 배열에 저장한다.
//석차를 의미하는 석차배열의 값을 각각 학생 수로 초기화 해주고
//수학점수를 하나 뽑아서 점수배열을 순회하며 석차를 구한다.
//------------------------------------------------------------------------------------------------------------------------------------
void Question25()
{
	int Number;
	int CheckNumber;
	int* RankArray;
	int* CheckArray;
	
	scanf_s("%d", &Number);

	RankArray = (int*)malloc(sizeof(int)*Number);
	CheckArray = (int*)malloc(sizeof(int)*Number);
	
	for (int i = 0; i < Number; i++)
	{
		scanf_s("%d", &CheckNumber);
		CheckArray[i] = CheckNumber;
		RankArray[i] = Number;
	}

	for (int i = 0; i < Number; i++)
	{
		for (int j = 0; j < Number; j++)
		{
			//자기자신은 제외
			if (i != j && CheckArray[i] >= CheckArray[j] )
			{
				RankArray[i]--;
			}
		}
	}

	for (int i = 0; i < Number; i++)
	{
		printf("%d ", RankArray[i]);
;	}

	free(RankArray);
	free(CheckArray);
}

//------------------------------------------------------------------------------------------------------------------------------------
//마라톤
//KSEA 장거리 달리기 대회가 진행되어 모든 선수가 반환점을 넘었다. 각 선수의 입장에서 자기보다 앞에 달리고 있는 선수들 중 평소 실력이
//자기보다 좋은 선수를 남은 거리 동안 앞지르는 것은 불가능하다. 반대로, 평소 실력이 자기보다 좋지 않은 선수가 앞에 달리고 있으면
//남은 거리 동안 앞지르는 것이 가능하다.이러한 가정 하에서 각 선수는 자신이 앞으로 얻을수 있는 최선의 등수를 알 수 있다.
//각 선수의 평소 실력은 정수로 주어지는데 더 큰 값이 더 좋은 실력을 의미한다. 현재 달리고 있는 선수를 앞에서 부터 표시했을 때
//평소 실력이 각각 2, 8, 10, 7, 1, 9, 4, 15라고 하면 각 선수가 얻을 수 있는 최선의 등수는(같은 순서로) 각각 1, 1, 1, 3, 5, 2, 5, 1이 된다.
//예를 들어, 4번째로 달리고 있는 평소 실력이 7인 선수는 그 앞에서 달리고 있는 선수들 중 평소 실력이 2인 선수만 앞지르는 것이 가능하고
//평소실력이 8과 10인 선수들은 앞지르는 것이 불가능하므로, 최선의 등수는 3등이 된다. 선수들의 평소 실력을 현재 달리고 있는 순서대로
//입력 받아서 각 선수의 최선의 등수를 계산하는 프로그램을 작성하시오. 동일한 실력이면 초월하지 못한다.
//------------------------------------------------------------------------------------------------------------------------------------
//나의 풀이 : 선수 수를 입력받고 각 선수의 실력을 저장해둔다.
//순서대로 등수를 저장해주고 1 2 3 4 5 6 7 ...
//실력 배열에서 수를 뽑은 후 앞자리부터 비교해서 자신보다 값이 작으면 등수를 1씩 줄여준다.
//------------------------------------------------------------------------------------------------------------------------------------
void Question26()
{
	int Number;
	int Score;
	int* ScoreArray;
	int* RankArray;
	int CheckScore;

	scanf_s("%d", &Number);

	ScoreArray = (int*)malloc(sizeof(int) * Number);
	RankArray = (int*)malloc(sizeof(int) * Number);

	for (int i = 0; i < Number; i++)
	{
		scanf_s("%d", &Score);
		ScoreArray[i] = Score;
		RankArray[i] = i + 1;
	}

	for (int i = 0; i < Number; i++)
	{
		//자신 기준점까지만 비교
		for (int j = 0; j < i; j++)
		{
			if (ScoreArray[i] > ScoreArray[j])
			{
				RankArray[i]--;
			}
		}
	}

	for (int i = 0; i < Number; i++)
	{
		printf("%d", RankArray[i]);
	}
}

//------------------------------------------------------------------------------------------------------------------------------------
//N!의 표현법
//임의의 N에 대하여 N!은 1부터 N까지의 곱을 의미한다. 이는 N이 커짐에 따라 급격하게 커진다.
//이러한 큰 수를 표현하는 방법으로 소수들의 곱으로 표현하는 방법이 있다.
//먼저 소수는 2, 3, 5, 7, 11, 13...순으로 증가함을 알아야 한다.
//예를 들면 825는(0 1 2 0 1)로 표현이 가능한데, 이는 2는 없고 3은 1번, 5는 2번, 7은 없고, 11은 1번의 곱이라는 의미이다.
//101보다 작은 임의의 N에 대하여 N 팩토리얼을 이와 같은 표기법으로 변환하는 프로그램을 작성해 보자.
//------------------------------------------------------------------------------------------------------------------------------------
//나의 풀이 : N을 입력받고 소수의 개수를 판별할 PrimeCheck 배열을 준비한다.
//인덱스에 해당하는 값들이 소수의 개수를 의미한다. PrimeCheck[2] = 2라면 2가 2개 있는것
//초기에는 0으로 초기화 해주고 입력받은 N이 1~N까지의 수를 반복하면서 2부터 나눠주면서 소수의 개수를 구한다.
//------------------------------------------------------------------------------------------------------------------------------------
void Question27()
{
	int Number;
	int Factor;
	int* PrimeCheck;
	int j;
	
	scanf_s("%d", &Number);

	PrimeCheck = (int*)malloc(sizeof(int) * (Number + 1));
	memset(PrimeCheck, 0, sizeof(int) * (Number + 1));

	//2부터 시작한다.
	for (int i = 2; i <= Number; i++)
	{
		Factor = i;
		j = 2;

		while (1)
		{
			//위에서 받은 Factor을 j(2) 부터 나눠준다.
			//나눠 떨어지면 해당하는 PrimeCheck[j]를 1증가시켜줘서 소수의 개수를 판단한다.
			//또한 Factor을 j로 나눠준다. 
			if (Factor % j == 0)
			{
				PrimeCheck[j]++;
				Factor = Factor / j;
			}
			else
			{
				j++;
			}		

			//나눠지는 수가 1이 되면 나가서 다음수를 받아온다.
			if (Factor == 1)
			{
				break;
			}
		}
	}

	printf("%d! = ", Number);

	for (int i = 0; i <= Number; i++)
	{
		if (PrimeCheck[i] != 0)
		{
			printf("%d ", PrimeCheck[i]);
		}
	}
}

int main()
{
	Question27();
	return 0;
}

