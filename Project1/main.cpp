#include <iostream>
#include "player.h"
#include "List.h"
#include "Table.h"
#include <iomanip>
#include<string>
#include <fstream>


//�������� �� �����
bool check_input() {
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "������� �����!!!" << std::endl;
	}
	return false;
}
// 
// 
//��������� ����� �������
//--------------------------------------------------------------------------------------------------
void add_table(List<Table> &arr_table, std::string name) {
	arr_table.push_back(Table(name));
}
//--------------------------------------------------------------------------------------------------
// 
//������� �������
//--------------------------------------------------------------------------------------------------
void print_table(List<Table> &arr_table, int index) {
	arr_table[index].printPlayer();
}
//--------------------------------------------------------------------------------------------------
// 
//�������� ������ ������
//--------------------------------------------------------------------------------------------------
void print_list_table(List<Table> &arr_table) {
	for (int i = 0; i < arr_table.GetSize(); i++) {
		std::cout << i << "\t" << arr_table[i].name << std::endl;
	}
}
//--------------------------------------------------------------------------------------------------
// 
// �������� ������ �������
//--------------------------------------------------------------------------------------------------
void print_players(List<Table> &arr_table, const int index) {
	arr_table[index].printPlayer();
}
//--------------------------------------------------------------------------------------------------
// 
// ��������� ������� � ����
//--------------------------------------------------------------------------------------------------
void saveTables(const std::string& filename, List<Table>& arr_table) {
	std::ofstream file(filename);

	if (!file.is_open()) {
		std::cerr << "�� ������� ������� ���� ��� ������!" << std::endl;
		return;
	}

	file << arr_table.GetSize() << std::endl;

	for (int t = 0; t < arr_table.GetSize(); t++) {
		file << arr_table[t].name << std::endl;

		file << arr_table[t].arr_players.GetSize() << std::endl;

		for (int i = 0; i < arr_table[t].arr_players.GetSize(); i++) {
			file << arr_table[t].arr_players[i].name << " "
				<< arr_table[t].arr_players[i].surname << " "
				<< arr_table[t].arr_players[i].patronymic << " "
				<< arr_table[t].arr_players[i].age << " "
				<< arr_table[t].arr_players[i].rating;

			if (i < arr_table[t].arr_players.GetSize() - 1) {
				file << std::endl;
			}
		}

		file << std::endl;

		int tableSize = arr_table[t].arr_players.GetSize();

		for (int i = 0; i < tableSize * tableSize; i++) {
			file << arr_table[t].result[i];

			if ((i + 1) % tableSize != 0) {
				file << " ";
			}

			if ((i + 1) % tableSize == 0) {
				file << std::endl;
			}
		}

		if (t < arr_table.GetSize() - 1) {
			file << std::endl;
		}
	}

	file.close();
}
//--------------------------------------------------------------------------------------------------
// 
// ��������� ������� �� �����
//--------------------------------------------------------------------------------------------------
void loadTables(const std::string& filename, List<Table>& arr_table) {
	std::ifstream file(filename);

	if (!file.is_open()) {
		std::cerr << "�� ������� ������� ���� ��� ������!" << std::endl;
		return;
	}

	int tableCount;
	if (!(file >> tableCount)) {
		std::cerr << "������ ������ ���������� ������!" << std::endl;
		return;
	}
	file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	arr_table.clear();

	for (int t = 0; t < tableCount; t++) {
		std::string tableName;
		while (std::getline(file, tableName)) {
			if (!tableName.empty()) {
				break;
			}
		}

		if (tableName.empty()) {
			std::cerr << "������: ������ �������� ������� �� ����� " << t + 1 << "!" << std::endl;
			return;
		}

		std::cout << "������� �������� �������: '" << tableName << "'" << std::endl; 
		add_table(arr_table, tableName);

		int playerCount;
		if (!(file >> playerCount)) {
			std::cerr << "������ ������ ���������� ������� ��� ������� '" << tableName << "'!" << std::endl;
			arr_table.removeAT(t);
			return;
		}
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		for (int i = 0; i < playerCount; i++) {
			std::string name, surname, patronymic;
			int age, rating;

			if (!(file >> name >> surname >> patronymic >> age >> rating)) {
				std::cerr << "������ ������ ������ ������ #" << (i + 1) << " ��� ������� '" << tableName << "'!" << std::endl;
				arr_table.removeAT(t);
				return;
			}

			arr_table[t].addPlayer(name, surname, patronymic, age, rating);
			std::cout << "�������� �����: " << name << " " << surname << " " << patronymic << " " << age << " " << rating << std::endl;
		}

		arr_table[t].result.clear();
		for (int i = 0; i < playerCount * playerCount; i++) {
			float res;
			if (!(file >> res)) {
				std::cerr << "������ ������ ���������� ����� #" << (i + 1) << " ��� ������� '" << tableName << "'!" << std::endl;
				arr_table.removeAT(t);
				return;
			}
			arr_table[t].result.push_back(res);
		}
	}
	file.close();
}
//--------------------------------------------------------------------------------------------------

