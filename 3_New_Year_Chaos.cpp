It is New Year's Day and people are in line for the Wonderland rollercoaster ride. Each person wears a sticker indicating their initial position in the queue from  to . Any person can bribe the person directly in front of them to swap positions, but they still wear their original sticker. One person can bribe at most two others.

Determine the minimum number of bribes that took place to get to a given queue order. Print the number of bribes, or, if anyone has bribed more than two people, print Too chaotic.

Example


If person  bribes person , the queue will look like this: . Only  bribe is required. Print 1.


Person  had to bribe  people to get to the current position. Print Too chaotic.

Function Description

Complete the function minimumBribes in the editor below.

minimumBribes has the following parameter(s):

int q[n]: the positions of the people after all bribes
Returns

No value is returned. Print the minimum number of bribes necessary or Too chaotic if someone has bribed more than  people.
Input Format

The first line contains an integer , the number of test cases.

Each of the next  pairs of lines are as follows:
- The first line contains an integer , the number of people in the queue
- The second line has  space-separated integers describing the final state of the queue.

Constraints

Subtasks

For  score 
For  score 

Sample Input

STDIN       Function
-----       --------
2           t = 2
5           n = 5
2 1 5 3 4   q = [2, 1, 5, 3, 4]
5           n = 5
2 5 1 3 4   q = [2, 5, 1, 3, 4]
Sample Output

3
Too chaotic


QUESTION
1)print too chaotic if any one member bribed more than 2 times
2)else print the total no.of bribes done by all the members.




--------------------------------
void minimumBribes(vector<int> q) {
int fi=1;
int sec=2;
int thi=3,ans=0;
for(int i=0;i<q.size();i++)
{
    if(q[i]==fi)
    {
        fi=sec;
        sec=thi;
        thi++;
    }
    else if(q[i]==sec)
    {
        ans++;
        sec=thi;
        thi++;
    }else if (q[i]==thi)
    {
        ans+=2;
        thi++;
    }else{
        cout<<"Too chaotic"<<"\n";
        return;
    }
}
cout<<ans<<"\n";
}
