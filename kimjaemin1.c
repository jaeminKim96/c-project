#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 3 //���尳���� 3���� ����

//����ü ����
typedef struct _mart {
	char name[20];
	int serial;
	int tell;
	char juso[40];
	int output[6];
	int total, low, high; //����ü �� ��� ����
} MART;

MART m[SIZE]; //�迭���·� ���������� ����

//�޴�
void menu(void)
{
	printf("1. ������ �Է�\n");
	printf("2. �Է��� ��� ���� ���\n");
	printf("3. ���� �̸����� �˻��ϱ�\n");
	printf("4. ������ �ø��� �ѹ��� �˻��ϱ�\n");
	printf("5. �� ������� ���� ���� ���� �̸��� ��ȭ��ȣ, ����� ���\n");
	printf("6. �ø��� ��ȣ�� ���� �����ϱ�\n");
	printf("7. �ø��� ��ȣ�� ���� �����ϱ�\n");
	printf("8. ���Ϸ� �����ϱ�\n");
	printf("9. ���Ͽ��� �о����\n");
	printf("Q�� q���� �� ����\n");
	printf("----------------------------\n");
}

//2�� ��� �Լ�
void total_info(int count, MART *m)
{
	for (int i = 0; i < count; i++)
	{
		printf("--------------------------------------------------------------\n");
		printf("�̸�: %s \t �ø���: %d \t �ּ�: %s \t ��ȭ��ȣ: %d \t\n", m->name, m->serial, m->juso, m->tell);
		printf("1��: %d \t 2��: %d \t 3��: %d \t 4��: %d \t 5��: %d \t 6��: %d\n", m[i].output[0], m[i].output[1], m[i].output[2], m[i].output[3], m[i].output[4], m[i].output[5]);
		printf("�Ѹ����: %d \t �ְ� �����: %d \t ���� �����: %d\n", m[i].total, m[i].high, m[i].low);
		printf("---------------------------------------------------------------\n");
	}
}

//3�� ���
void info_name(int count, MART* m)
{
	char mn[50];
	printf("�˻��� �����̸�: ");
	scanf("%s", mn);

	for (int i = 0; i < count; i++)
	{
		if (strcmp(mn, m[i].name) == 0) //�Է��̸��� �����̸� ��ġ�ϸ�
		{
			printf("--------------------------------------------------------------\n");
			printf("�̸�: %s \t �ø���: %d \t �ּ�: %s \t ��ȭ��ȣ: %d \t\n", m[i].name, m[i].serial, m[i].juso, m[i].tell);
			printf("1��: %d \t 2��: %d \t 3��: %d \t 4��: %d \t 5��: %d \t 6��: %d\n", m[i].output[0], m[i].output[1], m[i].output[2], m[i].output[3], m[i].output[4], m[i].output[5]);
			printf("�Ѹ����: %d \t �ְ� �����: %d \t ���� �����: %d\n", m[i].total, m[i].high, m[i].low);
			printf("--------------------------------------------------------------\n");
		}
	}
}

//4�� ���
void print_number(int count, MART *m)
{
	int number;
	printf("Ȯ���Ϸ��� �ø���ѹ�: ");
	scanf("%d", &number);

	for (int i = 0; i < count; i++)
	{
		if (number == m[i].serial)
		{
			printf("--------------------------------------------------------------\n");
			printf("�̸�: %s \t �ø���: %d \t �ּ�: %s \t ��ȭ��ȣ: %d \t\n", m[i].name, m[i].serial, m[i].juso, m[i].tell);
			printf("1��: %d \t 2��: %d \t 3��: %d \t 4��: %d \t 5��: %d \t 6��: %d\n", m[i].output[0], m[i].output[1], m[i].output[2], m[i].output[3], m[i].output[4], m[i].output[5]);
			printf("�Ѹ����: %d \t �ְ� �����: %d \t ���� �����: %d\n", m[i].total, m[i].high, m[i].low);
			printf("--------------------------------------------------------------\n");
		}
	}
}

//5�� ���
void print_highest(int count,MART *m)
{
	MART temp;
	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (m[i].total < m[j].total)
			{
				temp = m[j];
				m[j] = m[i];
				m[i] = temp;
			}
		}
	}
	printf("----------------------------\n");
	printf("�̸�: %s \t ��ȭ��ȣ: %d \t �����: %d\n", m[0].name, m[0].tell, m[0].total);
	printf("----------------------------\n");
}

//7�� ���
void revise(int count, MART* m)
{
	int number;
	printf("������ ������ �ø��� �ѹ��Է�: ");
	scanf("%d", &number);

	for (int i = 0; i < count; i++)
	{
		if (number == m[i].serial)
		{
			//�ּ� �̸� ����� ��ȭ��ȣ �����ϱ�
			printf("������ �ּ�: ");
			scanf("%s", m[i].juso);
			printf("���� �̸� ����: ");
			scanf("%s", m[i].name);
			printf("��ȭ��ȣ ����: ");
			scanf("%d", &m[i].tell);
			printf("������� ����: ");
			for (int j = 0; j < 6; j++)
				scanf("%d", &m[i].output[j]);

			//����Ǵ� �Ѹ����
			m[i].total = m[i].output[0] + m[i].output[1] + m[i].output[2] + m[i].output[3] + m[i].output[4] + m[i].output[5];

			//����Ǵ� �ְ� ���������
			//�ְ�,��������� Ȯ��
			m[i].high = m[i].output[0]; //���� ����
			m[i].low = m[i].output[1];

			for (int k = 0; k < 6; k++)
			{
				if (m[i].output[k] > m[i].high) m[i].high = m[i].output[k];
				if (m[i].output[k] < m[i].low) m[i].low = m[i].output[k];
			}
		}
	}
}

