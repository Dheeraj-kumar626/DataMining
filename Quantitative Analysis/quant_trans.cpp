#include<bits/stdc++.h>
using namespace std;
int main(){
	srand(time(NULL));
	ofstream fout("qtran1.txt",ios::trunc);
	int tid=1;	map<int,int>mp;int iid,ic,count;
	int ct=9;   map<int,int>::iterator it;
	for(int i=0;i<ct;i++){
		mp.clear();
		fout<<i+1<<",      ";
	//	count=rand()%5+1;
		count=5;
		for(int j=0;j<count;){
			iid=rand()%5+1;
			ic=(rand()%100+1);
			if(ic<50){
				ic+=50;
			}
			if(mp.find(iid)==mp.end()){
				mp.insert(make_pair(iid,ic));
				j++;
				//fout<<iid<<","<<ic<<" ";
			}
		}
		for(it=mp.begin();it!=mp.end();it++){
			fout<<it->first<<","<<it->second<<" ";
		}
		fout<<"\n";
	}
	return 0;
}
