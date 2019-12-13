#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>

int size = 5; // NxN 게임판을 위한 사이즈
char gameBoard[5][5][3]; // 게임판
int score = 0; // 점수
int level; // 난이도 (쉬움,보통,어려움)

typedef struct node {
	char name[20];
	int playerScore;
	struct node* next;
}RANKING;

typedef struct enemy { //적 객체의 위치정보를 행과 열로 나타냄
	int row;
	int col;
}ENEMY;
ENEMY enemys[30]; //

typedef struct { //플레이어 객체의 위치정보를 행과 열로 나타냄
	int row;
	int col;
}PLAYER;
PLAYER player;

int enemyCount = 0; // 적의 수

RANKING* new_node;
RANKING* list_head = NULL;
RANKING* tmp_node;
RANKING* next_p;
RANKING* prev_p;

void GameStart(int level, int (*func)(int)); //게임 실행 함수
void mainMenu(); // 메인 메뉴로 가는 함수
void ChooseGameLevel(); // 게임 난이도를 고르는 함수
void HowToPlayGame(); // 게임 방법을 설명하는 함수

int EnemyCount(int level); // 난이도에 따라 적의 수 결정하는 함수 
void PrintGameBoard(); // 몬스터와 플레이어를 게임판을 출력하는 함수
void InitializationBoard(); // 게임판을 출력하기 전에 게임판을 초기화하는 함수

void EnemyMove(); // 적의 움직임을 구현한 함수
void PlayerMove(); // 플레이어의 움직임을 구현한 함수

void ShowRanking(RANKING* head); // 랭킹표를 보여주는 함수
void RegisterOnRanking(int _score); // 게임이 끝나면 점수를 랭킹표에 등록하는 함수

void SaveRanking(RANKING* head); // 랭킹을 외부 파일에 저장하는 함수
void LoadRanking(); // 외부 파일에 있는 랭킹을 불러오는 함수

void mainMenu() // 맨 처음 게임시작시 나오는 메뉴
{
	score = 0; // 점수 초기화
	int menu;
	printf("\n좀비 피하기 게임\n\n");
	printf("1. 게임시작\n");
	printf("2. 게임방법\n");
	printf("3. 랭킹보기\n");
	printf("4. 게임종료\n");
	scanf("%d", &menu);
	printf("\n");
	switch (menu)
	{
	case 1:
		ChooseGameLevel();
		return;
	case 2:
		HowToPlayGame();
		return;
	case 3:
		ShowRanking(list_head);
		return;
	case 4:
		while (list_head) { // 게임종료시 할당한 메모리 반환
			tmp_node = list_head;
			list_head = list_head->next;
			free(tmp_node);
		}
		return;
	}
	printf("잘못된 값을 입력하셨습니다. 다시 입력해 주세요.\n\n");
	mainMenu();
}

void HowToPlayGame() // 게임방법 설명
{
	printf("네모는 게임판, 동그라미는 플레이어, 세모는 적입니다.\n\n");
	printf("플레이어는 적을 피해서 도망다녀야 합니다.\n\n");
	printf("적은 상하좌우로 움직일 수 있고, 움직이지 않을수도 있습니다. 플레이어는 상하좌우로만 움직일 수 있습니다.\n\n");
	printf("플레이어가 먼저 움직이고, 적이 움직입니다. 각자 한번씩 움직이면 한턴이 끝나면서 플레이어는 점수를 얻습니다.\n\n");
	printf("난이도에 따라 턴마다 얻는 점수가 다릅니다.\n\n");
	printf("맨 왼쪽 위의 적의 적진을 가면 보너스 점수 5점을 얻습니다.\n\n");
	printf("적을 피해서 살아남으세요!\n\n");

	mainMenu();
}

void ChooseGameLevel() // 메인메뉴에서 게임 시작을 누르면 나오는 난이도 선택란
{
	printf("난이도를 고르시오.\n");
	printf("1. 쉬움\n");
	printf("2. 보통\n");
	printf("3. 어려움\n");
	printf("0. 뒤로가기\n");
	scanf("%d", &level);
	printf("\n");

	if (level == 0)
		mainMenu();
	else if (0 < level && level < 4)
		GameStart(level, EnemyCount);
	else {
		printf("잘못 입력하셨습니다. 다시 입력해주세요.\n");
		ChooseGameLevel();
	}
}

