#pragma once
#include"pch.h"
#include"Shifr.h"


DES::DES():text(nullptr) 
{
	S = CreateS();
}


vector<vector<bool>> DES::IP(vector<vector<bool>>& data)
{
	vector<vector<bool>> res;
	
	res.push_back(GetInvertRow(data, 1));
	res.push_back(GetInvertRow(data, 3));
	res.push_back(GetInvertRow(data, 5));
	res.push_back(GetInvertRow(data, 7));
	res.push_back(GetInvertRow(data, 0));
	res.push_back(GetInvertRow(data, 2));
	res.push_back(GetInvertRow(data, 4));
	res.push_back(GetInvertRow(data, 6));

	return res;
}
vector<vector<bool>> DES::IPrev(vector<vector<bool>>& data)
{
	vector<vector<bool>>res;
	for (int i = 0; i < 8; i++)res.push_back(vector<bool>({0,0,0,0,0,0,0,0}));

	for (int i = data.size() - 1; i > -1; i--)res[i][1] = data[0][7 - i];
	for (int i = data.size() - 1; i > -1; i--)res[i][3] = data[1][7 - i];
	for (int i = data.size() - 1; i > -1; i--)res[i][5] = data[2][7 - i];
	for (int i = data.size() - 1; i > -1; i--)res[i][7] = data[3][7 - i];
	for (int i = data.size() - 1; i > -1; i--)res[i][0] = data[4][7 - i];
	for (int i = data.size() - 1; i > -1; i--)res[i][2] = data[5][7 - i];
	for (int i = data.size() - 1; i > -1; i--)res[i][4] = data[6][7 - i];
	for (int i = data.size() - 1; i > -1; i--)res[i][6] = data[7][7 - i];

	return res;
}


vector<vector<bool>> DES::CharToBool(char* data, int len)
{
	map<int, int> bit;
	bit[0] = 1;
	bit[1] = 2;
	bit[2] = 4;
	bit[3] = 8;
	bit[4] = 16;
	bit[5] = 32;
	bit[6] = 64;
	bit[7] = 128;


	vector<vector<bool>> res;
	for (int i = 0; i < len - 1; i++)
	{
		vector<bool> temp;
		for (int g = 0; g < 8; g++)
		{
			temp.push_back((data[i] & bit[g]) >> g);
		}
		res.push_back(temp);
	}
	return res;
}
vector<vector<bool>> DES::StringToBool(string& data)
{
	map<int, int> bit;
	bit[0] = 1;
	bit[1] = 2;
	bit[2] = 4;
	bit[3] = 8;
	bit[4] = 16;
	bit[5] = 32;
	bit[6] = 64;
	bit[7] = 128;


	vector<vector<bool>> res;
	for (int i = 0; i < data.size(); i++)
	{
		vector<bool> temp;
		for (int g = 0; g < 8; g++)
		{
			temp.push_back((data[i] & bit[g]) >> g);
		}
		res.push_back(temp);
	}
	return res;
}


string DES::BoolToString(vector<vector<bool>>& data)
{
	string res;
	for (auto& item : data)res += BoolToChar(item);
	return res;
}
char DES::BoolToChar(vector<bool>& data)
{
	unsigned char res = 0;
	for (int i = 0; i < 8; i++)
	{
		res |= data[i]<<i;
	}
	return res;
}


vector<bool> DES::GetInvertRow(vector<vector<bool>>& data, int id)
{
	vector<bool>res;
	for (int i = data.size() - 1; i > -1; i--)res.push_back(data[i][id]);
	return res;
}


vector<vector<bool>> DES::getL(vector<vector<bool>>& data)
{
	vector<vector<bool>> res;
	for (int i = 0; i < 4; i++)res.push_back(data[i]);
	return res;
}
vector<vector<bool>> DES::getR(vector<vector<bool>>& data)
{
	vector<vector<bool>> res;
	for (int i = 4; i < 8; i++)res.push_back(data[i]);
	return res;
}
vector<vector<bool>> DES::conj(vector<vector<bool>>& L, vector<vector<bool>>& R)
{
	vector<vector<bool>> res;
	for (auto& item : L)res.push_back(item);
	for (auto& item : R)res.push_back(item);
	return res;
}


