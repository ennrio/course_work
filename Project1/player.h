
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
	//������ ���
	void ChangeName(std::string name);
	//������ �������
	void ChangeSurname(std::string surname);
	//������ ��������
	void ChangePatronymic(std::string patronymic);
	//������ �������
	void ChangeAge(int age);
	//������ �������
	void ChangeRating(int rating);


private:
};

