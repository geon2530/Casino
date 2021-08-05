#include "Default.h"
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <fstream>

#define CR 13;

using namespace std;

void ChangeColor(int c);
void GameSetting(string Name);
void Rule(); void Card(int i);
void Game();

struct PlayerInformation {
	int Age = 0;
	string Gender = "None";
	string Name = "None";
};

struct MC {
	int PlayerCard[7] = { 0 };
	int PlayerMoney = 10000;
	int RandomCard[7] = { 0 };
	int RandomMoney = 10000;
};

struct GameS {
	int Round = 0;
	int SCard = 0;
};

struct PlayerInformation pi;
struct MC c;
struct GameS s;

int main(void) {
	srand(time(NULL));
	char Enter;

	system("mode con cols=50 lines=30");
	std::cout << "\t ī���뿡 ���Ű��� ȯ���մϴ�. \t";
	
	for (int i = 0; i <= 5; i++)
		std::cout << endl;

	ChangeColor(3);
	std::cout << "\t �����Ϸ��� Enter�� ��������.\t" << endl;
	ChangeColor(7);

	while (1) {
		Enter = _getch();
		try {
			if (Enter == 13) {
				system("cls"); std::cout << "������� �̸��� �Է����ּ���(�г���,�Ǹ� X): ";
				std::cin >> pi.Name;

				std::cout << "\n������� ���� ���̸� �Է����ּ���: ";
				std::cin >> pi.Age;

				std::cout << "\n������� ������ �Է����ּ���: ";
				std::cin >> pi.Gender;

				if (pi.Age < 7) {
					ChangeColor(12);
					std::cout << "�˼��մϴ�. " << pi.Name << "��. \n" << pi.Age << "���� �� ������ �÷��� �� �� �����ϴ�.\n";
					ChangeColor(7);
					exit(1);
				}
				else
					GameSetting(pi.Name);
			}
		} catch (std::exception &e) {
			e.what();
			continue;
		}
		
	}
	return 0;
}

void ChangeColor(int c) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void GameSetting(string Name) {
	char YoN;

	system("cls");
	std::cout << "���� ������ �´��� Ȯ�����ּ���. \n" << pi.Name << ", " << pi.Age << "��, " << pi.Gender << "\n";
	std::cout << "�´ٸ� Y, �ƴ϶�� N�� �Է����ּ���." << endl;

	YoN = _getch();
	if (YoN == 121) {
		Rule(); Card(0); Game();
	}

	if (YoN == 110)
		return;
}
void Rule() {
	system("cls");
	ChangeColor(12);

	std::cout << "���ݺ��� ��Ģ ������ �����ϰڽ��ϴ�. \n" << std::endl;
	ChangeColor(14); Sleep(1000);

	std::cout << "���� ����ڴ� 1���� 7�� ī�忡 10000$�� ���� ������ ���� �մϴ�.(��� ������ �ʿ�� �����ϴ�.) \n" << std::endl;
	ChangeColor(10); Sleep(1000);

	std::cout << "������ AI�� �������� ���� �����մϴ�. \n" << std::endl;
	ChangeColor(11); Sleep(1000);

	std::cout << "�÷��̾�� AI�� ����� ī�带 ���� �����ϰ� �� ī�忡 ���õǾ� �ִ� ���� ����ϴ�. \n" << std::endl;
	ChangeColor(9); Sleep(1000);

	std::cout << "�� 10���� �����Ͽ� ���� �� ���� �� ����� �̱�� �����Դϴ�. \n" << std::endl;
	ChangeColor(7); Sleep(1000);
	
	Sleep(3500);

	system("cls");

	return;
}

void Card(int i) {
	//AI card betting
	for (i; i <= 6; i++) {
		c.RandomCard[i] = rand() % 1428 + 1;
		c.RandomMoney = c.RandomMoney - c.RandomCard[i];
	}

	i = 0;

	//Player card betting
	for (i; i <= 6; i++) {
		ChangeColor(10);
		std::cout << "���� ��: " << c.PlayerMoney << endl << endl;

		ChangeColor(7);
		std::cout << i + 1 << "��°�� ������ �ݾ��� �Է��ϼ��� \n >> ";
		scanf_s("%d", &c.PlayerCard[i]); puts("\n");

		if (c.PlayerCard[i] > c.PlayerMoney || c.PlayerCard[i] < 0) {
			
			ChangeColor(4);
			std::cout <<  "Warning C4512: ���� �� ���� ���� �Է��߰ų� ������ �ݾ��� �����Դϴ�.\n";
			Sleep(1000);
			ChangeColor(7); 

			system("cls");
			--i; continue;
		} else {
			c.PlayerMoney = c.PlayerMoney - c.PlayerCard[i]; system("cls");
		}

	}

	return;
}

void Game() {
	for (int l = 0; l <= 6; l++) {
		std::cout << "�÷��̾�: " << c.PlayerCard[l] << endl;
		std::cout << "AI: " << c.RandomCard[l] << endl;
	}
}