#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstring>
#include <iostream>
#define MAX_SIZE 128
#define MAX 120
using namespace std;


void maxlenght(FILE* filesource) {
	char word[MAX_SIZE];
	char longwoord[MAX] = " ";
	while (fscanf(filesource, "%s", word) == 1) {
		if (strlen(word) > strlen(longwoord)){
			strcpy(longwoord, word);
		}
		
	}
	cout << "The most long word is: " << longwoord << endl;
}
void samword(FILE*  same, char woord[]) {
	char words[MAX_SIZE];
	int count = 0;
	while (fscanf(same, "%s", words) == 1) {
		if (strcmp(woord, words) == 0) {
			count++;
		}
		}
	cout << "Amount of the same words: " << count << endl;
}
int main() {
	const char* pathout = "Source1.txt";
	const char* sameword = "Tcp.txt";
	
	FILE* fileout, *fileX;

	if (fopen_s(&fileout, pathout, "r") != NULL) {
		cout << "Can't open: " ;
	}
	else if (fopen_s(&fileX, sameword, "r") != NULL) {
		cout << "Can't open: ";
	}
	
	else {
		maxlenght(fileout);
		char theword[MAX_SIZE];
		cout << "Your word: " << endl;
		cin >> theword;

		samword(fileX, theword);
		
		fclose(fileout);
		fclose(fileX);
	}
	
}