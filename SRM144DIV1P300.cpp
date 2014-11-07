/*
Problem Statement
    
Let's say you have a binary string such as the following:
011100011
One way to encrypt this string is to add to each digit the sum of its adjacent digits. For example, the above string would become:
123210122
In particular, if P is the original string, and Q is the encrypted string, then Q[i] = P[i-1] + P[i] + P[i+1] for all digit positions i. Characters off the left and right edges of the string are treated as zeroes.
An encrypted string given to you in this format can be decoded as follows (using 123210122 as an example):
Assume P[0] = 0.
Because Q[0] = P[0] + P[1] = 0 + P[1] = 1, we know that P[1] = 1.
Because Q[1] = P[0] + P[1] + P[2] = 0 + 1 + P[2] = 2, we know that P[2] = 1.
Because Q[2] = P[1] + P[2] + P[3] = 1 + 1 + P[3] = 3, we know that P[3] = 1.
Repeating these steps gives us P[4] = 0, P[5] = 0, P[6] = 0, P[7] = 1, and P[8] = 1.
We check our work by noting that Q[8] = P[7] + P[8] = 1 + 1 = 2. Since this equation works out, we are finished, and we have recovered one possible original string.
Now we repeat the process, assuming the opposite about P[0]:
Assume P[0] = 1.
Because Q[0] = P[0] + P[1] = 1 + P[1] = 1, we know that P[1] = 0.
Because Q[1] = P[0] + P[1] + P[2] = 1 + 0 + P[2] = 2, we know that P[2] = 1.
Now note that Q[2] = P[1] + P[2] + P[3] = 0 + 1 + P[3] = 3, which leads us to the conclusion that P[3] = 2. However, this violates the fact that each character in the original string must be '0' or '1'. Therefore, there exists no such original string P where the first digit is '1'.
Note that this algorithm produces at most two decodings for any given encrypted string. There can never be more than one possible way to decode a string once the first binary digit is set.
Given a string message, containing the encrypted string, return a vector <string> with exactly two elements. The first element should contain the decrypted string assuming the first character is '0'; the second element should assume the first character is '1'. If one of the tests fails, return the string "NONE" in its place. For the above example, you should return {"011100011", "NONE"}.
Definition
    
Class:
BinaryCode
Method:
decode
Parameters:
string
Returns:
vector <string>
Method signature:
vector <string> decode(string message)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
message will contain between 1 and 50 characters, inclusive.
-
Each character in message will be either '0', '1', '2', or '3'.
Examples
0)

    
"123210122"
Returns: { "011100011",  "NONE" }
The example from above.
1)

    
"11"
Returns: { "01",  "10" }
We know that one of the digits must be '1', and the other must be '0'. We return both cases.
2)

    
"22111"
Returns: { "NONE",  "11001" }
Since the first digit of the encrypted string is '2', the first two digits of the original string must be '1'. Our test fails when we try to assume that P[0] = 0.
3)

    
"123210120"
Returns: { "NONE",  "NONE" }
This is the same as the first example, but the rightmost digit has been changed to something inconsistent with the rest of the original string. No solutions are possible.
4)

    
"3"
Returns: { "NONE",  "NONE" }

5)

    
"12221112222221112221111111112221111"
Returns: 
{ "01101001101101001101001001001101001",
  "10110010110110010110010010010110010" }
  */
  
  #include<vector>
#include<string>
#include<sstream>
using namespace std;
class BinaryCode
{
	public:
	vector<string> decode(string message)
	{
		vector<string> result;
		int n = message.length();
		if(n == 1){
			if(message.at(0) - '0' == 0){
				result.push_back("0");
				result.push_back("NONE");
			}
			else{
				result.push_back("NONE");
				result.push_back("1");
			}
			return result;
		}
		int Q[n];
		int P[n];
		
		//decode message into Q
		for(int i=0; i<n; i++){
			Q[i] = message.at(i) - '0';
		}
		
		//obtain result with zero assumed
		bool success = true;
		P[0] = 0;
		P[1] = Q[0];
		for(int i= 2; i<n; i++){
			P[i] = Q[i-1] - P[i-1] - P[i-2];
			if(P[i] < 0 || P[i] > 1){
				success = false;
				break;
			}
		}
		
		ostringstream oss("");
		if(success){
			for(int i=0; i<n; i++){
				oss << P[i];	
			}
			result.push_back(oss.str());
		}
		else{
			result.push_back("NONE");
		}
		
		//obtain result with 1 assumed in P[0]
		oss.clear();
		success = true;
		P[0] = 1;
		P[1] = Q[0] - P[0];
		for(int i= 2; i<n; i++){
			P[i] = Q[i-1] - P[i-1] - P[i-2];
			if(P[i] < 0 || P[i] > 1){
				success = false;
				break;
			}
		}
		if(success){
			for(int i=0; i<n; i++){
				oss << P[i];	
			}
			result.push_back(oss.str());
		}
		else{
			result.push_back("NONE");
		}
		return result;
	}
};
