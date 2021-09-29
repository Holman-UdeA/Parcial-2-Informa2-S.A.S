#include "metodos.h"

Metodos::Metodos(unsigned long DimensionImagen, int AnchoImagenOriginal, int AltoImagenOriginal)
{
    Dimension = DimensionImagen;
    AnchoImgO = AnchoImagenOriginal;
    AltoImgO = AltoImagenOriginal;
    MatrizFilas = new int*[AnchoImgO];
    for(int Fila=0; Fila<AnchoImgO; Fila++){
        MatrizFilas[Fila] = new int[3];
    }
}

int **Metodos::SubMuestreoAncho(int **MatrizImagen)
{
    MatrizImagenCodificada = new int*[(AnchoFinal*AltoImgO)];
    for(int Fila=0; Fila<(AnchoFinal*AltoImgO); Fila++){
        MatrizImagenCodificada[Fila] = new int[3];
    }

    int CantidadPixeles, CantidadPixeles2, Counter = 0, FilaMatriz = 0;
    int Sobrante, Sobrante2, PromedioR, PromedioG, PromedioB, Fila = 0;
    unsigned long SumaR = 0, SumaG = 0, SumaB = 0;
    CantidadPixeles = AnchoImgO / AnchoFinal;
    Sobrante = AnchoImgO % AnchoFinal;

    if(AnchoImgO%AnchoFinal == 0){
        for(unsigned long Pixel=0; Pixel<Dimension; Pixel++){
            if(Counter == CantidadPixeles){
                PromedioR = SumaR/CantidadPixeles;
                PromedioG = SumaG/CantidadPixeles;
                PromedioB = SumaB/CantidadPixeles;
                MatrizImagenCodificada[Fila][0] = PromedioR;
                MatrizImagenCodificada[Fila][1] = PromedioG;
                MatrizImagenCodificada[Fila][2] = PromedioB;
                Fila++;
                SumaR = 0;
                SumaG = 0;
                SumaB = 0;
                PromedioR = 0;
                PromedioG = 0;
                PromedioB = 0;
                Counter = 0;
            }
            SumaR += MatrizImagen[Pixel][0];
            SumaG += MatrizImagen[Pixel][1];
            SumaB += MatrizImagen[Pixel][2];
            Counter++;
        }
    }
    else {
        for(unsigned long Pixel=0; Pixel<Dimension; Pixel++){
            MatrizFilas[FilaMatriz][0] = MatrizImagen[Pixel][0];
            MatrizFilas[FilaMatriz][1] = MatrizImagen[Pixel][1];
            MatrizFilas[FilaMatriz][2] = MatrizImagen[Pixel][2];
            FilaMatriz++;
            if((Pixel+1)%AnchoImgO == 0){
                CantidadPixeles2 = CantidadPixeles;
                Sobrante2 = Sobrante;
                FilaMatriz = 0;
                for(int i=0; i<AnchoImgO; i++){
                    if(Counter == CantidadPixeles){
                        if(Sobrante2 > (Sobrante/2)){
                            SumaR += MatrizFilas[i][0];
                            SumaG += MatrizFilas[i][1];
                            SumaB += MatrizFilas[i][2];
                            i++;
                            Sobrante2--;
                            CantidadPixeles2++;
                        }
                        else{
                            if((i > AnchoImgO - ((CantidadPixeles+1)*Sobrante2)) && Sobrante2 > 0){
                                SumaR += MatrizFilas[i][0];
                                SumaG += MatrizFilas[i][1];
                                SumaB += MatrizFilas[i][2];
                                Sobrante2--;
                                i++;
                                CantidadPixeles2++;
                            }
                        }
                        PromedioR = SumaR/CantidadPixeles2;
                        PromedioG = SumaG/CantidadPixeles2;
                        PromedioB = SumaB/CantidadPixeles2;
                        MatrizImagenCodificada[Fila][0] = PromedioR;
                        MatrizImagenCodificada[Fila][1] = PromedioG;
                        MatrizImagenCodificada[Fila][2] = PromedioB;
                        Fila++;
                        SumaR = 0;
                        SumaG = 0;
                        SumaB = 0;
                        PromedioR = 0;
                        PromedioG = 0;
                        PromedioB = 0;
                        Counter = 0;
                        CantidadPixeles2 = CantidadPixeles;
                    }
                    if(i < AnchoImgO){
                        SumaR += MatrizFilas[i][0];
                        SumaG += MatrizFilas[i][1];
                        SumaB += MatrizFilas[i][2];
                        Counter++;
                    }
                }
            }
        }
    }
    return MatrizImagenCodificada;
}

