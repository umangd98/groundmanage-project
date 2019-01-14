#include<stdio.h>
#include<string.h>
int ngrounds=2;			//should be less than 10
struct Time
{
	int h;
};

struct Date
{
	int day;
	int month;
	int year;
	int ntime;
	struct Time stime[10];		//on a particular day, a particular sport can have 10 times in hours to start
	struct Time etime[10];		//on a particular day, a particular sport can have 10 times in hours to end
};	

struct Sports
{
	char name[50];
	int hourly_rate;
	struct Date date[10]; 
	int ndate;
};

struct Grounds
{
	char Ground_Name[50];
	char City[50];
	char State[50];
	int nhsports;					//nhsports --> number of sports it can hold 
	char sports_hold[10][50];
	int nsports;					//nsports should be less than 10 --> number of sports it's holding
	struct Sports sports[10];
	
}grounds[10];
void InitialDB(struct Grounds grounds[], int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		grounds[i].Ground_Name[0]='\0';
		grounds[i].City[0]='\0';
		grounds[i].State[0]='\0';
		grounds[i].nsports=0;
		grounds[i].nhsports=0;
		grounds[i].sports_hold[i][0]='\0';

		for(int j=0;j<10;j++)
		{
			grounds[i].sports[j].name[0] = '\0';
			grounds[i].sports[j].hourly_rate = 0;
			grounds[i].sports[j].ndate = 0;

			for(int k=0;k<10;k++)
			{
				grounds[i].sports[j].date[k].day = 0;
				grounds[i].sports[j].date[k].month = 0;
				grounds[i].sports[j].date[k].year = 0;
				grounds[i].sports[j].date[k].ntime = 0;

				for(int l=0;l<10;l++)
				{
					grounds[i].sports[j].date[k].stime[l].h=0;
					grounds[i].sports[j].date[k].etime[l].h=0;
				}
			}
			
		}		
	}
}
void getGroundInfo(char city[]){
	int count=0;char temp[50];
	char tempn[10][50];
	for(int i=0;i<ngrounds;i++){
		if(strcmp(city,grounds[i].City)==0)
		{	
			strcpy(tempn[count++],grounds[i].Ground_Name);
		}
	}
	for(int i=0;i<count-1;i++)		//sort of ground names
	{
		for(int j=i+1;j<count;j++)
		{
			if(strcmp(tempn[i],tempn[j])>0)
			{
				strcpy(temp,tempn[i]);	
				strcpy(tempn[i],tempn[j]);	
				strcpy(tempn[j],temp);
			}
			
		}
	}
	printf("The sorted order names in city %s is\n",city);
	for(int i=0;i<count;i++)
	{

		printf("%s\n",tempn[i]);
	}
}
void addSport(char city[], char ground_name[], struct Sports sport)
{	int i=0,flag = 0;
	for(i=0;i<ngrounds&&flag==0;i++)
	{
		if(strcmp(grounds[i].Ground_Name, ground_name)==0&&strcmp(grounds[i].City, city)==0&&flag==0)
		{	
			int j=0;
			for(int j=0;j<grounds[i].nhsports&&flag==0;j++)
			{	
				if(strcmp(grounds[i].sports_hold[j],sport.name)==0&&flag==0)
				{int count=0;
					for(int k=0;k<=grounds[i].nsports&&flag==0;k++)
					{	
						if(strcmp(grounds[i].sports[k].name, sport.name)==0&&flag==0)
						{
							for(int l=0;l<grounds[i].sports[k].ndate&&flag==0;l++)
							{
								int day = grounds[i].sports[k].date[l].day;
								int month = grounds[i].sports[k].date[l].month;
								int year = grounds[i].sports[k].date[l].year;
								if(day==sport.date[0].day&&month==sport.date[0].month&&year==sport.date[0].year&&flag==0)
								{
									for(int m=0; m<grounds[i].sports[k].date[l].ntime&&flag==0;m++)
									{		
										if(grounds[i].sports[k].date[l].stime[m].h<sport.date[0].etime[0].h&&grounds[i].sports[k].date[l].etime[m].h>sport.date[0].stime[0].h&&flag==0)
										{
												printf("FAILURE");

										}
										else 
										{
											strcpy(grounds[i].sports[k].name, sport.name);
											grounds[i].sports[k].hourly_rate = sport.hourly_rate;
											grounds[i].sports[k].date[l].day = sport.date[0].day;
											grounds[i].sports[k].date[l].month = sport.date[0].month;
											grounds[i].sports[k].date[l].year = sport.date[0].year;
											grounds[i].sports[k].date[l].stime[m].h = sport.date[0].stime[0].h;
											grounds[i].sports[k].date[l].etime[m].h = sport.date[0].etime[0].h;	
											printf("SUCCESS\n");
											flag=1;
											grounds[i].sports[k].date[l].ntime++;
											if(strcmp(grounds[i].sports[k].name,sport.name)!=0)
											{
												grounds[i].nsports++;
											}
										}
									}
								}
								else 
								{
									strcpy(grounds[i].sports[k].name, sport.name);
									grounds[i].sports[k].hourly_rate = sport.hourly_rate;
									grounds[i].sports[k].date[l].day = sport.date[0].day;
									grounds[i].sports[k].date[l].month = sport.date[0].month;
									grounds[i].sports[k].date[l].year = sport.date[0].year;
									grounds[i].sports[k].date[l].stime[0].h = sport.date[0].stime[0].h;
									grounds[i].sports[k].date[l].etime[0].h = sport.date[0].etime[0].h;
									printf("SUCCESS\n");
									flag=1;
									grounds[i].sports[k].ndate++;
									grounds[i].sports[k].date[l].ntime++;
									if(strcmp(grounds[i].sports[k].name,sport.name)!=0)
									{
										grounds[i].nsports++;
									}
								}
							}
						}
						else if(count==grounds[i].nsports&&flag==0)
						{
							strcpy(grounds[i].sports[count].name, sport.name);
							grounds[i].sports[count].hourly_rate = sport.hourly_rate;
							grounds[i].sports[count].date[0].day = sport.date[0].day;
							grounds[i].sports[count].date[0].month = sport.date[0].month;
							grounds[i].sports[count].date[0].year = sport.date[0].year;
							grounds[i].sports[count].date[0].stime[0].h = sport.date[0].stime[0].h;
							grounds[i].sports[count].date[0].etime[0].h = sport.date[0].etime[0].h;
							printf("SUCCESS\n");
							flag=1;
							grounds[i].sports[count].ndate++;
							grounds[i].sports[count].date[0].ntime++;
							grounds[i].nsports++;
						}
						else
						{	count++;
							for(int l=0;l<grounds[i].sports[k].ndate&&flag==0;l++)
							{
								int day = grounds[i].sports[k].date[l].day;
								int month = grounds[i].sports[k].date[l].month;
								int year = grounds[i].sports[k].date[l].year;
								if(day==sport.date[0].day&&month==sport.date[0].month&&year==sport.date[0].year)
								{
									for(int m=0; m<grounds[i].sports[k].date[l].ntime&&flag==0;m++)
									{		
										if(grounds[i].sports[k].date[l].stime[m].h<=sport.date[0].etime[0].h&&grounds[i].sports[k].date[l].etime[m].h>=sport.date[0].stime[0].h)
										{
												printf("FAILURE");
												count=0;
										}
									}
								}
							}
						}
					}		
				}				
			}
			if(j>=grounds[i].nhsports&&flag==0)
			{
				printf("FAILURE");	
			}
		}
	}
	if(i>=ngrounds&&flag==0)
	{
		printf("FAILURE");
	}
}

