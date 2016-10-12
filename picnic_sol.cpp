#include<iostream>
using namespace std;

int n;
bool areFriends[10][10];
//taken[i]=i번째 학생이 짝을 이미 찾앗으면 true,아니면 false

int countParingsFail(bool taken[10]);
int countParings(bool taken[10]);

int main()
{
	return 0;
}


int countParingsFail(bool taken[10])
{//한 경우를 중복으로 세는 잘못된 함수
	/*-----기저사례;모든학생이 짝을 찾았으면
		한 가지 방법을 찾았으니 종료----------*/
	bool finished=true;

	for(int i=0; i<n; i++)
	{
		if(!taken[i])
		{
			finished=false;
		}
	}

	if(finished)
		return 1;
	//---------------------------------------------
	/*-----서로 친구인 두 학생을 찾아 짝을 지어준다-----*/
	int ret=0;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(!taken[i] && !taken[j] && areFriends[i][j])
			{
				taken[i]=taken[j]=true;
				ret += countParings(taken);
				taken[i]=taken[j]=false;
				
			}
		}
	}
	//------------------------------------------------------
	return ret;
}

int countParings(bool taken[10])
{
	/*-----남은 학생들 중 가장 번호가 빠른 학생을 찾는다-----*/
	int firstFree=-1;

	for(int i=0; i<n; i++)
	{
		if(!taken[i])
		{
			firstFree=i;
			break;
		}
	}
	//-------------------------------------------------------
	/*-----기저사례 : 모든 학생이 짝을 찾았으면
		한 가지 방법을 찾앗으니 종료 ----*/
	if(firstFree==-1)
		return 1;
	//----------------------------------------
	/*-----이 학생과 짝지을 학생을 결정한다-----*/
	int ret=0;

	for(int pairWith = firstFree+1; pairWith<n;pairWith++)
	{
		if(!taken[pairWith] && areFriends[firstFree][pairWith])
		{
			taken[firstFree]=taken[pairWith]=true;
			ret+=countParings(taken);
			taken[firstFree]=taken[pairWith]=false;
		}
	}
	//--------------------------------------------

	return ret;
}
