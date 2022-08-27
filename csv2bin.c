#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) 
{
	FILE *inputFile;
	FILE *outFile;
	char *filename;
	int records = 0;
	
	
	
	//char line[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	char line[15];
	
	char *sp;

	char appendString[] = ".hex";
	///////////////////////////////////////////

	printf("useage: dec2hex inputFile.txt\n");
	// Check if a filename has been specified in the command
	if (argc < 2)
	{
		printf("Missing Filename\n");
		return 1;
	}
	
	filename = argv[1];

	// Open file in read-only mode
	inputFile = fopen(filename,"r");
	
	if (inputFile == NULL)
	{
		printf("Hey! Failed to open the file\n");
		return 1;
	}
	
	strcat (filename, appendString);
	//printf ("write out filename : %s\n",filename);
	//outFile = fopen(filename,"w");
	outFile = fopen(filename,"wb");

	while (fgets(line, 15, inputFile) != NULL)
	{
		sp = strtok(line, ",");		
		char Y_pos = atoi(sp);
		
		sp = strtok(NULL, ",");
		
		char X_pos = atoi(sp);
		
		sp = strtok(NULL, ",");
		char OType = atoi(sp);

		//print to file
		fprintf(outFile,"%c", Y_pos);
		fprintf(outFile,"%c", X_pos);
		fprintf(outFile,"%c", OType);
		
		records ++;
	}
	//fprintf(outFile,'\0');
	
	printf ("records = %d\n",records);
	fclose(inputFile);

	fclose(outFile);

return 0;
}
