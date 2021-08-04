import java.util.Scanner;

public class Main {
	private static int H,W;
	private static char[][]arr;
	
	private static int y;
	private static int x;
	
	// ^:0 v:1 <:2 >:3
	private static int dir;
	private static int[] dy = {-1,1,0,0};
	private static int[] dx = {0,0,-1,1};
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int t=1; t<=T; t++) {
			H = sc.nextInt();
			W = sc.nextInt();		
			arr = new char[H][W];
			
			for(int i=0; i<H; i++) {			
				String str = sc.next();
				
				for(int j=0; j<str.length(); j++) {
					arr[i][j] = str.charAt(j);
					
					// 초기 좌표와 위치 저장
					if(arr[i][j]=='^' || arr[i][j]=='v' || arr[i][j]=='<' || arr[i][j]=='>') {
						y = i;
						x = j;
						dir = parseDir(arr[i][j]);
					}		
				}
			}
			
			int N = sc.nextInt();
			String str = sc.next();
			
			// Game Start!
			for(int i=0; i<N; i++) {
				char cur = str.charAt(i);
				act(cur);
			}
			
			System.out.print("#" + t + " "); 
			print();
			
		}
	}
	private static void act(char cur) {
		int ny=0, nx=0;
		switch(cur) {
		case 'U' :
			dir = 0;
			arr[y][x] = '^';	
			ny = y + dy[0];
			nx = x + dx[0];
			if(check(ny, nx) && arr[ny][nx]=='.') {
				arr[y][x] = '.';
				arr[ny][nx] = '^';	
				y = ny;
				x = nx;
			}
			break;
		case 'D' :
			dir = 1;
			arr[y][x] = 'v';
			ny = y + dy[1];
			nx = x + dx[1];
			if(check(ny, nx) && arr[ny][nx]=='.') {				
				arr[y][x] = '.';
				arr[ny][nx] = 'v';
				y = ny;
				x = nx;
			}
			break;
		case 'L' :
			dir = 2;
			arr[y][x] = '<';
			ny = y + dy[2];
			nx = x + dx[2]; 
			if(check(ny, nx) && arr[ny][nx]=='.') {
				arr[y][x] = '.';
				arr[ny][nx] = '<';		
				y = ny;
				x = nx;
			}
			break;
		case 'R' :
			dir = 3;
			arr[y][x] = '>';
			ny = y + dy[3];
			nx = x + dx[3]; 
			if(check(ny, nx) && arr[ny][nx]=='.') {
				arr[y][x] = '.';
				arr[ny][nx] = '>';
				y = ny;
				x = nx;
			}
			break;
		case 'S' :
			shoot();
			return;
		}
	}
	private static void shoot() {
		int by=y, bx=x;
		while(true) {
			int bny = by + dy[dir];
			int bnx = bx + dx[dir];
			
			// 슛 종료 조건
			if(!check(bny, bnx) || arr[bny][bnx]=='#') {
				break;
			}
			
			// 벽돌 벽 부딪힐 때
			if(arr[bny][bnx]=='*') {
				arr[bny][bnx] = '.';
				break;
			}
			
			by = bny;
			bx = bnx;
		}
	}
	
	private static void print() {
		for(int i=0; i<H; i++) {
			for(int j=0; j<W; j++)
				System.out.print(arr[i][j]);
			System.out.println();
		}
	}
	private static int parseDir(char c) {
		if(c == '^')	return 0;
		if(c == 'v')	return 1;
		if(c == '<')	return 2;
		return 3;
	}
	private static boolean check(int y, int x) {
		return y>=0 && x>=0 && y<H && x<W;
	}
}
