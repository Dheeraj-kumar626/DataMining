#include<bits/stdc++.h>
using namespace std;
#define f first 
#define s second 
int main(){
	float d[5][3];
	for(int i=0;i<5;i++){
		for(int j=0;j<3;j++){
			d[i][j]=0;
		}
	}
	int minsup=2;
	ifstream fin("qfuzz.txt");
	ofstream fout("L1fuzz.txt",ios::trunc);
	string s1;int num;char x;float a1,b1,c1;int c=0;
	
	while(getline(fin,s1)){
		stringstream ss(s1);
		ss>>num>>x; c=0;
		while(ss>>a1>>b1>>c1>>x){
			d[c][0]+=a1;
			d[c][1]+=b1;
			d[c][2]+=c1;
			c++;
		}
	}
	
	for(int i=0;i<5;i++){
		for(int j=0;j<3;j++){
			cout<<d[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	for(int i=0;i<5;i++){
		pair<int,int>p;int mid;
		float m1=max(d[i][0],max(d[i][1],d[i][2]));
		for(int j=0;j<3;j++){
			if(m1==d[i][j]){
				mid=j;
			}
		}
		if(m1>minsup){
			fout<<i<<","<<mid<<"|"<<"   "<<100<<","<<d[i][mid]<<","<<"\n";
			cout<<i<<","<<mid<<"   "<<d[i][mid]<<"\n";
		}
	}
	return 0;
}
