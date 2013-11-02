//-----------------------------------------------------------------------------
// hw4.c
//
// Matrizen Drechung
// Group: /
//
//-----------------------------------------------------------------------------
//
#include <stdio.h>

// Main function consists of 4 matrixes, and of calling out the two functions:
// printout, which prints out matrixes and rotation function which rotates matrixes..

int main()

{
    char matx1[4][4] = {{'-','-','-','-'}, {'-','o','-','-'}, {'o','o','o','-'}, {'-','-','-','-'}};
    char matx2[4][4] = {{'-','-','-','-'}, {'-','o','o','-'}, {'o','o','-','-'}, {'-','-','-','-'}};
    char matx3[4][4] = {{'-','-','-','-'}, {'-','o','-','-'}, {'-','o','-','-'}, {'-','o','o','-'}};
    char matx4[4][4] = {{'-','-','o','-'}, {'-','-','o','-'}, {'-','-','o','-'}, {'-','-','o','-'}};

    printout(matx1, matx2, matx3, matx4);
    rotation(matx1);
    rotation(matx2);
    rotation(matx3);
    rotation(matx4);
    printout(matx1, matx2, matx3, matx4);
    rotation(matx1);
    rotation(matx2);
    rotation(matx3);
    rotation(matx4);
    printout(matx1, matx2, matx3, matx4);
    rotation(matx1);
    rotation(matx2);
    rotation(matx3);
    rotation(matx4);
    printout(matx1, matx2, matx3, matx4);
    rotation(matx1);
    rotation(matx2);
    rotation(matx3);
    rotation(matx4);
    printout();

    return 0;

}

// Printout() function is there to actually assemble the matrixes and to print them out.

int printout(char matx1[4][4], char matx2[4][4], char matx3[4][4], char matx4[4][4])
        {

            int i = 0;
            int j = 0;
            //printing out the matrixes..
            for (i = 0; i < 4; i++)
                {
                    for (j = 0; j < 4; j++)
                    {
                        printf("%c ", matx1[i][j]);
                    }
                    printf(" ");

                    for (j = 0; j < 4; j++)
                        {
                            printf("%c ", matx2[i][j]);
                        }
                    printf(" ");

                    for (j = 0; j < 4; j++)
                        {
                            printf("%c ", matx3[i][j]);
                        }
                    printf(" ");

                    for (j = 0; j < 3; j++)
                        {
                            printf("%c ", matx4[i][j]);
                        }
                    printf("%c\n", matx4[i][3]);
                }

            printf("\n");

        }


// Rotation() is a function which rotates matrixes one by one.. and momorizes them, and after all four or if want for example to rotate only
// 3 matrixes, we can also do that.. when the rotation has been called in main() function, than there is a need to those matrixes out..

int rotation(char x[4][4])
{
    int i = 0;
    int j = 0;
    char y[4][4];
    for (i = 0; i < 4; i++)
        {
        for (j = 0; j < 4; j++)
            {
                y[i][j] = x[i][j];
            }
        }

        for (i = 0; i < 4; i++)
            {
                x[i][3] = y[0][i];
                x[i][2] = y[1][i];
                x[i][1] = y[2][i];
                x[i][0] = y[3][i];
            }


}











