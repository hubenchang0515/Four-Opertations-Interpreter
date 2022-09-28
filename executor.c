#include <stdio.h>

#include "executor.h"

double execute(const ast_node_t* node)
{
    switch(node->category)
    {
    case NC_NUMBER:
        return node->number.value;

    case NC_POSITIVE:
        return execute(node->unary.operand);

    case NC_NEGATIVE:
        return -1 * execute(node->unary.operand);

    case NC_ADD:
        return execute(node->binary.left) + execute(node->binary.right);

    case NC_SUB:
        return execute(node->binary.left) - execute(node->binary.right);

    case NC_MUL:
        return execute(node->binary.left) * execute(node->binary.right);

    case NC_DIV:
        return execute(node->binary.left) / execute(node->binary.right);

    case NC_BRACKET:
        return execute(node->bracket.son);

    default:
        fprintf(stderr, "unknown node: %d\n", node->category);
        return 0.0;
    }
}