vector<vector<bool>> DES::E(vector<vector<bool>>& R)
{
	vector<vector<bool>>res;
	vector<bool> temp;
	//первая строка 
	temp.push_back(R[3][7]);
	for (int i = 0; i < 5; i++)temp.push_back(R[0][i]);
	res.push_back(temp);
	temp.clear();

	//вторая
	for (int i = 3; i < 8; i++)temp.push_back(R[0][i]);
	temp.push_back(R[1][0]);
	res.push_back(temp);
	temp.clear();

	//третья
	temp.push_back(R[0][7]);
	for (int i = 0; i < 5; i++)temp.push_back(R[1][i]);
	res.push_back(temp);
	temp.clear();

	//4
	for (int i = 3; i < 8; i++)temp.push_back(R[1][i]);
	temp.push_back(R[2][0]);
	res.push_back(temp);
	temp.clear();

	//5
	temp.push_back(R[1][7]);
	for (int i = 0; i < 5; i++)temp.push_back(R[2][i]);
	res.push_back(temp);
	temp.clear();

	//6
	for (int i = 3; i < 8; i++)temp.push_back(R[2][i]);
	temp.push_back(R[3][0]);
	res.push_back(temp);
	temp.clear();

	//7
	temp.push_back(R[2][7]);
	for (int i = 0; i < 5; i++)temp.push_back(R[3][i]);
	res.push_back(temp);
	temp.clear();

	//8
	for (int i = 3; i < 8; i++)temp.push_back(R[3][i]);
	temp.push_back(R[0][0]);
	res.push_back(temp);
	temp.clear();


	return res;
}


vector<vector<vector<int>>> DES::CreateS()
{
	vector<vector<vector<int>>> res;
	vector<vector<int>> S;
	//[0][0]
	vector<int>temp = { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7 };
	S.push_back(temp);
	//[0][1]
	temp = { 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8 };
	S.push_back(temp);
	//[0][2]
	temp = { 4, 1, 4, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0 };
	S.push_back(temp);
	//[0][3]
	temp = { 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 };
	S.push_back(temp);
	res.push_back(S);
	S.clear();

	//[1][0]
	temp = { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10 };
	S.push_back(temp);
	//[1][1]
	temp = { 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5 };
	S.push_back(temp);
	//[1][2]
	temp = { 0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15 };
	S.push_back(temp);
	//[1][3]
	temp = { 13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 };
	S.push_back(temp);
	res.push_back(S);
	S.clear();

	//[2][0]
	temp = { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8 };
	S.push_back(temp);
	//[2][1]
	temp = { 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1 };
	S.push_back(temp);
	//[2][2]
	temp = { 13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7};
	S.push_back(temp);
	//[2][3]
	temp = { 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 };
	S.push_back(temp);
	res.push_back(S);
	S.clear();

	//[3][0]
	temp = { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15 };
	S.push_back(temp);
	//[3][1]
	temp = { 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9 };
	S.push_back(temp);
	//[3][2]
	temp = { 10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4 };
	S.push_back(temp);
	//[3][3]
	temp = { 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 };
	S.push_back(temp);
	res.push_back(S);
	S.clear();

	//[4][0]
	temp = { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9 };
	S.push_back(temp);
	//[4][1]
	temp = { 14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6 };
	S.push_back(temp);
	//[4][2]
	temp = { 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14 };
	S.push_back(temp);
	//[4][3]
	temp = { 11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 };
	S.push_back(temp);
	res.push_back(S);
	S.clear();

	//[5][0]
	temp = { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11 };
	S.push_back(temp);
	//[5][1]
	temp = { 10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8 };
	S.push_back(temp);
	//[5][2]
	temp = { 9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 1, 6 };
	S.push_back(temp);
	//[5][3]
	temp = { 4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 };
	S.push_back(temp);
	res.push_back(S);
	S.clear();

	//[6][0]
	temp = { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1 };
	S.push_back(temp);
	//[6][1]
	temp = { 13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6 };
	S.push_back(temp);
	//[6][2]
	temp = { 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2 };
	S.push_back(temp);
	//[6][3]
	temp = { 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 };
	S.push_back(temp);
	res.push_back(S);
	S.clear();

	//[7][0]
	temp = { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7 };
	S.push_back(temp);
	//[7][1]
	temp = { 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2 };
	S.push_back(temp);
	//[7][2]
	temp = { 7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8 };
	S.push_back(temp);
	//[7][3]
	temp = { 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 };
	S.push_back(temp);
	res.push_back(S);
	S.clear();
}


bool compare(vector<vector<bool>>& data1, vector<vector<bool>>& data2)
{
	for (int i = 0; i < data1.size(); i++)
	{
		for (int g = 0; g < data1[i].size(); g++)
		{
			if (data1[i][g] != data2[i][g])return false;
		}
	}
	return true;
}
void DES::test()
{
	string str = "01234567";
	auto bits = StringToBool(str);
	auto l = getL(bits);
	auto r = getR(bits);
	auto Etest = E(r);
	
	while (1);
}