//显示图像文件
#include <opencv2/opencv.hpp>
using namespace std;


int main()
{
	const char *ImageName = "F:\\Opencv_Demo_other.jpg";
	const char *WindowsTitle = "Opencv_Demo";

	//从文件中读取图像
	IplImage *pImage = cvLoadImage(ImageName, CV_LOAD_IMAGE_UNCHANGED);

	//创建窗口
	cvNamedWindow(WindowsTitle, CV_WINDOW_AUTOSIZE);

	//在指定窗口中显示图像
	cvShowImage(WindowsTitle, pImage);

	//等待按键事件
	cvWaitKey();

	//收尾
	cvDestroyWindow(WindowsTitle);
	cvReleaseImage(&pImage);
	return 0;
}