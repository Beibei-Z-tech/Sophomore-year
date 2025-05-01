//Question：有1,2,3,4个数字，能组成多少个互不相同的无重复数字的三位数？都是多少？
#include"stdio.h"
int main(){
	int i,j,k;
	printf("\n");
	for(i=1;i<5;i++){
		for(j=1;j<5;j++){
			for(k=1;k<5;k++){
				if(i!=k&&i!=j&&k!=j)
				printf("%d%d%d\n",i,j,k);
			}
		}
	}
	return 0;
}

