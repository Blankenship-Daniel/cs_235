#ifndef EXPRESSIONMANAGER_H_
#define EXPRESSIONMANAGER_H_

#include "ExpressionManagerInterface.h"
#include <algorithm>
#include <sstream>
#include <cctype>
#include <vector>

const string OPEN  = "([{";
const string CLOSE = ")]}";
const string OPERATORS = "+-*/%()";
const int PRECEDENCE[] = { 1, 1, 2, 2, -1, -1 }; 

class ExpressionManager : public ExpressionManagerInterface
{
public:
    ExpressionManager() : postfix(""), infix(""), error(false)
    {}

    ~ExpressionManager()
    {}

   /*
	* Checks whether an expression is balanced on its parentheses
	*
	* - The given expression will have a space between every number or operator
	* 
	* @return true if expression is balanced
	* @return false otherwise
	*/
    bool isBalanced(string expression)
    {
        stack<char> s;        // used to store each element in expression string
        bool balanced = true; // tracks whether the string is balanced or not
        int index = 0;        // tracks to see if entire string has been read

        // removes all spaces from the string
        expression = removeSpaces(expression);
        
        // while balanced is equal to true and the end of the expression
        //  string has not been reached
        while (balanced && index < expression.length())
        {
            // store single character from the expression string
            char next_ch = expression[index];

            // if char is "[", "(", or "{"
            if (isOpen(next_ch))
            {
                // push onto the stack
                s.push(next_ch);
            } // if char is "]", ")", or "}"
            else if (isClose(next_ch))
            {
                // if the stack is empty
                if (s.empty())
                {
                    balanced = false;
                }
                else
                {
                    char top_ch = s.top(); // grab the char off of the top of the stack
                    s.pop(); // pop it off
                    balanced = OPEN.find(top_ch) == CLOSE.find(next_ch); // if an opening and closing bracket is found
                }
            }
            ++index;
        }
        return balanced && s.empty();
    }

    /*
     * Removes all spaces from a given expression
     *
     * - i.e. ( ( A + B ) / ( C * D ) ) becomes ((A+B)/(C*D))
     */
    string removeSpaces(string expression)
    {
        expression.erase(remove_if(expression.begin(), expression.end(), ::isspace), expression.end());
        return expression;
    }

    bool isOpen(char ch)
    {
        // searches for the string in the constant OPEN
        //  if it doesn't find what it was looking for it returns
        //  TRUE for found
        //  FALSE otherwise
        return OPEN.find(ch) != string::npos; // string::npos is a way to say no position
    }

    bool isClose(char ch)
    {
        // searches for the string in the constant CLOSE
        //  if it doesn't find what it was looking for it returns
        //  TRUE for found
        //  FALSE otherwise
        return CLOSE.find(ch) != string::npos;
    }

    /**
	 * Converts a postfix expression into an infix expression
	 * and returns the infix expression.
	 *
	 * - The given postfix expression will have a space between every number or operator.
	 * - The returned infix expression must have a space between every number or operator.
	 * - Redundant parentheses are acceptable i.e. ( ( 3 * 4 ) + 5 ).
	 * - Check lab requirements for what will be considered invalid.
	 *
	 * return the string "invalid" if postfixExpression is not a valid postfix expression.
	 * otherwise, return the correct infix expression as a string.
	 */
    string postfixToInfix(string postfixExpression)
    {
        infix = "";
       
        for (int i = 0; i < postfixExpression.length(); i++)
        {
            if (postfixExpression[i] == '.')
            {
                return "invalid";
            }
        }
        
        stack<string> op_stack;
        
        istringstream postfix_tokens(postfixExpression);
        string next_token;

        while (postfix_tokens >> next_token)
        {
            if (isdigit(next_token[0]))
            {
                op_stack.push(next_token);   
            }
            else if (is_operator(next_token[0]))
            {
                infix = "";
                if (op_stack.empty())
                {
                    return "invalid";
                }
                string rhs = op_stack.top();
                op_stack.pop();
                if (op_stack.empty())
                {
                    return "invalid";
                }
                string lhs = op_stack.top();
                op_stack.pop();

                infix += "( ";
                infix += lhs;
                infix += " ";
                infix += next_token;
                infix += " ";
                infix += rhs;
                infix += " )";

                op_stack.push(infix);
            }
            else
            {
                return "invalid";
            }
        }
        if (op_stack.empty())
        {
            return "invalid";
        }
        infix = op_stack.top();
        op_stack.pop();
        if (!op_stack.empty())
        {
            return "invalid";
        }
        return infix;
    }
    
