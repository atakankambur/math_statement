# math_statement
a math statement which the operator is placed after the operands. 2 operands 1 operator = result
1-Read the characters from left to right in the given statement.
2-If the reading character is operand then push it on to the stack.
3-If the reading symbol is operator (+ , - , * , /) then store the two popped operands in two different variables. 
  Then perform reading character operation using operand1 and operand2 and push result back on to the stack.
4-Lastly perform a pop operation and display the result.
Example Output:
    Enter myMath statement:93-76+*
    Result of myMath statement:69
    Enter myMath statement:198+2-+*
    Result of myMath statement:6
