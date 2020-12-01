#include <stdio.h>
#include <unistd.h>
#include "assets/assets.c"
#include "ADT/boolean.h"
#include "string.h"



// $ ***** Variables *****
char menu[100];
boolean Exit;       // = false;
boolean ExitMenu;   // = false;
boolean EndTurn;    // = false;
boolean AksiValid;	// = true


int main() {
    do {
        Exit = false;
        puts("");
        MainProgram();
        printf("\n");
        do {
            ExitMenu = false;
            MainMenu();
            // * Lakukan Input dengan 'mesinkata'
            int idxMenu = 0;
            do {
                scanf("%c", menu + idxMenu);
            } while (menu[idxMenu++] != '\n');
            menu[--idxMenu] = '\0';

                // $ ######### TUTORIAL ########
            if (strcmp(menu,"OVERVIEW") == 0) {
                printf("\n");
                // todo Tutorial1();
                puts("");
                printf("#COBA TEKAN ENTER#\n");
                getchar();
                puts("");
                printf("Pak Santo adalah seorang mahasiswa informatika yang sangat senang memprogram. Selama\n");
                printf("berkuliah, beliau sangat menikmati berbagai aktivitas belajar dan sangat berniat mengerjakan\n");
                printf("tugas. Namun, seiring berjalannya waktu, beliau lelah terhadap berbagai tugas yang diberikan\n");
                printf("karena tidak sesuai dengan minat asli beliau. Oleh sebab itu, pada tahun terakhir kuliahnya, beliau\n");
                printf("memutuskan untuk mengerjakan skripsi dengan seadanya dan fokus untuk lulus secepat mungkin.\n");
                printf("Setelah Pak Santo lulus, beliau pun memutuskan untuk membuka toko komputer saja karena\n");
                printf("sudah terlanjur kehilangan minat terhadap dunia pemrograman.\n");
                sleep(1);
                puts("");
                // todo Tutorial2();
                printf("#TEKAN ENTER LAGI UNTUK KEMBALI#\n");
                getchar();
                puts("");
                ExitMenu = true;

            }   // $ ######### CREDITS ########
            else if (strcmp(menu, "CREDITS") == 0) {
                puts("");
                Credits();
                getchar();
                ExitMenu = true;

            }   // $ ######### QUIT ########
            else if (strcmp(menu, "QUIT") == 0) {
                Quit();
                ExitMenu = true;
                Exit = true;
            }
            // ######### PLAY #########
            else if (strcmp(menu, "PLAY") == 0) {
                puts("");
                Loading();
                sleep(1);
                printf("||||||||||");
                sleep(1);
                printf("|||||||||||||||||||||||||");
                sleep(1);
                printf("|||");
                sleep(1);
                printf("||||||||||||||||");
                sleep(1);
                printf("||||||||||||||||||||");
                sleep(1);
                printf("|||||");
                sleep(1);
                printf("\n\nLoading complete!\n\n");
                sleep(1);
                printf("Tekan enter untuk melanjutkan.\n\n");
                sleep(1);
                printf("Programnya belum ada isinya cuy aokwokowakowa. enter lagi sana.\n\n");
                puts("");
                getchar();
                COMMAND();
                ExitMenu = true;
            }

            else {
                Invalid();
                getchar();
            }

        } while (!ExitMenu);
        ExitMenu = false;
    } while (!Exit);
    return 0;
}

void COMMAND(){
    char com[20];

    printf ("ENTER COMMAND : ");
    scanf ("%s", &com);
    
    if (strcmp(com, "MOV") == 0){
        MOVE();
    }else if (strcmp(com, 'STATUS') == 0){
        STATUS();
    }else if (strcmp(com, 'CHECKORDER') == 0){
        CHECKORDER();
    }else if (strcmp(com, 'STARTBUILD') == 0){
        STARTBUILD();
    }else if (strcmp(com, 'FINISHBUILD') == 0){
        FINISHBUILD();
    }else if (strcmp(com, 'ADDCOMPONENT') == 0){
        ADDCOMPONENT();
    }else if (strcmp(com, 'REMOVECOMPONENT') == 0){
        REMOVECOMPONENT();
    }else if (strcmp(com, 'SHOP') == 0){
        SHOP();
    }else if (strcmp(com, 'DELIVER') == 0){
        DELIVER();
    }else if (strcmp(com, 'END_DAY') == 0){
        END_DAY();
    }else if (strcmp(com, 'SAVE') == 0){
        SAVE();
    }else if (strcmp(com, 'MAP') == 0){
        MAP();
    }else if (strcmp(com, 'EXIT') == 0){
        EXIT();
    }else {
        printf("ENTER COMMAND : ");
        scanf("%s", &com);
    }
    return 0;
}