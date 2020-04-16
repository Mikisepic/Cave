#define _XOPEN_SOURCE

#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <stdlib.h>
#include <unistd.h>
#include <cs50.h>
#include <time.h>
#include <string.h>

#include "cave_mobs.c"

int main(int argc, char *argv[])
{
    int enemies;
    char choice;

    srand(time(NULL));

    hero.hp = 100;
    hero.dmg = 14;

    int fleur = 0;

    char enter = 0;
    openFiles("logo.txt");
    while (enter != '\n' && enter != '\r')
    {
        enter = getchar();
    }
    clear();

    for (int i = 0; i < 4; i++)
    {
        if(fleur == 0)
        {
            slimeMob();
            fleur++;
        }
        else if(fleur == 1)
        {
            for (int j = 0; j < 1; j++)
            {
                enemies = rand () % 2; // types of enemies
            }

            if (enemies == 0)
            {
                //slimeMob();
                hugeRatMob();
            }

            else if (enemies == 1)
            {
                hugeRatMob();
            }
            fleur++;
        }

        else if(fleur == 2)
        {
            for (int j = 0; j < 1; j++)
            {
                enemies = rand () % 2; // types of enemies
            }

            if (enemies == 0)
            {
                armorMob();
            }

            else if (enemies == 1)
            {
                armorMob();
                //hugeRatMob();
            }
            fleur++;
        }

        else if(fleur == 3)
        {
            for (int j = 0; j < 1; j++)
            {
                enemies = rand () % 3; // types of enemies
            }

            if (enemies == 0)
            {
                golemMob();
            }

            else if (enemies == 1)
            {
                golemMob();
                //hugeRatMob();
            }

            else if (enemies == 2)
            {
                heavyArmorMob();
            }
            fleur++;
        }

        else if(fleur == 4)
        {
            for (int j = 0; j < 1; j++)
            {
                enemies = rand () % 3; // types of enemies
            }

            if (enemies == 0)
            {
                cultistMob();
            }

            else if (enemies == 1)
            {
                cultistMob();
                //hugeRatMob();
            }

            else if (enemies == 2)
            {
                shadowMob();
            }
            fleur++;
        }

        else if(fleur == 5)
        {
            bossFightWorm();

            hero.hp = 100;
        }
    }
    return 0;
}

void clear()
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}