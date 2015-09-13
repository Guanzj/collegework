/*
	搜索演示：折半（二分）法搜索
*/

int  main()   {
    int a[10]={1,22,33,44,50,66,77,88,99,100};
    int target=50;
    int found=0; //搜索标志，=1表示查找成功

    int low=0;  
	int high=10-1;
	int mid=0;

	//二分法搜索
    while( low<=high && !found){   
        mid=(low+high)/2;  //中间位置

        if (a[mid]==target) 
		{
			found=1;         //查找成功
			//break;
		}
        else  if  (target<a[mid]) 
		{
			high=mid-1; //下一次到前半区查找  
		}
        else
		{
			low=mid+1;  //下一次到后半区查找 
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