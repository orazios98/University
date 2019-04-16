class Hyperball extends Ball
{
  color c;
  Hyperball(int x, int y, int r)
  {
    super(x,y,r);
    c=color(0,0,255);
  }
  
  void display()
  {
    noStroke();
    fill(c);
    ellipseMode(CENTER);
    ellipse(posX,posY,r*2,r*2);
  }
  
  void mouseCovered()
  {
    if((mouseX>(posX-r)) && (mouseX<(posX+r)) && (mouseY>(posY-r)) && (mouseY<(posY+r)))
    {
      c=color(random(0,255),random(0,255),random(0,255));
    }
  }
  
  void run()
  {
    mouseCovered();
    super.run();
  }
  
  
}
