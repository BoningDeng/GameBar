#pragma once
#include "Game.h"
#include <vector>
#include <iostream>

void swap(Game a, Game b)
{
    Game t = a;
    a = b;
    b = t;
}

int partition(vector<Game> vect, int low, int high) {
    Game pivot = vect[high];
    int i = (low - 1);
	
    for (int j = low; j <= high - 1; j++) {
		if (vect[j].getUser_review() == -1 ) {
			vect[j].setUser_review(0);
		}
		else if(pivot.getUser_review() == -1) {
			pivot.setUser_review(0);
		}

        if (vect[j].getUser_review() < pivot.getUser_review()) {
            i++;
            swap(vect[i], vect[j]);
        }
    }
    swap(vect[i + 1], vect[high]);
    return (i + 1);
}

int partition2(vector<Game> vect, int low, int high) {
	Game pivot = vect[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (vect[j].getMeta_score() < pivot.getMeta_score()) {
			i++;
			swap(vect[i], vect[j]);
		}
	}
	swap(vect[i + 1], vect[high]);
	return (i + 1);
}

void quickSort(vector<Game> vect, int low, int high, int input)
{
	if (input == 1) {
		if (low < high) {
			int pi = partition(vect, low, high);

			quickSort(vect, low, pi - 1, input);
			quickSort(vect, pi + 1, high, input);
		}
	}
	else if (input == 2) {
		if (low < high) {
			int pi = partition2(vect, low, high);

			quickSort(vect, low, pi - 1, input);
			quickSort(vect, pi + 1, high, input);
		}
	}
}

void quickSortHelper(vector<Game> Games, int input) {
	vector<Game> tempVect;
	vector<Game> tempVect2;
	vector<Game> tempVect3;
	vector<Game> tempVect4;
	vector<Game> tempVect5;
	vector<Game> tempVect6;
	vector<Game> tempVect7;
	vector<Game> tempVect8;
	vector<Game> tempVect9;
	vector<Game> tempVect10;
	for (int i = 0; i < 2000; i++) {
		tempVect.push_back(Games[i]);
	}

	for (int i = 2000; i < 4000; i++) {
		tempVect2.push_back(Games[i]);
	}

	for (int i = 4000; i < 6000; i++) {
		tempVect3.push_back(Games[i]);
	}

	for (int i = 6000; i < 8000; i++) {
		tempVect4.push_back(Games[i]);
	}

	for (int i = 8000; i < 10000; i++) {
		tempVect5.push_back(Games[i]);
	}

	for (int i = 10000; i < 12000; i++) {
		tempVect6.push_back(Games[i]);
	}

	for (int i = 12000; i < 14000; i++) {
		tempVect7.push_back(Games[i]);
	}

	for (int i = 14000; i < 16000; i++) {
		tempVect8.push_back(Games[i]);
	}

	for (int i = 16000; i < 18000; i++) {
		tempVect9.push_back(Games[i]);
	}

	for (int i = 18000; i < 18802; i++) {
		tempVect10.push_back(Games[i]);
	}

	quickSort(tempVect, 0, tempVect.size() - 1, input);
	std::cout << "1/10" << std::endl;
	quickSort(tempVect2, 0, tempVect2.size() - 1, input);
	std::cout << "2/10" << std::endl;
	quickSort(tempVect3, 0, tempVect3.size() - 1, input);
	std::cout << "3/10" << std::endl;
	quickSort(tempVect4, 0, tempVect4.size() - 1, input);
	std::cout << "4/10" << std::endl;
	quickSort(tempVect5, 0, tempVect5.size() - 1, input);
	std::cout << "5/10" << std::endl;
	quickSort(tempVect6, 0, tempVect6.size() - 1, input);
	std::cout << "6/10" << std::endl;
	quickSort(tempVect7, 0, tempVect7.size() - 1, input);
	std::cout << "7/10" << std::endl;
	quickSort(tempVect8, 0, tempVect8.size() - 1, input);
	std::cout << "8/10" << std::endl;
	quickSort(tempVect9, 0, tempVect9.size() - 1, input);
	std::cout << "9/10" << std::endl;
	quickSort(tempVect10, 0, tempVect10.size() - 1, input);
	std::cout << "10/10" << std::endl;

	vector<Game> Games2;
	for (int i = 0; i < tempVect.size(); i++) {
		Games2.push_back(tempVect[i]);
	}

	for (int i = 0; i < tempVect2.size(); i++) {
		Games2.push_back(tempVect2[i]);
	}

	for (int i = 0; i < tempVect3.size(); i++) {
		Games2.push_back(tempVect3[i]);
	}

	for (int i = 0; i < tempVect4.size(); i++) {
		Games2.push_back(tempVect4[i]);
	}

	for (int i = 0; i < tempVect5.size(); i++) {
		Games2.push_back(tempVect5[i]);
	}

	for (int i = 0; i < tempVect6.size(); i++) {
		Games2.push_back(tempVect6[i]);
	}

	for (int i = 0; i < tempVect7.size(); i++) {
		Games2.push_back(tempVect7[i]);
	}

	for (int i = 0; i < tempVect8.size(); i++) {
		Games2.push_back(tempVect8[i]);
	}

	for (int i = 0; i < tempVect9.size(); i++) {
		Games2.push_back(tempVect9[i]);
	}

	for (int i = 0; i < tempVect10.size(); i++) {
		Games2.push_back(tempVect10[i]);
	}
	Games = Games2;
}
