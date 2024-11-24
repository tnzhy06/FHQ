#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 20000

double num_stack[MAX];
char op_stack[MAX];
int num_top = -1;
int op_top = -1;

double round_nearest_even(double value, int places)
{
    double scale = pow(10, places);
    double scaled_value = value * scale;
    double rounded_value = floor(scaled_value);

    double fraction = scaled_value - rounded_value;

    if (fraction > 0.5)
    {
        rounded_value += 1.0;
    }
    else if (fraction == 0.5)
    {
        if (fmod(rounded_value, 2.0) != 0)
        {
            rounded_value += 1.0;
        }
    }

    return rounded_value / scale;
}

// double round_bankers(double value)
// {
//     double factor = pow(10.0, 6);
//     double temp = value * factor;
//     long integer_part = (long)temp;
//     double fractional_part = temp - integer_part;

//     if (((long)(fractional_part * 10)) % 10 == 5)
//     {
//         if (fabs(fractional_part - 0) > 1e-6)
//         {
//             return ((integer_part + 1) / factor);
//         }
//         else if ((integer_part % 2) == 0)
//         {
//             return (integer_part / factor);
//         }
//         else
//         {
//             return ((integer_part + 1) / factor);
//         }
//     }
//     else if (fractional_part < 0.5)
//     {
//         return (integer_part / factor);
//     }
//     else
//     {
//         return ((integer_part + 1) / factor);
//     }
// }

int is_num_empty()
{
    return num_top == -1;
}

int is_op_empty()
{
    return op_top == -1;
}

void push_num(double val)
{
    num_stack[++num_top] = val;
}

double pop_num()
{
    if (is_num_empty())
    {
        printf("num empty error\n");
        exit(1);
    }
    return num_stack[num_top--];
}

void push_op(char op)
{
    op_stack[++op_top] = op;
}

char pop_op()
{
    if (is_op_empty())
    {
        printf("op empty error\n");
        exit(1);
    }
    return op_stack[op_top--];
}

int priority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == 'x' || op == '/')
        return 2;
    return 0;
}

void process_op(char op)
{
    while (!is_op_empty() && priority(op_stack[op_top]) >= priority(op))
    {
        char top_op = pop_op();
        double v2 = pop_num();
        double v1 = pop_num();

        switch (top_op)
        {
        case '+':
            push_num(v1 + v2);
            break;
        case '-':
            push_num(v1 - v2);
            break;
        case 'x':
            push_num(v1 * v2);
            break;
        case '/':
            push_num(v1 / v2);
            break;
        }
    }
    push_op(op);
}
int flag;
double calculate(char *infix)
{
    int i = 0;
    push_num(0);

    while (infix[i] != '=')
    {
        if (infix[i] == ' ')
        {
            i++;
            continue;
        }
        // if (infix[0] == '-' && infix[1] == '(')
        // {
        //     flag = 1;
        // }
        if (isdigit(infix[i]) || (infix[i] == '-' && ((i == 0 && infix[1] != '(') || infix[i - 1] == '(' || infix[i - 1] == 'x' || infix[i - 1] == '/' || infix[i - 1] == '+' || infix[i - 1] == '-')))
        {
            char buffer[MAX];
            int j = 0;
            if (infix[i] == '-')
            {
                buffer[j++] = infix[i++];
            }
            while (isdigit(infix[i]) || infix[i] == '.')
            {
                buffer[j++] = infix[i++];
            }
            buffer[j] = '\0';
            // printf("%lf\n", atof(buffer));
            push_num(atof(buffer));
        }

        else if (infix[i] == '(')
        {
            push_op('(');
            i++;
        }
        else if (infix[i] == ')')
        {
            while (!is_op_empty() && op_stack[op_top] != '(')
            {
                char top_op = pop_op();
                double v2 = pop_num();
                double v1 = pop_num();

                switch (top_op)
                {
                case '+':
                    push_num(v1 + v2);
                    break;
                case '-':
                    push_num(v1 - v2);
                    break;
                case 'x':
                    push_num(v1 * v2);
                    break;
                case '/':
                    push_num(v1 / v2);
                    break;
                }
            }
            pop_op();

            // if(flag)
            // {
            //     num_stack[num_top] = -num_stack[num_top];
            //     flag = 0;
            // }
            i++;
        }
        else
        {
            process_op(infix[i]);
            i++;
        }
    }

    while (!is_op_empty())
    {
        char top_op = pop_op();
        double v2 = pop_num();
        double v1 = pop_num();

        switch (top_op)
        {
        case '+':
            push_num(v1 + v2);
            break;
        case '-':
            push_num(v1 - v2);
            break;
        case 'x':
            push_num(v1 * v2);
            break;
        case '/':
            push_num(v1 / v2);
            break;
        }
    }

    return pop_num();
}

int main()
{
    char infix[MAX];
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        fgets(infix, MAX, stdin);
        infix[strcspn(infix, "\n")] = 0;
        double result = calculate(infix);

        double rounded_number = round_nearest_even(result, 6);

        if (fabs(rounded_number == (long)rounded_number))
        {
            printf("%ld\n", (long)rounded_number);
        }
        else
        {
            printf("%.6lf\n", rounded_number);
        }
    }

    return 0;
}