/*
17?---------------??????
??????:???? ??? ??? ???? ???
??? ??? ???? ??? ???? ??
short *p,data=5;
p= &data; //??? ??p? data??? ???? ??
1???????!--???? ??? 1???
??? ?? ??? *???? ??? ??? ??? ?????
??? ?? ??? ??? *??? ???? ???? ??? ? *??? ????
char *p1;  //1????? : p1,*p1  ????or??? ???? ??
char **p2; //2????? : p2,*p2,**p2  ??or???or?????
? ???? ??????? ??
*/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

short data=0;
int my_ptr =(int)&data;
data변수의 주소를 my__ptr에 저장하기위해 형 변환
4바이트크기의 변수이므로 포인터변수가 아니더라도 주소저장가능
*my_ptr=3;  오류! 포인터변수가 아니므로 *연산자 사용불가
2차원 포인터는 1차원 포인터의 주소값을 저장한다



int main(){
    //short **pp;  //2차원 포인터변수 p를선언
    //int data=3;
    //pp=(short**)&data; //1차원포인터를 빼고 바로일반변수의 주소를넣으면?
    //좋지않음
    short **pp,*p,data=3;
    p=&data; //data변수의 주소값이 포인터변수p에저장
    pp=&p; //1차원 포인터 p의 주소값이 2차원 포인터pp에저장
    **pp=5; //5로바뀜 데이터변수가
}

int main(){
    short data=3;
    short *p=&data;
    short**pp=&p;
    printf("before data: %d \n",data);
    *p=4;
    printf("use *p data : %d \n",data);
    **pp=5;
    printf("use **pp data : %d \n",data);
}
//2차원 포인터가 가리키는 대상을 동적으로 할당하기

int main(){
    short **pp,data=3;
    pp=(short**)malloc(4);  //4바이트크기의 메모리를 만들고 그주소를 pp에
    //pp=(short**)malooc(sizeof(short*)); //short* 의크기는 4바이트니까
    *pp=&data; //data변수의 주소값을 두번째 상자에저장
    **pp=5; //3에서 5로변경 
}
//malloc을 이용하여 2차원 포인터 구조만들기

void main(){
    short **pp;
    pp=(short**)malloc(sizeof(short*));
    *pp=(short*)malloc(sizeof(short));
    **pp=10;
    printf("**pp : %d\n",**pp);
    free(*pp);
    free(pp);
}
//2차원 포인터로 8바이트동적메모리를 할당하는 함수만들기

void GetMyData(int**q){  //포인터변수 q에 p변수의 주소를저장
    *q=(int*)malloc(8); 
}   //할당된 메모리의 주소값을 포인터 q가 가리키는 p에저장
void main(){
    int *p;   //p는 초기화 되지않아서 쓰레기값저장
    GetMyData(&p);  //포인터변수 p의 주소값을 매개변수로 전달
    *p=5;  //할당된 메모리의 첫4바이트에 값5를 넣음 
    free(p);  //할당된 동적 메모리를 해제
}
/*여러개의 1차원포인터를 정적으로 할당하기
short *p[100]; //short* 형식의 1차원 포인터를 100개 선언
배열의 요소가100개 각요소의 크기는 4바이트
전체메모리 크기는 400바이트
p[0]~p[99] 총100개의 포인터 사용가능
메모리낭비가심함----------
short**pp;
pp=(short**)malloc(sizeof(short*));  */
int main(){
int n;
short **pp;
scanf("&d",&n);  //사용할 1차원 포인터의개수를 사용자에게 입력받음
pp=(short**)malloc(sizeof(short*)*n); //short*형식의 1차원포인터 n개할당
}
/*2차원 배열과 동적 메모리할당
회사에서 직원들을 체력테스트 결과 저장하는 프로그램 만든다가정
20대 4명  30대 2명  40대 3명
1분간 윗몸일으키기 후 이횟수를 연령별로저장
1.1명이 1분동안 수행한 윗몸일으키기 횟수를 저장하기위한 자료형(메모리크기)결정하기
0~200 사이 값을 저장하면되기 떄문에 unsigned char 자료형 사용 1바이트면충분
2.어떤 배열구조를 사용할지 정하기
연령별 그룹수(3그룹)과 각 그룹별 인원수(최대4명)고려하여 2차원배열구조사용
    unsigned char count[3][4]; //3개의 그룹에 최대4명의 사람관리 
    count[0][1]=49; //20대연령의 두번째사람
    count[1][0]=45; //30대연령의 첫번째사람
    count[2][2]=42; //40대연령의 세번째사람
*/

