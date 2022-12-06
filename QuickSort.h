#pragma once
#include "Game.h"
#include <vector>
#include <iostream>
void swap(Game* a, Game* b)
{
	Game t = *a;
	*a = *b;
	*b = t;

}
int partition(vector<Game*> vect, int low, int high) {
	Game* pivot = vect[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (vect[j]->getUser_review() < pivot->getUser_review()) {
			i++;
			swap(vect[i], vect[j]);
		}
	}
	swap(vect[i + 1], vect[high]);
	return (i + 1);
}
int partition2(vector<Game*> vect, int low, int high) {
	Game* pivot = vect[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (vect[j]->getMeta_score() < pivot->getMeta_score()) {
			i++;
			swap(vect[i], vect[j]);
		}
	}
	swap(vect[i + 1], vect[high]);
	return (i + 1);
}
void quickSort(vector<Game*> vect, int low, int high, int input)
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