//6�� ���
void del_info(int count, MART *m)
{
	int number;
	printf("������ ���� �ø��� �ѹ�: ");
	scanf("%d", &number);

	for (int i = 0; i < count; i++)
	{
		if (number == m[i].serial)
		{
			for (int j = i; j < count - 1; j++)
			{
				m[j] = m[j+1];
			}
		}
	}
	/*
	//�ٸ� ���
	for (int i = number-1; i < count - 1; i++)
	{
		memcpy(&m[i], &m[i + 1], sizeof(MART)); //�ι�° ���ڿ��� ù��° ���� �ּҷ� ����° ��� ũ�⸸ŭ ����
	}
	*/
}

int main(void)
{
	menu();
	char choice;
	int count = 0;

	while (1)
	{
		printf("�޴� �����Ͻÿ� ");
		scanf_s(" %c", &choice);

		switch (choice)
		{
		case '1': //�����Է�
			if (count == SIZE)
			{
				printf("����ԷµǾ����ϴ�\n");
				break;
			}
			else
			{
				printf("������ �Է��Ͻÿ�:\n");

				printf("%d�� �����̸�: ",count+1);
				scanf("%s", m[count].name);

				printf("%d�� �ø��� �ѹ�: ",count+1);
				scanf_s("%d", &m[count].serial);

				printf("%d�� �����ּ�: ",count+1);
				scanf("%s", m[count].juso);

				printf("%d�� ��ȭ��ȣ:",count+1);
				scanf_s("%d", &m[count].tell);

				printf("%d���� 6���� �� �����: ",count+1);
				for (int i = 0; i < 6; i++)
					scanf_s("%d", &m[count].output[i]);

				//�Ѹ����
				m[count].total = m[count].output[0] + m[count].output[1] + m[count].output[2] + m[count].output[3] + m[count].output[4] + m[count].output[5];

				//�ְ�,��������� Ȯ��
				m[count].high = m[count].output[0]; //���� ����
				m[count].low = m[count].output[0];

				for (int i = 0; i < 6; i++)
				{
					if (m[count].output[i] > m[count].high) m[count].high = m[count].output[i];
					if (m[count].output[i] < m[count].low) m[count].low = m[count].output[i];
				}
				count++; //�����Է�Ƚ�� ����
			}
			break;
		case '2': //�Էµ� ���� ���
			total_info(count, m);
			break;
		case '3': //�����̸����� �˻�
			info_name(count, m);
			break;
		case '4': //�ø��� �ѹ��� �˻�
			print_number(count, m);
			break;
		case '5': //�Ѹ��� ���� ���� ����(�̸�,��ȭ��ȣ,�����)
			print_highest(count, m);
			break;
		case '6': //�ø���� ��������
			del_info(count, m);
			count--; //�������������� ����
			break;
		case '7': //��������
			revise(count, m);
			break;
		case '8': //���Ϸ� ����
			FILE* file = fopen("��������.txt", "wt"); //FILE* file�� ���� ����ü�� �̿��Ͽ� ��Ʈ���� ������ ������ ������ ���� 
			//fopen�� ��Ʈ���� ���� ()�ȿ��� �ʿ�����
			if (file != NULL) //��Ʈ���� ���������� ������ ���!
			{
				for (int i = 0; i < count; i++)
				{
					fprintf(file, "�̸�: %s\t", m[i].name);
					fprintf(file, "�ø���: %d\t", m[i].serial);
					fprintf(file, "�ּ�: %s\t", m[i].juso);
					fprintf(file, "��ȭ��ȣ: %d\t", m[i].tell);
					fprintf(file, "1������: %d\t", m[i].output[0]);
					fprintf(file, "2������: %d\t", m[i].output[1]);
					fprintf(file, "3������: %d\t", m[i].output[2]);
					fprintf(file, "4������: %d\t", m[i].output[3]);
					fprintf(file, "5������: %d\t", m[i].output[4]);
					fprintf(file, "6������: %d\t", m[i].output[5]);
					fprintf(file, "�Ѹ���: %d\t", m[i].total);
					fprintf(file, "�ְ����: %d\t", m[i].high);
					fprintf(file, "��������: %d\t", m[i].low);
					fprintf(file, "\n");
				}
				printf("����Ϸ�\n");
				fclose(file); //��Ʈ�� �Ҹ� //���������� ���� ������ 0��ȯ �ƴϸ� EOF
			}
			break;
		case '9': //���Ͽ��� �о����
			FILE* file1 = fopen("��������.txt", "rt");
			int count1 = 0;
			if (file1 != NULL)
			{
				fscanf(file1, "%d\n", &count1); 
				for (int i = 0; i < count1; i++)
				{
					fscanf(file1, "%s\t", m[i].name);

					char temp[50];

					fscanf(file1, "%s\t", temp);
					m[i].serial = atoi(temp);
					fscanf(file1, "%s\t", m[i].juso);
					fscanf(file1, "%s\t", temp);
					m[i].tell = atoi(temp);
					fscanf(file1, "%s\t", temp);
					m[i].output[0] = atoi(temp);
					fscanf(file1, "%s\t", temp);
					m[i].output[1] = atoi(temp);
					fscanf(file1, "%s\t", temp);
					m[i].output[2] = atoi(temp);
					fscanf(file1, "%s\t", temp);
					m[i].output[3] = atoi(temp);
					fscanf(file1, "%s\t", temp);
					m[i].output[4] = atoi(temp);
					fscanf(file1, "%s\t", temp);
					m[i].output[5] = atoi(temp);
				}
				printf("�ҷ����� ����\n");
				fclose(file1);
			}
			break;
		case 'Q':
		case 'q':
			return 0;
		}
	}
}