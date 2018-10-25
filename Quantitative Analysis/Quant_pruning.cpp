#include<bits/stdc++.h>
using namespace std;
#define f first 
#define s second 
float searchtransaction(vector<pair<float,float> >item){

	int n;string str3;float d[5][3];
	int num;char ch;int num1;
	ifstream fin("qfuzz.txt");
	n = item.size();
	float count = 1000;bool flag; char x;float a1,b1,c1;int c=0; float ans=0;
	while(getline(fin,str3))
	{
		stringstream ss2(str3);
		ss2>>num>>x; c=0;
		while(ss2>>a1>>b1>>c1>>x){
			d[c][0]=a1;
			d[c][1]=b1;
			d[c][2]=c1;
			c++;
		}
		
		flag = true;
		for(int i=0;i<n;i++)
		{
			int ind1=item[i].f;
			int ind2=item[i].s;
			count=min(count,d[ind1][ind2]);
		}
		ans+=count;
		count=1000;
		cout<<" ans is "<<ans;
		ss2.clear();
	}
	fin.close();
	return ans;
}
int main(){
	int minsup;
	cout<<"enter min support:"<<endl;
	cin>>minsup;
	int k=2;
//	while(1)
//	{
		char ch[2];ch[0] = char('0'+k);ch[1]='\0';
		char str[20]="c";strcat(str,ch);strcat(str,"fuzz.txt");
		cout<<str<<endl;
 		ofstream fout(str,ios::trunc);	
 		ch[0]= char('0'+k-1);
		char pstr[20]="L";strcat(pstr,ch);strcat(pstr,"fuzz.txt");
		cout<<pstr<<endl;

		ifstream fin(pstr);ifstream fin1(pstr);
		float x,y;int c; char ch1,ch2;float p;
		vector<pair<float,float> > v1,v2;
		string s,s1;
		while(getline(fin,s))
		{
			stringstream ss(s);
			cout<<s<<endl;
			while(ss>>x>>ch1>>p>>ch2){
				v1.push_back(make_pair(x,p));
			}
			v1.pop_back();
			cout<<"k is:"<<k<<endl;
			cout<<" v1 is \n";
			for(int i=0;i<v1.size();i++){
				cout<<"("<<v1[i].f<<","<<v1[i].s<<")"<<"  ";
			}
			cout<<"\n";
			ifstream fin1(pstr);
		//	cout<<" yooooo\n";
			while(getline(fin1,s1))
			{
			//	cout<<" ttttttttttttttttttt\n";
				stringstream ss1(s1);
				while(ss1>>y>>ch1>>p>>ch2){
				//	cout<<" (y,p) are "<<y<<","<<p<<"\n";
				v2.push_back(make_pair(y,p));
				}
				v2.pop_back();
				cout<<"k is:"<<k<<endl;
				cout<<" v2 is \n";
				for(int i=0;i<v2.size();i++){
					cout<<"("<<v2[i].f<<","<<v2[i].s<<")"<<"  ";
				}
				cout<<"\n";
				bool flag = true;
				
				for(int i1=0;i1<k-2;i1++)
				{
					if(v1[i1]!=v2[i1])
					{
						flag = false;break;	
					}
				}
				if(flag)
				{
					vector<pair<float,float> > temp;
					cout<<"entered into flg "<<endl;
					if(v1[k-2]<v2[k-2])
					{
						for(int i2=0;i2<k-2;i2++)temp.push_back(v1[i2]);
						temp.push_back(v1[k-2]);temp.push_back(v2[k-2]);
						cout<<" Combined Temp is \n";
						for(int i3=0;i3<temp.size();i3++){
							cout<<"("<<temp[i3].f<<","<<temp[i3].s<<")"<<"  ";
						}
						cout<<"\n";
						float pk = searchtransaction(temp);
						cout<<" combined Temp value is "<<pk<<"\n";
			//			if(pk>=minsup)
			//			{
							cout<<" combination is \n";
						for(int i3=0;i3<k-2;i3++){
							fout<<v1[i3].f<<","<<v1[i3].s<<"|";
							cout<<v1[i3].f<<","<<v1[i3].s<<"|";
						}
						fout<<v1[k-2].f<<","<<v1[k-2].s<<"|";
						fout<<v2[k-2].f<<","<<v2[k-2].s<<"|"<<"    ";
						fout<<100<<","<<pk<<",\n";
						
						cout<<v1[k-2].f<<","<<v1[k-2].s<<"|";
						cout<<v2[k-2].f<<","<<v2[k-2].s<<"|"<<"    ";
						cout<<100<<","<<pk<<",\n";
			//			}
						temp.clear();
					}
				}
			ss1.clear();
			v2.clear();
		 }
			fin1.close();
			v1.clear();
			ss.clear();
	   }
	   
		fin.close();
		fout.close();
		
		ch[0]= char('0'+k);
		char ostr[20]="L";strcat(ostr,ch);strcat(ostr,"fuzz.txt");
		ifstream ifs(str);
		ofstream ofs(ostr,ios::trunc);
		string temp;
		bool flaggy = true;
		while(getline(ifs,temp))
		{
			int id;
			stringstream ss4(temp);
		//	cout<<"in l2"<<endl;
		//	cout<<temp<<endl;
			while(ss4>>x>>ch1>>p>>ch2){
		//		cout<<p<<":==:";
			}
			if(p>=minsup)    //min support
			{
				flaggy = false;
				ofs<<temp<<endl;
			}
			ss4.clear();
		}

}