int EnemyCount(int level) // 적의 수 결정하는 함수
{
	switch (level)
	{
	case 1:
		return 8;
	case 2:
		return 12;
	case 3:
		return 16;
	}
	return 0;
}
//위의 EnemyCount 함수를 인자로 받아서 적의 수 결정
void GameStart(int level, int (*func)(int)) // 게임 시작
{
	enemyCount = func(level);
	for (int i = 0; i < enemyCount; i++) // 적의 수만큼 적 위치를 0,0으로 초기화
	{
		enemys[i].row = 0;
		enemys[i].col = 0;
	}

	player.col = 4;
	player.row = 4;// 플레이어의 위치는 4,4로 초기화

	int outWhile = 0;//중첩 루프 탈출을 위한 변수
	while (1) {
		PrintGameBoard(); // 일단 현재 게임판 출력
		PlayerMove(); // 캐릭터 움직임
		PrintGameBoard();

		for (int i = 0; i < enemyCount; i++) // 적에게 잡혔으면 반복문 탈출
		{
			if (enemys[i].col == player.col && enemys[i].row == player.row) {
				outWhile = 1;
				break;
			}
		}
		if (outWhile)
			break;
		if (player.row == 0 && player.col == 0) {
			printf("적의 본진을 점령했습니다!! +5점\n");
			score += 5;
		}
		printf("적들이 움직일 차례입니다.\n");
		Sleep(1000); // 1초 시간지연 
		EnemyMove(); // 적 움직임

		for (int i = 0; i < enemyCount; i++) // 적에게 잡혔으면 반복문 탈출
		{
			if (enemys[i].col == player.col && enemys[i].row == player.row) {
				outWhile = 1;
				break;
			}
		}
		if (outWhile)
			break;
		score += level;
	}
	PrintGameBoard();
	printf("적에게 잡혔습니다!!\n");
	printf("당신의 점수는 %d점 입니다.\n\n", score);
	printf("당신의 점수를 랭킹표에 등록하시겠습니까? (0.아니오 1.네)\n");
	int isRegister;
	scanf("%d", &isRegister);
	if (isRegister) {
		RegisterOnRanking(score);
	}
	mainMenu();
}

void PrintGameBoard()
{
	InitializationBoard();

	strcpy(gameBoard[player.row][player.col], "●"); // 플레이어 위치 o으로 색칠

	for (int i = 0; i < enemyCount; i++)
	{
		strcpy(gameBoard[enemys[i].row][enemys[i].col], "▲"); // 적들 위치 ㅁ으로 색칠
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%s", gameBoard[i][j]);
		}
		if (i == 2)
			printf("   점수 : %d", score); // 게임판 첫째줄 옆에 점수 출력
		printf("\n");
	}
}
void InitializationBoard() // 게임판 ㅁ로 초기화
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			strcpy(gameBoard[i][j], "□");
		}
	}
}

void EnemyMove()
{
	int direction;
	srand((int)time(NULL));

	for (int i = 0; i < enemyCount; i++)
	{
		ENEMY enemyPosition = { enemys[i].row,enemys[i].col }; // 몬스터가 벽을 넘어가면 다시 원위치 시키기 위한 변수저장

		direction = rand() % 5; // 적이 움직일 방향 설정; 0은 위 1은 오른쪽 2는 아래 3은 왼쪽
		switch (direction)
		{
		case 0:
			enemys[i].row -= 1; // 위로 한칸 이동
			break;
		case 1:
			enemys[i].col += 1; // 오른쪽
			break;
		case 2:
			enemys[i].row += 1; // 아래
			break;
		case 3:
			enemys[i].col -= 1; // 왼쪽
		case 4:
			break;
		}
		if (enemys[i].row < 0 || enemys[i].col < 0 || enemys[i].row > 4 || enemys[i].col > 4) {
			enemys[i].row = enemyPosition.row; //5x5 게임판 범위를 넘으면 원위치
			enemys[i].col = enemyPosition.col;
			i--; // 위치 재설정
		}
		Sleep(direction);
	}
}

