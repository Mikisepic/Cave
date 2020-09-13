#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "cave_header.h"
#include "cave_loot.c"

int type = 0;
char option[1];

void defence(int *hp, int *dmg, int *block);
void attack(int *hp, int *dmg, int *block, int *hp1, int *dmg1, int *block1);
void special(int *hp, int *dmg, int *block, int *hp1, int *dmg1, int *block1);
void openFiles(char *name);

void slimeMob()
{
    slime.hp = 30, slime.dmg = 10, slime.block = 0; //slime struct

    srand(time(NULL));

    bool debuff = false;
    int counter = 0;

    printf("\nYour are attacked by a gooey slime\n");

    sleep(1);

    do
    {
        clear();

        if (debuff == true)
        {
            counter--;
            if (counter <= 0)
            {
                debuff = false;
                hero.dmg /= 0.5;
            }
            for (int i = 0; i < 1; i++)
            {
                slime.atk = rand() % 2;
            }
        }
        else if (debuff == false)
        {
            for (int i = 0; i < 1; i++)
            {
                slime.atk = rand() % 3;
            }
        }

        sleep(1);

        if (slime.atk == 0)
        {
            printf("\nIt redies itself to spit at you, [10 dmg]\n");
            slime.dmg = 10;
        }

        else if (slime.atk == 1)
        {
            printf("\nYou see little slimy tendrils emerge from its slimy body, [5 x 3 dmg]\n");
            slime.dmg = 15;
        }

        else if (slime.atk == 2)
        {
            printf("\nYou got covered in slime and do 2x less dmg for 2 turns\n");
            hero.dmg *= 0.5;
            slime.dmg = 0;
            debuff = true;
            counter = 2;
        }

        sleep(1);
        printf("\n");

        openFiles("sprites/slime.txt");

        printf("\n\nSWORD:[%s]      SHIELDS:[%s]        SPECIALS:[%s]\n\n", item0, item1, item2);
    OPTION:
        printf("Its your turn mortal, what will you do? [A/D]\n");
        scanf("%s", option);

        if (strcmp(option, "A") == 0 || strcmp(option, "a") == 0)
        {
            attack(&hero.hp, &hero.dmg, &hero.def, &slime.hp, &slime.dmg, &slime.block);
            printf("Your hp is %i, and the enemy's is %i\n", hero.hp, slime.hp);
            sleep(1);
        }

        else if (strcmp(option, "D") == 0 || strcmp(option, "d") == 0)
        {
            defence(&hero.hp, &slime.dmg, &hero.def);
            printf("Your hp is %i, and the enemy's is %i\n", hero.hp, slime.hp);
            sleep(1);
        }

        else if (strcmp(option, "S") == 0 || strcmp(option, "s") == 0)
        {
            if (strcmp(item2, "No item") == 0)
            {
                printf("can't use this\n");
                goto OPTION;
            }
            else
            {
                special(&hero.hp, &hero.dmg, &hero.def, &slime.hp, &slime.dmg, &slime.block);
                printf("Your hp is %i, and the enemy's is %i\n", hero.hp, slime.hp);
                sleep(1);
            }
        }

        if (hero.def < 0)
        {
            hero.def = 0;
        }

        if (hero.hp <= 0)
        {
            printf("The slime slowly gobles you up, with your final moments you pray that the person after you has a better journey\n");
            sleep(2);
            break;
        }

        if (slime.hp <= 0)
        {
            printf("With swift slashes you slice the monster in to tiny bits, leaving sludge all over the place, the wall, the ceiling\n");
            sleep(1);

            for (int i = 0; i < 1; i++)
            {
                type = rand() % 100;
                if (type >= 0 && type < 75)
                {
                    loot(0);
                }
                else if (type >= 75 && type <= 99)
                {
                    loot(1);
                }
            }
        }
    } while (slime.hp > 0);
}

