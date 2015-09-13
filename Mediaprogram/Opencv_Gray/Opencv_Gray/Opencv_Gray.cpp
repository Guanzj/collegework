#include <opencv2/opencv.hpp>
#include<highgui.h>
#include<iostream>
#include "stdafx.h"
#include "cv.h"
#include "highgui.h"
#include<iostream>
#include<math.h>
#include <iomanip>
using namespace std;
using namespace cv;
#define PI 3.1415926
const int quantize[][8] = 
{ 16, 11, 10, 16, 24, 40, 51, 61,   //������������
12, 12, 14, 19, 26, 58, 60, 55,
14, 13, 16, 24, 40, 57, 69, 56,
14, 17, 22, 29, 51, 87, 80, 62,
18, 22, 37, 56, 68, 109, 103, 77,
24, 35, 55, 64, 81, 104, 103, 77,
49, 64, 78, 87, 103, 121, 120, 101,
72, 92, 95, 98, 112, 100, 103, 99, };

void DCT(int input[8][8], double output[8][8]);
void _DCT(double input[8][8], int output[8][8]);
void lianghua(double input[8][8], int output[8][8]);
void _lianghua(int input[8][8], double output[8][8]);
void coutGray(double input[8][8]);
void Array2Img(double input[8][8], IplImage *dct);
void coutGray(int input[8][8]);
void Array2Img(int input[8][8], IplImage *dct);
int main(int argc, char *argv[])
{
	cout << "����ͼƬ��" << endl;
	CvSize dst_cvsize(8, 8);   //Ŀ��ͼ��ߴ�
	IplImage*src = cvLoadImage("F:\\Gray.bmp", 0);//����ͼƬ;   //Դͼ��ָ�� 
	cout << "ͼƬ���سɹ�"<<endl;
	cout<<"���ػҶ�ͼͨ��ֵ"<<cvGetImageCOI(src)<<endl;//���ͼƬͨ��ֵ
	IplImage*dst = cvCreateImage(dst_cvsize, IPL_DEPTH_8U, 1); //����Ŀ��ͼ��  //Ŀ��ͼ��ָ�� //8*8�Ҷ�ֵ����
	IplImage*dct = cvCreateImage(dst_cvsize, IPL_DEPTH_8U,1); //����Ŀ��ͼ��  //Ŀ��ͼ��ָ�� //DCT�任����
	IplImage*qua = cvCreateImage(dst_cvsize, IPL_DEPTH_8U, 1); //����Ŀ��ͼ��  //Ŀ��ͼ��ָ�� //��������
	IplImage*_qua = cvCreateImage(dst_cvsize, IPL_DEPTH_8U, 1); //����Ŀ��ͼ��  //Ŀ��ͼ��ָ�� //����������
	IplImage*_dct = cvCreateImage(dst_cvsize, IPL_DEPTH_8U, 1); //����Ŀ��ͼ��  //Ŀ��ͼ��ָ�� //��DCT�任����
	double Arraydct[8][8];//DCT��������
	int Arrayqua[8][8];//������������
	double Arraydqua[8][8];//��������������
	int Arrayddct[8][8];//��DCT��������
	cvResize(src, dst, CV_INTER_LINEAR); //����Դͼ��Ŀ��ͼ��  ͼ��ѹ��
	cvNamedWindow("src", CV_WINDOW_AUTOSIZE); //����������ʾԴͼ��Ĵ���  
	cvNamedWindow("dst", CV_WINDOW_AUTOSIZE); //����������ʾĿ��ͼ��Ĵ���  
	cvShowImage("src", src);  //��ʾԴͼ��  
	cvShowImage("dst", dst);  //��ʾĿ��ͼ��  
	int width = dst->width;//ͼƬ���
	int height = dst->height;//ͼƬ�߶�
	int Gray[8][8];//�Ҷ�ֵ��������
	for (int row = 0; row<height; row++)
	{
		uchar* ptr = (uchar*)dst->imageData + row*dst->width;//��ûҶ�ֵ����ָ��
		for (int cols = 0; cols<width; cols++)
		{
			uchar intensity = ptr[cols];//��������
			cout << (int)intensity << "  ";//ǿ��ת��
			Gray[row][cols] = intensity;//�洢�Ҷ�ֵ����
		}
		cout << endl;
	}//�������  ͼ��ѹ��  ����ͼ�񴴽�  ����ͼ�񱣴�  �ҶȾ������  �ҶȾ��󱣴�

	cvWaitKey();
	//cvDestroyWindow("src");
	//cvReleaseImage(&src);
	//cvWaitKey();
	//DCT
	cout << "����DCT�任" << endl;
	DCT(Gray, Arraydct);
	coutGray(Arraydct);
	Array2Img(Arraydct, dct);
	cvNamedWindow("dct", CV_WINDOW_AUTOSIZE); 
	cvShowImage("dct", dct); 
	cvWaitKey();
	//lianghua
	cout << "������������" << endl;
	lianghua(Arraydct, Arrayqua);
	coutGray(Arrayqua);
	Array2Img(Arrayqua, qua);
	cvNamedWindow("qua", CV_WINDOW_AUTOSIZE);
	cvShowImage("qua", dct);
	cvWaitKey();
	//_lianghua
	cout << "���з���������" << endl;
	_lianghua(Arrayqua, Arraydqua);
	coutGray(Arraydqua);
	Array2Img(Arraydqua, _qua);
	cvNamedWindow("_qua", CV_WINDOW_AUTOSIZE);
	cvShowImage("_qua", dct);
	cvWaitKey();
	//_DCT
	cout << "������DCT�任" << endl;
	_DCT(Arraydqua, Arrayddct);
	coutGray(Arrayddct);
	Array2Img(Arrayddct, _dct);
	cvNamedWindow("_dct", CV_WINDOW_AUTOSIZE);
	cvShowImage("_dct", dct);
	cvWaitKey();

		system("pause");
		return 0;
	}