void deleteSport(char city[], char ground_name[], struct Sports sport)		//Number of failures idicate the number of mistakes
{	int i=0,flag = 0;
	for(i=0;i<ngrounds&&flag==0;i++)
	{
		if(strcmp(grounds[i].Ground_Name,ground_name)==0&&strcmp(grounds[i].City,city)==0)
		{	
			int j=0;
			for(j=0;j<grounds[i].nsports&&flag==0;j++)
			{
				if(strcmp(sport.name,grounds[i].sports[j].name)==0)
				{	
					int k=0;
					for(k=0;k<grounds[i].sports[j].ndate&&flag==0;k++)
					{
						if(sport.date[0].day==grounds[i].sports[j].date[k].day&&sport.date[0].month==grounds[i].sports[j].date[k].month&&sport.date[0].year==grounds[i].sports[j].date[k].year)
						{
							int l=0;
							for(l=0;l<grounds[i].sports[j].date[k].ntime&&flag==0;l++)
							{
								if(grounds[i].sports[j].date[k].stime[l].h==sport.date[0].stime[0].h&&grounds[i].sports[j].date[k].etime[l].h==sport.date[0].etime[0].h)
								{
									// grounds[i].nsports--;
									grounds[i].sports[j].name[0]='\0';
									grounds[i].sports[j].hourly_rate=0;
									// grounds[i].sports[j].ndate--;
									grounds[i].sports[j].date[k].day=0;
									grounds[i].sports[j].date[k].month=0;
									grounds[i].sports[j].date[k].year=0;
									// grounds[i].sports[j].date[k].ntime--;
									grounds[i].sports[j].date[k].stime[l].h=0;
									grounds[i].sports[j].date[k].etime[l].h=0;
									flag=1;
									printf("SUCCESS\n");
								}
							}
							if(l>=grounds[i].sports[j].date[k].ntime&&flag==0)
							{
								printf("FAILURE\n");
							}
						}
					}
					if(k>=grounds[i].sports[j].ndate&&flag==0)
					{
						printf("FAILURE\n");
					}
					
				}
			}
			if(j>=grounds[i].nsports&&flag==0)
			{
				printf("FAILURE\n");
			}
		}
	}
	if(i>=ngrounds&&flag==0)
	{
		printf("FAILURE\n");
	}
}



void addGround(struct Grounds ground)
{	int flag=0;
	int temp;
	for(int i=0;i<10&&flag==0;i++)
	{	
		if(strcmp(grounds[i].Ground_Name,ground.Ground_Name)==0&&strcmp(grounds[i].City,ground.City)==0)
		{
			printf("Ground already Exist\n");
			printf("FAILURE\n");
			flag=1;
			temp=i;
		}
		else if(grounds[i].Ground_Name[0]=='\0'&&grounds[i].City[0]=='\0'&&grounds[i].State[0]=='\0')
		{	temp=i;
			flag =1;
			strcpy(grounds[i].Ground_Name,ground.Ground_Name);
			strcpy(grounds[i].City,ground.City);
			strcpy(grounds[i].State,ground.State);
			grounds[i].nhsports= ground.nhsports;
			grounds[i].nsports=0;
			for(int j=0;j<ground.nhsports;j++)
			{
				strcpy(grounds[i].sports_hold[j],ground.sports_hold[j]);
			}
			ngrounds+=1;
			printf("SUCCESS\n");
		}	
	}
	printf("Ground Name:%s\n",grounds[temp].Ground_Name);
	printf("City:%s\n",grounds[temp].City);
	printf("State%s\n",grounds[temp].State);
	printf("Number of Games it can Hold:%d\n",grounds[temp].nhsports);
	for(int k=0;k<grounds[temp].nhsports;k++)
	{
		printf("Game %d %s\n",k+1,grounds[temp].sports_hold[k]);
	}
	if(flag==0)
		printf("FAILURE\n");
}



void deleteGround(char ground_name[], char city[])
{
	int flag=0;
	for(int i=0;i<ngrounds&&flag==0;i++)
	{
		if(strcmp(grounds[i].Ground_Name,ground_name)==0&&strcmp(grounds[i].City,city)==0)
		{
			flag=1;
			printf("SUCCESS\n");
			grounds[i].Ground_Name[0]='\0';
			grounds[i].City[0]='\0';
			grounds[i].State[0]='\0';
			for(int j=0;j<grounds[i].nhsports;j++)
			{
				grounds[i].sports_hold[j][0]='\0';
			}
			grounds[i].nhsports=0;
			for(int j=0;j<grounds[i].nsports;j++)
			{
				grounds[i].sports[j].name[0]='\0';
				grounds[i].sports[j].hourly_rate=0;
				for(int k=0;k<grounds[i].sports[j].ndate;k++)
				{
					grounds[i].sports[j].date[k].day=0;
					grounds[i].sports[j].date[k].month=0;
					grounds[i].sports[j].date[k].year=0;
					for(int l=0;l<grounds[i].sports[j].date[k].ntime;l++)
					{
						grounds[i].sports[j].date[k].stime[l].h=0;
						grounds[i].sports[j].date[k].etime[l].h=0;
					}
					grounds[i].sports[j].date[k].ntime=0;
				}
				grounds[i].sports[j].ndate=0;
			}
			grounds[i].nsports=0;
		}	
	}

	if(flag==0)
		printf("FAILURE\n");
}


void updateGround(char  city[], char ground_name[], struct Grounds ground)
{
	int flag=0,temp;
	for(int i=0;i<ngrounds&&flag==0;i++)
	{
		if(strcmp(grounds[i].Ground_Name,ground.Ground_Name)==0&&strcmp(grounds[i].City,ground.City)==0)
		{
			flag=1;
			temp=i;
			printf("Ground already exist\n");
			printf("FAILURE\n");
		}
	}
	for(int i=0;i<ngrounds&&flag==0;i++)
	{
		if(strcmp(grounds[i].Ground_Name,ground_name)==0&&strcmp(grounds[i].City,city)==0)
		{	
			temp=i;
			flag =1;
			strcpy(grounds[i].Ground_Name,ground.Ground_Name);
			strcpy(grounds[i].City,ground.City);
			strcpy(grounds[i].State,ground.State);
			grounds[i].nhsports=ground.nhsports;
			int j=0;
			for(int j=0;j<grounds[i].nhsports;j++)
			{
				strcpy(grounds[i].sports_hold[j],ground.sports_hold[j]);
			}
			printf("SUCCESS\n");
		}
	}
	printf("Ground Name:%s\n",grounds[temp].Ground_Name);
	printf("City:%s\n",grounds[temp].City);
	printf("State:%s\n",grounds[temp].State);
	printf("Number of Games it can Hold:%d\n",grounds[temp].nhsports);
	for(int k=0;k<grounds[temp].nhsports;k++)
	{
		printf("Game %d %s\n",k+1,grounds[temp].sports_hold[k]);
	}
	if(flag==0)
		printf("FAILURE\n");
}


