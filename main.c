#include <allegro.h>
#include <time.h>
#include <stdio.h>
volatile int exit_programa = FALSE; //Tambem pode ser while(!exit_program) ali no while, ao invés de !key[KEY_ESC]
void fecha_programa() {exit_programa=TRUE;}
int trilho(int x,int y){
    return 1;
}

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


    BITMAP *direita[2];
    BITMAP *esquerda[2];
    BITMAP *cima[2];
    BITMAP *baixo[2];

    direita[0] = load_bitmap("sprites/pacman1.bmp",NULL);
    direita[1] = load_bitmap("sprites/pacman11.bmp",NULL);
    esquerda[0] = load_bitmap("sprites/pacman3.bmp",NULL);
    esquerda[1] = load_bitmap("sprites/pacman33.bmp",NULL);
    cima[0] = load_bitmap("sprites/pacman4.bmp",NULL);
    cima[1] = load_bitmap("sprites/pacman44.bmp",NULL);
    baixo[0] = load_bitmap("sprites/pacman2.bmp",NULL);
    baixo[1] = load_bitmap("sprites/pacman22.bmp",NULL);


    BITMAP *buffer = create_bitmap(600,600);
    BITMAP *sprite_atual = cima[0]; //Ponteiro pro Boneco
    BITMAP *mapa = load_bitmap("sprites/mapa.bmp",NULL); //Ponteiro pro mapa

    int i = 0;
    int tempo_andar = clock();
    int tempo_sprite = clock();
    int pos_x=574,pos_y=530;
    int direcao_atual=2; // 0=direita 1=esquerda 2=cima 3=baixo
    //GAME LOOP
    while (!exit_programa) //Condição para fechar o programa, array Key[estado da tecla]
    {
        //textout_centre_ex(screen,font,"OI ATAIDE, SOU O MELHOR STORM SPIRIT",SCREEN_W/2, SCREEN_H/2,makecol(255,255,255),-1);

        //INPUT
        //Detecta as entradas
            if(key[KEY_ESC]){
              fecha_programa();
            }
            if(key[KEY_D]){
                direcao_atual=0;

            }
            if(key[KEY_S]){
                direcao_atual=3;
            }
            if(key[KEY_A]){
                direcao_atual=1;
            }
            if(key[KEY_W]){
                direcao_atual=2;
            }

            if(clock() - tempo_andar > 5){
                if(direcao_atual==0){
                    pos_x++;
                }
                else if(direcao_atual==1){
                    pos_x--;
                }
                else if(direcao_atual==2){
                    pos_y--;
                }
                else if (direcao_atual==3){
                    pos_y++;
                }
                tempo_andar = clock();
            }

            if(clock() - tempo_sprite > 100){
                i++;
                if(i>1)
                    i=0;
                if(direcao_atual==0){
                    sprite_atual = direita[i];
                }
                else if(direcao_atual==1){
                    sprite_atual = esquerda[i];
                }
                else if(direcao_atual==2){
                    sprite_atual = cima[i];
                }
                else if (direcao_atual==3){
                    sprite_atual = baixo[i];
                }
                tempo_sprite = clock();
            }
            //printf ("tempo:%d clock:%d\n",tempo,clock());


        //UPDATE
        //Atualiza o estado do jogo
        //pos_x++; //Variar a posição do circulo ao longo do tempo

        //DRAW
        //Parte de desenho - Ponteiro para BITMAP que é o "screen", tudo que vc desenhar, aparece na tela

        draw_sprite(buffer,mapa,0,0);
        draw_sprite(buffer,sprite_atual,pos_x,pos_y);
        //draw_sprite_ex(screen,pacman,pos_x,pos_y, DRAW_SPRITE_NORMAL,DRAW_SPRITE_NO_FLIP);
        draw_sprite(screen,buffer,0,0); //Sprite em que eu quero desenhar, buffer na screen
        //clear(buffer);


    }
    //FINALIZAÇÃO
    destroy_bitmap(buffer);
    destroy_bitmap(sprite_atual);
    destroy_bitmap(mapa);



    return 0;
}
END_OF_MAIN() //Tem que botar por questões de compatiblidade
