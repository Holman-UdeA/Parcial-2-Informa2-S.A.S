#include <iostream>
#include <QImage>

using namespace std;

int main()
{
    QImage Imagen;
    int **MatrizImg;
    int Ancho, Alto;
    unsigned long Dimension, PosPixel = 0;
    string FilePath = "../Parcial_2_QT/Imagenes/";
    string FileName;

    cout << "Ingrese el nombre de la imagen a tratar: "; getline(cin, FileName); cout << endl;
    FilePath.append(FileName);
    if(Imagen.load(FilePath.c_str())){
        cout << "Imagen tratada con exito. " << endl;
        Ancho = Imagen.width();
        Alto = Imagen.height();
        Dimension = Ancho*Alto;
        MatrizImg = new int*[Dimension];
        for(unsigned long FilaM=0; FilaM<Dimension; FilaM++){
            MatrizImg[FilaM] = new int[3];
        }

        for(int PosY=0; PosY<Imagen.height(); PosY++){
            for(int PosX=0; PosX<Imagen.height(); PosX++){
                MatrizImg[PosPixel][0] = Imagen.pixelColor(PosX, PosY).red();
                MatrizImg[PosPixel][1] = Imagen.pixelColor(PosX, PosY).green();
                MatrizImg[PosPixel][2] = Imagen.pixelColor(PosX, PosY).blue();
                PosPixel++;
            }
        }
    }
    else{
        cout << "No se encontro la imagen. " << endl;
        cout << "Recuerde que la imagen debe estar guardada dentro de la carpeta del programa, llamada \"Imagenes\". " << endl;
    }

    return 0;
}