void getFixturesinCity(char city[], struct Date sdate , struct Date edate)	//sdate-->start date, edate-->end date
{
	char tempn[50][50], temps[50][50], temp[50];
	int count=0;
	for(int i=0;i<ngrounds;i++)
	{
		if(strcmp(grounds[i].City,city)==0)
		{	
			for(int j=0;j<grounds[i].nsports;j++)
			{	
				for(int k=0;k<grounds[i].sports[j].ndate;k++)
				{
					if(grounds[i].sports[j].date[k].year>sdate.year&&grounds[i].sports[j].date[k].year<edate.year)
					{
						strcpy(tempn[count],grounds[i].Ground_Name);
						strcpy(temps[count++],grounds[i].sports[j].name);
						
						
					}
					else if(grounds[i].sports[j].date[k].year==sdate.year||grounds[i].sports[j].date[k].year==edate.year)
					{
						if(grounds[i].sports[j].date[k].month>sdate.month&&grounds[i].sports[j].date[k].month<edate.month)
						{
							strcpy(tempn[count],grounds[i].Ground_Name);
							strcpy(temps[count++],grounds[i].sports[j].name);
							
						}
						else if(grounds[i].sports[j].date[k].month==sdate.month||grounds[i].sports[j].date[k].month==edate.month)
						{
							if(grounds[i].sports[j].date[k].day>=sdate.day&&grounds[i].sports[j].date[k].day<=edate.day)
							{
								strcpy(tempn[count],grounds[i].Ground_Name);
								strcpy(temps[count++],grounds[i].sports[j].name);
								
							}
						}
					}
				}
			}
		}
	}
	// for(int i=0;i<count;i++)
 //    {
 //    	printf("%s\t",temps[i]);
 //    	printf("%s\n",tempn[i] );
 //    }
	for (int i = 0; i < count - 1 ; i++)		// Bubble Sorting on ground name and sport name
        {
            for (int j = i + 1; j < count; j++)
            {
                if (strcmp(tempn[i], tempn[j]) > 0) 
                {
                    strcpy(temp, tempn[i]);
                    strcpy(tempn[i], tempn[j]);
                    strcpy(tempn[j], temp);

                    strcpy(temp, temps[i]);
                    strcpy(temps[i], temps[j]);
                   	strcpy(temps[j], temp);
                }
                else if(strcmp(tempn[i], tempn[j])==0)
                {
                	if (strcmp(temps[i], temps[j]) > 0) 
               		{
                    	strcpy(temp, temps[i]);
                    	strcpy(temps[i], temps[j]);
                    	strcpy(temps[j], temp);
                	}
                }
            }
        }
    
    if(count==0)
  	{
  		printf("NO GAMES IN BETWEEN THOSE DATES\n");
  	}
  	else
  	{	
  		printf("Sport Name\tGround Name\n");
  		for(int i=0;i<count;i++)
    	{
    		printf("%s",temps[i]);
    		printf("\t");
    		printf("%s\n",tempn[i]);
    	}
  	}
    

    
}

void getFixturesinState(char state[])
{	char city[50][50], ground[50][50], sport[50][50], temp[50];
	int c=0;
	for(int i=0;i<ngrounds;i++)
	{
		if(strcmp(grounds[i].State,state)==0)
		{
			for(int j=0;j<grounds[i].nsports;j++)
			{	
				if(grounds[i].sports[j].name[0]!='\0')
				{	
					strcpy(sport[c],grounds[i].sports[j].name);	
					strcpy(city[c],grounds[i].City);
					strcpy(ground[c++],grounds[i].Ground_Name);		
				}
			}

		}
	}
	for (int i = 0; i < c ; i++)		// Bubble Sorting 
        {
            for (int j = i + 1; j < c; j++)
            {
                if (strcmp(sport[i], sport[j]) > 0) 
                {
                    strcpy(temp, sport[i]);
                    strcpy(sport[i], sport[j]);
                    strcpy(sport[j], temp);

                   	strcpy(temp, ground[i]);
                   	strcpy(ground[i], ground[j]);
                   	strcpy(ground[j], temp);
                }
                else if(strcmp(sport[i], sport[j])==0)
                {
                	if (strcmp(ground[i], ground[j]) > 0) 
               		{
                    	strcpy(temp, ground[i]);
                    	strcpy(ground[i], ground[j]);
                    	strcpy(ground[j], temp);
                	}
                }
            }
        }
    if(c==0)
  	{
  		printf("NO GAMES IN  THE STATE: %s\n",state);
  	}
  	else
    {
    	printf("Sport Name\tGround Name\n");
	    for(int i=0;i<c;i++)
	    {
	    	printf("%s\t%s\n",sport[i],ground[i]);
	    }
	}
}


void getFixturesSortedonDate(struct Grounds grounds[])
{	
	struct sortdate
	{
		char name[50];
		int day;
		int month;
		int year;
		int stime;
		int etime;
	}record[20];
	int c=0;
	for(int i=0;i<ngrounds;i++)
	{
		for(int j=0;j<grounds[i].nsports;j++)
		{
			for(int k=0;k<grounds[i].sports[j].ndate;k++)
			{
				for(int l=0;l<grounds[i].sports[j].date[k].ntime;l++)
				{
					strcpy(record[c].name, grounds[i].Ground_Name);
					record[c].day=grounds[i].sports[j].date[k].day;
					record[c].month=grounds[i].sports[j].date[k].month;
					record[c].year=grounds[i].sports[j].date[k].year;
					record[c].stime=grounds[i].sports[j].date[k].stime[l].h;
					record[c++].etime=grounds[i].sports[j].date[k].etime[l].h;
				}
			}
		}
	}
	int temp;
	char tempc[50];
	for(int i=0;i<c-1;i++)
	{
		for(int j=i+1;j<c;j++)
		{
			if(record[i].year>record[j].year)
			{
					temp=record[i].year;
					record[i].year=record[j].year;
					record[j].year=temp;

					temp=record[i].month;
					record[i].month=record[j].month;
					record[j].month=temp;

					temp=record[i].day;
					record[i].day=record[j].day;
					record[j].day=temp;

					temp=record[i].stime;
					record[i].stime=record[j].stime;
					record[j].stime=temp;

					temp=record[i].etime;
					record[i].etime=record[j].etime;
					record[j].etime=temp;

					strcpy(tempc,record[i].name);
					strcpy(record[i].name,record[j].name);
					strcpy(record[j].name,tempc);
			}
			else if(record[i].year==record[j].year)
			{
				if(record[i].month>record[j].month)
				{
					temp=record[i].month;
					record[i].month=record[j].month;
					record[j].month=temp;

					temp=record[i].day;
					record[i].day=record[j].day;
					record[j].day=temp;

					temp=record[i].stime;
					record[i].stime=record[j].stime;
					record[j].stime=temp;

					temp=record[i].etime;
					record[i].etime=record[j].etime;
					record[j].etime=temp;

					strcpy(tempc,record[i].name);
					strcpy(record[i].name,record[j].name);
					strcpy(record[j].name,tempc);
				}

				else if(record[i].month==record[j].month)
				{
					if(record[i].day>record[j].day)
					{
						temp=record[i].day;
						record[i].day=record[j].day;
						record[j].day=temp;

						temp=record[i].stime;
						record[i].stime=record[j].stime;
						record[j].stime=temp;

						temp=record[i].etime;
						record[i].etime=record[j].etime;
						record[j].etime=temp;

						strcpy(tempc,record[i].name);
						strcpy(record[i].name,record[j].name);
						strcpy(record[j].name,tempc);
					}

					else if(record[i].day==record[j].day)
					{
						if(record[i].stime>record[j].stime)
						{
							temp=record[i].stime;
							record[i].stime=record[j].stime;
							record[j].stime=temp;

							temp=record[i].etime;
							record[i].etime=record[j].etime;
							record[j].etime=temp;


							strcpy(tempc,record[i].name);
							strcpy(record[i].name,record[j].name);
							strcpy(record[j].name,tempc);
						}

						else if(record[i].stime==record[j].stime)
						{
							if(strcmp(record[i].name,record[j].name)>0)
							{
								strcpy(tempc,record[i].name);
								strcpy(record[i].name,record[j].name);
								strcpy(record[j].name,tempc);
							}
						}
					}
				}
			}
		}
	}

	printf("The Sorted List is:\n");
	{
		for(int i=0;i<c;i++)
		{
			printf("%s\t",record[i].name);
			printf("%d  ",record[i].day );
			printf("%d  ",record[i].month );
			printf("%d  ",record[i].year );
			printf("%d  ",record[i].stime );
			printf("%d  ",record[i].etime );
			printf("\n");
		}
	}
}

