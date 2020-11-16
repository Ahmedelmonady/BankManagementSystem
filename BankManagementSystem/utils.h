#ifndef __utils__
#define __utils__

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "stdlib.h"

#define DATABASE_FILE "Data-BankDb.bin"
#define COUNT_FILE "Data-Count.bin"
#define ADD_USER 1
#define REMOVE_USER -1
#define ADD_BALANCE 1
#define WITHDRAW_BALANCE -1
#define MAX_LEN 25
#define JSON_OUT "{\"username\": \"%s\", \"password\": \"%s\", \"balance\": \"%f\"}\n"
#define JSON_IN "{\"username\": \"%[^\"]\", \"password\": \"%[^\"]\", \"balance\": \"%f\"}\n"

typedef struct {
	char username[MAX_LEN];
	char password[MAX_LEN];
	float balance;
}BankAccount;

static BankAccount Accounts[10000];

FILE* loadFile(char* filename, char* type);
int getListCount();
void updateUserCount(int offset);
void addNewAccount(BankAccount bankAccount);
void getUserAccount(char* username, char* password, BankAccount *user);
int checkUsernameExists(char* username);
void modifyAccountBalance(char* username, float amount, int operation);
void loadAllAccounts();
void writeAllAccounts();
#endif