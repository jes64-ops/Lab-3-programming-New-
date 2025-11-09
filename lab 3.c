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
    getchar();// reads a single character from standard input and remove leftover newline character so fgets can work properly
    for (i = 0; i <n ; i++) {// a loop is enabled to read each data from keyboad for each song 
        
        printf("Enter artist name:\n");//prints to display asks for artist name
        fgets(song[i].artist, 50, stdin);//reads input from standard keyboard and stores into artsist in each array up to 50 characters only string

        printf("Enter song title:\n");// display asks for song title 
        fgets(song[i].title, 50, stdin);//reads input from standard keyboard and stores into title in each array up to 50 characters only string

        printf("Enter price:\n");//prints to display asking for price 
        scanf("%f", &song[i].price);//using scanf to read float from input keyboard stores in float song array within price

        printf("Enter year:\n");//prints to display asking for year
        scanf("%d", &song[i].year);//using scanf to read integer from input keyboard which stoers in interger song array within year  
        getchar();// reads a single character from standard input and remove leftover newline character so fgets can work properly
    }
    main();// returns to main menu after reading data
}

void save_data(){// function to save data to a text file
    int n = 5, i;// n = number of songs, i = loop counter
    FILE *myPtr;// file pointer declaration
    myPtr = fopen("Song_Catalogue.txt", "w");// opens file in write mode

    if (myPtr == NULL) {// checks if file opened completely
        printf("The file could not be opened.\n");// error message if file not opened
        return;// exits the function
    } else {
        printf("The file is now opened.\n");// display message if file opened successfully

        for (i = 0; i < n; i++) {// loop to write each song's data to the file
            fprintf(myPtr, "%s %s %f %d", song[i].artist, song[i].title, song[i].price, song[i].year);// using fprintf is used to print data to file
        }
        fclose(myPtr);// closes the file after writing
        printf("Songs have been saved to 'Song Catalogue.txt'.\n");// confirmation message after saving
    }
    main();// returns to main menu after saving data
}

void print_out_catologue_to_screen(){// function to print out the song catalogue to the screen
    FILE *myPtr = fopen("Song_Catalogue.txt", "r");// opens the file in read mode
    if (myPtr == NULL) {// checks if file opened successfully
        printf("Error: cannot open file for reading.\n");// error message if file not opened
        return;
    }
    int i, n= 5;
    for(i=0;i <n; i++){// loop to read each song's data from the file
        fgets(song[i].artist, 50, myPtr);// reads artist name from file
        fgets(song[i].title,50,myPtr);// reads title from file
        fscanf(myPtr,"%f",&song[i].price);// reads price from file
        fscanf(myPtr,"%d",&song[i].year);// reads year from file
        getchar();// reads the newline character after year to prepare for next fgets
    }
    fclose(myPtr);// closes the file after reading
    sorting();// calls sorting function to sort songs by year
    for (int j = 0; j < n; j++) {// loop to print each song's data to the screen
        printf("Artist:%s", song[j].artist);// prints artist name to screen
        printf("Title:%s", song[j].title);// prints title to screen
        printf("Price:%.2f\n", song[j].price);// prints price to screen
        printf("Year:%d\n", song[j].year);// prints year to screen
    }
}

void sorting() {// using bubble sorting
    int n = 5, i; // number of songs
    for (i = 0; i < n - 1; i++) {//outer loop for passes
        for (int j = 0; j < n - 1; j++) {//inner loop compares data
            if (song[j].year < song[j + 1].year) {// compares year of current song with next song if current song year is less than next song year
                struct songs_catalogue temp = song[j];// temporary variable to hold current song data that is being swapped
                song[j] = song[j + 1];// swaps current song with next song
                song[j + 1] = temp;// assigns temporary variable to next song
            }
        }
    }
}

int main(){//main function
    int choice;// variable to store user choice as integer
    printf("The following options are available:\n");
    printf("Read in data[1]\n");
    printf("Print Out the catalogue[2]\n");
    printf("Save data to file[3]\n");
    printf("Exit Program[4]\n");
    printf("Enter choice Now:");
    scanf("%d",&choice);// reads user choice from keyboard input

    switch(choice){// switch statement to handle user choice
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
        default:// default case for invalid choice
        printf("INVALID CHOICE TRY AGAIN");
    }
}