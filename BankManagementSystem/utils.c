#include "utils.h"

void initDataFiles(){
	FILE* file;
	fopen_s(&file, COUNT, "r+");
	if (file == NULL) {
		fopen_s(&file, COUNT, "wb+");

		fprintf_s(file, "%d", 0);

		fflush(file);
		fclose(file);

		fopen_s(&file, DATABASE, "w+");
		fflush(file);
		fclose(file);
	}
}