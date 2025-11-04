#include <stdio.h> 
#include <stdbool.h>
#define max_songs 7 //max number of songs is 7

struct songs_catalogue{  
    char artist[50];
    char song_name[50];
    float price;
    int year    ;
} song[max_songs];

int main(){
    int choice;
    printf("The following options are Avaliable:\n");
    printf("Read in data[1]");
    printf("Print Out the catalogue[2]");
    printf("Save data to file[3]");
    printf("Exit Program[4]");
    printf("Enter choice Now:");
    scanf("%d",choice);
}


void read_in_data(){
    int n=5, i; // set at least five songs integer
    for (i=0; i<n; i++){
        printf("Enter artist name:");
        fgets(song[i].artist, 50, stdin);
        printf("Enter song name:");
        fgets(song[i].song_name, 50, stdin);
        printf("Enter price:");
        scanf("%.2f", &song[i].price);
        printf("Enter year:");
        scanf("%d", &song[i].year);
    }
    return 0;
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
            fprintf(myPtr, "Artist: %s", song[i].artist);
            fprintf(myPtr, "Song name: %s", song[i].song_name);
            fprintf(myPtr, "Price: %.2f", song[i].price);
            fprintf(myPtr, "Year: %d", song[i].year);
        }

        fclose(myPtr);
        printf("Songs have been saved to 'Song Catalogue.txt.\n");
    }
}

void print_out_data(){
    int n=5;
    FILE *myPtr = fopen("Song_Catalogue.txt", "r");
    if (myPtr == NULL) {
        printf("Error cannot not open file for reading.\n");
        return;
    while (fscanf(myPtr,))