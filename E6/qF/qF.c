#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

enum{
    STACK_LIMIT = 10005,
    STRING_LENGTH_LIMIT = STACK_LIMIT,
};
enum BracketType {
    Round,
    Square,
    Brace,
};
enum BracketOrientation {
    Left,
    Right,
};
struct Bracket {
    enum BracketType type;
    enum BracketOrientation orientation;
};
struct Stack {
    struct Bracket data[STACK_LIMIT];
    size_t top;
};
void stack_push(struct Stack *stack, struct Bracket value);
struct Bracket stack_get(struct Stack stack);
void stack_pop(struct Stack *stack);
bool stack_is_empty(struct Stack stack);

bool is_bracket_match(struct Bracket left, struct Bracket right);
void bracket_push(struct Stack *stack, struct Bracket value);

struct Bracket char_to_Bracket(char ch);

int main(void){
    char string[STRING_LENGTH_LIMIT];
    struct Stack stack = {};
    while (fgets(string, STRING_LENGTH_LIMIT, stdin) != NULL) {
        stack.top = (size_t)(-1);
        for (size_t i = 0; string[i+1] != '\0'; i++) {
            bracket_push(&stack, char_to_Bracket(string[i]));
        }
        if (stack_is_empty(stack)) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
}

void stack_push(struct Stack *stack, struct Bracket value){
    stack->top ++;
    stack->data[stack->top] = value;
}

struct Bracket stack_get(struct Stack stack){
    return stack.data[stack.top];
}

void stack_pop(struct Stack *stack){
    stack->top --;
}
bool stack_is_empty(struct Stack stack){
    return stack.top == (size_t)(-1);
}

void bracket_push(struct Stack *stack, struct Bracket value){
    if (stack_is_empty(*stack)) {
        stack_push(stack, value);
        return;
    }
    if (is_bracket_match(stack_get(*stack), value)) {
        stack_pop(stack);
    }
    else {
        stack_push(stack, value);
    }
}

bool is_bracket_match(struct Bracket left, struct Bracket right){
    if (
        left.type == right.type &&
        left.orientation == Left &&
        right.orientation == Right
    ) {
        return true;
    }
    else {
        return false;
    }
}

struct Bracket char_to_Bracket(char ch){
    struct Bracket bracket;
    switch (ch) {
        case '(':
        case ')':
            bracket.type = Round;
            break;
        case '[':
        case ']':
            bracket.type = Square;
            break;
        case '{':
        case '}':
            bracket.type = Brace;
            break;
    }
    switch (ch) {
        case '(':
        case '[':
        case '{':
            bracket.orientation = Left;
            break;
        case ')':
        case ']':
        case '}':
            bracket.orientation = Right;
            break;
    }
    return bracket;
}
