#include <stdio.h>
#include <stdlib.h>

#include "ast.h"

void ast_node_release(ast_node_t* node)
{
    if (node == NULL)
        return;

    switch (node->category)
    {
    case NC_NUMBER:
        free(node);
        break;
    
    case NC_POSITIVE:
    case NC_NEGATIVE:
        ast_node_release(node->unary.operand);
        free(node);
        break;

    case NC_ADD:
    case NC_SUB:
    case NC_MUL:
    case NC_DIV:
        ast_node_release(node->binary.left);
        ast_node_release(node->binary.right);
        free(node);
        break;

    case NC_BRACKET:
        ast_node_release(node->bracket.son);
        free(node);
        break;

    default:
        fprintf(stderr, "unknown node: %d\n", node->category);
        break;
    }
}

ast_node_t* ast_make_number_node(double value)
{
    ast_node_t* node = malloc(sizeof(ast_node_t));
    if (node == NULL)
        return NULL;

    node->category = NC_NUMBER;
    node->number.value = value;
    return node;
}

ast_node_t* ast_make_unary_node(node_category_t category, ast_node_t* operand)
{
    ast_node_t* node = malloc(sizeof(ast_node_t));
    if (node == NULL)
        return NULL;

    node->category = category;
    node->unary.operand = operand;
    return node;
}

ast_node_t* ast_make_binary_node(node_category_t category, ast_node_t* left, ast_node_t* right)
{
    ast_node_t* node = malloc(sizeof(ast_node_t));
    if (node == NULL)
        return NULL;

    node->category = category;
    node->binary.left = left;
    node->binary.right = right;
    return node;
}

ast_node_t* ast_make_bracket_node(ast_node_t* son)
{
    ast_node_t* node = malloc(sizeof(ast_node_t));
    if (node == NULL)
        return NULL;

    node->category = NC_BRACKET;
    node->bracket.son = son;
    return node;
}

void ast_node_print(ast_node_t* node)
{
    switch(node->category)
    {
    case NC_NUMBER:
        printf("%f", node->number.value);
        break;

    case NC_POSITIVE:
        printf("+");
        ast_node_print(node->unary.operand);
        break;

    case NC_NEGATIVE:
        printf("-");
        ast_node_print(node->unary.operand);
        break;

    case NC_ADD:
        ast_node_print(node->binary.left);
        printf("+");
        ast_node_print(node->binary.right);
        break;

    case NC_SUB:
        ast_node_print(node->binary.left);
        printf("-");
        ast_node_print(node->binary.right);
        break;

    case NC_MUL:
        ast_node_print(node->binary.left);
        printf("*");
        ast_node_print(node->binary.right);
        break;

    case NC_DIV:
        ast_node_print(node->binary.left);
        printf("/");
        ast_node_print(node->binary.right);
        break;

    case NC_BRACKET:
        printf("(");
        ast_node_print(node->bracket.son);
        printf(")");
        break;

    default:
        fprintf(stderr, "unknown node: %d\n", node->category);
        break;
    }
}