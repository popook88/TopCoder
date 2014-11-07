/*
Problem Statement
    
"Němec's quadratic law: how many minutes the teacher was late to the lesson, that many minutes squared he'll end the lesson earlier." 
 
In other words, if the teacher is t minutes late (for some non-negative integer t), he should end the lesson t2 minutes early. Of course, this means the teacher can't be too late, because a lesson can't end before even starting. It is, however, possible for the teacher to arrive and end the lesson immediately (in fact, he then only arrives to tell the students that the lesson's cancelled).
 
You're given a long long d. The lesson was supposed to take d minutes. Compute and return the largest non-negative integer t such that the teacher can be t minutes late.
Definition
    
Class:
QuadraticLaw
Method:
getTime
Parameters:
long long
Returns:
long long
Method signature:
long long getTime(long long d)
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
d will be between 1 and 1,000,000,000,000,000,000, inclusive.
Examples
0)

    
1
Returns: 0
The lesson was supposed to take 1 minute. The teacher can only be 0 minutes late, in which case he ends the lesson 0 minutes early (i.e. he arrives and ends the lecture on time).
1)

    
2
Returns: 1
It's possible for the teacher to be 1 minute late and end the lecture 1 minute early (so there's no lecture at all).
2)

    
5
Returns: 1

3)

    
6
Returns: 2

4)

    
7
Returns: 2

5)

    
1482
Returns: 38

6)

    
1000000000000000000
Returns: 999999999

7)

    
31958809614643170
Returns: 178770270
*/

class QuadraticLaw
{
public:
long long getTime(long long d){
return recursive(d, 1, 1);
}

long long recursive(long long d, long long current, long long increment)
{
	if(((d-current) - (current*current)) < 0)
	{
		if( (d-current+1) - ((current-1) * (current-1)) >=0)
			return current-1;
		else
			return recursive(d, current-(increment/2), 1);
	}
	else
	{
		return recursive(d, current + increment, increment*increment);
	}
}
};
