#include "QuickSort.h"
#include "Game.h"
#include "mergeSort.h"
#include <fstream>
#include <algorithm>
#include <chrono>  
using namespace std;

//Updated: printList to intake a value which could be the size of Games.
void printList(vector<Game*> output, int value)
{
	for (int i = 0; i < value; i++)
	{
		std::cout << "Name: " << output[i]->getName() << endl;
		std::cout << "Platform: " << output[i]->getPlatform() << endl;
		std::cout << "Release Date:" << output[i]->getRelease_date() << endl;
		std::cout << "Meta Score: " << output[i]->getMeta_score() << endl;
		std::cout << "User Review:" << output[i]->getUser_review() << endl;
		std::cout << "Summary: " << output[i]->getSummary() << endl;
		std::cout << " " << endl;
	}
}

//Added: searchList which will return a list of Games with either the platform or name being found through a given string. INPUT 1 FOR NAME AND 2 FOR PLATFORM
vector<Game*> searchList(vector<Game*> output, std::string search, int input) {
	vector<Game*> tempList;
	if (input == 1) {
		for (int i = 0; i < output.size(); i++) {
			if (output[i]->getName().find(search) != std::string::npos) {
				tempList.push_back(output[i]);
			}
		}
	}
	else if (input == 2) {
		for (int i = 0; i < output.size(); i++) {
			if (output[i]->getPlatform().find(search) != std::string::npos) {
				tempList.push_back(output[i]);
			}
		}
	}
	return tempList;
}

vector<Game*> readData()
{
	vector<Game*> Games;

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

		Game* temp = new Game(name, platform, release_date, summary, meta_score, user_review);
		Games.push_back(temp);
	}
	return Games;
}

