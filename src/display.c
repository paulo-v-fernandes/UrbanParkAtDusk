#include <GL/glut.h>
#include "display.h"
#include "camera.h"
#include "objetos.h"
#include "iluminacao.h"

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    configurarCamera();
    atualizarLuzes();
    desenharChao();
    desenharBanco();
    desenharPoste();
    desenharArvore();
    desenharLixeira();
    desenharPedras();
    desenharLago();
    glFlush();
    glutSwapBuffers();
}