void getFixturesSortedonState(struct Grounds grounds[])
{
	struct sortState
	{	char name[50];
		char City[50];
		char State[50];
		
	}record[20];	
	int c=0;
	for(int i=0;i<ngrounds;i++)
	{
		for(int j=0;j<grounds[i].nsports;j++)
		{
			for(int k=0;k<grounds[i].sports[j].ndate;k++)
			{
				for(int l=0;l<grounds[i].sports[j].date[k].ntime;l++)
				{
					strcpy(record[c].name, grounds[i].Ground_Name);
					strcpy(record[c].City, grounds[i].City);
					strcpy(record[c++].State, grounds[i].State);
				}
			}
		}
	}
	char tempc[50];
	for(int i=0;i<c-1;i++)
	{
		for(int j=i+1;j<c;j++)
		{
			if(strcmp(record[i].State,record[j].State)>0)
			{
				strcpy(tempc,record[i].State);
				strcpy(record[i].State,record[j].State);
				strcpy(record[j].State,tempc);

				strcpy(tempc,record[i].City);
				strcpy(record[i].City,record[j].City);
				strcpy(record[j].City,tempc);
		
				strcpy(tempc,record[i].name);
				strcpy(record[i].name,record[j].name);
				strcpy(record[j].name,tempc);
			}
			else if(strcmp(record[i].State,record[j].State)==0)
			{
				if(strcmp(record[i].City,record[j].City)>0)
				{
					strcpy(tempc,record[i].City);
					strcpy(record[i].City,record[j].City);
					strcpy(record[j].City,tempc);
			
					strcpy(tempc,record[i].name);
					strcpy(record[i].name,record[j].name);
					strcpy(record[j].name,tempc);	
				}
				else if(strcmp(record[i].City,record[j].City)==0)
				{
					if(strcmp(record[i].name,record[j].name)>0)
					{
						strcpy(tempc,record[i].name);
						strcpy(record[i].name,record[j].name);
						strcpy(record[j].name,tempc);	
					}
				}
			}
		}
	}

	for(int i=0;i<c;i++)
	{
		printf("%s\t",record[i].name);
		printf("%s\t",record[i].City);
		printf("%s\t",record[i].State);
		printf("\n");
	}
}

void isAvailable(char sport_name[], struct Date date)
{	int flag=1,c=0;
	struct available
	{
		char name[50];
		char City[50];
		char State[50];
	}record[10];
	for(int i=0;i<ngrounds;i++)
	{
		for(int j=0;j<grounds[i].nhsports&&flag==1;j++)
		{
			if(strcmp(sport_name, grounds[i].sports_hold[j])==0&&flag==1)
			{ 	
				if(grounds[i].nsports==0)
				{	
					strcpy(record[c].name,grounds[i].Ground_Name);
					strcpy(record[c].City,grounds[i].City);
					strcpy(record[c++].State,grounds[i].State);	
					flag=0;
				}
				else
				{	int count=0;
					for(int k=0;k<grounds[i].nsports&&flag==1;k++)
					{
						for(int l=0;l<grounds[i].sports[k].ndate&&flag==1;l++)
						{
							if(grounds[i].sports[k].date[l].day==date.day&&grounds[i].sports[k].date[l].month==date.month&&grounds[i].sports[k].date[l].year==date.year)
							{
								for(int m=0;m<grounds[i].sports[k].date[l].ntime&&flag==1;m++)
								{
									if(grounds[i].sports[k].date[l].stime[m].h<date.etime[0].h&&grounds[i].sports[k].date[l].etime[m].h>date.stime[0].h&&flag==1)
									{
										flag=0;
									}
									else
									{
										strcpy(record[c].name,grounds[i].Ground_Name);
										strcpy(record[c].City,grounds[i].City);
										strcpy(record[c++].State,grounds[i].State);
									}
								}
							}
							else if(count!=grounds[i].nsports)
							{
								count++;
							}
							else
							{
								strcpy(record[c].name,grounds[i].Ground_Name);
								strcpy(record[c].City,grounds[i].City);
								strcpy(record[c++].State,grounds[i].State);
							}
						}
					}
					if(count==2)
					{
						strcpy(record[c].name,grounds[i].Ground_Name);
						strcpy(record[c].City,grounds[i].City);
						strcpy(record[c++].State,grounds[i].State);	
					}
				}
			}
		}
	}

	char tempc[50];
	for(int i=0;i<c-1;i++)
	{
		for(int j=i+1;j<c;j++)
		{
			if(strcmp(record[i].State,record[j].State)>0)
			{
				strcpy(tempc,record[i].State);
				strcpy(record[i].State,record[j].State);
				strcpy(record[j].State,tempc);

				strcpy(tempc,record[i].City);
				strcpy(record[i].City,record[j].City);
				strcpy(record[j].City,tempc);
		
				strcpy(tempc,record[i].name);
				strcpy(record[i].name,record[j].name);
				strcpy(record[j].name,tempc);
			}
			else if(strcmp(record[i].State,record[j].State)==0)
			{
				if(strcmp(record[i].City,record[j].City)>0)
				{
					strcpy(tempc,record[i].City);
					strcpy(record[i].City,record[j].City);
					strcpy(record[j].City,tempc);
			
					strcpy(tempc,record[i].name);
					strcpy(record[i].name,record[j].name);
					strcpy(record[j].name,tempc);	
				}
				else if(strcmp(record[i].City,record[j].City)==0)
				{
					if(strcmp(record[i].name,record[j].name)>0)
					{
						strcpy(tempc,record[i].name);
						strcpy(record[i].name,record[j].name);
						strcpy(record[j].name,tempc);	
					}
				}
			}
		}
	}
	// if(c==0)
	// {
	// 	printf("Sport Cannot be played anywhere\n");
	// }
	// else
	{
		printf("The grounds available are:\n");
		for(int i=0;i<c;i++)
		{
			printf("%s\t",record[i].name);
			printf("%s\t",record[i].City);
			printf("%s\t",record[i].State);
			printf("\n");
		}
	}
}

