#include <stdio.h>
#define S(n) (scanf("%d",&n))
#define MAX 101

typedef struct _point {
	int x,y;
} Point;

Point hermione, ext;

char forest[MAX][MAX];
int count[MAX][MAX], wand[MAX][MAX], visited[MAX][MAX];
int n, m;

Point queue[MAX*MAX];
int front, back;

void init_q(){
	front = back = -1;
}
int empty_q(){
	return ((front>back)||(front==back && front==-1));
}
void enqueue(Point p){
	if(front == back && front==-1){
		front = back = 0;
	}else{
		back++;
	}
	queue[back] = p;
}

Point dequeue(){
	if(!empty_q()){
		return queue[front++];
	}
}

int inbound(int i, int j){
	return (i>=0 && i<n && j>=0 && j<m);
}

void isvalid(Point p){
	Point p1;
	p1.x = p.x, p1.y = p.y-1;
	int cnt = 0;
	if(inbound(p1.x, p1.y) && (forest[p1.x][p1.y] == '.' || forest[p1.x][p1.y]=='*')){
		enqueue(p1);
		count[p1.x][p1.y] = 1+ count[p.x][p.y];
		cnt++;
	}
	p1.x = p.x-1, p1.y = p.y;
	if(inbound(p1.x, p1.y) && (forest[p1.x][p1.y] == '.' || forest[p1.x][p1.y]=='*')){
		enqueue(p1);
		count[p1.x][p1.y] = 1+ count[p.x][p.y];
		cnt++;
	}
	p1.x = p.x, p1.y = p.y+1;
	if(inbound(p1.x, p1.y) && (forest[p1.x][p1.y] == '.' || forest[p1.x][p1.y]=='*')){
		enqueue(p1);
		count[p1.x][p1.y] = 1+ count[p.x][p.y];
		cnt++;
	}
	p1.x = p.x+1, p1.y = p.y;
	if(inbound(p1.x, p1.y) && (forest[p1.x][p1.y] == '.' || forest[p1.x][p1.y]=='*')){
		enqueue(p1);
		count[p1.x][p1.y] = 1+ count[p.x][p.y];
		cnt++;
	}
	if(cnt > 1){
		wand[p.x][p.y] = 1;
	}
}

int travel(){
	int i,j;
	Point p;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			count[i][j] = wand[i][j] = visited[i][j] = 0;
		}
	}
	init_q();
	enqueue(hermione);
	visited[hermione.x][hermione.y] = 1;
	while(!empty_q()){
		p = dequeue();
		if(forest[p.x][p.y] == '*')
			break;
		isvalid(p);
	}
}

int main(int argc, char **argv) {
	int t, count = 0, i, j, k;
	S(t);
	while(t--){
		S(n), S(m);
		for(i=0;i<n;n++){
			scanf("%s", &forest[i]);
			for(j=0;j<m;i++){
				if(forest[i][j] == 'M'){
					hermione.x = i, hermione.y = j;
				}else if(forest[i][j] == '*'){
					ext.x = i, ext.y = j;
				}
			}
		}
		S(k);
		count = travel();
		if(count == k){
			printf("Impressed\n");
		}else{
			printf("Oops!\n");
		}
	}
	return 0;
}