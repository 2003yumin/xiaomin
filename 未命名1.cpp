//ATM
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Start();
void Exit();
void Qury();
int Log_On();
void Mune();
void Withdraw_Money();
void rpassward(char  *p);
void Transfer_Money();
struct user
{
    char zh[20];
    char mm[10];
    int money;

};
struct user users[10];
int count=0;
int t=0;
int main()
{

    Start();
    t = Log_On();
    Mune();

    Exit();
}
void Mune()
{
    int c=0; 
    while(1)
    {
        printf("��ѡ����ķ���\n");
        printf("1-ȡ��,2-ת��,3-����ѯ,4-�޸�����,5-�˳�\n");
        scanf("%d",&c);
         switch(c)
        {
            case 1:Withdraw_Money(&users[t].money);break;
            case 2:Transfer_Money();break;
            case 3:Qury();break;
            case 4:rpassward(users[t].mm);break;
            case 5:printf("��ӭ�´ι���\n");return;
            

        }
    }


}
int Log_On()
{
    char account[20];
    char  pw[10];
    int i;
    while(1)
    {
    printf("�������ʺ�:\n");
    gets(account);
    printf("����������:\n");
    gets(pw);
    for(i=0;i<count;i++)
    {
        if(strcmp(account,users[i].zh)==0)
            if(strcmp(pw,users[i].mm)==0)
                {
                t = i;
                break;
                }

    }
    if(i<count)
        break;
     printf("������ʺ��������!!!\n���������:\n");
    }
	
}
void Start()
{
    FILE *rp=fopen("users.txt","r");
    int i=0;
    if(rp != NULL)
    {
        while(fscanf(rp,"%s%s%d",users[i].zh,users[i].mm,&users[i].money)!=EOF)
            {
                i++;
                count++;
            }
    }
    fclose(rp);
}

void Exit()
{
    FILE *wp = fopen("users.txt","w");
    int i; 
     for( i = 0;i<count;i++)
     {
         fprintf(wp,"%s %s %d\n",users[i].zh,users[i].mm,users[i].money);
     }
     fclose(wp);
}
void rpassward(char  *p)
{
    char mm[10],rmm[10];
    int i=0;
    scanf("%*c");
    while(1)
    {
        printf("����������:\n");
        gets(mm);
        printf("���ٴ�ȷ������:\n");
        gets(rmm);
        if(strcmp(mm,rmm)==0)
        {
            strcpy(p,mm);
            printf("�޸ĳɹ�\n");
            return;
        }
        else
        {
            printf("�����������벻�����\n");
            continue;
        }
    }
}
void Qury()
{
	printf("�������Ϊ:\n");
	printf("%d\n",users[t].money);
} 
void Withdraw_Money(int *p)
{
	int money;
	printf("����������ȡ���:\n");
	scanf("%d",&money);
	while(1)
	{
		if(money< *p)
		{
			printf("�ɹ�ȡ��\n");
			*p -= money;
			break;
		}
		else 
		{
			printf("����");
			break;			
		}
	}
}
void Transfer_Money()
{
	char zh[20];
	int money;
	int t1,i;
	scanf("%*c");
	
	while(1)
	{
		printf("����ת���˻�\n"); 
		gets(zh);
		for(i=0;i<count;i++)
		{
			if(strcmp(zh,users[i].zh)==0)
 			{
				t1 = i;
				break;
    		}

    	}
		if(i<count)
    		break;
   		else
   		printf("���˻�����������������\n");
	}
	printf("������ת�˽��\n");
	scanf("%d",&money);
	if(users[t].money>money)
	{
		users[t].money -= money;
		users[t1].money += money;
		printf("ת�˳ɹ�\n");
	}
	else
	{
		printf("Ǯ����ת��ʧ��\n");
	}
	
}
