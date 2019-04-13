class Triangolo
{
  float posX,posY,lato,sX,sY,altezza;
  
  Triangolo(float x, float y, float l,float h, float s)
  {
    posX=x;
    posY=y;
    lato=l;
    altezza=h;
    sX=s;
  }
  
  void display()
  {
    fill(0,0,255);
    noStroke();
    triangle(posX,posY,posX+(lato/2),posY-altezza,posX+lato,posY);
  }
  
  void move()
  {
    posX+=sX;
  }
  
  void bounce()
  {
    if(posX+(lato/2)>512)
    {
      sX=-sX;
      posX=512-(lato/2);
    }
    
    if(posX+(lato/2)<0)
    {
      sX=-sX;
      posX=-lato/2;
    }
    
  }
  
  void run()
  {
    display();
    move();
    bounce();
  }
  
  
  
}
