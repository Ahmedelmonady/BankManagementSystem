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

void getUserAccount(char* username, char* password, BankAccount *user) {
	
	int total_count = getListCount();
	FILE* file = loadFile(DATABASE_FILE, "r");
	if (file != NULL) {
		for (int i = 0; i < total_count; i++) {
			BankAccount hit;
			fscanf_s(file, JSON_IN, hit.username, MAX_LEN, hit.password, MAX_LEN, &hit.balance);
			if (strcmp(hit.username, username) == 0 && strcmp(hit.password, password) == 0) {
				//printf(JSON_OUT, hit.username, hit.password, hit.balance);
				*user = hit;
			}
		}
	}
}

int checkUsernameExists(char* username) {
	int total_count = getListCount();
	FILE* file = loadFile(DATABASE_FILE, "r");
	if (file != NULL) {
		for (int i = 0; i < total_count; i++) {
			BankAccount hit;
			fscanf_s(file, JSON_IN, hit.username, MAX_LEN, hit.password, MAX_LEN, &hit.balance);
			if (strcmp(hit.username, username) == 0 ) {
				return 1; //exists
			}
		}
		return 0; //couldn't retrieve data
	}
	return 0;//doesnot exist
}

void modifyAccountBalance(char* username, float amount, int operation) {
	int total_count = getListCount();
	FILE* file = loadFile(DATABASE_FILE, "r");
	if (file != NULL) {
		loadAllAccounts();
		for (int i = 0; i < total_count; i++) {
			if (strcmp(Accounts[i].username, username) == 0) {
				Accounts[i].balance = Accounts[i].balance + (operation * amount);
			}
		}
	}
	fclose(file);

	writeAllAccounts();
}

void loadAllAccounts() {
	int total_count = getListCount();
	FILE* file = loadFile(DATABASE_FILE, "r");
	if (file != NULL) {
		for (int i = 0; i < total_count; i++) {
			BankAccount hit;
			fscanf_s(file, JSON_IN, hit.username, MAX_LEN, hit.password, MAX_LEN, &hit.balance);
			Accounts[i] = hit;
		}
	}
	fclose(file);
}

void writeAllAccounts() {
	FILE* file = loadFile(DATABASE_FILE, "w");
	for (int i = 0; i < getListCount(); i++) {
		if (file != NULL) {
			fprintf_s(file, JSON_OUT, Accounts[i].username, Accounts[i].password, Accounts[i].balance);
		}
	}
}