#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include<conio.h>



#pragma warning(disable:4996)


char str1[5000];
char str2[5000];
char str3[5000];
char str4[5000];
char str5[5000];
char str6[5000];




struct shangpin
{
	char name[30];
	char num[30];
	char sex[10];
	char cont[30];
};



char mima[] = "123456";//�������� 

					   /* run this program using the console pauser or add your own getch, system("pause") or input loop */


struct shangpin p[200];

void add();
void chaxun();
void shanchu();
void fix();
void save();
void shouye();




void add()
{
	int n = 0, i = 0;
	for (i = 0; i<200; i++)//ѭ��200��
	{
		char s;
		printf("����:\n");
		scanf("%s", p[i].name);
		getchar();


		printf("ѧ��:\n");
		scanf("%s", &p[i].num);
		getchar();


		printf("�Ա�:\n");
		scanf("%s", p[i].sex);
		getchar();


		printf("�ܷ�:\n");
		scanf("%s", &p[i].cont);
		getchar();


		n++;
		printf("�Ƿ��������yΪ������nΪ�˳���\n");
		s = getch();
		system("CLS");
		if (s != 'n'&&s != 'N')
		{
			break;//����ѭ��
		}
		else
		{
			continue;
		}
		shouye();

	}


	FILE *fp;
	fp = fopen("data.txt", "a");

	if ((fp = fopen("data.txt", "a")) == NULL) {                  //���ж��Ƿ��ܴ��ļ� 
		printf("�Ҳ����ļ�\n");
		system("pause");
	}

	for (i = 0; i<n; i++) {
		fprintf(fp, "%s %s %s %s", p[i].name, p[i].num, p[i].sex, p[i].cont);    //�����������ļ� 
	}
	fclose(fp);
	shouye();
}






void chaxun()
{
	int i = 0, n = 0;
	char mingcheng[30];
	printf("������Ҫ��ѯ������:\n");
	scanf("%s", mingcheng);


	FILE *fp;
	if ((fp = fopen("data.txt", "r")) == NULL) {                  //���ж��Ƿ��ܴ��ļ� 

		printf("�Ҳ����ļ�\n");
		system("pause");
	}
	fp = fopen("data.txt", "r");
	while (fscanf(fp, "%s %s %s %s", p[i].name, p[i].num, p[i].sex, p[i].cont) != EOF)
	{
		i++;
	}

	fclose(fp);

	for (n = 0; n <= i; n++)
	{
		if (strcmp(p[n].name, mingcheng) == 0)
		{
			printf("%s %s %s %s", p[n].name, p[n].num, p[n].sex, p[n].cont);
		}
	}




	//�Ƿ�������� 
	printf("�Ƿ������ѯyΪ������nΪ�˳���\n");

	char s;
	s = getch();
	system("CLS");
	if (s != 'n'&&s != 'N')
	{
		chaxun();
	}
	else
	{
		shouye();
	}



}







void shanchu()
{
	int i = 0, n = 0;
	char mingcheng[30];
	printf("������Ҫ��ѯ��ѧ��������:\n");
	scanf("%s", mingcheng);

	FILE *fp, *fp2;
	if ((fp = fopen("data.txt", "r")) == NULL) {                  //���ж��Ƿ��ܴ��ļ� 
		printf("�Ҳ����ļ�\n");
		system("pause");
	}

	fp = fopen("data.txt", "r");
	while (fscanf(fp, "%s %s %s %s", p[n].name, p[n].num, p[n].sex, p[n].cont) != EOF)
	{

		i++;

	}

	fclose(fp);

	//Ѱ��Ҫɾ��������

	for (n = 0; n <= i; n++)
	{
		if (strcmp(p[n].name, mingcheng) == 0)
		{
			sprintf(p[n].name, "-2634");//��ʼ��
		}

	}

	//ɾ������Ʒ���־�Ϊ���ˣ�����Ҫ�ѿ����ֵ���Ʒ�������� 
	fp2 = fopen("data.txt", "w");
	for (n = 0; n<i; n++)
	{
		char y[30] = "-2634";
		if (strcmp(y, p[n].name) != 0)//�ж���ֵ
		{

			fprintf(fp2, "%s %s %s %s", p[n].name, p[n].num, p[n].sex, p[n].cont);//����ı�
		}

	}
	fclose(fp2);

	printf("�Ƿ����ɾ��yΪ������nΪ�˳���\n");
	char s;
	s = getch();
	system("CLS");
	if (s != 'n'&&s != 'N')//�������
	{
		shanchu();
	}
	else
	{
		shouye();
	}

}







