#pragma once
#include <math.h>

#define PI 3.14159265358979
#define earth_Re 6378237   //���򳤰뾶m
#define earth_f 1/298.257223563   //�������
#define earth_Rp (1-earth_f)*earth_Re      //����̰뾶
#define wie 7.2921151467e-5   //������ת������rad/s
#define earth_e sqrt(2*earth_f-earth_f*earth_f) //��һƫ����
#define earth_ep sqrt(earth_Re*earth_Re-earth_Rp*earth_Rp)//�ڶ�ƫ����
#define earth_e2 (earth_e)*(earth_e)
#define earth_ep2 (earth_ep)*(earth_ep)
#define g0 9.7803267714 //�������ٶ�

#define mg 1.0e-3*g0
#define ug 1.0e-6*g0
#define deg PI/180
#define min deg/60
#define sec min/60
#define ppm 1.0e-6
#define hur 3600.0
#define dps deg/1.0
#define dph deg/hur
#define dpsh deg/sqrt(hur)
#define dphpsh dph/sqrt(hur)
#define ugpsHz ug / sqrt(1.0)
#define ugpsh  ug/sqrt(hur)
#define mpsh 1/sqrt(hur)
#define mpspsh 1/1/sqrt(hur)
#define ppmpsh ppm/sqrt(hur)
#define secpsh sec/sqrt(hur)