void armorMob()
{
    hallowArmor.hp = 45, hallowArmor.dmg = 20, hallowArmor.block = 0; // hallow armor sturct

    srand(time(NULL));

    // bool debuff = false;
    // int counter = 0;

    printf("Your are attacked by a walking armor, by the sound you can dissern that its empty\n");

    sleep(1);

    do
    {
        clear();

        for (int i = 0; i < 1; i++)
        {
            hallowArmor.atk = rand() % 3;
        }

        sleep(1);

        if (hallowArmor.atk == 0)
        {
            printf("It draws an axe, [25 dmg]\n");
            hallowArmor.dmg = 25;
        }

        else if (hallowArmor.atk == 1)
        {
            printf("Crossing his arms, it braces for impact [+10 def]\n");
            hallowArmor.block += 10;
            hallowArmor.dmg = 0;
        }

        else if (hallowArmor.atk == 2)
        {
            printf("He gets ready to tackle you [5 x 4]\n");
            hallowArmor.dmg = 20;
        }

        sleep(1);

        openFiles("sprites/knight.txt");

        for (int j = 0; j < 3; j++)
        {
            printf("\n");
        }
        printf("\n\nSWORD:[%s]      SHIELDS:[%s]        SPECIALS:[%s]\n\n", item0, item1, item2);

        printf("Its your turn mortal, what will you do? [A/D]\n");
        scanf("%s", option);

        if (strcmp(option, "A") == 0 || strcmp(option, "a") == 0)
        {
            attack(&hero.hp, &hero.dmg, &hero.def, &hallowArmor.hp, &hallowArmor.dmg, &hallowArmor.block);
            printf("Your hp is %i, and the enemy's is %i, enemy's block is %i\n", hero.hp, hallowArmor.hp, hallowArmor.block);
        }

        else if (strcmp(option, "D") == 0 || strcmp(option, "d") == 0)
        {
            defence(&hero.hp, &hallowArmor.dmg, &hero.def);
            printf("Your hp is %i, and the enemy's is %i, enemy's block is %i\n", hero.hp, hallowArmor.hp, hallowArmor.block);
        }

        sleep(1);

        if (hero.hp <= 0)
        {
            printf("You try to run away, but with one clean slash with his axe, you get cut in half\n");
            sleep(2);
            break;
        }

        else if (hallowArmor.hp <= 0)
        {
            printf("Dodging his overhead hit, you quickly jab piercing his armor, and suddenly the armor goes limp\n");
            sleep(1);

            for (int i = 0; i < 1; i++)
            {
                type = rand() % 100;
                if (type >= 0 && type < 75)
                {
                    loot(3);
                }
                else if (type >= 75 && type <= 99)
                {
                    loot(2);
                }
            }
        }
    } while ((hallowArmor.hp > 0) && (hero.hp > 0));
}

void hugeRatMob()
{
    hugeRat.hp = 35, hugeRat.dmg = 10, hugeRat.block = 0; //huge Rat struct

    srand(time(NULL));

    bool debuff = false;
    int counter = 0;

    printf("You see a huge rat aproching you, it's red eyes warn you of it's ferocious nature\n");

    sleep(1);

    do
    {
        clear();

        if (debuff == true)
        {
            hero.hp -= 5;
            counter--;
            if (counter <= 0)
            {
                debuff = false;
                hero.dmg /= 0.5;
            }
            for (int i = 0; i < 1; i++)
            {
                slime.atk = rand() % 1;
            }
        }
        else if (debuff == false)
        {
            for (int i = 0; i < 1; i++)
            {
                hugeRat.atk = rand() % 2;
            }
        }

        sleep(1);

        if (hugeRat.atk == 0)
        {
            printf("It brandishes its razor sharp claws [15 dmg]\n");
            hugeRat.dmg = 15;
        }

        else if (hugeRat.atk == 1)
        {
            printf("You see it widen its mouth, to reveal a set of green/black teeth [10 dmg + poison for 2 turns[5 dmg]]\n");
            hugeRat.dmg = 10;
            debuff = true;
            counter = 2;
        }

        sleep(1);
        printf("\n");

        openFiles("sprites/rat.txt");

        printf("\n\nSWORD:[%s]      SHIELDS:[%s]        SPECIALS:[%s]\n\n", item0, item1, item2);
        printf("Its your turn mortal, what will you do? [A/D]\n");
        scanf("%s", option);

        if (strcmp(option, "A") == 0 || strcmp(option, "a") == 0)
        {
            attack(&hero.hp, &hero.dmg, &hero.def, &hugeRat.hp, &hugeRat.dmg, &hugeRat.block);
            printf("Your hp is %i, and the enemy's is %i\n", hero.hp, hugeRat.hp);
            sleep(1);
        }

        else if (strcmp(option, "D") == 0 || strcmp(option, "d") == 0)
        {
            defence(&hero.hp, &hugeRat.dmg, &hero.def);
            printf("Your hp is %i, and the enemy's is %i\n", hero.hp, hugeRat.hp);
            sleep(1);
        }

        if (hero.def < 0)
        {
            hero.def = 0;
        }

        if (hero.hp <= 0)
        {
            printf("You feel yourself getting drowsy, with your last sight, you see the rat's face become somewhat of a twisted sile\n");
            sleep(2);
            break;
        }

        if (hugeRat.hp <= 0)
        {
            printf("You impale it throught the stomach, it squeels and rattles, but finally closes its bloodshot eyes\n");
            sleep(1);

            for (int i = 0; i < 1; i++)
            {
                type = rand() % 100;
                if (type >= 0 && type < 50)
                {
                    loot(0);
                }
                else if (type >= 50 && type <= 99)
                {
                    loot(3);
                }
            }
        }
    } while (hugeRat.hp > 0);
}

