
/* Vorlagedatei zu E1 Aufgabe 6 (Speicherverwaltung) */
/* 17.06.05/gle */


#include <stdlib.h>
#include <stdio.h>

int main() {
    unsigned int cam[12] = {0xf83c, 0x0a93, 0xda1f, 0x093a, 0x8f1d, 0x4444, 0x9269, 0xc645, 0xaffe, 0x0000, 0x7e3b, 0x038a};
    bool valid[12] = {0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1};
    unsigned int muster, maske;

    printf("Bitte Musterwert eingeben: ");
    scanf("%x", &muster);
    printf("\nBitte Maskenwert eingeben: ");
    scanf("%x", &maske);
    printf("\n");

    for (int i = 0; i <= 12; i++) {
        if (valid[i]) {
            if ((muster & maske) == (cam[i] & maske)) {
                printf("Gueltiger wert gefunden: index %i, 0x%x\n", i, cam[i]);
            }
        }
    }


    return 0;
}
