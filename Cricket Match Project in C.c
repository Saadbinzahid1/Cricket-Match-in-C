#include <stdio.h>
#include <string.h>

struct team
{
    char name[50];
    int truns;
    int extras;
    int wides;
    int noballs;
    int boundary4;
    int boundary6;
};

struct ball
{
    int runs[20][6];
    char status[20][6];
};

// Structure for Match Details
struct matchdata
{
    char team1name[50];
    char team2name[50];
    char team1players[11][50];
    char team2players[11][50];
    char winner[50];
    char manofthematch[50];
};

// Input Names
void input(char a[][50], int n, char b[])
{
    printf("Enter Team %d Name:", n);
    gets(b);
    for (int i = 0; i < 11; i++)
    {
        printf("Enter Player %d Name of Team %d:", i + 1, n);
        gets(a[i]);
    }
}

// Output Batting Team Names
void outputbat(char a[][50])
{
    printf("\nBatting Team Player Names:");
    for (int i = 0; i < 11; i++)
        printf("\n%d: %s", i + 1, a[i]);
}

// Output Bowling Team Names
void outputbowl(char a[][50])
{
    printf("\nBowling Team Player Names:");
    for (int i = 0; i < 11; i++)
        printf("\n%d: %s", i + 1, a[i]);
}

// Handling Toss
int toss(void)
{
    char ch, toss, tossresult;
    printf("Team 1 Choose Head or Tail(H for head and T for tail):");
    scanf(" %c", &toss);
    while (toss != 'H' && toss != 'T')
    {
        printf("Enter choice correctly:");
        scanf(" %c", &toss);
    }
    printf("What is the result (H or T):");
    scanf(" %c", &tossresult);
    while (tossresult != 'H' && tossresult != 'T')
    {
        printf("Enter toss result correctly:");
        scanf(" %c", &tossresult);
    }
    if (toss == tossresult)
    {
        printf("Team 1 won the toss!");
        return 1;
    }
    else
    {
        printf("Team 2 won the toss!");
        return 2;
    }
}

// Displaying Remaining Players of Batting Team
void displayremplayers(char a[][50], int b[], int k, int nonstriker)
{
    printf("\nRemaining Player Names:");
    for (int i = 0; i < 11; i++)
    {
        int flag = 0;
        for (int j = 0; j <= k; j++)
        {
            if (i == b[j])
            {
                flag = 1;
                break;
            }
        }
        if (i == nonstriker)
            flag = 1;
        if (flag == 0)
            printf("\n%d: %s", i + 1, a[i]);
    }
}

// inning Function
void inning(struct team *bat, struct team *bowl, char batnames[][50], char bowlnames[][50], int batsmanruns[], int inn)
{
}

// Finding Man Of The Match
int manofthematch(int batsmanruns[])
{
}

// Save Match Details to a File
void savematchdata(struct team t1, struct team t2, char team1[][50], char team2[][50], char *winner, char *manofthematch)
{
}

// Read Match Data from File
void readfromfile()
{
}

