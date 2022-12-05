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
		std::cout << "Name: " << output[i].getName() << endl;
		std::cout << "Platform: " << output[i].getPlatform() << endl;
		std::cout << "Release Date:" << output[i].getRelease_date() << endl;
		std::cout << "Meta Score: " << output[i].getMeta_score() << endl;
		std::cout << "User Review:" << output[i].getUser_review() << endl;
		std::cout << "Summary: " << output[i].getSummary() << endl;
		std::cout << " " << endl;
	}
}

vector<Game> readData()
{
	vector<Game> Games;

	string name;
	string platform;
	string release_date;
	string summary;
	string tempMeta_score;
	string tempUser_review;
	int meta_score;
	float user_review;

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
	return Games;
}

int main()
{
	vector<Game> Games = readData();

	bool endProgram = false;
	string input;
	while (!endProgram)
	{
		std::cout << "Welcome to Game Bar" << endl;
		std::cout << "0.Exit" << endl;
		std::cout << "1.Listing all games by rating" << endl;
		std::cout << "2.Listing the top 20 games by rating" << endl;
		std::cout << "3.Searching by name" << endl;
		std::cout << "4.Filtering by platform" << endl;
		std::cout << "Input: ";
		cin >> input;
		switch(stoi(input)) 
		{
		case 0:
			endProgram = true;
			break;

		case 1:
			std::cout << "1.Quick sort" << endl;
			std::cout << "2.Merge sort" << endl;
			std::cout << "Input: ";
			cin >> input;
			if (stoi(input) == 1)
			{
				//Quick sort here
				//test
				std::cout << "quick" << endl;

				auto start = chrono::high_resolution_clock::now();
				//run the algorithm here
				//pass the output into print
				//printList(Games);
				auto stop = chrono::high_resolution_clock::now();
				auto runtime = chrono::duration_cast<chrono::microseconds>(stop - start);
				std::cout << "Runtime: " << runtime.count() << " ms" << endl;
				std::cout << " " << endl;
			}
			else if (stoi(input) == 2)
			{
				//Merge sort here
				//test
				std::cout << "merge" << endl;

				auto start = chrono::high_resolution_clock::now();
				//run the algorithm here
				//pass the output into print
				//printList(Games);
				auto stop = chrono::high_resolution_clock::now();
				auto runtime = chrono::duration_cast<chrono::microseconds>(stop - start);
				std::cout << "Runtime: " << runtime.count() << " ms" << endl;
				std::cout << " " << endl;
			}
			break;

		case 2:
			std::cout << "1.Quick sort" << endl;
			std::cout << "2.Merge sort" << endl;
			std::cout << "Input: ";
			cin >> input;
			if (stoi(input) == 1)
			{
				//Quick sort here
				//test
				std::cout << "quick" << endl;

				auto start = chrono::high_resolution_clock::now();
				//run the algorithm here
				//pass the output into print
				//printList(Games);
				auto stop = chrono::high_resolution_clock::now();
				auto runtime = chrono::duration_cast<chrono::microseconds>(stop - start);
				std::cout << "Runtime: " << runtime.count() << " ms" << endl;
				std::cout << " " << endl;
			}
			else if (stoi(input) == 2)
			{
				//Merge sort here
				//test
				std::cout << "merge" << endl;

				auto start = chrono::high_resolution_clock::now();
				//run the algorithm here
				//pass the output into print
				//printList(Games);
				auto stop = chrono::high_resolution_clock::now();
				auto runtime = chrono::duration_cast<chrono::microseconds>(stop - start);
				std::cout << "Runtime: " << runtime.count() << " ms" << endl;
				std::cout << " " << endl;
			}
			break;

		case 3:
			std::cout << "1.Quick sort" << endl;
			std::cout << "2.Merge sort" << endl;
			std::cout << "Input: ";
			cin >> input;
			if (stoi(input) == 1)
			{
				//Quick sort here
				//test
				std::cout << "quick" << endl;

				auto start = chrono::high_resolution_clock::now();
				//run the algorithm here
				//pass the output into print
				//printList(Games);
				auto stop = chrono::high_resolution_clock::now();
				auto runtime = chrono::duration_cast<chrono::microseconds>(stop - start);
				std::cout << "Runtime: " << runtime.count() << " ms" << endl;
				std::cout << " " << endl;
			}
			else if (stoi(input) == 2)
			{
				//Merge sort here
				//test
				std::cout << "merge" << endl;

				auto start = chrono::high_resolution_clock::now();
				//run the algorithm here
				//pass the output into print
				//printList(Games);
				auto stop = chrono::high_resolution_clock::now();
				auto runtime = chrono::duration_cast<chrono::microseconds>(stop - start);
				std::cout << "Runtime: " << runtime.count() << " ms" << endl;
				std::cout << " " << endl;
			}
			break;

		case 4:
			std::cout << "1.Quick sort" << endl;
			std::cout << "2.Merge sort" << endl;
			std::cout << "Input: ";
			cin >> input;
			if (stoi(input) == 1)
			{
				//Quick sort here
				//test
				std::cout << "quick" << endl;

				auto start = chrono::high_resolution_clock::now();
				//run the algorithm here
				//pass the output into print
				//printList(Games);
				auto stop = chrono::high_resolution_clock::now();
				auto runtime = chrono::duration_cast<chrono::microseconds>(stop - start);
				std::cout << "Runtime: " << runtime.count() << " ms" << endl;
				std::cout << " " << endl;
			}
			else if (stoi(input) == 2)
			{
				//Merge sort here
				//test
				std::cout << "merge" << endl;

				auto start = chrono::high_resolution_clock::now();
				//run the algorithm here
				//pass the output into print
				//printList(Games);
				auto stop = chrono::high_resolution_clock::now();
				auto runtime = chrono::duration_cast<chrono::microseconds>(stop - start);
				std::cout << "Runtime: " << runtime.count() << " ms" << endl;
				std::cout << " " << endl;
			}
			break;

		default:
			break;
		}
	}
	std::cout << "Exiting..." << endl;
	return 0;
}