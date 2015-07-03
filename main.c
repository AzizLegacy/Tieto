#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>




struct Strukturka1
{
    int x;
    char slowo[10];

};

typedef struct
{
    int x;
    char slowo[10];

} Strukturka2;

Strukturka2 Konstruktor(int a, char *slowko) //"In C I typically create a function in the style of a constructor which does this."
{
    Strukturka2 tmp;
    tmp.x = a;
    strcpy(tmp.slowo, slowko);
    return tmp;

}


void Wypisz_Struktury()
{

   struct Strukturka1 Strukturka1_instancja1; //bez keyword 'struct' - uknown type name 'Strukturka1'. Struct trzeba by było pisać wszędzie. W C++ nie trzeba :)

   Strukturka2 Strukturka2_instancja1; //z typedefem nie trzeba nigdzie pisać 'struct'

    Strukturka2 Strukturka2_instancja2 = Konstruktor(10, "Aziz");
    printf("%d %s\n", Strukturka2_instancja2.x, Strukturka2_instancja2.slowo);
/*
In C, the name s appearing in

struct s
    {
    ...
    };
is a tag. A tag name is not a type name. Given the definition above, declaration such as

s x;    //error in C
is error in C. You must write it as

struct s x;     // OK

*/

}

int Wypisz_Bity()
{
    int x = 20;
    char schowek[ sizeof(int) * 8 + 1]; //4 bajty, każdy po 8 bitów.
    int iterator = sizeof(int) * 8;

    memset(schowek, 'x', sizeof(schowek) );
    schowek[iterator--]= '\0';

    if(x < 0)
    {
        printf("Liczba musi byc nieujemna!");
        return -1;
    }



    while(x != 0) //Zapisywanie od tyłu.
    {
        if(x&1 == 1)
        {
          //  printf("1");
            schowek[iterator--] = '1';
        }
        else
        {
         //   printf("0");
            schowek[iterator--] = '0';
        }
        x>>=1;

    }


    int znak;
    for(znak = 0 ; znak < sizeof(schowek) -1; znak++)
    {
        if(schowek[znak] == '0' || schowek[znak] == '1' )
            printf("%c", schowek[znak]);


    }

//printf("Tablica: %s", schowek);
return 0;
}

int main()
{
   // Wypisz_Struktury();
    Wypisz_Bity();

    return 0;
}
