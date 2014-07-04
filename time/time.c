#include <stdio.h>


#define STRID_MONDAY                                      65 
#define STRID_TUESDAY                                     66 
#define STRID_WEDNESDAY                                   67 
#define STRID_THURSDAY                                    68 
#define STRID_FIRDAY                                      69 
#define STRID_SATURDAY                                    70 
#define STRID_SUNDAY    71
#define TIME_VALUE_TYPE_MAST			0X0000007F
	#define TIME_VALUE_TYPE_ALL 		TIME_VALUE_TYPE_MAST
	#define TIME_VALUE_TYPE_DATE 		0x00000007
		#define TIME_VALUE_TYPE_YEAR 		0x00000001
		#define TIME_VALUE_TYPE_MONTH 		0x00000002
		#define TIME_VALUE_TYPE_DAY		 	0x00000004
	#define TIME_VALUE_TYPE_WEEK 		0x00000008
	#define TIME_VALUE_TYPE_TIME 		0x00000070
		#define TIME_VALUE_TYPE_HOUR 		0x00000010
		#define TIME_VALUE_TYPE_MIN 		0x00000020
		#define TIME_VALUE_TYPE_SEC 		0x00000040
#define TIME_SHIFT		28800		//nanjing + 8:00

typedef long time_t;

struct tm
{
	int	tm_sec;
	int	tm_min;
	int	tm_hour;
	int	tm_mday;
	int	tm_mon;
	int	tm_year;
	int	tm_wday;
	int	tm_yday;
	int	tm_isdst;
};

void ap_time_daytime2CHNstr (time_t time, unsigned int * str,unsigned long time_type)
{
	struct tm tm_time;
	unsigned int tmp_str[6];
	long year;
	long mon, day, hour, min,sec;
	time_t temp;
	int week_idx;
	unsigned int year_chn[2]={0x745e,0}; //.
	unsigned int month_chn[2]={0x0867,0};//.
	unsigned int day_chn[3]={0xe565,0}; //.
	unsigned int *week_chn;

	unsigned int week_strid_idx[7]=
	{
		STRID_SUNDAY, 
		STRID_MONDAY ,   
		STRID_TUESDAY ,  
		STRID_WEDNESDAY, 
		STRID_THURSDAY ,
		STRID_FIRDAY , 
		STRID_SATURDAY, 
	};


	temp = time + TIME_SHIFT;
	GMTTIME_R(&temp, &tm_time);

	year = tm_time.tm_year+1900;
	mon = tm_time.tm_mon +1, day = tm_time.tm_mday;
	hour = tm_time.tm_hour, min = tm_time.tm_min;
	sec = tm_time.tm_sec;

	week_idx = tm_time.tm_wday;

	if((TIME_VALUE_TYPE_MAST & time_type)&TIME_VALUE_TYPE_YEAR)
	{
		convert_num_to_fixed_dec_str (str, year, 4);
		uni_strcat (str,year_chn,2);
	}
	if((TIME_VALUE_TYPE_MAST & time_type)&TIME_VALUE_TYPE_MONTH)
	{
		convert_num_to_fixed_dec_str (tmp_str, mon, 2);
		uni_strcat (str, tmp_str, 5);
		uni_strcat (str,month_chn,2);
	}
	if((TIME_VALUE_TYPE_MAST & time_type)&TIME_VALUE_TYPE_DAY)
	{
		convert_num_to_fixed_dec_str (tmp_str, day, 2);
		uni_strcat (str, tmp_str, 5);
		uni_strcat (str,day_chn,2);
	}

	if((TIME_VALUE_TYPE_MAST & time_type)&TIME_VALUE_TYPE_WEEK)
	{
		ascstr_to_uni ((unsigned char *)" ", tmp_str);
		uni_strcat (str, tmp_str, 5);
		week_chn = (unsigned int *)osd_rsc_get_string(osd_rsc_get_language(), week_strid_idx[week_idx]);
		uni_strcat(str,week_chn,10);
	}

	if((TIME_VALUE_TYPE_MAST & time_type)&TIME_VALUE_TYPE_HOUR)
	{
		ascstr_to_uni ((unsigned char *)" ", tmp_str);
		uni_strcat (str, tmp_str, 5);
		convert_num_to_fixed_dec_str (tmp_str, hour, 2);
		uni_strcat (str, tmp_str, 5);
	}
	if((TIME_VALUE_TYPE_MAST & time_type)&TIME_VALUE_TYPE_MIN)
	{
		ascstr_to_uni ((unsigned char *)":", tmp_str);
		uni_strcat (str, tmp_str, 5);
		convert_num_to_fixed_dec_str (tmp_str, min, 2);
		uni_strcat (str, tmp_str, 5);
	}
	if((TIME_VALUE_TYPE_MAST & time_type)&TIME_VALUE_TYPE_SEC)
	{
		ascstr_to_uni ((unsigned char *)":", tmp_str);
		uni_strcat (str, tmp_str, 5);
		convert_num_to_fixed_dec_str (tmp_str, sec, 2);
		uni_strcat (str, tmp_str, 5);
	}

}

int main(void)
{
	unsigned long input_time;
	unsigned int str[80];
	int i;
	input_time = 1113480000;

	memset(str, 0, sizeof(str));
	ap_time_daytime2CHNstr(input_time,str,0x00000040);
	while(str[i] != 0)
	{
		printf("%ld  ",str[i]);
		i++;
	}
}
