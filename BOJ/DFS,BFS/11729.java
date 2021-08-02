import java.util.*;

public class Main {
	static int cnt=0;
	static StringBuilder sb = new StringBuilder();
	
	static void hanoi(int n,int S,int T,int D) {
		cnt++;
		if(n==1) { // 원판이 1개
			sb.append(S+" "+D+"\n");
			return;
		}else {
			hanoi(n-1,S,D,T); 
			sb.append(S+" "+D+"\n");
			hanoi(n-1,T,S,D);
		}
	}
	
	public static void main(String[] args)   {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		hanoi(n,1,2,3);
		System.out.println(cnt);
		System.out.println(sb);
		
	}
	
}
