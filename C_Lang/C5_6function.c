/*5장함수---
한개의 프로그램에서 main함수는 반드시 한개만 있어야함
피호출자>호출자순으로 or 함수선언하고 main밑에 함수정의
*/
#include <stdio.h> //헤더파일임 함수원형들을 특정파일에 미리선언 해두고 사용
				   // 중괄호안에 main함수가 작업할 내용
//반환형 함수이름 (매개변수)

int sum(int value1, int value2)
{	int result =value1 + value2;
	return result; //반환값
}
int main()
{	int a=2,b=3,value;
	value =sum(a,b);
    printf("%d",value);
}

int sum(int, int); //함수원형 선언할때 매개변수 이름 생략가능*/

/*6장 표준출력 함수
라이브러리: C에서 함수를 효과적으로 관리할 수 있도록 제공하는기술
6-3 전처리기 : 프로그래머가 원하는 사항을 컴파일러에 직접지시하는 문법
#으로 시작 ;사용XX
#include "읽을파일 이름" OR<> :소스파일에 헤더파일을 포함하여 컴파일
#define 전처리기는 상수나 명령문을 치환하는 문법
#define 치환할이름 치환할내용  ex) #define MAX_COUNT 3
3이라는 상수를 MAX_COUNT로 치환
int data=MAX_COUNT;
#define POWVALUE(a)  (a*a)
int data =POWVALUE(3);  int data = (3*3); 으로 번역됨
*/

/*putchar, putc :단일 문자 출력함수
putchar(65); 아스키 값 65에 해당하는 문자 A가 출력됨
putchar('A'); 문자 A가 출략됨
puts : 문자열 출력 함수
puts("HI~");  HI~ 출력후에 줄 바꿈이 일어남 */

int main() {
	char data = 65;
	printf("%c의 ASCII값은 %d입니다.", data, data);  //A의값은 65입니다
	//  %뒤에 뭐가오느냐가 더 중요
	//  %전체칸수.소수점 자릿수f
	// %8.4f 는 8자리수 소수점이하 4자리
}