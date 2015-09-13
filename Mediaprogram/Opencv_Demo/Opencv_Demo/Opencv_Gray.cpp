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
	CvSize dst_cvsize(8, 8);   //目标图像尺寸
	IplImage*src = cvLoadImage("F:\\Gray.bmp", 0);//导入图片;   //源图像指针  
	IplImage*dst = cvCreateImage(dst_cvsize, 255, 1); //构造目标图象  //目标图像指针   
	//CvSize dst_cvsize(8,8);   //目标图像尺寸  
	//dst = cvCreateImage(dst_cvsize, 255, 1); //构造目标图象  
	cvResize(src, dst, CV_INTER_AREA); //缩放源图像到目标图像  
	cvSaveImage("F:\\dst.bmp", dst);
	//cvNamedWindow("src", CV_WINDOW_AUTOSIZE); //创建用于显示源图像的窗口  
	//cvNamedWindow("dst", CV_WINDOW_AUTOSIZE); //创建用于显示目标图像的窗口  
	//cvShowImage("src", src);  //显示源图像  
	//cvShowImage("dst", dst);  //显示目标图像  
	int width = dst->width;//图片宽度
	int height = dst->height;//图片高度
	int Gray[1024][1024];
	for (int row = 0; row<height; row++)
	{
		uchar* ptr = (uchar*)dst->imageData + row*dst->width;//获得灰度值数据指针
		for (int cols = 0; cols<width; cols++)
		{
			uchar intensity = ptr[cols];//数据类型
			cout << (int)intensity << "  ";//强制转换
			Gray[row][cols] = intensity;
		}
		cout << endl;
	}//以上完成  图像压缩  副本图像创建  副本图像保存  灰度矩阵输出  灰度矩阵保存


	//变换


	system("pause");
	return 0;
}