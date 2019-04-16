class Ball
{
  int posX, posY, r, sy;
  
  Ball(int px,int py,int _r)
  {
    posX=px;
    posY=py;
    r=_r;
    sy=5;
  }
  
  void display()
  {
    noStroke();
    fill(255,0,0);
    ellipseMode(CENTER);
    ellipse(posX,posY,r*2,r*2);
  }
  
  void move()
  {
    posY+=sy;
  }
  
  void bounce()
  {
    if(posY>height)
    {
      sy=-sy;
      posY=height;
    }
    if(posY<0)
    {
      sy=-sy;
      posY=0;
    }
  }
  
  void run()
  {
    move();
    display();
    bounce();
  }
  
  
  
}
