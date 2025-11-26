# Calculadora Científica 2.0 em C

Este projeto consiste em uma **calculadora científica desenvolvida em linguagem C**, capaz de realizar operações básicas, científicas e estatísticas, além de manipulação de matrizes.  
O código foi estruturado de forma modular, utilizando funções, estruturas e boas práticas de programação.



## Funcionalidades

A calculadora oferece um conjunto abrangente de operações matemáticas organizadas em categorias:

### Operações básicas
- Soma  
- Subtração  
- Multiplicação  
- Divisão  

### Operações matemáticas gerais
- Potência  
- Raiz quadrada  
- Valor absoluto  
- Máximo e mínimo entre dois números  
- Exponencial  
- Logaritmos (base 10 e natural)  

### Funções trigonométricas
- Seno  
- Cosseno  
- Tangente  
- Conversão entre graus e radianos  

### Outras funções matemáticas
- Fatorial  
- Máximo Divisor Comum (MDC)  
- Mínimo Múltiplo Comum (MMC)  
- Cálculo da hipotenusa  

### Operações estatísticas
- Média  
- Mediana  
- Desvio padrão  

### Operações com matrizes
- Soma de matrizes 2x2  
- Multiplicação de matrizes 2x2  

### Recursos adicionais
- Histórico de operações (até 50 registros)  
- Sistema de menu interativo em terminal  



## Estrutura do Código

O código utiliza:
- **Struct `Operacao`** para registrar o histórico de cálculos realizados.  
- **Funções específicas** para cada tipo de operação, promovendo modularidade e clareza.  
- **Validação de entrada**, evitando erros como divisão por zero, logaritmos de números negativos ou valores fora do limite de cálculo.  
- **Bibliotecas utilizadas:**
  - `stdio.h`
  - `stdlib.h`
  - `string.h`
  - `math.h`


Limitações

O histórico armazena no máximo 50 operações.

As matrizes são fixas no formato 2x2.

O cálculo fatorial é limitado a n ≤ 20 para evitar estouro de variáveis do tipo long long.

