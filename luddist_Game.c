#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define Aim 30
void About();
void HowToPlay();
void devloper();
void mainMenu();
// Generate Random Number
int autogenrate(int n)
{
    srand(time(NULL));
    return rand() % n;
}

// Store Players Information
struct luddist_Player
{
    char name[25];
    int score;
} p1, p2, p3, p4;

// Show Result With Players Names
void result()
{
    system("cls");
    if (p1.score >= Aim)
    {
        printf("\t\t\033[3;32m%s Completed Score. So his out of This Game\033[0;0m\n", p1.name);
    }
    if (p2.score >= Aim)
    {
        printf("\t\t\033[3;32m%s Completed Score. So his out of This Game\033[0;0m\n", p2.name);
    }
    if (p3.score >= Aim)
    {
        printf("\t\t\033[3;32m%s Completed Score. So his out of This Game\033[0;0m\n", p3.name);
    }
    if (p4.score >= Aim)
    {
        printf("\t\t\033[3;32m%s Completed Score. So his out of This Game\033[0;0m\n", p4.name);
    }

    printf("\n\n\t\t\t\033[3;34mLUDDIST GAME\033[0;0m");
    printf("\n\t---------------------------------------------\n");
    printf("\t\t\033[3;33mPlayers \t\t Score\033[0;0m\n");
    printf("\t\t%s \t\t\t %d\n\n", p1.name, p1.score);
    printf("\t\t%s \t\t\t %d\n\n", p2.name, p2.score);
    printf("\t\t%s \t\t\t %d\n\n", p3.name, p3.score);
    printf("\t\t%s \t\t\t %d\n", p4.name, p4.score);
    printf("\t---------------------------------------------\n");
}

// Functions for bit
void plr1(char nm1[15], char nm2[15])
{
    printf("\n\033[0;35m\t%s bitted to %s\n\n\033[0;0m", nm1, nm2);
}

void plr2(char nm1[15], char nm2[15])
{
    printf("\n\033[0;35m\t%s bitted to %s\n\n\033[0;0m", nm1, nm2);
}

void plr3(char nm1[15], char nm2[15])
{
    printf("\n\033[0;35m\t%s bitted to %s\n\n\033[0;0m", nm1, nm2);
}

void plr4(char nm1[15], char nm2[15])
{
    printf("\n\033[0;35m\t%s bitted to %s\n\n\033[0;0m", nm1, nm2);
}

