// C program of 15 puzzle Game
#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
int n[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 14, 100}; // 100 as a placeholder for space
void print_head(int i)
{
	printf("\t15 PUZZLE GAME\n\nArrange the tiles in ascending order\nMoves:\n\t a -> Left\n\t d -> Right\n\t w -> Up\n\t s -> Down\n");
	printf("\n\t q -> Quit Game\n");
	// printf("i=%d r=%d,c=%d,ch=%c\n",i,r,c,ch);
	printf("No. of moves tried = %d \n", i);
}
void p() // print the tiles
{
	printf("\t_________________________\n");

	for (int i = 0; i < 4; i++)
	{
		// printf("\n|\n|");

		printf("\t|     |     |     |     |\n");
		printf("\t|");
		for (int j = 0; j < 4; j++)
		{
			if (n[i][j] == 100)
				printf("     |");
			else
				printf(" %2d  |", n[i][j]);
		}
		printf("\n\t|_____|_____|_____|_____|\n");
	}
}
int win()
{ // check winning configuration on the square
	int b = 0, *c;
	c = *n; // n[0] as first element of array
	for (int i = 0; i < 15; i++)
	{
		if (*c < *(c + 1))
			b++;
		c++;
	}
	if(b==15){
		return 1;
	}
	return 0;
}

int main()
{

	int x = 0, r = 3, c = 3;
	char ch;
	for (int i = 0; 1; i++)
	{
		if (ch == 'q')
		{
			i--;
			printf("Are you sure you want to quit?\nPress : n-No     Any other letter-Yes\n");
			// scanf(" %c", &ch);
			ch=_getche();
			if (ch =='n')
			{
				system("cls");
				ch=0;
			}
			else
			{
				return 0;
			}
		}
		print_head(i);
		if (i == 0)
			;
		else
		{
			if ((c != 3) && (ch == 'a'))
			{
				n[r][c] = n[r][c + 1];
				n[r][c + 1] = 100;
				c++;
			}
			else if ((c != 0) && (ch == 'd'))
			{
				n[r][c] = n[r][c - 1];
				n[r][c - 1] = 100;
				c--;
			}
			else if ((r != 0) && (ch == 's'))
			{
				n[r][c] = n[r - 1][c];
				r--;
				n[r][c] = 100;
			}
			else if ((r != 3) && (ch == 'w'))
			{
				n[r][c] = n[r + 1][c];
				r++;
				n[r][c] = 100;
			}
			else if(ch!=0)
			{
				printf("[Move '%c' is not allowed]\n", ch);
			}
		}
		p();

		printf("\n");

		if (win())
		{
			printf("You won using %d moves\nPress any letter to exit", i);
			scanf(" %c", &ch);
			return 0;
		}
		printf("Your move - ");
		// scanf(" %c", &ch);
		ch=_getche();
		system("cls");
	}
}