    /*
	 * Converts an infix expression into a postfix expression 
	 * and returns the postfix expression
	 * 
	 * - The given infix expression will have a space between every number or operator.
	 * - The returned postfix expression must have a space between every number or operator.
	 * - Check lab requirements for what will be considered invalid.
	 * 
	 * return the string "invalid" if infixExpression is not a valid infix expression.
	 * otherwise, return the correct postfix expression as a string.
	 */
    string infixToPostfix(string infixExpression)
    {
        postfix = "";
       
        for (int i = 0; i < infixExpression.length(); i++)
        {
            if (infixExpression[i] == '.')
            {
                return "invalid";
            }
        }

        bool balanced = isBalanced(infixExpression);
        if (!balanced)
        {
            return "invalid";
        }

        bool valid_infix = is_valid_infix(infixExpression);
        if (!valid_infix)
        {
            return "invalid";
        }

        while (!operator_stack.empty())
            operator_stack.pop();

        istringstream infix_tokens(infixExpression);
        string next_token;

        while (infix_tokens >> next_token)
        {
            if (isdigit(next_token[0]))
            {
                postfix += next_token;
                postfix += " ";
            }
            else if (is_operator(next_token[0]))
            {
                bool valid = process_operator(next_token[0]);
                if (!valid)
                {
                    return "invalid";
                }
            }
            else 
            {
                return "invalid";
            }
        }

        int i = 0;
        // Pop any remaining operators and append them to postfix
        while (!operator_stack.empty())
        {
            char op = operator_stack.top();
            operator_stack.pop();
            if (op == '(')
            {
                return "invalid";
            }
            if (i == 0)
            {
                postfix += op;
            }
            else
            {
                postfix += " ";
                postfix += op;
            }
            i++;
        }
        return postfix;
    }
    
    /*
	 * Evaluates a postfix expression returns the result as a string
	 *
	 * - The given postfix expression will have a space between every number or operator.
	 * - Check lab requirements for what will be considered invalid.
	 * 
	 * return the string "invalid" if postfixExpression is not a valid postfix Expression
	 * otherwise, return the correct evaluation as a string
	 */
    string postfixEvaluate(string postfixExpression)
    {
        while (!op_stack.empty())
        {
            op_stack.pop();
        }
        istringstream tokens(postfixExpression);
        char next_char;
        
        while (tokens >> next_char)
        {
            if (isdigit(next_char))
            {
                tokens.putback(next_char);
                int value = 0;
                tokens >> value;
                op_stack.push(value);
            }
            else if (is_operator(next_char))
            {
                int result = eval_op(next_char);
                if (error && result == -1)
                {
                    error = false;
                    return "invalid";
                }

                op_stack.push(result);
            }
            else
            {
                return "invalid";
            }
        }
        if (!op_stack.empty())
        {
            int ans = op_stack.top();
            string answer;
            
            // perform the conversion from int to string
            ostringstream convert;
            convert << ans;
            answer = convert.str();
            
            // pop that value off of the stack
            op_stack.pop();

            if (op_stack.empty())
            {
                return answer;
            }
            else
            {
                return "invalid";
            }
        }
        else
        {
            return "invalid";
        }
    }

private:
    
    /*
     * Determines whether the string given is an operator token or not
     *
     * - if the string is an operator function returns true
     * - if the string is not an operator function returns false
     *
     */
    bool is_operator(char op)
    {
        return OPERATORS.find(op) != string::npos;
    }

    /*
     * Determines the precedence of the operator.
     *
     * - value that returns 0 has less precedence.
     * - value that returns 1 has greater precedence etc.
     */
    int precedence(char op) const
    {
        return PRECEDENCE[OPERATORS.find(op)];
    }

    // process operator
    bool process_operator(char op)
    {
        if (operator_stack.empty() || (op == '('))
        {
            if (op == ')')
            {
                return false;
            }
            operator_stack.push(op);
        }
        else
        {
            if (precedence(op) > precedence(operator_stack.top()))
                operator_stack.push(op);
            else
            {
                // Pop all stacked operators with equal 
                // or higher precedence than op.
                while (!operator_stack.empty() && 
                       (operator_stack.top() != '(') && 
                       (precedence(op) <= precedence(operator_stack.top())))
                {
                    postfix += operator_stack.top();
                    postfix += " ";
                    operator_stack.pop();
                }
                if (op == ')')
                {
                    if (!operator_stack.empty() && (operator_stack.top() == '('))
                        operator_stack.pop();
                    else
                    {
                        return false;
                    }
                }
                else
                    operator_stack.push(op);
            }
        }
        return true;
    }

    // is valid infix expression
    bool is_valid_infix(string expression)
    {
        istringstream tokens(expression);
        string next_token;

        int i = 1; 
        while (tokens >> next_token)
        {
           if (is_operator(next_token[0]) && next_token != ")" &&  next_token != "(")
           {
               i++;
           }
           else if (isdigit(next_token[0]))
           {
               i--;
           }
        }
        if (i != 0)
        {
            return false;
        }
        return true;
    }

    // division by zero
    bool div_by_zero(int numerator, int denominator)
    {
        return (denominator == 0);
    }

    // evaluate operator
    int eval_op(char op)
    {
        if (op_stack.empty())
        {
            error = true;
            return -1;
        }
        int rhs = op_stack.top();
        op_stack.pop();
        if (op_stack.empty())
        {
            error = true;
            return -1;
        }
        int lhs = op_stack.top();
        op_stack.pop();
        int result = 0;
        switch(op)
        {
            case '+' : {
                            result = lhs + rhs;
                            break;
                       }
            case '-' : {
                            result = lhs - rhs;
                            break;
                       }
            case '*' : {
                            result = lhs * rhs;
                            break;
                       }
            case '/' : {
                            bool div_by_zero_error = div_by_zero(lhs, rhs);
                            if ( div_by_zero_error )
                            {
                                error = true;
                                return -1;
                            }
                            result = lhs / rhs;
                            break;
                       }
            case '%' : {
                            result = lhs % rhs;
                            break;
                       }
        }
        return result;
    }

    // private variables
    stack<char> operand_stack;
    stack<char> operator_stack;
    stack<int>  op_stack;
    string postfix;
    string infix;
    bool error;
};
#endif