int main()
{
	vector<Game*> Games = readData();

	int numGames;
	int rating;
	bool endProgram = false;
	string input;
	while (!endProgram)
	{
		//Updated: Made the menu look a little nicer and updated options so that they do one thing and there are subcategories for Amount of Games, Sorting Algorithm, and What to Sort By.
		//I plan to put our names somewhere on this title screen.
		std::cout << "----------------" << endl;
		std::cout << "|   Game Bar   |" << endl;
		std::cout << "----------------" << endl;
		std::cout << "Total Games: " << Games.size() << endl;
		std::cout << std::endl;
		std::cout << "0.Exit" << endl;
		std::cout << "1.Listing all games" << endl;
		std::cout << "2.Listing a specified amount of games" << endl;
		std::cout << "3.Searching by name" << endl;
		std::cout << "4.Searching by platform" << endl;
		std::cout << "Input: ";
		cin >> input;
		switch (stoi(input))
		{
		case 0:
			endProgram = true;
			break;

		case 1:
			//Updated: Users choose what to sort by. 
			std::cout << std::endl;
			std::cout << "Sort by?" << endl;
			std::cout << "1.User Rating" << endl;
			std::cout << "2.Metascore" << endl;
			std::cout << "Input: ";
			cin >> input;
			rating = stoi(input);
			std::cout << std::endl;

			//Updated: Users choose sorting Alrgorithm.
			std::cout << "Sorting Algortihm?" << endl;
			std::cout << "1.Quick sort" << endl;
			std::cout << "2.Merge sort" << endl;
			std::cout << "Input: ";
			cin >> input;
			if (stoi(input) == 1)
			{
				std::cout << "Quick Sort" << endl;
				auto start = chrono::high_resolution_clock::now();

				quickSort(Games, 0, Games.size() - 1, rating);
				reverse(Games.begin(), Games.end());
				printList(Games, Games.size());

				auto stop = chrono::high_resolution_clock::now();
				auto runtime = chrono::duration_cast<chrono::microseconds>(stop - start);
				std::cout << "Runtime: " << runtime.count() << " ms" << endl;
				std::cout << " " << endl;
			}
			else if (stoi(input) == 2)
			{
				std::cout << "merge" << endl;

				auto start = chrono::high_resolution_clock::now();
				
				mergeSort(Games, 0, Games.size() - 1, rating);
				reverse(Games.begin(), Games.end());
				printList(Games, Games.size());
				auto stop = chrono::high_resolution_clock::now();
				auto runtime = chrono::duration_cast<chrono::microseconds>(stop - start);
				std::cout << "Runtime: " << runtime.count() << " ms" << endl;
				std::cout << " " << endl;
			}
			break;

		case 2:
			//Updated: Asks users how many games they want to print. "all" prints every game.
			std::cout << "How many games?  ";
			cin >> input;

			numGames = stoi(input);

			std::cout << std::endl;
			std::cout << "Sort by?" << endl;
			std::cout << "1.User Rating" << endl;
			std::cout << "2.Metascore" << endl;
			std::cout << "Input: ";
			cin >> input;
			rating = stoi(input);
			std::cout << std::endl;

			std::cout << "Sorting Algortihm?" << endl;
			std::cout << "1.Quick sort" << endl;
			std::cout << "2.Merge sort" << endl;
			std::cout << "Input: ";
			cin >> input;
			if (stoi(input) == 1)
			{

				std::cout << "Quick Sort" << endl;

				auto start = chrono::high_resolution_clock::now();

				quickSort(Games, 0, Games.size() - 1, rating);
				reverse(Games.begin(), Games.end());
				printList(Games, numGames);

				auto stop = chrono::high_resolution_clock::now();
				auto runtime = chrono::duration_cast<chrono::microseconds>(stop - start);
				std::cout << "Runtime: " << runtime.count() << " ms" << endl;
				std::cout << " " << endl;
			}
			else if (stoi(input) == 2)
			{
				
				std::cout << "merge" << endl;

				auto start = chrono::high_resolution_clock::now();
				mergeSort(Games, 0, Games.size() - 1, rating);
				reverse(Games.begin(), Games.end());
				printList(Games, numGames);
				auto stop = chrono::high_resolution_clock::now();
				auto runtime = chrono::duration_cast<chrono::microseconds>(stop - start);
				std::cout << "Runtime: " << runtime.count() << " ms" << endl;
				std::cout << " " << endl;
			}
			break;

		case 3:
			std::cout << "Sort by?" << endl;
			std::cout << "1.User Rating" << endl;
			std::cout << "2.Metascore" << endl;
			std::cout << "Input: ";
			cin >> input;
			rating = stoi(input);
			std::cout << std::endl;

			std::cout << "Sorting Algortihm?" << endl;
			std::cout << "1.Quick sort" << endl;
			std::cout << "2.Merge sort" << endl;
			std::cout << "Input: ";
			cin >> input;
			if (stoi(input) == 1)
			{
				std::cout << "Game Name: ";
				cin >> input;
				vector<Game*> newList = searchList(Games, input, 1);

				std::cout << "How many games? (Type \"all\" to print every game.) ";
				cin >> input;
				if (input == "all") {
					numGames = newList.size();
				}
				else {
					numGames = stoi(input);
				}
				std::cout << std::endl;

				std::cout << "Quick Sort" << endl;

				auto start = chrono::high_resolution_clock::now();

				quickSort(newList, 0, newList.size() - 1, rating);
				reverse(newList.begin(), newList.end());
				printList(newList, numGames);

				auto stop = chrono::high_resolution_clock::now();
				auto runtime = chrono::duration_cast<chrono::microseconds>(stop - start);
				std::cout << "Runtime: " << runtime.count() << " ms" << endl;
				std::cout << " " << endl;
			}
			else if (stoi(input) == 2)
			{
				std::cout << "Game Name: ";
				cin >> input;
				vector<Game*> newList = searchList(Games, input, 1);

				std::cout << "How many games? (Type \"all\" to print every game.) ";
				cin >> input;
				if (input == "all") {
					numGames = newList.size();
				}
				else {
					numGames = stoi(input);
				}
				std::cout << std::endl;

				//Use "newList" instead of "Games" here for mergesort as its an updated list of games for the name.
				
				std::cout << "merge" << endl;

				auto start = chrono::high_resolution_clock::now();
				mergeSort(newList, 0, newList.size() - 1, rating);
				if (input == "all")
					reverse(newList.begin(), newList.end());
				printList(newList, numGames);
				auto stop = chrono::high_resolution_clock::now();
				auto runtime = chrono::duration_cast<chrono::microseconds>(stop - start);
				std::cout << "Runtime: " << runtime.count() << " ms" << endl;
				std::cout << " " << endl;
			}
			break;

		case 4:
			std::cout << "Sort by?" << endl;
			std::cout << "1.User Rating" << endl;
			std::cout << "2.Metascore" << endl;
			std::cout << "Input: ";
			cin >> input;
			rating = stoi(input);
			std::cout << std::endl;

			std::cout << "Sorting Algortihm?" << endl;
			std::cout << "1.Quick sort" << endl;
			std::cout << "2.Merge sort" << endl;
			std::cout << "Input: ";
			cin >> input;
			if (stoi(input) == 1)
			{
				std::cout << "Platform Name: ";
				cin >> input;
				vector<Game*> newList = searchList(Games, input, 2);

				std::cout << "How many games? (Type \"all\" to print every game.) ";
				cin >> input;
				if (input == "all") {
					numGames = newList.size();
				}
				else {
					numGames = stoi(input);
				}
				std::cout << std::endl;

				std::cout << "Quick Sort" << endl;

				auto start = chrono::high_resolution_clock::now();

				quickSort(newList, 0, newList.size() - 1, rating);
				reverse(newList.begin(), newList.end());
				reverse(newList.begin(), newList.end());
				printList(newList, numGames);

				auto stop = chrono::high_resolution_clock::now();
				auto runtime = chrono::duration_cast<chrono::microseconds>(stop - start);
				std::cout << "Runtime: " << runtime.count() << " ms" << endl;
				std::cout << " " << endl;
			}
			else if (stoi(input) == 2)
			{
				std::cout << "Platform Name: ";
				cin >> input;
				vector<Game*> newList = searchList(Games, input, 2);

				std::cout << "How many games? (Type \"all\" to print every game.) ";
				cin >> input;
				if (input == "all") {
					numGames = newList.size();
				}
				else {
					numGames = stoi(input);
				}
				std::cout << std::endl;

				//Use "newList" instead of "Games" here for mergesort as its an updated list of games for the platform.
				
				std::cout << "merge" << endl;

				auto start = chrono::high_resolution_clock::now();
				mergeSort(newList, 0, newList.size() - 1, rating);
				if (input == "all")
					reverse(newList.begin(), newList.end());
				printList(newList, numGames);
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
