#pragma once
#include<iostream>
#include<iomanip>
#include"List.h"
#include"player.h"
class Table {
public:

	Table();
	// ����������� � �������������� �����
	Table(std::string name);
	// ����������� �����������
	Table(const Table& other);
	// ��������� ������ � ����������� ������
	void addPlayer(std::string name, std::string surname, std::string patronymic, int age, int rating);
	//������� ������
	void delPlayer(const int index); //*
	// ������� ������ �������
	void printPlayer();
	//������� ���������� 
	void printResult();
	// ������ �������
	void createTable(); //*
	//��������� ������������� �����
	void ChangeResult(int i, int j, float data);
	//��������� ������� �� ��������
	void SortRate(); //*
	


	List<player> arr_players;
	List<float> result;
	std::string name;
}; //end talbe

