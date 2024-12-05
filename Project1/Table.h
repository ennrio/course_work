#pragma once
#include<iostream>
#include<iomanip>
#include"List.h"
#include"player.h"
class Table {
public:

	Table();
	// конструктор с инициализацией имени
	Table(std::string name);
	// Конструктор копирования
	Table(const Table& other);
	// Добавляет игрока в односвязный список
	void addPlayer(std::string name, std::string surname, std::string patronymic, int age, int rating);
	//Удаляет игрока
	void delPlayer(const int index); //*
	// Выводит список игроков
	void printPlayer();
	//Выводит результаты 
	void printResult();
	// Создаёт таблицу
	void createTable(); //*
	//Позволяет корретировать даные
	void ChangeResult(int i, int j, float data);
	//Сортирует игроков по рейтингу
	void SortRate(); //*
	


	List<player> arr_players;
	List<float> result;
	std::string name;
}; //end talbe

