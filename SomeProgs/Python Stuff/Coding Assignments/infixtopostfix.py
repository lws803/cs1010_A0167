class Stack_front(object):
    def __init__(self):
        self.data = []

    def IsEmpty(self):
        return len(self.data) == 0

    def push(self,data):
        self.data.insert(0,data)

    def pop(self):
        return self.data.pop(0)

    def size(self):
        return len(self.data)

    def peek(self):
        return self.data[0] #peek at data at the top of the stack

def operate(token,y,x):
    if token == "+":
        return y + x
    elif token == "-":
        return y - x
    elif token == "*":
        return y * x
    elif token == "/":
        return y / x

def infix_to_postfix(infixexpression):
    opStack = Stack_front()
    postfixList = []
    tokenList = infixexpression.split()
    prec = {} #Setting the precedence weight of the operators
    prec["*"] = 3
    prec["/"] = 3
    prec["+"] = 2
    prec["-"] = 2
    prec["("] = 1
    prec[")"] = 1
    
    ##ALGORITHM
    ##Step 1:	PUSH a left parenthesis ‘(’ onto STACK and append right parenthesis ‘)’ to end of input string, Q
    opStack.push("(")
    tokenList.append(')')
    
    ##Step 2:	While STACK is not empty, read Q from left to right and do steps 2a to 2d
    for token in tokenList:
    
    ##Step 2a:	If current character is an operand, copy to output string, P
        if token.isalnum():
            postfixList.append(token)
    
    ##Step 2b:	If current character is a ‘(’, PUSH it on STACK
        elif token == "(":
            opStack.push(token)
    
    ##Step 2c:	If current character is an operator @, then
    ##(i)	POP operators (if any) from STACK while they have equal or higher precedence than @, and insert the popped operators in P
    ##(ii)	PUSH @ to STACK
        elif token in "*/+-":
            while prec[opStack.peek()] >= prec[token]:
                postfixList.append(opStack.pop())

            opStack.push(token)
            
    ##Step 2d:	If current character is ‘)’, then
    ##(i)	POP operators from STACK and insert in P until a ‘(’ is at the top of STACK
    ##(ii)	POP (and discard) the ‘(’ from the STACK

        elif token == ")":
            topToken = opStack.pop()
            while topToken != '(':
                postfixList.append(topToken)
                topToken = opStack.pop()
    ##Step 3:  Exit
    return " ".join(postfixList)    

def evaluate_postfix(postfixexpression):
    opStack = Stack_front()
    tokenList = postfixexpression.split()
    ##ALGORITHM
    ##Step 1:	Append NULL character ‘\0’ at end of P (Processing stops when NULL is encountered)
    ##No need to do in Python
    ##Step 2:	While NULL has not been encountered, read P from left to right and repeat steps 2a and 2b
    for token in tokenList:
        
    ##Step 2a:	If current character is an operand, PUSH it onto STACK
        if token.isdigit():
            opStack.push(int(token))
    ##Step 2b:	If current character is an operator @, then
    ##    Pop top 2 elements of STACK into variables x and y
    ##    Calculate y @ x
    ##    PUSH result to STACK
        else:
            operand_x = opStack.pop()
            operand_y = opStack.pop()
            result = operate(token,operand_y,operand_x)
            opStack.push(result)
    ##Step 3:	When NULL is encountered, POP top value of STACK (This is the result of the Postfix expression)
    ##No need to do in Python
    ##Step 4:	Exit
    return opStack.pop()

print(evaluate_postfix(infix_to_postfix("5 * ( 6 + 2 ) - 12 / 4")))
print(evaluate_postfix(infix_to_postfix("6 + 7 * 10")))

print(infix_to_postfix("5 * ( 6 + 4 ) - 12 / 4"))
