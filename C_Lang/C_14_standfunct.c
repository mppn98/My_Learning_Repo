/*
14장----표준입력함수
표준입력버퍼: 특정 키를 누를떄까지 사용자입력을 임시로 저장하는 메모리  ex)키보드에서 "abc"입력>> 입력버퍼에 "abc"저장
*문자 한 개를 입력받는 getchar 함수:문자 한개를 입력받더라고 enter키를 눌러야만 작업이 완료됨
int input_data=getchar() //표준입력함수를 사용하여 문자한개를 입력
printf("input : %c\n",input_data);  //입력받은 문자 출력
rewind(stdin) //표준 입력 버퍼에있는 모든 입력 값을제거
*문자열을 입력받는 gets함수 enter키를 입력할떄까지 입력한 모든 문자를 하나의 문자열로본다.
char input_string[10];
gets(input_string); //문자열을 입력받아 input_string에저장
printf("input : %s\n",input_string);
gets함수는 입력 버퍼에 enter키가 남지 않는다.
enter키를 입력한 위치에 null문자0이 추가된다
gets 함수로 입력받은 숫자는 정수가 아닌 문자열로 인식됨
int data = "12345" //오류!! 문자열은 정수형 변수에 대입 불가!
만능표준입력함수 scanf 문자,문자열,정수,실수까지 모두 입력받기가능
%d 정수 %h short int %f 실수 %lf double %c %s
int data;
scanf("%d",&data); 
scanf(입력형식지정키워드,입력받은값저장할변수주소)
scanf 함수에서&연산자의 이유
scanf함수는 포인터 기술을 사영하여 값을 반환
scanf함수에서 입력된값을 구분하는 방법
1.엔터키를 사용하여 구분하기 2.공백을 사용하여 구분하기

*/