void UniqueSports(char ground_name[], char city[])
{	
	int index=-1;
	for(int i=0;i<ngrounds;i++)
	{
		if(strcmp(grounds[i].Ground_Name,ground_name)==0&&strcmp(grounds[i].City,city)==0)
		{
			index=i;
		}
	}

	for(int i=0;i<ngrounds;i++)
	{	
		if(i!=index)
		{	
			for(int j=0;j<grounds[index].nsports;j++)
			{int count = 0;
				for(int k=0;k<grounds[i].nsports;k++)
				{	
					if(strcmp(grounds[index].sports[j].name,grounds[i].sports[k].name)==0)
					{
						count++;
					}
				}
				if(count==0)
				{
					printf("%s\n", grounds[index].sports[j].name);
				}
			}
		}		
	}
	if(index==-1)
	{
		printf("Ground does not exist\n");
	}
} 


void SportwithGround(char sport_name[])
{	char ground[20][50];
	int c=0;
	for(int i=0;i<ngrounds;i++)
	{
		for(int j=0;j<grounds[i].nhsports;j++)
		{
			if(strcmp(grounds[i].sports_hold[j], sport_name)==0)
			{
				strcpy(ground[c++],grounds[i].Ground_Name);
			}
		}
	}
	char tempc[50];
	for(int i=0;i<c-1;i++)
	{
		for(int j=i+1;j<c;j++)
		{
			if(strcmp(ground[i],ground[j])>0)
			{
				strcpy(tempc,ground[i]);
				strcpy(ground[i],ground[j]);
				strcpy(ground[j],tempc);
			}
		}
	}
	printf("The sport %s can be played in:\n",sport_name );
	for(int i=0;i<c;i++)
	{
		printf("%s\n",ground[i]);
	}
}

void FindLocationsForGameEvents(char sport_name[], struct Date sdate, struct Date edate)
{	char ground[20][50];
	int c=0;
	for(int i=0;i<ngrounds;i++)
	{
		for(int j=0;j<grounds[i].nsports;j++)
		{
			if(strcmp(grounds[i].sports[j].name, sport_name)==0)
			{
				for(int k=0;k<grounds[i].sports[j].ndate;k++)
				{
					if(grounds[i].sports[j].date[k].year>sdate.year&&grounds[i].sports[j].date[k].year<edate.year)
					{
						strcpy(ground[c++],grounds[i].Ground_Name);
					}
					else if(grounds[i].sports[j].date[k].year==sdate.year||grounds[i].sports[j].date[k].year==edate.year)
					{
						if(grounds[i].sports[j].date[k].month>sdate.month&&grounds[i].sports[j].date[k].month<edate.month)
						{
							strcpy(ground[c++],grounds[i].Ground_Name);
						}
						else if(grounds[i].sports[j].date[k].month==sdate.month||grounds[i].sports[j].date[k].month==edate.month)
						{
							if(grounds[i].sports[j].date[k].day>=sdate.day&&grounds[i].sports[j].date[k].day<=edate.day)
							{
								strcpy(ground[c++],grounds[i].Ground_Name);
							}
						}
					}
				}
			}
		}
	}

	char tempc[50];
	for(int i=0;i<c-1;i++)
	{
		for(int j=i+1;j<c;j++)
		{
			if(strcmp(ground[i],ground[j])>0)
			{
				strcpy(tempc,ground[i]);
				strcpy(ground[i],ground[j]);
				strcpy(ground[j],tempc);
			}
		}
	}
	printf("The sport %s is  played in the following grounds for the given date range:\n",sport_name );
	for(int i=0;i<c;i++)
	{
		printf("%s\n",ground[i]);
	}
}

void FindLocationsForGame(char sport_name[], struct Date date)
{
	int flag=1,c=0;
	struct available
	{
		char name[50];
		char City[50];
	}record[10];
	for(int i=0;i<ngrounds;i++)
	{
		for(int j=0;j<grounds[i].nhsports&&flag==1;j++)
		{
			if(strcmp(sport_name, grounds[i].sports_hold[j])==0&&flag==1)
			{ 	
				if(grounds[i].nsports==0)
				{	printf("The grounds available are:\n");
					printf("%s\t", grounds[i].Ground_Name);
					printf("%s\n", grounds[i].City);
					flag=0;
				}
				else
				{	int count=0;
					for(int k=0;k<grounds[i].nsports&&flag==1;k++)
					{
						for(int l=0;l<grounds[i].sports[k].ndate&&flag==1;l++)
						{
							if(grounds[i].sports[k].date[l].day==date.day&&grounds[i].sports[k].date[l].month==date.month&&grounds[i].sports[k].date[l].year==date.year)
							{
								for(int m=0;m<grounds[i].sports[k].date[l].ntime&&flag==1;m++)
								{
									if(grounds[i].sports[k].date[l].stime[m].h<date.etime[0].h&&grounds[i].sports[k].date[l].etime[m].h>date.stime[0].h&&flag==1)
									{
										flag=0;
									}
									else
									{
										strcpy(record[c].name,grounds[i].Ground_Name);
										strcpy(record[c++].City,grounds[i].City);
									}
								}
							}
							else if(count!=grounds[i].nsports)
							{
								count++;
							}
							else
							{
								strcpy(record[c].name,grounds[i].Ground_Name);
								strcpy(record[c++].City,grounds[i].City);
							}
						}
					}
					if(count==2)											// If all the sports have been iterated and no dates matched then ground will be definately free on the date
					{
						strcpy(record[c].name,grounds[i].Ground_Name);
						strcpy(record[c++].City,grounds[i].City);
					}
				}	
			}
		}
	}
	printf("The grounds available are:\n");
	for(int i=0;i<c;i++)
	{
		printf("%s\t",record[i].name);
		printf("%s\t",record[i].City);
		printf("\n");
	}
}

void FindLocationsForGameInTimeRange(char sport_name[], struct Date sdate, struct Date edate)
{
	char tempn[50][50], tempc[50][50];
	int count=0,l,flag=0,index[10],a=0;
	for(int i=0;i<ngrounds;i++)
	{	
		for(l=0;l<grounds[i].nhsports&&flag==0;l++)
		{
			if(strcmp(grounds[i].sports_hold[l],sport_name)==0)
			{	index[a++]=i;
				if(grounds[i].nsports==0)
				{
					printf("%s\t", grounds[i].Ground_Name);
					printf("%s\n", grounds[i].City);
					flag=1;
				}
				else
				{
					for(int j=0;j<grounds[i].nsports;j++)
					{	
						for(int k=0;k<grounds[i].sports[j].ndate;k++)
						{
							if(grounds[i].sports[j].date[k].year>sdate.year&&grounds[i].sports[j].date[k].year<edate.year)
							{	
								strcpy(tempc[count],grounds[i].City);
								strcpy(tempn[count++],grounds[i].Ground_Name);						
							}
							else if(grounds[i].sports[j].date[k].year==sdate.year||grounds[i].sports[j].date[k].year==edate.year)
							{
								if(grounds[i].sports[j].date[k].month>sdate.month&&grounds[i].sports[j].date[k].month<edate.month)
								{
									strcpy(tempc[count],grounds[i].City);
									strcpy(tempn[count++],grounds[i].Ground_Name);
								}
								else if(grounds[i].sports[j].date[k].month==sdate.month||grounds[i].sports[j].date[k].month==edate.month)
								{
									if(grounds[i].sports[j].date[k].day>=sdate.day&&grounds[i].sports[j].date[k].day<=edate.day)
									{
										strcpy(tempc[count],grounds[i].City);
										strcpy(tempn[count++],grounds[i].Ground_Name);
									}
								}
							}
						}
					}
				}
				
			}
		}
	}
	printf("The grounds available are:\n");
	for(int i=0;i<ngrounds;i++)
	{
		for(int k=0;k<a;k++)
		{
			if(i==a)
			{
				int c=0;
				for(int j=0;j<count;j++)
				{
					if(strcmp(grounds[i].Ground_Name,tempn[j])==0)
					{
						c++;
					}
				}
				if(c==0)
				{
					printf("%s\t", grounds[i].Ground_Name);
					printf("%s\n", grounds[i].City);

				}
			}

		}	

		
	}

}

