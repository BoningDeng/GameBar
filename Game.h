#pragma once
#include <string>
using namespace std;

class Game
{
private:
	string name;
	string platform;
	string release_date;
	string summary;
	int meta_score;
	float user_review;
public:
	Game(string name_, string platform_, string release_date_, string summary_, int meta_score_, float user_review_);
	string getName();
	string getPlatform();
	string getRelease_date();
	string getSummary();
	int getMeta_score();
	float getUser_review();
	void setUser_review(float newReview);
};

Game::Game(string name_, string platform_, string release_date_, string summary_, int meta_score_, float user_review_)
{
	name = name_;
	platform = platform_;
	release_date = release_date_;
	summary = summary_;
	meta_score = meta_score_;
	user_review = user_review_;
}

string Game::getName()
{
	return name;
}

string Game::getPlatform()
{
	return platform;
}

string Game::getRelease_date()
{
	return release_date;
}

string Game::getSummary()
{
	return summary;
}

int Game::getMeta_score()
{
	return meta_score;
}

float Game::getUser_review()
{
	return user_review;
}

void setUser_review(float newReview) {
	user_review = newReview;
}