#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "utils.h"
#include "strings.h"
#include "lexer.h"

bool lexer_init(lexer_t* lexer, const char* code)
{
    if (lexer == NULL)
        return false;

    lexer->length = strlen(code);
    lexer->code = code;
    lexer->current_index = 0;
    lexer->current_char = lexer->code[lexer->current_index];

    return true;
}

static bool lexer_next(lexer_t* lexer)
{
    if (lexer == NULL)
        return false;

    lexer->current_index += 1;
    if (lexer->current_index >= lexer->length)
        return false;

    lexer->current_char = lexer->code[lexer->current_index];
    return true;
}

static double lexer_parse_number(lexer_t* lexer)
{
    string_t token_string;
    string_init(&token_string, NULL);

    while (lexer->current_index < lexer->length && is_char_in(lexer->current_char, "1234567890."))
    {
        string_append(&token_string, lexer->current_char);
        lexer_next(lexer);
    }

    double num = atof(token_string.data);
    string_release(&token_string);
    return num;
}

bool lexer_parse(lexer_t* lexer, vector_t* tokens)
{
    token_t token;
    while(lexer->current_index < lexer->length)
    {
        
        if (is_char_in(lexer->current_char, "1234567890"))
        {
            double n = lexer_parse_number(lexer);
            token_make_number(&token, n);
        }
        else if (lexer->current_char == '+')
        {
            token_make_add(&token);
            lexer_next(lexer);
        }
        else if (lexer->current_char == '-')
        {
            token_make_sub(&token);
            lexer_next(lexer);
        }
        else if (lexer->current_char == '*')
        {
            token_make_mul(&token);
            lexer_next(lexer);
        }
        else if (lexer->current_char == '/')
        {
            token_make_div(&token);
            lexer_next(lexer);
        }
        else if (lexer->current_char == '(')
        {
            token_make_left_bracket(&token);
            lexer_next(lexer);
        }
        else if (lexer->current_char == ')')
        {
            token_make_right_bracket(&token);
            lexer_next(lexer);
        }
        else
        {
            fprintf(stderr, "syntax error: symbol '%c' is illegal\n",lexer->current_char);
        }

        vector_append(tokens, &token);
    }

    return true;
}

