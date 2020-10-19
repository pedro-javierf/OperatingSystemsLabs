
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Team
{
    char name[64]; //Stack allocated variable
    char city[64]; //Stack allocated variable
    int points;    //Stack allocated variable
};

void main(int argc, char *argv[])
{

        char usage[] = "Usage: program <teamName> <teamCity> <teamPoints>";

        if(argc < 4)
        {
                fprintf(stderr, "%s", usage);
                exit(EXIT_FAILURE);
        }

        struct Team team;

        strncpy(team.name,argv[1],64);
        strncpy(team.city,argv[2],64);
        team.points = atoi(argv[3]);


        FILE * pFile;


        //The filename is <teamName>.dat
        char fileName[68];
        
        strncpy(fileName,argv[1],64);
        strcat(fileName,".dat");


        pFile = fopen(fileName,"wb");

        if (pFile!=NULL)
        {
                //Binary write the struct to the file
                fwrite(&team, sizeof(struct Team), 1, pFile);

                //Close the file
                fclose (pFile);
                
                //Inform the user
                printf("Program completed successfully\n");
        }
        else
        {
                printf("Couldn't open the file\n");
        }

}