void PlayerMove()
{
	char direction[10];
	PLAYER playerPosition = { player.row,player.col }; // 플레이어의 현재 위치 저장했다가 플레이어가 벽 뚫으면 원위치로

	printf("움직일 방향을 입력하세요. (w:위; s:아래; a:왼쪽 d:오른쪽)\n");
	scanf("%s", direction);
	switch (direction[0])
	{
	case 'w':
		player.row -= 1; // 위로 한칸 이동
		break;
	case 's':
		player.row += 1; // 아래
		break;
	case 'a':
		player.col -= 1; // 왼쪽
		break;
	case 'd':
		player.col += 1; // 오른쪽
		break;
	}
	if (direction[0] != 'w' && direction[0] != 's' && direction[0] != 'a' && direction[0] != 'd') {
		// 문자를 이상한거 입력했을 시
		printf("잘못 입력하셨습니다. 다시 입력해주세요. 혹시 대문자로 입력하셨다면 소문자로 입력하세요\n");
		PlayerMove(); // 다시 호출
	}
	if (player.row < 0 || player.col < 0 || player.row > 4 || player.col > 4) {
		// 5x5 게임판 범위를 넘으면 위치 재설정
		printf("벽을 뚫을 순 없습니다. 다시 입력해주세요.\n");
		player.row = playerPosition.row; // 플레이어 위치 원위치
		player.col = playerPosition.col;
		PlayerMove(); // 다시 호출
	}
}

void ShowRanking(RANKING* head) // 랭킹을 보여주는 함수
{
	if (head == NULL) // 랭킹이 없을시
	{
		printf("랭킹이 없습니다.\n\n");
		mainMenu();
		return;
	}

	int rank = 1;

	printf("================랭킹표===============\n\n");
	while (rank < 11) // 10번째 연결리스트 까지 보여줌
	{
		printf("%d등 : %s님 %d점\n\n", rank, head->name, head->playerScore);
		if (head->next == NULL) // 다음값이 null이면 반복문 탈출
			break;
		head = head->next;
		rank++;
	}
	printf("=====================================\n\n");
	printf("0. 메인 메뉴로 가기\n");
	printf("1. 랭킹 저장하기");
	int Choice;
	scanf("%d", &Choice);
	if (!Choice)
		mainMenu();
	else
		SaveRanking(list_head);
}

void RegisterOnRanking(int _score)
{
	char _name[20];

	printf("이름을 입력하세요:\n");
	scanf("%s", _name);

	new_node = (RANKING*)malloc(sizeof(RANKING));
	strcpy(new_node->name, _name);
	new_node->playerScore = _score;

	if (list_head == NULL) // 리스트 헤드에 아무것도 없을때, 이번에 얻은 점수를 헤드에 추가
	{
		new_node->next = list_head;
		list_head = new_node;
		return;
	}

	next_p = list_head;
	prev_p = NULL;

	while (next_p) { // 연결리스트를 순회하면서 맞는 자리 찾아가기
		if (next_p->playerScore < new_node->playerScore)
			break;
		prev_p = next_p;
		next_p = next_p->next;
	}
	new_node->next = next_p;

	if (prev_p) // 중간에 삽입
		prev_p->next = new_node;
	else // 처음에 삽입
		list_head = new_node;
	printf("랭킹표에 등록되었습니다.\n\n");
}

void SaveRanking(RANKING* head)
{
	FILE* fp = fopen("Ranking.txt", "wt"); // 랭킹을 저장할 파일 열기
	if (fp == NULL)
	{
		printf("파일 오픈 실패!");
		return;
	}

	int count = 0; //랭킹 10위까지만 저장하기위한 변수
	while (count < 10) {
		if (head == NULL) // 
		{
			printf("저장할 랭킹이 없습니다.");
			return;
		}
		fprintf(fp, "%s %d", head->name, head->playerScore);
		if (head->next == NULL) // 다음값이 널이면 루프 탈출
			break;
		head = head->next;
		count++;
	}
	printf("랭킹 저장이 완료되었습니다.\n");
	fclose(fp);
	ShowRanking(list_head);
}

void LoadRanking()
{
	FILE * fp = fopen("Ranking.txt", "rt");
	if (fp == NULL)
		return;

	int confirm; // fscanf가 제데로 실행되었나 확인하는 변수
	int count = 0; // 랭킹 10위까지만 가져오게 하는 변수
	while (count < 10)
	{
		if (feof(fp) != 0) // 파일의 끝 도달시 루프 탈출 1
			break;

		printf("%d\n", count);
		new_node = (RANKING*)malloc(sizeof(RANKING));
		confirm = fscanf(fp, "%s %d", new_node->name, &(new_node->playerScore));

		new_node->next = list_head;
		list_head = new_node;
		count++;

		if (confirm == EOF) // 파일의 끝 도달시 루프 탈출확인 2
			break;
	}
	fclose(fp);
}

int main()
{
	LoadRanking(); // 실행하면 랭킹 바로 불러오기
	mainMenu();
}