void fix()
{
	int i = 0, n = 0;
	int q = -1;
	char mingcheng[30];
	printf("������Ҫ�޸ĵ�����:\n");
	scanf("%s", mingcheng);


	FILE *fp;
	if ((fp = fopen("data.txt", "r")) == NULL) {                  //���ж��Ƿ��ܴ��ļ� 
		printf("�Ҳ����ļ�\n");
		system("pause");
	}


	fp = fopen("data.txt", "r");


	while (fscanf(fp, "%s %s %s %s", p[i].name, p[i].num, p[i].sex, p[i].cont) != EOF)
	{
		i++;
	}



	for (n = 0; n <= i; n++)
	{
		if (strcmp(p[n].name, mingcheng) == 0)
		{
			q = i;
			printf("�ҵ��Ľ��Ϊ��%s %s %s %s", p[n].name, p[n].num, p[n].sex, p[n].cont);
			break;
		}
	}

	if (q == -1)
	{
		printf("δ�ҵ��������²���");
		system("CLS");
		fix();
	}

	Sleep(500);
	printf("�������޸ĺ�����:\n");
	scanf("%s", p[q].name);
	getchar();
	printf("�������޸ĺ�ѧ��:\n");
	scanf("%s", &p[q].num);
	getchar();
	printf("�������޸ĺ��Ա�:\n");
	scanf("%s", p[q].sex);
	getchar();
	printf("�������޸ĺ��ܷ�:\n");
	scanf("%s", p[q].cont);
	getchar();
	for (n = 0; n <= i; n++)
	{
		fprintf(fp, "%s %s %s %s", p[n].name, p[n].num, p[n].sex, p[n].cont);
	}

	fclose(fp);

	//�Ƿ�������� 
	printf("�Ƿ������ѯyΪ������nΪ�˳���\n");
	char s;
	s = getch();
	system("CLS");
	if (s != 'n'&&s != 'N')
	{
		fix();
	}
	else
	{
		shouye();
	}



}






void save()
{
	int i = 0, n = 0;
	FILE *fp;
	fp = fopen("C://data.txt", "r");
	while (fscanf(fp, "%s %s %s %s", p[i].name, p[i].num, p[i].sex, p[i].cont) != EOF)
	{
		i++;
	}
	FILE *fp2;
	fp2 = fopen("C://data.txt", "w");
	for (n = 0; n <= i; n++)
	{
		fprintf(fp2, "%s %s %s %s", p[n].name, p[n].num, p[n].sex, p[n].cont);
	}




	//���ݿ����ת��
	FILE *fp3, *fp4;
	i = 0;
	fp = fopen("C://data.txt", "r");
	while (fscanf(fp, "%s %s %s %s", p[i].name, p[i].num, p[i].sex, p[i].cont) != EOF)
	{
		i++;
	}

	fp2 = fopen("C://data.txt", "w");
	for (n = 0; n <= i; n++)
	{
		fprintf(fp2, "%s %s %s %s %s %s %s %s", p[n].name, str2, p[n].num, str2, p[n].sex, str2, p[n].cont, str3);
	}

	fclose(fp);
	fclose(fp2);

	fp3 = fopen("C://data.txt", "r");
	//fscanf(fp3,"%s",str5);
	int j = 0;
	while (fscanf(fp3, "%s", str5) && j<100)
	{
		strcat(str6, str5);
		j++;
	}


	fp4 = fopen("C://data.sql", "w");
	fprintf(fp4, "%s %s %s", str1, str6, str4);



	fclose(fp3);
	fclose(fp4);

	printf("\n�����ѱ�����C��data.sql�ļ���\n\n");
	system("pause");

}






void shouye()
{
	printf("\t��������������������\n");
	printf("\t��1---�����Ϣ--- ��\n");
	printf("\t��2---��ѯ��Ϣ--- ��\n");
	printf("\t��3---ɾ����Ϣ--- ��\n");
	printf("\t��4---�޸���Ϣ--- ��\n");
	printf("\t��0---�����˳�--- ��\n");
	printf("\t��������������������\n");
	char a;
	a = getch();
	system("CLS");
	switch (a)
	{
	case '1':add(); break;
	case '2':chaxun(); break;
	case '3':shanchu(); break;
	case '4':fix(); break;
	case '0':save(); break;
	}


}






void login()
{
	char password[20];
	printf("�������½���룺\n");
	scanf("%s", password);
	getchar();

	if (strcmp(password, mima) == 0)
	{
		printf("������ȷ\n");
		Sleep(500);

		int i = 0;
		for (i = 0; i < 20; i++)
		{
			printf("-");
			Sleep(30);
		}

		printf("\r");

		for (i = 0; i < 20; i++)
		{
			printf(">");
			Sleep(30);
		}
		system("CLS");
		shouye();

	}
	else
	{
		printf("\n");
		printf("�����������������\n");
		login();
	}

}





//��ʼ�����ݿ���������
void first()
{
	FILE *fp;
	fp = fopen("C://data1.txt", "r");
	fscanf(fp, "%s", str1);


	fp = fopen("C://data2.txt", "r");
	fscanf(fp, "%s", str2);


	fp = fopen("C://data3.txt", "r");
	fscanf(fp, "%s", str3);


	fp = fopen("C://data4.txt", "r");
	fscanf(fp, "%s", str4);



	fclose(fp);

}



int main(int argc, char *argv[]) {
	first();
	login();
	rename("C://data.txt", "C://data.sql");
	return 0;
}


















