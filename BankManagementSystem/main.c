#include "utils.h"

void addusers() {
	BankAccount a = {
		.username = "Ahmed",
		.password = "123",
		.balance = 2.50
	};
	BankAccount b = {
		.username = "Mohamed",
		.password = "321",
		.balance = 5.20
	};

	addNewAccount(a);
	addNewAccount(b);
}

int main() {
	printf("Hello, Press 1 for Logging in or 2 for creating a new account!\n");
	int op;
	int op2;
	float amount;
	char username[MAX_LEN]; char password[MAX_LEN];
	BankAccount acc;
	scanf("%d", &op);
	switch (op) {
	case 1:
		printf("Enter your Username: ");
		scanf("%s", username);
		printf("Enter Your Password: ");
		scanf("%s", password);

		getUserAccount(username, password, &acc);
		printf("1. to add balance, 2. to withdraw balance, 3. to show balance: ");
		scanf("%d", &op2);
		printf("\n");
		switch (op2) {
		case 1:
			printf("Enter amount to add: ");
			scanf("%f", &amount);
			printf("\n");
			modifyAccountBalance(acc.username, amount, ADD_BALANCE);
				break;
		case 2:
			printf("Enter amount to withdraw: ");
			scanf("%f", &amount);
			printf("\n");
			modifyAccountBalance(acc.username, amount, WITHDRAW_BALANCE);
			break;
		case 3:
			printf("Username: %s\n", acc.username);
			printf("Balance: EGP%f\n", acc.balance);
			break;
		}
		break;
	case 2:
		printf("Enter Your Username: ");
		scanf("%s", acc.username);
		printf("\n");
		while (checkUsernameExists(acc.username)) {
			printf("Username exists, enter another one!: ");
			scanf("%s", acc.username);
			printf("\n");
		}
		printf("Enter Your Password: ");
		scanf("%s", acc.password);
		printf("\n");
		printf("Enter Your Balance: ");
		scanf("%f", &(acc.balance));
		printf("\n");
		addNewAccount(acc);
		printf("Done!");
		break;
	}
	printf("Bye-Bye!\n");
	return 0;
}