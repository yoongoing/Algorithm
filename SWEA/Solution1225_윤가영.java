import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

public class {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		for(int k=0; k<10; k++) {
			String T = sc.next();
			
			Deque<Integer> dq = new LinkedList<>();
			for(int i=0; i<8; i++) {
				int a = sc.nextInt();
				dq.addLast(a);
			}
			
			while(true) {
				
				// while문 탈출 조건
				boolean flag = false;
				
				// 1 사이클 당 5개 작업
				for(int i=1; i<=5; i++) {
					int front = dq.getFirst();
					dq.pollFirst();
					
					int next = front - i;
					
					// while문 탈출 조건
					if(next <= 0) {
						dq.addLast(0);
						flag = true;
						break;
					}
					dq.addLast(next);
				}
				if(flag)
					break;
			}
			
			System.out.print("#" + T + " ");
			while(!dq.isEmpty()) {
				System.out.print(dq.getFirst() + " ");
				dq.pollFirst();
			}
			System.out.println();
		}
	}

}
