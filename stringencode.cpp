#include"bits/stdc++.h"

/*GS coderpad questions*

AAA=> A*A 
AAAA=> AA*=> A*
ABCABCABCABCA => ABCABC*A=>ABC**A
*/

using namespace std;

int findEncodedString(string thisString)
{
    if(thisString.size()<=1){return thisString.size();} //boundary case

    int maxlen = thisString.size()/2;

    while(maxlen)
    {
      if(thisString.substr(0,maxlen)==thisString.substr(maxlen,maxlen))
      {
        return findEncodedString(thisString.substr(0,maxlen))+1+thisString.size()-2*maxlen;
      }
      maxlen--;
    }
    return thisString.size();    
}


int main()
{
 string temp;
 while(cin>>temp)
 cout<<findEncodedString(temp)<<endl;

}