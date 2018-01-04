/**
 * @file knightrider.ino 
 * @author copyrights
 * @brief Knight Rider like front row.
 * @ingroup knightrider
 */
#include "knightrider.h"
#include "utils.h"
/**
 * @ingroup knightrider
 * @{
 */
 
/**
 * @brief Knight Rider like front row.
 * 
 * This let a light move from left to right and back from right to left
 * on the front row. It should look like KITT from the famous 80's TV
 * Show Knight Rider.
 * 
 */
void knightrider(){
  uint16_t lc,s,pit,distance,pos;
  uint8_t f;
  
  lc = sizeof(front_row);
  s = KRPERIOD / lc;
  pit = time % KRPERIOD;
  
  if((time % (KRPERIOD * 2)) < KRPERIOD){
    
    for(uint16_t i=0;i<lc;i++){
      pos = i * s;
      if (pos>pit)
      {
        distance = pos - pit;
      }
      else
      {
        distance = pit - pos;
      }  
      f = fade8(distance, KRDTZ);
      strip.setPixelColor(front_row[i], percent8(KRR,f), percent8(KRG,f), percent8(KRB,f));
    }
  }else{
    for(uint16_t i=0;i<lc;i++){  
      pos = (lc-1-i)*s;
      if (pos>pit)
      {
        distance = pos - pit;
      }
      else
      {
        distance = pit - pos;
      }  
      f = fade8(distance, KRDTZ);
      strip.setPixelColor(front_row[i], percent8(KRR,f), percent8(KRG,f), percent8(KRB,f));
    } 
  }
}
/**@}*/
