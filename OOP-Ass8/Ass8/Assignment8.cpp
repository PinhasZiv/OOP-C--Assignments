// Pinhas Ziv, Nir Avisror
#include <iostream>

using namespace std;

// Declaring functions
int numCharsInStr(char*, char*);
int indexOfEqual(char*, char*);
int EncryptionText(char*, char*);
bool checkWord(char*, char*);
int* even(int*, int);
int sortArr(int*, int);
void printArr(int*, int);
void swap(int*, int*);

int main() {
	// Question 1:
	cout << "// Question 1:" << endl;
	char str1[] = "aabbcedef";
	char str2[] = "abc";
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
	cout << "Number of impressions: " << numCharsInStr(str1, str2) << endl;
	
	// Question 2::
	cout << "\n// Question 2:" << endl;
	char str3[] = "keyboard";
	char str4[] = "blackboard";
	cout << "str3: " << str3 << endl;
	cout << "str4: " << str4 << endl;
	cout << "Index of equal: " << indexOfEqual(str3, str4) << endl;
	
	// Question 3:
	cout << "\n// Question 3:" << endl;
	char str5[] = "The 2017-18 North Korea crisis was a period of heightened tension between North Korea and the United States";
	char str6[] = "Korea";

	cout << "Before: " << str5 << endl;
	cout <<  "Number of encrypted words: " << EncryptionText(str5, str6) << endl;
	cout << "After: " << str5 << endl;

	// Question 4:
	cout << "\n// Question 4:" << endl;
	int arr[] = { 3, 5, 3, 9, 6, 5, 4 };
	printArr(arr, 7);
	cout << "First even address: " << even(arr, 7) << " = " << *(even(arr, 7)) << endl;

	// Question 5:
	cout << "\n// Question 5:" << endl;
	printArr(arr, 7);
	cout << "Number of different digits: " << sortArr(arr, 7) << endl;
	cout << "Sorted array: " << endl;
	printArr(arr, 7);
}

// Returns number of repeated impressions of letters within a given string
int numCharsInStr(char* str1, char* str2) {
	int counter = 0;
	int str2Len = strlen(str2);

	while (*str1 != '\0') {
		
		while (*str2 != '\0') {
			if (*str1 == *str2) {
				counter++;
			}
			str2++;
		}
		str2 -= str2Len;
		str1++;
	}
	return counter;
}

// Return the index of the first string that started
 // from this index, the strings are the same to the end.
int indexOfEqual(char* str1, char* str2) {
	int str1Len = strlen(str1);
	int str2Len = strlen(str2);

	while (str1Len >= 0 && str2Len >= 0) {
		if (*(str1 + str1Len) != *(str2 + str2Len)) {
			if (str1Len == strlen(str1))
				return -1;
			else
				return str1Len + 1;
		}
		else {
			str1Len--;
			str2Len--;
		}
	}
	return str1Len + 1;
}

// Replace all instances of the word with asterisks.
// in addition, the function will return the amount of words encrypted.
int EncryptionText(char* text, char* word) {
	int counter = 0;
	int textLen = strlen(text);
	int wordLen = strlen(word);

	while (*text != '\0') {
		if (checkWord(text, word)) {
			counter++;
			for (int i = 0; i < wordLen; i++, text++) {
				*text = '*';
			}
		}
		else {
			text++;
		}
	}
	return counter;
}

// Auxiliary function
// Returns true if received an index where the word starts appearing in the string,
 //otherwise - returns false
bool checkWord(char* text, char* word) {
	while (*word != '\0' && *text != '\0') {
		if (*text != *word) {
			return false;
		}
		word++;
		text++;
	}
	return true;
}

// Gets an array of integers and their size and returns a pointer to the even number
// The first in the array. If there is no even number, the function returns NULL
int* even(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		if ((*arr % 2) == 0) {
			return arr;
		} else {
			arr++;
		}
	}
	return NULL;
}

// Gets an array of integers and their size. The function will sort the smallest organs to grow.
// In addition, the function returns the number of different organs in the array.
int sortArr(int* arr, int size) {
	int counter = 0;
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (int i = 0; i < size - 1; i++) {
			if (*(arr + i) > *(arr + i + 1)) {
				swap((arr + i), (arr + i + 1));
				sorted = false;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		if (*(arr + i) != *(arr + i + 1)) {
			counter++;
		}
	}
	return counter;
}

// Auxiliary function
// Prints an int type array
void printArr(int* arr, int size) {
	for (int i = 0; i < size; i++){
		cout << "[ " << *(arr + i) << " ] ";
	}
	cout << endl;
}

// Auxiliary function
// Swap values between two int pointers
void swap(int* first, int* second) {
	int temp = *second;
	*second = *first;
	*first = temp;
}