# Parque Urbano ao Entardecer

Construção de Cena 3D

## Descrição

Este projeto consiste em uma cena tridimensional interativa que simula um pequeno parque urbano ao entardecer. A cena foi desenvolvida utilizando OpenGL com a biblioteca GLUT para gerenciamento de janelas e entrada do usuário.

## Elementos da Cena

- Chão gramado com variação de cores simulando textura natural
- Banco de praça com assento, encosto e pernas
- Poste de iluminação com lanterna elaborada
- Duas árvores com tronco e copa
- Lixeira ao lado do banco
- Lago com borda de pedras decorativas
- Pedras espalhadas pelo ambiente
- Céu azul de entardecer

## Controles

| Tecla | Ação |
|-------|------|
| A | Liga/desliga luz do poste |
| S | Liga/desliga luz direcional (sol) |
| Seta Esquerda | Rotaciona câmera para esquerda |
| Seta Direita | Rotaciona câmera para direita |
| Seta Cima | Eleva ângulo da câmera |
| Seta Baixo | Abaixa ângulo da câmera |
| Esc | Encerra o programa |

## Conceitos de Computação Gráfica Aplicados

### 1. Pipeline Gráfico

O pipeline gráfico é o processo pelo qual os dados 3D são transformados em pixels na tela. Nosso projeto utiliza o pipeline fixo do OpenGL que consiste em:

- Transformação de modelo: posiciona objetos no mundo
- Transformação de vista: posiciona a câmera
- Projeção: converte 3D para 2D
- Rasterização: converte primitivas em pixels

### 2. Primitivas 3D

Utilizamos diversas primitivas para construir os objetos:

- `glutSolidCube`: cubos para o banco
- `glutSolidSphere`: esferas para pedras e luminária
- `glutSolidCone`: cones para copa das árvores
- `gluCylinder`: cilindros para troncos e poste
- `gluDisk`: discos para o lago
- `GL_QUADS`: quadriláteros para o chão

### 3. Transformações Geométricas

As três transformações fundamentais foram utilizadas:

- `glTranslatef(x, y, z)`: move objetos no espaço
- `glRotatef(angulo, x, y, z)`: rotaciona objetos
- `glScalef(x, y, z)`: escala objetos

### 4. Transformações Hierárquicas

Objetos compostos como o banco e o poste utilizam hierarquia de transformações. Cada parte é posicionada relativamente à anterior usando a pilha de matrizes:

- `glPushMatrix()`: salva o estado atual da matriz
- `glPopMatrix()`: restaura o estado salvo

Isso permite criar objetos complexos onde cada componente herda as transformações do pai.

### 5. Sistema de Coordenadas

O projeto utiliza um sistema de coordenadas destro onde:

- Eixo X: direita/esquerda
- Eixo Y: cima/baixo
- Eixo Z: frente/trás

### 6. Projeção Perspectiva

Utilizamos `gluPerspective` para criar a sensação de profundidade onde objetos distantes aparecem menores. Parâmetros:

- Campo de visão: 60 graus
- Proporção: 800/600 (largura/altura da janela)
- Plano near: 0.1 (distância mínima visível)
- Plano far: 100.0 (distância máxima visível)

### 7. Câmera

A câmera é controlada por `gluLookAt` que define:

- Posição do observador (eye)
- Ponto para onde olha (center)
- Vetor que indica o "cima" (up)

A movimentação orbital é implementada usando coordenadas esféricas, convertendo ângulos em posições XYZ através de seno e cosseno.

### 8. Iluminação

O projeto implementa o modelo de iluminação de Phong com dois tipos de luz:

**Luz Direcional (Sol)**
- Simula raios paralelos vindos de uma direção
- Posição com W=0 indica luz direcional
- Cor alaranjada simulando pôr do sol

**Luz Pontual (Poste)**
- Emite luz em todas as direções a partir de um ponto
- Posição com W=1 indica luz pontual
- Atenuação com a distância (mais realista)
- Intensidade aumenta quando o sol é desligado

**Componentes da luz:**
- Ambiente: iluminação base que atinge todas as superfícies
- Difusa: luz que espalha igualmente ao atingir superfícies
- Especular: reflexos brilhantes (não utilizado neste projeto)

### 9. Materiais e Cores

Utilizamos `GL_COLOR_MATERIAL` que permite definir a cor do material através de `glColor3f`. Isso simplifica o código pois não precisamos definir arrays de material para cada objeto.

### 10. Normais

Vetores normais são essenciais para o cálculo correto da iluminação. Eles indicam a direção perpendicular à superfície:

- Chão: normal apontando para cima (0, 1, 0)
- Objetos GLU: normais calculadas automaticamente com `gluQuadricNormals`
- Objetos GLUT: normais já incluídas nas primitivas sólidas

### 11. Teste de Profundidade

`glEnable(GL_DEPTH_TEST)` ativa o Z-buffer que garante que objetos mais próximos da câmera sejam desenhados na frente dos mais distantes, independente da ordem de desenho.

### 12. Buffer Duplo

`GLUT_DOUBLE` utiliza dois buffers de imagem. Enquanto um é exibido, o outro é desenhado. Ao trocar os buffers com `glutSwapBuffers`, a transição é suave sem tremulação.

## Estrutura do Código
```
src/
├── main.c          Ponto de entrada e configuração do GLUT
├── init.c          Inicializações do OpenGL
├── init.h          Cabeçalho do init
├── display.c       Função de desenho da cena
├── display.h       Cabeçalho do display
├── camera.c        Controle da câmera e projeção
├── camera.h        Cabeçalho da câmera
├── iluminacao.c    Configuração das luzes
├── iluminacao.h    Cabeçalho da iluminação
├── objetos.c       Desenho de todos os objetos da cena
├── objetos.h       Cabeçalho dos objetos
├── teclado.c       Tratamento de entrada do teclado
├── teclado.h       Cabeçalho do teclado
└── README.md       Este arquivo
```

## Compilação e Execução

### Pré-requisitos

No Ubuntu/Debian, instale as dependências:
```bash
sudo apt update
sudo apt install freeglut3-dev libgl1-mesa-dev libglu1-mesa-dev
```

### Compilar
```bash
gcc main.c init.c display.c camera.c objetos.c iluminacao.c teclado.c -o parque -lGL -lGLU -lglut -lm
```

### Executar
```bash
./parque
```

## Funcionalidades Implementadas

- [x] Primitivas 3D adequadas (cubos, esferas, cilindros, cones, discos)
- [x] Transformações geométricas hierárquicas
- [x] Luz direcional (sol) com liga/desliga
- [x] Luz pontual (poste) com liga/desliga
- [x] Projeção perspectiva
- [x] Teste de profundidade
- [x] Movimentação da câmera por teclado
- [x] Iluminação dinâmica (poste mais forte sem sol)
- [x] Efeito visual de luminária acesa/apagada