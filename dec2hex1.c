//https://github.com/aarifboy/testgithub/blob/master/File_Handling_c_with_command_line_arguments.txt
//https://www.opentechguides.com/how-to/article/c/45/c-read-file.html

#include <stdio.h>
#include <string.h>

typedef struct
{
	int Y_char_position;
	int X_char_position;
	int object_type;
} collision;



int main(int argc, char **argv) 
{
	FILE *inputFile;
	FILE *outFile;
	char *filename;
	char ch;
	int i;
	int records = 0;
	int read = 0;
	
	
	collision collisionTable[512];
	
	char appendString[] = ".hex";
	
	/////////////////////////////////////////////////

	printf("useage: dec2hex inputFile.txt\n");
	// Check if a filename has been specified in the command
	if (argc < 2)
	{
		printf("Missing Filename\n");
		return(1);
	}
	else
	{
		filename = argv[1];
        printf("Filename : %s\n", filename);
	}

	// Open file in read-only mode
	inputFile = fopen(filename,"r");
	
	if (inputFile == NULL)
	{
		printf("Hey! Failed to open the file\n");
	}
	
	strcat (filename, appendString);
	printf ("%s\n",filename);
	
	printf("File contents:\n");

	while ((ch=getc(inputFile))!=EOF) //reading the character from file until fp equals to EOF{
	{
		read = fscanf(inputFile,"%d,%d,%d\n",
		&collisionTable[records].Y_char_position,
		&collisionTable[records].X_char_position,
		&collisionTable[records].object_type);

		records ++;
	}
	printf ("records = %d\n",records);


//PRINT to SCREEN in decimal
	for (i = 0; i < records; i++)
	{
		printf ("1 = %d   ",collisionTable[i].Y_char_position);
		printf ("2 = %d   ",collisionTable[i].X_char_position);
		printf ("3 = %d   ",collisionTable[i].object_type);
		printf ("record = %d\n",i);
		printf ("\n");
		//01,02,03,
		//10,11,12,
		//11,22,33,
		//44,55,66
	}
//PRINT to SCREEN in HEX
	for (i = 0; i < records; i++)
	{
		printf ("1 = %02x  ",collisionTable[i].Y_char_position);
		printf ("2 = %02x  ",collisionTable[i].X_char_position);
		printf ("3 = %02x  ",collisionTable[i].object_type);
		printf ("record = %d\n",i);
		printf ("\n");
		//01,02,03,
		//10,11,12,
		//11,22,33,
		//44,55,66
	}
	
	fclose(inputFile);
	
	outFile = fopen(filename,"w");

	for (i = 0; i < records; i++)
	{

		fprintf(outFile,"%c", collisionTable[i].Y_char_position);
		fprintf(outFile,"%c", collisionTable[i].X_char_position);
		fprintf(outFile,"%c", collisionTable[i].object_type);


		//01,02,03,
		//10,11,12,
		//11,22,33,
		//44,55,66
	}
	
	//fwrite( &collision, sizeof collision, 1, filename );
	
	fclose(outFile);


return(0);
}





/*

		
//fprintf(outFile,"%02x", i, collisionTable[i].Y_char_position);
//fprintf(outFile,"%02x", i, collisionTable[i].X_char_position);
//fprintf(outFile,"%02x", i, collisionTable[i].object_type);

//fprintf(outFile,"%d", i, collisionTable[i].Y_char_position);
//fprintf(outFile,"%d", i, collisionTable[i].X_char_position);
//fprintf(outFile,"%d", i, collisionTable[i].object_type);

//fprintf(outFile,"%d", i, &collisionTable[i].Y_char_position);
//fprintf(outFile,"%d", i, &collisionTable[i].X_char_position);
//fprintf(outFile,"%d", i, &collisionTable[i].object_type);


//fprintf(outFile,"%d", &collisionTable[i].Y_char_position, &collisionTable[i].Y_char_position);
//fprintf(outFile,"%d", &collisionTable[i].X_char_position, &collisionTable[i].X_char_position);
//fprintf(outFile,"%d", &collisionTable[i].object_type, &collisionTable[i].object_type);

//fprintf(outFile,"%d", collisionTable[i].Y_char_position);
//fprintf(outFile,"%d", collisionTable[i].X_char_position);
//fprintf(outFile,"%d", collisionTable[i].object_type);

//fprintf(outFile,"%02x", collisionTable[i].Y_char_position);
//fprintf(outFile,"%02x", collisionTable[i].X_char_position);
//fprintf(outFile,"%02x", collisionTable[i].object_type);



*/