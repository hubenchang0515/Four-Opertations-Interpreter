#ifndef AST_H
#define AST_H

typedef enum NodeCategory node_category_t;
typedef union AstNode ast_node_t;

enum NodeCategory
{
    // Literal Node
    NC_NUMBER,

    // Unary Operation Node
    NC_POSITIVE,
    NC_NEGATIVE,
    
    // Binary Operation Node
    NC_ADD,
    NC_SUB,
    NC_MUL,
    NC_DIV,

    // Bound Symbol Node
    NC_BRACKET,
};

struct NumberNode
{
    node_category_t category;
    double value;
};

struct UnaryOpNode
{
    node_category_t category;
    ast_node_t* operand;
};

struct BinaryOpNode
{
    node_category_t category;
    ast_node_t* left;
    ast_node_t* right;
};

struct BracketNode
{
    node_category_t category;
    ast_node_t* son;
};

union AstNode
{
    node_category_t category;
    struct NumberNode number;
    struct UnaryOpNode unary;
    struct BinaryOpNode binary;
    struct BracketNode bracket;
};

struct Ast
{
    ast_node_t* root;
};


void ast_node_release(ast_node_t* node);
ast_node_t* ast_make_number_node(double value);
ast_node_t* ast_make_unary_node(node_category_t category, ast_node_t* operand);
ast_node_t* ast_make_binary_node(node_category_t category, ast_node_t* left, ast_node_t* right);
ast_node_t* ast_make_bracket_node(ast_node_t* son);
void ast_node_print(ast_node_t* node);

#endif // AST_H