#pragma once
class generator
{
public:
	bool row[10][100];//row[i][j]表示第i行是否有j这个数字
	bool col[10][100];//col[i][j]表示第i列是否有j这个数字
	bool InA[10][100];//InA[i][j]表示第i区域是否有j这个数字
	char mat[10][10];//表示矩阵中的数字
	int cnt;//已经填好的数字个数
	int now;//已经构造矩阵个数
	int rep;//要求构造矩阵个数
	void debug();
	void init(int n);//初始化
	void work();//工作函数
	inline void Myprint();//输出函数
	void dfs(char num, int area);
	generator();
	~generator();
};