void bossFightWorm()
{
    bossWorm.hp = 200, bossWorm.dmg = 0, bossWorm.stackdmg = 0, bossWorm.block = 0; // worm struct

    bool debuff = false;
    int counter = 0;

    printf("You start to hear low rumbling sound below your feet\n");
    sleep(1);
    clear();
    printf("Suddenly, a huge sand worm emerges from the ground, ensircling you with its long body");
    sleep(1);

    do
    {
        clear();

        if (bossWorm.buff % 3 == 0)
        {
            if (bossWorm.buff == 24)
            {
                printf("Slowly circling you like a whirlpool, it crushes your spine, killing you instantly. With you last dying breath you let out an agonizing scream\n");
                break;
            }

            else
            {
                printf("Its slowly circles you more, making you fell more and more claustrophobic [you got %i turns to live]\n", 24 - bossWorm.buff);
                bossWorm.dmg = 0;
                bossWorm.buff++;
            }
        }

        else
        {
            if (debuff == true)
            {
                counter--;
                if (counter <= 0)
                {
                    debuff = false;
                    hero.dmg /= 0.5;
                }
                for (int i = 0; i < 1; i++)
                {
                    bossWorm.atk = rand() % 2;
                }
            }
            else if (debuff == false)
            {
                for (int i = 0; i < 1; i++)
                {
                    bossWorm.atk = rand() % 3;
                }
            }

            sleep(1);

            if (bossWorm.atk == 0)
            {
                printf("You see it getting ready to slam its giant head on you [30 dmg]\n");
                bossWorm.dmg = 30 + bossWorm.stackdmg;
            }

            else if (bossWorm.atk == 1)
            {
                printf("With a loud blearch its fangs get covered in venom [+3 dmg]\n");
                bossWorm.stackdmg += 3;
                bossWorm.dmg = 0;
            }

            else if (bossWorm.atk == 2)
            {
                printf("Its burrows deep, making the ground shake beneith your feet [2 x 5 dmg & you deal 2x less dmg for 2 turns]\n");
                bossWorm.dmg = 10;
                debuff = true;
                counter = 2;
                hero.dmg *= 0.5;
            }
            bossWorm.buff++;
        }

        sleep(1);
        openFiles("sprites/worm.txt");
        printf("\n\nSWORD:[%s]      SHIELDS:[%s]        SPECIALS:[%s]\n\n", item0, item1, item2);

        printf("Its your turn mortal, what will you do? [A/D]\n");
        scanf("%s", option);

        if (strcmp(option, "A") == 0 || strcmp(option, "a") == 0)
        {
            attack(&hero.hp, &hero.dmg, &hero.def, &bossWorm.hp, &bossWorm.dmg, &bossWorm.block);
            printf("Your hp is %i, and the enemy's is %i\n", hero.hp, bossWorm.hp);
        }

        else if (strcmp(option, "D") == 0 || strcmp(option, "d") == 0)
        {
            defence(&hero.hp, &bossWorm.dmg, &hero.def);
            printf("Your hp is %i, and the enemy's is %i\n", hero.hp, bossWorm.hp);
        }

        sleep(1);

        if (hero.hp <= 0)
        {
            printf("You last sight is the endless abyss of the monsters teeth ridden mouth, before it gobbles you up whole\n");
            break;
        }

        else if (bossWorm.hp <= 0)
        {
            printf("Even agains a much bigger foe, you climg on top of him and drop straight down, slicing his head clean off\n");
            loot(7);
        }
    } while ((bossWorm.hp > 0) && (hero.hp > 0));

    hero.hp = 100;
}

