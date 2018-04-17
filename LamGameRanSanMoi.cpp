#include<iostream>
#include<windows.h>
#include<conio.h>
#include<time.h>
#define Width 30
#define Height 30
enum Trangthai{DOWN,LEFT,RIGHT,UP};

using namespace std;

	
	struct Toado
	{
		int x,y; // x la hoanh do, y là tung do	
		
	};
	struct Snake
	{
		Toado dot[100];
		Trangthai tt;
		int n;
	};
	struct Hoaqua
	{
		Toado td;	
	};	
	void gotoxy(int x, int y){
    	static HANDLE  h = NULL;
    	if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    	COORD c = {x,y};
    	SetConsoleCursorPosition(h,c);
	}
	void SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
 
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;
 
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
	void KhoitaoSnake(Snake &snake,Hoaqua &hq){
		
		snake.n=3;
		snake.dot[0].x=4;
		snake.dot[0].y=4;
		snake.dot[1].x=3;
		snake.dot[1].y=4;
		snake.dot[2].x=2;
		snake.dot[2].y=4;
		
		//snake.tt=static_cast <Trangthai>(rand() % 4);
		//hq.td.x=rand() % Width;
		//hq.td.y=rand() % Height;	
		
		}
	void Hienthi(Snake snake,Hoaqua hq){
		system("cls");
		//clrscr();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			for(int i=1;i<Width-1;i++)
			{
				
				putchar(205);
			}
			for(int j=0;j<Height;j++)
			{
				for(int i=0;i<Width;i++)
				{
					if(i==0 || i==Width)
					putchar(179);
					else putchar(32);
				}
				cout<<endl;
			}
			
			/*SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			gotoxy(hq.td.x,hq.td.y);
			cout<<"%";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
			for(int i=0;i<snake.n;i++){
			gotoxy (snake.dot[i].x,snake.dot[i].y);
			cout<<"@";
			}*/
	
	}	
	void Move_Snake(Snake &snake){
		
		// truyen trang thai cho dot cu
		for (int i=snake.n-1;i>0;i--)
			snake.dot[i]=snake.dot[i-1];
			
		if (kbhit())	 //hàm phát hien phim nhan
		{
			int key = _getch();
		
			if (key=='A' || key=='a')
				snake.tt=LEFT;
			else if (key=='D' || key=='d')
				snake.tt=RIGHT;
			else if (key=='S' || key=='s')
				snake.tt=DOWN;
			else if (key=='W' || key=='w')
				snake.tt=UP;
		}
		
		if (snake.tt==LEFT) snake.dot[0].x--;
		else if (snake.tt==DOWN) snake.dot[0].y++;
		else if (snake.tt==RIGHT) snake.dot[0].x++;
		else if (snake.tt==UP) snake.dot[0].y--;					
		
			
	}		
	void Xuli(Snake &snake,Hoaqua &hq){
		if(snake.dot[0].x==hq.td.x && snake.dot[0].y==hq.td.y)
		{
			for(int i=snake.n;i>0;i--)
				snake.dot[i]=snake.dot[i-1];
				
			snake.n++;
			
			if(snake.tt==UP) snake.dot[0].y--;
			else if(snake.tt==DOWN) snake.dot[0].y++;
			else if(snake.tt==RIGHT) snake.dot[0].x++;
			else if(snake.tt==LEFT) snake.dot[0].x--;
			
			hq.td.x=rand() % Width;
			hq.td.y=rand() % Height;					
		}
	}
	/*int Checking_Die(Snake &snake){
		
		for(int i=1;i<snake.n;i++){
			if (snake.dot[0].x == snake.dot[i].x && snake.dot[0].y == snake.dot[i].y)
				Check=1;
				}
		if(snake.dot[0].x<0 || snake.dot[0].y<0 || snake.dot[0].x>Width || snake.dot[0].y>Height)					
			return 1;
			}
			*/
			
	int main(){
		srand(time(NULL));
		Snake snake;
		Hoaqua hq;
		int x,y,result=0;
		int Check=0;
		gotoxy(x,y);
		KhoitaoSnake(snake,hq);
		while(1){
		//Hien thi
			Hienthi(snake,hq);		
		//DieuKhien_Dichuyen
			//Move_Snake(snake);
		//Xu li
			//Xuli(snake,hq);
		//Win or Gameover
			/*Check=Checking_Die(snake);
			
				if(Check==1)
				{
					gotoxy(Width+1,10);
					cout<<"Game Over";
					getchar();
					break;
					} */
			Sleep(100);
			
		}
		return 0;
	}
		
