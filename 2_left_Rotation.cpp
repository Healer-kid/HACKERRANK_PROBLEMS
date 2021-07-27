A left rotation operation on an array shifts each of the array's elements  unit to the left. For example, if  left rotations are performed on array , then the array would become . Note that the lowest index item moves to the highest index in a rotation. This is called a circular array.

Given an array  of  integers and a number, , perform  left rotations on the array. Return the updated array to be printed as a single line of space-separated integers.

Function Description

Complete the function rotLeft in the editor below.

rotLeft has the following parameter(s):

int a[n]: the array to rotate
int d: the number of rotations
Returns

int a'[n]: the rotated array
Input Format

The first line contains two space-separated integers  and , the size of  and the number of left rotations.
The second line contains  space-separated integers, each an .

Constraints

Sample Input

5 4
1 2 3 4 5
Sample Output

5 1 2 3 4


--------------------------------------


CODE:
METHOD-1
---------------
vector<int> rotLeft(vector<int> a, int d) {
int n=a.size();
while(d--)
{
    int first=a[0];
    for(int i=1;i<=n-1;i++ )
    {
        a[i-1]=a[i];
        
    }
    a[n-1]=first;
    
}
return a;

}




METHOD-2
---------
USING AUXILLARY ARRAY
1)copy the elements from d to n-1 into the ans array
2)copy the elements from 0 to d-1 into the ans array

vector<int> rotLeft(vector<int> a, int d) {
 int n=a.size();
 vector<int> ans(n,0);
 
    int j=0;
    for(int i=d;i<n;i++)
    {
        ans[j++]=a[i];
    }
   
    for(int i=0;i<=d-1;i++)
    {
        ans[j++]=a[i];
    }
    
    return ans;
}