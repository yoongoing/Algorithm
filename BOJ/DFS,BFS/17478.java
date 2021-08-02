import java.util.Scanner;

public class Main {
	static String[] story = {"\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.",
			"마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지."
			,"그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\""};
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		// start
		System.out.println("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.");
		recursive(n, 0);
	}
	
	private static void recursive(int n, int cnt) {
		// ask - 필수
		for(int i=0; i<cnt; i++) 
			System.out.print("____");
		System.out.println("\"재귀함수가 뭔가요?\"");
		
		// end - 마무리 
		if(cnt == n) {
			for(int i=0; i<cnt; i++) {
				System.out.print("____");
			}
			System.out.println("\"재귀함수는 자기 자신을 호출하는 함수라네\"");
			for(int i=0; i<cnt; i++) {
				System.out.print("____");
			}
			System.out.println("라고 답변하였지.");
			return;
		}
		
		// talk - n번 필수
		for(int i=0; i<story.length; i++) {
			for(int j=0; j<cnt; j++) {
				System.out.print("____");
			}
			System.out.println(story[i]);
		}
		
		recursive(n, cnt+1);
		
		// end - 마무리
		for(int i=0; i<cnt; i++) {
			System.out.print("____");
		}
		System.out.println("라고 답변하였지.");
	}
}
