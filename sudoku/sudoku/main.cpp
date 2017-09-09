#include "stdafx.h"
#include "generator.h"
using namespace std;

int N;//要求生成的矩阵数

bool oknum(string s)
{
	//判断参数是否合法，即是否为1~100W之间的整数
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
	printf("请输入正确参数");
	return 0;
	}
	printf("参数正确，开始生成%d个数独\n",N);
	generator Gen;
	Gen.init(N);
	Gen.work();
	return 0;
}