void golemMob()
{
    golem.hp = 80, golem.dmg = 10, golem.block = 40; //golem struct

    srand(time(NULL));

    // bool debuff = false;
    int counter = 0;

    printf("From the darkness a large clay golem emerges, he is almost twice your size\n");

    sleep(1);

    do
    {
        clear();

        if (golem.block == 0)
        {
            golem.atk = 2;
        }

        if (counter == 1)
        {
            golem.atk = 1;
        }
        else if (counter == 0)
        {
            golem.atk = 0;
        }

        sleep(1);

        if (golem.atk == 0)
        {
            printf("He clenches his fists, preparing to strike [30 dmg]\n");
            golem.dmg = 30;
            counter = 1;
        }

        else if (golem.atk == 1)
        {
            printf("His slow movement lets you get an extra hit, [0 dmg]\n");
            golem.dmg = 0;
            counter = 0;
        }

        else if (golem.atk == 2)
        {
            printf("The clay on the golem starts to reform [+15 def]\n");
            golem.block += 20;
        }

        sleep(1);
        printf("\n");

        openFiles("sprites/golem.txt");

        printf("\n\nSWORD:[%s]      SHIELDS:[%s]        SPECIALS:[%s]\n\n", item0, item1, item2);
        printf("Its your turn mortal, what will you do? [A/D]\n");
        scanf("%s", option);

        if (strcmp(option, "A") == 0 || strcmp(option, "a") == 0)
        {
            attack(&hero.hp, &hero.dmg, &hero.def, &golem.hp, &golem.dmg, &golem.block);
            printf("Your hp is %i, and the enemy's is %i (block: %i)\n", hero.hp, golem.hp, golem.block);
            sleep(1);
        }

        else if (strcmp(option, "D") == 0 || strcmp(option, "d") == 0)
        {
            defence(&hero.hp, &golem.dmg, &hero.def);
            printf("Your hp is %i, and the enemy's is %i (block: %i)\n", hero.hp, golem.hp, golem.block);
            sleep(1);
        }

        if (hero.def < 0)
        {
            hero.def = 0;
        }

        if (hero.hp <= 0)
        {
            printf("With a precice blow he knocks you to the ground, then picks you up and breaks your spine, with your fading sight you see the golems dead, lifeless eyes\n");
            sleep(1);
            break;
        }

        if (golem.hp <= 0)
        {
            printf("The golem toples to the ground, his head falls on the ground ant you see a small piece of paper in its mouth\n");
            sleep(1);

            for (int i = 0; i < 1; i++)
            {
                type = rand() % 100;
                if (type >= 0 && type < 75)
                {
                    loot(0);
                }
                else if (type >= 75 && type <= 99)
                {
                    loot(2);
                }
            }
        }
    } while (golem.hp > 0);
}

