#include<stdio.h>
#include<process.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
int check(char*);
int special_key(int*,char);
void main()
{
	int a,b,c,d,x=4,y=5,count=0,i,j,flag[4]={0,0,0,0};
	char user[4],in[4];

	clrscr();

	do{

		printf("\nEnter the Word:");
		gets(user);

		strupr(user);

		a=0;

		if(strlen(user)!=4)
		{
			printf("\nThe word should have exactly 4 letters!!");
			a=1;
		}
		else
		  for(i=0;i<4;++i)
		    if( isdigit(user[i]) || !isalpha(user[i]) )
		    {
			a=1;
			printf("\nThe word should contain letters only!!");
			break;
		    }
		if(!check(user))
		{
			a=1;
			printf("\nWord does not exist!!");
		}
	}while(a==1);

	clrscr();
	printf("\n----START GUESSING----\n   _ _ _ _\n");

	while(count<15)
	{
		if(count<9)
		  printf("\n%d: ",count+1);
		else printf("\n%d:",count+1);

		for(i=0;i<4;x+=2)
		{
			in[i]=getch();

			if(in[i]==8 || in[i]==13 || in[i]==27)
			  i+=special_key(&x,in[i]);

			if(in[i]==8)
			{
			  gotoxy(x,y);
			  printf(" ");
			}

			if(i>4)
			  break;

			printf("%c ",in[i]);
			flag[i]=0;
		}

		if(i==4)
		  getch();

		a=b=c=d=0;
		strupr(in);

		for(i=0;i<4;++i)
		    if( isdigit(in[i]) || !isalpha(in[i]) )
		    {
			a=1;
			d=1;
			printf("\n\t\tWrong input, lost a turn!!\n");
			count++;
			break;
		    }

		if(!check(in) && d!=1)
		{
			a=1;
			printf("\nNo such word exists!! Lost a turn for cheating -.- !!\n");
			count++;
		}

		if(a==1)
		  continue;

		for(i=0;i<4;++i)
		  if(user[i]==in[i])
		  {
			b++;
			flag[i]=1;
		  }

		if(b==4)
		{
			printf("\n\nGot it right!!\nTurns used: %d",count+1);
			break;
		}

		for(i=0;i<4;++i)
		  for(j=i;j<4;++j)
		    if(user[i]==user[j] && i!=j )
		      flag[j]=1;

		for(i=0;i<4;++i)
		  for(j=0;j<4;++j)
		    if(flag[i]==0 && user[i]==in[j])
		      c++;

		count++;
		y+=3;

		printf("\n\t\tBULL=%d\tCOW=%d",b,c);
	}

	if(count==15)
	  printf("\n\nOOPS! RAN OUT OF TURNS!!\n\nThe word was: %s\n",user);

	getch();
}
int check(char word[])
{
	int found,i;
	char c,chk[4];
	FILE *f;

	f=fopen("4letter.txt","r");

	while(c!=EOF)
	{
		found=0;
		c=fscanf(f,"%s",chk);

		for(i=0;i<4;++i)
		{
		  if(word[i]==chk[i])
		    continue;
		  else  break;
		}

		if(i==4)
		{
		  found=1;
		  break;
		}
	}

	fclose(f);

	return found;
}

int special_key(int *x,char key)
{
	int inc=0;

	if(key==13)
	  inc+=10;
	else if(key==8)
	{
	  inc--;
	  *x-=-2;
	}
	else if(key==27)
	  inc=100;

	return inc;
}
