/**
 * @file rainbow.ino
 * @author copyrights
 * @brief Rainbow effect functions.
 * @ingroup rainbow
 * @todo Make period of rainbow cycle configurable in @ref config.h
 */
 
/**
 * @ingroup rainbow
 * @{
 */

void rainbowmode()
{
  byte pos = ((time * 255)/1000) % 255;
  //Button2
  if(buttonState(S2))
  {
    for (byte i=0;i<sizeof(rainbowrow_left);i++)
    {
      rainbow(rainbowrow_left[i],pos,i);
    }
    for (byte i=0;i<sizeof(rainbowrow_right);i++)
    {
      rainbow(rainbowrow_right[sizeof(rainbowrow_left)-1-i],pos,i);
    }
  }//Button3
  else if(buttonState(S3))
  {
    for (byte i=0;i<sizeof(rainbowrow_left);i++)
    {
      rainbow(rainbowrow_left[sizeof(rainbowrow_left)-1-i],pos,i);
    }
    for (byte i=0;i<sizeof(rainbowrow_right);i++)
    {
      rainbow(rainbowrow_right[i],pos,i);
    }
  }  
  //Button4
  else if(buttonState(S4))
  {
    for (byte i=0;i<sizeof(rainbowrow_left);i++)
    {
      rainbow(rainbowrow_left[sizeof(rainbowrow_left)-1-i],pos,i);
    }
    for (byte i=0;i<sizeof(rainbowrow_right);i++)
    {
      rainbow(rainbowrow_right[sizeof(rainbowrow_left)-1-i],pos,i);
    }
  }
  else
  {
    for (byte i=0;i<sizeof(rainbowrow_left);i++)
    {
      rainbow(rainbowrow_left[i],pos,i);
    }
    for (byte i=0;i<sizeof(rainbowrow_right);i++)
    {
      rainbow(rainbowrow_right[i],pos,i);
    }
  }
}

void underbody_rb()
{
  byte pos = ((time * 255)/1000) % 255;
  byte so;
  so=sizeof(down_left_row)-1;
  for (byte i=0;i<sizeof(down_left_row);i++)
  {
    rainbow(down_left_row[so-i],pos,i);
  }
  so=sizeof(down_right_row)-1;
  for (byte i=0;i<sizeof(down_right_row);i++)
  {
    rainbow(down_right_row[so-i],pos,i);
  }
}

void rainbow(byte led, byte pos,byte distance)
{
  strip.setPixelColor(led,Wheel((pos+distance*RBSTEP)%255));
}

/**@}*/
