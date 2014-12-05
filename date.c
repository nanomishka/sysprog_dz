 #include <stdio.h>  
 #include <time.h>  
  
 int main () {  
      time_t rawtime;  
      struct tm * stTimeInfo;   
      time ( &rawtime );  
      stTimeInfo = localtime ( &rawtime );  
      stTimeInfo->tm_year = nYear - 1900;  
      stTimeInfo->tm_mon = nMonth - 1;  
      stTimeInfo->tm_mday = nDay-1;  
      mktime ( stTimeInfo );  
      printf ("%d/%d/%d\n", stTimeInfo->tm_year+1900, stTimeInfo->tm_mon+1, stTimeInfo->tm_mday);
      return 0;  
 }  