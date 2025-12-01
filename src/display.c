#include <GL/glut.h>
#include "display.h"
#include "camera.h"
#include "objetos.h"
#include "iluminacao.h"

void display(void) {
    if (luzSolEstaAtiva()) {
        glClearColor(0.5, 0.6, 0.8, 1.0);
    } else {
        glClearColor(0.02, 0.02, 0.1, 1.0);
    }
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    configurarCamera();
    atualizarLuzes();
    desenharSol();
    desenharChao();
    desenharSombras();
    desenharBanco();
    desenharPoste();
    desenharArvore();
    desenharLixeira();
    desenharPedras();
    desenharLago();
    glFlush();
    glutSwapBuffers();
}