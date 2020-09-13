#include <stdio.h>
#define LIMIT 5

struct
{
    int hp;
    int dmg;
    int dmgreceived;
    int def;
} hero;

struct
{
    int hp;
    int atk;
    int dmg;
    int block;
} slime;

struct
{
    int hp;
    int atk;
    int dmg;
    int block;
} golem;

struct
{
    int hp;
    int atk;
    int dmg;
    int block;
} cultist;

struct
{
    int hp;
    int atk;
    int dmg;
    int block;
} hugeRat;

struct
{
    int hp;
    int dmg;
    int block;
    int atk;
} hallowArmor;

struct
{
    int hp;
    int dmg;
    int block;
    int atk;
} heavyArmor;

struct
{
    int hp;
    int dmg;
    int block;
    int atk;
    int stackdmg;
} shadow;

struct
{
    int hp;
    int dmg;
    int atk;
    int stackdmg;
    int buff;
    int block;
} bossWorm;

char *item0 = "No item"; // swords and other kind of weapons
char *item1 = "No item"; // shields and other kinds of defensive objects
char *item2 = "No item"; // rings and special attacks
bool cast = false;

void clear();
void loot(int type);
