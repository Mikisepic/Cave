#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

void openTheFiles(char *name)
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

void flamePotion()
{
    printf("You got a flame potion\n");

    openTheFiles("items/flame.txt");

    char ch[1];

    printf("Do u want to get this item?[Y/N]\n");
    scanf("%s", ch);

    if (strcmp(ch, "n") == 0 || strcmp(ch, "N") == 0)
    {
        printf("You leave it\n");
    }

    else if (strcmp(ch, "y") == 0 || strcmp(ch, "Y") == 0)
    {
        hero.dmg += 4;
    }
}

void lightningPotion()
{
    printf("You got a lightning potion\n");

    openTheFiles("items/lightning.txt");

    char ch[1];

    printf("Do u want to get this item?[Y/N]\n");
    scanf("%s", ch);

    if (strcmp(ch, "N") == 0 || strcmp(ch, "n") == 0)
    {
        printf("You leave it\n");
    }

    else if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
    {
        hero.dmg += 8;
    }
}

void infernalPotion()
{
    printf("You got a infernal potion\n");

    openTheFiles("items/infernal.txt");

    char ch[1];

    printf("Do u want to get this item?[Y/N]\n");
    scanf("%s", ch);

    if (strcmp(ch, "n") == 0 || strcmp(ch, "N") == 0)
    {
        printf("You leave it\n");
    }

    else if (strcmp(ch, "y") == 0 || strcmp(ch, "Y") == 0)
    {
        hero.dmg += 12;
    }
}

void crowEye()
{
    //doubles your attack on next turn
    printf("You received a Crow's eye\n");
    char ch[1];

    printf("Do u want to get this item?[Y/N]\n");
    scanf("%s", ch);

    if (strcmp(ch, "N") == 0 || strcmp(ch, "n") == 0)
    {
        printf("You leave it\n");
    }

    else if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
    {
        item2 = "crowEye";
        cast = true;
    }
}

void sturdyArmor()
{
    char ch[1];

    printf("Do u want to get this item?[Y/N]\n");
    scanf("%s", ch);

    if (strcmp(ch, "N") == 0 || strcmp(ch, "n") == 0)
    {
        printf("You leave it\n");
    }

    else if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
    {
        hero.def += 20;
    }
}

void ring_of_focus()
{
    //doubles your dmg on the first turn of combat
    printf("You received a Ring of focus\n");
    char ch[1];

    printf("Do u want to get this item?[Y/N]\n");
    scanf("%s", ch);

    if (strcmp(ch, "N") == 0 || strcmp(ch, "n") == 0)
    {
        printf("You leave it\n");
    }

    else if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
    {
        item2 = "ringOfFocus";
    }
}

bool skipFight()
{
    printf("You got a get-out-of-jail free card, you can skip any fight, but get your health reduced by 30 and don't get loot\n");
    if (hero.hp > 30)
    {
        return false;
    }
    item2 = "Skip Boss";
    cast = true;
    return true;
}

bool leatherArmor()
{
    printf("You got a leather armor\n");
    char ch[1];

    printf("Do u want to get this item?[Y/N]\n");
    scanf("%s", ch);

    if (strcmp(ch, "N") == 0 || strcmp(ch, "n") == 0)
    {
        printf("You leave it\n");
    }

    else if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
    {
        if (strcmp(item1, "No item") == 0)
        {
            return false;
        }
        hero.def += 10;
        item1 = "Leather Armor";
        return true;
    }
    return false;
}

void hydraShield()
{
    //if you defend, you takse .25 dmg instead of .5
    printf("You received a Hydra shield\n");
    char ch[1];

    printf("Do u want to get this item?[Y/N]\n");
    scanf("%s", ch);

    if (strcmp(ch, "N") == 0 || strcmp(ch, "n") == 0)
    {
        printf("You leave it\n");
    }

    else if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
    {
        item1 = "hydraShield";
    }
}

void vampireBlade()
{
    //heals for 0.5 dmg dealt
    printf("You received a crimson red Vampire's blade\n");
    char ch[1];

    printf("Do u want to get this item?[Y/N]\n");
    scanf("%s", ch);

    if (strcmp(ch, "N") == 0 || strcmp(ch, "n") == 0)
    {
        printf("You leave it\n");
    }

    else if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
    {
        item0 = "vampireBlade";
    }
}

void golemCoat()
{
    //when you take dmg, you gain 5 block
    printf("You received a coat of a golems clay coat\n");
    char ch[1];

    printf("Do u want to get this item?[Y/N]\n");
    scanf("%s", ch);

    if (strcmp(ch, "N") == 0 || strcmp(ch, "n") == 0)
    {
        printf("You leave it\n");
    }

    else if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
    {
        item1 = "golemCoat";
    }
}

void sacraficialDagger()
{
    //when you activate it, you take 5 dmg and deal and extra 15 dmg on your attack
    printf("You received a ornamental dagger with barbs sticking out of its handle\n");
    char ch[1];

    printf("Do u want to get this item?[Y/N]\n");
    scanf("%s", ch);

    if (strcmp(ch, "N") == 0 || strcmp(ch, "n") == 0)
    {
        printf("You leave it\n");
    }

    else if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
    {
        item2 = "sacraficialDagger";
    }
}

void heavyAxe()
{
    //your attack deal double dmg, but after attacking you need 1 turn to recover,
    printf("You received a broad, two sidded axe, it takes all your strength to pick it up\n");
    char ch[1];

    printf("Do u want to get this item?[Y/N]\n");
    scanf("%s", ch);

    if (strcmp(ch, "N") == 0 || strcmp(ch, "n") == 0)
    {
        printf("You leave it\n");
    }

    else if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
    {
        item0 = "heavyAxe";
    }
}

void shadowCloak()
{
    //your defence make you take 0% dmg.
    printf("You received misty, dark cloak, it feels extremly light\n");
    char ch[1];

    printf("Do u want to get this item?[Y/N]\n");
    scanf("%s", ch);

    if (strcmp(ch, "N") == 0 || strcmp(ch, "n") == 0)
    {
        printf("You leave it\n");
    }

    else if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
    {
        item1 = "shadowCloak";
    }
}

void loot(int type)
{
    if (type == 0)
    {
        flamePotion();
    }

    else if (type == 1)
    {
        lightningPotion();
    }

    else if (type == 2)
    {
        infernalPotion();
    }

    else if (type == 3)
    {
        sturdyArmor();
    }

    else if (type == 4)
    {
        leatherArmor();
    }

    else if (type == 5)
    {
        skipFight();
    }

    else if (type == 6)
    {
        ring_of_focus();
    }

    else if (type == 7)
    {
        crowEye();
    }

    else if (type == 8)
    {
        hydraShield();
    }

    else if (type == 9)
    {
        golemCoat();
    }
    else if (type == 10)
    {
        sacraficialDagger();
    }
    else if (type == 11)
    {
        heavyAxe();
    }
    else if (type == 12)
    {
        shadowCloak();
    }
}