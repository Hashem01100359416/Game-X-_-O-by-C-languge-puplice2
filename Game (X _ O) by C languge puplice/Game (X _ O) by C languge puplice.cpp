#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#define null -32
#define normalcolor 10
#define highcolor 150
#define win 140


void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}

void gotoxy(int x, int y)
{
    COORD coord = { 0,0 };
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main()
{
    int size = 3;
    char menuitem[3][3] = { {'_','_','_'},{'_','_','_'},{'_','_','_'} };//"1 2 3 4 5","1 2 3 4 5","1 2 3 4 5","1 2 3 4 5"};
    int quitfalg = 0;
    int row = 20, col = 90;
    int currentitem = 0, r1 = 0, c1 = 0, c2 = 0, cxc = 0, coc = 0, cxr1 = 0, cxr2 = 0, cxr3 = 0, cor1 = 0, cor2 = 0, cor3 = 0, ml = 0, mr = 0, mx = 0, mo = 0, g = 0;
    char c;
    char x = 'X', o = 'O';

    do
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {

                gotoxy(col + j * 10, row + i * 4);
                if (currentitem == (i * size) + j)
                {
                    textattr(highcolor);
                    r1 = i;
                    c1 = j;
                }
                else
                {
                    textattr(normalcolor);
                }
                printf("%c", menuitem[i][j]);
            }
        }
        textattr(normalcolor);
        printf("\n\n");
        if (x == 10)
        {
            // textattr(win);
            printf("                                                       player X WIN\n\n\n\n\n");
        }
        else if (x == 15)
        {
            //  textattr(win);
            printf("                                                       player O WIN\n\n\n\n\n");
        }
        if (x == 15 || x == 10)
        {
            printf("Enter 1 to again  this Game and Enter 2 to End this Game \n\n");
            scanf("%i", &g);
            if (g == 1)
            {
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++)
                    {

                        menuitem[i][j] = '_';
                    }
                }
            }
            else
            {
                quitfalg = 1;
            }
            x = 0;
        }



        if (quitfalg == 0);
        {
            c = getch();
            switch (c)
            {
            case -32: //extended keys
                c = getch();
                switch (c)
                {
                case 72:   //  up
                    if (r1 > 0)
                    {
                        r1--;
                        currentitem = ((r1)*size) + c1;
                    }
                    break;
                case 80:   //  down
                    if (r1 < size - 1)
                    {
                        r1++;
                        currentitem = ((r1)*size) + c1;
                    }
                    break;
                case 77:   //  right
                    if (c1 < size - 1)
                    {
                        c1++;
                        currentitem = ((r1)*size) + c1;;
                    }
                    break;
                case 75:   //  lift
                    if (c1 > 0)
                    {
                        c1--;
                        currentitem = ((r1)*size) + c1;
                    }
                    break;

                default:
                    printf("%i\n", c);

                }

                break;
            case 13:          //   Enter
                if (menuitem[r1][c1] != 'O' && menuitem[r1][c1] != 'X')
                {

                    system("cls");

                    if (c2 % 2 == 0)
                    {
                        printf("%c", x);
                        menuitem[r1][c1] = 'X';
                        c2++;
                    }
                    else
                    {
                        printf("%c", o);
                        menuitem[r1][c1] = 'O';
                        c2++;
                    }
                    for (int i = 0; i < size; i++)
                    {

                        if (menuitem[i][0] == 'X')
                        {
                            cxr1++;
                        }
                        else if (menuitem[i][0] == 'O')
                        {
                            cor1++;
                        }
                        if (menuitem[i][1] == 'X')
                        {
                            cxr2++;
                        }
                        else if (menuitem[i][1] == 'O')
                        {
                            cor2++;
                        }
                        if (menuitem[i][2] == 'X')
                        {
                            cxr3++;
                        }
                        else if (menuitem[i][2] == 'O')
                        {
                            cor3++;
                        }
                        for (int j = 0; j < size; j++)
                        {
                            if (menuitem[i][j] == 'X')
                            {
                                cxc++;
                            }
                            else if (menuitem[i][j] == 'O')
                            {
                                coc++;
                            }
                            if (menuitem[i][j] == 'X' && i == j)
                            {
                                mr++;
                            }
                            else if (menuitem[i][j] == 'O' && i == j)
                            {
                                ml++;
                            }

                            if (menuitem[i][j] == 'O' && i == 2 - j)
                            {
                                mo++;
                            }
                            else if (menuitem[i][j] == 'X' && i == 2 - j)
                            {
                                mx++;
                            }
                        }
                        if (cxc == 3 || cxr1 == 3 || cxr2 == 3 || cxr3 == 3 || mr == 3 || mx == 3)
                        {

                            x = 10;

                        }
                        else if (coc == 3 || cor1 == 3 || cor2 == 3 || cor3 == 3 || ml == 3 || mo == 3)
                        {
                            x = 15;
                        }
                        cxc = 0;
                        coc = 0;
                    }
                    cxc = 0, coc = 0, cxr1 = 0, cxr2 = 0, cxr3 = 0, cor1 = 0, cor2 = 0, cor3 = 0, ml = 0, mr = 0, mx = 0, mo = 0;
                    getch();
                }
                break;
            case 27:
                //  Exit
                quitfalg = 1;
                break;
            case 73:                   //pg up
                if (currentitem != 0)
                {
                    currentitem = 0;
                }
                break;
            case 81:                 //pg dn
                if (currentitem != 4)
                {
                    currentitem = (size * size) - 1;
                }
                break;

            default:
                printf("%i\n", c);

            }
        }

    } while (quitfalg != 1);
    return 0;
}
© 2021 GitHub,