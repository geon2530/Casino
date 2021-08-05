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
	std::cout << "\t 카지노에 오신것을 환영합니다. \t";
	
	for (int i = 0; i <= 5; i++)
		std::cout << endl;

	ChangeColor(3);
	std::cout << "\t 시작하려면 Enter를 누르세요.\t" << endl;
	ChangeColor(7);

	while (1) {
		Enter = _getch();
		try {
			if (Enter == 13) {
				system("cls"); std::cout << "사용자의 이름을 입력해주세요(닉네임,실명 X): ";
				std::cin >> pi.Name;

				std::cout << "\n사용자의 실제 나이를 입력해주세요: ";
				std::cin >> pi.Age;

				std::cout << "\n사용자의 성별을 입력해주세요: ";
				std::cin >> pi.Gender;

				if (pi.Age < 7) {
					ChangeColor(12);
					std::cout << "죄송합니다. " << pi.Name << "님. \n" << pi.Age << "세는 이 게임을 플레이 할 수 없습니다.\n";
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
	std::cout << "다음 정보가 맞는지 확인해주세요. \n" << pi.Name << ", " << pi.Age << "세, " << pi.Gender << "\n";
	std::cout << "맞다면 Y, 아니라면 N을 입력해주세요." << endl;

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

	std::cout << "지금부터 규칙 설명을 시작하겠습니다. \n" << std::endl;
	ChangeColor(14); Sleep(1000);

	std::cout << "먼저 사용자는 1부터 7의 카드에 10000$의 돈을 나눠서 배팅 합니다.(모두 배팅할 필요는 없습니다.) \n" << std::endl;
	ChangeColor(10); Sleep(1000);

	std::cout << "게임의 AI도 랜덤으로 돈을 배팅합니다. \n" << std::endl;
	ChangeColor(11); Sleep(1000);

	std::cout << "플레이어와 AI는 상대의 카드를 각각 선택하고 그 카드에 배팅되어 있는 돈을 얻습니다. \n" << std::endl;
	ChangeColor(9); Sleep(1000);

	std::cout << "총 10번을 진행하여 돈을 더 많이 딴 사람이 이기는 게임입니다. \n" << std::endl;
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
		std::cout << "남은 돈: " << c.PlayerMoney << endl << endl;

		ChangeColor(7);
		std::cout << i + 1 << "번째에 배팅할 금액을 입력하세요 \n >> ";
		scanf_s("%d", &c.PlayerCard[i]); puts("\n");

		if (c.PlayerCard[i] > c.PlayerMoney || c.PlayerCard[i] < 0) {
			
			ChangeColor(4);
			std::cout <<  "Warning C4512: 가진 돈 보다 많이 입력했거나 배팅한 금액이 음수입니다.\n";
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
		std::cout << "플레이어: " << c.PlayerCard[l] << endl;
		std::cout << "AI: " << c.RandomCard[l] << endl;
	}
}