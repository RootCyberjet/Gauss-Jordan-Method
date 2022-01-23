/*				NAME - SHIBA BISWAS			
				DESIGNATION - M.Sc STUDENT (Mathematics)
				University of North Bengal
				Siliguri - 734014, WB, India
				Email - shibabiswas1@gmail.com
================================================================================================
*/


#include<stdio.h>
#include"all.h"
void main()
{
	int n,m,i,j,k;
	float a[50][50][50],p[50][50][50],c[50][50][50];
	printf("Enter the no. of rows & columns of square matrix : ");
	scanf("%d",&m);
	n=2*m;
	printf("The no. of rows of Augmented matrix is %d.\n",m);
	printf("The no. of columns of Augmented matrix is %d.\n",n);
	printf("Therefore the considered matrix is of order (%d*%d).\n",m,n);
	read(a,m,m);
	printline(88);
	printf("The given matrix is :\n\n");
	write(a,m,m,1);
	printline(88);
	printf("The Augmented matrix is :\n\n");
	fuse(a,m,c);
	write(c,m,n,1);
	printline(88);
	printf("The operations on above matrix are as follows :\n");
	printline(88);
	for(k=1;k<m;k++)
	{
		for(j=1;j<=n;j++)
		{
			for(i=1;i<=m;i++)
			{
				if(i<=k)
				{
					c[i][j][k+1]=c[i][j][k];
				}
				else
				{
					c[i][j][k+1]=c[i][j][k]-((c[i][k][k]*c[k][j][k])/c[k][k][k]);
				}
			}
		}
		printline(88);
		write(c,m,n,k+1);
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			p[i][j][1]=c[i][j][m]/c[i][i][m];
		}
	}
	printline(88);
	write(p,m,n,1);
	printline(88);
	for(k=1;k<m;k++)
	{
		for(i=m;i>=1;i--)
		{
			for(j=1;j<=n;j++)
			{
				if(i>=(m-k+1))
				{
					p[i][j][k+1]=p[i][j][k];
				}
				else
				{
					p[i][j][k+1]=p[i][j][k]-(p[m-k+1][j][k]*p[i][m-k+1][k]);
				}
			}
		}
		write(p,m,n,k+1);
		printline(88);
	}
	printf("\nThe Required inverse of given matrix is :\n");
	printline(88);
	writeR(p,m,m+1,n,m);
	printline(88);
}

/*========================================== END OF PROGRAM ==============================================*/
