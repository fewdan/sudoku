#include "stdafx.h"
#include "generator.h"
using namespace std;

int N;//Ҫ�����ɵľ�����

bool oknum(string s)
{
	//�жϲ����Ƿ�Ϸ������Ƿ�Ϊ1~100W֮�������
	int sz = s.size();
	N = 0;
	for (int i = 0; i < sz; ++i)
	{
		if (isdigit(s[i]) == 0)
		{
			return 0;
		}
		N = N * 10 + s[i] - '0';
		if (N > 1000000)
		{
			return 0;
		}
	}
	if (N < 1 || N>1000000)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main(int argc, char* args[])
{
	if (argc != 3 || strcmp(args[1], "-c") != 0 || !oknum(args[2]))
	{
	printf("��������ȷ����");
	return 0;
	}
	printf("������ȷ����ʼ����%d������\n",N);
	generator Gen;
	Gen.init(N);
	Gen.work();
	return 0;
}