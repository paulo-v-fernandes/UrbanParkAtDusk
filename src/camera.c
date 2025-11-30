#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>
#include "camera.h"

static float anguloHorizontal = 45.0;
static float anguloVertical = 20.0;
static float distancia = 8.0;

void configurarProjecao(void) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 800.0/600.0, 0.1, 100.0);
}

void configurarCamera(void) {
    float rad_h = anguloHorizontal * 3.14159 / 180.0;
    float rad_v = anguloVertical * 3.14159 / 180.0;
    
    float x = distancia * cos(rad_v) * sin(rad_h);
    float y = distancia * sin(rad_v);
    float z = distancia * cos(rad_v) * cos(rad_h);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x, y, z,
              0.0, 0.5, 0.0,
              0.0, 1.0, 0.0);
}

void moverCameraEsquerda(void) {
    anguloHorizontal += 5.0;
}

void moverCameraDireita(void) {
    anguloHorizontal -= 5.0;
}

void moverCameraCima(void) {
    if (anguloVertical < 80.0) {
        anguloVertical += 5.0;
    }
}

void moverCameraBaixo(void) {
    if (anguloVertical > 5.0) {
        anguloVertical -= 5.0;
    }
}