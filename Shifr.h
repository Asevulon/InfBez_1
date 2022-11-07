#pragma once
#include<afxwin.h>
#include<map>
#include<vector>
#include<string>
using namespace std;


static HWND mainWnd;


class DES
{
private:
	char* text;
	vector<vector<vector<int>>> S;


protected:
	/*
	������ ������������ IP.
	������������ ���� � data �� �������������� �������.
	��������� ���������������� ������.
	*/
	vector<vector<bool>> IP(vector<vector<bool>>& data);
	/*
	�������� ������������ IP.
	������������ ���� � data ������� �� �������������� �������.
	��������� ���������������� ������.
	*/
	vector<vector<bool>> IPrev(vector<vector<bool>>& data);


	/*
	����������� ������ �������� � ����� ������� ��������:
	i-��� ������ �������� i-��� �������� ������.
	*/
	vector<vector<bool>> CharToBool(char* data, int len);
	/*
	����������� ������ � ����� ������� ��������.
	*/
	vector<vector<bool>>StringToBool(string& data);
	/*
	����������� ������ ������� �������� � ������.
	*/
	string BoolToString(vector<vector<bool>>& data);
	/*
	����������� ������� ������ � ������. 
	*/
	char BoolToChar(vector<bool>& data);
	/*
	�������� �� ���� ������ ������� �������� � ���������� ������� ������ �� �������� ��������� ������� "����� �����".
	*/
	vector<bool> GetInvertRow(vector<vector<bool>>& data, int id);
	/*
	���������� ����� �������� ������
	*/
	vector<vector<bool>> getL(vector<vector<bool>>& data);
	/*
	���������� ������ �������� ������
	*/
	vector<vector<bool>> getR(vector<vector<bool>>& data);
	/*
	���������� ������������ ������� ������
	*/
	vector<vector<bool>>conj(vector<vector<bool>>& L, vector<vector<bool>>& R);
	/*
	������� ����������
	*/
	vector<vector<bool>>E(vector<vector<bool>>& R);
	//��������� ������� S
	vector<vector<vector<int>>> CreateS();

public:
	DES();

	void test();
};