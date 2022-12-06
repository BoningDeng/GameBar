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
	void setName(std::string name_);
	void setPlatform(std::string platform_);
	void setMeta_score(int meta_score_);
	void setRelease_Date(std::string newReview);
	void setSummary(std::string newReview);
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

void Game::setUser_review(float user_review_) {
	user_review = user_review_;
}

void Game::setName(std::string name_) {
	name = name_;
}

void Game::setPlatform(std::string platform_) {
	platform = platform_;
}

void Game::setMeta_score(int meta_score_) {
	meta_score = meta_score_;
}

void Game::setRelease_Date(std::string release_date_) {
	release_date = release_date_;
}

void Game::setSummary(std::string summary_) {
	summary = summary_;
}