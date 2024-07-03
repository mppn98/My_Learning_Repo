
8장 조건문---
if(조건수식) 명령문;
switch조건문  정해진 상수를 여러번 비교하는경우 switch문이 효율적
switch(수식 또는 변수){
	case 상수1;
	명령문2;
	break;
	
	default;
	------;
}

#include <stdio.h>

int main() {
	int data = 5;
	if (data > 3) 
		printf("data는 3보다 큰수입니다.\n");
	printf("작업종료 \n");
	return 0;

	if (data > 5) return 1; //if 문 사용
	else return 0;

	return(data > 5) ? 1 : 0;  //조건 수식 연산자 사용
}

/*9장-반복문
for(시작조건;종결조건;조건변화수식) 명령문;
while(종결조건) 명령문;
*/


int main() {
	int sum = 0, num;

	for (num = 1; num <= 5; num++) {
		sum = sum + num;
	}
	int sum = 0, num = 1;
	while (num <= 5) {
		sum = sum + num;
		num++;
	}
	return 0;

}
