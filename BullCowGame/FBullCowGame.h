#pragma once
#include <string>

class FBullCowGame {
public:
	void Reset();
	int getMaxTries();
	int getCurrenttry();
	bool confirmWord(std::string guess);
	bool checkWord();


private:
	int myCurrentTry;
	int myMaxTries;

};