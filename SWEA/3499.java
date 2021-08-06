import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		for(int t=1; t<=T; t++) {
			int N = sc.nextInt();
			String[] arr = new String[N+1];
			
			for(int i=1; i<=N; i++)
				arr[i] = sc.next();
			
			int H = parseH(N); // 첫번째로 끼워넣을 카드 인덱스 파싱
			
			ArrayList<String> result = new ArrayList<>();
			result.add(arr[1]); // 첫번째 카드는 미리 넣어놓기
			int idx = 2;
			
			for(int i=H; i<=N; i++) {
				result.add(arr[i]);
				
				// 카드가 홀수개면 상관없지만, 짝수개면 마지막 카드는 안넣어야함.
				if(N%2==0 && i!=N)
					result.add(arr[idx++]);
				if(N%2 == 1)
					result.add(arr[idx++]);
			}
			
			// 정답 출력
			System.out.print("#" + t + " ");
			for(int i=0; i<result.size(); i++)
				System.out.print(result.get(i) + " ");
			System.out.println();
		}
	}
	private static int parseH(int N) {
		if(N%2 == 0) {
			return N/2+1;
		}
		return N/2+2;
	}

}
