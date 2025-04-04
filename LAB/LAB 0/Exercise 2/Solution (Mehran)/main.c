#include <stdio.h>
#include <string.h>
#include <math.h>


typedef struct Rectangle {
    char word[16];
    float first[2];
    float second[2];
    float area;
    float perimeter;
} rectangle;

void read_and_update(rectangle[], char*, int*);
void update_area_perimeter(rectangle [] , int *);
void sort_based_area(rectangle[] , int *);



int main() {
    char *file = "../file.txt";
    int number_of_rectangles = 0;
    rectangle Torino[100];

    read_and_update(Torino, file, &number_of_rectangles);
    update_area_perimeter(Torino ,  &number_of_rectangles);

    for (int j = 0; j < number_of_rectangles; j++) {
        printf("THE RECTANGLE NAME IS  : %s\n", Torino[j].word);
        printf("the first points coordinate is %f and %f\n", Torino[j].first[0], Torino[j].first[1]);
        printf("the second points coordinate is %f and %f\n", Torino[j].second[0], Torino[j].second[1]);
        printf("Area: %f\n", Torino[j].area);
        printf("Perimeter: %f\n", Torino[j].perimeter);

    }

    return 0;
}

void read_and_update(rectangle array[], char *file_name, int *counter) {
    FILE *fin;

    if (!(fin = fopen(file_name, "r"))) {
        printf("ERROR REGARDING READING THE FILE %s\n", file_name);
        return;
    }

    *counter = 0;
    char temp[16];
    float first, second;

    while (fscanf(fin, "%s %f %f", temp, &first, &second) == 3) {
        int found = 0;

        for (int j = 0; j < *counter; j++) {
            if (strcmp(array[j].word, temp) == 0) {
                array[j].second[0] = first;
                array[j].second[1] = second;
                found = 1;
                break;
            }
        }

        if (!found && *counter < 100) {
            strcpy(array[*counter].word, temp);
            array[*counter].first[0] = first;
            array[*counter].first[1] = second;
            (*counter)++;
        }
    }

    fclose(fin);
}

void update_area_perimeter(rectangle array[] , int *number){
    int j=0;
    float x1 , x2 ;
    float y1 , y2 ;

    for (j=0 ; j< (*number) ; j++){
    x1=array[j].first[0];
    y1=array[j].first[1];
    x2=array[j].second[0];
    y2=array[j].second[1];
    array[j].area=fabs(x1 - x2) *fabs (y1 -y2);
    array[j].perimeter=(fabs(x1 -x2) + fabs ( y1 -y2)) *2;
    }

}

void sort_based_area(rectangle array[] , int *number){

    int i ;
    rectangle temp;


    for (i=0; i < (*number) ; i++){

        for (int j=i ; j< (*number) -1 ; j++){
            if (array[j].area < array[j+1].area){
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }

        }

    }




}