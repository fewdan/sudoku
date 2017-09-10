#include "stdafx.h"
#include "generator.h"
using namespace std;

generator::generator()
{
}

void generator::debug()
{
	cout << "!!!!!" << endl;
}

void generator::init(int n)//初始化
{
	//freopen("..\\BIN\\sudoku.txt", "w", stdout);
	freopen("sudoku.txt", "w", stdout);
	now = 0;
	rep = n;
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	memset(InA, 0, sizeof(InA));
	memset(mat, '0', sizeof(mat));
	cnt = 1;
	mat[1][1] = '9';//学号要求
	row[1]['9'] = col[1]['9'] = InA[1]['9'] = 1;
}

namespace fastIO {//快速输出
#define BUF_SIZE 4000000

	struct Ostream_fwrite {
		char *buf, *p1, *pend;
		Ostream_fwrite() { buf = new char[BUF_SIZE]; p1 = buf; pend = buf + BUF_SIZE; }
		void out(char ch) {
			if (p1 == pend) {
				fwrite(buf, 1, BUF_SIZE, stdout); p1 = buf;
			}
			*p1++ = ch;
		}
		void flush() { if (p1 != buf) { fwrite(buf, 1, p1 - buf, stdout); p1 = buf; } }
		~Ostream_fwrite() { flush(); }
	}Ostream;
	inline void print(char x) { Ostream.out(x); }
	inline void println(char x) { Ostream.out(x); Ostream.out('\n'); }
	inline void println() { Ostream.out('\n'); }
	inline void flush() { Ostream.flush(); }
};
using namespace fastIO;

inline void generator::Myprint()//输出函数
{
	for (register int i = 1; i <= 9; ++i)
	{
		for (register int j = 1; j <= 8; ++j)
		{
			print(mat[i][j]); print(' ');
		}
		println(mat[i][9]);
	}
	println();
}

void generator::dfs(char num, int area)
{
	if (now == rep) exit(0);
	if (cnt == 81)
	{
		++now;
		Myprint();
		return;
	}
	if (InA[area][num])
	{
		//debug();
		if (area == 9)
		{
			dfs(num + 1, 1);
		}
		else
		{
			dfs(num, area + 1);
		}
	}
	int xleft = (area - 1) / 3 * 3 + 1;
	int xright = xleft + 2;
	int yup = (area - 1) % 3 * 3 + 1;
	int ydown = yup + 2;
	//分别表示在area内x,y坐标的上下限
	for (register int i = xleft; i <= xright; ++i)
	{
		for (register int j = yup; j <= ydown; ++j)
		{
			if (mat[i][j] == '0' && row[j][num] == 0 && col[i][num] == 0)
			{
				mat[i][j] = num;
				row[j][num] = col[i][num] = 1;
				++cnt;
				if (area == 9)
				{
					dfs(num + 1, 1);
				}
				else
				{
					dfs(num, area + 1);
				}
				mat[i][j] = '0';
				row[j][num] = col[i][num] = 0;
				--cnt;
			}
		}
	}
}

void generator::work()
{
	dfs('1', 1);
}

generator::~generator()
{
}
