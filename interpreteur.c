#include "interpreteur.h"
#include "encodageTM.h"

#define IMG_LENGTH 921656

char *capture()
{
    FILE *imageFile = fopen("temp.bmp", "wb");
    char *img;
    if ((img = malloc(IMG_LENGTH * sizeof(char))) == NULL)
    {
        printf("erreur allocation memoire\n");
        return NULL;
    }
    return img;
}

char *interpreteur(mainStruct *main_s)
{
    STRINGLENGTH *string;
    int cnt = 0;
    char *bufferMsg;
    if ((bufferMsg = malloc(100 * sizeof(char))) == NULL)
    {
        printf("erreur allocation mémoire \n");
        return NULL;
    }
    if ((string = malloc(sizeof(STRINGLENGTH))) == NULL)
    {
        printf("erreur allocation mémoire \n");
        return NULL;
    }
    if (main_s->cmd_struct->change_mode == true)
    {
        cnt++;
        switch (main_s->chg_mode_struct->mode)
        {
        case 0:
            // system("cd /home/root/A-Eye-Visor/\n./processIA")
            bufferMsg = "Process IA running";
            string->length = strlen(bufferMsg);
            if ((string->string = malloc(sizeof(char) * string->length)) == NULL)
                printf("erreur allocation memoire \n");
            string->string = bufferMsg;
            bufferMsg = stringEncodedTM(string, 4);
            main_s->buf_f_struct->new_data_f = true;
            break;
        case 1:
            if (main_s->chg_mode_struct->capture == true)
            {
                // TO DO :
                // déclencher une capture manuelle
                main_s->img_s->length = IMG_LENGTH;
                main_s->img_s->capture_f = true;
                bufferMsg = "Capture";
                string->length = strlen(bufferMsg);
                if ((string->string = malloc(sizeof(char) * string->length)) == NULL)
                    printf("erreur allocation memoire \n");
                string->string = bufferMsg;
                bufferMsg = stringEncodedTM(string, 4);
                main_s->buf_f_struct->new_data_f == true;
            }
            else
            {
                bufferMsg = "Mode capture manuelle";
                string->length = strlen(bufferMsg);
                if ((string->string = malloc(sizeof(char) * string->length)) == NULL)
                    printf("erreur allocation memoire \n");
                string->string = bufferMsg;
                bufferMsg = stringEncodedTM(string, 4);
                main_s->buf_f_struct->new_data_f = true;
            }

            break;
        case 2:
            // TO DO :
            // mode vidéo, bonus
            bufferMsg = "Mode video";
            string->length = strlen(bufferMsg);
            if ((string->string = malloc(sizeof(char) * string->length)) == NULL)
                printf("erreur allocation memoire \n");
            string->string = bufferMsg;
            bufferMsg = stringEncodedTM(string, 4);
            main_s->buf_f_struct->new_data_f = true;
            break;
        default:
            break;
        }
    }
    if (main_s->cmd_struct->start == true)
    {
        // TO DO :
        // Sequence d'init
    }
    else
    {
        // TO DO : stop le système
        // bufferMsg = "Closing ...";
        // string->length = strlen(bufferMsg);
        // if ((string->string = malloc(sizeof(char)*string->length)) == NULL)
        //         printf("erreur allocation memoire \n");
        // string->string = bufferMsg;
        // bufferMsg = stringEncodedTM(string, 4);
        // circular_buf_put(main_s->buf_f_struct->cbuf, bufferMsg);
        // main_s->buf_f_struct->new_data_f = true;
    }
    if (main_s->cmd_struct->weights_update == true)
    {
        cnt++;
        // TO DO :
        // charger arch et weights dans IA en c
        // bonus
        bufferMsg = "Chargement des poids";
        string->length = strlen(bufferMsg);
        if ((string->string = malloc(sizeof(char) * string->length)) == NULL)
            printf("erreur allocation memoire \n");
        string->string = bufferMsg;
        bufferMsg = stringEncodedTM(string, 4);
        main_s->buf_f_struct->new_data_f = true;
    }
    if (cnt == 0)
    {
        main_s->buf_f_struct->new_data_f = false;
    }
    return bufferMsg;
}
