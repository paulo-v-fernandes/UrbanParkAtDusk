#include <GL/glut.h>
#include "init.h"
#include "display.h"
#include "teclado.h"

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Parque Urbano ao Entardecer");
    inicializar();
    glutDisplayFunc(display);
    glutKeyboardFunc(tecladoNormal);
    glutSpecialFunc(tecladoEspecial);
    glutMainLoop();
    return 0;
}