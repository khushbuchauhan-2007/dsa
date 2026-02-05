#include<stdio.h>
void fun(char*pA);

int main()
{
    char myA[4] = {1, 9, 8, 6};
    fun (myA);
    return 0;

}
void fun(char*pA)
{ 
    int i = 0;
    while (i<4)
   {
      printf("%d\n",pA[i]);
      i++;
   }

}