int main() {
	setlocale(LC_ALL, "RU");
	List<int> test;
	test.push_back(23);
	test.push_back(34);
	test.removeAT(0);
	std::cout << test.GetSize() << std::endl;
	List<Table> arr_table;
	loadTables("table_data.txt",arr_table);
	while (true)
	{
		int p1;
		
		std::cout << "1 - ������� ������� ��� ���������� ������" << std::endl;
		std::cout << "2 - �������� ����� �������" << std::endl;
		std::cout << "3 - ��������� ����������" << std::endl;
		std::cout << "4 - ������� �������" << std::endl;
		std::cout << "5 - ����� �� ���������" << std::endl;
		std::cout << ">>>>>";
		std::cin >> p1;
		if (p1 == 1) {
			bool work_table = true;
			print_list_table(arr_table);
			std::cout << ">>>>";
			int index;
			std::cin >> index;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "������� �����!!!" << std::endl;
				continue;
			}
			if (index < 0 || index >= arr_table.GetSize()) {
				std::cout << "������ ������� ��� � ������" << std::endl;
				continue;
			}
			while (work_table) {
				int p2;
				std::cout << "��� �� ������ ��������?" << std::endl;
				std::cout << "1 - ������� �������" << std::endl;
				std::cout << "2 - �������� ���������� ������" << std::endl;
				std::cout << "3 - �������� ���������� � �����-�� ������" << std::endl;
				std::cout << "4 - ������� ������ �������" << std::endl;
				std::cout << "5 - �������� ������ ������" << std::endl;
				std::cout << "6 - ������� ������" << std::endl;
				std::cout << "����� ������ ����� - ����� �� ������ ��������������" << std::endl;
				std::cout << ">>>>" << std::endl;
				std::cin >> p2;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "������� �����!!!" << std::endl;
					continue;
				}
				if (p2 == 1) {
					arr_table[index].createTable();
					arr_table[index].printResult();

				}
				else if (p2 == 2) {
					arr_table[index].createTable();
					arr_table[index].printResult();
					int i;
					int j;
					float data;
					std::cout << "������� ���>>>>";
					std::cin >> i;
					std::cout << std::endl;
					std::cout << "������� �������>>>>";
					std::cin >> j;
					std::cout << std::endl;
					if (i<0 || j<0 || i>arr_table[index].arr_players.GetSize() || j>arr_table[index].arr_players.GetSize()) {
						std::cout << "��� ��� ������� ������� �������!!!!" << std::endl;
					}
					std::cout << "������� �������� ����� 1.0 - ������, 0.5 - �����, 0.0 - ��������� >>";
					std::cin >> data;				
					if (data == 0.5 || data == 1.0 || data == -1.0 || data == 0) {
						arr_table[index].ChangeResult(i - 1, j - 1, data);
					}
					else {
						std::cout << "������ ������� �������, ��� �� ������!!!" << std::endl;
					}
				}
				else if (p2 == 3) {
					arr_table[index].printPlayer();
					//arr_table[index].changePlayer();
					//changePlayer
					{
						//while (true)
						//{
							int index2 = 0;
							std::cout << "������� ������ ������, � ������� ������ �������� ����������>>" << std::endl;
							std::cin >> index2;
							if (index2 < 0 || index2 >= arr_table[index].arr_players.GetSize()) {
								std::cout << "����������� ������" << std::endl;
								continue;
							}
							int p;
							std::cout << "��� �� ������ ��������?" << std::endl;
							std::cout << "1 - name" << std::endl;
							std::cout << "2 - surname" << std::endl;
							std::cout << "3 - patronamic" << std::endl;
							std::cout << "4 - age" << std::endl;
							std::cout << "5 - rate" << std::endl;
							std::cout << ">>>>>";
							std::cin >> p;
							if (p == 1) {
								std::string name;
								std::cout << "������� ���>>>>";
								std::cin >> name;
								int flag = true;
								for (int i = 0; i < arr_table[index].arr_players.GetSize(); i++) {
									if (name == arr_table[index].arr_players[i].name && arr_table[index].arr_players[index2].surname == arr_table[index].arr_players[i].surname) {
										flag = false;
									}
								}
								if (flag) {
									arr_table[index].arr_players[index2].ChangeName(name);
								}
								else {
									std::cout << "������ �������� ������ � ����������� ��������, ������ � ���������" << std::endl;
								}
								break;
							}
							else if (p == 2) {
								std::string surname;
								std::cout << "������� �������>>>>";
								std::cin >> surname;
								int flag = true;
								for (int i = 0; i < arr_table[index].arr_players.GetSize(); i++) {
									if (arr_table[index].arr_players[index2].name == arr_table[index].arr_players[i].name && surname == arr_table[index].arr_players[i].surname) {
										flag = false;
									}
								}
								if (flag) {
									arr_table[index].arr_players[index2].ChangeSurname(surname);
								}
								else {
									std::cout << "������ �������� ������ � ����������� ��������, ������ � ���������" << std::endl;
								}

								break;
							}
							else if (p == 3) {
								std::string patronamic;
								std::cout << "������� ��������>>>>";
								std::cin >> patronamic;
								arr_table[index].arr_players[index2].ChangePatronymic(patronamic);
								break;
							}
							else if (p == 4) {
								int age;
								std::cout << "������� �������>>>>";
								std::cin >> age;
								arr_table[index].arr_players[index2].ChangeAge(age);
								if (std::cin.fail())
								{
									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
									std::cout << "������� �����!!!" << std::endl;
									continue;
								}
								break;
							}
							else if (p == 5) {
								int rate;
								std::cout << "������� ������� >>>>";
								std::cin >> rate;
								arr_table[index].arr_players[index2].ChangeRating(rate);
								if (std::cin.fail())
								{
									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
									std::cout << "������� �����!!!" << std::endl;
									continue;
								}
								break;
							}
							else {
								break;
							}
						/*}*/
					}
				}
				else if (p2 == 4) {
					//arr_table[index].SortRate();
					arr_table[index].printPlayer();
				}
				else if (p2 == 5) {
					std::string name;
					std::string surname;
					std::string patronamic;
					int age;
					int rate;
					std::cout << "������� ���" << std::endl;
					std::cout << ">>>>";
					std::cin >> name;
					std::cout << "������� �������" << std::endl;
					std::cout << ">>>>";
					std::cin >> surname;
					std::cout << "������� ��������" << std::endl;
					std::cout << ">>>>";
					std::cin >> patronamic;
					std::cout << "������� �������" << std::endl;
					std::cout << ">>>>";
					std::cin >> age;
					std::cout << "������� �������" << std::endl;
					std::cout << ">>>>";
					std::cin >> rate;
					bool flag = true;
					for (int i = 0; i < arr_table[index].arr_players.GetSize(); i++) {
						if (name == arr_table[index].arr_players[i].name && surname == arr_table[index].arr_players[i].surname) {
							flag = false;
						}
					}
					if (flag == true) {
						arr_table[index].arr_players.push_back(player(name, surname, patronamic, age, rate));
					}
					else {
						std::cout << "������ �������� ������ � ����������� �������� � ������" << std::endl;
					}
					//arr_table[index].addPlayer(name, surname, patronamic, age, rate);
				}
				else if (p2 == 6) {
					arr_table[index].printPlayer();
					int h;
					std::cout << "������� ������ ������>>";
					std::cin >> h;
					check_input();
					if (h >= 0 && h < arr_table.GetSize()) {
						arr_table[index].delPlayer(h);
					}
					else {
						std::cout << "������� ���������� ������" << std::endl;
					}

							}
				else {
					work_table = false;
					break;
				}
			}//end work table			
		}
		else if (p1 == 2) {
			std::string table_name;
			std::cout << "������� ��� �������" << std::endl;
			std::cout << ">>>>";
			std::cin >> table_name;
			add_table(arr_table, table_name);
		}
		else if (p1 == 3){
			for (int i = 0; i < arr_table.GetSize(); i++) {
				arr_table[i].createTable();
			}
			saveTables("table_data.txt",arr_table);
		}
		else if (p1 == 4) {
			print_list_table(arr_table);
			std::cout << "�������� ������� ��� �������� �� ������.\n� ������, ���� �� ������ ����� " 
			<< "������� ����� ������ �����" << std::endl;
			std::cout << "������� ������>>";
			int h2;
			std::cin >> h2;
			if (check_input()) {
				std::cout << "������������ ����" << std::endl;
				continue;
			}
			if (h2<0 || h2> arr_table.GetSize()) {
				std::cout << "������������ ������" << std::endl;
				continue;
			}
			arr_table.removeAT(h2);
		}

		else {
			break;
		}
	}
	return 0;
}



