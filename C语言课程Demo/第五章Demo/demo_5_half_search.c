/*
	������ʾ���۰루���֣�������
*/

int  main()   {
    int a[10]={1,22,33,44,50,66,77,88,99,100};
    int target=50;
    int found=0; //������־��=1��ʾ���ҳɹ�

    int low=0;  
	int high=10-1;
	int mid=0;

	//���ַ�����
    while( low<=high && !found){   
        mid=(low+high)/2;  //�м�λ��

        if (a[mid]==target) 
		{
			found=1;         //���ҳɹ�
			//break;
		}
        else  if  (target<a[mid]) 
		{
			high=mid-1; //��һ�ε�ǰ��������  
		}
        else
		{
			low=mid+1;  //��һ�ε���������� 
		}
   } 

   if(found)	   
   {
	   printf("target found, pos=%d\n", mid );
   }
   else
   {
	   printf("target not found\n");
   }

   return   0;  
}