//void (*start)()
#include "nRF52810_timer.h"
nrf_bool start_event_enable = TRUE; //boolean to check if stop_event routine is called
void start_event(nrf_int time_in_us, void (*start)(int))
{
	nrf_drv_timer_init();
	nrf_drv_timer_enable();
	nrf_int event_count = 0; // variable to count the number of times an event has occured
	
	while(true)
	{
		if(start_event_enable) // 
		{
			ticks_in_us(time_in_us); // assuming that Nordic has this function that counts in us
			event_count++;
			start(event_count);
		}
	}
}

void stop_event()
{
	start_event_enable = FALSE;
	event_count = 0;
}

void print_count(nrf_int count)
{
	nrf_println(count); // assuming that Nordic has this routine for printing, as printf is a very expensive operation
}

int main(void)
{
	//there will be some nrf52810 related initializations.
	void (*start)(int) = print_count;
	start_event(509000, start);
	return 0;
}
