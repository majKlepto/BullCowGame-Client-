#pragma once
#include <string>
using FString = std::string;
using int32 = int;


//enum creates a list of tokens that can be returned to mean different things
	// in this case the token list represent differnt states of a guessed words validity 
	// there can be multiple reasons for failure and the enum will be able to tell us why
	// see confirmWord()
enum EGuessValidity {
	INVALID,
	OK,
	WRONG_LENGTH,
	NOT_LOWERCASE,
	NOT_ISOGRAM,

};

//structs act similarly to a class object but their member variables are public 
struct FBullCowCount {
	int32 bulls = 0;
	int32 cows = 0;

};

class FBullCowGame {
public:
	
	FBullCowCount awardAnimals(FString vGuess);
	FBullCowGame();
	void Reset();

	// in this context the key word const simply places a safeguard over the function, preventing me from changing any of the member variables while within the function
	int32 getMaxTries() const;
	int32 getCurrentTry() const;
	int32 getHiddenWordLength() const;
	EGuessValidity confirmWord(FString guess) const;
	bool IsGameWon()const;

private:
	int32 myCurrentTry;
	int32 myMaxTries;
	FString myHiddenWord;

}; 