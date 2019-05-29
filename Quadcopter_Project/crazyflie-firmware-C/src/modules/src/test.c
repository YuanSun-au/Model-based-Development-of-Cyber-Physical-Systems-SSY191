#include <stdio.h>
#include <math.h>

static void matrix_multiply(int A_rows, int A_cols, int A[A_rows][A_cols], 
                            int B_rows, int B_cols, int B[A_cols][B_cols], 
                            int C[A_rows][B_cols])
{
    for (int i = 0; i < A_rows; i++)
    {
         for (int j = 0; j < B_cols; j++)
         {
              int sum = 0;
              for (int k = 0; k < A_cols; k++)
                  sum += A[i][k] * B[k][j];
              C[i][j] = sum;
         }
    }
}

static void print_matrix(const char *tag, int w, int N, int M, int matrix[N][M])
{
    printf("%s (%dx%d):\n", tag, N, M);
    for (int i = 0; i < N; i++)
    {
         for (int j = 0; j < M; j++)
             printf("%*d", w, matrix[i][j]);
         putchar('\n');
    }
}

int main(void)
{
    // int A[3][4] =
    // {
    //     { 41, 76, 70, 42, },
    //     { 70, 62, 77, 74, },
    //     { 49, 55, 43, 65, },
    // };
    // int B[4][5] =
    // {
    //     { 73, 33, 42, 72, 65, },
    //     { 69, 30, 83, 83, 64, },
    //     { 90, 74, 84, 51, 23, },
    //     { 62, 45, 84, 46, 43, },
    // };
    // int C[3][5];
    // print_matrix("A", 3, 3, 4, A);
    // print_matrix("B", 3, 4, 5, B);
    // // matrix_multiply(A, 3, 4, B, 4, 5, C);
    // matrix_multiply(3, 4, A, 4, 5, B, C);
    // print_matrix("C", 6, 3, 5, C);

    float a = -2;

    float b = sqrt(pow(a,2));
    printf("%f\n",b);

    printf("%f\n", pow(a,2));

    return 0;
}