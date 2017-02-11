#include <stdio.h>
#include <graphics.h>

int main() {

  int gd=DETECT, gm;
  initgraph(&gd, &gm, NULL);

  line(0, getmaxy()/2, getmaxx(), getmaxy()/2);
  line(getmaxx()/2, 0, getmaxx()/2, getmaxy());

  setcolor(BLUE);
  circle(getmaxx()/2, getmaxy()/2, 150);

  setcolor(GREEN);
  circle(getmaxx()/2, getmaxy()/2, 75);

  setcolor(RED);
  circle(getmaxx()/2, getmaxy()/2, 25);

  delay(5000);
  closegraph();

  return 0;
}

/*

  - A biblioteca graphics.h é para a criação de graficos em c

  - Para instalar é só seguir os seguintes passos:

    Instalar o basico do compilador:
      sudo apt-get install build-essential

    Instalar dependencias da biblioteca:
      sudo apt-get install libsdl-image1.2 libsdl-image1.2-dev guile-1.8 guile-1.8-dev libsdl1.2debian libart-2.0-dev libaudiofile-dev libesd0-dev libdirectfb-dev libdirectfb-extra libfreetype6-dev libxext-dev x11proto-xext-dev libfreetype6 libaa1 libaa1-dev libslang2-dev libasound2 libasound2-dev


    Download de libgraph-1.0.2 e fazer os comandos abaixo:

      cd libgraph-1.0.2

      ./configure

      sudo make

      sudo make install

      sudo cp /usr/local/lib/libgraph.* /usr/lib

    Compilar no terminal:

      gcc NomeDoPrograma.c -o prog -lgraph

*/
