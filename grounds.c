#include<stdio.h>
struct Grounds
{
	char Ground_Name[50];
	char City[50];
	char State[50];
	struct Games games[10];
	struct Sports sports[10];
	
};
struct Games
{
	char name[50];
	int hourly_rate;
	struct Date date;
	int time[24]; 

};
struct Sports
{
	char name[50];
	struct Date date;

};
struct Date
{
	int day;
	int month;
	int year;
};
void InitialDB(struct Grounds grounds[], int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		grounds[i].Ground_Name='\0';
		grounds[i].City='\0';
		grounds[i].State='\0';
		for(int j=0;j<10;j++)
		{grounds[i].games[j]='\0';}
		


	}
}