#ifndef TOKEN_H
#define TOKEN_H

#include <stdbool.h>

typedef enum TokenCategory token_category_t;
typedef union Token token_t;

enum TokenCategory
{
    // Key Word Token

    // Identifier Token

    // Literal Token
    TC_NUMBER,
    
    // Operation Token
    TC_ADD,
    TC_SUB,
    TC_MUL,
    TC_DIV,

    // Bound Symbol Token
    TC_LEFT_BRACKET,
    TC_RIGHT_BRACKET,
};

struct NumberToken
{
    token_category_t category;
    double value;
};

struct OperationToken
{
    token_category_t category;
};

union Token
{
    token_category_t category;
    struct NumberToken number;
    struct OperationToken add;
    struct OperationToken sub;
    struct OperationToken mul;
    struct OperationToken div;
};

void token_print(token_t* token);

bool token_make_number(token_t* token, double value);
bool token_make_add(token_t* token);
bool token_make_sub(token_t* token);
bool token_make_mul(token_t* token);
bool token_make_div(token_t* token);
bool token_make_left_bracket(token_t* token);
bool token_make_right_bracket(token_t* token);

#endif // TOKEN_H