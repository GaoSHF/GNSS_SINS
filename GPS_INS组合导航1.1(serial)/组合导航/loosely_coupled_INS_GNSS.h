#pragma once

#include "matrix.h"
#include "util.h"
#include "Sins.h"
#include "nmea.h"

//#define DIMSTATE 15  //ϵͳ״̬ά��
#define DIMMEA 6 //����ά��

//�����������ṹ
typedef struct
{
	float64 Fkk1[DIMSTATE*DIMSTATE];                       //״̬ת�ƾ���                         15x15
	float64 Qk[DIMSTATE*DIMSTATE];                         //״̬����Э�������                   15x15
	float64 Hk1[DIMMEA*DIMSTATE];                          //����ϵ������                         6x15
	float64 Rk1[DIMMEA*DIMMEA];                            //��������Э�������                   6x6 
	
	float64 Xkk1[DIMSTATE*1];                              //״̬һ��Ԥ��X(K|K-1)                 15x1 
	float64 Pkk1[DIMSTATE*DIMSTATE];                       //״̬һ��Ԥ�����Э�������P(K|K-1)   15x15
	float64 K1[DIMSTATE*DIMMEA];                           //�������                             15x6                
	float64 Xk[DIMSTATE*1];                                //X(K)                                 15x1
	float64 Pk[DIMSTATE*DIMSTATE];                         //�����������P(K)                     15x15
	
	float64 Zk1[DIMMEA*1];                                 //����ֵ.                 6x1
	float64 rk[DIMMEA * 1];                                //����һ��Ԥ�����
	float64 Gk[DIMSTATE*1];
	float64 Qt[6*6];                                       //״̬��������

	float64 Pxykk_1[DIMSTATE*DIMMEA];                      //״̬һ��Ԥ�����������һ��Ԥ�������׻��ԭ���   P(k1/k)*H(k1)T     15x6
	float64 Py0[DIMMEA*DIMMEA];                            //H(k1)*P(k1/k)*H(k1)T  6x6
	float64 Pykk_1[DIMMEA*DIMMEA];                         //����һ��Ԥ�����Э�������  H(k1)*P(k1/k)*H(k1)T+R(k1)  6x6
	float64 dx[DIMSTATE * 1];                              //״̬������
	float64 dP[DIMSTATE*DIMSTATE];                         
}S_Kalmanfilter;

//�������˲�������
typedef struct
{
	Vect atti;
	float64 Cnb[3*3];
	quat qnb;
	Vect pos;
	Vect vel;
}SinsFilterOpt;

int16s filter_init(S_Kalmanfilter *kf, sins *sinst,float64 nts);
void allan_var(S_Kalmanfilter *kf, int32u iTer,float64 *Zk1);
void filter_update(S_Kalmanfilter *kf, char *updatemode, bool adaptive,float64 beta);
void filter_feedback(S_Kalmanfilter *kf, psins sinst, SinsFilterOpt *sinsfilter_opt);
int8u loosely_coupled_GNSS_INS(pearth earth_p, psins sinst, nmeaINFO *info, float64 ts, S_Kalmanfilter *kf, SinsFilterOpt *sinsfilter_opt, char *kf_updatemode, int32u *iTer_allan, float64 *beta);