
/*
12장--배열과 문자열
배열:자료형이 같은 변수들을 그룹으로 묶어서 관리할때
자료형 변수이름 [요소개수];  
문자열을 다루는 c내장함수 string.h 파일에서 함수의 원형제공
strlen : 문자열의 길이를 구하는 문자열 표준 함수
strcpy : 문자열을 복사하는 문자열 표준함수
strcat: 문자열 뒤에 다른 문자열을 덧붙이는 문자열 표준함수
*/
#include <stdio.h>

//short student [20] 2바이트 정수형데이터 20개를 저장할수있는배열 선언 전체40바이트

int main() {

	short student[20] = { 0, }; //이렇게하면 나머지 다0으로 초기화됨
		//배열 선언할때[]안의 요소개수 생략하고 선언가능
	//short data[] = { 1,2,3,1,2 };
	//char data[6] = { 'h','a','p','p','y',0 };
	char data[6] = "happy";  //문자열의 끝에 null이 자동으로 포함됨
	//문자 개수는 5개이고  끝에0을 덧붙여야하므로 배열의 크기는6
	printf("%s \n", data);  //문자열출력할떄는 %s
}

//배열에 저장된 문자열의 길이를 구하는 getstringlength 함수만들기
int getstringlength(char data[]) {
	int count = 0;
	while (data[count])
		count++;   //0이 나올때까지 문자의 개수를 더함
	return count;
}
void main() {
	int data_length;
	char data[10] = "happyy";
	data_length = getstringlength(data);
	printf("data length = %d\n", data_length);
}

#include <string.h>
void main() {
	int data_length;
	char data[10] = "happy";
	data_length = strlen(data);
	printf("data lengrh = %d", data_length);
}
//2차원 배열
//char data[5][4]; //4개씩 가지고있는 배열 5개
//char temp[2][3]={ { 1, 2, 3 }, { 4,5,6 } };


