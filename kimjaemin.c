#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define COUNT 5 //�� �ο�

struct info {
	int number;
	char name[50];
	int kor;
	int eng;
	int math;
	double avg;
};

void fun1()
{
	printf("1�� �޴�����\n");

}
void fun2()
{
	printf("2�� �޴�����\n");
}
void fun3()
{
	printf("3�� �޴�����\n");
}
void fun4()
{
	printf("4�� �޴�����\n");
}
void fun5()
{
	printf("5�� �޴�����\n");
}
void fun6()
{
	printf("6�� �޴�����\n");
}
void fun7()
{
	printf("7�� �޴�����\n");
}
void fun8()
{
	printf("8�� �޴�����\n");
}
void fun9()
{
	printf("9�� �޴�����\n");

}

//�̸����� ���� �ҷ�����
void print_name(int count, char name[50],struct info *info)
{
	for (int i = 0; i < count; i++)
	{
		if (strcmp(name,info[i].name) == 0) //��ġ�� ��
			printf("�̸�: %s \t �й�: %d \t ����: %d \t ����: %d \t ����: %d \t ���: %lf\n", info[i].name, info[i].number, info[i].kor, info[i].eng, info[i].math, info[i].avg);
	}
}
//�й����� ���� �ҷ�����
void print_num(int count, int num, struct info* info) 
{
	for (int i = 0; i < COUNT; i++)
	{
		if (num == info[i].number)
			printf("�̸�: %s �й�: %d ����: %d ����: %d ����: %d ���: %lf\n", info[i].name, info[i].number, info[i].kor, info[i].eng, info[i].math, info[i].avg);
	}
}
void menu(void)
{
	printf("1. ������ �Է�\n");
	printf("2. �Է��� ��� ���� ���\n");
	printf("3. �̸����� �˻��ϱ�\n");
	printf("4. ��ȣ�� �˻��ϱ�\n");
	printf("5. ��� ������ ���� ������ �̸��� ���\n");
	printf("6. �̸� �Ǵ� ��ȣ�� �����ϱ�\n");
	printf("7. �̸� �Ǵ� ��ȣ�� ���� �����ϱ�\n");
	printf("8. ���Ϸ� �����ϱ�\n");
	printf("9. ���Ͽ��� �о����\n");
	printf("--------------------------\n");
}
int main(void)
{
	char slt;
	struct info info[COUNT];
	int count = 0;
	struct info aver[COUNT];
	struct info temp;

	menu();
	while (1)
	{
		printf("�޴��� �����Ͻÿ�: ");
		scanf_s(" %c", &slt);

		switch (slt)
		{
		case '1':
			fun1();			
			if (count == COUNT) //5������� �Է� ����
				printf("��� �ԷµǾ����ϴ�.");
			else //���� 5�� �̸�
			{
				printf("%d�� �л� �����Է�: \n", count + 1);
				printf("�й�: ");
				scanf_s("%d", &info[count].number);
				printf("�̸�: ");
				scanf_s("%49s", info[count].name,50);
				printf("����: ");
				scanf_s("%d", &info[count].kor);
				printf("����: ");
				scanf_s("%d", &info[count].eng);
				printf("����: ");
				scanf_s("%d", &info[count].math);

				info[count].avg = (double)(info[count].kor + info[count].eng + info[count].math) / (double)3;
				count++;
			}
			break;

		case '2':
			fun2();
			for (int i = 0; i < count; i++)
			{
				printf("-----------------\n");
				printf("%d�� �л�����: \n",i+1);
				printf("�̸�: %s �й�: %d ����: %d ����: %d ����: %d ���: %lf\n", info[i].name,info[i].number, info[i].kor, info[i].eng, info[i].math,info[i].avg);
				printf("-----------------\n");
			}
			break;

		case '3':
			fun3();
			printf("-----------------\n");
			printf("ã�� �л��� �̸��� �Է��Ͻÿ�: ");
			char name[20];
			scanf("%s", name);
			printf("-----------------\n");
			print_name(count,name,info );
			printf("-----------------\n");

			break;

		case '4':
			fun4();
			printf("-----------------\n");
			printf("ã�� �л��� �й��� �Է��Ͻÿ�: ");
			int num;
			scanf_s("%d", &num);
			printf("-----------------\n");
			print_num(count, num, info);
			printf("-----------------\n");
			break;

		case '5': //��� ���� ������ �̸� ���
			fun5();
			break;

		case '6': //�̸� �Ǵ� ��ȣ�� ����
			fun6();
			printf("������ �̸��̳� ��ȣ�Է�: ");
			char name1[20];
			scanf("%s", name1);
			for (int i = 0; i < count; i++)
			{
				if (strcmp(name1, info[i].name) == 0)
				{
					for (int j = i + 1; j < count; j++)
					{
						info[j] = info[j + 1];
					}
				}
			}
			count--;
			printf("�����Ϸ�\n");
			break;

		case '7': //�̸� �Ǵ� ��ȣ�� ����
			fun7();
			char name2[20];
			char subject[20];

			printf("������ ����� �̸��̳� �й��Է�: ");
			scanf("%s", name2);

			for (int i = 0; i < count; i++)
			{
				if (strcmp(name2, info[i].name) == 0)
				{
					printf("������ �����Է�: ");
					scanf("%s", subject);

					if (strcmp(subject, "kor") == 0)
					{
						printf("������ �����Է�: ");
						scanf("%d", &info[i].kor);
					}
					else if (strcmp(subject, "eng") == 0)
					{
						printf("������ �����Է�: ");
						scanf("%d", &info[i].eng);
					}
					else if (strcmp(subject, "math") == 0)
					{
						printf("������ �����Է�: ");
						scanf("%d", &info[i].math);
					}
				}
			}
			break;

		case '8': //���Ϸ� ����
			fun8();
			FILE* file = fopen("�л�����.txt", "wt");
			if (file != NULL)
			{
				for (int i = 0; i < count; i++)
				{
					fprintf(file, "%d\t", info[i].number);
					fprintf(file, "%s\t", info[i].name);
					fprintf(file, "%d\t", info[i].kor);
					fprintf(file, "%d\t", info[i].eng);
					fprintf(file, "%d\t", info[i].math);
					fprintf(file, "%lf\t", info[i].avg);
					fprintf(file, "\n");
				}
				printf("����Ϸ�\n");
				fclose(file);
			}
			break;
		case '9': //���Ͽ��� �о����
			fun9();
			break;
		case 'Q':
		case 'q':
			return 0;
		}
	}
}