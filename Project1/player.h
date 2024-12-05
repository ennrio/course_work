
#pragma once
#include<iostream>
class player
{
public:
	player();
	player(std::string name, std::string surname, std::string patronymic, int age, int rating);
	~player();
	std::string name;
	std::string surname;
	std::string patronymic;
	int age;
	int rating;
	//Меняет имя
	void ChangeName(std::string name);
	//Меняет Фамилию
	void ChangeSurname(std::string surname);
	//Меняет Отчество
	void ChangePatronymic(std::string patronymic);
	//Меняет Возраст
	void ChangeAge(int age);
	//Меняет Рейтинг
	void ChangeRating(int rating);


private:
};

