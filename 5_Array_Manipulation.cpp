Starting with a 1-indexed array of zeros and a list of operations, for each operation add a value to each the array element between two given indices, inclusive. Once all operations have been performed, return the maximum value in the array.

Example


Queries are interpreted as follows:

    a b k
    1 5 3
    4 8 7
    6 9 1
Add the values of  between the indices  and  inclusive:

index->	 1 2 3  4  5 6 7 8 9 10
	[0,0,0, 0, 0,0,0,0,0, 0]
	[3,3,3, 3, 3,0,0,0,0, 0]
	[3,3,3,10,10,7,7,7,0, 0]
	[3,3,3,10,10,8,8,8,1, 0]
The largest value is  after all operations are performed.

Function Description

Complete the function arrayManipulation in the editor below.

arrayManipulation has the following parameters:

int n - the number of elements in the array
int queries[q][3] - a two dimensional array of queries where each queries[i] contains three integers, a, b, and k.
Returns

int - the maximum value in the resultant array
Input Format

The first line contains two space-separated integers  and , the size of the array and the number of operations.
Each of the next  lines contains three space-separated integers ,  and , the left index, right index and summand.

Constraints

Sample Input

5 3
1 2 100
2 5 100
3 4 100
Sample Output

200




-----------------------
METHOD-1
BRUTE FORCE APPROACH


long arrayManipulation(int n, vector<vector<int>> queries) {

     vector<long> v(n+1,0);
     long maxi=INT_MIN;
     for(long i=0;i<queries.size();i++)
    {
        long a=queries[i][0];
        long b=queries[i][1];
        long k=queries[i][2];
        for(long j=a;j<=b;j++)
        {
            v[j]+=k;
            maxi=max(maxi,v[j]);
            
        }
        
    }
return maxi;
}


--------------------------------------------
METHOD-2
o(n+m)

1) 3,5 add 7
 ==> a[3]=7 //a[starting]=7
     a[4]=a[3]+a[4]
     a[5]=a[3]+a[4]+a[5]
     a[6]=a[3]+a[4]+a[5]+a[6] //but a[6] should not have 7 instead it should have 0
	but do we know where to stop?
     so in the b+1 (6th position,in this case)
	we need to subtract 7 ,so it will have zero now as answer and thats what we want






long arrayManipulation(int n, vector<vector<int>> queries) {

     vector<long> v(n+1,0);
     long maxi=INT_MIN;
     for(long i=0;i<queries.size();i++)
    {
        long a=queries[i][0];
        long b=queries[i][1];
        long k=queries[i][2];
        v[a]+=k;
        if(b<n)
        v[b+1]-=k;
        
        
    }
    for(int i=1;i<=n;i++)
    {
        v[i]+=v[i-1];
        maxi=max(v[i],maxi);
    }
return maxi;
}