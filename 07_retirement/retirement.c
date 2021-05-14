#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

void retirement (int startAge,   //in months
		 double initial, //initial savings in dollars
		 retire_info working, //info about working
		 retire_info retired){ //info about being retired
  int months = startAge;
  double saving = initial;
  int year = months / 12;
  int month = months % 12;
  printf("Age  %d month %2d you have $%.2f\n", year, month, saving);
  for(int i = 0; i < working.months; i++){
    months++;
    year = months / 12;
    month = months % 12;
    saving = saving + saving * working.rate_of_return / 12 + working.contribution;
    printf("Age  %d month %2d you have $%.2f\n", year, month, saving);
  }

  for(int i = 1; i < retired.months; i++){
    months++;
    year = months / 12;
    month = months % 12;
    saving = saving + saving * retired.rate_of_return / 12 + retired.contribution;
    printf("Age  %d month %2d you have $%.2f\n", year, month, saving);
  }
}

int main(){
  retire_info working = {489, 1000, 0.045};
  retire_info retired = {384, -4000, 0.01};
  int age = 327;
  double saving = 21345;
  retirement(age, saving, working, retired);
  return EXIT_SUCCESS;
}
