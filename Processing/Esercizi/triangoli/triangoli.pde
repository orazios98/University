Triangolo t;
Driangolo d;

void setup()
{
  size(512,512);
  t=new Triangolo(200,200,150,150,4);
  d=new Driangolo(200,400,200,200,4,5);
  frameRate(1000000000);
}

void draw()
{
  background(255);
  t.run();
  d.run();
}


void keyPressed()
{
  if(key=='s')
  {
    if(t.sX>0)
      t.sX--;
    else
      t.sX++;
  }
  if(key=='f')
  {
    if(t.sX>0)
      t.sX++;
    else
      t.sX--;
  }
}
