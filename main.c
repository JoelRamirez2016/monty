#include "monty.h"
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char buff[1024], line[255];

	fp = fopen("bytecodes.m", "r");

	while (fgets(line, 255, (FILE*)fp))
	{
		exe(line);
		strcat(buff, line);		
	}

	fclose(fp);
	return (0);
}

void exe(char *l)
{
	instruction_t instructions[3] = {
		{"push", push}, 
		{"pall", pall}
		{0, 0}
	};


}
