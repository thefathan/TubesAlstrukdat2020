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