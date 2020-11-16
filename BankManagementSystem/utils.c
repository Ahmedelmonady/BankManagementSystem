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

		printf("%d", count);

		fclose(file);
	}
	else printf("NULL");
}