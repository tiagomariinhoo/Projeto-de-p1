#include <allegro.h>

volatile int exit_programa = FALSE; //Tambem pode ser while(!exit_program) ali no while, ao invés de !key[KEY_ESC]
void fecha_programa() {exit_programa=TRUE;}
END_OF_FUNCTION(fecha_programa);

int main ()
{
    allegro_init(); //Vai inicializar umas coisas basicas da biblioteca
    install_timer(); //Instalar os timers padrão, funcionar o mouse e tocar audio etc
    install_keyboard(); //Para instalar o teclado,tambem pode instalar mouse etc
    set_color_depth(32); //Parametros são a quantidade de cores, 32 bits,16 bits etc
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,600,555,0,0); //Autodetect detecta o driver de vídeo, é o recomendado, windowed e fullsc
    set_window_title("PACMAN"); //Titulo da janela do programa

    exit_programa=FALSE;
    LOCK_FUNCTION(exit_program);
    LOCK_VARIABLE(fecha_programa);
    set_close_button_callback(fecha_programa);



    BITMAP *buffer = create_bitmap(600,600);
    BITMAP *pacman = load_bitmap("sprites/pacman.bmp",NULL); //Ponteiro pro Boneco
    BITMAP *mapa = load_bitmap("sprites/mapa.bmp",NULL); //Ponteiro pro mapa


    int pos_x=110,pos_y=110;
    //GAME LOOP
    while (!exit_programa) //Condição para fechar o programa, array Key[estado da tecla]
    {
        //textout_centre_ex(screen,font,"OI ATAIDE, SOU O MELHOR STORM SPIRIT",SCREEN_W/2, SCREEN_H/2,makecol(255,255,255),-1);

        //INPUT
        //Detecta as entradas
            if(key[KEY_ESC])
            {
              fecha_programa();
            }

            if(key[KEY_D])
            {
                //clear(buffer);
                pos_x++;
            }
            if(key[KEY_S])
            {
                //clear(buffer);
                pos_y++;
            }
            if(key[KEY_A])
            {
                //clear(buffer);
                pos_x--;
            }
            if(key[KEY_W])
            {
                //clear(buffer);
                pos_y--;
            }

        //UPDATE
        //Atualiza o estado do jogo
        //pos_x++; //Variar a posição do circulo ao longo do tempo

        //DRAW
        //Parte de desenho - Ponteiro para BITMAP que é o "screen", tudo que vc desenhar, aparece na tela

        draw_sprite(buffer,mapa,0,0);
        draw_sprite_ex(screen,pacman,pos_x,pos_y, DRAW_SPRITE_NORMAL,DRAW_SPRITE_NO_FLIP);


        draw_sprite(screen,buffer,0,0); //Sprite em que eu quero desenhar, buffer na screen
        //clear(buffer);


    }
    //FINALIZAÇÃO
    destroy_bitmap(buffer);
    destroy_bitmap(pacman);
    destroy_bitmap(mapa);



    return 0;
}
END_OF_MAIN() //Tem que botar por questões de compatiblidade
