#include "utils.h"


FILE* loadFile(char* filename, char* type) {
	FILE* file;
	fopen_s(&file, filename, type);
	if (file == NULL)
		return NULL;
	return file;
}

int getListCount() {
	FILE* file = loadFile(COUNT_FILE, "r+");
	int count;
	if (file != NULL) {
		fscanf_s(file, "%d", &count, MAX_LEN);

		fclose(file);

		return count;
	}
	else return -1;
}

void updateUserCount(int offset) {
	int count = getListCount();
	count += offset;
	FILE* file = loadFile(COUNT_FILE, "r+");
	if (file != NULL) {
		fprintf_s(file, "%d", count);
		fclose(file);
	}
}

void addNewAccount(BankAccount bankAccount) {
	FILE* file = loadFile(DATABASE_FILE, "a+");
	if (file != NULL) {
		fprintf_s(file, JSON_OUT, bankAccount.username, bankAccount.password, bankAccount.balance);
		updateUserCount(ADD_USER);
		fflush(file);
		fclose(file);
	}
	else {
		printf("Failed to add user!");
	}
}

void getAllAccounts() {
	int total_count = getListCount();
	FILE* file = loadFile(DATABASE_FILE, "r");
	if (file != NULL) {
		BankAccount* accounts;
		accounts = calloc(total_count, sizeof(BankAccount));
		for (int i = 0; i < total_count; i++) {
			BankAccount reader;
			fscanf_s(file, JSON_IN, reader.username, MAX_LEN, reader.password, MAX_LEN, &reader.balance);
			*(accounts + i) = reader;

			printf(JSON_OUT, (accounts + i)->username, (accounts + i)->password, (accounts+i)->balance);
		}

		free(accounts);
	}
}