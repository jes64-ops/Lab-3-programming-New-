#include <stdio.h>// standard libary from input and output functions
#include <stdlib.h>// for exit function

#define max_songs 6 //max number of songs is 6 stored in the array

struct songs_catalogue{  //defined a structure to store song information
    char artist[50]; // array enables to store artists up to 50 characters 
    char title[50];// enables array to store title of upto 50 characters 
    float price; // float to store in array the prices
    int year;// integer to store years in array 
}song[max_songs]; //array of songs structres with max number of songs

void read_in_data() {// function to read songs from the standard keyboard input 
    int i ,n =5;  //i = the loop counter
    getchar();
    for (i = 0; i <n ; i++) {// a loop is enabled to read each data from keyboad for each song 
        
        printf("Enter artist name:\n");//display asks for artist name
        fgets(song[i].artist, 50, stdin);

        printf("Enter song title:\n");// display asks for song title 
        fgets(song[i].title, 50, stdin);//reads input from standard keyboard and stores into title in each array

        printf("Enter price:\n");//
        scanf("%f", &song[i].price);

        printf("Enter year:\n");
        scanf("%d", &song[i].year);
        getchar();
    }
    main();
}

void save_data(){
    int n = 5, i;
    FILE *myPtr;
    myPtr = fopen("Song_Catalogue.txt", "w");

    if (myPtr == NULL) {
        printf("The file could not be opened.\n");
        return;
    } else {
        printf("The file is now opened.\n");

        for (i = 0; i < n; i++) {
            fprintf(myPtr, "%s %s %f %d", song[i].artist, song[i].title, song[i].price, song[i].year);
        }
        fclose(myPtr);
        printf("Songs have been saved to 'Song Catalogue.txt.\n");
    }
    main();
}

void print_out_catologue_to_screen(){
    FILE *myPtr = fopen("Song_Catalogue.txt", "r");
    if (myPtr == NULL) {
        printf("Error: cannot open file for reading.\n");
        return;
    }
    int i, n= 5;
    for(i=0;i <n; i++){
        fgets(song[i].artist, 50, myPtr);
        fgets(song[i].title,50,myPtr);
        fscanf(myPtr,"%f",&song[i].price);
        fscanf(myPtr,"%d",&song[i].year);
        getchar();
    }
    fclose(myPtr);
    sorting();
    for (int j = 0; j < n; j++) {
        printf("Artist:%s", song[j].artist);
        printf("Title:%s", song[j].title);
        printf("Price:%.2f\n", song[j].price);
        printf("Year:%d\n", song[j].year);
    }
}


void sorting() {// using bubble sorting
    int n = 5, i; // number of songs
    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i; j++) {
            if (song[j].year < song[j + 1].year) {//newsest to old check
                // Swap entire struct
                struct songs_catalogue temp = song[j];
                song[j] = song[j + 1];
                song[j + 1] = temp;
            }
        }
    }
}



int main(){
    int choice;
    printf("The following options are available:\n");
    printf("Read in data[1]\n");
    printf("Print Out the catalogue[2]\n");
    printf("Save data to file[3]\n");
    printf("Exit Program[4]\n");
    printf("Enter choice Now:");
    scanf("%d",&choice);

    switch(choice){
        case 1:
        read_in_data();
        break;
        case 2:
        print_out_catologue_to_screen();
        break; 
        case 3:
        save_data();
        break;
        case 4:
        exit(0);
        printf("exiting program\n");
        break;
        default:
        printf("INVALID CHOICE TRY AGAIN");
    }
}