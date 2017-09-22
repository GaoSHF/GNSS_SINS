#pragma once
#include "types.h"
#include "util.h"

#define DIMSTATE 15  //ϵͳ״̬ά��

typedef struct
{
	Vect atti;//��̬ŷ���� x:pitch,y:roll,z:yaw
	quat qnb;//��̬��Ԫ��
	float64 Cnb[3*3]; //��̬����������
	Vect vel;//���� x:velE,y:velN,z:velU
	Vect pos;//λ�� x:latitude,y:longitude,z:height
	float64 Mpv[3*3];//λ�þ���
	float64 Ft[DIMSTATE*DIMSTATE];//״̬ת�ƾ���
	
	Vect wib;//����ϵ����ڹ���ϵ����ת���ٶ�
	Vect wnb;//����ϵ��Ե���ϵ����ת���ٶ�
	Vect web;//����ϵ��Ե���ϵ����ת���ٶ�
	Vect fb;//����
	Vect fn;//�����ڵ���ϵ��ͶӰ
	Vect an;//����ϵ�߼��ٶ�
	float64 Cne[3 * 3];//λ�þ���
	float64 tauG;//����������Ʒ����ʱ��
	float64 tauA;//�Ӽ�����Ʒ����ʱ��
}sins;
typedef sins *psins;

void earth_para_update(Vect vn, Vect pos, pearth earth_p);
void align_coarse(Vect wm, Vect vm, pearth earth_p, float64 *Cnb);
void align_coarse1(Vect wm, Vect vm, pearth earth_p, float64 *Cnb);
void sins_init(Vect atti0, Vect pos0, Vect vel0, psins sins0);
void sins_init1(float64 *Cnb, quat qnb0,Vect atti0,Vect pos0, Vect vel0, psins sinst);
void attupdate(earth_para earth_p, Vect phim, float64 nts, psins sinst);
void velupdate(earth_para earth_p, Vect fn, float64 nts, psins sinst);
void posupdate(earth_para earth_p, float64 nts,Vect vn1, psins sinst);
void posupdate1(earth_para earth_p, float64 nts, Vect vn1, psins sinst);
void sins_update(Vect *wm, Vect *vm, int16u nSamples, float64 ts, psins sinst,pearth earthp);
void sins_setFt(pearth earth_p, psins sinst);

