#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define COUNT 5 //총 인원

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
	printf("1번 메뉴선택\n");

}
void fun2()
{
	printf("2번 메뉴선택\n");
}
void fun3()
{
	printf("3번 메뉴선택\n");
}
void fun4()
{
	printf("4번 메뉴선택\n");
}
void fun5()
{
	printf("5번 메뉴선택\n");
}
void fun6()
{
	printf("6번 메뉴선택\n");
}
void fun7()
{
	printf("7번 메뉴선택\n");
}
void fun8()
{
	printf("8번 메뉴선택\n");
}
void fun9()
{
	printf("9번 메뉴선택\n");

}

//이름으로 정보 불러오기
void print_name(int count, char name[50],struct info *info)
{
	for (int i = 0; i < count; i++)
	{
		if (strcmp(name,info[i].name) == 0) //일치할 때
			printf("이름: %s \t 학번: %d \t 국어: %d \t 영어: %d \t 수학: %d \t 평균: %lf\n", info[i].name, info[i].number, info[i].kor, info[i].eng, info[i].math, info[i].avg);
	}
}
//학번으로 정보 불러오기
void print_num(int count, int num, struct info* info) 
{
	for (int i = 0; i < COUNT; i++)
	{
		if (num == info[i].number)
			printf("이름: %s 학번: %d 국어: %d 영어: %d 수학: %d 평균: %lf\n", info[i].name, info[i].number, info[i].kor, info[i].eng, info[i].math, info[i].avg);
	}
}
void menu(void)
{
	printf("1. 데이터 입력\n");
	printf("2. 입력한 모든 정보 출력\n");
	printf("3. 이름으로 검색하기\n");
	printf("4. 번호로 검색하기\n");
	printf("5. 평균 점수가 높은 순으로 이름을 출력\n");
	printf("6. 이름 또는 번호로 삭제하기\n");
	printf("7. 이름 또는 번호로 정보 변경하기\n");
	printf("8. 파일로 저장하기\n");
	printf("9. 파일에서 읽어오기\n");
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
		printf("메뉴를 선택하시오: ");
		scanf_s(" %c", &slt);

		switch (slt)
		{
		case '1':
			fun1();			
			if (count == COUNT) //5명까지만 입력 가능
				printf("모두 입력되었습니다.");
			else //정보 5개 미만
			{
				printf("%d번 학생 정보입력: \n", count + 1);
				printf("학번: ");
				scanf_s("%d", &info[count].number);
				printf("이름: ");
				scanf_s("%49s", info[count].name,50);
				printf("국어: ");
				scanf_s("%d", &info[count].kor);
				printf("영어: ");
				scanf_s("%d", &info[count].eng);
				printf("수학: ");
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
				printf("%d번 학생정보: \n",i+1);
				printf("이름: %s 학번: %d 국어: %d 영어: %d 수학: %d 평균: %lf\n", info[i].name,info[i].number, info[i].kor, info[i].eng, info[i].math,info[i].avg);
				printf("-----------------\n");
			}
			break;

		case '3':
			fun3();
			printf("-----------------\n");
			printf("찾을 학생의 이름을 입력하시오: ");
			char name[20];
			scanf("%s", name);
			printf("-----------------\n");
			print_name(count,name,info );
			printf("-----------------\n");

			break;

		case '4':
			fun4();
			printf("-----------------\n");
			printf("찾을 학생의 학번을 입력하시오: ");
			int num;
			scanf_s("%d", &num);
			printf("-----------------\n");
			print_num(count, num, info);
			printf("-----------------\n");
			break;

		case '5': //평균 높은 순으로 이름 출력
			fun5();
			break;

		case '6': //이름 또는 번호로 삭제
			fun6();
			printf("삭제할 이름이나 번호입력: ");
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
			printf("삭제완료\n");
			break;

		case '7': //이름 또는 번호로 변경
			fun7();
			char name2[20];
			char subject[20];

			printf("변경할 사람의 이름이나 학번입력: ");
			scanf("%s", name2);

			for (int i = 0; i < count; i++)
			{
				if (strcmp(name2, info[i].name) == 0)
				{
					printf("변경할 과목입력: ");
					scanf("%s", subject);

					if (strcmp(subject, "kor") == 0)
					{
						printf("변경할 점수입력: ");
						scanf("%d", &info[i].kor);
					}
					else if (strcmp(subject, "eng") == 0)
					{
						printf("변경할 점수입력: ");
						scanf("%d", &info[i].eng);
					}
					else if (strcmp(subject, "math") == 0)
					{
						printf("변경할 점수입력: ");
						scanf("%d", &info[i].math);
					}
				}
			}
			break;

		case '8': //파일로 저장
			fun8();
			FILE* file = fopen("학생성적.txt", "wt");
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
				printf("저장완료\n");
				fclose(file);
			}
			break;
		case '9': //파일에서 읽어오기
			fun9();
			break;
		case 'Q':
		case 'q':
			return 0;
		}
	}
}