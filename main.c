#include <allegro.h>
#include <time.h>
#include <stdio.h>
#define MAX_X 555
#define MAX_Y 515
#define MIN_XY 15
#define VELOCIDADE 10 //quanto menor, mais rápido
#define VELOCIDADE_SPRITE 100

typedef struct comida{
    int x;
    int y;
    int desenhar;
}Comida;
volatile int exit_programa = FALSE; //Tambem pode ser while(!exit_program) ali no while, ao invés de !key[KEY_ESC]
void fecha_programa() {exit_programa=TRUE;}
int trilho(int x,int y){
    //y = -y;
    //ANDAR NAS CORDENADAS X

    if(x==MAX_X){
        if((y<=MAX_Y && y>=460) || (y<=410 && y>=353) || y==245 || (y<=141 && y>=MIN_XY))
            return 1;
    }

    else if(x==512){
        if((y<=460 && y>=410))
            return 1;
    }

    else if(x==450){
        if((y<=460 && y>=MIN_XY))
            return 1;
    }

    else if(x==385){
        if((y<=460 && y>=410) || (y<=353 && y>=194) || (y<=141 && y>=90))
            return 1;
    }

    else if(x==318){
        if((y<=MAX_Y && y>=460) || (y<=410 && y>=353) || (y<=194 && y>=141) || (y<=90 && y>=MIN_XY))
            return 1;
    }

    else if(x==257){
        if((y<=MAX_Y && y>=460) || (y<=410 && y>=353) || (y<=194 && y>=141) || (y<=90 && y>=MIN_XY))
            return 1;
    }

    else if(x==187){
        if((y<=460 && y>=410) || (y<=353 && y>=194) || (y<=141 && y>=90))
            return 1;
    }

    else if(x==123){
        if((y<=460 && y>=MIN_XY))
            return 1;
    }

    else if(x==61){
        if((y<=460 && y>=410))
            return 1;
    }

    else if(x==MIN_XY){
        if((y<=MAX_Y && y>=460) || (y<=410 && y>=353) || y==245 || (y<=141 && y>=MIN_XY))
            return 1;
    }

    //ANDAR NAS CORDENADAS Y

    if(y==MAX_Y){
        if(x<=MAX_X && x>=MIN_XY)
            return 1;
    }
    else if(y==460){
        if((x<=MAX_X && x>=450) || (x<=385 && x>=318) || (x<=257 && x>=187) || (x<=123 && x>=MIN_XY))
            return 1;
    }
    else if(y==410){
        if((x<=MAX_X && x>=512) || (x<=450 && x>=123) || (x<=61 && x>=MIN_XY))
            return 1;
    }
    else if(y==353){
        if((x<=MAX_X && x>=318) || (x<=257 && x>=MIN_XY) || (x<=61 && x>=MIN_XY))
            return 1;
    }

    else if(y==300){
        if((x<=385 && x>=187))
            return 1;
    }

    else if(y==248){
        if((x<=MAX_X && x>=385) ||(x<=187 && x>=MIN_XY) )
            return 1;
    }

    else if(y==194){
        if((x<=385 && x>=187))
            return 1;
    }

    else if(y==141){
        if((x<=MAX_X && x>=450) || (x<=385 && x>=318) || (x<=257 && x>=187)|| (x<=123 && x>=MIN_XY))
            return 1;
    }

    else if(y==90){
        if((x<=MAX_X && x>=MIN_XY))
            return 1;
    }

    else if(y==MIN_XY){
        if((x<=MAX_X && x>=318) || (x<=257 && x>=MIN_XY))
            return 1;
    }

    return 0;
}
void setarPixelComidas (Comida * comidas){
    //int i, j=15, k=15, r=15, s=15, t=153, u=15, v=318, w=318;
    comidas[0].x = 15;
    comidas[0].y = 520;
    comidas[0].desenhar=1;
    comidas[1].x = 45;
    comidas[1].y = 520;
    comidas[1].desenhar=1;
    comidas[2].x = 75;
    comidas[2].y = 520;
    comidas[2].desenhar=1;
    comidas[3].x = 105;
    comidas[3].y = 520;
    comidas[3].desenhar=1;
    comidas[4].x = 135;
    comidas[4].y = 520;
    comidas[4].desenhar=1;
    comidas[5].x = 165;
    comidas[5].y = 520;
    comidas[5].desenhar=1;
    comidas[6].x = 195;
    comidas[6].y = 520;
    comidas[6].desenhar=1;
    comidas[7].x = 225;
    comidas[7].y = 520;
    comidas[7].desenhar=1;
    comidas[8].x = 255;
    comidas[8].y = 520;
    comidas[8].desenhar=1;
    comidas[9].x = 285;
    comidas[9].y = 520;
    comidas[9].desenhar=1;
    comidas[10].x = 315;
    comidas[10].y = 520;
    comidas[10].desenhar=1;
    comidas[11].x = 345;
    comidas[11].y = 520;
    comidas[11].desenhar=1;
    comidas[12].x = 375;
    comidas[12].y = 520;
    comidas[12].desenhar=1;
    comidas[13].x = 405;
    comidas[13].y = 520;
    comidas[13].desenhar=1;
    comidas[14].x = 435;
    comidas[14].y = 520;
    comidas[14].desenhar=1;
    comidas[15].x = 465;
    comidas[15].y = 520;
    comidas[15].desenhar=1;
    comidas[16].x = 495;
    comidas[16].y = 520;
    comidas[16].desenhar=1;
    comidas[17].x = 525;
    comidas[17].y = 520;
    comidas[17].desenhar=1;
    comidas[18].x = 555;
    comidas[18].y = 520;
    comidas[18].desenhar=1;
    /*comidas[19].x = 450;
    comidas[19].y = 15;
    comidas[19].desenhar=1;*/
    comidas[20].x = 450;
    comidas[20].y = 45;
    comidas[20].desenhar=1;
    comidas[21].x = 450;
    comidas[21].y = 75;
    comidas[21].desenhar=1;
    comidas[22].x = 450;
    comidas[22].y = 105;
    comidas[22].desenhar=1;
    comidas[23].x = 450;
    comidas[23].y = 135;
    comidas[23].desenhar=1;
    comidas[24].x = 450;
    comidas[24].y = 165;
    comidas[24].desenhar=1;
    comidas[25].x = 450;
    comidas[25].y = 195;
    comidas[25].desenhar=1;
    comidas[26].x = 450;
    comidas[26].y = 225;
    comidas[26].desenhar=1;
    comidas[27].x = 450;
    comidas[27].y = 255;
    comidas[27].desenhar=1;
    comidas[28].x = 450;
    comidas[28].y = 285;
    comidas[28].desenhar=1;
    comidas[29].x = 450;
    comidas[29].y = 315;
    comidas[29].desenhar=1;
    comidas[30].x = 450;
    comidas[30].y = 345;
    comidas[30].desenhar=1;
    comidas[31].x = 450;
    comidas[31].y = 375;
    comidas[31].desenhar=1;
    comidas[32].x = 450;
    comidas[32].y = 405;
    comidas[32].desenhar=1;
    comidas[33].x = 450;
    comidas[33].y = 435;
    comidas[33].desenhar=1;
    comidas[34].x = 450;
    comidas[34].y = 465;
    comidas[34].desenhar=1;
    comidas[35].x = 123;
    comidas[35].y = 15;
    comidas[35].desenhar=1;
    comidas[36].x = 123;
    comidas[36].y = 45;
    comidas[36].desenhar=1;
    comidas[37].x = 123;
    comidas[37].y = 75;
    comidas[37].desenhar=1;
    comidas[38].x = 123;
    comidas[38].y = 105;
    comidas[38].desenhar=1;
    comidas[39].x = 123;
    comidas[39].y = 135;
    comidas[39].desenhar=1;
    comidas[40].x = 123;
    comidas[40].y = 165;
    comidas[40].desenhar=1;
    comidas[41].x = 123;
    comidas[41].y = 195;
    comidas[41].desenhar=1;
    comidas[42].x = 123;
    comidas[42].y = 225;
    comidas[42].desenhar=1;
    comidas[43].x = 123;
    comidas[43].y = 255;
    comidas[43].desenhar=1;
    comidas[44].x = 123;
    comidas[44].y = 285;
    comidas[44].desenhar=1;
    comidas[45].x = 123;
    comidas[45].y = 315;
    comidas[45].desenhar=1;
    comidas[46].x = 123;
    comidas[46].y = 345;
    comidas[46].desenhar=1;
    comidas[47].x = 123;
    comidas[47].y = 375;
    comidas[47].desenhar=1;
    comidas[48].x = 123;
    comidas[48].y = 405;
    comidas[48].desenhar=1;
    comidas[49].x = 123;
    comidas[49].y = 435;
    comidas[49].desenhar=1;
    comidas[50].x = 123;
    comidas[50].y = 465;
    comidas[50].desenhar=1;
    comidas[51].x = 15;
    comidas[51].y = 90;
    comidas[51].desenhar=1;
    comidas[52].x = 45;
    comidas[52].y = 90;
    comidas[52].desenhar=1;
    comidas[53].x = 75;
    comidas[53].y = 90;
    comidas[53].desenhar=1;
    comidas[54].x = 105;
    comidas[54].y = 90;
    comidas[54].desenhar=1;
    comidas[55].x = 135;
    comidas[55].y = 90;
    comidas[55].desenhar=1;
    comidas[56].x = 165;
    comidas[56].y = 90;
    comidas[56].desenhar=1;
    comidas[57].x = 195;
    comidas[57].y = 90;
    comidas[57].desenhar=1;
    comidas[58].x = 225;
    comidas[58].y = 90;
    comidas[58].desenhar=1;
    comidas[59].x = 255;
    comidas[59].y = 90;
    comidas[59].desenhar=1;
    comidas[60].x = 285;
    comidas[60].y = 90;
    comidas[60].desenhar=1;
    comidas[61].x = 315;
    comidas[61].y = 90;
    comidas[61].desenhar=1;
    comidas[62].x = 345;
    comidas[62].y = 90;
    comidas[62].desenhar=1;
    comidas[63].x = 375;
    comidas[63].y = 90;
    comidas[63].desenhar=1;
    comidas[64].x = 405;
    comidas[64].y = 90;
    comidas[64].desenhar=1;
    comidas[65].x = 435;
    comidas[65].y = 90;
    comidas[65].desenhar=1;
    comidas[66].x = 465;
    comidas[66].y = 90;
    comidas[66].desenhar=1;
    comidas[67].x = 495;
    comidas[67].y = 90;
    comidas[67].desenhar=1;
    comidas[68].x = 525;
    comidas[68].y = 90;
    comidas[68].desenhar=1;
    comidas[69].x = 555;
    comidas[69].y = 90;
    comidas[69].desenhar=1;
    comidas[70].x = 153;
    comidas[70].y = 410;
    comidas[70].desenhar=1;
    comidas[71].x = 183;
    comidas[71].y = 410;
    comidas[71].desenhar=1;
    comidas[72].x = 213;
    comidas[72].y = 410;
    comidas[72].desenhar=1;
    comidas[73].x = 243;
    comidas[73].y = 410;
    comidas[73].desenhar=1;
    comidas[74].x = 273;
    comidas[74].y = 410;
    comidas[74].desenhar=1;
    comidas[75].x = 303;
    comidas[75].y = 410;
    comidas[75].desenhar=1;
    comidas[76].x = 333;
    comidas[76].y = 410;
    comidas[76].desenhar=1;
    comidas[77].x = 363;
    comidas[77].y = 410;
    comidas[77].desenhar=1;
    comidas[78].x = 393;
    comidas[78].y = 410;
    comidas[78].desenhar=1;
    comidas[79].x = 423;
    comidas[79].y = 410;
    comidas[79].desenhar=1;
    comidas[80].x = 15;
    comidas[80].y = 360;
    comidas[80].desenhar=1;
    comidas[81].x = 45;
    comidas[81].y = 360;
    comidas[81].desenhar=1;
    comidas[82].x = 75;
    comidas[82].y = 360;
    comidas[82].desenhar=1;
    comidas[83].x = 105;
    comidas[83].y = 360;
    comidas[83].desenhar=1;
    comidas[84].x = 135;
    comidas[84].y = 360;
    comidas[84].desenhar=1;
    comidas[85].x = 165;
    comidas[85].y = 360;
    comidas[85].desenhar=1;
    comidas[86].x = 195;
    comidas[86].y = 360;
    comidas[86].desenhar=1;
    comidas[87].x = 225;
    comidas[87].y = 360;
    comidas[87].desenhar=1;
    comidas[88].x = 255;
    comidas[88].y = 360;
    comidas[88].desenhar=1;
    comidas[89].x = 318;
    comidas[89].y = 360;
    comidas[89].desenhar=1;
    comidas[90].x = 348;
    comidas[90].y = 360;
    comidas[90].desenhar=1;
    comidas[91].x = 378;
    comidas[91].y = 360;
    comidas[91].desenhar=1;
    comidas[92].x = 408;
    comidas[92].y = 360;
    comidas[92].desenhar=1;
    /*comidas[93].x = 438;
    comidas[93].y = 360;
    comidas[93].desenhar=1;*/
    comidas[94].x = 468;
    comidas[94].y = 360;
    comidas[94].desenhar=1;
    comidas[95].x = 498;
    comidas[95].y = 360;
    comidas[95].desenhar=1;
    comidas[96].x = 528;
    comidas[96].y = 360;
    comidas[96].desenhar=1;
    comidas[97].x = 558;
    comidas[97].y = 360;
    comidas[97].desenhar=1;
    comidas[98].x = 318;
    comidas[98].y = 20;
    comidas[98].desenhar=1;
    comidas[99].x = 348;
    comidas[99].y = 20;
    comidas[99].desenhar=1;
    comidas[100].x = 378;
    comidas[100].y = 20;
    comidas[100].desenhar=1;
    comidas[101].x = 408;
    comidas[101].y = 20;
    comidas[101].desenhar=1;
    comidas[102].x = 438;
    comidas[102].y = 20;
    comidas[102].desenhar=1;
    comidas[103].x = 468;
    comidas[103].y = 20;
    comidas[103].desenhar=1;
    comidas[104].x = 498;
    comidas[104].y = 20;
    comidas[104].desenhar=1;
    comidas[105].x = 528;
    comidas[105].y = 20;
    comidas[105].desenhar=1;
    comidas[106].x = 558;
    comidas[106].y = 20;
    comidas[106].desenhar=1;
    comidas[107].x = 555;
    comidas[107].y = 460;
    comidas[107].desenhar=1;
}
int trilho1(int x, int y){
    printf ("X:%d Y:%d\n",x,y);
    if(y<0 || y>530 || x<0 || x>574)
        return 0;
    return 1;

}
void retirarTrilho(Comida * comida, int x, int y){
    if((comida->x >= x-5 && comida->x <= x+15) && (comida->y >= y-5 && comida->y <= y+15))
        comida->desenhar=0;
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
    BITMAP *comida = load_bitmap("sprites/comida.bmp",NULL);//Ponteiro pra comida
    BITMAP *mapa = load_bitmap("sprites/mapa.bmp",NULL); //Ponteiro pro mapa

    int i = 0;
    int tempo_andar = clock();
    int tempo_sprite = clock();
    int pos_x=555,pos_y=515;
    int direcao_atual=2; // 0=direita 1=esquerda 2=cima 3=baixo
    //GAME LOOP

    //CRIAR VETOR DO TAMANHO DE COMIDAS
    int quantidade_comidas=108;
    Comida comidas[quantidade_comidas];

    setarPixelComidas(comidas);




    while (!exit_programa) //Condição para fechar o programa, array Key[estado da tecla]
    {
        //textout_centre_ex(screen,font,"OI ATAIDE, SOU O MELHOR STORM SPIRIT",SCREEN_W/2, SCREEN_H/2,makecol(255,255,255),-1);

        //INPUT
        //Detecta as entradas
            if(key[KEY_ESC]){
              fecha_programa();
            }

            if(key[KEY_D]){
                if(trilho(pos_x+1,pos_y))
                    direcao_atual=0;
            }

            if(key[KEY_S]){
                if(trilho(pos_x,pos_y+1))
                    direcao_atual=3;
            }
            if(key[KEY_A]){
                if(trilho(pos_x-1,pos_y))
                    direcao_atual=1;
            }
            if(key[KEY_W]){
                if(trilho(pos_x,pos_y-1))
                    direcao_atual=2;
            }


            if(clock() - tempo_andar > VELOCIDADE){
                printf ("X:%d Y:%d\n",pos_x,pos_y);
                if(direcao_atual==0){
                    if(trilho(pos_x+1,pos_y))
                        pos_x++;
                }
                else if(direcao_atual==1){
                    if(trilho(pos_x-1,pos_y))
                        pos_x--;
                }
                else if(direcao_atual==2){
                    if(trilho(pos_x,pos_y-1))
                        pos_y--;
                }
                else if (direcao_atual==3){
                    if(trilho(pos_x,pos_y+1))
                        pos_y++;
                }

                tempo_andar = clock();
            }

            if(clock() - tempo_sprite > VELOCIDADE_SPRITE){
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
        int j;

            //printf ("tempo:%d clock:%d\n",tempo,clock());


        //UPDATE
        //Atualiza o estado do jogo
        //pos_x++; //Variar a posição do circulo ao longo do tempo

        //DRAW
        //Parte de desenho - Ponteiro para BITMAP que é o "screen", tudo que vc desenhar, aparece na tela

        draw_sprite(buffer,mapa,0,0);

        for (j=0;j<quantidade_comidas;j++){
            retirarTrilho(&comidas[j],pos_x,pos_y);
            if(comidas[j].desenhar)
                draw_sprite(buffer,comida,comidas[j].x+5,comidas[j].y);
        }

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
