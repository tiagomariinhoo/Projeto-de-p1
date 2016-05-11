#include <allegro.h>
#include <time.h>
#include <stdio.h>
#define MAX_X 555
#define MAX_Y 515
#define MIN 15

volatile int exit_programa = FALSE; //Tambem pode ser while(!exit_program) ali no while, ao invés de !key[KEY_ESC]
void fecha_programa() {exit_programa=TRUE;}
int trilho(int * x,int * y){
    //y = -y;
    printf ("X:%d Y:%d\n",*x,*y);
    //ANDAR NAS CORDENADAS X

    if((*x)==MAX_X){
        if(((*y)<=MAX_Y && (*y)>=460) || ((*y)<=410 && (*y)>=353) || (*y)==245 || ((*y)<=141 && (*y)>=MIN))
            return 1;
    }

    else if((*x)==512){
        if(((*y)<=460 && (*y)>=410))
            return 1;
    }

    else if((*x)==450){
        if(((*y)<=460 && (*y)>=MIN))
            return 1;
    }

    else if((*x)==385){
        if(((*y)<=460 && (*y)>=410) || ((*y)<=354 && (*y)>=194) || ((*y)<=141 && (*y)>=90))
            return 1;
    }

    else if((*x)==318){
        if(((*y)<=MAX_Y && (*y)>=460) || ((*y)<=410 && (*y)>=354) || ((*y)<=194 && (*y)>=141) || ((*y)<=90 && (*y)>=MIN))
            return 1;
    }

    else if((*x)==257){
        if(((*y)<=MAX_Y && (*y)>=460) || ((*y)<=410 && (*y)>=354) || ((*y)<=194 && (*y)>=141) || ((*y)<=90 && (*y)>=MIN))
            return 1;
    }

    else if((*x)==187){
        if(((*y)<=460 && (*y)>=410) || ((*y)<=354 && (*y)>=194) || ((*y)<=141 && (*y)>=90))
            return 1;
    }

    else if((*x)==123){
        if(((*y)<=460 && (*y)>=MIN))
            return 1;
    }

    else if((*x)==61){
        if(((*y)<=460 && (*y)>=410))
            return 1;
    }

    else if((*x)==MIN){
        if(((*y)<=MAX_Y && (*y)>=460) || ((*y)<=410 && (*y)>=353) || (*y)==245 || ((*y)<=141 && (*y)>=MIN))
            return 1;
    }

    //ANDAR NAS CORDENADAS Y

    if((*y)==MAX_Y){
        if((*x)<=MAX_X && (*x)>=MIN)
            return 1;
    }
    else if((*y)==460){
        if(((*x)<=MAX_X && (*x)>=450) || ((*x)<=385 && (*x)>=318) || ((*x)<=257 && (*x)>=187) || ((*x)<=123 && (*x)>=MIN))
            return 1;
    }
    else if((*y)==410){
        if(((*x)<=MAX_X && (*x)>=512) || ((*x)<=450 && (*x)>=123) || ((*x)<=61 && (*x)>=MIN))
            return 1;
    }
    else if((*y)==353){
        if(((*x)<=MAX_X && (*x)>=318) || ((*x)<=257 && (*x)>=MIN) || ((*x)<=61 && (*x)>=MIN))
            return 1;
    }

    else if((*y)==300){
        if(((*x)<=385 && (*x)>=187))
            return 1;
    }

    else if((*y)==248){
        if(((*x)<=MAX_X && (*x)>=385) ||((*x)<=187 && (*x)>=MIN) )
            return 1;
    }

    else if((*y)==194){
        if(((*x)<=385 && (*x)>=187))
            return 1;
    }

    else if((*y)==141){
        if(((*x)<=MAX_X && (*x)>=450) || ((*x)<=385 && (*x)>=318) || ((*x)<=257 && (*x)>=187)|| ((*x)<=123 && (*x)>=MIN))
            return 1;
    }

    else if((*y)==88){
        if(((*x)<=MAX_X && (*x)>=MIN))
            return 1;
    }

    else if((*y)==MIN){
        if(((*x)<=MAX_X && (*x)>=318) || ((*x)<=257 && (*x)>=MIN))
            return 1;
    }



    return 0;
}

int trilho1(int x, int y){
    printf ("X:%d Y:%d\n",x,y);
    if(y<0 || y>530 || x<0 || x>574)
        return 0;
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
    int pos_x=555,pos_y=515;
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

            if(clock() - tempo_andar > 20){
                if(direcao_atual==0){
                    pos_x++;
                    if(!trilho(&pos_x,&pos_y))
                        pos_x--;
                }
                else if(direcao_atual==1){
                    pos_x--;
                    if(!trilho(&pos_x,&pos_y))
                        pos_x++;
                }
                else if(direcao_atual==2){
                    pos_y--;
                    if(!trilho(&pos_x,&pos_y))
                        pos_y++;
                }
                else if (direcao_atual==3){
                    pos_y++;
                    if(!trilho(&pos_x,&pos_y))
                        pos_y--;
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
