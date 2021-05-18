#include <stdio.h>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

//-----------------------------------------------------------------------------------------------------
//�Ҽ� �����
//�־��� ���� �� 3���� ���� ������ �� �Ҽ��� �Ǵ� ����� ������ ���Ϸ��� �մϴ�.
//���ڵ��� ����ִ� �迭 nums�� �Ű������� �־��� ��, nums�� �ִ� ���ڵ� ��
//���� �ٸ� 3���� ��� ������ �� �Ҽ��� �Ǵ� ����� ������ return �ϵ��� solution �Լ��� �ϼ����ּ���.
//���ѻ���
//nums�� ����ִ� ������ ������ 3�� �̻� 50�� �����Դϴ�.
//nums�� �� ���Ҵ� 1 �̻� 1000 ������ �ڿ����̸�, �ߺ��� ���ڰ� ������� �ʽ��ϴ�.
//����� ��
//[1,2,3,4]   1
//[1,2,7,6,4] 4
//����� �� ����
//����� �� #1
//[1,2,4]�� �̿��ؼ� 7�� ���� �� �ֽ��ϴ�.
//����� �� #2
//[1,2,4]�� �̿��ؼ� 7�� ���� �� �ֽ��ϴ�.
//[1,4,6]�� �̿��ؼ� 11�� ���� �� �ֽ��ϴ�.
//[2,4,7]�� �̿��ؼ� 13�� ���� �� �ֽ��ϴ�.
//[4,6,7]�� �̿��ؼ� 17�� ���� �� �ֽ��ϴ�.
//-----------------------------------------------------------------------------------------------------
int Solution(int* Nums, size_t Nums_len)
{
	int Count = 0;

	for (int i = 0; i < Nums_len - 2; i++)
	{
		for (int j = i + 1; j < Nums_len - 1; j++)
		{
			for (int k = j + 1; k < Nums_len; k++)
			{
				int Sum = Nums[i] + Nums[j] + Nums[k];

				bool IsPrimeNumber = true;
				for (int l = 2; l < Sum; l++)
				{
					if (Sum % l == 0)
					{
						IsPrimeNumber = false;
						break;
					}
				}

				if (IsPrimeNumber)
				{
					Count++;
				}
			}
		}
	}

	return Count;
}

void Prime()
{
	int Array[] = { 1,2,7,6,4 };
	int Len = 5;

	int PrimeNumCount = Solution(Array, Len);

	printf("%d", PrimeNumCount);
}

int main()
{
	Prime();

	return 0;
}