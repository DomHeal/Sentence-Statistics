//============================================================================
// Name        : SentenceStats.cpp
// Author      : Dominic Heal
// Version     : MinGW GCC 4.8.1
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;

namespace {
istringstream iss;
map<string, int> myMap;
map<string, int> myMapLetters;
map<string, int>::iterator p;
vector<int> myVec;
vector<int> myVecLetters;
const int FIVE = 5;
}

class Calculations {

public:
	void mostFiveLetters();
	void leastFiveLetters();
	void mostFiveWords();
	void leastFiveWords();

	int median(vector<int> x);
	void mode(vector<int> x);
	int mean(vector<int> x);
	int range(vector<int> x);

	void uniqueNum();

};
void Calculations::mostFiveLetters() {
	map<string, int> map2;
	map2.insert(myMapLetters.begin(), myMapLetters.end());

	p = map2.begin();
	int t = 0;

	for (unsigned int y = myVecLetters.size() - 1; y >= 0; y--) {
		if (map2.size() == 0) {
			break;
		}
		p = map2.begin();

		while (p != map2.end()) {
			if (myVecLetters[y] == p->second) {
				cout << p->first;
				cout << "(" << p->second << ") ";
				t++;
				map2.erase(p);
				break;
			}
			p++;
		}
		if (t == FIVE) {
			break;
		}
	}

}

void Calculations::leastFiveLetters() {
	map<string, int> map2;
	map2.insert(myMapLetters.begin(), myMapLetters.end());

	p = map2.begin();
	int t = 0;
	std::reverse(myVecLetters.begin(), myVecLetters.end());

	for (unsigned int y = myVecLetters.size() - 1; y >= 0; y--) {
		if (map2.size() == map2.empty()) {
			break;
		}
		p = map2.begin();

		while (p != map2.end()) {
			if (myVecLetters[y] == p->second) {
				cout << p->first;
				cout << "(" << p->second << ") ";
				t++;
				map2.erase(p);
				break;
			}
			p++;
		}
		if (t == FIVE) {
			break;
		}
	}

}

void Calculations::mostFiveWords() {
	map<string, int> map2;
	map2.insert(myMap.begin(), myMap.end());

	p = map2.begin();
	int t = 0;

	for (unsigned int y = myVec.size() - 1; y >= 0; y--) {
		if (map2.size() == 0) {
			break;
		}
		p = map2.begin();

		while (p != map2.end()) {
			if (myVec[y] == p->second) {
				cout << p->first;
				cout << "(" << p->second << ") ";
				t++;
				map2.erase(p);
				break;
			}
			p++;
		}
		if (t == FIVE) {
			break;
		}
	}

}

void Calculations::leastFiveWords() {
	map<string, int> map2;
	map2.insert(myMap.begin(), myMap.end());

	p = map2.begin();
	int t = 0;
	std::reverse(myVec.begin(), myVec.end());
	for (unsigned int y = myVec.size() - 1; y >= 0; y--) {
		if (map2.size() == 0) {
			break;
		}
		p = map2.begin();

		while (p != map2.end()) {
			if (myVec[y] == p->second) {
				cout << p->first;
				cout << "(" << p->second << ") ";
				t++;
				map2.erase(p);
				break;
			}
			p++;
		}
		if (t == FIVE) {
			break;
		}
	}

}

int Calculations::median(vector<int> x) {
	return x.at(x.size() / 2);
}

void Calculations::uniqueNum() {
	p = myMap.begin();
	int uniqueCount = 0;
	while (p != myMap.end()) {
		if (p->second == 1) {
			uniqueCount++;
		}

		p++;

	}
	cout << uniqueCount;
}

int Calculations::range(vector<int> x) {
	return x.back() -= x.front();
}
int Calculations::mean(vector<int> x) {
	return accumulate(x.begin(), x.end(), 0) / x.size();

}

void Calculations::mode(vector<int> x) {
	int prevCount = 0;
	int currCount = 0;
	int mode = 0;
	for (unsigned int i = 0; i < x.size(); ++i) {
		for (unsigned int j = 0; j < x.size(); ++j) {
			if (x[j] == x[i]) {
				++currCount;
			}
		}
		if (currCount > prevCount) {
			mode = x[i];
			prevCount = currCount;
		}
		currCount = 0;
	}
	cout << mode;
}

int main() {
	//Defining Variables
	Calculations Cal;

	vector<string> words;
	vector<int> wordslength;
	vector<pair<string, int> > wordfrequency;
	string sentence;
	string word;
	int sentenceCount = 0;
	vector<int>::iterator it;

	cout << "Program is running! Please enter some text...:" << endl;

	while (getline(cin, sentence) && !sentence.empty()) {
		istringstream iss(sentence);
		while (iss >> word) {
			// Change words to lowercase
			std::transform(word.begin(), word.end(), word.begin(), ::tolower);

			// Populate Vectors
			words.push_back(word);
			wordslength.push_back(word.length());

			// Check if word is already in the map, if not, add it.
			if (myMap.find(word) == myMap.end()) {
				myMap[word] = 1;

			}
			// Else increment value (frequency)
			else {
				++myMap[word];
			}

			// Breaking down the string to chars
			for (unsigned int i = 0; i < word.size(); ++i) {
				char letter = word[i];
				string s(1, letter);
				// Check if word is already in the map, if not, add it.
				if (myMapLetters.find(s) == myMapLetters.end()) {
					myMapLetters[s] = 1;

				}

				// Else increment value (frequency)
				else {
					++myMapLetters[s];
				}
			}
		}

		++sentenceCount;
	}

	//Creating Vector from word values
	p = myMap.begin();
	int i = 0;
	while (p != myMap.end()) {
		myVec.push_back(p->second);
		p++;
		i++;
	}

	//Creating Vector from letter values
	p = myMapLetters.begin();
	i = 0;
	while (p != myMapLetters.end()) {
		myVecLetters.push_back(p->second);
		p++;
		i++;
	}

	// Sort Vectors in order
	sort(myVec.begin(), myVec.end());
	sort(myVecLetters.begin(), myVecLetters.end());
	sort(wordslength.begin(), wordslength.end());

	//Print Statistics

	cout << "Print Statistics" << endl;
	cout << "-------------------------------" << endl;
	cout << "Total Sentence Count: " << sentenceCount << endl;
	cout << "Total Word Count: " << words.size() << endl;
	cout << "Total Unique Words: "; Cal.uniqueNum(); cout << endl;

	cout << "-------------------------------" << endl;
	cout << "Mean Length: " << Cal.mean(wordslength) << endl;
	cout << "Mode Length: "; Cal.mode(wordslength);	cout << endl;
	cout << "Median Length: " << Cal.median(wordslength) << endl;
	cout << "Range Length: " << Cal.range(wordslength) << endl;

	cout << "-------------------------------" << endl;

	cout << "Five Most Common Words: " ; Cal.mostFiveWords(); cout << endl;
	cout << "Five Most Common Letter: "; Cal.mostFiveLetters(); cout << endl;
	cout << "Five Least Common Words: "; Cal.leastFiveWords(); cout << endl;
	cout << "Five Least Common Letter: "; Cal.leastFiveLetters(); cout << endl;

}

