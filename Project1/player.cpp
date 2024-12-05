#include "player.h"

player::player()
{
}

player::player(std::string name, std::string surname, std::string patronymic, int age, int rating)
{
	this->name = name;
	this->surname = surname;
	this->patronymic = patronymic;
	this->age = age;
	this->rating = rating;
}

player::~player()
{
}

void player::ChangeName(std::string name)
{
	this->name = name;
}

void player::ChangeSurname(std::string surname)
{
	this->surname = surname;
}

void player::ChangePatronymic(std::string Patronymic)
{
	this->patronymic = Patronymic;
}

void player::ChangeAge(int age)
{
	this->age = age;
}

void player::ChangeRating(int rating)
{
	this->rating = rating;
}
