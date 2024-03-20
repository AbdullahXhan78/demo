#include<stdio.h>
#include<conio.h>
void showframe(int posx, int posy)
{
	int hr=196,vr=179;
	int crossbr=197;
	int x=posx, y=posy;
	int i,j;
	gotoxy(35,4);
	cprint("TIC TAC TOE");
	for(i=0,i<2,i++)
	{
		for(j=1,j<=11,j++)
		{
			gotoxy(x,y);
			printf("%c",hr);
			x++;p; x++;
		}
		x=posx; y+=2;
	}
	x=posx+3; y=posy-1;
	for(i=0,i<2,i++)
	{
		for(j=1,j<=11,j++)
		{
			gotoxy(x,y);
			printf("%c",vr);
			y++;
		}
		x=posx+3; y=posy;
	}
	x=posx+3; y=posy;
	gotoxy(x.y);
	printf("%c",crossbr);
	
	x=posx+7; y=posy;
	gotoxy(x,y);
	printf("%c",crossbr);
	
	x=posx+3; y=posy;
	gotoxy(x.y);
	printf("%c",crossbr);
	
	x=posx+7; y=posy+2;
	gotoxy(x,y);
	printf("%c",crossbr);
}
void showbox(char ch, int box)
{
	switch(box)
	{
		case 1 : gotoxy(_x+1, _y-1);
		printf("%c",ch); break;
		case 2 : gotoxy(_x+5, _y-1);
		printf("%c",ch); break;
		case 3 : gotoxy(_x+9, _y-1);
		printf("%c",ch); break;
		case 4 : gotoxy(_x+1, _y+1);
		printf("%c",ch); break;
		case 5 : gotoxy(_x+5, _y+1);
		printf("%c",ch); break;
		case 6 : gotoxy(_x+9, _y+1);
		printf("%c",ch); break;
		case 7 : gotoxy(_x+1, _y+3);
		printf("%c",ch); break;
		case 8 : gotoxy(_x+5, _y+3);
		printf("%c",ch); break;
		case 9 : gotoxy(_x+9, _y+3);
		printf("%c",ch); break;
	}
}
void putintobox(char arr[3][3], char ch, int box)
{
	switch(box)
	{
		case 1 : if(arr[0][0]!='X' && arr[0][0]!='O')
		{
			arr[0][0] = ch;
			showbox(ch, 1); 
		}
		break;
	}
	case 2 : if(arr[0][1]!='X' && arr[0][1]!='O')
		{
			arr[0][1] = ch;
			showbox(ch, 2); 
		}
		break;
	}
	case 3 : if(arr[0][2]!='X' && arr[0][2]!='O')
		{
			arr[0][2] = ch;
			showbox(ch, 3); 
		}
		break;
	}
	case 4 : if(arr[1][0]!='X' && arr[1][0]!='O')
		{
			arr[1][0] = ch;
			showbox(ch, 4); 
		}
		break;
	}
	case 5 : if(arr[1][1]!='X' && arr[1][1]!='O')
		{
			arr[1][1] = ch;
			showbox(ch, 5); 
		}
		break;
	}
	case 6 : if(arr[1][2]!='X' && arr[1][2]!='O')
		{
			arr[1][2] = ch;
			showbox(ch, 6); 
		}
		break;
	}
	case 7 : if(arr[2][0]!='X' && arr[2][0]!='O')
		{
			arr[2][0] = ch;
			showbox(ch, 7); 
		}
		break;
	}
	case 8 : if(arr[2][1]!='X' && arr[2][1]!='O')
		{
			arr[2][1] = ch;
			showbox(ch, 8); 
		}
		break;
	}
	case 9 : if(arr[2][2]!='X' && arr[2][2]!='O')
		{
			arr[2][2] = ch;
			showbox(ch, 9); 
		}
		break;
	}
}
void gotobox(int box)
{
	switch(box)
	{
		case 1 : gotoxy(_x+1,_y-1);break;
		case 2 : gotoxy(_x+5,_y-1);break;
		case 3 : gotoxy(_x+9,_y-1);break;
		case 4 : gotoxy(_x+1,_y+1);break;
		case 5 : gotoxy(_x+5,_y+1);break;
		case 6 : gotoxy(_x+9,_y+1);break;
		case 7 : gotoxy(_x+1,_y+3);break;
		case 8 : gotoxy(_x+5,_y+3);break;
		case 9 : gotoxy(_x+9,_y+3);break;
	}
}
int navigate(char arr[3][3], int box, int player, int key)
{
	switch(key)
	{
		case UPARROW : if((box!=1) \\ (box!=2) \\ (box!=3))
		{
			box=3;
			if((box<1) box=1;gotobox(box))
			break;
		}
		case DOWNARROW : if((box!=7) \\ (box!=8) \\ (box!=9))
		{
			box+=3;
			if(box>9) box=9;gotobox(box);
			break;
		}
		case LEFTARROW : if((box!=1) \\ (box!=4) \\ (box!=7))
		{
			box--;
			if(box<1) box=1;gotobox(box);
			break;
		}
		case RIGHTARROW : if((box!=3) \\ (box!=6) \\ (box!=9))
		{
			box++;
			if(box>9) box=9;gotobox(box);
			break;
		}
		case ENTER : if(player==0)
		{
			putintobox(arr'O',box);
		}
		else if(player==1)
		{
			putintobox(arr'X',box);
		}
			break;
	}
	return box;
}
int checkforwin(char arr[3][3])
{
	int w=0;
	//rows
	if((arr[0][0] == arr[0][1]) && (arr[0][1]==arr[0][2])) w=1;
	else if((arr[1][0] == arr[1][1]) && (arr[1][1] == arr[1][2])) w=1;
	else if((arr[2][0] == arr[2][1]) && (arr[2][1] == arr[2][2])) w=1;
	//columns
	else if((arr[0][0] == arr[1][0]) && (arr[1][0] == arr[2][0])) w=1;
	else if((arr[0][1] == arr[1][1]) && (arr[1][1] == arr[2][1])) w=1;
	else if((arr[0][2] == arr[1][2]) && (arr[1][2] == arr[2][2])) w=1;
	//diagonals
	else if((arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2])) w=1;
	else if((arr[0][2] == arr[1][1]) && (arr[1][1] == arr[2][0])) w=1;
	return w;
}
int boxesleft(char arr[3][3])
{
	int i,j,boxesleft = 9;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if((a[i][j] == 'X')\\(a[i][j] == 'O'))
			{
				boxesleft--;
			}
		}
	}
	return boxesleft;
}
