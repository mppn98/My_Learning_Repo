/*
16장 메모리할당
프로그램:프로그래머가 만든 프로그램 실행파일
프로세스:cpu가 실행파일에 있는 명령들을 실행할 수 있도록 운영체제가 실행 파일의 명령들을 읽어서 메모리에 재구성한것.
데이터를 저장할 공간을 적정하게 나누는 작업이 메모리할당!
정적메모리할당: 컴파일러가 그시점에 변수에 크기에 맞게 메모리를 할당하는것/프로그램이 실행될 때 메모리의 위치가 결정됨
정적으로 할당된 메모리를 관리하는법:지역변수를 시작위치 포인터와 끝 위치포인터를 사용하여 관리가능
프로세스 안에서 지역변수가 저장되는 기본스택 메모리 크기는 1MByte
char data[1024*1024] //오류발생!!
동적메모리할당!!: 원하는 시점에 원하는 크기만큼 힙메모리에 할당가능
메모리사용이 끝나면 언제든지 할당한 메모리 해제가능/Giga byte단위까지 할당가능
c표준함수 malloc함수를 사용해서 메모리할당가능
함수원형: void*malloc(size);  size는 unsigned int와 같은 자료형
함수 사용형식 : void *p=malloc(100);  100바이트의 메모리를 할당하여 포인터p에저장

*/
#include <stdio.h>
#include <malloc.h> 
/* c표준함수 malloc함수를 사용해서 메모리할당가능
함수원형: void*malloc(size);  size는 unsigned int와 같은 자료형
함수 사용형식 : void *p=malloc(100);  100바이트의 메모리를 할당하여 포인터p에저장
void *형식으로 주소를 반환 
free함수로 할당된 메모리해제하기!
*/

int main(){
    short *p=(short*)malloc(100); //50개그룹
    int *p=(int*)malloc(100); //100바이트를 4바이트단위로쓰고싶다,25개그룹
    free(p) //p가 가지고있는 주소에 할당된 메모리를 해제
} 

void main(){
    char *p_name;
    p_name=(char*)malloc(32); //32바이트 메모리를 동적할당
    if(p_name!=NULL){   //메모리 할당성공
        printf("Your name : ");
        gets(p_name);
        printf("Hi! %s\n",p_name);
        free(p_name); //포인터변수 p_name에 동적할당된 메모리를해제
    }
    else{
        printf("Memory allocation error!!"); //메모리 할당실패
    }
}

int main(){
    int *p=(int*)malloc(12); //int data[3]과같음  12바이트할당!!
    int*p=(int*)malloc(sizeof(int)*3);//4바이트크기 3개를 원하는구나
    int data_size=3;
    int*p=(int*)malloc(data_size); //메모리할당 크기를 변수로지정가능
}