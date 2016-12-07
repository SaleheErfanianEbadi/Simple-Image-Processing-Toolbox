#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{

       int i = 0 ;
       int j = 0;
       int a[9] = { 2 ,3 , 1 , 4 , 6 , 2 };
       int tempR;
              

       
       for(i=0;i <5;i++)  
               for(j=i;j < 5 ;j++)   
               {
                     if(a[i] > a[j])
                                         {
                     tempR=a[i];
                     a[i]=a[j];
                     a[j]=tempR;
                     j=i;
                                         }
               }

                                        
               for(j=0;j < 5 ;j++)   
               {
                                       cout << a[j] << "\t";

                               }

                               return 0;
}
