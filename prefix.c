/*Program to convert an expression from infix expression to prefix using stack
@Jubin Joy 
Roll No 35 
01/08/2025 */

#include<stdio.h>
#include<ctype.h>
#include<string.h> // Needed for strlen()

// Global variables for the operator stack and the postfix (intermediate) string
char stack[20], pf[20];
int top = -1, ptop = -1;

// --- Stack Functions ---

void push(char n)
{
    if(top + 1 == 20)
    {
        printf("Error:Stack is full\n");
    }
    else
    {
        stack[++top] = n;
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Error:Stack is empty\n");
    }
    else
    {
        // Pop from operator stack and add to postfix string
        pf[++ptop] = stack[top--]; 
    }
}

// --- Helper Functions for Prefix Conversion ---

// Reverses a string in place
void reverse_string(char* str)
{
    int len = strlen(str);
    int i = 0, j = len - 1;
    char temp;
    
    while(i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Swaps '(' with ')' and vice-versa
void swap_parentheses(char* str)
{
    int i;
    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == '(')
        {
            str[i] = ')';
        }
        else if(str[i] == ')')
        {
            str[i] = '(';
        }
    }
}

// --- Core Conversion Logic ---

// Returns precedence of an operator
int precedence(char op)
{
    switch(op)
    {
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default:  return -1;
    }
}

// Function to convert infix to postfix
// (We will feed it the modified/reversed string)
void infix_to_postfix(char* b)
{
    int i;
    for(i = 0; b[i] != '\0'; i++)
    {
        if(isalnum(b[i])) // If it's an operand
        {
            pf[++ptop] = b[i];
        }
        else if(b[i] == '(') // Push '('
        {
            push(b[i]);
        }
        else if(b[i] == ')') // Pop until '('
        {
            while(top != -1 && stack[top] != '(')
            {
                pop();
            }
            if(top == -1)
            {
                printf("Error: Mismatched parentheses\n");
                return;
            }
            top--; // Pop and discard the '('
        }
        else if (b[i] == '+' || b[i] == '-' || b[i] == '*' || b[i] == '/')
        {
            // Pop operators with higher or equal precedence
            while(top != -1 && stack[top] != '(' && precedence(stack[top]) >= precedence(b[i]))
            {
                pop();
            }
            push(b[i]);
        }
    }
    
    // Pop remaining operators
    while(top != -1)
    {
        if(stack[top] == '(')
        {
            printf("Error: Mismatched parentheses\n");
            top--;
        }
        else
        {
            pop();
        }
    }
    
    // Add null terminator to the postfix string
    pf[++ptop] = '\0';
}

// --- Main Function ---

int main()
{
    char infix[20];
    
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    
    printf("Original Infix: %s\n", infix);
    
    // Step 1: Reverse the infix string
    reverse_string(infix);
    //printf("Reversed: %s\n", infix); // Uncomment to debug
    
    // Step 2: Swap parentheses
    swap_parentheses(infix);
    //printf("Swapped: %s\n", infix); // Uncomment to debug

    // Step 3: Run the postfix algorithm
    infix_to_postfix(infix);
    //printf("Intermediate Postfix: %s\n", pf); // Uncomment to debug
    
    // Step 4: Reverse the result to get the prefix expression
    reverse_string(pf);
    
    printf("The prefix expression:\n");
    puts(pf);
    return 0;
}
