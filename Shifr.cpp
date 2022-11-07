#pragma once
#include"pch.h"
#include"Shifr.h"


DES::DES():text(nullptr) {}


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




void DES::test()
{
	
}