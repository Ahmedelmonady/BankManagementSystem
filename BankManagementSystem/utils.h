#ifndef __utils__
#define __utils__

#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "stdlib.h"

#define DATABASE "Data-BankDb.bin"
#define COUNT "Data-Count.bin"
#define ADD_USER 1
#define REMOVE_USER -1
#define MAX_LEN 25
#define JSON_OUT "{\"username\": \"%s\", \"password\": \"%s\", \"balance\": \"%f\"}\n"
#define JSON_IN "{\"username\": \"%[^\"]\", \"password\": \"%[^\"]\", \"balance\": \"%f\"}"

typedef struct {
	char username[MAX_LEN];
	char password[MAX_LEN];
	float balance;
}BankAccount;

void initDataFiles();

#endif