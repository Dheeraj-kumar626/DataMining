#include<bits/stdc++.h>
using namespace std;
#define f first 
#define s second 
	pair<int,int>low=make_pair(50,69);pair<int,int>mid=make_pair(63,85);pair<int,int>high=make_pair(78,100); int mid_p=73;
	float ps=10;
float low_width(){
	
	return(((low.second-low.first)+1)/ps);
}
float slope(int a,int b,float p){
	float ans=(float)((abs(b-a))+1)/p;
	cout<<" Slope in Function is "<<ans<<"\n";
	return ans;
}
int main(){
	ifstream fin("qtran1.txt");
	ofstream fout("qfuzz.txt",ios::trunc);
//	pair<int,int>low=make_pair(50,69);pair<int,int>mid=make_pair(63,85);pair<int,int>high=make_pair(78,100);
	string s1;	int x;char ch;int tid;	int iid;float a1=0,b1=0,c1=0; 	
	while(getline(fin,s1)){
		stringstream ss(s1);
		ss>>tid>>ch;
		fout<<tid<<ch<<"     "; 
		cout<<" Tid is "<<tid<<"\n";
		while(ss>>iid>>ch>>x){
			cout<<" Item No ,quant are "<<iid<<" "<<x<<"   ";
			float k,k1;
			
			if(low.f<=x&& x<=low.s){
				cout<<" slope in Low is  "<<slope(low.f,low.s,ps)<<"  ";
				k1=(((x-low.f)+2)/slope(low.f,low.s,ps))*(1/ps);
				k=1-k1;
				a1=k;
				if(a1<0){
					a1=0;
				}
				if(a1>1){
					a1=1;
				}
			}
			if(mid.f<=x && x<=mid_p){
				cout<<" slope in mid 1 is "<<slope(mid.f,mid_p,ps)<<"  ";
				k1=((x+2-mid.f)/slope(mid.f,mid_p,ps))*(1/ps);
				b1=k1;
			}
			if(mid_p<x && x<=mid.s){
				cout<<" slope in mid 2 is "<<slope(mid_p+1,mid.second,ps)<<"  ";
				k1=((x+2-(mid_p+1))/slope(mid_p+1,mid.second,ps))*(1/ps);
				b1=k1;
			}
			if(b1<0){
				b1=0;
			}
			if(b1>1){
				b1=1;
			}
			if(high.first<=x && x<=high.second){
				k1=(((x-high.f)+2)/slope(high.f,high.s,ps))*(1/ps);
				cout<<" k1 in high is "<<k1<<"\n";
				k=1-k1;
				c1=k;
				if(c1<0){
					c1=0;
				}
				if(c1>1){
					c1=1;
				}
				cout<<" c1 in high is "<<c1<<"\n";
			}
			
			cout<<" a1,b1,c1 are "<<fixed<< setprecision(1)<<a1<<" "<<b1<<" "<<c1<<"\n";
			fout<<fixed<< setprecision(1)<< a1<<" "<<b1<<" "<<c1<<" |";
			a1=b1=c1=0;
		}
		fout<<"\n";
	}
	return 0;
}


