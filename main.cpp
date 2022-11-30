#include "Game.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	string name = "The Legend of Zelda : Ocarina of Time";
	string platform = "Nintendo 64";
	string release_date = "23-Nov-98";
	string summary = "As a young boy, Link is tricked by Ganondorf, the King of the Gerudo Thieves. The evil human uses Link to gain access to the Sacred Realm, where he places his tainted hands on Triforce and transforms the beautiful Hyrulean landscape into a barren wasteland. Link is determined to fix the problems he helped to create, so with the help of Rauru he travels through time gathering the powers of the Seven Sages.";
	int meta_score = 99;
	float user_review = 9.1;
	Game temp(name, platform, release_date, summary, meta_score, user_review);
	std::cout << name << std::endl;
	std::cout << platform << std::endl;
	std::cout << release_date << std::endl;
	std::cout << summary << std::endl;
	std::cout << meta_score << std::endl;
	std::cout << user_review << std::endl;

	vector<Game> Games;

	fstream file;
	file.open("all_games.csv", ios::in);

	return 0;
}