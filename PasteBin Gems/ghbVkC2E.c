#include<cstdio>
#include<cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
int main(){
   double x,y;
   cin>>x>>y;
   int n;
   cin>>n;
   vector<pair<pair<double,double>,double>> bord;
   for(int i=0;i<n;i++){
      double l,r;
      double val;
      cin>>l>>r>>val;
      bord.push_back(make_pair(make_pair(l,r),val));
   }
   sort(bord.begin(),bord.begin()+bord.size());
   double count=0;
   for(int i=0;i<bord.size();i++){
      if(!i){
         count+=bord[i].first.first+(bord[i].first.second-bord[i].first.first)*bord[i].second;
         continue;
      }
      count+=bord[i].first.first-bord[i-1].first.second+(bord[i].first.second-bord[i].first.first)*bord[i].second;
   }
   count+=y-bord[bord.size()-1].first.second;
   cout<<fixed<<setprecision(10)<<(double)x/(double)count<<endl;
   return 0;
}