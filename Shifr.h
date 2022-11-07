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

public:
	DES();

	void test();
};