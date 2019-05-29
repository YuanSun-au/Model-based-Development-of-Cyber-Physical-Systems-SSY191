static void addm(int rows, int cols, float A[rows][cols], float B[rows][cols], float C[rows][cols]){
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}

static void addv(int N, float A[N], float B[N], float C[N]){
	for (int i = 0; i < N; i++){
		C[i] = A[i] + B[i];
	}
}

static void mult(int A_rows, int A_cols, float A[A_rows][A_cols],
				 int B_rows, int B_cols, float B[A_cols][B_cols],
				 float C[A_rows][B_cols]){
	for (int i = 0; i < A_rows; i++){
		for (int j = 0; j < B_cols; j++){
			int sum = 0;
			for (int k = 0; k < A_cols; k++)
				sum += A[i][k] * B[k][j];
			C[i][j] = sum;
		}
	}
}

static void smult(int rows, int cols, float A[rows][cols], float b, float C[rows][cols]){
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			C[i][j] = b * A[i][j];
		}
	}
}