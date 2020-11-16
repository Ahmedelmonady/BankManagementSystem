#ifndef __utils__
#define __utils__

#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "stdlib.h"

#define DATABASE "BankDb.txt"
#define COUNT "Count.txt"
#define ADD_USER 1
#define REMOVE_USER -1
#define MAX_LEN 25
#define JSON_OUT ""
#define JSON_IN ""

typedef struct {
	char username[MAX_LEN];
	char password[MAX_LEN];
	float balance;
	char Name[MAX_LEN];
}BankAccount;

#endif