#include <stdio.h>
void get_inputs(int* NoOfDays,
                 int* Airfare, 
                 int* GroundTransportationPerDay,
                 int* HotelCostPerNight,
                 int* CostOfFoodPerDay,
                 int* Entertainment);
void get_subtotal(int days, 
                   int car_per_day, 
                   int hotel_per_night, 
                   int food_per_day, 
                   int* Total_car, 
                   int* Total_hotel, 
                   int* Total_food);
void get_total (int days, 
                int Total_car, 
                int Total_hotel,
                int Total_food, 
                int entertainment, 
                int* Total);
void get_print(int Total_car, 
                int Total_hotel, 
                int Total_food, 
                int Total);
    

int main(void)
{
    int days, airfare, car_per_day, hotel_per_night, food_per_day, entertainment;
    int Total_car, Total_hotel, Total_food;
    int Total;
    
    get_inputs(&days, &airfare, &car_per_day, &hotel_per_night, &food_per_day, &entertainment);

    get_subtotal(days, car_per_day, hotel_per_night, food_per_day, &Total_car, &Total_hotel, &Total_food);
    
    get_total(days, Total_car, Total_hotel, Total_food, entertainment, &Total);
    
    get_print(Total_car, Total_hotel, Total_food, Total);
}


void get_inputs(int* NoOfDays,
                 int* Airfare, 
                 int* GroundTransportationPerDay,
                 int* HotelCostPerNight,
                 int* CostOfFoodPerDay,
                 int* Entertainment)
{
    printf("Total Number of days : ");
    scanf("%d", NoOfDays);
    
    printf("Total Airfare : ");
    scanf("%d", Airfare);
    
    printf("Ground transportation per day : ");
    scanf("%d", GroundTransportationPerDay);
    
    printf("Hotel cost Per night : ");
    scanf("%d", HotelCostPerNight);
    
    printf("Cost Of food per day : ");
    scanf("%d", CostOfFoodPerDay);
    
    printf("Total cost of entertainment : ");
    scanf("%d", Entertainment);
    
    return;
}

void get_subtotal (int days, 
                int car_per_day, 
                int hotel_per_night, 
                int food_per_day, 
                int* Total_car, 
                int* Total_hotel, 
                int* Total_food)
{
    *Total_car = car_per_day * days;
    *Total_hotel = hotel_per_night * (days-1);
    *Total_food = food_per_day * days;
    
    return;
 
}

void get_total (int days, 
                int Total_car, 
                int Total_hotel,
                int Total_food, 
                int entertainment, 
                int *Total)
{
    *Total = days + Total_car + Total_hotel + Total_food + entertainment;
    
    return;
}

void get_print(int Total_car, 
                int Total_hotel, 
                int Total_food, 
                int Total)
{
    printf("Total cost for car: %d\n", Total_car);
    printf("Total cost for hotel: %d\n", Total_hotel);
    printf("Total cost for food: %d\n", Total_food);
    printf("Total Trip Cost: %d\n", Total);
    
    return;
}