void DCT(int input[8][8], double output[8][8])//��ÿһС��ͼ�����DCT�任
{
	int i, j, p, q;
	double a1, a2, temp;
	for (i = 0; i<8; i++)
	{
		for (j = 0; j<8; j++)
		{
			temp = 0.0;
			if (i == 0) { a1 = sqrt(1.0 / 8); }
			else   { a1 = sqrt(2.0 / 8); }
			if (j == 0) { a2 = sqrt(1.0 / 8); }
			else   { a2 = sqrt(2.0 / 8); }
			for (p = 0; p<8; p++)
			{
				for (q = 0; q<8; q++)
				{
					temp += input[p][q] * cos((2 * p + 1)*i*PI / 16)*cos((2 * q + 1)*j*PI / 16);
				}
			}
			output[i][j] = a1*a2*temp;
		}
	}
}

void _DCT(double input[8][8], int output[8][8])
{
	int i, j, p, q;
	double a1, a2, temp;
	for (i = 0; i<8; i++)
	{
		for (j = 0; j<8; j++)
		{
			temp = 0.0;
			for (p = 0; p<8; p++)
			{
				for (q = 0; q<8; q++)
				{
					if (p == 0) { a1 = sqrt(1.0 / 8); }
					else   { a1 = sqrt(2.0 / 8); }
					if (q == 0) { a2 = sqrt(1.0 / 8); }
					else   { a2 = sqrt(2.0 / 8); }
					temp += a1*a2*input[p][q] * cos((2 * i + 1)*p*PI / 16)*cos((2 * j + 1)*q*PI / 16);
				}

			}
			output[i][j] = temp;
		}
	}
}

void lianghua(double input[8][8], int output[8][8])
{
	int i, j;
	for (i = 0; i<8; i++)
	{
		for (j = 0; j<8; j++)
		{
			output[i][j] = (int)(input[i][j] / quantize[i][j]);
		}
	}
}

void _lianghua(int input[8][8], double output[8][8])
{
	int i, j;
	for (i = 0; i<8; i++)
	{
		for (j = 0; j<8; j++)
		{
			output[i][j] = input[i][j] * quantize[i][j];
		}
	}
}

void coutGray(double input[8][8])
{
	int i, j;
	for (i = 0; i<8; i++)
	{
		for (j = 0; j<8; j++)
		{
			cout.width(9);
			cout.setf(ios::showpos);
			cout.precision(6);
			cout<<input[i][j]<<" ";
		}
			cout << endl;
	}
}

void Array2Img(double input[8][8], IplImage *dct)
{
	int i, j;
	for (i = 0; i<8; i++)
	{
		for (j = 0; j<8; j++)
		{
			cvSetReal2D(dct, i, j, input[i][j]);
		}
	}
}

void coutGray(int input[8][8])
{
	int i, j;
	for (i = 0; i<8; i++)
	{
		for (j = 0; j<8; j++)
		{
			cout.width(9);
			cout.setf(ios::showpos);
			cout.precision(6);
			cout << input[i][j] << " ";
		}
		cout << endl;
	}
}

void Array2Img(int input[8][8], IplImage *dct)
{
	int i, j;
	for (i = 0; i<8; i++)
	{
		for (j = 0; j<8; j++)
		{
			cvSetReal2D(dct, i, j, input[i][j]);
		}
	}
}