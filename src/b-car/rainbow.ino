#define RBSTEP 40
const byte rainbowrow_left[]  = {5,13,14,17,15,16,18,19,20,21,30,31,29, 9,10,11,12};
const byte rainbowrow_right[] = {5, 4, 3, 0 , 2, 1,22,23,24,25,27,26,28, 9, 8, 7, 6};

void rainbowmode()
{
  byte pos = ((time * 255)/1000) % 255;
  //Button2
  if((pressed & (1<<1)) > 0)
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
  else if((pressed & (1<<2)) > 0)
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
  else if((pressed & (1<<3)) > 0)
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
  modified=true;
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
  modified=true;
}

void rainbow(byte led, byte pos,byte distance)
{
  strip.setPixelColor(led,Wheel((pos+distance*RBSTEP)%255));
}
