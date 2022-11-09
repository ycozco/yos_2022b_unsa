#include<stdio.h>

#include<stdlib.h>

#include<pthread.h>

#include<sys/sem.h>

#include<sys/ipc.h>

#define KEY 12345
#define PERM 0666

int a[5][5];
void init();
void display();
char check();
int semid;
//int th_args[8]={0,1,2,3,4,5,6,7};
static struct sembuf move[2] = {
  0,
  0,
  0,
  0,
  1,
  0
};

static struct sembuf release[1] = {
  0,
  -1,
  IPC_NOWAIT
};

void l_move() {
  semop(semid, & move[0], 2);
}

void l_release() {
  semop(semid, & release[0], 1);
}

void leader_move() {
  int x, y;
  printf("Enter X,Y coordinates for ur move: ");
  printf("\n");
  scanf("%d%*c%d", & x, & y);
  x--;
  y--;
  l_move(); //here cn be the problem
  if (a[x][y] != ' ') {
    printf("Invalid move, try again.\n");
    leader_move();
  }
  // l_move();
  else a[x][y] = 'x';
  l_release();
}

void * th1_move() {
  int i, j;
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++)
      if (a[i][j] == ' ') break;
    if (a[i][j] == ' ') break;
  }

  if (i * j == 9) {
    printf("draw\n");
    exit(0);
  } else
    a[i][j] = 'O';
}

void * th2_move() {
  int i, j;
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++)
      if (a[i][j] == ' ') break;
    if (a[i][j] == ' ') break;
  }

  if (i * j == 9) {
    printf("draw\n");
    exit(0);
  } else
    a[i][j] = '1';
}

void * th3_move() {
  int i, j;
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++)
      if (a[i][j] == ' ') break;
    if (a[i][j] == ' ') break;
  }

  if (i * j == 9) {
    printf("draw\n");
    exit(0);
  } else
    a[i][j] = '2';
}

void main() {
  printf("Juego 3 en raya\n");
  char done = ' ';
  int i, j;
  pthread_t th1, th2, th3;
  if ((semid = semget(KEY, 1, IPC_CREAT | PERM)) < 0)
    printf("error");
  init();

  do {
    display();
    //l_move(semid);
    leader_move();
    //pthread_create(&th,NULL,leader_move,NULL);
    //l_release(semid);
    done = check();
    if (done != ' ') break;
    pthread_create( & th1, NULL, th1_move, NULL);
    done = check();
    pthread_create( & th2, NULL, th2_move, NULL);
    done = check();
    pthread_create( & th3, NULL, th3_move, NULL);
    done = check();
  } while (done == ' ');
  if (done == 'x')
    printf("leader win\n");
  else if (done == '0')
    printf("player1 win\n");
  else if (done == '1')
    printf("player2 win\n");
  else
    printf("player3 win");
  display();

  // create players
  // for(i=0;i<3;i++)
}

void init() {
  int i, j;

  for (i = 0; i < 5; i++)
    for (j = 0; j < 5; j++) a[i][j] = ' ';

}

void display() {
  int i;

  for (i = 0; i < 5; i++) {
    printf(" %c | %c | %c | %c | %c ", a[i][0],
      a[i][1], a[i][2], a[i][3], a[i][4]);
    if (i != 4) printf("\n---|---|---|---|---\n");
  }
  printf("\n");

}

char check() {
  int i;
  for (i = 0; i < 5; i++)
    if (a[i][0] == a[i][1] &&
      a[i][0] == a[i][2] &&
      a[i][0] == a[i][3] &&
      a[i][0] == a[i][4])

      return a[i][0];

  for (i = 0; i < 5; i++)
    if (a[0][i] == a[1][i] &&
      a[0][i] == a[2][i] &&
      a[0][i] == a[3][i] &&
      a[0][i] == a[4][i])
      return a[0][i];

  if (a[0][0] == a[1][1] &&
    a[1][1] == a[2][2] &&
    a[2][2] == a[3][3] &&
    a[3][3] == a[4][4])
    return a[0][0];

  if (a[0][4] == a[1][3] &&
    a[1][3] == a[2][2] &&
    a[2][2] == a[3][1] &&
    a[3][1] == a[4][0])
    return a[0][4];

  return ' ';
}
