package assignment_7;

import java.util.Stack;

public class Postfix {

    public static int evaluate(String expression) {
        Stack<Integer> stack = new Stack<>();

        String[] tokens = expression.split(" ");

        for (int i = 0; i < tokens.length; i++) {
            String token = tokens[i];

            if (token.equals("+") || token.equals("-") ||
                token.equals("*") || token.equals("/")) {

                int b = stack.pop();
                int a = stack.pop();

                if (token.equals("+")) {
                    stack.push(a + b);
                } 
                else if (token.equals("-")) {
                    stack.push(a - b);
                } 
                else if (token.equals("*")) {
                    stack.push(a * b);
                } 
                else {
                    stack.push(a / b);
                }
            } 
            else {
                stack.push(Integer.parseInt(token));
            }
        }

        return stack.pop();
    }

    public static void main(String[] args) {
        String expression = "2 3 1 * + 9 -";

        System.out.println(evaluate(expression));
    }
}
