 #include <stdio.h>  
 #include <time.h>  
  
 int main () {  
      time_t rawtime;  
      struct tm * stTimeInfo;  
      int nYear, nMonth, nDay;  
      char * weekday[] = { "Sunday",  
                           "Monday",  
                           "Tuesday",   
                           "Wednesday",  
                           "Thursday",  
                           "Friday",   
                           "Saturday"};  
     /* 
      * take the user date 
      */  
      printf ("Enter Year: ");  
      scanf  ("%d",&nYear);  
      printf ("Enter Month: ");   
      scanf  ("%d",&nMonth);  
      printf ("Enter Day: ");   
      scanf  ("%d",&nDay);  
  
     /* 
      * get current stTimeInfo and modify it to the user's choice  
      */  
      time ( &rawtime );  
      stTimeInfo = localtime ( &rawtime );  
      stTimeInfo->tm_year = nYear - 1900;  
      stTimeInfo->tm_mon = nMonth - 1;  
      stTimeInfo->tm_mday = nDay-1;  
  
     /* 
      * call mktime: stTimeInfo->tm_wday will be set  
      */  
      mktime ( stTimeInfo );  
      //printf ("Entered Day is a %s.\n", weekday[stTimeInfo->tm_wday]);  
      printf ("%d/%d/%d\n", stTimeInfo->tm_year+1900, stTimeInfo->tm_mon+1, stTimeInfo->tm_mday);
      return 0;  
 }  