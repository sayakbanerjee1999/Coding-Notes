import java.io.*;
import java.util.*;

public class Main {


  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String exp = br.readLine();

    // code
    Stack<Integer> operand = new Stack<>();
    Stack<Character> operator = new Stack<>();
    for (int i = 0; i < exp.length(); i++) {
      char ch = exp.charAt(i);
      if (ch == '(') {
        operator.push(ch);
      } else if (Character.isDigit(ch)) {
        operand.push(ch-'0');
      } else if (ch == ')') {
        while (operator.peek() != '('){
            char op = operator.pop();
            int v2 = operand.pop();
            int v1 = operand.pop();
            int opv = oper(v1,v2,op);
            operand.push(opv);
        }
        operator.pop();
      } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
          //ch wanting higher priority operators to solve first
            while (operator.size()>0 && operator.peek()!='(' && prec(ch)<=operator.peek()){
                char op = operator.pop();
                int v2 = operand.pop();
                int v1 = operand.pop();
                int opv = oper(v1,v2,op);
                operand.push(opv);
            }
            //now ch will push itself
            operator.push(ch);
      }
    }
    while (operator.size() != 0){
            char op = operator.pop();
            int v2 = operand.pop();
            int v1 = operand.pop();
            int opv = oper(v1,v2,op);
            operand.push(opv);
        }
        
    System.out.println(operand.peek());

  }
  public static int prec(char op) {
    if (op == '+' || op == '-') {
      return 1;
    } else {
      return 2;
    }
  }

  public static int oper(int v1, int v2, char op) {
    if (op == '+') {
      return v1 + v2;
    } else if (op == '-') {
      return v1 - v2;
    } else if (op == '*') {
      return v1 * v2;
    } else {
      return v1 / v2;
    }
  }
}
