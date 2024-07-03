
20장 함수포인터
특정 함수를 구성하는 시작명령의 위치를 가리키는 포인터
함수포인터를 사용해서 함수를 호출하여 실행가능
int sim(int a,int b){
    int result=0; //이 명령문이 저장된 위치의 주소가 sum함수의 시작주소
    result=a+b;
    return result;
}
int result =sum(2,3);
&sum;  //sum함수의 첫번째 명령문 주소를 의미 &생략가능
함수포인터는 함수 원형을 사용해서 포인터를 선언

int(*p)(int,int); //sum함수를 가리킬 수 있는 함수포인터선언
p=&sum;   // sum함수의 주소를 p에저장
int result = (*p)(2,3); //int result=sum(2,3) 과 동일

int (*p[4])(int,int)={&sum,&&sub,&mul,&div};
함수의 주소를 4개저장하기 위해 함수의 포인터를 배열로 선언
int result[4],i;
for(i=0;i<4;i++)
result[i]=(*p[i])(8,2);
