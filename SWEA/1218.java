import java.util.Scanner;
import java.util.Stack;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 항상 10개의 테스트케이스
		for(int t=1; t<=10; t++) {
			Stack<Character> s = new Stack<>();
			
			int N = sc.nextInt();
			String str = sc.next();
			
			for(int i=0; i<N; i++) {
				if(s.empty())
					s.push(str.charAt(i));
				else {
					if(check(s.peek(), str.charAt(i)))
						s.pop();
					else
						s.push(str.charAt(i));
				}
			}
			if(s.empty())
				System.out.println("#" + t + " 1");
			else
				System.out.println("#" + t + " 0");
		}
	}
	
	private static boolean check(char a, char b) {
		switch(a) {
		//'()', '[]', '{}', '<>'
		case '(':
			if(b != ')')
				return false;
			return true;
		case '[':
			if(b != ']')
				return false;
			return true;
		case '{':
			if(b != '}')
				return false;
			return true;
		case '<':
			if(b != '>')
				return false;
			return true;
		}
		return false;
	}

}
