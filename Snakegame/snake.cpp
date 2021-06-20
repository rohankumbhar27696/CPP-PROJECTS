#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#include <windows.h>
#include <conio.h>
#include <process.h>

#define UP    72
#define DOWN  80
#define LEFT  75
#define RIGHT 77

struct coordinate {
    int X;
    int Y;
    int direction;
    
};

typedef struct coordinate coordinate;

coordinate *body,head,apple;


int gameOver = 0;
int appleEaten = 0;
int life = 3;
int score=0;
int bodycnt = 0 ; 
char key = RIGHT;
char food_char = '@';
int RCORNER_Y_UP = 10;
int RCORNER_X_UP = 5;
int RCORNER_Y_DOWN = 30;
int RCORNER_X_DOWN = 95;


void setXY(int x, int y);
void printscoreboard(int lives , int score);
void board();
void food();
void spawnSnake() ;
void move();
int getInput(unsigned int timeout);
void right_move();
void left_move();
void up_move();
void down_move();
void eat();
void print_body();
void print_head();
void collect_coord();
void border_check();
void game_on();
void git_test();

int main()
{


	printf("opening snakeswarm.exe....\n");

	
	game_on();
	
	
	

	
}


void printscoreboard(int lives , int score)
{
	setXY(10,5);
	printf("SCORE = %d \n",score);	
}

