#include <stdio.h>
#include <math.h>

int main(void) {
  int temperature, windSpeed;
  double windChill;
  printf("Enter the temperature: ");
  scanf("%d", &temperature);
  printf("Enter the wind speed: ");
  scanf("%d", &windSpeed);
  windChill = 35.74 + (0.6215*(double)temperature)-(35.75*pow((double)windSpeed, 0.16))+ (0.4275*(double)temperature*pow((double)windSpeed, 0.16));
  printf("Entering %d %d gives a wind chill of %lf\n", temperature, windSpeed, windChill);
return 0;
}
