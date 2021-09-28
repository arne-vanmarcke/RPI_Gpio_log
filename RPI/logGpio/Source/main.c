#include "RPI.h"
#include <stdio.h>
#include <mysql.h>

typedef struct Gpio{
    int pin;
    int state;
}_gpio;

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}

int main(){
    _gpio Gpio[5];
    Gpio[0].pin=17;
    Gpio[1].pin=27;
    Gpio[2].pin=22;
    Gpio[3].pin=23;
    Gpio[4].pin=24;
    MYSQL *con = mysql_init(NULL);

    if (con == NULL) 
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        return -1;
    }

    if (mysql_real_connect(con, "localhost", "webuser", "secretpassword", "GPIO", 0, NULL, 0) == NULL) 
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        return -1;
    }  

    if(map_peripheral(&gpio)==-1){
        printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
        return -1;
    }

    for(int i=0; i<(sizeof(Gpio)/sizeof(Gpio[0]));i++)
    {
        INP_GPIO(Gpio[i].pin);

        int val=GPIO_READ(Gpio[i].pin);
        if(val>0){
            Gpio[i].state=1;
        }
        else
        {
            Gpio[i].state=0;
        }
    }

    while(1){
        for(int i=0; i<(sizeof(Gpio)/sizeof(Gpio[0]));i++)
        {
            int gpioVal=GPIO_READ(Gpio[i].pin);
            printf("pin %d: %d (state:%d)\r\n",Gpio[i].pin,gpioVal,Gpio[i].state);
            if(gpioVal)
                gpioVal=1;
            else
                gpioVal=0;
            if(gpioVal!=Gpio[i].state)
            {
                printf("Gpio %d set to %d (prev state:%d)\r\n",Gpio[i].pin,!Gpio[i].state,Gpio[i].state);
                Gpio[i].state=!Gpio[i].state;

                char sql_query[100];

                sprintf(sql_query,"INSERT INTO gpio_logs(nr,state)VALUES(%d,%d)",Gpio[i].pin,Gpio[i].state);

                if (mysql_query(con, sql_query))
                {
                    finish_with_error(con);
                }
            }
        }
    }

    mysql_close(con);
    return 0;
}