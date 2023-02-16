#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 3 //매장개수는 3개로 설정

//구조체 선언
typedef struct _mart {
	char name[20];
	int serial;
	int tell;
	char juso[40];
	int output[6];
	int total, low, high; //구조체 및 멤버 선언
} MART;

MART m[SIZE]; //배열형태로 전역변수로 선언

//메뉴
void menu(void)
{
	printf("1. 데이터 입력\n");
	printf("2. 입력한 모든 정보 출력\n");
	printf("3. 매장 이름으로 검색하기\n");
	printf("4. 매장의 시리얼 넘버로 검색하기\n");
	printf("5. 총 매출액이 가장 높은 매장 이름과 전화번호, 매출액 출력\n");
	printf("6. 시리얼 번호로 정보 삭제하기\n");
	printf("7. 시리얼 번호로 정보 변경하기\n");
	printf("8. 파일로 저장하기\n");
	printf("9. 파일에서 읽어오기\n");
	printf("Q나 q누를 시 종료\n");
	printf("----------------------------\n");
}

//2번 기능 함수
void total_info(int count, MART *m)
{
	for (int i = 0; i < count; i++)
	{
		printf("--------------------------------------------------------------\n");
		printf("이름: %s \t 시리얼: %d \t 주소: %s \t 전화번호: %d \t\n", m->name, m->serial, m->juso, m->tell);
		printf("1월: %d \t 2월: %d \t 3월: %d \t 4월: %d \t 5월: %d \t 6월: %d\n", m[i].output[0], m[i].output[1], m[i].output[2], m[i].output[3], m[i].output[4], m[i].output[5]);
		printf("총매출액: %d \t 최고 매출액: %d \t 최저 매출액: %d\n", m[i].total, m[i].high, m[i].low);
		printf("---------------------------------------------------------------\n");
	}
}

//3번 기능
void info_name(int count, MART* m)
{
	char mn[50];
	printf("검색할 매장이름: ");
	scanf("%s", mn);

	for (int i = 0; i < count; i++)
	{
		if (strcmp(mn, m[i].name) == 0) //입력이름과 매장이름 일치하면
		{
			printf("--------------------------------------------------------------\n");
			printf("이름: %s \t 시리얼: %d \t 주소: %s \t 전화번호: %d \t\n", m[i].name, m[i].serial, m[i].juso, m[i].tell);
			printf("1월: %d \t 2월: %d \t 3월: %d \t 4월: %d \t 5월: %d \t 6월: %d\n", m[i].output[0], m[i].output[1], m[i].output[2], m[i].output[3], m[i].output[4], m[i].output[5]);
			printf("총매출액: %d \t 최고 매출액: %d \t 최저 매출액: %d\n", m[i].total, m[i].high, m[i].low);
			printf("--------------------------------------------------------------\n");
		}
	}
}

//4번 기능
void print_number(int count, MART *m)
{
	int number;
	printf("확인하려는 시리얼넘버: ");
	scanf("%d", &number);

	for (int i = 0; i < count; i++)
	{
		if (number == m[i].serial)
		{
			printf("--------------------------------------------------------------\n");
			printf("이름: %s \t 시리얼: %d \t 주소: %s \t 전화번호: %d \t\n", m[i].name, m[i].serial, m[i].juso, m[i].tell);
			printf("1월: %d \t 2월: %d \t 3월: %d \t 4월: %d \t 5월: %d \t 6월: %d\n", m[i].output[0], m[i].output[1], m[i].output[2], m[i].output[3], m[i].output[4], m[i].output[5]);
			printf("총매출액: %d \t 최고 매출액: %d \t 최저 매출액: %d\n", m[i].total, m[i].high, m[i].low);
			printf("--------------------------------------------------------------\n");
		}
	}
}

//5번 기능
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
	printf("이름: %s \t 전화번호: %d \t 매출액: %d\n", m[0].name, m[0].tell, m[0].total);
	printf("----------------------------\n");
}

//7번 기능
void revise(int count, MART* m)
{
	int number;
	printf("수정할 매장의 시리얼 넘버입력: ");
	scanf("%d", &number);

	for (int i = 0; i < count; i++)
	{
		if (number == m[i].serial)
		{
			//주소 이름 매출액 전화번호 변경하기
			printf("변경할 주소: ");
			scanf("%s", m[i].juso);
			printf("매장 이름 변경: ");
			scanf("%s", m[i].name);
			printf("전화번호 변경: ");
			scanf("%d", &m[i].tell);
			printf("월매출액 변경: ");
			for (int j = 0; j < 6; j++)
				scanf("%d", &m[i].output[j]);

			//변경되는 총매출액
			m[i].total = m[i].output[0] + m[i].output[1] + m[i].output[2] + m[i].output[3] + m[i].output[4] + m[i].output[5];

			//변경되는 최고 최저매출액
			//최고,최저매출액 확인
			m[i].high = m[i].output[0]; //임의 지정
			m[i].low = m[i].output[1];

			for (int k = 0; k < 6; k++)
			{
				if (m[i].output[k] > m[i].high) m[i].high = m[i].output[k];
				if (m[i].output[k] < m[i].low) m[i].low = m[i].output[k];
			}
		}
	}
}

