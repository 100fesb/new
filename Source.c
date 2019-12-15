#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BUFFER_LENGTH 1024
#define MAX_STUDENATA 9999
#define MAX_PREDMETA 999
#define MAX_PROFESORA 999

#define ERROR -1

typedef struct StudentiPredmetiOcjene StudentiPO; // sad mos svugdi koristit StudentiPO umjesto cilog imena





typedef struct Studenti *PozicijaS;
typedef struct Predmeti *PozicijaP;

// bilo bi dobro da su studenti cirkularno dvostruko vezani - radi menija (zelite drugog studenta za ispis/upis....)
struct Studenti{
	int ID;
	PozicijaP NextP;
	PozicijaS NextS;
};

// Ocjena je 0 ako student slusa predmet, -1 ako ne slusa predmet
struct Predmeti{
	int ID;
	int Ocjena;
	PozicijaP NextP;
};


int UcitajStudenta(PozicijaS);


int main()
{
	struct Studenti HeadS;
	HeadS.NextP = NULL;
	HeadS.NextS = NULL;

	UcitajStudenta(&HeadS);


	system("pause");
	return 0;
}


int UcitajStudenta(PozicijaS H)
{
	char *fileName = NULL;
	FILE *fp = NULL;
	int a = 0, b = 0;
	char aa[10], bb[10];

	fileName = (char*)malloc(sizeof(char)* BUFFER_LENGTH);
	if (fileName == NULL) return ERROR;
	memset(fileName, '\0', BUFFER_LENGTH);

	printf("\r\n\tUnesite ime dadoteke za citanje : ");
	scanf(" %s", fileName);

	if (strchr(fileName, '.') == NULL)
		strcat(fileName, ".txt");

	fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		printf("\r\n\tGRESKA!\r\n\t%s datoteka nije otvorena.", fileName);
		return ERROR;
	}

	while (!feof(fp))
	{
		printf("your line is %d long", strlen(fp));
		fscanf(fp, " %d %s %s %d", &a, aa, bb, &b);
		//fp[len - 1] == '\n'
		//fscanf(fp, " %d %s %s %d %d %d %d %d %d", &q->koeficijent, &q->eksponent);

		

	}

	fclose(fp);
	
	return 0;
}