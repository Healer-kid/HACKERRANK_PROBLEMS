You are given an array and you need to find number of tripets of indices  such that the elements at those indices are in geometric progression for a given common ratio  and .

Example
 

There are  and  at indices  and . Return .

Function Description

Complete the countTriplets function in the editor below.

countTriplets has the following parameter(s):

int arr[n]: an array of integers
int r: the common ratio
Returns

int: the number of triplets
Input Format

The first line contains two space-separated integers  and , the size of  and the common ratio.
The next line contains  space-seperated integers .

Constraints

Sample Input 0

4 2
1 2 2 4
Sample Output 0

2
Explanation 0

There are  triplets in satisfying our criteria, whose indices are  and 

Sample Input 1

6 3
1 3 9 9 27 81
Sample Output 1

6
Explanation 1

The triplets satisfying are index , , , ,  and .

Sample Input 2

5 5
1 5 5 25 125
Sample Output 2

4



method-1
-----------

long countTriplets(vector<long> arr, long r) {


long count=0;
for(int i=0;i<arr.size()-2;i++)
{
    for(int j=i+1;j<arr.size()-1;j++){
        
        for(int k=j+1;k<arr.size();k++)
        {
            if(arr[j]==arr[i]*r)
             if(arr[k]==arr[j]*r)
             count++;
            
        }
    }
    
}
return count;

}






-----------------------
method-2

---------------
long countTriplets(vector<long> arr, long r) {


long count=0;
unordered_map<long,long> right,left;


for(int i=0;i<arr.size();i++)
right[arr[i]]++;

for(int i=0;i<arr.size();i++)
{
    long mid=arr[i];
     right[mid]--;
    if(mid%r==0){
        
       
        long c1=0,c2=0;
        
        if(left.find(mid/r)!=left.end())
        c1=left[mid/r];
        
        if(right.find(mid*r)!=right.end())
        c2=right[mid*r];
        
        count+=c1*c2;
             
    }
    
    left[mid]++;
    
}




return count;

}
