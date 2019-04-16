PImage R;
int n;

void setup()
{
  n=3;
  size(512,256);
  R=loadImage("lena.png");
  R.filter(GRAY);
  R.resize(256,256);
  image(R,0,0);
  image(bitplane(R,n),256,0);
}

void draw(){}

PImage bitplane(PImage R, int n)
{
  PImage I=R.copy();
  R.loadPixels();
  for(int i=0;i<R.pixels.length;i++)
  {
    int k=int(green(R.pixels[i]));
    int r=(k>>n)&1;
    I.pixels[i]=color(r*255);
  }
  return I;
}

void keyPressed()
{
  if(key=='+' && n<7)
    image(bitplane(R,++n),256,0);
  if(key=='-' && n>0)
    image(bitplane(R,--n),256,0);
}
