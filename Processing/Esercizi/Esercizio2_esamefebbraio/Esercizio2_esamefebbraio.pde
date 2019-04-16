PImage I;
void setup()
{
  size(768,256);
  I=loadImage("lena.png");
  I.filter(GRAY);
  I.resize(256,256);
  image(I,0,0);
  image(hash(I,30,128),256,0);
  image(hash(I,60,128,10),512,0);
}

void draw() {}

PImage hash(PImage I, int h, int k)
{
  PImage R=I.copy();
  for(int i=0;i<R.height;i++)
  {
    R.set(h,i,color(0));
    R.set(k,i,color(0));
  }
  return R;
}

PImage hash(PImage I, int h, int k, int n)
{
  PImage R=I.copy();
  int off=n/2;
  float f[];
  f=new float[n*n];
  for(int i=0;i<I.width;i++)
  {
    for(int j=0;j<I.height;j++)
    {
      PImage sub=I.get(i-off,j-off,n,n);
      sub.loadPixels();
      for(int tm=0;tm<sub.pixels.length;tm++)
      {
        f[tm]=green(sub.pixels[tm]);
      }
      float massimo=max(f);
      R.set(i,j,color(massimo));
    }
  }
  R=hash(R,h,k);
  return R;
}
