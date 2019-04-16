PImage I;
int n;

void setup()
{
  n=1;
  size(768,512);
  I=loadImage("lena.png");
  I.resize(256,256);
  I.filter(GRAY);  
}


void draw()
{
    image(I,0,0);
  image(massimo(I,n),256,0);
  image(minimo(I,n),512,0);
  image(mediano(I,n),0,256);
  image(media(I,n),256,256);
}

PImage massimo(PImage I, int n)
{
  PImage R=createImage(I.width,I.height,RGB);
  float f[]=new float[n*n];
  int off=n/2;
  for(int i=0;i<I.width;i++)
  {
    for(int j=0;j<I.height;j++)
    {
      PImage sub=I.get(i-off,j-off,n,n);
      sub.loadPixels();
      for(int k=0;k<sub.pixels.length;k++)
      {
        f[k]=red(sub.pixels[k]);
      }
      int m=int(max(f));
      R.set(i,j,color(m));
    }
  }
  return R;  
}

PImage minimo(PImage I, int n)
{
  PImage R=createImage(I.width,I.height,RGB);
  int off=n/2;
  float f[];
  int xs, ys;
  
  for(int i=0;i<I.width;i++)
  {
    for(int j=0;j<I.height;j++)
    {
      xs=i-off;
      ys=j-off;
      PImage sub=I.get(max(0,xs),max(0,ys),min(n,n+xs,I.width-xs),min(n,n+ys,I.height-ys));
      sub.loadPixels();
      f=new float[sub.pixels.length];
      
      for(int k=0;k<sub.pixels.length;k++)
      {
        f[k]=red(sub.pixels[k]);
      }
      
      int m=int(min(f));
      R.set(i,j,color(m));
    }
  }  
  return R;
}


PImage mediano(PImage I, int n)
{
  PImage R=createImage(I.width,I.height,RGB);
  int off=n/2;
  float f[];
  int xs,ys;
  
  for(int i=0;i<I.width;i++)
  {
    for(int j=0;j<I.height;j++)
    {
      xs=i-off;
      ys=j-off;
      PImage s=I.get(max(0,xs),max(0,ys),min(n,n+xs,I.width-xs),min(n,n+ys,I.height-ys));
      s.loadPixels();
      f=new float[s.pixels.length];
      for(int k=0;k<s.pixels.length;k++)
      {
        f[k]=green(s.pixels[k]);
      }
      float m;
      f=sort(f);
      if(f.length%2==1)
      {
        m=f[f.length/2];
      }
      else
      {
        m=(f[f.length/2]+f[f.length/2-1])/2;
      }
      R.set(i,j,color(m));   
    }
  }
  return R;
}

PImage media(PImage R, int n)
{
  PImage I=createImage(R.width,R.height,RGB);
  int off=n/2;
  float f[];
  int xs,ys;
  for(int i=0;i<R.width;i++)
  {
    for(int j=0;j<R.height;j++)
    {
      xs=i-off;
      ys=j-off;
      PImage sub=R.get(max(0,xs),max(0,ys),min(n,n+xs,I.width-xs),min(n,n+ys,I.height-ys));
      sub.loadPixels();
      int ls=sub.pixels.length;
      f=new float[ls];
      for(int k=0;k<ls;k++)
      {
        f[k]=green(sub.pixels[k]);
      }
      float ris=0;
      for(int k=0;k<ls;k++)
      {
        ris+=f[k];
      }
      float m=ris/f.length;
      I.set(i,j,color(m));
    }
  }
  
  
  return I;
}

void keyPressed()
{
  if(key=='+')
    n++;
  if(key=='-' && n>1)
    n--;
}