void setXY(int x, int y)
{
	
    COORD c;
    fflush(stdout);
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void board()
{
	int x = 0,y=0;
	setXY(RCORNER_X_UP,RCORNER_Y_UP);
	for( x = RCORNER_X_UP ; x < 95 ; x++)
	{
		setXY(x,RCORNER_Y_UP);
		printf("_");	
	}
	
	setXY(RCORNER_X_UP,RCORNER_Y_DOWN);
	for( x = RCORNER_X_UP ; x < 95 ; x++)
	{
		setXY(x,RCORNER_Y_DOWN);
		printf("_");	
	}
	
	setXY(RCORNER_X_UP+1,RCORNER_Y_UP);
	for( y = RCORNER_Y_UP+1 ; y <= 30 ; y++)
	{
		setXY(RCORNER_X_UP,y);
		printf("|");	
	}	
	
	setXY(RCORNER_X_UP+1,RCORNER_Y_UP);
	for( y = RCORNER_Y_UP+1 ; y <= 30 ; y++)
	{
		setXY(RCORNER_X_DOWN,y);
		printf("|");	
	}				
	
	
	
}

void food() {
	
    if (apple.X == 0 && apple.Y == 0) {
    	
        int rx = ((rand() % 89 + 5));
        int ry = ((rand() % 24 + 10));
        apple.X = rx;
        apple.Y = ry;
        setXY(apple.X, apple.Y);
        printf("A");
    } else {
        setXY(apple.X, apple.Y);
        printf("A");
    }
    
}


void spawnSnake() 
{
    int x = 90/ 2;
    int y = (41) / 2;
    head.X = x;
    head.Y = y;
    body[0].X = head.X;
    body[0].Y = head.Y;
    
    head.direction = RIGHT;
    body[0].Y = head.direction;
    setXY(x, y);
    printf(">");
}

int getInput(unsigned int timeout)
{
    for (; timeout != 0; timeout--)
    {
        if (kbhit())
        {
            return 1;
        }
    }
   	return 0;
}

void right_move()
{
	setXY((body[0].X), body[0].Y);
	printf(" ");	
	
	body[0].X = head.X++;
	body[0].Y = head.Y;	
	body[0].direction = RIGHT;
			

	setXY(body[0].X,body[0].Y);
	printf(">");
}

void left_move()
{
	setXY((body[0].X), body[0].Y);
	printf(" ");	
	
	body[0].X = head.X--;
	body[0].Y = head.Y;	
	body[0].direction = LEFT;
			

	setXY(body[0].X,body[0].Y);
	printf("<");
}

void up_move()
{
	setXY((body[0].X), body[0].Y);
	printf(" ");	
	
	body[0].X = head.X;
	body[0].Y = head.Y--;	
	body[0].direction = UP;
			

	setXY(body[0].X,body[0].Y);
	printf("^");
}

void down_move()
{
	setXY((body[0].X), body[0].Y);
	printf(" ");	
	
	body[0].X = head.X;
	body[0].Y = head.Y++;	
	body[0].direction = DOWN;
			

	setXY(body[0].X,body[0].Y);
	printf("v");
}


void eat()
{
	int  i =0;
	if ( body[0].X == apple.X && body[0].Y == apple.Y  )
	{
		apple.X = 0;
		apple.Y = 0;
		food();
		bodycnt++;
		
		body = (coordinate *)realloc(body, bodycnt);
		score++;
		printscoreboard(life,score);
		
		
	}

}


void collect_coord()
{
	int i = 0;
	for( i  = bodycnt ; i > 0  ; i--)
	{

		setXY( body[i].X,body[i].Y);
		printf(" ");							
		body[i].X = body[i-1].X;
		body[i].Y = body[i-1].Y;
		body[i].direction = body[i].direction ;

		
							
	}	
}

void print_body()
{
	int i = 0;
	

			for( i  = bodycnt ; i > 0  ; i--)
			{
				setXY( body[i].X , body[i].Y );
				printf(" ");

				setXY( body[i].X , body[i].Y );
				printf("O");					
						
			}
	
}



void print_head()
{
	setXY( body[0].X , body[0].Y );
	if( body[0].direction == RIGHT)
	{
		printf(">");
		
	}
	else if( body[0].direction == LEFT)
	{
		printf("<");
	}
	else if(body[0].direction == UP)
	{
		printf("^");
	}
	else if(body[0].direction == DOWN)
	{
		printf("v");
	}
}

void border_check()
{
	if( (body[0].X <= 5  ||  body[0].X >=95) ||   (body[0].Y <= 10  ||  body[0].Y >=30))
	{


		system("cls");
		setXY(20,10);
		printf("GAME OVER");
		setXY(20,11);
		printf("SCORE - %d ",score);
	
		setXY(20,15);
		printf("PLAY AGAIN ? Y (GAME ON) / N (EXIT)");
		while(1)
		{
			if(getInput(10000))
			{
				key = getch();
				
				if( key == 'Y' || key == 'y')
				{
					system("cls");
					game_on();
				}
				else if( key == 'N' || key == 'n' )
				{
					exit(0);
				}
				else
				{
					setXY(20,15);
					printf("PLAY AGAIN ? Y (GAME ON) / N (EXIT)");	
				}
				
			}
		}
	}
}



void game_on()
{
	printscoreboard(3,0);
	board();
	food();
	body = (coordinate *)realloc(body, bodycnt+1);
	spawnSnake();
	while(1)
	{
		if( getInput(10000))
		{
			key = getch();
			
			if( key == RIGHT && body[0].direction != LEFT )
			{
				collect_coord();
				right_move();
				eat();
				print_head();
				print_body();
				border_check();
				

				
			}
			else if( key == LEFT && body[0].direction != RIGHT )
			{
				collect_coord();
				left_move();
				eat();
				print_head();
				print_body();
				border_check();
				
			}
			else if( key == UP && body[0].direction != DOWN  )
			{
				collect_coord();
				up_move();
				eat();
				print_head();
				print_body();
				border_check();
				

			}
			else if( key == DOWN && body[0].direction != UP  )
			{
				collect_coord();
				down_move();
				eat();
				print_head();
				print_body();
				border_check();

			}

			
			
			
			
						
		}
		else
		{
			
			if( key == RIGHT  )
			{
				collect_coord();
				right_move();
				eat();
				print_head();
				print_body();
				border_check();

			}
			else if( key == LEFT )
			{
				collect_coord();
				left_move();
				eat();
				print_head();
				print_body();
				border_check();

			}
			else if( key == UP)
			{
				collect_coord();
				up_move();
				eat();
				print_head();
				print_body();
				border_check();

			}
			else if( key == DOWN )
			{
				collect_coord();
				down_move();
				eat();
				print_head();
				print_body();
				border_check();

			}
			else
			{
				
			}			
			
			
		}
	}	
}


void git_test()
{
	printf("FOR TESTING GIT.......\n");
}