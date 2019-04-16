Ball b,c;
void setup()
{
  size(512,256);
  b=new Ball(50,0,10);
  c=new Hyperball(100,0,20);
}

void draw()
{
  background(255);
  b.run();
  c.run();
  
  
}
