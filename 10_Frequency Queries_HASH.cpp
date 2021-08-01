You are given  queries. Each query is of the form two integers described below:
-  : Insert x in your data structure.
-  : Delete one occurence of y from your data structure, if present.
-  : Check if any integer is present whose frequency is exactly . If yes, print 1 else 0.

The queries are given in the form of a 2-D array  of size  where  contains the operation, and  contains the data element.

Example

The results of each operation are:

Operation   Array   Output
(1,1)       [1]
(2,2)       [1]
(3,2)                   0
(1,1)       [1,1]
(1,1)       [1,1,1]
(2,1)       [1,1]
(3,2)                   1
Return an array with the output: .

Function Description

Complete the freqQuery function in the editor below.

freqQuery has the following parameter(s):

int queries[q][2]: a 2-d array of integers
Returns
- int[]: the results of queries of type 

Input Format

The first line contains of an integer , the number of queries.
Each of the next  lines contains two space-separated integers,  and .

Constraints

All 
Sample Input 0

8
1 5
1 6
3 2
1 10
1 10
1 6
2 5
3 2
Sample Output 0

0
1
Explanation 0

For the first query of type , there is no integer whose frequency is  (). So answer is .
For the second query of type , there are two integers in  whose frequency is  (integers =  and ). So, the answer is .

Sample Input 1

4
3 4
2 1003
1 16
3 1
Sample Output 1

0
1
Explanation 1

For the first query of type , there is no integer of frequency . The answer is . For the second query of type , there is one integer,  of frequency  so the answer is .

Sample Input 2

10
1 3
2 3
3 2
1 4
1 5
1 5
1 4
3 2
2 4
3 2
Sample Output 2

0
1
1
Explanation 2

When the first output query is run, the array is empty. We insert two 's and two 's before the second output query,  so there are two instances of elements occurring twice. We delete a  and run the same query. Now only the instances of  satisfy the query.



METHOD-1
---------------

unordered_map<int,int> mp;
vector<int> v;
for(int i=0;i<queries.size();i++)
{
    if(queries[i][0]==1)
    mp[queries[i][1]]++;
    
    else if(queries[i][0]==2){
        if(mp[queries[i][1]]>1)
         mp[queries[i][1]]--;
         else
         mp.erase(queries[i][1]);
        
    }
   
    
    else if(queries[i][0]==3)
    {
        int f=0;
      for(auto a:mp){
          
          if(a.second==queries[i][1]){
          v.push_back(1);
          f=1;
          break;
        }  
      }
     if(f==0)
     v.push_back(0);   
    }
}
return v;

}

-----------------------------

METHOD-2

USING TWO HASHMAP ,ONE FOR FREQUENCY ANOTHER ONE FOR FREQUENCY OF FREQUENCY



vector<int> freqQuery(vector<vector<int>> queries) {

unordered_map<int,int> mp1,mp2;
vector<int> v;
for(int i=0;i<queries.size();i++)
{
    if(queries[i][0]==1){
        
    int k=mp1[queries[i][1]];
    if(k>0)
    mp2[k]--;
    mp1[queries[i][1]]++;
    mp2[k+1]++;    
    
    
    }else if(queries[i][0]==2){
        int k=mp1[queries[i][1]];
       if(k>0){
        mp2[k]--;
        if(k-1>0)
        mp2[k-1]++;
        
        mp1[queries[i][1]]--;
        
       }
   
    } 
    else 
    {
       if(mp2[queries[i][1]]>0)
       v.push_back(1);
       else
         v.push_back(0);   
    }
}
return v;

}
