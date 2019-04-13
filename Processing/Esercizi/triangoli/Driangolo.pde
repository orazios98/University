class Driangolo extends Triangolo
{
  float angolo;
  Driangolo(float x, float y, float l,float h, float s, float ang)
  {
    super(x,y,l,h,s);
    angolo=ang;
  }
  
  void display()
  {
    fill((255+angolo*8)%255,100+angolo%255*2,30+angolo%255*1);
    pushMatrix();
    translate(posX,posY);
    rotate(radians(angolo));
    triangle(-lato/2,altezza/3,0+(lato/2)-(lato/2),0-altezza+(altezza/3),0+lato-(lato/2),altezza/3);
    stroke(0);
    point(0,0);
    popMatrix();
    angolo++;
  }
  
    void bounce()
  {
    if(posX>512)
    {
      sX=-sX;
      posX=512;
    }
    
    if(posX<0)
    {
      sX=-sX;
      posX=0;
    }
    
  }
}
