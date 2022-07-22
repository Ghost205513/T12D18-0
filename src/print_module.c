#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#include "print_module.h"

char print_char(char ch) {
    return putchar(ch);
}

void print_log(char(*print) (char), char* message) {
    time_t temp = time(NULL);
    struct tm *local_time = localtime(&temp);
    int mes_len = strlen(message);

    for (int i = 0; i < (int) strlen(Log_prefix); i++) {
        print(Log_prefix[i]);
    }

    print(' ');
    print(48 + local_time->tm_hour / 10);
    print(48 + local_time->tm_hour % 10);
    print(':');
    print(48 + local_time->tm_min / 10);
    print(48 + local_time->tm_min % 10);
    print(':');
    print(48 + local_time->tm_sec / 10);
    print(48 + local_time->tm_sec % 10);
    print(' ');

    for (int i = 0; i < mes_len; i++)
        print(message[i]);

    free(local_time);
}
