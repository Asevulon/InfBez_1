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
	/*
	Возвращает левую половину строки
	*/
	vector<vector<bool>> getL(vector<vector<bool>>& data);
	/*
	Возвращает правую половину строки
	*/
	vector<vector<bool>> getR(vector<vector<bool>>& data);
	/*
	Возвращает объеденненую булевую строку
	*/
	vector<vector<bool>>conj(vector<vector<bool>>& L, vector<vector<bool>>& R);
	/*
	Функция расширения
	*/
	vector<vector<bool>>E(vector<vector<bool>>& R);
	//Формирует таблицу S
	vector<vector<vector<int>>> CreateS();

public:
	DES();

	void test();
};