int main()
{
    char team1[11][50];
    char team2[11][50];
    struct team t1;
    struct team t2;
    char matchchoice;
    printf("Do you want to organize match?(y or n)");
    scanf("%c", &matchchoice);
    getchar();
    while (matchchoice == 'y' || matchchoice == 'Y')
    {
        t1.truns = 0;
        t1.extras = 0;
        t1.wides = 0;
        t1.noballs = 0;
        t1.boundary4 = 0;
        t1.boundary6 = 0;
        t2.truns = 0;
        t2.extras = 0;
        t2.wides = 0;
        t2.noballs = 0;
        t2.boundary4 = 0;
        t2.boundary6 = 0;

        // Inputting Names
        input(team1, 1, t1.name);
        input(team2, 2, t2.name);

        // Handling Toss
        int result = toss();
        char choice;
        int batsmanruns1[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int batsmanruns2[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int man;
        if (result == 1)
        {
            printf("\nWould %s like to bat or field (B/F): ", t1.name);
            scanf(" %c", &choice);

            // If Team 1 Chooses Batting
            if (choice == 'B')
            {
                // 1st Inning (Team 1 Batting)
                inning(&t1, &t2, team1, team2, batsmanruns1, 1);

                // 2nd Inning(Team 2 Batting)
                inning(&t2, &t1, team2, team1, batsmanruns2, 1);

                // Match Result
                if (t1.truns > t2.truns)
                {
                    printf("\n%s wins the match!!", t1.name);
                    man = manofthematch(batsmanruns1);
                    printf("\nMan of the Match: %s", team1[man]);
                    savematchdata(t1, t2, team1, team2, t1.name, team1[man]);
                }
                else if (t2.truns > t1.truns)
                {
                    printf("\n%s wins the match!!", t2.name);
                    man = manofthematch(batsmanruns2);
                    printf("\nMan of the Match: %s", team2[man]);
                    savematchdata(t1, t2, team1, team2, t2.name, team2[man]);
                }
                else
                {
                    printf("\nMatch Draw!!");
                    savematchdata(t1, t2, team1, team2, "Draw", "None");
                }
            }

            // If Team 1 Chooses Bowling
            else if (choice == 'F')
            {
                // 1st Inning (Team 2 Batting)
                inning(&t2, &t1, team2, team1, batsmanruns2, 1);

                // 2nd Inning(Team 1 Batting)
                inning(&t1, &t2, team1, team2, batsmanruns1, 2);

                // Match Result
                if (t1.truns > t2.truns)
                {
                    printf("\n%s wins the match!!", t1.name);
                    man = manofthematch(batsmanruns1);
                    printf("\nMan of the Match: %s", team1[man]);
                    savematchdata(t1, t2, team1, team2, t1.name, team1[man]);
                }
                else if (t2.truns > t1.truns)
                {
                    printf("\n%s wins the match!!", t2.name);
                    man = manofthematch(batsmanruns2);
                    printf("\nMan of the Match: %s", team2[man]);
                    savematchdata(t1, t2, team1, team2, t2.name, team2[man]);
                }
                else
                {
                    printf("\nMatch Draw!!");
                    savematchdata(t1, t2, team1, team2, "Draw", "None");
                }
            }
        }

        // If Team 2 Wins The Toss
        else if (result == 2)
        {
            printf("\nWould %s like to bat or field (B/F)!", t2.name);
            scanf(" %c", &choice);

            // If Team 2 Chooses Batting
            if (choice == 'B')
            {
                // 1st Inning (Team 2 Batting)
                inning(&t2, &t1, team2, team1, batsmanruns2, 1);

                // 2nd Inning(Team 1 Batting)
                inning(&t1, &t2, team1, team2, batsmanruns1, 2);

                // Match Result
                if (t1.truns > t2.truns)
                {
                    printf("\n%s wins the match!!", t1.name);
                    man = manofthematch(batsmanruns1);
                    printf("\nMan of the Match: %s", team1[man]);
                    savematchdata(t1, t2, team1, team2, t1.name, team1[man]);
                }
                else if (t2.truns > t1.truns)
                {
                    printf("\n%s wins the match!!", t2.name);
                    man = manofthematch(batsmanruns2);
                    printf("\nMan of the Match: %s", team2[man]);
                    savematchdata(t1, t2, team1, team2, t2.name, team2[man]);
                }
                else
                {
                    printf("\nMatch Draw!!");
                    savematchdata(t1, t2, team1, team2, "Draw", "None");
                }
            }

            // If Team 2 Chooses Bowling
            else if (choice == 'F')
            {
                // 1st Inning (Team 1 Batting)
                inning(&t1, &t2, team1, team2, batsmanruns1, 1);

                // 2nd Inning(Team 2 Batting)
                inning(&t2, &t1, team2, team1, batsmanruns2, 2);

                // Match Result
                if (t1.truns > t2.truns)
                {
                    printf("\n%s wins the match!!", t1.name);
                    man = manofthematch(batsmanruns1);
                    printf("\nMan of the Match: %s", team1[man]);
                    savematchdata(t1, t2, team1, team2, t1.name, team1[man]);
                }
                else if (t2.truns > t1.truns)
                {
                    printf("\n%s wins the match!!", t2.name);
                    man = manofthematch(batsmanruns2);
                    printf("\nMan of the Match: %s", team2[man]);
                    savematchdata(t1, t2, team1, team2, t2.name, team2[man]);
                }
                else
                {
                    printf("\nMatch Draw!!");
                    savematchdata(t1, t2, team1, team2, "Draw", "None");
                }
            }
        }
        printf("\nDo you want to organize another match?(y or n)");
        scanf(" %c", &matchchoice);
        getchar();
    }
}