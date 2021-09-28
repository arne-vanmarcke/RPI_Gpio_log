#include <gpiod.h>
#include <stdio.h>
#include <mysql.h>

#ifndef	CONSUMER
#define	CONSUMER	"Consumer"
#endif

typedef struct Gpio{
    int pin;
    struct gpiod_line *line;
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

    char *chipname = "gpiochip0";
	struct gpiod_chip *chip;
	struct gpiod_line *line;
	int ret;

    chip=gpiod_chip_open_by_name(chipname);
    if(!chip){
        return -1;
    }

    for(int i=0; i<(sizeof(Gpio)/sizeof(Gpio[0]));i++){
        Gpio[i].line=gpiod_chip_get_line(chip, Gpio[i].pin);
        //print("%d\r\n",Gpio[i].line);
        if(!Gpio[i].line){
            return -1;
        }

        ret=gpiod_line_request_input(Gpio[i].line, CONSUMER);
        if (ret < 0) {
            return -1;
	    }
    }

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

    for(int i=0; i<(sizeof(Gpio)/sizeof(Gpio[0]));i++)
    {
        Gpio[i].state=gpiod_line_get_value(Gpio[i].line);
    }

    while(1){
        for(int i=0; i<(sizeof(Gpio)/sizeof(Gpio[0]));i++)
        {
            int gpioVal=gpiod_line_get_value(Gpio[i].line);
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