//6번 기능
void del_info(int count, MART *m)
{
	int number;
	printf("삭제할 매장 시리얼 넘버: ");
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
	//다른 방법
	for (int i = number-1; i < count - 1; i++)
	{
		memcpy(&m[i], &m[i + 1], sizeof(MART)); //두번째 인자에서 첫번째 인자 주소로 세번째 요소 크기만큼 복사
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
		printf("메뉴 선택하시오 ");
		scanf_s(" %c", &choice);

		switch (choice)
		{
		case '1': //정보입력
			if (count == SIZE)
			{
				printf("모두입력되었습니다\n");
				break;
			}
			else
			{
				printf("정보를 입력하시오:\n");

				printf("%d번 매장이름: ",count+1);
				scanf("%s", m[count].name);

				printf("%d번 시리얼 넘버: ",count+1);
				scanf_s("%d", &m[count].serial);

				printf("%d번 매장주소: ",count+1);
				scanf("%s", m[count].juso);

				printf("%d번 전화번호:",count+1);
				scanf_s("%d", &m[count].tell);

				printf("%d번의 6개월 간 매출액: ",count+1);
				for (int i = 0; i < 6; i++)
					scanf_s("%d", &m[count].output[i]);

				//총매출액
				m[count].total = m[count].output[0] + m[count].output[1] + m[count].output[2] + m[count].output[3] + m[count].output[4] + m[count].output[5];

				//최고,최저매출액 확인
				m[count].high = m[count].output[0]; //임의 지정
				m[count].low = m[count].output[0];

				for (int i = 0; i < 6; i++)
				{
					if (m[count].output[i] > m[count].high) m[count].high = m[count].output[i];
					if (m[count].output[i] < m[count].low) m[count].low = m[count].output[i];
				}
				count++; //정보입력횟수 증가
			}
			break;
		case '2': //입력된 정보 출력
			total_info(count, m);
			break;
		case '3': //매장이름으로 검색
			info_name(count, m);
			break;
		case '4': //시리얼 넘버로 검색
			print_number(count, m);
			break;
		case '5': //총매출 높은 매장 정보(이름,전화번호,매출액)
			print_highest(count, m);
			break;
		case '6': //시리얼로 정보삭제
			del_info(count, m);
			count--; //정보삭제했으니 감소
			break;
		case '7': //정보변경
			revise(count, m);
			break;
		case '8': //파일로 저장
			FILE* file = fopen("매장정보.txt", "wt"); //FILE* file은 파일 구조체를 이용하여 스트림을 생성할 포인터 변수의 선언 
			//fopen이 스트림의 역할 ()안에는 필요인자
			if (file != NULL) //스트림이 정상적으로 생성된 경우!
			{
				for (int i = 0; i < count; i++)
				{
					fprintf(file, "이름: %s\t", m[i].name);
					fprintf(file, "시리얼: %d\t", m[i].serial);
					fprintf(file, "주소: %s\t", m[i].juso);
					fprintf(file, "전화번호: %d\t", m[i].tell);
					fprintf(file, "1월매출: %d\t", m[i].output[0]);
					fprintf(file, "2월매출: %d\t", m[i].output[1]);
					fprintf(file, "3월매출: %d\t", m[i].output[2]);
					fprintf(file, "4월매출: %d\t", m[i].output[3]);
					fprintf(file, "5월매출: %d\t", m[i].output[4]);
					fprintf(file, "6월매출: %d\t", m[i].output[5]);
					fprintf(file, "총매출: %d\t", m[i].total);
					fprintf(file, "최고매출: %d\t", m[i].high);
					fprintf(file, "최저매출: %d\t", m[i].low);
					fprintf(file, "\n");
				}
				printf("저장완료\n");
				fclose(file); //스트림 소멸 //성공적으로 파일 닫으면 0반환 아니면 EOF
			}
			break;
		case '9': //파일에서 읽어오기
			FILE* file1 = fopen("저장정보.txt", "rt");
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
				printf("불러오기 성공\n");
				fclose(file1);
			}
			break;
		case 'Q':
		case 'q':
			return 0;
		}
	}
}