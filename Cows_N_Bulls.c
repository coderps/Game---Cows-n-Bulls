#include<stdio.h>
#include<process.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
void main()
{
	int a,b,c,count=0,i,j,flag[4]={0,0,0,0};
	char user[4],in[4];

	clrscr();

	do{
		printf("\nEnter the Word:");
		gets(user);

		for(i=0;i<4;++i)
		  toupper(user[i]);

		a=0;

		if(strlen(user)!=4)
		{
			printf("\nThe word should have exactly 4 letters!!");
			a=1;
		}
		else
		  for(i=0;i<4;++i)
		    if( !isalpha(user[i]) )
		    {
			a=1;
			printf("\nThe word should contain letters only!!");
			break;
		    }
	}while(a==1);

	clrscr();
	printf("\n----START GUESSING----\n   _ _ _ _\n");

	while(count<15)
	{
		if(count<9)
		  printf("\n%d: ",count+1);
		else printf("\n%d:",count+1);

		gets(in);

		a=b=c=0;

		if(strlen(in)!=4)
		{
			printf("\nThe word should have exactly 4 letters!!");
			a=1;
		}
		else
		  for(i=0;i<4;++i)
		    if( !isalpha(in[i]) )
		    {
			a=1;
			printf("\nThe word should contain letters only!!");
			break;
		    }

		for(i=0;i<4;++i)
		{
		  flag[i]=0;
		  toupper(in[i]);
		}

		if(a==1)
		{
		  printf("\n\t\tWrong input, lost a turn!!");
		  count++;
		  continue;
		}

		for(i=0;i<4;++i)
		  if(user[i]==in[i])
		  {
			b++;
			flag[i]=1;
		  }

		if(b==4)
		{
			printf("\nGot it right!!\nTurns used: %d",count+1);
			break;
		}

		for(i=0;i<4;++i)
		  for(j=i;j<4;++j)
		    if(user[i]==user[j] && i!=j )
		      flag[j]=1;

		for(i=0;i<4;++i)
		  for(j=0;j<4;++j)
		    if(flag[i]==0 && user[i]==in[j])
		    {
			c++;
			flag[i]==1;
		    }

		count++;
		printf("\n\t\tBULL=%d\tCOW=%d",b,c);
	}

	if(count==15)
	  printf("\n\nOOPS! RAN OUT OF TURNS!!\n\nThe word was: %s\n",user);

	getch();
}
