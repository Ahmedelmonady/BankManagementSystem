#include "utils.h"

void initDataFiles(){
	FILE* file;
	fopen_s(&file, COUNT_FILE, "w+");

	if (ftell(file) == 0) {
		fprintf_s(file, "%d", 0);
	}
	fclose(file);

	fopen_s(&file, DATABASE_FILE, "w+");

	fclose(file);

}

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