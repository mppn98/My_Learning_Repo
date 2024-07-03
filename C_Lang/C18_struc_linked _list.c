#include <stdio.h>
/* 구조체: 서로다른 데이터를 그룹
typedef=type define의줄임 표현
자료형 이름의 길이가 긴경우 자료형을 재정의해 사용하는 문법
typedef  unsigned short int US //unsigned short int형을 US라는 새로운이름으로 정의
US temp;
typedef int my_data[5];
my_data temp;  //int temp[5]와같음
배열의 한계:크기가같은 데이터만 그룹으로 묶을수있음
나이,키,몸무게 별로 그룹을 나누는 것보다 특정사람의 정보를 모아서 그룹으로 만드는것이 효율적
구조체: 크기나 형식이 다른데이터를 그룹지을수 있음
struct 구조체이름{
    자료형1 변수 이름1;
    자료형2 변수 이름2;
    자료형3 변수 이름3;
};
*/

typedef struct people{   //people안적고 person;으로가능
    char name[12];  //이름 12바이트
    unsigned short int age;  //나이 2바이트
    float height;  //4
    float weight;  //4
}person;

typedef struct people person;  //person이라는 자료형으로 재정의
int main(){
    struct people data;  //일반변수 data변수의 크기는 22바이트 {}안에 선언한 요소들의 크기의합
    struct people friend_list[64];  //22*64크기 바이트
    struct people *p;  //p는 포인터변수 크기4바이트

    person data;  //person자료형으로 data변수선언
    person friend_list;
    person *p;

    data.age=21;  //22바이트중 2바이트차지
    data.height=178.3; //4바이트
}
 구조체를 사용하여 사람의 신체정보입력받고출력
typedef struct people{   
    char name[12];  //이름 12바이트
    unsigned short int age;  //나이 2바이트
    float height;  //4
    float weight;  //4
}person;
int main(){
    person data;
    printf("대상자의 정보를 입력하세여\n");
    printf("이름 : ");
    scanf("%s",data.name);
    printf("나이 : ");
    scanf("%hu",&data.age);
    printf("키 : ");
    scanf("%f",&data.height);
    printf("몸무게 : ");
    scanf("%f",&data.weight);

    printf("%s : %d세, %.1fcm, %.1fkg\n",data.name,data.age,data.height,data.weight);
}

int main(){
    person freinds[3];  //person 데이터 3개를 저장할수있는 66바이트할당
    freinds[1].age=22;  //두번째 요소의 age에 22대임
    
    person data;
    person *p;
    p=&data;
    //(*p).age=23;   //*p.age 오류!! 연산자우선순위조심
    p->age=23;   // 위에식과동일

    struct people data={"홍길동,51,184.2,79"};
}


#define MAX_COUNT 5
int main(){
    person friends[MAX_COUNT];
    int count=0,num;
}
int addfreind(person *p_friend,int count){
    p_friend= p_friend+count;

    printf("이름 : ");
    scanf("%s",p_friend->name);
    printf("나이 : ");
    scanf("%hu",&p_friend->age);
    printf("키 : ");
    scanf("%f",&p_friend->height);
    printf("몸무게 : ");
    scanf("%f",&p_friend->weight);
}
void showfriendlist(person *p_friend,int count){
    printf("친구목록");
    for(int i=0;i<count;i++){
        printf("%-14s, %3d, %6.2f, %6.2f\n",p_friend->name,p_friend->age,p_friend->height,p_friend->weight);

    }
}
/* 구조체의 요소는 같은크기끼리 모아주는것이 좋다
구조체의 크기를 구할때에는 sizeof연산자를 사용하는것이 안전
struct test *p1 = (struct test *)malloc(16); //오류일수도
struct test *p2 = (struct test *)malloc(sizeof(struct test));
사용자에게 묻지않고 프로그램이 알아서 동적메모리 할당하기
여러개의 숫자를 입력받아서 합산하는 더히기 프로그램을 만든다고 가정
배열:정해진 숫자만큼 배열을 선언하여 숫자를 입력받음
동적할당: 사용자에게 숫자의 개수를 입력받아 그 개수만큼 메모리를 동적할당하여 숫자를저장
연결리스트:사용자가 입력한 모든 숫자를 저장하고 합산
*/
/*사용자가 입력한 숫자를 저장하기 위해 동적으로 할당된 메모리의 주소값을
저장하려면 그 개수만큼 포인터 필요 */
// 포인터1 --> 숫자1ㅣ포인터2   오른쪽꺼가 노드
// 노드:연결리스트에서 숫자와 포인터를 함께 저장하기 위해 할당한메모리


1단계:연결리스트의 시작상태
동적으로 할당되는 첫노드의 주소값을 저장해야 하기때문에 포인터가필요
연결 리스트의 시작점이 되는포인터가 헤드포인터 --주의:노드아님!!
NODE *p_head=NULL;  // 첫노드를 가리킬 헤드포인터선언,null을초기값으로 대입
//헤드포인터: 가리키는대상이없음
2단계: 숫자12를 저장하기위해 새 노드추가
새로운 노드를 위한 메모리를 malloc으로 동적할당
할당된 새노드의 주소값은 헤더포인터에 저장
할당된 노드의 number에는12,p_next에는 null을대입
p_head=(NODE*)malloc(sizeof(NODE)); //노드크기만큼 동적할당,새노드추가
p_head->number=12;
p_head->p_next =NULL; //다음노드가 없음을명시
3단계: 숫자 15를 저장하기위해 새 노드추가
p_head->p_next=(NODE*)malloc(sizeof(NODE));
p_head->p_next->number=15; 
p_head->p_next->p_next=null;



//100개가 추가되었고 101번째 노드를 추가해야한다면?
NODE *p=p_head;
//p_next가 null일때까지 반복 null이면 마지막노드라는뜻
while(NULL !=p->p_next){
    p=p->p_next;  //p->p_next값을 p에 대입하면 p는 다음주소로이동
}

typedef struct node{
    int number; //숫자를 저장할변수
    struct node *p_next;//다음 노드를 가리킬 포인터
}NODE;
