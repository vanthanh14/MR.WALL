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
		Toado dot[20];
		Trangthai tt;
		int n;
	};
	
	struct Hoaqua
	{
		Toado td;
		
	};	
	void gotoxy(int x, int y)
{
    static HANDLE  h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = {x,y};
    SetConsoleCursorPosition(h,c);
}
	void KhoitaoSnake(Snake &snake,Hoaqua &hq){
		
		snake.n=3;
		snake.dot[0].x=2;
		snake.dot[0].y=0;
		snake.dot[1].x=1;
		snake.dot[1].y=0;
		snake.dot[2].x=0;
		snake.dot[2].y=0;
		snake.tt=RIGHT;
		hq.td.x=10;
		hq.td.y=10;	
		
		}
	void Hienthi(Snake snake,Hoaqua hq){
		system("cls");
		//clrscr();
			for(int i=0;i<Height;i++)
			{
				gotoxy(Width,i);
				putchar(179);
			}
			
			
			gotoxy(hq.td.x,hq.td.y);
			cout<<"A";
			
			for(int i=0;i<snake.n;i++){
			gotoxy (snake.dot[i].x,snake.dot[i].y);
			cout<<"*";
			}
	
	}	
	void Dieukhien_Dichuyen(Snake &snake){
		
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
	
	int KiemTra(Snake &snake){
		int result=1;
		for(int i=1;i<snake.n;i++){
			if (snake.dot[0].x == snake.dot[i].x && snake.dot[0].y == snake.dot[i].y)
				//gotoxy(Width+1,10);
				result=0;
				return result;
				}
		if(snake.dot[0].x<0 || snake.dot[0].y<0 || snake.dot[0].x>Width || snake.dot[0].y>Height){
			//gotoxy(Width+1,10);					
			result=0;
			return result;
			}
			
	}	
	int main(){
		srand(time(NULL));
		Snake snake;
		Hoaqua hq;
		int x,y,result;
		gotoxy(x,y);
		KhoitaoSnake(snake,hq);
		while(1){
		
		//Hien thi
	
			Hienthi(snake,hq);		
		//DieuKhien_Dichuyen
			Dieukhien_Dichuyen(snake);
		//Xu li
			Xuli(snake,hq);
		//Win or Gameover
			KiemTra(snake);
				
				
		Sleep(100);
		
		
		}
	return 0;	
		}
		
