#include "Table.h"

Table::Table()
{
}

Table::Table(std::string name)
{
	this->name = name;
}

Table::Table(const Table& other)
{
	name = other.name;
	arr_players = other.arr_players;
	result = other.result;
}

void Table::addPlayer(std::string name, std::string surname, std::string patronymic, int age, int rating)
{
	bool flag = true;
	for (int i = 0; i < arr_players.GetSize(); i++) {
		if (name == arr_players[i].name && surname == arr_players[i].surname) {
			flag = false;
		}
	}
	if (flag == true) {
		arr_players.push_back(player(name, surname, patronymic, age, rating));
	}
	else {
		std::cout << "Нельзя добавить игрока с совпадающей фамилией, именем" << std::endl;
	}
}

void Table::delPlayer(const int index)
{
	for (int i = result.GetSize() * index; i < result.GetSize() * index + 1; i++) {
		result.removeAT(i);
	}
	arr_players.removeAT(index);
}

void Table::printPlayer()
{
	for (int i = 0; i < arr_players.GetSize(); i++) {
		std::cout << i <<
			std::setw(20) << arr_players[i].name <<
			std::setw(20) << arr_players[i].surname <<
			std::setw(20) << arr_players[i].patronymic <<
			std::setw(20) << arr_players[i].age <<
			std::setw(20) << arr_players[i].rating
			<< std::endl;
	}
}

void Table::printResult()
{
	std::cout << std::setw(20) << " ";
	for (int i = 0; i < arr_players.GetSize(); i++) {
		std::cout << std::setw(20) << arr_players[i].name + " " + arr_players[i].surname;
	}
	std::cout << std::endl;

	for (int i = 0; i < arr_players.GetSize(); i++) {
		std::cout << std::setw(20) << arr_players[i].name + " " + arr_players[i].surname;
		for (int j = i * arr_players.GetSize(); j < (i + 1) * arr_players.GetSize(); j++) {
			std::cout << std::setw(20) << result[j];
		}
		std::cout << std::endl;
	}
}

void Table::createTable()
{
	int newSize = arr_players.GetSize();

	if (result.GetSize() == 0) {
		for (int i = 0; i < newSize * newSize; i++) {
			if (i % newSize == i / newSize) {
				result.push_back(-1);
			}
			else {
				result.push_back(0);
			}
		}
	}
	else {
		List<float> temp;

		for (int i = 0; i < newSize * newSize; i++) {
			if (i % newSize == i / newSize) {
				temp.push_back(-1);
			}
			else {
				temp.push_back(0);
			}
		}

		int oldSize = result.GetSize();
		oldSize = static_cast<int>(sqrt(oldSize));

		for (int i = 0; i < oldSize; i++) {
			for (int j = 0; j < oldSize; j++) {
				temp[i * newSize + j] = result[i * oldSize + j];
			}
		}

		result.clear();
		for (int i = 0; i < temp.GetSize(); i++) {
			result.push_back(temp[i]);
		}
	}
}

void Table::ChangeResult(int i, int j, float data)
{
	result[(i)*arr_players.GetSize() + (j)] = data;
}

void Table::SortRate()
{
	for (int i = 1; i < arr_players.GetSize(); i++) {
		if (arr_players[i-1].rating < arr_players[i].rating) {
			player temp = arr_players[i-1];
			arr_players[i-1] = arr_players[i];
			arr_players[i] = temp;
			if (i >= 2) {
				i -= 2;
			}
		}
	}
}
// Реализовать сохранение и чтение данных
// Реализовать консрукторы копрования для player and list
// Добавить миллиард проверок
// Отредачить код
// При добавлении 1 или нуль добавлять автоматически добавлять 1 или нуль соответственно  
// Режим заполнения всей таблицы разом
// Написать конструктор копирования List.h для createTable()
// 
// Рализовать удаление игрока и или таблицу
//Вынести проверки в main
//Не записывать данные после ошибки