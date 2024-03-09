
 /*--- keep ptrack of previous the Index(TargetSum-curNum) ----------*/  

  //  explanation 
 
 /* as we cant use the map to store the index of the current element , while travering the nums array //
   we can use the array of long limit , to store the index of current element , as the strArray 
   similtanously ,find the TargetSum-currNum(i), if is found in the strArray, we simple get the diff,
   and campare with minDis,
   if found less, then it may be answer , str it in resPair ...
*/


#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    int targetSum;
    cin>>targetSum;
   
    // act as the map , and the idx of the corresponding num //
    int strArryIndex[100000];

    for(int i=0;i<100000;++i)
    {
        strArryIndex[i]=-1;
    }

   // input the nums array //

    int sz;
    cin>>sz;

    int nums[sz];
    
    for(int i=0;i<sz;++i)
    {
        cin>>nums[i];
    }

   // store the res array //

    int resPair[2];

    resPair[0]=-1;
    resPair[1]=-1;
     
     int minDis=sz;  
                 // ( intial maximum indexs difference distances)

   for(int i=0;i<sz;++i)
   {  
      if(strArryIndex[targetSum-nums[i]]!=-1)
      {
        int curDis=i-strArryIndex[targetSum-nums[i]]-1;
        if(curDis < minDis )
        {
            minDis=curDis;
            resPair[0]=nums[strArryIndex[targetSum-nums[i]]];
            resPair[1]=nums[i];
        }

      }
      strArryIndex[nums[i]]=i;

   }

      
      cout<<resPair[0]<<" "<<resPair[1]<<"\n";


  return 0;
}