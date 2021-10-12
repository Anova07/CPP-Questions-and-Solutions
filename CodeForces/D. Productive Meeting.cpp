/*
D. Productive Meeting
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
An important meeting is to be held and there are exactly n people invited. At any moment, any two people can step back and talk in private. The same two people can talk several (as many as they want) times per meeting.

Each person has limited sociability. The sociability of the i-th person is a non-negative integer ai. This means that after exactly ai talks this person leaves the meeting (and does not talk to anyone else anymore). If ai=0, the i-th person leaves the meeting immediately after it starts.

A meeting is considered most productive if the maximum possible number of talks took place during it.

You are given an array of sociability a, determine which people should talk to each other so that the total number of talks is as large as possible.

Input
The first line contains an integer t (1≤t≤1000) — the number of test cases.

The next 2t lines contain descriptions of the test cases.

The first line of each test case description contains an integer n (2≤n≤2⋅105) —the number of people in the meeting. The second line consists of n space-separated integers a1,a2,…,an (0≤ai≤2⋅105) — the sociability parameters of all people.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105. It is also guaranteed that the sum of all ai (over all test cases and all i) does not exceed 2⋅105.

Output
Print t answers to all test cases.

On the first line of each answer print the number k — the maximum number of talks possible in a meeting.

On each of the next k lines print two integers i and j (1≤i,j≤n and i≠j) — the numbers of people who will have another talk.

If there are several possible answers, you may print any of them.


*/


#include<bits/stdc++.h>
#define ll   long long
#define  el           "\n"
#define  mod  1000000007
#define md 200001

using namespace std;


int main() {
        ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
      //  freopen("input.txt","r",stdin);
       //  freopen("output.txt","w",stdout);

int t=1;
cin>>t;
while(t--){

  int n;
  cin>>n;
  int a[n];
   set<pair<int,int>>s;
   for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>0)
        s.insert({-a[i],i+1}); // inserting all elememnts in decreasing order by taking -ve sign with their indices
   }

   vector<pair<int,int>>v;

   while(s.size()>1){

    auto it=*s.begin(); //  we picked maximum elements because we need maximum no of talks so every time we picked two maximum element 
    s.erase(it);
    auto it1=*s.begin();
    s.erase(it1);

    v.push_back({it.second,it1.second});  // Always picking  two maximum element insert their indices in the vector in vector
    it.first++;                         //  decrease the value of element by 1 and reinsert in the set till their value >0 
    it1.first++;
        if(it.first<0)   
    s.insert({it.first,it.second});
     if(it1.first<0)
    s.insert({it1.first,it1.second});


   }
   cout<<v.size()<<el;        //printing maximum no of talks
   for(auto x:v)           //printing person who talks with each other every time
    cout<<x.first<<" "<<x.second<<el;



    }


    return 0;}
