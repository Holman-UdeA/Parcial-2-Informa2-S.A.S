#include <iostream>
#include <QImage>

using namespace std;

int main()
{
    QImage Imagen;
    string FilePath = "../Parcial_2_QT/Imagenes/";
    string FileName;

    cout << "Ingrese el nombre de la imagen a tratar: "; cin >> FileName; cout << endl;
    FilePath.append(FileName);
    if(Imagen.load(FilePath.c_str())){
        cout << "Imagen tratada con exito. " << endl;
    }
    else{
        cout << "No se encontro la imagen. " << endl;
        cout << "Recuerde que la imagen debe estar guardada dentro de la carpeta del programa. " << endl;
    }

    return 0;
}
