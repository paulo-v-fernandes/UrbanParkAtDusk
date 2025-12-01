#include <GL/glut.h>
#include "init.h"
#include "display.h"
#include "teclado.h"

// Função principal
int main(int argc, char** argv) {
    // Inicializa o GLUT
    glutInit(&argc, argv);
    
    // Configura buffer duplo, cores RGB e buffer de profundidade
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    // Define janela
    glutInitWindowSize(800, 600);
    glutCreateWindow("Parque Urbano ao Entardecer");
    
    // Configura OpenGL (profundidade, iluminação, projeção)
    inicializar();
    
    // Registra função de desenho
    glutDisplayFunc(display);
    
    // Registra função para teclas normais (A, S, Esc)
    glutKeyboardFunc(tecladoNormal);
    
    // Registra função para teclas especiais (setas)
    glutSpecialFunc(tecladoEspecial);
    
    // Inicia loop principal de eventos
    glutMainLoop();
    
    return 0;
}