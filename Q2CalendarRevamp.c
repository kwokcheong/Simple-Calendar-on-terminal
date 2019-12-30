#include <stdio.h>
#include <stdbool.h>

bool is_leap_year (int year) { 
bool is_leap = 0;
if (year % 4 == 0) { 
    is_leap = 1;
} 
if ( year % 100 == 0) { 
    if (year % 400 == 0){ 
        is_leap = 1;
    } else { 
        is_leap = 0;
    }
}
return is_leap;
}

int days_in_month (int month, int year) { 
 int day = 0;
 int array[4] = {4,6,9,11};
if (month == 2){ 
    if (is_leap_year(year)) { 
        day = 29;
    } else { 
        day = 28;
    }
} else {
    for (int i=0; i<=3; i++){ 
        if (month == array[i]){ 
        day = 30;
        break;
        } else { 
        day = 31;
        }
}
}
return day;
}

int inc_date (int date){ 
    int day = date%100;
    int month = (date/100) % 100;
    int year = date/10000;

    if (day == days_in_month(month, year)){ 
        date = date + (101-day);
    } else { 
        date = date + 1;
    }
    if (((date/100) % 100) > 12){ 
        date = date + 8800;
    }
    return date;
}

int days_from_epoch (int day, int month, int year){ 
//assume input > epoch
int epoch = 19700101;
int t_year = year * 10000 + month * 100 + day;
int days=0;

if ( t_year >= epoch){
while (epoch <= t_year){
    epoch = inc_date(epoch);
    days++;
}
} else if (t_year <= epoch) {
while (t_year <= epoch){
    t_year = inc_date(t_year);
    days++;
}
days = days* -1;
} else { 
    days = 0;
}

return days;
}


int day_of_week (int day, int month, int year){ 
//Assume higher than epoch
int date =4;
int days = days_from_epoch(day,month, year);
if (days > 0){
while (days > 0){ 
date++;
if (date > 6){ 
date = 0;
} 
days --;
}
} else { 
    while (days < 0){ 
date--;
if (date < 0 ){ 
date = 6;
} 
days ++;
}
}
return date;
}

void display_month ( int month, int year){ 
int day = 1;
int start_day = day_of_week(1,month, year);

printf ("  S  M  T  W  T  F  S");

for (int i=0; i<5; i++){ 
    printf("\n");
    for (int j=0; j<=6;j++){
        if (day <= days_in_month(month,year)){
            if (start_day > 0){
                day = day - start_day;
                start_day = 0;
            }
        if (day <= 0){ 
        printf ("   ");
        day++;
        } else {
        printf ("%3d",day);
        day++;
        }
    }
}
}


}

int main (void) { 
//printf ("%d", days_from_epoch (01,01,0001));
display_month(12,1991);
}