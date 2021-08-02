import java.util.Scanner;

public class Combination {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int r = sc.nextInt();
		System.out.println(combination(N,r));
	}
	
	private static int combination(int N, int r) {
		if(N==0 || r==0 || N==r)	return 1;
		if(r==1 && N!=1)			return N;
		return combination(N-1, r-1) + combination(N-1, r);
	}

}
