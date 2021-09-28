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

    int CantidadPixeles = AnchoImgO / AnchoFinal, CantidadPixeles2, Counter = 0, FilaMatriz = 0, Sobrante, Sobrante2;
    int PromedioR, PromedioG, PromedioB, Fila = 0;
    unsigned long SumaR = 0, SumaG = 0, SumaB = 0;

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
        Sobrante = AnchoImgO % AnchoFinal;
        CantidadPixeles2 = CantidadPixeles;
        Sobrante2 = Sobrante;
        for(unsigned long Pixel=0; Pixel<Dimension; Pixel++){
            MatrizFilas[FilaMatriz][0] = MatrizImagen[Pixel][0];
            MatrizFilas[FilaMatriz][1] = MatrizImagen[Pixel][1];
            MatrizFilas[FilaMatriz][2] = MatrizImagen[Pixel][2];
            FilaMatriz++;
            if((Pixel+1)%AnchoImgO == 0){

            }
        }
    }
    return MatrizImagenCodificada;
}