void ClashOfMatches(struct Date date, char sport_name[])
{
	char name[20][50];	
	int c=0;
	for(int i=0;i<ngrounds;i++)
	{
		for(int j=0;j<grounds[i].nsports;j++)
		{
			if(strcmp(sport_name, grounds[i].sports[j].name)==0)
			{
				for(int k=0;k<grounds[i].sports[j].ndate;k++)
				{
					if(grounds[i].sports[j].date[k].day==date.day&&grounds[i].sports[j].date[k].month==date.month&&grounds[i].sports[j].date[k].year==date.year)
					{
						strcpy(name[c++],grounds[i].Ground_Name);
					}
				}
			}
		}
	}

	if(c==1)
	{
		printf("Match is happening only at one location: %s\n",name[0]);
	}
	else if(c==0)
	{
		printf("No match is played anywhere amongst all the grounds.\n");
	}
	else
	{	
		printf("Clash of Matches! of %s on %d %d %d\n",sport_name, date.day, date.month, date.year );
		for(int i=0;i<c;i++)
		{
			printf("Match is at %s\n",name[i] );
		}
	}
}


void GiveListOfGroundsHavingMinOneMatch(struct Date date, char city[])
{
	char name[20][50];	
	int c=0;
	for(int i=0;i<ngrounds;i++)
	{
		if(strcmp(grounds[i].City, city)==0)
		{
			for(int j=0;j<grounds[i].nsports;j++)
			{
				for(int k=0;k<grounds[i].sports[j].ndate;k++)
				{
					if(grounds[i].sports[j].date[k].day==date.day&&grounds[i].sports[j].date[k].month==date.month&&grounds[i].sports[j].date[k].year==date.year)
					{
						if(grounds[i].nsports>=1)
						{
							strcpy(name[c++],grounds[i].Ground_Name);
						}
					}
				}
			}
		}
		
	}
	if(c==1)
	{
		printf("Match is happening only at one location in the city: %s\n",name[0]);
	}
	else if(c==0)
	{
		printf("No match is played anywhere amongst all the grounds in the city.\n");
	}
	else
	{	
		printf(" Grounds having more than or equal to one match in the city %s on %d %d %d\n",city, date.day, date.month, date.year );
		for(int i=0;i<c;i++)
		{
			printf("Match is at %s\n",name[i] );
		}
	}
}

void GiveListOfGroundsHavingAtLeastKMatches(struct Date date, char city[], int l)
{
	char name[20][50];	
	int c=0;
	for(int i=0;i<ngrounds;i++)
	{
		if(strcmp(grounds[i].City, city)==0)
		{
			for(int j=0;j<grounds[i].nsports;j++)
			{
				for(int k=0;k<grounds[i].sports[j].ndate;k++)
				{
					if(grounds[i].sports[j].date[k].day==date.day&&grounds[i].sports[j].date[k].month==date.month&&grounds[i].sports[j].date[k].year==date.year)
					{
						if(grounds[i].nsports>=l)
						{
							strcpy(name[c++],grounds[i].Ground_Name);
						}
					}
				}
			}
		}
		
	}
	if(c>=l)
	{
		printf(" Grounds having more than or equal to K = %d match in the city %s on %d %d %d\n",l,city, date.day, date.month, date.year );
		for(int i=0;i<c;i++)
		{
			printf("Match is at %s\n",name[i] );
		}
	}		
}

void SortOnPriceForAGame(char sport_name[], struct Date date)
{
	int flag=1,c=0;
	struct available
	{
		char name[50];
		int hourly_rate;
	}record[10];
	for(int i=0;i<ngrounds;i++)
	{
		for(int j=0;j<grounds[i].nhsports&&flag==1;j++)
		{
			if(strcmp(sport_name, grounds[i].sports_hold[j])==0&&flag==1)
			{ int count=0;
				for(int k=0;k<grounds[i].nsports&&flag==1;k++)
				{
					for(int l=0;l<grounds[i].sports[k].ndate&&flag==1;l++)
					{
						if(grounds[i].sports[k].date[l].day==date.day&&grounds[i].sports[k].date[l].month==date.month&&grounds[i].sports[k].date[l].year==date.year)
						{
							for(int m=0;m<grounds[i].sports[k].date[l].ntime&&flag==1;m++)
							{
								if(grounds[i].sports[k].date[l].stime[m].h<date.etime[0].h&&grounds[i].sports[k].date[l].etime[m].h>date.stime[0].h&&flag==1)
								{
									flag=0;
								}
								else
								{
									strcpy(record[c].name,grounds[i].Ground_Name);
									record[c++].hourly_rate=grounds[i].sports[j].hourly_rate;
								}
							}
						}
						else if(count!=grounds[i].nsports)
						{
							count++;
						}
						else
						{
							strcpy(record[c].name,grounds[i].Ground_Name);
							record[c++].hourly_rate=grounds[i].sports[j].hourly_rate;
						}
					}
				}
				if(count==2)											// If all the sports have been iterated and no dates matched then ground will be definately free on the date
				{
					strcpy(record[c].name,grounds[i].Ground_Name);
					record[c++].hourly_rate=grounds[i].sports[j].hourly_rate;
				}
			}
		}
	}

	int hours = date.etime[0].h - date.stime[0].h;
	int temp; char tempc[50];
	for(int i=0;i<c-1;i++)
	{
		for(int j=i+1; j<c ; j++)
		{	
			if(record[i].hourly_rate>record[j].hourly_rate)
			{
				temp = record[i].hourly_rate;
				record[i].hourly_rate = record[j].hourly_rate;
				record[j].hourly_rate = temp;

				strcpy(tempc, record[i].name);
				strcpy(record[i].name, record[j].name);
				strcpy(record[j].name, tempc);
			}
		}
	}

	printf("Sorted List of Grounds :\n");
	for(int i=0; i<c; i++)
	{
		printf("%s\t",record[i].name );
		printf("%d\n",hours*record[i].hourly_rate );
	}
}

