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
data������ �ּҸ� my__ptr�� �����ϱ����� �� ��ȯ
4����Ʈũ���� �����̹Ƿ� �����ͺ����� �ƴϴ��� �ּ����尡��
*my_ptr=3;  ����! �����ͺ����� �ƴϹǷ� *������ ���Ұ�
2���� �����ʹ� 1���� �������� �ּҰ��� �����Ѵ�



int main(){
    //short **pp;  //2���� �����ͺ��� p������
    //int data=3;
    //pp=(short**)&data; //1���������͸� ���� �ٷ��Ϲݺ����� �ּҸ�������?
    //��������
    short **pp,*p,data=3;
    p=&data; //data������ �ּҰ��� �����ͺ���p������
    pp=&p; //1���� ������ p�� �ּҰ��� 2���� ������pp������
    **pp=5; //5�ιٲ� �����ͺ�����
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
//2���� �����Ͱ� ����Ű�� ����� �������� �Ҵ��ϱ�

int main(){
    short **pp,data=3;
    pp=(short**)malloc(4);  //4����Ʈũ���� �޸𸮸� ����� ���ּҸ� pp��
    //pp=(short**)malooc(sizeof(short*)); //short* ��ũ��� 4����Ʈ�ϱ�
    *pp=&data; //data������ �ּҰ��� �ι�° ���ڿ�����
    **pp=5; //3���� 5�κ��� 
}
//malloc�� �̿��Ͽ� 2���� ������ ���������

void main(){
    short **pp;
    pp=(short**)malloc(sizeof(short*));
    *pp=(short*)malloc(sizeof(short));
    **pp=10;
    printf("**pp : %d\n",**pp);
    free(*pp);
    free(pp);
}
//2���� �����ͷ� 8����Ʈ�����޸𸮸� �Ҵ��ϴ� �Լ������

void GetMyData(int**q){  //�����ͺ��� q�� p������ �ּҸ�����
    *q=(int*)malloc(8); 
}   //�Ҵ�� �޸��� �ּҰ��� ������ q�� ����Ű�� p������
void main(){
    int *p;   //p�� �ʱ�ȭ �����ʾƼ� �����Ⱚ����
    GetMyData(&p);  //�����ͺ��� p�� �ּҰ��� �Ű������� ����
    *p=5;  //�Ҵ�� �޸��� ù4����Ʈ�� ��5�� ���� 
    free(p);  //�Ҵ�� ���� �޸𸮸� ����
}
/*�������� 1���������͸� �������� �Ҵ��ϱ�
short *p[100]; //short* ������ 1���� �����͸� 100�� ����
�迭�� ��Ұ�100�� ������� ũ��� 4����Ʈ
��ü�޸� ũ��� 400����Ʈ
p[0]~p[99] ��100���� ������ ��밡��
�޸𸮳��񰡽���----------
short**pp;
pp=(short**)malloc(sizeof(short*));  */
int main(){
int n;
short **pp;
scanf("&d",&n);  //����� 1���� �������ǰ����� ����ڿ��� �Է¹���
pp=(short**)malloc(sizeof(short*)*n); //short*������ 1���������� n���Ҵ�
}
/*2���� �迭�� ���� �޸��Ҵ�
ȸ�翡�� �������� ü���׽�Ʈ ��� �����ϴ� ���α׷� ����ٰ���
20�� 4��  30�� 2��  40�� 3��
1�а� ��������Ű�� �� ��Ƚ���� ���ɺ�������
1.1���� 1�е��� ������ ��������Ű�� Ƚ���� �����ϱ����� �ڷ���(�޸�ũ��)�����ϱ�
0~200 ���� ���� �����ϸ�Ǳ� ������ unsigned char �ڷ��� ��� 1����Ʈ�����
2.� �迭������ ������� ���ϱ�
���ɺ� �׷��(3�׷�)�� �� �׷캰 �ο���(�ִ�4��)����Ͽ� 2�����迭�������
    unsigned char count[3][4]; //3���� �׷쿡 �ִ�4���� ������� 
    count[0][1]=49; //20�뿬���� �ι�°���
    count[1][0]=45; //30�뿬���� ù��°���
    count[2][2]=42; //40�뿬���� ����°���
*/

int main(){
    unsigned char limit_table[3]={4,2,3};
    unsigned char count[3][4]; //���ɺ� ��������Ű�� Ƚ���� ������ �迭
    int age,member,temp,sum;
    for(age=0;age<3;age++){
        printf("\n%d0�� ������ ��������Ű�� Ƚ��\n",age+2);
        for(member=0;member<limit_table[age];member++){
            printf("%dth : ",member+1);
            scanf("%d",&temp);
            count[age][member]=(unsigned char)temp;
        }
    }
    printf("\n\n���ɺ� ��� ���� ����Ű�� Ƚ��\n");
    for(age=0;age<3;age++){
        sum=0;
        printf("%d0�� : ",age+2);
        for(member=0;member<limit_table[age];member++){
            sum=sum+count[age][member];
        }
        printf("%5.2f\n",(double)sum/limit_table[age]);
    }
}
/*�����߰�
1.�� �������� ���Ե� �ο����� ���Ѵٸ�?
�������Ǽ���4�� �̻��̵Ǹ� count�迭�� ��������� ����Ű��Ƚ���� ������ϴ� �����߻�
-----------�����Ҵ����� �����ذ�!!
    unsigned char limit_table[3]={4,2,3};
    unsigned char *p[3]; //1���� ������ 3���� ����
    for(age=0;age<3;age++){
        p[age]=(unsigned char *)malloc(limit_table[age]);
    }  //�޸� ���񰡾���
    for(age=0;age<3;age++)free(p[age]);
2.�������� 50,60�뵵??
unsigned char *p_limit_table; �������� �ο����� ������ ������
unsigned char **p;  1���������͸� n�������� 2����������
int age_step=3,age;  //���ɴ��ǰ��� 10,20,30��
//�������� �ο����� ������ �޸𸮸� �������� �Ҵ���
p_limit_table=(unsigned char *)malloc(age_step);
p_limit_table[0]=4;   20�� 4
p_limit_table[1]=2;   30�� 2
p_limit_table[2]=3;   40�� 3
 //���������� ��������Ű�� Ƚ���� ������ �����͸� ������ ������ŭ ����
p=(unsigned char**)malloc(sizeof(unsigned char*)*age_step);
//���������� �Էµ� �ο�����ŭ �������� �޸𸮸� �Ҵ���
for(age=0;age<age_step;age++){
    *(p+age)=(char*)malloc(*(p_limit_table+age));
}'''''
//�޸�����
for(Age=0;age<age_step;age++)free(*(p+age));
free(p); 1���������� �޸�����
free(p_limit_table);  ���ɺ� �ο����� �����ϱ� ���� ���礤 �޸𸮸����� 
//���������� �Էµ� �ο�����ŭ �������� �޸��Ҵ�
*/
1����
int main(){
    unsigned char limit_table[3],*p[3];
    int age,member,temp,sum;

    for(age=0;age<3;age++){
        printf("\n%d0�� ������ ��������Ű�� Ƚ��\n",age+2);
        printf("�� ���ɴ�� ����Դϱ�? : ");
        scanf("%d",&temp);
        limit_table[age]=(unsigned char)temp;

        p[age]=(unsigned char *)malloc(limit_table[age]); //�ο�����ŭ �޸��Ҵ�
        for(member=0;member<limit_table[age];member++){
            printf("%dth : ",member+1);
            scanf("%d",&temp);
            *(p[age]+member)=(unsigned char)temp;
        }
    }
    printf("\n\n���ɺ� ��� ���� ����Ű�� Ƚ��\n");
    for(age=0;age<3;age++){
        sum=0;
        printf("%d0�� : ",age+2);
        for(member=0;member<limit_table[age];member++){
            sum=sum+*(p[age]+member);
        }
        printf("%5.2f\n",(double)sum/limit_table[age]);
        free(p[age]);  //�̿��ɿ� �Ҵ��ߴ� ���� �޸� ����     
    }
} 
//-----------------���� 2���������ͷ� ���ɺ� ��������Ű�� Ƚ�������ϱ�

int main(){
    unsigned char *p_limit_table,**p;
    int age,age_step,member,temp,sum;
    printf("20����� �����ؼ� �������� ��ΰ��� : ");
    scanf("%d",&age_step)  ;
    //���ɺ� �ο����� ������ �޸𸮸� ����
    p_limit_table=(unsigned char *)malloc(age_step);
    p = (unsigned char**)malloc(sizeof(unsigned char *)* age_step);

    for(age=0;age<age_step;age++){
        printf("\n%d0�� ������ ��������Ű�� Ƚ��\n",age+2);
        printf("�� ���ɴ�� ����Դϱ�? : ");
        scanf("%d",&temp);
        *(p_limit_table+age)=(unsigned char)temp;
        *(p+age)=(unsigned char*)malloc(*(p_limit_table+age));//�޸��Ҵ�
        for(member=0;member<*(p_limit_table+age);member++){
            printf("%dth : ",member+1);
            scanf("%d",&temp);
            *(*(p+age)+member)=(unsigned char)temp;
        }
    }
    printf("\n\n���ɺ� ��� ���� ����Ű�� Ƚ��\n");
    for(age=0;age<age_step;age++){
        sum=0;
        printf("%d0�� : ",age+2);
        for(member=0;member<*(p_limit_table+age);member++){
            sum=sum+*(*(p+age)+member);
        }
        printf("%5.2f\n",(double)sum/ *(p_limit_table+age));
        free(*(p+age));  //�̿��ɿ� �Ҵ��ߴ� ���� �޸� ����
    }
    free(p); //���� ����Ű�� Ƚ���� �����ϴ� �޸𸮸� ������
    free(p_limit_table); //���ɺ� �ο��� �����ϴ� �޸𸮸� ������
}
