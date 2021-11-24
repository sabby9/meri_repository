#include<unistd.h>
#include<sys/syscall.h>
#include<stdio.h>
#include<linux/kernel.h>

#define sys_kernel_2d_memcpy 335

int main(){
  int row = 3,column = 3;
  float orignalmatrix[row][column] = {{1,1,1},{2,2,2},{3,3,3}};
  float copiedmatrix[row][column];
  long int x = syscall(sys_kernel_2d_memcpy,*orignalmatrix,*copiedmatrix,row,column);
  printf("%s \n \n","Copied Matrix-");
  for(int i = 0 ; i < 3 ; i++){for(int j = 0 ; j < 3 ; j++){printf(" %f ",copiedmatrix[i][j]);}printf("\n");}
  return 0;
}


