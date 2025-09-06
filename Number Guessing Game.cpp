#include <iostream>

using namespace std;
enum Difficulty { Easy = 1, Medium = 2, Hard = 3 };

int RandomNumber(int From, int To) {
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
void resetscreen() {
	system("cls");
	system("color 0f");
}
Difficulty ChooseDiffequlty() {
	char t;
	do {
		resetscreen();
		cout << "choose diffeculty round: \n";
		cout << "1.Easy \n";
		cout << "2.Medium \n";
		cout << "3.Hard \n";
		 cin >> t;
	} while (t < '1' || t > '3');
	return (Difficulty)(t - '0');
}
int ReadUserNumber() {
	int num;
	do {
		cout << "Guess The Number from 1 : 100 ----> ";
		cin >> num;
	} while (num <= 0 || num > 100);
	return num ;
}

void Guessing(int game_num, int& attemps, Difficulty type_level , int best_score) {

	int level = 0;
	if (type_level == Difficulty::Easy)
		level = 80;
	else if (type_level == Difficulty::Medium)
		level = 50;
	else
		level = 20;
	bool flag = false;
	while (attemps < level) {
		int UserNumber = ReadUserNumber();
		if (UserNumber > game_num) {
			cout << "Too High !  \ntry again  \n";
			attemps++;
		}
		else if (UserNumber < game_num) {
			cout << "Too Low !  \ntry again  \n";
			attemps++;
		}
		else {
			resetscreen();
			cout << "Correct Number \n";
			attemps++;
			flag = true;
			break;
		}
	}
	best_score = min(best_score, attemps);
	if (!flag) {
		resetscreen();
		cout << "Game Over !!! \n";
		cout << "Your Attemps = " << attemps << '\n';
		cout << "Your Best Score = " << best_score << '\n';
		cout << "Correct number is " << game_num << '\n';
		system("color 4f");
	}
	else {
		cout << "Your Attemps = " << attemps << '\n';
		cout << "Your Best Score = " << best_score << '\n';
		system("color 2f");
	}
}

void startgame() {
	char playagain;
	int best_score = INT_MAX;
	do {

		int attempts = 0;
		Difficulty Level = ChooseDiffequlty();
		int GameNumber = RandomNumber(1, 100);
		Guessing(GameNumber, attempts, Level, best_score);
		cout << "Do you want to play again ? y or n "; cin >> playagain;
	} while (tolower(playagain) == 'y');
}

int main()
{
	srand((unsigned)time(NULL));    //to multiply choices
	startgame();

	return 0;
}
