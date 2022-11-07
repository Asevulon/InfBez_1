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
	Прямая перестановка IP.
	Перемешивает биты в data по установленному правилу.
	Возращает перестановленный вектор.
	*/
	vector<vector<bool>> IP(vector<vector<bool>>& data);
	/*
	Обратная перестановка IP.
	Переставляет биты в data обратно по установленному правилу.
	Возращает перестановленный вектор.
	*/
	vector<vector<bool>> IPrev(vector<vector<bool>>& data);


	/*
	Преобразует строку символов в набор булевых векторов:
	i-тый вектор является i-тым символом строки.
	*/
	vector<vector<bool>> CharToBool(char* data, int len);
	/*
	Преобразует строку в набор булевых векторов.
	*/
	vector<vector<bool>>StringToBool(string& data);
	/*
	Преобразует вектор булевых векторов в строку.
	*/
	string BoolToString(vector<vector<bool>>& data);
	/*
	Преобразует булевый вектор в символ. 
	*/
	char BoolToChar(vector<bool>& data);
	/*
	Получает на вход вектор булевых векторов и возвращает булевый вектор из значений заданного столбца "снизу вверх".
	*/
	vector<bool> GetInvertRow(vector<vector<bool>>& data, int id);

public:
	DES();

	void test();
};