main()
{
	InitialDB(grounds,10);
	// for(int i=0;i<1;i++)
 	strcpy(grounds[0].Ground_Name, "VCA");
 	strcpy(grounds[0].City, "Nagpur");
 	strcpy(grounds[0].State, "Maharashtra");
 	strcpy(grounds[0].sports_hold[0], "Cricket");
 	strcpy(grounds[0].sports_hold[1], "Football");
 	strcpy(grounds[0].sports_hold[2], "Hockey");
 	grounds[0].nhsports = 3;

 	strcpy(grounds[0].sports[0].name, "Cricket");
 	grounds[0].sports[0].hourly_rate = 100;
 	grounds[0].nsports = 1;
 	grounds[0].sports[0].date[0].day = 05;
 	grounds[0].sports[0].date[0].month = 10;
 	grounds[0].sports[0].date[0].year = 2018;
 	grounds[0].sports[0].ndate=1;
 	grounds[0].sports[0].date[0].stime[0].h = 4;
 	grounds[0].sports[0].date[0].etime[0].h = 7;
 	grounds[0].sports[0].date[0].ntime = 1;

 	strcpy(grounds[0].sports[1].name, "Football");
 	grounds[0].sports[1].hourly_rate = 200;
 	grounds[0].nsports = 2;
 	grounds[0].sports[1].date[0].day = 15;
 	grounds[0].sports[1].date[0].month = 11;
 	grounds[0].sports[1].date[0].year = 2018;
 	grounds[0].sports[1].ndate=1;
 	grounds[0].sports[1].date[0].stime[0].h = 3;
 	grounds[0].sports[1].date[0].etime[0].h = 5; 
 	grounds[0].sports[1].date[0].ntime=1;

 	strcpy(grounds[1].Ground_Name, "BCA");
 	strcpy(grounds[1].City, "Nagpur");
 	strcpy(grounds[1].State, "Maharashtra");
 	strcpy(grounds[1].sports_hold[0], "Cricket");
 	strcpy(grounds[1].sports_hold[1], "Hockey");
 	strcpy(grounds[1].sports_hold[2], "Football");
 	grounds[1].nhsports = 3;

 	strcpy(grounds[1].sports[0].name, "Cricket");
 	grounds[1].sports[0].hourly_rate = 200;
 	grounds[1].nsports = 1;
 	grounds[1].sports[0].date[0].day = 05;
 	grounds[1].sports[0].date[0].month = 10;
 	grounds[1].sports[0].date[0].year = 2018;
 	grounds[1].sports[0].ndate=1;
 	grounds[1].sports[0].date[0].stime[0].h = 4;
 	grounds[1].sports[0].date[0].etime[0].h = 7;
 	grounds[1].sports[0].date[0].ntime =1;

 	strcpy(grounds[1].sports[1].name, "Hockey");
 	grounds[1].sports[1].hourly_rate = 200;
 	grounds[1].nsports = 2;
 	grounds[1].sports[1].date[0].day = 15;
 	grounds[1].sports[1].date[0].month = 11;
 	grounds[1].sports[1].date[0].year = 2018;
 	grounds[1].sports[1].ndate=1;
 	grounds[1].sports[1].date[0].stime[0].h = 3;
 	grounds[1].sports[1].date[0].etime[0].h = 5; 
 	grounds[1].sports[1].date[0].ntime =1;

 	int input;
 	while(1)
 	{
 		printf("1.getGroundInfo\n2.addSport\n3.deleteSport\n4.addGround\n5.deleteGround\n6.updateGround\n7.getFixturesinCity\n8.getFixturesinState\n9.getFixturesSortedonDate\n10.getFixturesSortedonState\n11.isAvailable\n12.UniqueSports\n13.SportwithGround\n14.FindLocationsForGameEvents\n15.FindLocationsForGame\n16.FindLocationsForGameInTimeRange\n17.ClashOfMatches\n18.GiveListOfGroundsHavingMinOneMatch\n19.GiveListOfGroundsHavingAtLeastKMatches\n20.SortOnPriceForAGame\n");
	 	printf("Choose the function by entering the number\n");
	 	scanf("%d", &input);
	 	switch(input)
	 	{
	 		case 1: 
	 		{
	 			char city1[50];
	 			printf("enter city name\n");
	 			scanf("%s",city1);
	 			getGroundInfo(city1);
	 		};break;

	 		case 2:
	 		{	struct Sports temp2;
	 			char city2[50], ground_name2[50];
	 			printf("enter city name\n");
	 			scanf("%s",city2);
	 			printf("enter ground name\n");
	 			scanf("%s",ground_name2);
	 			printf("Enter the sport name\n");
	 			scanf("%s",temp2.name);
	 			printf("Enter the hourly rate\n");
	 			scanf("%d",&temp2.hourly_rate);
	 			printf("Enter the date in dd mm yyyy\n");
	 			scanf("%d", &temp2.date[0].day);
	 			scanf("%d", &temp2.date[0].month);
	 			scanf("%d", &temp2.date[0].year);
	 			printf("Enter the start time in hh\n");
	 			scanf("%d", &temp2.date[0].stime[0].h);
	 			printf("Enter the end time in hh\n");
	 			scanf("%d", &temp2.date[0].etime[0].h);
	 			addSport(city2,ground_name2,temp2);

	 		};break;

	 		case 3:
	 		{
	 			struct Sports temp3;
	 			char city3[50], ground_name3[50];
	 			printf("enter city name\n");
	 			scanf("%s",city3);
	 			printf("enter ground name\n");
	 			scanf("%s",ground_name3);
	 			printf("Enter the sport name\n");
	 			scanf("%s",temp3.name);
	 			printf("Enter the hourly rate\n");
	 			scanf("%d",&temp3.hourly_rate);
	 			printf("Enter the date in dd mm yyyy\n");
	 			scanf("%d", &temp3.date[0].day);
	 			scanf("%d", &temp3.date[0].month);
	 			scanf("%d", &temp3.date[0].year);
	 			printf("Enter the start time in hh\n");
	 			scanf("%d", &temp3.date[0].stime[0].h);
	 			printf("Enter the end time in hh\n");
	 			scanf("%d", &temp3.date[0].etime[0].h);
	 			deleteSport(city3,ground_name3,temp3);
	 		}break;

	 		case 4:
	 		{
	 			struct Grounds temp4;
	 			printf("enter ground name\n");
	 			scanf("%s",temp4.Ground_Name);
	 			printf("enter city name\n");
	 			scanf("%s",temp4.City);
	 			printf("enter State name\n");
	 			scanf("%s",temp4.State);
	 			printf("Enter the number of games it can hold\n");
	 			scanf("%d", &temp4.nhsports);
	 			printf("Enter the name of sports it can hold\n");
	 			for(int i=0;i<temp4.nhsports;i++)
	 			{
	 				scanf("%s",temp4.sports_hold[i]);
	 			};
	 			addGround(temp4);
	 		}break;

	 		case 5:
	 		{
	 			char city5[50], ground_name5[50];
	 			printf("enter city name\n");
	 			scanf("%s",city5);
	 			printf("enter ground name\n");
	 			scanf("%s",ground_name5);
	 			deleteGround(ground_name5, city5);
	 		}break;

	 		case 6:
	 		{	
	 			char city6[50], ground_name6[50];
	 			printf("enter current city name\n");
	 			scanf("%s",city6);
	 			printf("enter the current ground name\n");
	 			scanf("%s",ground_name6);
	 			struct Grounds temp6;
	 			printf("enter new ground name\n");
	 			scanf("%s",temp6.Ground_Name);
	 			printf("enter new city name\n");
	 			scanf("%s",temp6.City);
	 			printf("enter new State name\n");
	 			scanf("%s",temp6.State);
	 			printf("Enter the new number of games it can hold\n");
	 			scanf("%d", &temp6.nhsports);
	 			printf("Enter the new name of sports it can hold\n");
	 			for(int i=0;i<temp6.nhsports;i++)
	 			{
	 				scanf("%s",temp6.sports_hold[i]);
	 			};
	 			updateGround(city6, ground_name6, temp6);
	 		}break;

	 		case 7:
	 		{
	 			char city7[50];
	 			printf("Enter the city name\n");
	 			scanf("%s",city7);
	 			struct Date sdate7, edate7;
	 			printf("enter the start date in dd mm yyyy");
	 			scanf("%d",&sdate7.day);
	 			scanf("%d",&sdate7.month);
	 			scanf("%d",&sdate7.year);
	 			printf("enter the end date in dd mm yyyy");
	 			scanf("%d",&edate7.day);
	 			scanf("%d",&edate7.month);
	 			scanf("%d",&edate7.year);
	 			getFixturesinCity(city7, sdate7, edate7);
	 		}break;

	 		case 8:
	 		{
	 			char state8[50];
	 			printf("Enter the State name\n");
	 			scanf("%s",state8);
	 			getFixturesinState(state8);
	 		}break;
	 		
	 		case 9:
	 		{
	 			getFixturesSortedonDate(grounds);
	 		}break;

	 		case 10:
	 		{
	 			getFixturesSortedonState(grounds);
	 		}break;

	 		case 11:
	 		{
	 			char sport_name11[50];
	 			printf("Enter the sport name:\n");
	 			scanf("%s",sport_name11);
	 			struct Date sport11;
	 			sport11.ntime=1;
	 			printf("Enter the date in dd mm yyyy\n");
	 			scanf("%d", &sport11.day);
	 			scanf("%d", &sport11.month);
	 			scanf("%d", &sport11.year);
	 			printf("Enter the start time\n");
	 			scanf("%d", &sport11.stime[0].h);
	 			printf("Enter the end time\n");
	 			scanf("%d", &sport11.etime[0].h);
	 			isAvailable(sport_name11,sport11);
	 		}break;

	 		case 12:
	 		{
	 			char city12[50];
	 			printf("Enter the city name\n");
	 			scanf("%s",city12);
	 			printf("Enter the ground name\n");
	 			char ground12[50];
	 			scanf("%s",ground12);
	 			UniqueSports(ground12,city12);
	 		}break;

	 		case 13:
	 		{
	 			char sport13[50];
	 			printf("Enter the Sport Name\n");
	 			scanf("%s",sport13);
	 			SportwithGround(sport13);
	 		}break;

	 		case 14:
	 		{
	 			char sport14[50];
	 			printf("Enter the Sport Name\n");
	 			scanf("%s",sport14);
	 			struct Date sdate14, edate14;
	 			printf("enter the start date in dd mm yyyy\n");
	 			scanf("%d",&sdate14.day);
	 			scanf("%d",&sdate14.month);
	 			scanf("%d",&sdate14.year);
	 			printf("enter the end date in dd mm yyyy\n");
	 			scanf("%d",&edate14.day);
	 			scanf("%d",&edate14.month);
	 			scanf("%d",&edate14.year);
	 			FindLocationsForGameEvents(sport14,sdate14,edate14);
	 		}break;

	 		case 15:
	 		{
	 			char sport15[50];
	 			printf("Enter the Sport Name\n");
	 			scanf("%s",sport15);
	 			struct Date date15;
	  			printf("enter the date in dd mm yyyy\n");
	 			scanf("%d",&date15.day);
	 			scanf("%d",&date15.month);
	 			scanf("%d",&date15.year);
	 			printf("enter the start time\n");
	 			scanf("%d",&date15.stime[0].h);
	 			printf("enter the end time\n");
	 			scanf("%d",&date15.etime[0].h);
	 			FindLocationsForGame(sport15,date15);
	 		}break;

	 		case 16:
	 		{
	 			char sport16[50];
	 			printf("Enter the Sport Name\n");
	 			scanf("%s",sport16);
	 			struct Date sdate16, edate16;
	 			printf("enter the start date in dd mm yyyy\n");
	 			scanf("%d",&sdate16.day);
	 			scanf("%d",&sdate16.month);
	 			scanf("%d",&sdate16.year);
	 			printf("enter the end date in dd mm yyyy\n");
	 			scanf("%d",&edate16.day);
	 			scanf("%d",&edate16.month);
	 			scanf("%d",&edate16.year);
	 			FindLocationsForGameInTimeRange(sport16,sdate16,edate16);
	 		}break;

	 		case 17:
	 		{
	 			struct Date date17;
	 			printf("enter the date in dd mm yyyy\n");
	 			scanf("%d",&date17.day);
	 			scanf("%d",&date17.month);
	 			scanf("%d",&date17.year);
	 			char sport17[50];
	 			printf("Enter the sport name\n");
	 			scanf("%s",sport17);
	 			ClashOfMatches(date17,sport17);
	 		}break;

	 		case 18:
	 		{
	 			struct Date date18;
	 			printf("enter the date in dd mm yyyy\n");
	 			scanf("%d",&date18.day);
	 			scanf("%d",&date18.month);
	 			scanf("%d",&date18.year);
	 			char city18[50];
	 			printf("Enter the city name\n");
	 			scanf("%s",city18);
	 			GiveListOfGroundsHavingMinOneMatch(date18,city18);
	 		}break;

	 		case 19:
	 		{
	 			struct Date date19;
	 			printf("enter the date in dd mm yyyy\n");
	 			scanf("%d",&date19.day);
	 			scanf("%d",&date19.month);
	 			scanf("%d",&date19.year);
	 			char city19[50];
	 			printf("Enter the city name\n");
	 			scanf("%s",city19);
	 			int k;
	 			printf("Enter the value of K\n");
	 			scanf("%d",&k);
	 			GiveListOfGroundsHavingAtLeastKMatches(date19,city19,k);
	 		}break;

	 		case 20:
	 		{
	 			struct Date date20;
	 			printf("enter the date in dd mm yyyy\n");
	 			scanf("%d",&date20.day);
	 			scanf("%d",&date20.month);
	 			scanf("%d",&date20.year);
	 			printf("Enter the start Time\n");
	 			scanf("%d",&date20.stime[0].h);
	 			printf("Enter the end Time\n");
	 			scanf("%d",&date20.etime[0].h);
	 			char sport20[50];
	 			printf("Enter the sport name\n");
	 			scanf("%s",sport20);
	 			SortOnPriceForAGame(sport20,date20);
	 		}break;
	 	}
 	}
 	




	// {
	// 	printf("%s\n",grounds[i].Ground_Name);
	// 	printf("%s\n",grounds[i].City);
	// 	printf("%s\n",grounds[i].State);
	// 	for(int j=0;j<10;j++)
	// 	{	
	// 		printf("%s\n",grounds[i].games[j].name);
	// 		printf("%d\n",grounds[i].games[j].hourly_rate);
	// 		printf("%d\n",grounds[i].games[j].date.day);
	// 		printf("%d\n",grounds[i].games[j].date.month);
	// 		printf("%d\n",grounds[i].games[j].date.year);
	// 		printf("%s\n",grounds[i].sports[j].name);
	// 		printf("%d\n",grounds[i].sports[j].date.day);
	// 		printf("%d\n",grounds[i].sports[j].date.month);
	// 		printf("%d\n",grounds[i].sports[j].date.year);						
	// 	}
	// }
}