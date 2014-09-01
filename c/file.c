#include "file.h"




void gparticles(const char* file, struct particles* plist){
	FILE* fp = fopen(file, "r");
	if (fp == NULL) {
		printf("Could not open %s\n", file);
	}
	else{
		printf("Loading particles\n");
		int ln = 0; //line number
		char ptc[50];
		while (fgets(ptc, 50, fp) != NULL){//while there is something to read
			plist[ln].mass = atoi(strtok(ptc, " ,.-"));
			plist[ln].xpos = atoi(strtok(NULL, " ,.-"));
			plist[ln].ypos = atoi(strtok(NULL, " ,.-"));
			plist[ln].xvol = atoi(strtok(NULL, " ,.-"));
			plist[ln].yvol = atoi(strtok(NULL, " ,.-"));
			plist[ln].xacc = 0;
			plist[ln].yacc = 0;
			ln++;
		}
		fclose(fp);//close file
		printf("Finished loading particles\n");
	}
};


int gline(const char* file){
	FILE* fp = fopen(file, "r");
	if (fp == NULL) {
		printf("Could not open %s\n", file);
	}
	else{
		int ln = 0; //line number
		char ptc[10];
		while (fgets(ptc, 10, fp) != NULL){//while there is something to read
			ln++;
		}
		return ln;
		fclose(fp);//close file
	}
}
