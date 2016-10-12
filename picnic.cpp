//picnic.cpp
#include<iostream>
using namespace std;

int countParings(int n, bool** student);
void setMat(int stuPair[], int size_stuPair, bool** mat, bool val);
void setMatAll(int x, int y, bool** mat, bool val);
void printMat(int x_p, int y_p, bool** mat);
void set_mat_sym(int size, bool** mat);
bool isMatEmpty(int n, bool** student);

int main()
{
	int c;
	cout<<"insert the number of test case"<<endl;
	cout<<"(lower than 51 && higher than 0)"<<endl;
	cin>>c;
	if(c>51 || c<1)
	{
		cout<<"you put the wrong number"<<endl;
		return 0;
	}

	for(int it=0; it<c; it++)
	{
		int n,m;
		cout<<"insert n (the number of students) and m (the number of student couples)"<<endl;
		cout<<"       n (higher than 1 && less than 11)  m (higher than -1 && euqal lower than (n(n-1))/2"<<endl;
		cin>>n>>m;
		if(1<n && n<11)	{;}
		else
		{
			cout<<"you put the wrong number for m"<<endl;
			return 0;
		}
		if(-1<m && m<=(n*(n-1))/2){;}
		else
		{
			cout<<"you put the wrong number for m"<<endl;
			return 0;
		}
	
		cout<<"put m student couples , each numbers are integer and must be lower than n"<<endl;
		bool** student = new bool*[n];
		for(int i=0; i<n; i++)
			student[i]=new bool[n];
		int* stuPair=new int[2*m];

		for(int i=0; i<2*m; i++)
		{
			cin>>stuPair[i];
			if(-1<stuPair[i] && stuPair[i]<n){;}
			else
			{
				cout<<"you put the wrong number for element of stuPair"<<endl;
				return 0;
			}
		}
		cout<<"----------------------------"<<endl;

		setMatAll(n,n,student,false);
		setMat(stuPair,2*m, student, true);
		set_mat_sym(n, student);
//		printMat(n,n,student);
		int a=countParings(n,student);
		cout<<"count is :"<<a<<endl;

		for(int i=0; i<n; i++)
			delete[] student[i];
		delete[] student;
		delete[] stuPair;
	}

	return 0;
}

void printMat(int x_p, int y_p, bool** mat)
{
	cout<<"------------------------------"<<endl;
	for(int x_l=0; x_l<x_p; x_l++)
	{
		for(int y_l=0; y_l<y_p; y_l++)
		{
			if(mat[x_l][y_l]==true)
				cout<<"1 ";
			else
				cout<<"0 ";
		}
		cout<<endl;
	}
	cout<<"------------------------------"<<endl;
}

void setMatAll(int x_p, int y_p, bool** mat, bool val)
{
	for(int x_l=0; x_l<x_p; x_l++)
		for(int y_l=0; y_l<y_p; y_l++)
			mat[x_l][y_l]=val;
}

void setMat(int stuPair[], int len_stuPair, bool** mat, bool val)
{
	for(int it=0; it<len_stuPair; it+=2)
	{
		mat[stuPair[it+1]][stuPair[it]]=val;
	}
}

int count=0;

/*void count_sub(int n, bool** student)
{
	if(!isMatEmpty(n,student))
	{
	}
	else
	{
	}
}*/

int countParings(int n,bool** student)
{
	printMat(n,n,student);
	if(!isMatEmpty(n,student))
	{
		cout<<"mat not empty"<<endl;
		for(int y_l=0; y_l<n; y_l++)
		{
			for(int x_l=0; x_l<n; x_l++)
			{
				if(student[y_l][x_l]==true)
				{
					bool** new_mat = new bool*[n];
            				for(int k=0; k<n; k++)
						 new_mat[k]=new bool[n];
					//----------------------------------------
					for(int x_new=0; x_new<n; x_new++)
					{
						for(int y_new=0; y_new<n; y_new++)
						{
							new_mat[y_new][x_new]=student[y_new][x_new];
						}
					}
					for(int i=0; i<n; i++)
					{
						new_mat[y_l][i]=false;
						new_mat[x_l][i]=false;
						new_mat[i][y_l]=false;
						new_mat[i][x_l]=false;
					}
					countParings(n,new_mat);
					//--------------------------------------
					for(int k=0; k<n; k++)
					{
						delete[] new_mat[k];
						new_mat[k]==NULL;
					}
					delete[] new_mat;
					new_mat=NULL;
				}
			}
		}
	}
	else
	{
		cout<<"mat emtpy"<<endl;
		count++;
	}
	return count;
}

bool isMatEmpty(int n, bool** student)
{
	bool check=false;
	for(int y=0; y<n; y++)
	{
		for(int x=0; x<n; x++)
		{
			check=(student[y][x] || check);
		}
	}

	if(check)
		return false;
	else
		return true;
}

void set_mat_sym(int size, bool** mat)
{
	for(int i=0; i<size; i++)
		for(int j=0; j<i; j++)
		{
			if(mat[i][j]==true)
			{
				mat[j][i]=mat[i][j];
				mat[i][j]=false;
			}
		}
}