int **Metodos::SubMuestreoAlto(int **MatrizImagen)
{
    MatrizImagenCodificada = new int*[(AnchoFinal*AltoFinal)];
    for(int Fila=0; Fila<(AnchoFinal*AltoFinal); Fila++){
        MatrizImagenCodificada[Fila] = new int[3];
    }

    int CantidadPixeles, CantidadPixeles2, Counter = 0, Sobrante, Sobrante2;
    int PromedioR, PromedioG, PromedioB, Fila = 0;
    unsigned long SumaR = 0, SumaG = 0, SumaB = 0;
    bool Final = false;
    CantidadPixeles = AltoImgO / AltoFinal;

    if(AltoImgO%AltoFinal == 0){
        for(unsigned long i=0; i<unsigned(AnchoFinal*AltoImgO); i++){
            if((i%AnchoFinal) == 0 && i != 0){
                if(((i - AnchoFinal) + (AnchoFinal * CantidadPixeles)) >= unsigned(AnchoFinal*AltoImgO)){
                    Final = true;
                }
                else {
                    i = (i - AnchoFinal) + (AnchoFinal * CantidadPixeles);
                }
            }
            if(Final == false){
                Counter = i;
                for(int a=0; a<CantidadPixeles; a++){
                    if(a==0){
                        SumaR += MatrizImagen[(i+AnchoFinal)*a+i][0];
                        SumaG += MatrizImagen[(i+AnchoFinal)*a+i][1];
                        SumaB += MatrizImagen[(i+AnchoFinal)*a+i][2];
                    }
                    else {
                        SumaR += MatrizImagen[(Counter+AnchoFinal)][0];
                        SumaG += MatrizImagen[(Counter+AnchoFinal)][1];
                        SumaB += MatrizImagen[(Counter+AnchoFinal)][2];
                        Counter = Counter+AnchoFinal;
                    }
                }
                PromedioR = SumaR / CantidadPixeles;
                PromedioG = SumaG / CantidadPixeles;
                PromedioB = SumaB / CantidadPixeles;
                MatrizImagenCodificada[Fila][0] = PromedioR;
                MatrizImagenCodificada[Fila][1] = PromedioG;
                MatrizImagenCodificada[Fila][2] = PromedioB;
                Fila++;
                SumaR = 0;
                SumaG = 0;
                SumaB = 0;
                PromedioR = 0;
                PromedioG = 0;
                PromedioB = 0;
            }
        }
    }
    else {
        Sobrante = AltoImgO%AltoFinal;
        CantidadPixeles2 = CantidadPixeles + 1;
        Sobrante2 = Sobrante - 1;
        for(unsigned long i=0; i<unsigned(AnchoFinal*AltoImgO); i++){
            if((i%AnchoFinal) == 0 && i != 0){
                if(((i - AnchoFinal) + (AnchoFinal * CantidadPixeles2)) >= unsigned(AnchoFinal*AltoImgO)){ //Y que sobranye > 0 sino es cantidadpixeles
                    Final = true;
                }
                else {
                    i = (i - AnchoFinal) + (AnchoFinal * CantidadPixeles2);
                    CantidadPixeles2 = CantidadPixeles;
                    if(Sobrante2 > 0){
                        if(Sobrante2 > Sobrante/2){
                            CantidadPixeles2 += 1;
                            Sobrante2--;
                        }
                        else {
                            if((i/AnchoFinal) == unsigned(AltoImgO - (CantidadPixeles+1)*Sobrante2)){
                                CantidadPixeles2 += 1;
                                Sobrante2--;
                            }
                            else {
                                CantidadPixeles2 = CantidadPixeles;
                            }
                        }
                    }
                }
            }
            if(Final == false){
                Counter = i;
                for(int a=0; a<CantidadPixeles2; a++){
                    if(a==0){
                        SumaR += MatrizImagen[(i+AnchoFinal)*a+i][0];
                        SumaG += MatrizImagen[(i+AnchoFinal)*a+i][1];
                        SumaB += MatrizImagen[(i+AnchoFinal)*a+i][2];
                    }
                    else {
                        SumaR += MatrizImagen[(Counter+AnchoFinal)][0];
                        SumaG += MatrizImagen[(Counter+AnchoFinal)][1];
                        SumaB += MatrizImagen[(Counter+AnchoFinal)][2];
                        Counter = Counter+AnchoFinal;
                    }
                }
                PromedioR = SumaR / CantidadPixeles2;
                PromedioG = SumaG / CantidadPixeles2;
                PromedioB = SumaB / CantidadPixeles2;
                MatrizImagenCodificada[Fila][0] = PromedioR;
                MatrizImagenCodificada[Fila][1] = PromedioG;
                MatrizImagenCodificada[Fila][2] = PromedioB;
                Fila++;
                SumaR = 0;
                SumaG = 0;
                SumaB = 0;
                PromedioR = 0;
                PromedioG = 0;
                PromedioB = 0;
            }
        }
    }

    return MatrizImagenCodificada;
}

