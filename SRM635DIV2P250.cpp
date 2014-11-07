/*
Problem Statement
    
We call a pair of strings (s, t) "wood" if t is contained in s as a subsequence. (See Notes for a formal definition.)
 
Given strings s and t, return the string "Yep, it's wood." (quotes for clarity) if the pair (s, t) is wood and "Nope." otherwise.
Definition
    
Class:
IdentifyingWood
Method:
check
Parameters:
string, string
Returns:
string
Method signature:
string check(string s, string t)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Stack limit (MB):
256
Notes
-
String t is contained in string s as a subsequence if we can obtain t by removing zero or more (not necessarily consecutive) characters from s.
Constraints
-
s and t will consist only of lowercase English letters.
-
s and t will each be between 1 and 10 characters long, inclusive.
Examples
0)

    
"absdefgh"
"asdf"
Returns: "Yep, it's wood."

1)

    
"oxoxoxox"
"ooxxoo"
Returns: "Nope."

2)

    
"oxoxoxox"
"xxx"
Returns: "Yep, it's wood."

3)

    
"qwerty"
"qwerty"
Returns: "Yep, it's wood."

4)

    
"string"
"longstring"
Returns: "Nope."
*/

#include <string>
using namespace std;
class IdentifyingWood{
public:
string check(string s, string t)
{
	string success = "Yep, it's wood.";
	string fail = "Nope.";
	int sSize = s.size();
	int tSize = t.size();
	if(sSize < tSize)
		return fail;
		
	//loop through t, only continuing when we find a matching character
	for(int i = 0; i < tSize; i++)
	{
		for(int j = 0; j < sSize; j++)
		{
			if(t.at(i) == s.at(j))
			{
				s = s.substr(j);
				break;
			}
			if((sSize - tSize - j + i ) < 0)
				return fail;
		}
	}
	return success;
}
};
