#include <GL/glut.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <math.h>
#include "objetos.h"
#include "iluminacao.h"

void desenharChao(void) {
    glNormal3f(0.0, 1.0, 0.0);
    
    float tamanho = 10.0;
    float inicio = -5.0;
    int divisoes = 40;
    float passo = tamanho / divisoes;
    
    srand(12345);
    
    for (int i = 0; i < divisoes; i++) {
        for (int j = 0; j < divisoes; j++) {
            float variacao = (rand() % 20) / 100.0;
            float g = 0.45 + variacao;
            float r = 0.15 + variacao * 0.3;
            float b = 0.1 + variacao * 0.2;
            glColor3f(r, g, b);
            
            float x = inicio + i * passo;
            float z = inicio + j * passo;
            
            glBegin(GL_QUADS);
                glVertex3f(x, 0.0, z);
                glVertex3f(x, 0.0, z + passo);
                glVertex3f(x + passo, 0.0, z + passo);
                glVertex3f(x + passo, 0.0, z);
            glEnd();
        }
    }
}

void desenharBanco(void) {
    glColor3f(0.4, 0.2, 0.1);
    
    glPushMatrix();
        glTranslatef(0.0, 0.5, 0.0);
        glScalef(1.5, 0.1, 0.5);
        glutSolidCube(1.0);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(0.0, 0.85, -0.2);
        glScalef(1.5, 0.6, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(-0.6, 0.25, 0.15);
        glScalef(0.1, 0.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(0.6, 0.25, 0.15);
        glScalef(0.1, 0.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(-0.6, 0.25, -0.15);
        glScalef(0.1, 0.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(0.6, 0.25, -0.15);
        glScalef(0.1, 0.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();
}

void desenharPoste(void) {
    GLUquadric* quad = gluNewQuadric();
    gluQuadricNormals(quad, GLU_SMOOTH);
    
    glPushMatrix();
        glTranslatef(1.5, 0.0, 1.5);
        
        glColor3f(0.1, 0.1, 0.1);
        glPushMatrix();
            glRotatef(-90, 1.0, 0.0, 0.0);
            gluCylinder(quad, 0.08, 0.08, 2.5, 16, 4);
        glPopMatrix();
        
        glPushMatrix();
            glTranslatef(0.0, 2.5, 0.0);
            
            glColor3f(0.1, 0.1, 0.1);
            glPushMatrix();
                glScalef(1.0, 0.3, 1.0);
                glutSolidSphere(0.12, 16, 16);
            glPopMatrix();
            
            if (luzPosteEstaAtiva()) {
                glDisable(GL_LIGHTING);
                glColor3f(1.0, 0.9, 0.4);
                glPushMatrix();
                    glRotatef(-90, 1.0, 0.0, 0.0);
                    gluCylinder(quad, 0.1, 0.08, 0.25, 8, 4);
                glPopMatrix();
                glPushMatrix();
                    glTranslatef(0.0, 0.25, 0.0);
                    glutSolidSphere(0.1, 16, 16);
                glPopMatrix();
                glEnable(GL_LIGHTING);
            } else {
                glColor3f(0.2, 0.2, 0.15);
                glPushMatrix();
                    glRotatef(-90, 1.0, 0.0, 0.0);
                    gluCylinder(quad, 0.1, 0.08, 0.25, 8, 4);
                glPopMatrix();
                glPushMatrix();
                    glTranslatef(0.0, 0.25, 0.0);
                    glutSolidSphere(0.08, 16, 16);
                glPopMatrix();
            }
            
            glColor3f(0.1, 0.1, 0.1);
            glPushMatrix();
                glTranslatef(0.0, 0.3, 0.0);
                glRotatef(-90, 1.0, 0.0, 0.0);
                glutSolidCone(0.12, 0.1, 8, 4);
            glPopMatrix();
            
        glPopMatrix();
        
    glPopMatrix();
    
    gluDeleteQuadric(quad);
}

void desenharArvoreNaPosicao(float x, float z) {
    GLUquadric* quad = gluNewQuadric();
    gluQuadricNormals(quad, GLU_SMOOTH);
    
    glPushMatrix();
        glTranslatef(x, 0.0, z);
        
        glColor3f(0.4, 0.25, 0.1);
        glPushMatrix();
            glRotatef(-90, 1.0, 0.0, 0.0);
            gluCylinder(quad, 0.15, 0.12, 1.2, 16, 4);
        glPopMatrix();
        
        glColor3f(0.1, 0.5, 0.1);
        glPushMatrix();
            glTranslatef(0.0, 1.2, 0.0);
            glRotatef(-90, 1.0, 0.0, 0.0);
            glutSolidCone(0.8, 1.8, 16, 4);
        glPopMatrix();
        
    glPopMatrix();
    
    gluDeleteQuadric(quad);
}

void desenharArvore(void) {
    desenharArvoreNaPosicao(-2.5, 1.5);
    desenharArvoreNaPosicao(-3.5, -2.0);
}

void desenharLixeira(void) {
    GLUquadric* quad = gluNewQuadric();
    gluQuadricNormals(quad, GLU_SMOOTH);
    
    glPushMatrix();
        glTranslatef(1.2, 0.0, 0.5);
        
        glColor3f(0.3, 0.35, 0.3);
        glPushMatrix();
            glRotatef(-90, 1.0, 0.0, 0.0);
            gluCylinder(quad, 0.15, 0.18, 0.5, 16, 4);
        glPopMatrix();
        
        glColor3f(0.2, 0.25, 0.2);
        glPushMatrix();
            glTranslatef(0.0, 0.5, 0.0);
            glRotatef(-90, 1.0, 0.0, 0.0);
            gluDisk(quad, 0.0, 0.18, 16, 4);
        glPopMatrix();
        
        glColor3f(0.15, 0.15, 0.15);
        glPushMatrix();
            glTranslatef(0.0, 0.5, 0.0);
            glScalef(0.4, 0.02, 0.02);
            glutSolidCube(1.0);
        glPopMatrix();
        
    glPopMatrix();
    
    gluDeleteQuadric(quad);
}

void desenharPedras(void) {
    glColor3f(0.5, 0.5, 0.5);
    
    glPushMatrix();
        glTranslatef(3.5, 0.1, 2.0);
        glScalef(0.3, 0.15, 0.25);
        glutSolidSphere(1.0, 12, 12);
    glPopMatrix();
    
    glColor3f(0.55, 0.52, 0.5);
    glPushMatrix();
        glTranslatef(3.8, 0.08, 2.4);
        glScalef(0.2, 0.1, 0.18);
        glutSolidSphere(1.0, 12, 12);
    glPopMatrix();
    
    glColor3f(0.45, 0.45, 0.45);
    glPushMatrix();
        glTranslatef(3.2, 0.12, 2.5);
        glScalef(0.25, 0.18, 0.22);
        glutSolidSphere(1.0, 12, 12);
    glPopMatrix();
    
    glColor3f(0.5, 0.48, 0.45);
    glPushMatrix();
        glTranslatef(-1.5, 0.08, -3.0);
        glScalef(0.2, 0.12, 0.2);
        glutSolidSphere(1.0, 12, 12);
    glPopMatrix();
    
    glColor3f(0.52, 0.5, 0.48);
    glPushMatrix();
        glTranslatef(-1.0, 0.1, -3.3);
        glScalef(0.28, 0.14, 0.24);
        glutSolidSphere(1.0, 12, 12);
    glPopMatrix();
}

void desenharLago(void) {
    GLUquadric* quad = gluNewQuadric();
    gluQuadricNormals(quad, GLU_SMOOTH);
    
    glPushMatrix();
        glTranslatef(3.0, 0.01, -1.5);
        
        glColor3f(0.2, 0.4, 0.6);
        glRotatef(-90, 1.0, 0.0, 0.0);
        gluDisk(quad, 0.0, 1.2, 32, 8);
        
    glPopMatrix();
    
    glColor3f(0.4, 0.35, 0.3);
    
    int numPedras = 12;
    float raio = 1.25;
    for (int i = 0; i < numPedras; i++) {
        float angulo = (2.0 * 3.14159 * i) / numPedras;
        float px = 3.0 + raio * cos(angulo);
        float pz = -1.5 + raio * sin(angulo);
        float tamanho = 0.1 + (i % 3) * 0.03;
        
        glPushMatrix();
            glTranslatef(px, 0.05, pz);
            glScalef(tamanho, 0.06, tamanho);
            glutSolidSphere(1.0, 8, 8);
        glPopMatrix();
    }
    
    gluDeleteQuadric(quad);
}