//��ʾͼ���ļ�
#include <opencv2/opencv.hpp>
using namespace std;


int main()
{
	const char *ImageName = "F:\\Opencv_Demo_other.jpg";
	const char *WindowsTitle = "Opencv_Demo";

	//���ļ��ж�ȡͼ��
	IplImage *pImage = cvLoadImage(ImageName, CV_LOAD_IMAGE_UNCHANGED);

	//��������
	cvNamedWindow(WindowsTitle, CV_WINDOW_AUTOSIZE);

	//��ָ����������ʾͼ��
	cvShowImage(WindowsTitle, pImage);

	//�ȴ������¼�
	cvWaitKey();

	//��β
	cvDestroyWindow(WindowsTitle);
	cvReleaseImage(&pImage);
	return 0;
}