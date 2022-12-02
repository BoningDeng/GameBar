#include "Game.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>  
using namespace std;

void printList(vector<Game> output)
{
	for (int i = 0; i < output.size(); i++)
	{
		cout << "Name: " << output[i].getName() << endl;
		cout << "Platform: " << output[i].getPlatform() << endl;
		cout << "Release Date:" << output[i].getRelease_date() << endl;
		cout << "Meta Score: " << output[i].getMeta_score() << endl;
		cout << "User Review:" << output[i].getUser_review() << endl;
		cout << "Summary: " << output[i].getSummary() << endl;
	}
}

//pass both vector into function
void sortingMenu()
{
	string input;
	cout << "1.Quick sort" << endl;
	cout << "2.Merge sort" << endl;
	cout << "Input: ";
	cin >> input;
	if (stoi(input) == 1)
	{
		//Quick sort here
		//test
		cout << "quick" << endl;

		auto start = chrono::high_resolution_clock::now();
		//run the algorithm here
		//pass the output into print
		//printList();
		auto stop = chrono::high_resolution_clock::now();
		auto runtime = chrono::duration_cast<chrono::microseconds>(stop - start);
		cout << "Runtime: " << runtime.count() << " ms" << endl;
	}
	else if (stoi(input) == 2)
	{
		//Merge sort here
		//test
		cout << "merge" << endl;

		//pass the output here
		//printList();
	}
}

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

	bool endProgram = false;
	string input;
	while (!endProgram)
	{
		cout << "Game Bar" << endl;
		cout << "0.Exit" << endl;
		cout << "1.Listing all games" << endl;
		cout << "2.Listing the top 20 games by rating" << endl;
		cout << "3.Searching by name" << endl;
		cout << "4.Filtering  by platform" << endl;
		cout << "Input: ";
		cin >> input;
		switch(stoi(input)) 
		{
		case 0:
			endProgram = true;
			break;

		case 1:
			sortingMenu();
			break;

		case 2:
			sortingMenu();
			break;

		case 3:
			sortingMenu();
			break;

		case 4:
			sortingMenu();
			break;

		default:
			break;
		}
	}
	cout << "Exiting..." << endl;
	return 0;
}