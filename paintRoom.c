#include "paintRoom.h"
#include <string.h>
#include <stdlib.h>
void recPaintRoom(char** room, int row, int col, int distanceFromA);/* feel free to remove/add any other parameters here*/
/* declare any other helper functions here*/
int rows[4] = {0, 1, 0, -1};
int cols[4] = {1, 0, -1, 0};
/* printNames
 * input: none
 * output: none
 *
 * Prints names of the students who worked on this solution
 */
void printNames( )
{
    /* TODO : Fill in you and your partner's names (or N/A if you worked individually) */
    printf("\nThis solution was completed by:\n");
    printf("Jayden Palacios\n");
    printf("N/A\n\n");
}

/* TODO
 * paintRoom
 * input: the room to process
 * output: N/A
 *
 * This non-recursive function is called by the driver and it makes the initial call to recursive function recPaintRoom.
 */
void paintRoom( RoomData room )
{
    /* Call any other helper functions (a helper function to find the location of 'A' in room may be handy) */
    int* a = findA(room, room.numrows, room.numcols);
    /* Call your recursive function here */
    recPaintRoom( room.roomArray, a[0], a[1], 0);
    free(a);
}

/* TODO
 * recPaintRoom
 * input: the room to process, the row and column of the current location being explored, the distance traveled from 'A'
 * output: N/A
 */

/*run time is probably o(4^n) since there are four recusrive calls for each call*/
void recPaintRoom(char** room, int row, int col, int distanceFromA /* feel free to remove/add any other parameters here*/ )
{
    /* base cases */
    int i;
    if(room[row][col] == '*' || (room[row][col] < (65 + distanceFromA) && room[row][col] != ' ')) return;
    /* recursive cases */
    (distanceFromA >= 25) ? (room[row][col] = 90) : (room[row][col] = 65 + distanceFromA); /*if distance is over 'Z' assign element to 'Z' (up to 'Z') */
    for(i = 0; i < 4; i++) /*4 is number of calls (up left down right) */
        recPaintRoom(room, row + rows[i], col + cols[i], (distanceFromA +1)); /*uses global array with a loop to decide direction of 4 calls. just makes code cuter and cleaner*/
    return;
}

int * findA(RoomData room, int rows, int cols){
    int j, i;
    int* a = (int*)malloc(sizeof(int)*2);
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
        if(room.roomArray[i][j] == 65){
            a[0] = i;
            a[1] = j;
            return a;
        }
        }
        j = 0;
    } 
    return a; /* a not found*/
}