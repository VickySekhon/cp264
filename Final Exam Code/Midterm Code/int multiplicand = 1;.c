int multiplicand = 1;
int length = strlen(s);
int new_s; 
for (int i = 0; p[i] != '\0'; i++){
     multiplicand = 1;
     for(int j = 0; j < length - 1; j++){
          multiplicand *= 10; 
     }
     new_s += (p[i] - '0') * multiplicand;
     length--; 
}
return new_s; 