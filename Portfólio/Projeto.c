#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_HIST 50

typedef struct {
    int id;
    char tipo[30];
    double a, b, resultado;
} Operacao;

Operacao historico[MAX_HIST];
int totalOps = 0;

long long fatorial(int n) {
    if (n < 0 || n > 20) return -1;
    long long fat = 1;
    for (int i = 1; i <= n; i++) fat *= i;
    return fat;
}

double soma(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double mult(double a, double b) { return a * b; }
double divs(double a, double b) { return b == 0 ? NAN : a / b; }
double pot(double a, double b) { return pow(a, b); }
double raiz(double a) { return a < 0 ? NAN : sqrt(a); }
double seno(double a) { return sin(a * M_PI / 180); }
double coss(double a) { return cos(a * M_PI / 180); }
double tang(double a) { return tan(a * M_PI / 180); }
double log10b(double a) { return a <= 0 ? NAN : log10(a); }
double lognb(double a) { return a <= 0 ? NAN : log(a); }
double expb(double a) { return exp(a); }
double absb(double a) { return fabs(a); }
double maxb(double a, double b) { return fmax(a, b); }
double minb(double a, double b) { return fmin(a, b); }
double grausParaRad(double a) { return a * M_PI / 180; }
double radParaGraus(double a) { return a * 180 / M_PI; }
double hip(double a, double b) { return hypot(a, b); }

double mmc(int a, int b) {
    if (a <= 0 || b <= 0) return -1;
    int m = a, n = b;
    while (a != b) {
        if (a < b) a += m;
        else b += n;
    }
    return a;
}

double mdc(int a, int b) {
    if (a == 0) return b;
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void registrar(char tipo[], double a, double b, double r) {
    if (totalOps < MAX_HIST) {
        historico[totalOps].id = totalOps + 1;
        strcpy(historico[totalOps].tipo, tipo);
        historico[totalOps].a = a;
        historico[totalOps].b = b;
        historico[totalOps].resultado = r;
        totalOps++;
    }
}

void mostrarHistorico() {
    printf("\n--- HISTÓRICO ---\n");
    if (totalOps == 0) printf("Nenhuma operação registrada.\n");
    else
        for (int i = 0; i < totalOps; i++)
            printf("%d. %s (%.2lf, %.2lf) = %.4lf\n",
                   historico[i].id,
                   historico[i].tipo,
                   historico[i].a,
                   historico[i].b,
                   historico[i].resultado);
}

double media(double v[], int n) {
    double s = 0;
    for (int i = 0; i < n; i++) s += v[i];
    return s / n;
}

double mediana(double v[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (v[i] > v[j]) {
                double t = v[i];
                v[i] = v[j];
                v[j] = t;
            }
    return n % 2 == 0 ? (v[n / 2 - 1] + v[n / 2]) / 2 : v[n / 2];
}

double desvio(double v[], int n) {
    double m = media(v, n), s = 0;
    for (int i = 0; i < n; i++) s += pow(v[i] - m, 2);
    return sqrt(s / n);
}

void somaMatriz(double A[2][2], double B[2][2], double R[2][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            R[i][j] = A[i][j] + B[i][j];
}

void multMatriz(double A[2][2], double B[2][2], double R[2][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            R[i][j] = 0;
            for (int k = 0; k < 2; k++)
                R[i][j] += A[i][k] * B[k][j];
        }
}

int main() {
    int op;
    char cont = 's';
    double a, b, r;

    while (cont == 's' || cont == 'S') {
        printf("\n=== CALCULADORA CIENTÍFICA 2.0 ===\n");
        printf("1.Soma\t\t2.Subtração\t3.Multiplicação\t4.Divisão\n");
        printf("5.Potência\t6.Raiz\t\t7.Seno\t\t8.Cosseno\n");
        printf("9.Tangente\t10.Log10\t11.Ln\t\t12.Exp\n");
        printf("13.Fatorial\t14.Abs\t\t15.Max\t\t16.Min\n");
        printf("17.MMC\t\t18.MDC\t\t19.Graus->Rad\t20.Rad->Graus\n");
        printf("21.Hipotenusa\t22.Média\t23.Mediana\t24.Desvio Padrão\n");
        printf("25.Matriz Soma\t26.Matriz Mult\t27.Histórico\t28.Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);

        if (op == 28) break;

        switch (op) {
            case 1: case 2: case 3: case 4:
                printf("Digite dois números: ");
                scanf("%lf %lf", &a, &b);
                break;
        }

        switch (op) {
            case 1: r = soma(a, b); registrar("Soma", a, b, r); break;
            case 2: r = sub(a, b); registrar("Subtração", a, b, r); break;
            case 3: r = mult(a, b); registrar("Multiplicação", a, b, r); break;
            case 4: r = divs(a, b); if (isnan(r)) printf("Erro: divisão por zero.\n"); else registrar("Divisão", a, b, r); break;
            case 5: printf("Base e expoente: "); scanf("%lf %lf", &a, &b); r = pot(a, b); registrar("Potência", a, b, r); break;
            case 6: printf("Número: "); scanf("%lf", &a); r = raiz(a); if (!isnan(r)) registrar("Raiz", a, 0, r); break;
            case 7: printf("Ângulo (°): "); scanf("%lf", &a); r = seno(a); registrar("Seno", a, 0, r); break;
            case 8: printf("Ângulo (°): "); scanf("%lf", &a); r = coss(a); registrar("Cosseno", a, 0, r); break;
            case 9: printf("Ângulo (°): "); scanf("%lf", &a); r = tang(a); registrar("Tangente", a, 0, r); break;
            case 10: printf("Número: "); scanf("%lf", &a); r = log10b(a); if (!isnan(r)) registrar("Log10", a, 0, r); break;
            case 11: printf("Número: "); scanf("%lf", &a); r = lognb(a); if (!isnan(r)) registrar("Ln", a, 0, r); break;
            case 12: printf("Número: "); scanf("%lf", &a); r = expb(a); registrar("Exp", a, 0, r); break;
            case 13: printf("Inteiro: "); scanf("%lf", &a); r = fatorial((int)a); if (r >= 0) registrar("Fatorial", a, 0, r); break;
            case 14: printf("Número: "); scanf("%lf", &a); r = absb(a); registrar("Abs", a, 0, r); break;
            case 15: printf("Dois números: "); scanf("%lf %lf", &a, &b); r = maxb(a, b); registrar("Max", a, b, r); break;
            case 16: printf("Dois números: "); scanf("%lf %lf", &a, &b); r = minb(a, b); registrar("Min", a, b, r); break;
            case 17: printf("Dois inteiros: "); scanf("%lf %lf", &a, &b); r = mmc((int)a, (int)b); if (r > 0) registrar("MMC", a, b, r); break;
            case 18: printf("Dois inteiros: "); scanf("%lf %lf", &a, &b); r = mdc((int)a, (int)b); registrar("MDC", a, b, r); break;
            case 19: printf("Graus: "); scanf("%lf", &a); r = grausParaRad(a); registrar("Graus->Rad", a, 0, r); break;
            case 20: printf("Radianos: "); scanf("%lf", &a); r = radParaGraus(a); registrar("Rad->Graus", a, 0, r); break;
            case 21: printf("Catetos: "); scanf("%lf %lf", &a, &b); r = hip(a, b); registrar("Hipotenusa", a, b, r); break;
            case 22: {
                int n; printf("Quantidade: "); scanf("%d", &n);
                double v[n]; for (int i = 0; i < n; i++) scanf("%lf", &v[i]);
                r = media(v, n); registrar("Média", n, 0, r);
                break;
            }
            case 23: {
                int n; printf("Quantidade: "); scanf("%d", &n);
                double v[n]; for (int i = 0; i < n; i++) scanf("%lf", &v[i]);
                r = mediana(v, n); registrar("Mediana", n, 0, r);
                break;
            }
            case 24: {
                int n; printf("Quantidade: "); scanf("%d", &n);
                double v[n]; for (int i = 0; i < n; i++) scanf("%lf", &v[i]);
                r = desvio(v, n); registrar("Desvio", n, 0, r);
                break;
            }
            case 25: {
                double A[2][2], B[2][2], R[2][2];
                printf("Matriz A (2x2): "); for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) scanf("%lf", &A[i][j]);
                printf("Matriz B (2x2): "); for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) scanf("%lf", &B[i][j]);
                somaMatriz(A, B, R);
                printf("Resultado:\n"); for (int i = 0; i < 2; i++) { for (int j = 0; j < 2; j++) printf("%.2lf ", R[i][j]); printf("\n"); }
                break;
            }
            case 26: {
                double A[2][2], B[2][2], R[2][2];
                printf("Matriz A (2x2): "); for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) scanf("%lf", &A[i][j]);
                printf("Matriz B (2x2): "); for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) scanf("%lf", &B[i][j]);
                multMatriz(A, B, R);
                printf("Resultado:\n"); for (int i = 0; i < 2; i++) { for (int j = 0; j < 2; j++) printf("%.2lf ", R[i][j]); printf("\n"); }
                break;
            }
            case 27: mostrarHistorico(); break;
            default: printf("Opção inválida.\n");
        }

        if (op >= 1 && op <= 24) printf("Resultado: %.4lf\n", r);
        printf("\nDeseja continuar? (s/n): ");
        scanf(" %c", &cont);
    }

    printf("Calculadora encerrada.\n");
    return 0;
}
