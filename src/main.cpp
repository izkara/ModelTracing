/////////////////////////////////////////////////////////////////////////////
//OpenHaptics QuickHaptics - SimpleSphere example
//SensAble Technologies, Woburn, MA
//September 03, 2008
//Programmer: Hari Vasudevan
//////////////////////////////////////////////////////////////////////////////




#include <QHHeadersGLUT.h>//Include all necessary headers
#include <string>

using namespace std;


static double gSurfaceShapeSnapDistance = 0.0;
HLuint gSurfaceShapeId = 0;


int main(int argc, char *argv[])
{
	string file_name;
	gSurfaceShapeId = hlGenShapes(1);
	QHGLUT* DisplayObject = new QHGLUT(argc,argv);//create a display window
 
    DeviceSpace* Omni = new DeviceSpace;//Find the default Phantom Device
    DisplayObject->tell(Omni);//Tell Quickhaptics that omni 

	cout << "Drag OBJ here:" << endl;
	cin >> file_name;

	char *file = new char[file_name.size() + 1];
	copy(file_name.begin(), file_name.end(), file);
	file[file_name.size()] = '\0';

	TriMesh* Cow = new TriMesh(file, true);//Load a cow model
	Cow->setName("Cow");//give it a name
	//Cow->setMagnetic(true);//Make the Cylinder magnetic
    DisplayObject->tell(Cow);//Tell Quick Haptics that the sphere exists

	hlEndShape();


    Cursor* OmniCursor = new Cursor;//Create a cursor
    DisplayObject->tell(OmniCursor);//Tell QuickHaptics that a cursor exists
    
  
    qhStart();//Set everything in motion

	delete[] file;
    return 0;
}


