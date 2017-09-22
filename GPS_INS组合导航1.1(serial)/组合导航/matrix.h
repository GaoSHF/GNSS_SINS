#pragma once
#include "types.h"


#define IJ(i,j,n) ((i-1)*n + (j-1)) //����������ת����ϵ

typedef struct
{
	float64 *element;                   //����ʵ������
	int16u row;             //��������
	int16u col;             //��������
}Matrix;
//typedef Matrix *p_Matrix;  //�������


void Matrix_I(int8u n, float64 *Imat);
void Matrix_diag(float64 *dig, int8u n, float64 *diag);
void Matrix_diag2(float64 *dig, int8u n, float64 *diag);
int16u MatrixAdd(const float64 *clA, int16u row, int16u col, const float64 *clB, float64 *pclResult);
int16u MatrixSub(const float64 *clA, int16u row, int16u col, const float64 *clB, float64 *pclResult);
extern int MatrixTrans(const double *clA, int row, int colomn, double *pclDes);
int16u NumMultiMatrix(const float64 dwNum, float64 *clMatrix, int16u row, int16u col, float64 *pclMatrix);
extern int MatrixMultiply(float64 *matrixOut, float64 *lhs, int lrow, int lcolomn, float64 *rhs, int rrow, int rcolomn);
extern int *imat(int n, int m);
extern double *mat(int n, int m);
extern void matcpy(double *A, const double *B, int n, int m);
extern int Matrixinv(double *A, int n);