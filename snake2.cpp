  #include<stdio.h>  
#include<stdlib.h>
#include<conio.h>
#include<unistd.h>

int w=40,h=40,gameover,start,start2,start3,start4;
int a,b,food1,food2,score,flag;


// function to generate food and give iy a positiion
// within boundary
void position()
{
	 gameover=0;
	 // height and width
  a=w/2;
  b=h/2;
  
  start:
  
  food1=rand()%40;
  if(food1==0)
  goto start;
  	
  	 start2:
  
  food2=rand()%40;
  if(food2==0)
 goto start2;
 score=0;
  	
}
//  function to draw boundary
void draw()
{
	system("cls");
	int i, j;
	
	for(i=0;i<w;i++)
	{
	
		for(j=0;j<h;j++)
	
	{
	 	if(i==0||i==h-1||j==0||j==w-1 )
	 	{
	 			printf("*");
		 }
		 else
		 {
		 	    if(i==a && j==b)
		 	    printf("O>");
		 	    else if(i==food1&&j==food2)
		 	    printf("F");
		 	    else
		 		printf(" ");
		 }
	
	}
 		printf("\n");
 		}
		 //  function to print the score after the 
		 // game end
		printf("score =%d", score );
		printf("\n");
		printf("press X to quit the game ");

	
}

// funnction to take input 
void in()
	{
		if(kbhit()){
			switch (getch()){
			 
			case 'u':
			 flag =1;			 // up
			break ;
			case 'd':
			flag =2;				// down
			break ;					
			case 'l':
			flag =3;				//left
			break ;
			case 'r':
			flag =4;				//rigth
			break ;
			case 'x':
			gameover =1;
			break ;





		} 
	}
}
	
	// function for the logic behind each move 
	void logic()
	{
	sleep(0.001);
	switch (flag) 
	{
		case 1:
		   b--;
			break;
		case 2:
		   a++;
			break;
		case 3:
		   b++;
			break;
		case 4:
		   a--;
			break;
		defalt:
		break;
	}
	//if the game is over
	if (a<0||a>h||b<0||b>w)
	 gameover=1;
	 //if snake reaches the food then update the score 
	 if(a==food1&&b==food2)

 {
	 
  		start3:
  
  			food1=rand()%40;
  			if(food1==0)
  			goto start3;
  	
  	 	start4:
  
  			food2=rand()%40;
  			if(food2==0)
 			goto start4;
 		score+=10;
     }
 }
 // driver code

int main()
{
	position();
		draw();
while ( gameover !=1)

{

	
		in();
		logic();
	 
	}
	 
	return 0;
}
