#include <GL/glut.h>
#include <stdlib.h>
#include "teclado.h"
#include "iluminacao.h"
#include "camera.h"

void tecladoNormal(unsigned char tecla, int x, int y) {
    switch (tecla) {
        case 'a':
        case 'A':
            alternarLuzPoste();
            break;
        case 's':
        case 'S':
            alternarLuzSol();
            break;
        case 27:
            exit(0);
            break;
    }
    glutPostRedisplay();
}

void tecladoEspecial(int tecla, int x, int y) {
    switch (tecla) {
        case GLUT_KEY_LEFT:
            moverCameraEsquerda();
            break;
        case GLUT_KEY_RIGHT:
            moverCameraDireita();
            break;
        case GLUT_KEY_UP:
            moverCameraCima();
            break;
        case GLUT_KEY_DOWN:
            moverCameraBaixo();
            break;
    }
    glutPostRedisplay();
}