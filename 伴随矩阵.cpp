#include<stdio.h>
#define n 4

int main()
{
	static int numble[n];
	static int A[2*n][2*n];
	static int M[2*n][2*n];
	static int B[2*n][2*n];
	static int C[2*n][2*n]; 
	printf("����һ��%d�׵ľ���A:\n",n);
	
//�������� 
	int m=n+1,k=n-1;
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<m;j++)
		{
			printf("A[%d][%d]=",i,j);
			scanf("%d",&A[i][j]);
		}
	}

//����Ԫ�� 
	printf("\n����A:\n");
	for(int i=1;i<m;i++)
	{
		printf("[");
		for(int j=1;j<m;j++)
		{
			printf("%d",A[i][j]);
			if(j!=n)
			{
				printf(" ");
			}
		}
		printf("]\n");
	}
	
//������� 
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<m;j++)
		{
			//������� 
			for(int i1=1;i1<m;i1++)
			{
				for(int j1=1;j1<m;j1++)
				{
					M[i1][j1]=A[i1][j1];
				}
			}
			
			//���� 
			for(int i1=i;i1<m-1;i1++)
			{
				for(int j1=1;j1<m;j1++)
				{
					M[i1][j1]=A[i1+1][j1];
				}
			}
			
			//���� 
			for(int i1=1;i1<m;i1++)
			{
				for(int j1=j;j1<m-1;j1++)
				{
					M[i1][j1]=M[i1][j1+1];
				}
			}
			
			
//			//����ʽ 
//			printf("\nM(%d,%d)=\n",i,j);
//			for(int i1=1;i1<n;i1++)
//			{
//				printf("[");
//				for(int j1=1;j1<n;j1++)
//				{
//					printf("%d",M[i1][j1]);
//					if(j1!=n-1)
//					{
//						printf(" ");
//					}
//				}
//				printf("]\n");
//			}
//			
//			//��������ʽ 
//			if((i+j)%2==0)
//			{
//				printf("\nA(%d,%d)=M\n",i,j);
//			}
//			else if((i+j)%2==1)
//			{
//				printf("\nA(%d,%d)=-M\n",i,j);
//			}
//			for(int i1=1;i1<n;i1++)
//			{
//				printf("[");
//				for(int j1=1;j1<n;j1++)
//				{
//					printf("%d",M[i1][j1]);
//					if(j1!=n-1)
//					{
//						printf(" ");
//					}
//				}
//				printf("]\n");
//			}
			
			
			//��������ʽ�Ľ� 
			int a,b,s,p,sum=0;
			
			//sum1
			for(int a1=0;a1<k;a1++)
			{
				s=1;p=0;a=1;b=1;b+=a1;
				for(int a2=0;a2<k;a2++)
				{
					if(b==n)
					{
						b=1;
					}
					s*=M[a][b];a++;b++;
					numble[a2]=a;
				}
				
			//���У��������� 
				for(int a=0;a<k;a++)
				{
					for(int a=0;a<k-1;a++)
					{
						if(numble[a]>numble[a+1])
						{
							int num=0;
							num=numble[a+1];
							numble[a+1]=((numble[a]>numble[a+1])?numble[a]:numble[a+1]);
							numble[a]=num;p++;
						}
					}
				}
				
			//s1
				if(p%2==0)
				{
					sum+=s;
				}
				else if(p%2==1)
				{
					sum-=s;
				}
//				printf("s%d=%d\n",a1+1,s); 
//				printf("sum%d=%d\n",a1+1,sum);
			}
			
			
			//sum2
			for(int a1=0;a1<k;a1++)
			{
				s=1;p=0;a=k;b=1;b+=a1;
				for(int a2=0;a2<k;a2++)
				{
					if(b==n)
					{
						b=1;
					}
					s*=M[a][b];a--;b++;
					numble[a2]=a;
				}
				
			//���У��������� 
				for(int a=0;a<k;a++)
				{
					for(int a=0;a<k-1;a++)
					{
						if(numble[a]>numble[a+1])
						{
							int num=0;
							num=numble[a+1];
							numble[a+1]=((numble[a]>numble[a+1])?numble[a]:numble[a+1]);
							numble[a]=num;p++;
						}
					}
				}
				
			//s2
				if(p%2==0)
				{
					sum+=s;
				}
				else if(p%2==1)
				{
					sum-=s;
				}
//				printf("s%d=%d\n",a1+1,s); 
//				printf("sum%d=%d\n",a1+1,sum);
			}
			if((i+j)%2==0)
			{
				B[i][j]=sum;
			}
			else if((i+j)%2==1)
			{
				B[i][j]=-sum;
			}
		}
	}
	
	//ת�� 
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			C[i][j]=B[j][i];
		}
	}
	
	//��ӡ 
	printf("\nCΪA�İ������C=\n");
	for(int i=1;i<m;i++)
	{
		printf("[");
		for(int j=1;j<m;j++)
		{
			printf("%d",C[i][j]);
			if(j!=n)
			{
				printf(" ");
			}
		}
		printf("]\n");
	}		
	return 0;
}
	
