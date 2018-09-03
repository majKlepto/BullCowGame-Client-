#include "FBullCowGame.h"



FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset(){
	myCurrentTry = 1;
	myMaxTries = 8;
	return ;
}

int FBullCowGame::getMaxTries() const{
	
	return myMaxTries;
}

int FBullCowGame::getCurrenttry() const{
	return myCurrentTry;
}

bool FBullCowGame::confirmWord(FString guess) const{
	return false;
}

bool FBullCowGame::checkWord() {
	return false;
}
