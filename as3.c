#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{  if (argc==3)
   {  int no1;
      int ret=sscanf(argv[1],"%d",&no1);
      if (ret!=1)
      {  printf("\n ERROR- %s not an integer \n", argv[1]);
	 printf("Pass the first argument as an integer \n\n ");
         return 0;
      }
      int no2= atoi(argv[1]);
      printf("\n The order of matrix is : %d\n",no2);
      printf("The filename supplied is : %s \n\n", argv[2]);
   }
   else
   {  printf("exact two arguments needed \n order of matrix \n filename \n\n");
      return 0;
   }
   
   const int n=atoi(argv[1]);
// open the file

  FILE *fp=fopen(argv[2],"r");
  if (!fp)
  {  printf("\n error- no such file, \"%s\", exists\n\n", argv[2]);
     return 0;
  }

// declare siome global variable
  int i, j,k;
  double a[n][n+1];
  double factor;
  
// initialise thge matrix element ttozero
   for(i=0;i<n;i++)
   {
     for(j=0;j<n+1;j++)
     {
        a[i][j]=0;
     }
   }

//read matrix from file
   for(i=0;i<n;i++)
     {
       for(j=0;j<n+1;j++)
       { float b;
         fscanf(fp, "%f", &b);
         a[i][j]=b;
       }
     }

   printf("the matrix is \n");
   for(i=0;i<n;i++)
     {
       for(j=0;j<n+1;j++)
       { printf("%2.1f ",a[i][j]);
       }
       printf("\n");
     } 
  fclose(fp);
 
printf("\n  ");
printf("\n  ");
 
double a_backup[n][n+1];
 for(i=0;i<n;i++)
     {
       for(j=0;j<n+1;j++)
       { 
         a_backup[i][j]=a[i][j];
       }
     }

//gauss elimination

 for(j=0;j<n-1;j++)
  {  for(i=j+1;i<n;i++)
       {  
         factor = a[i][j]/a[j][j];
           for(k=0;k<n+1;k++)
              {  a[i][k]=a[i][k]-(factor*a[j][k]);
              }
     }
 }

printf("----------------------GAUSS ELIMINATION--------------------\n");
printf("\n");
 
printf("the gauss eliminated matrix is- \n");
   for(i=0;i<n;i++)
     {
       for(j=0;j<n+1;j++)
       { printf("%2.1f ",a[i][j]);
       }
       printf("\n");
     } 

//back substitution
  double sum=0;
  double x[n];
  x[n-1]=a[n-1][n]/a[n-1][n-1];
  for(i=n-2;i>=0;i--)
    { 
      sum=0;
      for(j=i+1; j<n;j++)
       { sum=sum+a[i][j]*x[j];
        }
      x[i]=(a[i][n]-sum)/a[i][i];
      }
printf("\n ");

 
//printing the solution
printf("solution for the given matrix using gauss elimination is \n");
  for(i=0;i<n;i++)
   printf("%2.1f , ",x[i]); 



printf("\n");
printf("--------------------GAUSS JORDAN---------------------------------\n");
 
//gauss jordan

 for(i=0;i<n;i++)
     {
       for(j=0;j<n+1;j++)
       { 
         a[i][j]=a_backup[i][j];//restoring the a matrix
       }
     }
  double c=0;
  int s,t;
  for(j=0; j<n; j++)
    {
     for(i=0; i<n; i++)
        {
         if(i==j)   //to make diagonal element one 
	   {
             c=a[i][i];
	     for(k=0; k<=n; k++)
		{    a[i][k]=a[i][k]/c;
                 }
           }

          if(i!=j) //non diagonal elements- make the enteries zero
            {
              c=a[i][j]/a[j][j];
              for(k=0; k<=n; k++)
                {
                    a[i][k]=a[i][k]-c*a[j][k];
                }
             }
   
        }
    }

   printf("the gauss jordon eliminated matrix is-\n");
   for(i=0;i<n;i++)
     {
       for(j=0;j<n+1;j++)
       { printf("%2.1f ",a[i][j]);
       }
       printf("\n");
     } 

printf("solution for the given matrix using gauss jordan elimination is \n");
for(i=0;i<n;i++)
 printf("%2.1f, ",a[i][n]); 


printf("\n");
printf("-----------------------GAUSS SIEDEL METHOD----------------\n  ");
 


  sum=0;
//restoring a and x
  for(i=0;i<n;i++)
     {
       for(j=0;j<n+1;j++)
       { 
         a[i][j]=a_backup[i][j];
       }
     }
  for(i=0;i<n;i++)
     {  x[i]=0;
     }
  double xtemp[]={0,0,0,0,0};
  int itr;



//gauss siedel method
for(i=0;i<n;i++)


for (itr=0;itr<=100;itr++)
{	
 for(i=0;i<n;i++)
     {sum=0;
       for(j=0;j<n;j++)
	   {    
		   if(j!=i)
		     sum=sum +a[i][j]*x[j];
	    }
		x[i]=(a[i][n]-sum)/a[i][i];
            }
	
}
 printf("the solution of the matrix using siedel method for iteretaion of 100- \n");
 for(i=0;i<n;i++)
       printf("%2.1f \n",x[i]);

 
 printf("\n  ");
printf("----------------------GAUSS JACOBI ITERATION--------------------\n");
 

 //Gauss-jacobi iteration
//restoring a and x
for(i=0;i<n;i++)
     {
       for(j=0;j<n+1;j++)
       { 
         a[i][j]=a_backup[i][j];
       }
     }
for(i=0;i<n;i++)
     {  x[i]=0;
       xtemp[i]=0;
     }


for (itr=0;itr<=100;itr++)
{	
 for(i=0;i<n;i++)
     {sum=0;
       for(j=0;j<n;j++)
	   {    
		   if(j!=i)
		     sum=sum +a[i][j]*x[j];
	    }
		xtemp[i]=(a[i][n]-sum)/a[i][i];
            }
 for(i=0;i<n;i++)
    { x[i]=xtemp[i];
    }
	
}
 printf(" the solution of the matrix using gauss jacobi method for iteretaion of 100-\n");
 for(i=0;i<n;i++)
       printf("    %2.1f \n",x[i]);


return 0;

}   
