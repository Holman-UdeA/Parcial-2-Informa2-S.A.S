#include <iostream>
#include <QImage>
#include <metodos.h>

using namespace std;

int main()
{
    QImage Imagen;
    int **MatrizImg, **MatrizImgC, **MatrizImgF;
    int Ancho, Alto, Ancho2 = 16, Alto2 = 9;
    unsigned long Dimension, PosPixel = 0;
    string FilePath = "../Parcial_2_QT/Imagenes/", FileName;

    cout << "Ingrese el nombre de la imagen a tratar: "; getline(cin, FileName); cout << endl;
    FilePath.append(FileName);
    if(Imagen.load(FilePath.c_str())){
        cout << "Imagen cargada con exito. " << endl;
        Ancho = Imagen.width();
        Alto = Imagen.height();
        Dimension = Ancho*Alto;
        Metodos IM(Dimension, Ancho, Alto);
        MatrizImg = new int*[Dimension];
        for(unsigned long FilaM=0; FilaM<Dimension; FilaM++){
            MatrizImg[FilaM] = new int[3];
        }
        MatrizImgC = new int*[(Ancho2*Alto)];
        for(int Filas=0; Filas<(Ancho2*Alto); Filas++){
            MatrizImgC[Filas] = new int[3];
        }
        MatrizImgF = new int*[(Ancho2*Alto2)];
        for(int Filas=0; Filas<(Ancho2*Alto2); Filas++){
            MatrizImgF[Filas] = new int[3];
        }

        for(int PosY=0; PosY<Alto; PosY++){
            for(int PosX=0; PosX<Ancho; PosX++){
                MatrizImg[PosPixel][0] = Imagen.pixelColor(PosX, PosY).red();
                MatrizImg[PosPixel][1] = Imagen.pixelColor(PosX, PosY).green();
                MatrizImg[PosPixel][2] = Imagen.pixelColor(PosX, PosY).blue();
                PosPixel++;
            }
        }
        if(Dimension != unsigned(Ancho2*Alto2)){ //Se valida que no tenga ya el tamaño deseado.
            if(Ancho > Ancho2){
                //Se realiza Submuestreo a las columnas.
                MatrizImgC = IM.SubMuestreoAncho(MatrizImg);
            }
            else {
                //Se realiza Sobremuestreo a las columnas.
            }
            if(Alto > Alto2){
                //Se realiza Soubmuestreo a las filas.
                MatrizImgF = IM.SubMuestreoAlto(MatrizImgC);
            }
            else {
                //Se realiza Sobremuestreo a las filas.
            }
        }
    }
    else{
        cout << "No se encontro la imagen. " << endl;
        cout << "Recuerde que la imagen debe estar guardada dentro de la carpeta directorio del programa, llamada \"Imagenes\". " << endl;
    }

    return 0;
}
