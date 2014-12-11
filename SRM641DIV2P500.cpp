/*
Kevin Kane 2014, live contest: success for 389.48 points

Problem Statement
    
We have chosen a finite set of points in the plane. You are given their coordinates in the vector <int>s x and y: for each valid i, there is a point with coordinates (x[i],y[i]). We are interested in triangles with the following properties:
Each vertex of the triangle is one of our chosen points.
The point (0,0) lies inside the triangle.
Return the number of such triangles. Note that the constraints guarantee that there are no degenerate triangles and that the point (0,0) never lies on the boundary of a triangle.
Definition
    
Class:
TrianglesContainOriginEasy
Method:
count
Parameters:
vector <int>, vector <int>
Returns:
int
Method signature:
int count(vector <int> x, vector <int> y)
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
x and y will contain between 3 and 50 elements, inclusive.
-
x and y will contain the same number of elements.
-
Each element of x and y will be between -1,000 and 1,000, inclusive.
-
No two points will be the same.
-
No three points will be collinear.
-
No point will be on the origin.
-
There will be no two points P and Q such that P, Q, and the origin are collinear.
Examples
0)

    
{-1,-1,1}
{1,-1,0}
Returns: 1
There is exactly one possible triangle. It does contain the origin.
1)

    
{-1,-1,1,2}
{1,-1,2,-1}
Returns: 2
There are four possible triangles. Two of them contain the origin. One is the triangle with vertices in (-1,1), (-1,-1), and (2,-1). The other is the triangle with vertices in (-1,-1), (1,2), and (2,-1).
2)

    
{-1,-2,3,3,2,1}
{-2,-1,1,2,3,3}
Returns: 8

3)

    
{1,5,10,5,-5,7,-9,-6,-3,0,8,8,1,-4,7,-3,10,9,-6}
{5,-6,-3,4,-2,-8,-7,2,7,4,2,0,-4,-8,7,5,-5,-2,-9}
Returns: 256
*/

#include<vector>
#include<string>
#include<sstream>
using namespace std;
class TrianglesContainOriginEasy{
public:
float sign (int p1x, int p1y, int p2x, int p2y, int p3x, int p3y)
{
    return (p1x - p3x) * (p2y - p3y) - (p2x - p3x) * (p1y - p3y);
}

bool PointInTriangle (int ptx, int pty, int v1x, int v1y, int v2x, int v2y, int v3x, int v3y)
{
    bool b1, b2, b3;

    b1 = sign(ptx, pty, v1x, v1y, v2x, v2y) < 0.0f;
    b2 = sign(ptx, pty, v2x, v2y, v3x, v3y) < 0.0f;
    b3 = sign(ptx, pty, v3x, v3y, v1x, v1y) < 0.0f;

    return ((b1 == b2) && (b2 == b3));
}

int count(vector <int> x, vector <int> y){
	int result = 0;
	for(int i=0; i<x.size(); i++){
		for(int j=i+1; j<y.size(); j++){
			for(int k = j+1; k<x.size(); k++){
				if(PointInTriangle(0, 0, x[i], y[i], x[j], y[j], x[k], y[k])){
					 result++;
				}
			}
		}
	}
	return result;
}



};