void cultistMob()
{
    cultist.hp = 80, cultist.dmg = 10, cultist.block = 0; //cultist struct

    srand(time(NULL));

    bool debuff = false;
    int counter = 0;

    printf("A red robe wearing figure aproches you, holding an elaborate scythe in his hands\n");

    sleep(1);

    do
    {
        clear();

        if (debuff == true)
        {
            counter--;
            if (counter <= 0)
            {
                debuff = false;
            }
            for (int i = 0; i < 1; i++)
            {
                cultist.atk = rand() % 2;
            }
        }
        else if (debuff == false)
        {
            if (cultist.hp <= 40)
            {
                cultist.atk = 3;
            }
            else
            {
                for (int i = 0; i < 1; i++)
                {
                    cultist.atk = rand() % 3;
                }
            }
        }

        sleep(1);

        if (cultist.atk == 0)
        {
            printf("He takes a quick step towards you and pulls his scythe back [15 dmg & +5 hp]\n");
            cultist.dmg = 15;
            cultist.hp += 5;
        }

        else if (cultist.atk == 1)
        {
            printf("Winding up he starts spinning towards you like a saw [1 x 10 dmg & +10 hp]\n");
            cultist.dmg = 10;
            cultist.hp += 10;
        }

        else if (cultist.atk == 2)
        {
            printf("He kneels and starts chanting, weird lights gather around him [+20 hp]\n");
            cultist.dmg = 0;
            debuff = true;
            counter = 2;
        }

        sleep(1);
        printf("\n");

        openFiles("sprites/cultist.txt");

        printf("\n\nSWORD:[%s]      SHIELDS:[%s]        SPECIALS:[%s]\n\n", item0, item1, item2);
    OPTION:
        printf("Its your turn mortal, what will you do? [A/D]\n");
        scanf("%s", option);

        if (strcmp(option, "A") == 0 || strcmp(option, "a") == 0)
        {
            attack(&hero.hp, &hero.dmg, &hero.def, &cultist.hp, &cultist.dmg, &cultist.block);
            printf("Your hp is %i, and the cultist's is %i\n", hero.hp, cultist.hp);
            sleep(1);
        }

        else if (strcmp(option, "D") == 0 || strcmp(option, "d") == 0)
        {
            defence(&hero.hp, &cultist.dmg, &hero.def);
            printf("Your hp is %i, and the cultist's is %i\n", hero.hp, cultist.hp);
            sleep(1);
        }

        else if (strcmp(option, "S") == 0 || strcmp(option, "s") == 0)
        {
            if (strcmp(item2, "No item") == 0)
            {
                printf("can't use this\n");
                goto OPTION;
            }
            else
            {
                special(&hero.hp, &hero.dmg, &hero.def, &cultist.hp, &cultist.dmg, &cultist.block);
            }
        }

        if (hero.def < 0)
        {
            hero.def = 0;
        }

        if (hero.hp <= 0)
        {
            printf("With a flash of steel he cleanly cuts you in half, your mind goes blank\n");
            sleep(2);
            break;
        }

        if (cultist.hp <= 0)
        {
            printf("\n");
            sleep(1);

            for (int i = 0; i < 1; i++)
            {
                type = rand() % 100;
                if (type >= 0 && type < 50)
                {
                    loot(0);
                }
                else if (type >= 50 && type < 89)
                {
                    loot(1);
                }
                else if (type >= 89 && type <= 99)
                {
                    loot(9);
                }
            }
        }
    } while (cultist.hp > 0);
}

