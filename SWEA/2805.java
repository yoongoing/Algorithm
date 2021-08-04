import java.util.Scanner;

public class Main {
	private static int N;
	private static int[][] arr;
	private static int[][] visited;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		for(int t=1; t<=T; t++) {
			N = sc.nextInt();
			arr = new int[N][N];
			visited = new int[N][N];
			
			for(int i=0; i<N; i++) {
				String str = sc.next();
				for(int j=0; j<N; j++)
					arr[i][j] = str.charAt(j) - '0';
			}
			
			int ans = harvest(0);
			System.out.println("#" + t + " " + ans);
		}
	}
	
	private static int harvest(int sum) {
		int H = N/2;
		
		int y = 0;
		for(int i=H+1; i>0; i--) {
			
			int x = 0;
			for(int j=i-1; j>0; j--)
				x++;

			for(int j=0; j<=H-i+1; j++) {
				// 기본 
				if(visited[y][x] == 0) {
					visited[y][x] = 1;
					sum += arr[y][x];
				}
				// x축 대칭이동 
				if(visited[y][x + (H-x)*2] == 0) {
					visited[y][x + (H-x)*2] = 1;
					sum += arr[y][x + (H-x)*2];
				}
				// y축 대칭이동
				if(visited[y + (H-y)*2][x] == 0) {
					visited[y + (H-y)*2][x] = 1;
					sum += arr[y + (H-y)*2][x];
				}
				// x,y축 대칭이동
				if(visited[y + (H-y)*2][x + (H-x)*2] == 0) {
					visited[y + (H-y)*2][x + (H-x)*2] = 1;
					sum += arr[y + (H-y)*2][x + (H-x)*2];
				}
				x++;
			}
			y++;
		}
		return sum;
	}
}