// Final Result
void FinalResult(int a, int b, int c, int d)
{
    system("cls");
    printf("\n\033[3;44m\t\t\t\t\t    Final Result    \033[0;0m\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("\033[3;33m\t\t\tNAME   \t\tSCORE\033[0;0m\n\n");
    printf("\t\t\t%s\t\t%d\n\n", p1.name, p1.score);
    printf("\t\t\t%s\t\t%d\n\n", p2.name, p2.score);
    printf("\t\t\t%s\t\t%d\n\n", p3.name, p3.score);
    printf("\t\t\t%s\t\t%d\n\n", p4.name, p4.score);
    printf("\t\t--------------------------------------------------------------------\n");
    printf("\t\t\033[1;42m | MAIN MENU - M | \033[0;0m  \t\t\033[1;43m | PLAY AGAIN - P | \033[0;0m   \t\t\033[0;41m | EXIT - E | \033[0;0m\n");
fix1:
    scanf("%c", &c);
    switch (c)
    {
    case 'M':
        mainMenu();
        break;
    case 'E':
        system("cls");
        exit(0);
        break;
    case 'P':
        system("cls");
        p1.score = 0, p2.score = 0, p3.score = 0, p3.score = 0, p4.score = 0;
        main();
    default:
    printf("\t->");
        goto fix1;
        break;
    }
}

void check1(int a, int b, int c, int d);

//--------------------------
/*<----One Player Out---->*/
void firstout()
{
    char c;
    while (p2.score <= Aim && p3.score <= Aim && p4.score <= Aim)
    {

        printf("\t Turn of %s:\n", p2.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p2.score = p2.score + (autogenrate(6) + 1);

        if (p2.score == p3.score)
        {
            p3.score = 0;
            result();
            plr3(p2.name, p3.name);
        }
        else if (p2.score == p4.score)
        {
            p4.score = 0;
            result();
            plr4(p2.name, p4.name);
        }
        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p3.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p3.score = p3.score + (autogenrate(6) + 1);
        if (p3.score == p2.score)
        {
            p2.score = 0;
            result();
            plr2(p3.name, p2.name);
        }

        else if (p3.score == p4.score)
        {
            p4.score = 0;
            result();
            plr4(p3.name, p4.name);
        }
        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p4.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p4.score = p4.score + (autogenrate(6) + 1);
        if (p4.score == p2.score)
        {
            p2.score = 0;
            result();
            plr2(p4.name, p2.name);
        }
        else if (p4.score == p3.score)
        {
            p3.score = 0;
            result();
            plr3(p4.name, p3.name);
        }

        else
        {
            printf("\n");
            result();
        }
    }
    check1(p1.score, p2.score, p3.score, p4.score);
}

void secondout()
{
    char c;
    while (p1.score <= Aim && p3.score <= Aim && p4.score <= Aim)
    {
        printf("\t Turn of %s", p1.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p1.score = p1.score + (autogenrate(6) + 1);
        if (p1.score == p3.score)
        {
            p3.score = 0;
            result();
            plr3(p1.name, p3.name);
        }
        else if (p1.score == p4.score)
        {
            p4.score = 0;
            result();
            plr4(p1.name, p4.name);
        }
        else
        {
            printf("\n");
            result();
        }

        printf("\t Turn of %s:\n", p3.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p3.score = p3.score + (autogenrate(6) + 1);
        if (p3.score == p1.score)
        {
            p1.score = 0;
            result();
            plr1(p3.name, p1.name);
        }
        else if (p3.score == p4.score)
        {
            p4.score = 0;
            result();
            plr4(p3.name, p4.name);
        }
        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p4.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p4.score = p4.score + (autogenrate(6) + 1);
        if (p4.score == p3.score)
        {
            p3.score = 0;
            result();
            plr3(p4.name, p3.name);
        }
        else if (p4.score == p1.score)
        {
            p1.score = 0;
            result();
            plr1(p4.name, p1.name);
        }
        else
        {
            printf("\n");
            result();
        }
    }
    check1(p1.score, p2.score, p3.score, p4.score);
}

void thirdout()
{
    char c;
    while (p1.score <= Aim && p2.score <= Aim && p4.score <= Aim)
    {
        printf("\t Turn of %s:\n", p1.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p1.score = p1.score + (autogenrate(6) + 1);
        if (p1.score == p2.score)
        {
            p2.score = 0;
            result();
            plr2(p1.name, p2.name);
        }
        else if (p1.score == p4.score)
        {
            p4.score = 0;
            result();
            plr4(p1.name, p4.name);
        }
        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p2.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p2.score = p2.score + (autogenrate(6) + 1);
        if (p2.score == p1.score)
        {
            p1.score = 0;
            result();
            plr1(p2.name, p1.name);
        }
        else if (p2.score == p4.score)
        {
            p4.score = 0;
            result();
            plr4(p2.name, p4.name);
        }
        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p4.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p4.score = p4.score + (autogenrate(6) + 1);
        if (p4.score == p2.score)
        {
            p2.score = 0;
            result();
            plr2(p4.name, p2.name);
        }

        else if (p4.score == p1.score)
        {
            p1.score = 0;
            result();
            plr1(p4.name, p1.name);
        }
        else
        {
            printf("\n");
            result();
        }
    }
    check1(p1.score, p2.score, p3.score, p4.score);
}

void fourthout()
{
    char c;
    while (p1.score <= Aim && p2.score <= Aim && p3.score <= Aim)
    {
        printf("\t Turn of %s:\n", p1.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p1.score = p1.score + (autogenrate(6) + 1);
        if (p1.score == p2.score)
        {
            p2.score = 0;
            result();
            plr2(p1.name, p2.name);
        }
        else if (p1.score == p3.score)
        {
            p3.score = 0;
            result();
            plr3(p1.name, p3.name);
        }
        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p2.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p2.score = p2.score + (autogenrate(6) + 1);
        if (p2.score == p1.score)
        {
            p1.score = 0;
            result();
            plr1(p2.name, p1.name);
        }
        else if (p2.score == p3.score)
        {
            p3.score = 0;
            result();
            plr3(p2.name, p3.name);
        }
        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p3.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p3.score = p3.score + (autogenrate(6) + 1);
        if (p3.score == p2.score)
        {
            p2.score = 0;
            result();
            plr2(p3.name, p2.name);
        }
        else if (p3.score == p1.score)
        {
            p1.score = 0;
            result();
            plr1(p3.name, p1.name);
        }
        else
        {
            printf("\n");
            result();
        }
    }
    check1(p1.score, p2.score, p3.score, p4.score);
}

//--------------------------

//-------------------------
// Fuction for one Players Out
void check(int a, int b, int c, int d)
{
    if (a > b && a > c && a > d)
    {
        firstout();
    }
    else if (b > a && b > c && b > d)
    {
        secondout();
    }
    else if (c > a && c > b && c > d)
    {
        thirdout();
    }
    else if (d > a && d > c && d > b)
    {
        fourthout();
    }
    else
    {
        printf("\n Match Is Draw");
    }
}
//--------------------

//------Two Players Out-------------
//----------------------------------
void FirstAndSecondOut()
{
    char c;
    while (p3.score <= Aim && p4.score <= Aim)
    {

        printf("\t Turn of %s:\n", p3.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p3.score = p3.score + (autogenrate(6) + 1);
        if (p3.score == p4.score)
        {
            p4.score = 0;
            result();
            plr4(p3.name, p4.name);
        }
        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p4.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p4.score = p4.score + (autogenrate(6) + 1);
        if (p4.score == p3.score)
        {
            p3.score = 0;
            result();
            plr3(p4.name, p3.name);
        }
        else
        {
            printf("\n");
            result();
        }
    }
    FinalResult(p1.score, p2.score, p3.score, p4.score);
}
void FirstAndThirdOut()
{
    char c;
    while (p2.score <= Aim && p4.score <= Aim)
    {

        printf("\t Turn of %s:\n", p2.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p2.score = p2.score + (autogenrate(6) + 1);
        if (p2.score == p4.score)
        {
            p4.score = 0;
            result();
            plr4(p2.name, p4.name);
        }
        else
        {
            printf("\n");
            result();
        }

        printf("\t Turn of %s:\n", p4.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p4.score = p4.score + (autogenrate(6) + 1);
        if (p4.score == p2.score)
        {
            p2.score = 0;
            result();
            plr2(p4.name, p2.name);
        }
        else
        {
            printf("\n");
            result();
        }
    }
    FinalResult(p1.score, p2.score, p3.score, p4.score);
}
void FirstAndFourthOut()
{
    char c;
    while (p2.score <= Aim && p3.score <= Aim)
    {
        printf("\t Turn of %s:\n", p2.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p2.score = p2.score + (autogenrate(6) + 1);
        if (p2.score == p3.score)
        {
            p3.score = 0;
            result();
            plr3(p2.name, p3.name);
        }

        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p3.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p3.score = p3.score + (autogenrate(6) + 1);
        if (p3.score == p2.score)
        {
            p2.score = 0;
            result();
            plr2(p3.name, p2.name);
        }
        else
        {
            printf("\n");
            result();
        }
    }
    FinalResult(p1.score, p2.score, p3.score, p4.score);
}
void SecondAndThirdOut()
{
    char c;
    while (p1.score <= Aim && p4.score <= Aim)
    {
        printf("\t Turn of %s:\n", p1.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p1.score = p1.score + (autogenrate(6) + 1);
        if (p1.score == p4.score)
        {
            p4.score = 0;
            result();
            plr4(p1.name, p4.name);
        }
        else
        {
            printf("\n");
            result();
        }

        printf("\t Turn of %s:\n", p4.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p4.score = p4.score + (autogenrate(6) + 1);
        if (p4.score == p1.score)
        {
            p1.score = 0;
            result();
            plr1(p4.name, p1.name);
        }
        else
        {
            printf("\n");
            result();
        }
    }
    FinalResult(p1.score, p2.score, p3.score, p4.score);
}
void SecondAndFourthOut()
{
    char c;
    while (p1.score <= Aim && p3.score <= Aim)
    {
        printf("\t Turn of %s:\n", p1.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p1.score = p1.score + (autogenrate(6) + 1);
        if (p1.score == p3.score)
        {
            p3.score = 0;
            result();
            plr3(p1.name, p3.name);
        }

        else
        {
            printf("\n");
            result();
        }

        printf("\t Turn of %s:\n", p3.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p3.score = p3.score + (autogenrate(6) + 1);
        if (p3.score == p1.score)
        {
            p1.score = 0;
            result();
            plr1(p3.name, p1.name);
        }

        else
        {
            printf("\n");
            result();
        }
    }
    FinalResult(p1.score, p2.score, p3.score, p4.score);
}
void FourthAndThirdOut()
{
    char c;
    while (p1.score <= Aim && p2.score <= Aim)
    {
        printf("\t Turn of %s:\n", p1.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p1.score = p1.score + (autogenrate(6) + 1);
        if (p1.score == p2.score)
        {
            p2.score = 0;
            result();
            plr2(p1.name, p2.name);
        }

        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p2.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p2.score = p2.score + (autogenrate(6) + 1);
        if (p2.score == p1.score)
        {
            p1.score = 0;
            result();
            plr1(p2.name, p1.name);
        }

        else
        {
            printf("\n");
            result();
        }
    }
    FinalResult(p1.score, p2.score, p3.score, p4.score);
}
// --------------------------

//<--------------------------->
// Fuction for two Players Out
void check1(int a, int b, int c, int d)
{
    if (a > c && a > d && b > c && b > d)
    {
        FirstAndSecondOut();
    }
    else if (a > b && a > d && c > b && c > d)
    {
        FirstAndThirdOut();
    }
    else if (a > b && a > c && d > b && d > c)
    {
        FirstAndFourthOut();
    }
    else if (b > a && b > d && c > a && c > d)
    {
        SecondAndThirdOut();
    }
    else if (b > a && b > c && d > a && d > c)
    {
        SecondAndFourthOut();
    }
    else if (d > b && d > a && c > b && c > a)
    {
        FourthAndThirdOut();
    }
    else
    {
        printf("Both Are Equal");
    }
}
//--------------------------
/*<----------->*/

// Main Function
int main()
{
    int b, d = 0, e = 0, f = 0, g = 0;
    char c;
    mainMenu();
start:
    system("cls");
    printf("\n\n\t\tEnter the name of palyer 1:  "); // Enter Players Names
    scanf("%s", &p1.name);
    printf("\n\t\tEnter the name of palyer 2:  ");
    scanf("%s", &p2.name);
    printf("\n\t\tEnter the name of palyer 3:  ");
    scanf("%s", &p3.name);
    printf("\n\t\tEnter the name of palyer 4:  ");
    scanf("%s", &p4.name);
    // Toss  Section
    system("cls");
    printf("\033[0;33m\n\t\tTossing.....\n\033[0;0m");
    Sleep(998);
    b = autogenrate(4);
    if (b == 0)
    {
        system("cls");
        printf("\n\t\t\033[3;33m%s Win The Toss.\n\033[0;0m", p1.name);
        printf("\t\tPlease Wait.....\n");
        Sleep(9910);
        goto case1;
    }
    else if (b == 1)
    {
        system("cls");
        printf("\n\t\t\033[3;33m%s Win The Toss.\n\033[0;0m", p2.name);
        printf("\t\tPlease Wait.....\n");
        Sleep(9910);
        goto case2;
    }
    else if (b == 3)
    {
        system("cls");
        printf("\n\t\t\033[3;33m%s Win The Toss.\n\033[0;0m", p3.name);
        printf("\t\tPlease Wait.....\n");
        Sleep(9910);
        goto case3;
    }
    else
    {
        system("cls");
        printf("\n\t\t\033[3;33m%s Win The Toss.\n\033[0;0m", p4.name);
        printf("\t\tPlease Wait.....\n");
        Sleep(9910);
        goto case4;
    }

    // First  Turn of Player 1
case1:
    system("cls");
    result();
    printf("\t\t%s Turn.\n", p1.name);
    while (p1.score <= Aim && p2.score <= Aim && p3.score <= Aim && p4.score <= Aim)
    {

        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p1.score = p1.score + (autogenrate(6) + 1);
        if (p1.score == p2.score)
        {
            p2.score = 0;
            result();
            plr2(p1.name, p2.name);
        }
        else if (p1.score == p3.score)
        {
            p3.score = 0;
            result();
            plr3(p1.name, p3.name);
        }
        else if (p1.score == p4.score)
        {
            p4.score = 0;
            result();
            plr4(p1.name, p4.name);
        }
        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p2.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p2.score = p2.score + (autogenrate(6) + 1);
        if (p2.score == p1.score)
        {
            p1.score = 0;
            result();
            plr1(p2.name, p1.name);
        }
        else if (p2.score == p3.score)
        {
            p3.score = 0;
            result();
            plr3(p2.name, p3.name);
        }
        else if (p2.score == p4.score)
        {
            p4.score = 0;
            result();
            plr4(p2.name, p4.name);
        }
        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p3.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p3.score = p3.score + (autogenrate(6) + 1);
        if (p3.score == p2.score)
        {
            p2.score = 0;
            result();
            plr2(p3.name, p2.name);
        }
        else if (p3.score == p1.score)
        {
            p1.score = 0;
            result();
            plr1(p3.name, p1.name);
        }
        else if (p3.score == p4.score)
        {
            p4.score = 0;
            result();
            plr4(p3.name, p4.name);
        }
        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p4.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p4.score = p4.score + (autogenrate(6) + 1);
        if (p4.score == p2.score)
        {
            p2.score = 0;
            result();
            plr2(p4.name, p2.name);
        }
        else if (p4.score == p3.score)
        {
            p3.score = 0;
            result();
            plr3(p4.name, p3.name);
        }
        else if (p4.score == p1.score)
        {
            p1.score = 0;
            result();
            plr1(p4.name, p1.name);
        }
        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p1.name);
    }
    check(p1.score, p2.score, p3.score, p4.score);
    goto end;

    // First Turn of Player 2
case2:
    system("cls");
    result();
    printf("\t\t%s Turn.\n", p2.name);
    while (p1.score <= Aim && p2.score <= Aim && p3.score <= Aim && p4.score <= Aim)
    {
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p2.score = p2.score + (autogenrate(6) + 1);
        if (p2.score == p1.score)
        {
            p1.score = 0;
            result();
            plr1(p2.name, p1.name);
        }
        else if (p2.score == p3.score)
        {
            p3.score = 0;
            result();
            plr3(p2.name, p3.name);
        }
        else if (p2.score == p4.score)
        {
            p4.score = 0;
            result();
            plr4(p2.name, p4.name);
        }
        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p3.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p3.score = p3.score + (autogenrate(6) + 1);
        if (p3.score == p2.score)
        {
            p2.score = 0;
            result();
            plr2(p3.name, p2.name);
        }
        else if (p3.score == p1.score)
        {
            p1.score = 0;
            result();
            plr1(p3.name, p1.name);
        }
        else if (p3.score == p4.score)
        {
            p4.score = 0;
            result();
            plr4(p3.name, p4.name);
        }
        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p4.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p4.score = p4.score + (autogenrate(6) + 1);
        if (p4.score == p2.score)
        {
            p2.score = 0;
            result();
            plr2(p4.name, p2.name);
        }
        else if (p4.score == p3.score)
        {
            p3.score = 0;
            result();
            plr3(p4.name, p3.name);
        }
        else if (p4.score == p1.score)
        {
            p1.score = 0;
            result();
            plr1(p4.name, p1.name);
        }
        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p1.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p1.score = p1.score + (autogenrate(6) + 1);
        if (p1.score == p2.score)
        {
            p2.score = 0;
            result();
            plr2(p1.name, p2.name);
        }
        else if (p1.score == p3.score)
        {
            p3.score = 0;
            result();
            plr3(p1.name, p3.name);
        }
        else if (p1.score == p4.score)
        {
            p4.score = 0;
            result();
            plr4(p1.name, p4.name);
        }
        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p2.name);
    }
    check(p1.score, p2.score, p3.score, p4.score);
    goto end;

    // First Turn of Player 3
case3:
    system("cls");
    result();
    printf("\t\t%s Turn.\n", p3.name);
    while (p1.score <= Aim && p2.score <= Aim && p3.score <= Aim && p4.score <= Aim)
    {
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p3.score = p3.score + (autogenrate(6) + 1);
        if (p3.score == p2.score)
        {
            p2.score = 0;
            result();
            plr2(p3.name, p2.name);
        }
        else if (p3.score == p1.score)
        {
            p1.score = 0;
            result();
            plr1(p3.name, p1.name);
        }
        else if (p3.score == p4.score)
        {
            p4.score = 0;
            result();
            plr4(p3.name, p4.name);
        }
        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p4.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p4.score = p4.score + (autogenrate(6) + 1);
        if (p4.score == p2.score)
        {
            p2.score = 0;
            result();
            plr2(p4.name, p2.name);
        }
        else if (p4.score == p3.score)
        {
            p3.score = 0;
            result();
            plr3(p4.name, p3.name);
        }
        else if (p4.score == p1.score)
        {
            p1.score = 0;
            result();
            plr1(p4.name, p1.name);
        }
        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p1.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p1.score = p1.score + (autogenrate(6) + 1);
        if (p1.score == p2.score)
        {
            p2.score = 0;
            result();
            plr2(p1.name, p2.name);
        }
        else if (p1.score == p3.score)
        {
            p3.score = 0;
            result();
            plr3(p1.name, p3.name);
        }
        else if (p1.score == p4.score)
        {
            p4.score = 0;
            result();
            plr4(p1.name, p4.name);
        }
        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p2.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p2.score = p2.score + (autogenrate(6) + 1);
        if (p2.score == p1.score)
        {
            p1.score = 0;
            result();
            plr1(p2.name, p1.name);
        }
        else if (p2.score == p3.score)
        {
            p3.score = 0;
            result();
            plr3(p2.name, p3.name);
        }
        else if (p2.score == p4.score)
        {
            p4.score = 0;
            result();
            plr4(p2.name, p4.name);
        }
        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p3.name);
    }
    check(p1.score, p2.score, p3.score, p4.score);
    goto end;

    // First Turn of Player 4
case4:
    system("cls");
    result();
    printf("\t\t%s Turn.\n", p4.name);
    while (p1.score <= Aim && p2.score <= Aim && p3.score <= Aim && p4.score <= Aim)
    {
        printf("\t\tplease press the * \n");
        scanf("%c", &c);
        getchar();
        p4.score = p4.score + (autogenrate(6) + 1);
        if (p4.score == p2.score)
        {
            p2.score = 0;
            result();
            plr2(p4.name, p2.name);
        }
        else if (p4.score == p3.score)
        {
            p3.score = 0;
            result();
            plr3(p4.name, p3.name);
        }
        else if (p4.score == p1.score)
        {
            p1.score = 0;
            result();
            plr1(p4.name, p1.name);
        }
        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p1.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p1.score = p1.score + (autogenrate(6) + 1);
        if (p1.score == p2.score)
        {
            p2.score = 0;
            result();
            plr2(p1.name, p2.name);
        }
        else if (p1.score == p3.score)
        {
            p3.score = 0;
            result();
            plr3(p1.name, p3.name);
        }
        else if (p1.score == p4.score)
        {
            p4.score = 0;
            result();
            plr4(p1.name, p4.name);
        }
        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p2.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p2.score = p2.score + (autogenrate(6) + 1);
        if (p2.score == p1.score)
        {
            p1.score = 0;
            result();
            plr1(p2.name, p1.name);
        }
        else if (p2.score == p3.score)
        {
            p3.score = 0;
            result();
            plr3(p2.name, p3.name);
        }
        else if (p2.score == p4.score)
        {
            p4.score = 0;
            result();
            plr4(p2.name, p4.name);
        }
        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p3.name);
        printf("\t\tplease press the *\n");
        scanf("%c", &c);
        getchar();
        p3.score = p3.score + (autogenrate(6) + 1);
        if (p3.score == p2.score)
        {
            p2.score = 0;
            result();
            plr2(p3.name, p2.name);
        }
        else if (p3.score == p1.score)
        {
            p1.score = 0;
            result();
            plr1(p3.name, p1.name);
        }
        else if (p3.score == p4.score)
        {
            p4.score = 0;
            result();
            plr4(p3.name, p4.name);
        }

        else
        {
            printf("\n");
            result();
        }
        printf("\t Turn of %s:\n", p4.name);
    }
    check(p1.score, p2.score, p3.score, p4.score);

end:
    return 0;
}

//----- About Here ---
void About()
{
    char c;
    system("cls");
    printf("\n\033[3;44m\t\t\t   ABOUT OF THIS GAME   \n\033[0;0m\n");
    printf("\t-----------------------------------------------------------------------------------------------------------\n");
    printf("\t1.\tThis game is similar in concept to the game of Luddo.\n  \t\tWhich is made in C language. and C libraries.\n\n");
    printf("\n\t2.\tThere will be four players in this game.\n  \t\tAnd in this game all the four players have to make their score 30.\n  \t\tAnd the player who first makes his score 30 will be in first place in this game.\n  \t\tAnd then the game will continue between the remaining three players.\n  \t\tNow whichever player out of these three will first score 30, he will be in second place in this game.\n  \t\tAnd again the game will continue like this. And the player who comes in fourth place will lose the game.\n\n");
    printf("\n\t3.\tIf two consecutive players have the same score, the first player scores zero,\n  \t\tand the second player scores the same score as the first player.\n  \t\tFor example, a player's score is x, and the player immediately following it's turn also has a score of x,\n  \t\tthen the player preceding it has a score of 0, and its score will remain x.\n\n");
    printf("\t-----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\033[1;42m | MAIN MENU - M | \033[0;0m    \t\t\t\033[0;41m | EXIT - E | \033[0;0m\n");
fix2:
    scanf("%c", &c);
    switch (c)
    {
    case 'M':
        mainMenu();
        break;
    case 'E':
        system("cls");
        exit(0);
        break;
    default:
        printf("\t->");
        goto fix2;
        break;
    }
}
//------------

//----Main Menu----
void mainMenu()
{
    system("cls");
    char c;
    printf("\n\033[3;43m\t\t\t\t\t    WELCOME TO LUDDIST GAME    \033[0;0m\n");
    printf("\t-----------------------------------------------------------------------------------------------------------\n\n");
    printf("\t\t\t\t\t\t\033[0;36m|  PLAY - P |\033[0;0m\n\n\t\t\t\t\t\t\033[0;36m|  HOW TO PLAY - H |\033[0;0m\n\n\t\t\t\t\t\t\033[0;36m|  ABOUT OF GAME - A |\033[0;0m\n\n\t\t\t\t\t\t\033[0;36m|  DEVLOPER - D |\033[0;0m\n\n\t\t\t\t\t\t\t\t\t\t\t\033[0;41m | EXIT - E | \033[0;0m\n");
    printf("\t-----------------------------------------------------------------------------------------------------------\n");
fix:
    scanf("%c", &c);
    switch (c)
    {
    case 'P':
        goto play;
        break;
    case 'H':
        HowToPlay();
        break;
    case 'A':
        About();
        break;
    case 'D':
        devloper();
        break;
    case 'E':
        system("cls");
        exit(0);
        break;
    default:
        printf("\t->");
        goto fix;
        break;
    }
play:
    printf("lets go to play");
}

//---------- How To Play -----
void HowToPlay()
{
    char c;
    system("cls");
    printf("\n\033[3;44m\t\t\t\t   HOW TO PLAY   \n\033[0;0m\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("\t\t\t1. First of all Enter four players name one by one.\n\n\n\t\t\t2. Then after tossing one by one players turn and press star for your turn\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("\t\t\t\033[1;42m | MAIN MENU - M | \033[0;0m    \t\t\t\033[0;41m | EXIT - E | \033[0;0m\n");

fix3:
    scanf("%c", &c);
    switch (c)
    {
    case 'M':
        mainMenu();
        break;
    case 'E':
        system("cls");
        exit(0);
        break;
    default:
        printf("\t->");
        goto fix3;
        break;
    }
}
//----------------------

//--------- Devloper--------
void devloper()
{
    char c;
    system("cls");
    printf("\n\033[3;44m\t\t\t\t\t    Devlopers    \033[0;0m\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("\033[3;33m\t\t\tNAME          \t\tROLL NUMBER \t\tREGISTRATION NUMBER\033[0;0m\n\n");
    printf("\t\t\tAshutosh Kumar\t\t224CA015    \t\t2240063\n\n");
    printf("\t\t\tROHIT Kumar   \t\t224CA066    \t\t-------\n\n");
    printf("\t\t\tAmit Kumar    \t\t224CA010    \t\t2240064\n\n");
    printf("\t\t\tRamveer       \t\t224CA065    \t\t-------\n\n");
    printf("\t\t--------------------------------------------------------------------\n");
    printf("\t\t\t\033[1;42m | MAIN MENU - M | \033[0;0m    \t\t\t\033[0;41m | EXIT - E | \033[0;0m\n");
fix1:
    scanf("%c", &c);
    switch (c)
    {
    case 'M':
        mainMenu();
        break;
    case 'E':
        system("cls");
        exit(0);
        break;
    default:
        printf("\t->");
        goto fix1;
        break;
    }
}