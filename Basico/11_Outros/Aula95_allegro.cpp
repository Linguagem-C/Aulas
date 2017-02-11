#include <stdio.h>
#include <allegro5/allegro.h>

int main(int argc, char *argv[]) {

    ALLEGRO_DISPLAY *janela = NULL;

    if (!al_init()) {
        fprintf(stderr, "Falha ao inicializar a Allegro 5\n");
        return -1;
    }

    janela = al_create_display(640, 480);

    if (!janela) {
        fprintf(stderr, "Falha ao criar a janela\n");
        return -1;
    }

    al_clear_to_color(al_map_rgb(255, 255, 255));

    al_flip_display();

    al_rest(10.0);

    al_destroy_display(janela);

    return 0;
}

/*

  - Alegro é uma biblioteca para criação de games 2D

  - Aparecerá uma janela preenchida de branco que permanecerá na tela por 10 segundos.

  - Instalar dependencias:

    sudo apt-get install build-essential subversion cmake xorg-dev libgl1-mesa-dev libglu-dev

  - Instalar as bibliotecas necessárias à compilação dos módulos da Allegro 5:

    sudo apt-get install libpng-dev libz-dev libcurl4-gnutls-dev libfreetype6-dev libjpeg-dev libvorbis-dev libopenal-dev libphysfs-dev libgtk2.0-dev libasound-dev libflac-dev libdumb1-dev

  - Construir os arquivos de documentação da biblioteca:

    sudo apt-get install exuberant-ctags dvi2ps dvipdfmx latex2html pandoc

  - Baixar o código-fonte da Allegro 5 para compilarmos:

    svn co https://alleg.svn.sourceforge.net/svnroot/alleg/allegro/branches/5.0 allegro-5.0

  - Este comando baixará o código-fonte dos repositórios oficiais e colocará em uma pasta chamada allegro-5.0.

  - Navegar para a pasta e preparar os arquivos para a instalação:

    cd allegro-5.0

    cmake -DCMAKE_INSTALL_PREFIX=/usr .

  - Para finalizar, digite no Terminal:

    make

    sudo make install

  - Para compilar e executar o programa, basta digitar no Terminal:

    gcc -lallegro -oteste main.c

    ./teste

*/
