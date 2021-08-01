#ifndef MEMEASSEMBLY_COMMANDS_H
#define MEMEASSEMBLY_COMMANDS_H

#include <stdint.h>

#define NUMBER_OF_COMMANDS 29
#define COMMAND_PATTERN_LIST_MAX_STRING_LENGTH 66
#define COMMAND_TRANSLATION_LIST_MAX_STRING_LENGTH 33
#define MAX_PARAMETER_COUNT 2
#define MAX_PARAMETER_LENGTH 4

#define OR_DRAW_25_OPCODE NUMBER_OF_COMMANDS - 1;

struct params {
    char params[MAX_PARAMETER_COUNT][MAX_PARAMETER_LENGTH];
};

struct variablePointer {
    char* param;
};

struct parsedCommand {
    uint8_t opcode;
    union {
        struct params paramsArray;
        struct variablePointer pointer;
    } parameters;
    uint8_t isPointer; //0 = No Pointer, 1 = first parameter, 2 = second parameter
    int lineNum;
};

struct commandsArray {
    struct parsedCommand* arrayPointer;
    int size;
};

struct command {
    char pattern[COMMAND_PATTERN_LIST_MAX_STRING_LENGTH];
    uint8_t usesPointer; //1 = Uses String pointer, 0 = Uses two char arrays
    uint8_t usedParameters;
    /*
     * Allowed types work as follows: Each bit is assigned to a type of variable. If it is set to one, it is allowed.
     * That way, each parameter can allow multiple variable types.
     *  Bit 0: 32 bit and 64 bit registers
     *  Bit 1: 16 bit registers
     *  Bit 2: 8 bit registers
     *  Bit 3: decimal numbers
     *  Bit 4: Characters (including Escape Sequences)
     *  Bit 5: Not used yet
     *  Bit 6: Not used yet
     *  Bit 7: Not used yet
     */
    uint8_t allowedTypesParam1;
    uint8_t allowedTypesParam2;
    char translationPattern[COMMAND_TRANSLATION_LIST_MAX_STRING_LENGTH];
};

#define commentStart "What the hell happened here?"

#define orDraw25Suffix "or draw 25"
#define orDraw25Start "or"
#define orDraw25End "draw 25"

#define pointerSuffix "do you know de wey"

#endif //MEMEASSEMBLY_COMMANDS_H
