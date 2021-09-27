#ifndef METODOS_H
#define METODOS_H


class Metodos
{
public:
    Metodos(unsigned long DimensionImagen, int AnchoImagenOriginal, int AltoImagenOriginal);
    int **SubMuestreoAncho(int **MatrizImagen);
private:
    int **MatrizFilas, **MatrizImagenCodificada;
    int AnchoFinal = 16, Altofinal = 9, AnchoImgO, AltoImgO;
    unsigned long Dimension;
};

#endif // METODOS_H
