#include <stdio.h>
/*배열과 포인터는 표기만 다를뿐 문법구조가 유사
data[n] 과 *(data+n)과 같다!
배열 변수의 이름은 배열의 시작주소!
&:주소를 얻겠다  *data:data가 가리키는 메모리
&(*data)상쇄!! ----data

*/
int main(){
    char data[5];
    data[1]=5;
    *(data+1)=5;  //data[1]=5;
    /*char data;
    char *p=&data;
    *p=3; //p[0]=3;*/
    char data[4];
    char *p =&data[0]; //배열의 첫번째 항목의 주소가 배열전체의 시작주소와 같음
    //char *p = & * (data+0)는 & * data 는 data;
    //주소를 얻는 &연산자와 주소를 지정하는*연산자는 서로반대개념의 연산자 서로상쇄!
    char*p=data; //Simple!!
}
int main(){
    char data[5]={1,2,3,4,5};
    int i,sum=0,select=2;
    // sum변수에 data[select](datap[2])요소값을 10번더함
    for(i=0;i<10;i++)
    sum= sum+data[select]; //sum+ *(data+select) 낭비!!

    char *p=data+select; //char*p = &data[select]와동일
    for(i=0;i<10;i++)
    sum=sum+ *p;  //Simple!!     
}
/*  char *형 변수 100개가필요한경우 char *p1,*p2,'''',*p100;
char *p[5]; //char *p1,*p2,*p3,*p4,*p5; 라고선언한 것과같음
포인터 5개선언한 것으로 p배열의 크기는 20바이트 
개별 포인터를 사용하려면 p[0],p[1],p[2],p[3],p[4],p[5] 같이 사용
int *p; 4바이트를 가리키는 포인터
char (*p)[5]; char5개짜리니 5바이트크기의 메모리를 가리키는p
(*p)[2]=7 p가 가리키는 대상의 5바이트중 3번쨰 항목에 7을저장
p++ //p=p+1;과 같으므로 주소가 5가증가!

*/

int main(){
    char data1,data2,data3,data4,data5,i;
    char *p[5]={&data1,&data2,&data3,&data4,&data5};
    for(i=0;i<5;i++)
        *p[i]=0;  //data1~data5에 모두 0이저장됨
}
int main(){
    char data[3][5];
    char (*p)[5];
    p=data;
    (*p)[1]=3; //p가 가리키는 대상의 2번째에 3을대입
    (*(p+1))[2]=4; //p+1이 가리키는 대상의 3번째 항목에4를 대입
    (*(p+2))[4]=5; //p+2이 가리키는 대상의 5번째 항목에5를 대입
}



