#pragma once
class generator
{
public:
	bool row[10][100];//row[i][j]��ʾ��i���Ƿ���j�������
	bool col[10][100];//col[i][j]��ʾ��i���Ƿ���j�������
	bool InA[10][100];//InA[i][j]��ʾ��i�����Ƿ���j�������
	char mat[10][10];//��ʾ�����е�����
	int cnt;//�Ѿ���õ����ָ���
	int now;//�Ѿ�����������
	int rep;//Ҫ����������
	void debug();
	void init(int n);//��ʼ��
	void work();//��������
	inline void Myprint();//�������
	void dfs(char num, int area);
	generator();
	~generator();
};

