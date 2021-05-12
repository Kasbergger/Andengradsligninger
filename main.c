#include <stdio.h>
#include <stdlib.h>

/**< Deklaretioner af alle funktionerne */
void SolveSecondDegree(float a, float b, float c);
void TopPointSecondDegree(float a, float b, float c);
float DeterminantRegner(float a, float b, float c);
float SecondDegreeFormula(float a, float b, float c, float d, char s);

int main()
{
    float a, b, c;
    int i = 1;
    char topTjek;
    while(1){
        printf("Hvad er a, b og c for fomlen:\n");
        printf("a = ");
        scanf("%f", &a);
        printf("b = ");
        scanf("%f", &b);
        printf("c = ");
        scanf("%f", &c);

        SolveSecondDegree(a, b, c);

        /**< Tjekker om der ønskes toppunkt */
        printf("\n\nVil du ogsaa gerne have toppunktet for 2.gradsligningen: j for ja OG n for nej\n");
        while(i == 1){
            scanf(" %c", &topTjek);
            switch(topTjek){
            case 'j':
            case 'J':
                TopPointSecondDegree(a, b, c);
                i = 0;
                break;
            case 'n':
            case 'N':
                printf("Okay\n");
                i = 0;
                break;
            default:
                printf("Inputted var ikke valid\nProev igen:");
            }
        }
        i = 1;
        printf("\n\n");
    }
    return 0;
}

/************************************************
 *  Beskrivelse: Beregner determinanten         *
 ************************************************
 *  Input: tre floats a, b og c                 *
 *  Output: float                               *
 ************************************************/
float DeterminantRegner(float a, float b, float c)
{
    float d;
    d = b*b-4.0*a*c;
    return d;
}

/************************************************
 *  Beskrivelse: Beregner en andengradsligning  *
 ************************************************
 *  Input: tre floats a, b, c & én string til   *
 *  at fortælle hvilken operation (+ eller -)   *
 *  Output: float                               *
 ************************************************/
float SecondDegreeFormula(float a, float b, float c, float d, char s)
{
    float out;
    switch(s){
    case '+':
        return (b+sqrt(d))/2.0*a;
    case '-':
        return (b-sqrt(d))/2.0*a;
    }
}

/************************************************
 *  Beskrivelse: Skal bruge a, b, og c fra en   *
 *  ordnede andengradsligning                   *
 *  andengradsligningen og Printer              *
 *  relevante info om den når den er løst       *
 ************************************************
 *  Input: tre floats a, b, c                   *
 *  Output: printf af svarene samt deres        *
 *  informationer                               *
 ************************************************/
void SolveSecondDegree(float a, float b, float c)
{
    char toppunktTjek;
    float d;
    float xf;
    float xs;

    d = DeterminantRegner(a, b, c);

    printf("\n");

    //Tjekker determinanten
    if(d > 0){
        xf = SecondDegreeFormula(a, b, c, d, '+');
        xs = SecondDegreeFormula(a, b, c, d, '-');

        printf("Formlen har 2 loesninger da: %f > 0\n", d);
        printf("Formlens to loesninger er: x1 = %lf  &  x2 = %lf", xf, xs);
    } else if(d == 0.000000){
        xf = SecondDegreeFormula(a, b, c, d, '+');

        printf("Formlen har 1 loesning da: %f = 0\n", d);
        printf("Formlens loesning er: x = %f", xf);
    } else{
        printf("Formlen har ingen loesninger da: %f < 0", d);
    }
}

/************************************************
 *  Beskrivelse: Beregner toppunkted for en     *
 *  andengradsligning                           *
 ************************************************
 *  Input: tre floats a, b, c                   *
 *  Output: printf to floats x, y for           *
 *  toppunkted                                  *
 ************************************************/
void TopPointSecondDegree(float a, float b, float c)
{
    float x, y;

    /**< Formlerne for at finde toppunktet i en andengradsligning */
    x = -b/(2*a);
    y = -DeterminantRegner(a,b,c)/(4*a);

    printf("\nToppunktet for formlen er: x = %f  & y = %f \n", x, y);
}

