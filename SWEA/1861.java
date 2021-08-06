import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

// C++ pair를 구현함.
class Pair{
	Integer y;
	Integer x;
	
	public Pair(Integer y, Integer x) {
		this.y = y;
		this.x = x;
	}
	public Integer first() {
		return y;
	}
	public Integer second() {
		return x;
	}
}

public class Main {
	private static int N;
	private static int[][] arr;
	
	private static int idx;
	private static int MAX;
	
	private static int[] dy = {-1,1,0,0};
	private static int[] dx = {0,0,-1,1};
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int t=1; t<=T; t++) {
			
			// init
			N = sc.nextInt();
			arr = new int[N][N];
			for(int i=0; i<N; i++)
				for(int j=0; j<N; j++)
					arr[i][j] = sc.nextInt();
			idx = Integer.MAX_VALUE;
			MAX = Integer.MIN_VALUE;
			
			// solve!
			sol();
			
			// print answer
			System.out.println("#" + t + " " + idx + " " + MAX);
		}
	}
	
	// 문제 풀이
	private static void sol() {
		for(int y=0; y<N; y++) {
			for(int x=0; x<N; x++) {
				
				// bfs call
				int sum = bfs(y, x);
				
				// compare 
				if(sum > MAX) {
					MAX = sum;
					idx = arr[y][x];
				}
				if(MAX==sum && idx > arr[y][x])
					idx = arr[y][x];
			}
		}
	}
	
	// 탐색 
	private static int bfs(int y, int x) {
		Queue<Pair> q = new LinkedList<>();
		boolean[][] visited = new boolean[N][N];
		
		visited[y][x] = true;
		q.add(new Pair(y, x));
		
		int sum = 1;
		while(!q.isEmpty()) {
			y = q.peek().first();
			x = q.peek().second();
			q.poll();
			
			for(int i=0; i<4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				// 맵 안이고, 가본적 없고, 정확하게 현재보다 1 만큼 더 클때만 이동.
				if(check(ny, nx) && !visited[ny][nx] && (arr[y][x]+1==arr[ny][nx])) {
					sum++;
					visited[ny][nx] = true;
					q.add(new Pair(ny, nx));
				}
			}
		}
		return sum;
	}
	
	// 인덱스 범위 체크
	private static boolean check(int y, int x) {
		return y>=0 && y<N && x>=0 && x<N;
	}

}
