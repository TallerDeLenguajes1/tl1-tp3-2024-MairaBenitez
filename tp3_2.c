#include <stdio.h>
#include <stdlib.h>

#define A 5
#define M 12
#define MAX 50001

void promedioGanancia(int *);
void valorMaxMin(int *);

void main()
{
    int mt[A][M], *p, i, j;
    p = &mt[0][0];

    printf("La producción de los próximos 5 años sera: \n");
    for (i = 0; i < A; i++)
    {
        for (j = 0; j < M; j++)
        {
            do
            {
                mt[i][j] = 10000 + rand();
            } while (mt[i][j] > MAX);
            printf("%2d ", mt[i][j]);
        }
        printf("\n");
    }
    promedioGanancia(p);
    valorMaxMin(p);
}

void promedioGanancia(int *p)
{
    int i, j, cont = 0;
    float suma, promedio;

    for (i = 0; i < A; i++)
    {
        suma = 0;
        promedio = 0;
        for (j = 0; j < M; j++)
        {
            suma = suma + *(p + (i * M + j));
        }
        promedio = suma / 12;
        printf("\nEl promedio de ganancia del año %i es %.3f", A - cont, promedio);
        cont++;
    }
}

void valorMaxMin(int *p)
{
    int i, j, max = 0, min = MAX, anioM, aniom, mesM, mesm;
    for (i = 0; i < A; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (max < *(p + (i * M + j)))
            {
                max = *(p + (i * M + j));
                anioM = i + 1;
                mesM = j + 1;
            }
            if (min > *(p + (i * M + j)))
            {
                min = *(p + (i * M + j));
                aniom = i + 1;
                mesm = j + 1;
            }
        }
    }
    printf("\nEl valor maximo es %i y se obtuvo en el año %i mes %i", max, anioM, mesM);
    printf("\nEl valor minimo es %i y se obtuvo en el año %i mes %i", min, aniom, mesm);
}