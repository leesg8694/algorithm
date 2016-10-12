#include<iostream>
using namespace std;

int n;
bool areFriends[10][10];

int countParings(bool taken[10]);

int main()
{
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			areFriends[i][j]=false;
		}
	}

	int c;
	cout<<"insert the number of test cases (c)"<<endl;
	cout<<"(1<=c && c<51)"<<endl;
	cin>>c;
	if(c<1 || 50<c)
	{
		cout<<"you put the wrong numebr"<<endl;
		return 0;
	}

	for(int it=0; it<c; it++)
	{
		int m;
		cout<<"insert n (the numebr of students) and m (the number of student couples)"<<endl;
		cout<<"n ( 2<=n && n<11 ), m( 0<=m && m<(n(n-1)/2)+1 )"<<endl;
		cin>>n>>m;

		if(2<=n && n<11) {;}
		else
		{
			cout<<"you put the wrong number for n"<<endl;
			return 0;
		}

		if(0<=m && m<(n*(n-1)/2)+1){;}
		else
		{
			cout<<"you put the wrong number for m"<<endl;
			return 0;
		}

		cout<<"put m student couples, each numbers are integer and must be lower than n"<<endl;
		int* stuPair=new int[2*m];

		for(int i=0; i<2*m; i++)
		{
			stuPair[i]=0;
		}

		for(int i=0; i<2*m; i++)
		{
			cin>>stuPair[i];
			if(0<=stuPair[i] && stuPair[i]<n){;}
			else
			{
				cout<<"you put the wrong number for element of stuPair"<<endl;
				return 0;
			}
		}
		cout<<"----------------------"<<endl;

		for(int i=0; i<2*m; i+=2)
		{
			areFriends[stuPair[i]][stuPair[i+1]]=true;
		}

		for(int i=0; i<10; i++)
		{
			for(int j=0; j<i; j++)
			{
				if( areFriends[i][j] == true)
				{
					areFriends[j][i]=areFriends[i][j];
					areFriends[i][j]=false;
				}
			}
		}

		bool taken[10];
		for(int i=0; i<10; i++)
		{
			taken[i]=true;
		}
		for(int i=0; i<2*m; i++)
		{
			taken[stuPair[i]]=false;
		}
		
		cout<<countParings(taken)<<endl;

		delete[] stuPair;
		stuPair=NULL;
	}
	return 0;
}

int countParings(bool taken[])
{
	int firstFree=-1;

	for(int i=0; i<n; i++)
	{
		if(!taken[i])
		{
			firstFree=i;
			break;
		}
	}

	if(firstFree==-1)
		return 1;

	int ret=0;

	for( int pairWith=firstFree+1; pairWith<n; pairWith++)
	{
		if(!taken[pairWith] && areFriends[firstFree][pairWith])
		{
			taken[firstFree]=taken[pairWith]=true;
			ret += countParings(taken);
			taken[firstFree]=taken[pairWith]=false;
		}
	}

	return ret;
}
