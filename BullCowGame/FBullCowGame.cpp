#include "FBullCowGame.h"



FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset(){
	myCurrentTry = 1;
	myMaxTries = 8;
	myHiddenWord = "planet";
	return;
}

int FBullCowGame::getMaxTries() const{
	
	return myMaxTries;
}

int FBullCowGame::getCurrentTry() const{
	return myCurrentTry;
}

int32 FBullCowGame::getHiddenWordLength() const
{
	return myHiddenWord.length();
}

//to use the enum list you must use EWordStatus::
EGuessValidity FBullCowGame::confirmWord(FString guess) const{
	 


	if (false)//if the guess isn't an isogram 
	{
		return  EGuessValidity::NOT_ISOGRAM;
	}
	else if (false)	//if the guess isn't all lowercase
	{
		return EGuessValidity::NOT_LOWERCASE;
	}
	else if (guess.length() != getHiddenWordLength())  //if the guess is the wrong length
	{
		return EGuessValidity::WRONG_LENGTH;
	}
	else
	{
		return EGuessValidity::OK;
	}
		

		
	
		
	
}


bool FBullCowGame::IsGameWon() const {
	if()
	return false;
}

FBullCowCount FBullCowGame::awardAnimals(FString guess)
{
	//incrment turn number.
	myCurrentTry++;
	//setup a return value
	FBullCowCount count;
	int maxlength = myHiddenWord.length();
	//loop through all letters in the guess
	for (int32 gx = 0; gx < maxlength; gx++) {
		// compare place against hidden word and increment any bulls
		
		
		for (int32 hx = 0; hx < maxlength; hx++) {
			//check if any letter used in the guessed word matches a letter in the hidden word
			if (guess[gx] == myHiddenWord[hx]){
				if (gx == hx){
					count.bulls++;
				}
				else {
					count.cows++;
				}
			}
			
		}
		
	}


	return count;
}
