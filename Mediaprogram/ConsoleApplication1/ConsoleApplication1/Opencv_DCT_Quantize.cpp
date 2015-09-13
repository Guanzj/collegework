// dctfenkuai.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "cv.h"
#include "highgui.h"
#include<iostream>
#include<math.h>
#include <iomanip>
using namespace std;
void PrintMat(CvMat *A);
int main(int argc, char** argv){

	float ztotalratio[8][8] = { 0 };
	int jishu[8][8] = { 0 };
	IplImage* img = cvLoadImage("F:\\Gray.bmp", 1);//加载图片


	IplImage* imggray = cvCreateImage(cvSize(img->width, img->height), IPL_DEPTH_8U, 1);//创建新图片

	cvCvtColor(img, imggray, CV_RGB2GRAY);//   zhuanhuan  yanse kongjian

	cvNamedWindow("Gray", CV_WINDOW_AUTOSIZE);
	cvShowImage("Gray", imggray);
	//cvSaveImage("lenagray.jpg",imggray);
	//获取图像信息
	int height, width, step, channels;
	uchar *data;

	height = imggray->height;
	width = imggray->width;

	step = imggray->widthStep;
	channels = imggray->nChannels;
	data = (uchar *)imggray->imageData;


	CvMat *img_mat = cvCreateMat(imggray->width, imggray->height, CV_32FC1);
	//CvMat *img_matdct= cvCreateMat(imggray->height, imggray->width, CV_8UC1);
	IplImage* dst = cvCreateImage(cvSize(width, height), IPL_DEPTH_32F, 1);

	cvConvert(imggray, img_mat);//重点*****转换
	cvDCT(img_mat, dst, CV_DXT_FORWARD);// DCT变换
	// 创建窗口
	cvConvert(dst, img_mat);
	PrintMat(img_mat);
	cvNamedWindow("DCT", CV_WINDOW_AUTOSIZE);
	cvMoveWindow("DCT", 100, 100);

	IplImage* imgdct = cvCreateImage(cvGetSize(imggray), imggray->depth, imggray->nChannels);
	cvConvert(dst, imgdct);//  juzhen  zhuanhuan  tuxiang
	//CvMat*dstmat=cvCreateMat(imggray->height, imggray->width, CV_32FC1);
	//cvConvert(dst,dstmat);
	//PrintMat(dstmat);
	//矩阵分块 设置了一个8*8子矩阵遍历提取原矩阵数据，进行DCT变换，赋值给另一矩阵
	CvMat *imgmatfenkuai = cvCreateMat(imggray->width, imggray->height, CV_32FC1);
	cvSetIdentity(imgmatfenkuai);
	CvMat *imgmatquantize = cvCreateMat(imggray->width, imggray->height, CV_32FC1);
	cvSetIdentity(imgmatquantize);
	CvMat *imgmatchazhi = cvCreateMat(imggray->width, imggray->height, CV_32FC1);
	cvSetIdentity(imgmatchazhi);
	int QS[8][8] = { 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1 };


	for (int ii = 0; ii<width / 8; ii++)
	{
		for (int jj = 0; jj<height / 8; jj++)
		{
			CvMat *imgmatsub1 = cvCreateMat(8, 8, CV_32FC1);
			CvRect imgmatsubrect1 = cvRect(8 * ii, 8 * jj, 8, 8);
			cvGetSubArr(img_mat, imgmatsub1, imgmatsubrect1);//get submat
			IplImage* imgdstsub1 = cvCreateImage(cvSize(8, 8), IPL_DEPTH_32F, 1);
			cvDCT(imgmatsub1, imgdstsub1, CV_DXT_FORWARD);//DCT for the 1th submat


			CvMat *imgmatdctsub1 = cvCreateMat(8, 8, CV_32FC1);
			cvConvert(imgdstsub1, imgmatdctsub1);

			//combine all matsub1 to  fenkuaidctmat

			for (int i = 0; i<8; i++)
			{
				for (int j = 0; j<8; j++)
				{
					cvmSet(imgmatfenkuai, 8 * ii + i, 8 * jj + j, cvmGet(imgmatdctsub1, i, j));

					double lianghua = cvRound(cvmGet(imgmatdctsub1, i, j) / QS[i][j]);//quantization *QS[i][j]
					cvmSet(imgmatquantize, 8 * ii + i, 8 * jj + j, lianghua);
					if (lianghua<0.00001) jishu[i][j] = jishu[i][j] + 1;
					cvmSet(imgmatchazhi, 8 * ii + i, 8 * jj + j, cvmGet(imgmatfenkuai, 8 * ii + i, 8 * jj + j) - cvmGet(imgmatquantize, 8 * ii + i, 8 * jj + j));
				}
			}


			//ztotalratio[ii][jj]=1-(float)jishu/64;
			//cout<<ztotalratio[ii][jj]<<endl;
			cvReleaseMat(&imgmatsub1);
			cvReleaseMat(&imgmatdctsub1);
			cvReleaseImage(&imgdstsub1);
		}
	}
	for (int m = 0; m<8; m++)
	{
		for (int n = 0; n<8; n++)
		{
			ztotalratio[m][n] = 1 - (float)jishu[m][n] / 4096;
			cout << ztotalratio[m][n] << endl;
		}
	}

	float a = 0.5;
	float sigema = -a*QS[0][0] / log(ztotalratio[0][0]);

	float MSE = 2 * sigema*sigema - ((2 * a - 1)*QS[0][0] * QS[0][0] + 2 * sigema)*exp(-a*QS[0][0] / sigema) / (1 - exp(QS[0][0] / sigema));
	cout << MSE;
	// 创建窗口,显示图像
	cvNamedWindow("DCT", CV_WINDOW_AUTOSIZE);
	cvMoveWindow("DCT", 100, 100);
	cvShowImage("DCT", imgdct);

	//show the imgmatfenkuai//***********************分块
	IplImage *imgdctfenkuai = cvCreateImage(cvGetSize(imggray), imggray->depth, imggray->nChannels);
	cvConvert(imgmatfenkuai, imgdctfenkuai);





	cvNamedWindow("DCT8*8", CV_WINDOW_AUTOSIZE);
	cvMoveWindow("DCT8*8", 100, 100);
	cvShowImage("DCT8*8", imgdctfenkuai);
	//show the imgmatquantize//******************量化
	IplImage *imgdctquantize = cvCreateImage(cvGetSize(imggray), imggray->depth, imggray->nChannels);

	//CvMat *imgmatquantint=cvCreateMat(imggray->width, imggray->height, CV_8SC1);
	/*cvConvert(imgmatquantize,imgmatquantint);
	for(int m=1;m<60;m++)
	{
	cout<<cvmGet(imgmatfenkuai,1,m);
	cout<<"rt:"<<cvmGet(imgmatquantize,1,m)<<endl;

	}
	*/
	cvConvert(imgmatquantize, imgdctquantize);
	//PrintMat(imgmatfenkuai);
	cvNamedWindow("DCTquantize", CV_WINDOW_AUTOSIZE);
	cvMoveWindow("DCTquantize", 100, 100);
	cvShowImage("DCTquantize", imgdctquantize);

	/*//show the imgmatchazhi
	IplImage *imgdctchazhi=cvCreateImage(cvGetSize(imggray),imggray->depth,imggray->nChannels);
	cvConvert(imgmatchazhi,imgdctchazhi);
	cvNamedWindow("DCTchazhi", CV_WINDOW_AUTOSIZE);
	cvMoveWindow("DCTchazhi", 100, 100);
	cvShowImage("DCTchazhi", imgdctchazhi);*/


	cvWaitKey(0);
	cvReleaseImage(&imgdctfenkuai);
	cvDestroyWindow("DCT8*8");

	cvReleaseImage(&imgdct);
	cvDestroyWindow("DCT");

	cvReleaseImage(&imgdctquantize);
	cvDestroyWindow("DCTquantize");

	//cvReleaseImage(&imgdctchazhi );
	//cvDestroyWindow("DCTchazhi");

	cvReleaseImage(&imggray);
	cvDestroyWindow("Gray");

	return 0;
}
void PrintMat(CvMat* A) // 显示矩阵
{
	int i, j;
	for (i = 0; i<A->rows; i++)    {
		printf("\n");
		switch (CV_MAT_DEPTH(A->type))        {
		case CV_32F:
		case CV_64F:
			for (j = 0; j<A->cols; j++) printf("%9.3f ", (float)cvGetReal2D(A, i, j));
			break;

		case CV_8U:
		case CV_16U:
			printf("%6d", (int)cvGetReal2D(A, i, j));
			break;

		default:    break;
		}
	}
	printf("\n");
}