int **Metodos::SobreMuestreoAncho(int **MatrizImagen)
{
    MatrizImagenCodificada = new int*[AnchoFinal*AltoImgO];
    for(int Fila=0; Fila<(AnchoFinal*AltoImgO); Fila++){
        MatrizImagenCodificada[Fila] = new int[3];
    }

    int CantidadPixeles, Counter = 0;
    int Sobrante, Sobrante2, FilaMO = 0;
    CantidadPixeles = AnchoFinal / AnchoImgO;

    if(AnchoFinal%AnchoImgO == 0){
        for(int i=0; i<(AnchoFinal*AltoImgO); i++){
            if(Counter == CantidadPixeles){
                FilaMO++;
                Counter = 0;
            }
            MatrizImagenCodificada[i][0] = MatrizImagen[FilaMO][0];
            MatrizImagenCodificada[i][1] = MatrizImagen[FilaMO][1];
            MatrizImagenCodificada[i][2] = MatrizImagen[FilaMO][2];
            Counter++;
        }
    }
    else {
        Sobrante = AnchoFinal % AnchoImgO;
        Sobrante2 = Sobrante;
        for(int i=0; i<(AnchoFinal*AltoImgO); i++){
            if(Counter == CantidadPixeles){
                if(Sobrante2 > 0){
                    if(Sobrante2 > (Sobrante/2)){
                        //Toma otro
                        MatrizImagenCodificada[i][0] = MatrizImagen[FilaMO][0];
                        MatrizImagenCodificada[i][1] = MatrizImagen[FilaMO][1];
                        MatrizImagenCodificada[i][2] = MatrizImagen[FilaMO][2];
                        Sobrante2--;
                        i++;
                    }
                    else {
                        if(((i+1)+((Sobrante2-1)*(CantidadPixeles+1))) == ((AnchoFinal*((AnchoFinal/i)+1))-1)){
                            MatrizImagenCodificada[i][0] = MatrizImagen[FilaMO][0];
                            MatrizImagenCodificada[i][1] = MatrizImagen[FilaMO][1];
                            MatrizImagenCodificada[i][2] = MatrizImagen[FilaMO][2];
                            Sobrante2--;
                            i++;
                        }
                    }
                }
                FilaMO++;
                Counter = 0;
            }
            MatrizImagenCodificada[i][0] = MatrizImagen[FilaMO][0];
            MatrizImagenCodificada[i][1] = MatrizImagen[FilaMO][1];
            MatrizImagenCodificada[i][2] = MatrizImagen[FilaMO][2];
            Counter++;
        }
    }

    return  MatrizImagenCodificada;
}

int **Metodos::SobreMuestreoAlto(int **MatrizImagen)
{
    MatrizImagenCodificada = new int*[(AnchoFinal*AltoFinal)];
    for(int Fila=0; Fila<(AnchoFinal*AltoFinal); Fila++){
        MatrizImagenCodificada[Fila] = new int[3];
    }

    int CantidadPixeles, Counter, Sobrante, Sobrante2, Fila = 0;
    bool Final = false, Final2 = false;
    Sobrante = AltoFinal%AltoImgO;
    Sobrante2 = Sobrante;

    if(Sobrante == 0){
        CantidadPixeles = AltoFinal / AltoImgO;
    }
    else {
        CantidadPixeles = (AltoFinal/AltoImgO) + 1;
        Sobrante2--;
    }
    for(int i=0; i<(AnchoFinal*AltoFinal); i++){
        if(i%AnchoFinal == 0 && i!= 0){
            if(Final == true){
                Final2 = true;
            }
            if((((CantidadPixeles+1)*Sobrante2)*AnchoFinal)+i == (AnchoFinal*AltoFinal)){
                Final = true;
            }
            else {
                i = (i - AnchoFinal) + (AnchoFinal * CantidadPixeles);
            }
            if(Sobrante2 > 0){
                if(Sobrante2 > (Sobrante/2)){
                    CantidadPixeles =  (AltoFinal/AltoImgO) + 1;
                    Sobrante2--;
                }
                else if((i/AnchoFinal) == (AltoFinal - ((CantidadPixeles+1)*Sobrante2))){
                    CantidadPixeles = (AltoFinal/AltoImgO) + 1;
                    Sobrante2--;
                }
                else {
                    CantidadPixeles = AltoFinal / AltoImgO;
                }
            }
        }
        if(Final2 == false){
            Counter = i;
            for(int a=0; a<CantidadPixeles; a++){
                if(a==0){
                    MatrizImagenCodificada[i][0] = MatrizImagen[Fila][0];
                    MatrizImagenCodificada[i][1] = MatrizImagen[Fila][1];
                    MatrizImagenCodificada[i][2] = MatrizImagen[Fila][2];
                }
                else {
                    MatrizImagenCodificada[(Counter+AnchoFinal)][0] = MatrizImagen[Fila][0];
                    MatrizImagenCodificada[(Counter+AnchoFinal)][1] = MatrizImagen[Fila][1];
                    MatrizImagenCodificada[(Counter+AnchoFinal)][2] = MatrizImagen[Fila][2];
                    Counter = Counter+AnchoFinal;
                }
            }
            Fila++;
        }
    }
    return MatrizImagenCodificada;
}
