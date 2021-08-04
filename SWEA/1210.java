import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
	private static int[] dy = {0,0,-1};
	private static int[] dx = {-1,1,0};
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		
		//항상 10개의 테스트케이스
		for(int t=0; t<10; t++) {
			
			int T = Integer.parseInt(bf.readLine().trim());
			int[][] arr = new int[100][100];
			int[][] visited = new int[100][100];
			
			// 밑에서 부터 거슬러 올라가자!
			int start_y=0, start_x=0;
			for(int i=0; i<100; i++) {
				String[] str = bf.readLine().split(" ");
				for(int j=0; j<100; j++) {
					arr[i][j] = Integer.parseInt(str[j]);
					
					// 거슬러 올라가는 지점 저장
					if(arr[i][j] == 2) {
						start_y = i;
						start_x = j;
					}
				}
			}
			
			// go!
			int ans = go(arr, visited, start_y, start_x);
			
			System.out.println("#" + T + " " + ans);
		}
	}

	private static int go(int[][] arr, int[][] visited, int y, int x) {
		// check-in
		visited[y][x] = 1;
		
		while(true) {
			// 왼쪽 -> 오른쪽 -> 위
			for(int dir=0; dir<3; dir++) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				
				// 도착
				if(ny == 0)
					return nx;
				
				// 범위 내 & 길이 있음 & 방문한적 없음
				if(check(ny, nx) && arr[ny][nx]!=0 && visited[ny][nx]==0) {
					y = ny;
					x = nx;
					visited[ny][nx] = 1;
					break; // 중요!
				}
			}
		}
	}
	
	// 범위 체크 
	private static boolean check(int y, int x) {
		return y>=0 && y<100 && x>=0 && x<100;
	}
}
