/*
	找一个行列式的马鞍点
*/

#include <stdio.h>
#include <stdlib.h>

int min_index( int a[], int n ){ //不返回最小值，返回最小值对应的位置
    int i ;
	int index=0; //假设第一个元素是最小值

    for(i=1;i<n;i++)
	{
        if(a[i]<a[index])
		{
			index=i; //如果有更小的元素则更新index
		}
	}

	return index;  //返回数组a[n]中的最小值的下标
}

int main(){
    int a[4][3]={{11,13,121},{407,72,88},{23,58,1},{134,30,62} };
    int row,count=0,col,i;

	
	//找出每行中的最小值，并判断它是否是同列中的最大值（马鞍点）
	for(row=0;row<4;row++)
	{
		int minInRow=0; //记录一行中的最小值的列下标
		int maxInCol=0;//记录一列中最大值

		//-------找当前行中的最小的值，列下标用minInRow记录
		for(i=0;i<3;i++)
		{
			if(a[row][i] < a[row][minInRow])
			{
				minInRow=i;  //记录一行中的最小值的列
			}
		}

		//运行到此，a[row][minInRow]为当前行（row行）中的最小值,它的列为minInRow

		//--------对找到的当前行中的最小值，判断它是否是它所在列中的最大值
		//maxInCol=minInRow;//记录一列中最大值
		maxInCol=row;//记录一列中最大值
		//判断a[row][minInRow]在它的列中（minInRow列）中是否是最大值
		for(i=0;i<4;i++)
		{
			if( a[i][minInRow] > a[row][minInRow])
			{
				maxInCol=i; //记录一列中最大值
			}
		}

		//如果该列中的最大值是a[row][minInRow]，则a[row][minInRow]是马鞍点
		if(maxInCol==row)
		{
			printf("row=%d,col=%d,value=%d\n",row, minInRow,a[row][minInRow]); //输出
            count++; //马鞍点个数递增
		}	
	}

    if(count==0)
	{
		printf("no\n"); //没有马鞍点
	}

	/*
	
    for(row=0;row<4;row++){
        col=min_index( a[row], 3); //找到一行最小值所在的列

        for(i=0;i<4 && a[i][col]<=a[row][col];i++); //检查该列是否有更大元素,注意此时的a[row][col]是当前行(row行)中的最小值

        if( i==4 ){ //没有更大的元素，说明是a[row][col]是col列中的最大值，也就是一个马鞍点
            printf("row=%d,col=%d,value=%d\n",row, col,a[row][col]);
            count++; //马鞍点个数递增
        }
    }

    if(count==0)
	{
		printf("no\n"); //没有马鞍点
	}
	*/
	

	system("pause");
    return 0;
}
