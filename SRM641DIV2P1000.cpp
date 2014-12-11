/*
Kevin Kane 2014, live contest
not successful submission

Problem Statement
    
Fox Ciel likes shuffling cards. She uses a deck with 2N cards, numbered 1 through 2N. Ciel always uses the same procedure when shuffling. One round of shuffling looks as follows:
She splits the deck into two piles: the top N cards will be pile A, the bottom N cards pile B.
She takes pile A and rearranges the cards it contains arbitrarily.
She takes pile B and rearranges the cards it contains arbitrarily.
She interleaves the cards from the two piles, producing a single deck again. More precisely, if pile A has cards A1,A2,...,AN and pile B has cards B1,B2,...,BN then the new deck will be A1,B1,A2,B2,...,AN,BN. (Note that the first card has to come from pile A.)
For example, let N=2 and suppose that Ciel starts with the sorted deck 1,2,3,4. One possible round of shuffling looks as follows:
She splits the deck into two piles: the cards 1,2 are pile A and the cards 3,4 are pile B.
She rearranges pile A into 1,2. (I.e., she keeps the cards in their current order.)
She rearranges pile B into 4,3.
She merges the two piles, obtaining the deck 1,4,2,3.
In the above example we have shown one of four possible outcomes of the shuffling process. After the first round of shuffling, Ciel could have that deck in one of these four orders:
1,3,2,4
1,4,2,3
2,3,1,4
2,4,1,3
You are given a vector <int> permutation which contains a permutation of the 2N cards. Ciel's deck is currently sorted: the cards are in the order 1,2,3,...,2N from top to bottom. Ciel wants to make exactly two rounds of shuffling. After the second round the order of cards in her deck should correspond to the given permutation. Return "Possible" (quotes for clarity) if this can be done and "Impossible" otherwise.
Definition
    
Class:
ShufflingCardsDiv2
Method:
shuffle
Parameters:
vector <int>
Returns:
string
Method signature:
string shuffle(vector <int> permutation)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Stack limit (MB):
256
Constraints
-
permutation will contain between 4 and 200 elements, inclusive.
-
The number of elements in permutation will be even.
-
The elements of permutation will form a permutation of the numbers 1 through 2N, where 2N is the number of elements in permutation.
Examples
0)

    
{1,2,3,4}
Returns: "Possible"
Fox Ciel can make the following two shuffles: {1,2,3,4} -> {1,3,2,4} -> {1,2,3,4}. Note that she cannot simply keep the deck in sorted order, the shuffling procedure does not allow that. Luckily for Ciel, it is possible to shuffle the deck in the first round and to return the cards to their original places in the second round.
1)

    
{4,3,2,1}
Returns: "Possible"

2)

    
{1,3,2,4}
Returns: "Impossible"
Ciel can produce this permutation after the first round of shuffling. However, it is not possible to start with a sorted deck and to have this permutation of cards after two rounds of shuffling.
3)

    
{1,4,2,5,3,6}
Returns: "Impossible"

4)

    
{8,5,4,9,1,7,6,10,3,2}
Returns: "Possible"
*/

 #include<vector>
#include<string>
#include<sstream>
#include<iostream>
#include <algorithm>

using namespace std;

class ShufflingCardsDiv2{
public:
string shuffle(vector <int> permutation){
	bool success = true;
	int min = permutation[0];
	int max = permutation[0];
	int n = permutation.size() / 2;	
	
	for(int i=0; i<permutation.size(); i++){
		if(permutation[i] < min){
			min = permutation[i];
		}
		if(permutation[i] > max){
			max = permutation[i];
		}
	}
	vector<int> deck;
	vector<int> front;
	vector<int> back;
	for(int i=min; i<=max; i++){
		if(i<n+min){
			front.push_back(i);
		}
		else{
			back.push_back(i);
		}
		deck.push_back(i);
	}
	
	vector<vector<int>> possible;
	vector<vector<int>> backPossible;
	vector<vector<int>> frontPossible;
	
	backPossible.push_back(back);
	frontPossible.push_back(front);
	while(std::next_permutation(back.begin(), back.end())){
		backPossible.push_back(back);
	}
	while(std::next_permutation(front.begin(), front.end())){
		frontPossible.push_back(front);
	}
	for(int i=0; i<backPossible.size(); i++){
		for(int j = 0; j<frontPossible.size(); j++){
			vector<int> combine;
			for(int k=0; k<backPossible.size(); k++){
				combine.push_back(backPossible[i][k]);
			}
			for(int k=0; k<frontPossible.size(); k++){
				combine.push_back(frontPossible[j][k]);
			} 
			vector<vector<int>>::iterator it = find(possible.begin(), possible.end(),combine);
			if( it == possible.end()){
				possible.push_back(combine);
			} 
		}
	}
	
		for(int i=min; i<=max; i++){
		if(i<n+min){
			front.push_back(i);
		}
		else{
			back.push_back(i);
		}
		deck.push_back(i);
	}
	
	for(int l = 0; l<possible.size(); l++){
		front.clear();
		back.clear();
		int count = 0;
		for(vector<int>::iterator iit = possible[l].begin(); iit!= possible[l].end(); iit++){
			if(count < n){
				front.push_back(*iit);
			}
			else{
				back.push_back(*iit);
			}
			count++;
		}

 	backPossible.clear();
	frontPossible.clear();
	vector<vector<int>> final;
	
	backPossible.push_back(back);
	frontPossible.push_back(front);
	while(std::next_permutation(back.begin(), back.end())){
		backPossible.push_back(back);
	}
	while(std::next_permutation(front.begin(), front.end())){
		frontPossible.push_back(front);
	}
	for(int i=0; i<backPossible.size(); i++){
		for(int j = 0; j<frontPossible.size(); j++){
			vector<int> combine;
			for(int k=0; k<backPossible.size(); k++){
				combine.push_back(backPossible[i][k]);
			}
			for(int k=0; k<frontPossible.size(); k++){
				combine.push_back(frontPossible[j][k]);
			} 
			success = true;
			for(int m=0; m<combine.size(); m++){
				if(combine[m]!=permutation[m]){
					success = false;
				}
			}
			if(success){
				return "Possible";
			}
		
		}
	}
	}
	
		return "Impossible";
	
}

};
