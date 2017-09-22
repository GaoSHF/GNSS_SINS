#pragma once
#include "types.h"
#include "matrix.h"

//������άʸ��
typedef struct
{
	float64 x;
	float64 y;
	float64 z;
}Vect;
//typedef Vect *pVect;
//������Ԫ��
typedef struct
{
	float64 q0;
	float64 q1;
	float64 q2;
	float64 q3;
}quat;

//����������
typedef struct
{
//	float64 g0;//�������ٶ�ʸ��
//	Vect g = { 0, 0, g0 };
	float64 lat;//γ��
	float64 lon;//����
	float64 heigh; //�߶�
	float64 RMh;//����Ȧ���ʰ뾶
	float64 RNh;//î��Ȧ���ʰ뾶
	Vect wnie;//������ת�����ڵ���ϵ�е�ͶӰ
	Vect wnen;//����ϵ����ڵ���ϵ����ת�������ڵ���ϵ�е�ͶӰ
	Vect wnin;//����ϵ����ڹ���ϵ����ת�������ڵ���ϵ�е�ͶӰ
	Vect wnien;
	Vect gn;//�������ٶ��ڵ���ϵ�е�ͶӰ
	Vect gcc;//�۳��к����ٶ�֮����������ٶ�
//	float64 Cne[3 * 3];
}earth_para;
typedef earth_para *pearth;

typedef struct
{
	float64 sec;
	int16u year;
	int8u mon;
	int8u day;
	int8u hour;
	int8u min;
} UTCTime, *pUTCTime;

typedef struct
{
	int64u time;
	int32u    vFMP;                   /*position fixing mode : 0-fix not 1:Do not care 2:BD2 3:GPS 4:Dual  */
	int32u    vFMV;                   /*Speed fixing mode : 0-fix not 1:Do not care 2:BD2 3:GPS 4:Dual     */
	int32u    dopFlg;                 /*�ڲ�ʹ��1����Ч0��Ч                                               */
	int8u     validFlg;				  /*GNSS״̬(0:��Ч��1:gps��Ч,2:bd2��Ч ,3:GPS_BD2ȫ����Ч)           */
	int8u     usedNum;				  /*ʹ��������                           */
	int8u     enviroment;             /*��λ����                             */	
	float64   dir; 					  /*����� (����)                        */

	Vect pos;                         /*λ�� lat,lon,atl*/
	Vect vel; 					      /*�ٶ� ve,vn,vu                        */
	Vect ecefPos;					/*ECEF��ʽλ��                       */
	Vect ecefVel;					/*ECEF��ʽ�ٶ�                       */

	float64   pdop_p;				  /*GNSSԭʼ��λ�þ�������               */
	float64   hdop_p; 				  /*GNSSԭʼ��ˮƽ�������� (С��2����)   */
	float64   vdop_p;				  /*GNSSԭʼ����ֱ�������� (С��2����)   */
	float64   pdop_v;				  /*GNSSԭʼ���ٶȾ�������               */
	float64   hdop_v; 				  /*GNSSԭʼ���ٶ�ˮƽ��������           */
	float64   dop_p; 				  /*ˮƽλ��������� (С��10����)����Ҫ���dopFlgʹ��                   */
	float64   dop_v;				  /*�ٶ�������ӣ�С��0.5���ã��� ��Ҫ���dopFlgʹ��                    */
	float64   dop_a; 				  /*�����������ӣ�Ŀǰ���޲ο���ֵ���� ��Ҫ���dopFlgʹ��             */
	UTCTime utc_time;			      /*UTCʱ��                              */

	int32u usdnumG;				      /*ʹ�õ�GPS������                      */
	int32u usdnumB;				      /*ʹ�õ�BD������                       */

	
	int32u optSwitch;
	int32u sig_mode;
	float64   orig_lon;
	float64   orig_lat;
	float64   orig_dir;
	float64   orig_vel;

	float64		vRsdSqureP;
	float64		vRsdSqureV;
	int32s		vDof;
	int32u		klmPVEstCnt;
	//FixInfHandle	hfix;


	int8u		velUsedBDsat;
	int8u		velUsedGPSsat;

}GNSS_SignData;

void Vect_norm(Vect v, float64 *norm);
void Vect_cross(Vect a, Vect b, Vect *out);
void Vect_dot(Vect a, Vect b, float64 *out);
void Vect_mul(Vect a, float64 b, Vect *out);
void Vect_add(Vect a, Vect b, Vect *out);
void Vect_sub(Vect a, Vect b, Vect *out);
void Vect_add_equ(Vect *a, Vect b);
//void Vect2matrix(Vect *v, float64 *m);
//void matrix2Vect(float64 *m, Vect *v);
void askew(Vect v, float64 *Mv);

void rv2q(Vect rv, quat *qo);
void rv2cnb(Vect rv, float64 *Cnb);
void att2cnb(Vect atti, float64 *Cnb);
void cnb2att(float64 *Cnb, Vect *atti);
void att2q(Vect atti, quat *qnb);
void q2att(quat qnb, Vect *atti);
void q2cnb(quat qnb, float64 *Cnb);
void cnb2q(float64 *Cnb, quat *qnb);
void cnb2q1(float64 *Cnb, quat *qnb);
void attsyn0(float64 *Cnb, quat *qnb, Vect *atti);
void attsyn1(quat qnb, float64 *Cnb, Vect *atti);
void attsyn2(Vect atti, quat *qnb, float64 *Cnb);

void qconj(quat qi, quat *qo);
void qnormlz(quat qi, quat *qo);
void qmul(quat qi1, quat qi2, quat *qo);
void qmulv(quat qi, Vect vi, Vect *vo);
void lq2m(quat qi, float64 *mq);
void rq2m(quat qi, float64 *mq);
void rotv(Vect rv, Vect vi, Vect *vo);