void heavyArmorMob()
{
    heavyArmor.hp = 100, heavyArmor.dmg = 10, heavyArmor.block = 0; //heavyArmor struct

    srand(time(NULL));

    // bool debuff = false;
    // int counter = 0;

    printf("A set of armor, wielding an axe, aproaches you, he's atleast twice your size, if not more\n");

    sleep(1);

    do
    {
        clear();

        if (heavyArmor.atk == 1)
        {
            heavyArmor.atk = 2;
        }
        else
        {
            for (int i = 0; i < 1; i++)
            {
                heavyArmor.atk = rand() % 3;
            }
        }

        sleep(1);

        if (heavyArmor.atk == 0)
        {
            printf("He swings his axe [35 dmg]\n");
            heavyArmor.dmg = 35;
        }

        else if (heavyArmor.atk == 1)
        {
            printf("He croses his arms, bracing for impact [+30 def]\n");
            heavyArmor.block += 30;
            heavyArmor.dmg = 0;
        }

        else if (heavyArmor.atk == 3)
        {
            printf("With his arms corssed he readys to charge you [%i dmg]\n", heavyArmor.block);
            heavyArmor.dmg = heavyArmor.block;
        }

        sleep(1);
        printf("\n");

        openFiles("sprites/heavyArmor.txt");

        printf("\n\nSWORD:[%s]      SHIELDS:[%s]        SPECIALS:[%s]\n\n", item0, item1, item2);
    OPTION:
        printf("Its your turn mortal, what will you do? [A/D]\n");
        scanf("%s", option);

        if (strcmp(option, "A") == 0 || strcmp(option, "a") == 0)
        {
            attack(&hero.hp, &hero.dmg, &hero.def, &heavyArmor.hp, &heavyArmor.dmg, &heavyArmor.block);
            printf("Your hp is %i, and the enemy's is %i, enemy's block is %i\n", hero.hp, heavyArmor.hp, heavyArmor.block);
            sleep(2);
        }

        else if (strcmp(option, "D") == 0 || strcmp(option, "d") == 0)
        {
            defence(&hero.hp, &heavyArmor.dmg, &hero.def);
            printf("Your hp is %i, and the enemy's is %i, enemy's block is %i\n", hero.hp, heavyArmor.hp, heavyArmor.block);
            sleep(2);
        }

        else if (strcmp(option, "S") == 0 || strcmp(option, "s") == 0)
        {
            if (strcmp(item2, "No item") == 0)
            {
                printf("can't use this\n");
                goto OPTION;
            }
            else
            {
                special(&hero.hp, &hero.dmg, &hero.def, &heavyArmor.hp, &heavyArmor.dmg, &heavyArmor.block);
            }
        }

        if (hero.def < 0)
        {
            hero.def = 0;
        }

        if (hero.hp <= 0)
        {
            printf("With an opverhead swing his slices you in half, right, down, the, middle\n");
            sleep(2);
            break;
        }

        if (heavyArmor.hp <= 0)
        {
            printf("Dodging and overhead attack, you quickly dash in and jum, slicing the armors helmet clean off, he goes limp\n");
            sleep(2);

            for (int i = 0; i < 1; i++)
            {
                type = rand() % 100;
                if (type >= 0 && type < 75)
                {
                    loot(11);
                }
                else if (type >= 75 && type <= 99)
                {
                    loot(10);
                }
            }
        }
    } while (heavyArmor.hp > 0);
}

void shadowMob()
{
    shadow.hp = 80, shadow.dmg = 0, shadow.stackdmg = 0, shadow.block = 0; //shadow struct

    srand(time(NULL));

    bool debuff = false;
    int counter = 0;

    printf("As you're walking through a long corridor in the cave, you see that your suroundings are getting harder to see, when you realise you're surounded by a wall of dark mist, a dark, shadowy sword swiftly lunges out of the mist trying to cut you into pieces\n");

    sleep(1);

    do
    {
        clear();

        if (debuff == true)
        {
            counter--;
            if (counter <= 0)
            {
                debuff = false;
                hero.dmg /= 0.5;
            }
            for (int i = 0; i < 1; i++)
            {
                shadow.atk = rand() % 4;
            }
        }
        else if (debuff == false)
        {
            for (int i = 0; i < 1; i++)
            {
                shadow.atk = rand() % 5;
            }
        }

        sleep(1);

        if (shadow.atk == 0)
        {
            printf("A shadowy axe lunges out of the black mist [20 dmg]\n");
            shadow.dmg = 20 + shadow.stackdmg;
        }

        else if (shadow.atk == 1)
        {
            printf("A broad greatsword drops from the mist cloud above you [30 dmg]\n");
            shadow.dmg = 30 + shadow.stackdmg;
        }

        else if (shadow.atk == 2)
        {
            printf("The shadowy mist starts expanding, engulfing more and more of the room [+5 dmg]\n");
            shadow.stackdmg += 3;
            shadow.dmg = 0;
        }

        else if (shadow.atk == 3)
        {
            printf("Large, dark shield form around the wall of mist [+25 def]\n");
            shadow.dmg = 0;
            shadow.block += 25;
        }

        else if (shadow.atk == 4)
        {
            printf("The mist thickens, you're vision starts fading [+20 def & weaken]\n");
            shadow.dmg = 0;
            shadow.block += 20;
            debuff = true;
            hero.dmg *= 0.5;
        }

        sleep(1);
        printf("\n");

        openFiles("sprites/shadow.txt");

        printf("\n\nSWORD:[%s]      SHIELDS:[%s]        SPECIALS:[%s]\n\n", item0, item1, item2);
    OPTION:
        printf("Its your turn mortal, what will you do? [A/D]\n");
        scanf("%s", option);

        if (strcmp(option, "A") == 0 || strcmp(option, "a") == 0)
        {
            attack(&hero.hp, &hero.dmg, &hero.def, &shadow.hp, &shadow.dmg, &shadow.block);
            printf("Your hp is %i, and the enemy's is %i, enemy's block is %i\n", hero.hp, shadow.hp, shadow.block);
            sleep(2);
        }

        else if (strcmp(option, "D") == 0 || strcmp(option, "d") == 0)
        {
            defence(&hero.hp, &shadow.dmg, &hero.def);
            printf("Your hp is %i, and the enemy's is %i, enemy's block is %i\n", hero.hp, shadow.hp, shadow.block);
            sleep(2);
        }

        else if (strcmp(option, "S") == 0 || strcmp(option, "s") == 0)
        {
            if (strcmp(item2, "No item") == 0)
            {
                printf("can't use this\n");
                goto OPTION;
            }
            else
            {
                special(&hero.hp, &hero.dmg, &hero.def, &shadow.hp, &shadow.dmg, &shadow.block);
            }
        }

        if (hero.def < 0)
        {
            hero.def = 0;
        }

        if (hero.hp <= 0)
        {
            printf("\n");
            sleep(2);
            break;
        }

        if (shadow.hp <= 0)
        {
            printf("\n");
            sleep(1);

            for (int i = 0; i < 1; i++)
            {
                type = rand() % 100;
                if (type >= 0 && type < 75)
                {
                    loot(11);
                }
                else if (type >= 75 && type <= 99)
                {
                    loot(12);
                }
            }
        }
    } while (shadow.hp > 0);
}

