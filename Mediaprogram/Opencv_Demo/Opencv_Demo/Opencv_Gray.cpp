#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <cv.h>
#include <highgui.h>
#include <cxcore.h>
using namespace std;

int main(int argc, char *argv[])
{
	cout << "1" << endl;
	CvSize dst_cvsize(8, 8);   //Ŀ��ͼ��ߴ�
	IplImage*src = cvLoadImage("F:\\Gray.bmp", 0);//����ͼƬ;   //Դͼ��ָ��  
	IplImage*dst = cvCreateImage(dst_cvsize, 255, 1); //����Ŀ��ͼ��  //Ŀ��ͼ��ָ��   
	//CvSize dst_cvsize(8,8);   //Ŀ��ͼ��ߴ�  
	//dst = cvCreateImage(dst_cvsize, 255, 1); //����Ŀ��ͼ��  
	cvResize(src, dst, CV_INTER_AREA); //����Դͼ��Ŀ��ͼ��  
	cvSaveImage("F:\\dst.bmp", dst);
	//cvNamedWindow("src", CV_WINDOW_AUTOSIZE); //����������ʾԴͼ��Ĵ���  
	//cvNamedWindow("dst", CV_WINDOW_AUTOSIZE); //����������ʾĿ��ͼ��Ĵ���  
	//cvShowImage("src", src);  //��ʾԴͼ��  
	//cvShowImage("dst", dst);  //��ʾĿ��ͼ��  
	int width = dst->width;//ͼƬ���
	int height = dst->height;//ͼƬ�߶�
	int Gray[1024][1024];
	for (int row = 0; row<height; row++)
	{
		uchar* ptr = (uchar*)dst->imageData + row*dst->width;//��ûҶ�ֵ����ָ��
		for (int cols = 0; cols<width; cols++)
		{
			uchar intensity = ptr[cols];//��������
			cout << (int)intensity << "  ";//ǿ��ת��
			Gray[row][cols] = intensity;
		}
		cout << endl;
	}//�������  ͼ��ѹ��  ����ͼ�񴴽�  ����ͼ�񱣴�  �ҶȾ������  �ҶȾ��󱣴�


	//�任


	system("pause");
	return 0;
}