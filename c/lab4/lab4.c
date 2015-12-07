#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float* getData(int* num_of_datareadings);
float** allocateMemoryForArrayOfPointers(float* data, int num_of_readings);
void sort(float** ptrArray, int num_of_readings);
float calcMean(float* data, int num_of_datareadings);
float calcStandardDeviation(float* data, int num_of_datareadings, float mean);
void output(float* data, float** ptrArray, int num_of_datareadings,
float mean, float standard_deviation);


/*
Lab 4
Author : Amrita Mukherjee
email : m.amrita@gmail.com
*/

int main(void)
{
    int n;
    int i;
    float* data;
    float** ptrArray;
    float mean;
    float standard_deviation;

    data = getData(&n);         // get data from the file to an array called data
    ptrArray = allocateMemoryForArrayOfPointers(data, n);
                                // creates an arraey of pointers (ptrArray) pointing
                                // to float pointers(data)
    sort(ptrArray, n);          // sorts the arrey of floats
    mean = calcMean(data, n);   // calculated mean of floats
    standard_deviation = calcStandardDeviation(data, n, mean);
                                // calculates the standard deviation of the floats
    output(data, ptrArray, n, mean, standard_deviation);
                                // output to a file

    system("pause");

    return 0;
}


/*============getData=================*/

float* getData(int* num_of_datareadings)
{
    FILE* fp;
    float* data;
    int i=0;

    fp = fopen("lab4.txt", "r");
    fscanf(fp, "%d", num_of_datareadings);
    data = (float*)calloc(*num_of_datareadings, sizeof(float));
    for(i=0;i<*num_of_datareadings;i++)
    {
        fscanf(fp, "%f", data+i);
    }
    fclose(fp);
    return data;
}

/*==============allocateMemoryForArrayOfPointers=============*/

float** allocateMemoryForArrayOfPointers(float* data, int num_of_readings)
{
    int i;
    float**  ptrArray;

    ptrArray = (float**)calloc(num_of_readings, sizeof(float*));
    for(i=0;i<num_of_readings;i++)
    {
        *(ptrArray+i)= data+i;
    }
    return ptrArray;
}


/*============sort======================*/

void sort(float** ptrArray, int num_of_readings)
{
    int current;
    int walker;
    int smallest_index;
    float* temp;

    for(current=0;current<num_of_readings-1;current++)
    {
        smallest_index = current;
        for(walker=current;walker<num_of_readings;walker++)
        {
            if(**(ptrArray+walker) < **(ptrArray+smallest_index))
            {
                smallest_index = walker;
            }
        }
        temp = *(ptrArray+current);
        *(ptrArray + current) = *(ptrArray + smallest_index);
        *(ptrArray+smallest_index) = temp;
    }
    return;
}

/*================calcMean===========================*/

float calcMean(float* data, int num_of_datareadings)
{
    float sum = 0.0;
    float mean;
    int i;

    for(i=0;i<num_of_datareadings;i++)
    {
        sum += *(data+i);
    }
    mean = sum/num_of_datareadings;
    return mean;
}

/*===================calcStandardDeviation=============*/

float calcStandardDeviation(float* data, int num_of_datareadings, float mean)
{
    float total_dataMinusMeanSq = 0;
    float standard_deviation;
    int i;

    for(i=0;i<num_of_datareadings;i++)
    {
        total_dataMinusMeanSq += ((*(data+i))-mean) * ((*(data+i))-mean);
    }
    standard_deviation = sqrt((float)(total_dataMinusMeanSq/num_of_datareadings));
    return standard_deviation;
}

/*============output================*/

void output(float* data,
        float** ptrArray,
        int num_of_datareadings,
        float mean,
        float standard_deviation)
{
    FILE* fp;
    int i;
    int notnewline;

    fp = fopen("lab4Output.txt", "w");
    if (fp == NULL)
    {
        printf("I couldn't open results.dat for writing.\n");
        exit(0);
    }
    fprintf(fp, "Author : Amrita Mukherjee | email : m.amrita@gmail.com | Lab4\n");
    fprintf(fp, "%d\n", num_of_datareadings);
    fprintf(fp, "\n");
    fprintf(fp, "The data array:\n");
    for(i=0;i<num_of_datareadings;i++)
    {
        fprintf(fp, "%8.2f", *(data+i));
        notnewline = (i+1) % 8;
        if (notnewline == 0) 
        {
            fprintf(fp, "\n");
        }
    }
    fprintf(fp, "\n\n");
    fprintf(fp, "The sorted array:\n");
    for(i=0;i<num_of_datareadings;i++)
    {
        fprintf(fp, "%8.2f", **(ptrArray+i));
        notnewline = (i+1) % 8;
        if (notnewline == 0) 
        {
            fprintf(fp, "\n");
        }
    }
    fprintf(fp, "\n\n");

    for(i=0; i<num_of_datareadings; i++)
    {
        if(    **(ptrArray+i) < mean - (1.5 * standard_deviation)
            || **(ptrArray+i) > mean + (1.5 * standard_deviation)
          )
        {
            fprintf(fp, "Out of range: ");
        }
        fprintf(fp, "%.2f\n", **(ptrArray+i));
    }
    fclose(fp);
    return;
}