// FUNCTIONS

// a function to show defence stats

void defence(int *hp, int *dmg, int *block)
{
    if (strcmp(item1, "hydraShield") == 0)
    {
        *hp -= 0.25 * *dmg;
    }
    else if (strcmp(item1, "shadowCloak") == 0)
    {
        *hp -= 0 * *dmg;
    }
    else
    {
        *hp -= 0.5 * *dmg;
    }

    if (strcmp(item1, "golemCoat") == 0)
    {
        *block += 5;
        printf("Block gotten: %i", *block);
    }
}

// a function to show attack stats

void attack(int *hp, int *dmg, int *block, int *hp1, int *dmg1, int *block1)
{
    if (*block1 > *dmg)
    {
        *block1 -= *dmg;
        if (*hp1 <= 0)
        {
            *dmg1 = 0;
        }
        *hp = *hp - (*dmg1 - *block);
    }
    else
    {
        *hp1 = *hp1 - (*dmg - *block1);
        if (*hp1 <= 0)
        {
            *dmg1 = 0;
        }
        *hp -= *dmg1;
        *block1 -= *dmg;
    }

    if (*block1 < 0)
    {
        *block1 = 0;
    }

    if (*block < 0)
    {
        *block = 0;
    }

    if (strcmp(item0, "vampireBlade") == 0)
    {
        *hp += 0.5 * *dmg;
        printf("Life stollen: %f\n", 0.5 * *dmg);
    }

    if (strcmp(item1, "golemCoat") == 0)
    {
        *block += 5;
        printf("Block gotten: %i", *block);
    }

    if (strcmp(item0, "heavyAxe") == 0)
    {
        *hp1 -= *dmg;
    }
}

void special(int *hp, int *dmg, int *block, int *hp1, int *dmg1, int *block1)
{
    // if (strcmp(item2, "crowEye") == 0)
    // {
    //     hero.dmg *= 2;
    //     int crowCounter = 1;
    // }

    // else if (strcmp(item2, "Skip Boss") == 0)
    // {
    // }

    if (strcmp(item2, "sacraficialDagger") == 0)
    {
        *dmg += 15;
        attack(hp, dmg, block, hp1, dmg1, block1);
        *hp -= 5;
        *dmg -= 15;
    }
}

// open files for ascii art

void openFiles(char *name)
{
    FILE *ascii = fopen(name, "r");

    if (ascii == NULL)
    {
        fclose(ascii);
    }

    char c = fgetc(ascii);

    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(ascii);
    }
    fclose(ascii);
}