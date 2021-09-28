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
}
