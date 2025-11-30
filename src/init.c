#include <GL/glut.h>
#include "init.h"
#include "camera.h"
#include "iluminacao.h"

void inicializar(void) {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.5, 0.6, 0.8, 1.0);
    configurarProjecao();
    inicializarIluminacao();
}