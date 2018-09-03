#pragma once
#include <string>

class FBullCowGame {
	using FString = std::string;
	using int32 = int;

public:
	FBullCowGame();

	//This is called a destructor, I have no idea what it does
	~FBullCowGame();

	void Reset();
	// in this context the key word const simply places a safeguard over the function, preventing me from changing any of the member variables while within the function
	int getMaxTries() const;
	int getCurrenttry() const;
	bool confirmWord(std::string guess) const;
	bool checkWord();

	//TODO create method that will count buls and cows, increment the turn


private:
	int32 myCurrentTry;
	int32 myMaxTries;

}; 