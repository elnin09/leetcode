#include "bits/stdc++.h"
#include "maximumgold.cpp"
#include "tree.cpp"
#include "majorityelement.cpp"
#include "movezeros.cpp"
#include "finddisappearednumbers.cpp"
using namespace std;


auto get2Dvector()
{
    vector<vector<int> > vin{{0,6,0},{5,8,7},{0,9,0}};
    return vin;
}
auto get1Dvector()
{
    vector<int> vin{1,2,3};
}


int main()
{
std::cout<<"just checking"<<endl;
auto vin = get2Dvector();
int rows = vin.size();
int columns = vin[0].size();


//cout<<getMaximumGold(vin)<<endl;


return 0;   
}