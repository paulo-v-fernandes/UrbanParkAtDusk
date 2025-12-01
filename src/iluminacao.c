#include <GL/glut.h>
#include "iluminacao.h"

static int luzPosteAtiva = 1;
static int luzSolAtiva = 1;

void inicializarIluminacao(void) {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    
    GLfloat luzAmbienteGlobal[] = {0.2, 0.15, 0.1, 1.0};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbienteGlobal);
}

void atualizarLuzes(void) {
    if (luzSolAtiva) {
        glEnable(GL_LIGHT0);
        GLfloat posicaoSol[] = {-5.0, 3.0, 0.0, 0.0};
        GLfloat corSol[] = {1.0, 0.6, 0.3, 1.0};
        GLfloat ambienteSol[] = {0.3, 0.2, 0.1, 1.0};
        glLightfv(GL_LIGHT0, GL_POSITION, posicaoSol);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, corSol);
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambienteSol);
    } else {
        glDisable(GL_LIGHT0);
    }
    
    if (luzPosteAtiva) {
        glEnable(GL_LIGHT1);
        GLfloat posicaoPoste[] = {1.5, 2.75, 1.5, 1.0};
        
        float intensidade = luzSolAtiva ? 1.0 : 1.8;
        GLfloat corPoste[] = {1.0 * intensidade, 0.9 * intensidade, 0.6 * intensidade, 1.0};
        GLfloat ambientePoste[] = {0.15 * intensidade, 0.12 * intensidade, 0.08 * intensidade, 1.0};
        
        glLightfv(GL_LIGHT1, GL_POSITION, posicaoPoste);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, corPoste);
        glLightfv(GL_LIGHT1, GL_AMBIENT, ambientePoste);
        glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0);
        glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.05);
        glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.01);
    } else {
        glDisable(GL_LIGHT1);
    }
}

void alternarLuzPoste(void) {
    luzPosteAtiva = !luzPosteAtiva;
}

void alternarLuzSol(void) {
    luzSolAtiva = !luzSolAtiva;
}

int luzPosteEstaAtiva(void) {
    return luzPosteAtiva;
}

int luzSolEstaAtiva(void) {
    return luzSolAtiva;
}