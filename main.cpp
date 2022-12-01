#include "Game.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	string name;
	string platform;
	string release_date;
	string summary;
	string tempMeta_score;
	string tempUser_review;
	int meta_score;
	float user_review;

	vector<Game> Games;

	fstream file;
	file.open("all_games.csv", ios::in);
	while (!file.eof())
	{
		getline(file, name, ',');
		getline(file, platform, ',');
		getline(file, release_date, ',');
		getline(file, tempMeta_score, ',');
		getline(file, tempUser_review, ',');
		meta_score = stoi(tempMeta_score);
		user_review = stof(tempUser_review);
		getline(file, summary);

		Game temp(name, platform, release_date, summary, meta_score, user_review);
		Games.push_back(temp);
	}

	cout << Games.size() << endl;
	return 0;
}