int main(){
    unsigned char limit_table[3]={4,2,3};
    unsigned char count[3][4]; //연령별 윗몸일으키기 횟수를 저장할 배열
    int age,member,temp,sum;
    for(age=0;age<3;age++){
        printf("\n%d0대 연령의 윗몸일으키기 횟수\n",age+2);
        for(member=0;member<limit_table[age];member++){
            printf("%dth : ",member+1);
            scanf("%d",&temp);
            count[age][member]=(unsigned char)temp;
        }
    }
    printf("\n\n연령별 평균 윗몸 일으키기 횟수\n");
    for(age=0;age<3;age++){
        sum=0;
        printf("%d0대 : ",age+2);
        for(member=0;member<limit_table[age];member++){
            sum=sum+count[age][member];
        }
        printf("%5.2f\n",(double)sum/limit_table[age]);
    }
}
/*조건추가
1.각 연령층에 포함된 인원수가 변한다면?
연령층의수가4명 이상이되면 count배열에 모든직원의 일으키기횟수를 저장못하는 문제발생
-----------동적할당으로 문제해결!!
    unsigned char limit_table[3]={4,2,3};
    unsigned char *p[3]; //1차원 포인터 3개를 선언
    for(age=0;age<3;age++){
        p[age]=(unsigned char *)malloc(limit_table[age]);
    }  //메모리 낭비가없음
    for(age=0;age<3;age++)free(p[age]);
2.연령층이 50,60대도??
unsigned char *p_limit_table; 연령층별 인원수를 저장할 포인터
unsigned char **p;  1차원포인터를 n개선언할 2차원포인터
int age_step=3,age;  //연령대의개수 10,20,30대
//연령층별 인원수를 저장할 메모리를 동적으로 할당함
p_limit_table=(unsigned char *)malloc(age_step);
p_limit_table[0]=4;   20대 4
p_limit_table[1]=2;   30대 2
p_limit_table[2]=3;   40대 3
 //연령층별로 윗몸일으키기 횟수를 저장할 포인터를 연령층 개수만큼 만듬
p=(unsigned char**)malloc(sizeof(unsigned char*)*age_step);
//연령층별로 입력된 인원수만큼 동적으로 메모리를 할당함
for(age=0;age<age_step;age++){
    *(p+age)=(char*)malloc(*(p_limit_table+age));
}'''''
//메모리정리
for(Age=0;age<age_step;age++)free(*(p+age));
free(p); 1차원포인터 메모리해제
free(p_limit_table);  연령별 인원수를 저장하기 위해 만든ㄴ 메모리를해제 
//연령층별로 입력된 인원수만큼 동적으로 메모리할당
*/
1조건
int main(){
    unsigned char limit_table[3],*p[3];
    int age,member,temp,sum;

    for(age=0;age<3;age++){
        printf("\n%d0대 연령의 윗몸일으키기 횟수\n",age+2);
        printf("이 연령대는 몇명입니까? : ");
        scanf("%d",&temp);
        limit_table[age]=(unsigned char)temp;

        p[age]=(unsigned char *)malloc(limit_table[age]); //인원수만큼 메모리할당
        for(member=0;member<limit_table[age];member++){
            printf("%dth : ",member+1);
            scanf("%d",&temp);
            *(p[age]+member)=(unsigned char)temp;
        }
    }
    printf("\n\n연령별 평균 윗몸 일으키기 횟수\n");
    for(age=0;age<3;age++){
        sum=0;
        printf("%d0대 : ",age+2);
        for(member=0;member<limit_table[age];member++){
            sum=sum+*(p[age]+member);
        }
        printf("%5.2f\n",(double)sum/limit_table[age]);
        free(p[age]);  //이연령에 할당했던 동적 메모리 해제     
    }
} 
//-----------------최종 2차원포인터로 연령별 윗몸일으키기 횟수관리하기

int main(){
    unsigned char *p_limit_table,**p;
    int age,age_step,member,temp,sum;
    printf("20대부터 시작해서 연령층이 몇개인가요 : ");
    scanf("%d",&age_step)  ;
    //연령별 인원수를 저장할 메모리를 만듦
    p_limit_table=(unsigned char *)malloc(age_step);
    p = (unsigned char**)malloc(sizeof(unsigned char *)* age_step);

    for(age=0;age<age_step;age++){
        printf("\n%d0대 연령의 윗몸일으키기 횟수\n",age+2);
        printf("이 연령대는 몇명입니까? : ");
        scanf("%d",&temp);
        *(p_limit_table+age)=(unsigned char)temp;
        *(p+age)=(unsigned char*)malloc(*(p_limit_table+age));//메모리할당
        for(member=0;member<*(p_limit_table+age);member++){
            printf("%dth : ",member+1);
            scanf("%d",&temp);
            *(*(p+age)+member)=(unsigned char)temp;
        }
    }
    printf("\n\n연령별 평균 윗몸 일으키기 횟수\n");
    for(age=0;age<age_step;age++){
        sum=0;
        printf("%d0대 : ",age+2);
        for(member=0;member<*(p_limit_table+age);member++){
            sum=sum+*(*(p+age)+member);
        }
        printf("%5.2f\n",(double)sum/ *(p_limit_table+age));
        free(*(p+age));  //이연령에 할당했던 동적 메모리 해제
    }
    free(p); //윗몸 일으키기 횟수를 저장하는 메모리를 해제함
    free(p_limit_table); //연령별 인원수 저장하는 메모리를 해제함
}
