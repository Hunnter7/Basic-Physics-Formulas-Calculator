#include<iostream>
#include <string>
#include<cmath>
#include<windows.h>
#include<fstream>

using namespace std;

void bienvenida();
void despedida();


class Fuerza {
private:
	float Fu1;
	float Fu2;
public:
	Fuerza(float,float);
	void mostrarFueza();
};

Fuerza::Fuerza(float _Fu1,float _Fu2) {
	Fu1 = _Fu1;
	Fu2 = _Fu2;
}

void Fuerza::mostrarFueza(){
	float FuF;
	FuF = Fu1 + Fu2;
	cout << "La fuerza es: " << FuF << endl;
}

class Persona {
private: //Atributos
	string nombre;
	int edad;
	string sexo;
public://Metodos
	Persona(string, int, string);
	void mostrarPersona();
};

class Alumno : public Persona {
private: //Atributos
	string codigo;
	float nota;
public://Metodos
	Alumno(string, int, string, string, float);//Constructor de la clase alumno
	void mostrarAlumno();
};

class Profesor : public Persona {
private: //Atributos
	string titulo;
	int experiencia;
public://Metodos
	Profesor(string, int, string, string, int);//Constructor de la clase profesor
	void mostrarProfesor();
};

//Constructor de la clase persona(Clase padre)
Persona::Persona(string _nombre, int _edad, string _sexo) {
	nombre = _nombre;
	edad = _edad;
	sexo = _sexo;
}

//Constructor de la clase alumno(Clase hija)
Alumno::Alumno(string _nombre, int _edad, string _sexo, string _codigo, float _nota) : Persona(_nombre, _edad, _sexo) {
	codigo = _codigo;
	nota = _nota;
}

//Constructor de la clase profesor(Clase hija)
Profesor::Profesor(string _nombre, int _edad, string _sexo, string _titulo, int _experiencia) : Persona(_nombre, _edad, _sexo) {
	titulo = _titulo;
	experiencia = _experiencia;
}

//Funcion de la clase persona
void Persona::mostrarPersona() {
	cout << "Su nombre: " << nombre << endl;
	cout << "Su edad: " << edad << endl;
	cout << "Su sexo: " << sexo << endl;
}

//Funcion de la clase hija
void Alumno::mostrarAlumno() {
	mostrarPersona();
	cout << "Su codigo: " << codigo << endl;
	cout << "Su nota: " << nota << endl;
}

//Funcion de la clase hija 2
void Profesor::mostrarProfesor() {
	mostrarPersona();
	cout << "Su titulo: " << titulo << endl;
	cout << "Su experiencia laboral: " << experiencia << endl;
}





float tye(float x, float y);

float inter(float a1, float a2, float a3, float a4, float a5);

int main(void) {

	int if1;//if
	int a, x, y, z, q;//switches
	float r1, r2, rr;//Fuerza
	float w, t, p;//Trabajo y energia
	float y0, x0, x1, y1, X, Y;//Interpolacion
	float xc1, V, vf, vfg;//Calidad 1.1
	float xc2, mv, ml;//Calidad 1.2
	float fx, fy, F, f1, f2;//Fuerza en los ejes
	float g = 9.81, * g_p, ms, wp;//gravedad
	float P, n, R, T, Rg, m;//Gases ideales
	float W, Ft, d, ang;//Trabajo mecanico
	long velm ,v, vo, ac, timp, xo, xp1, xp2;//Velocidad media
	float rs, rn=0, Rs, rp, vol, inten, resis;//circuitos electricos

	g_p = &g;

	string nombreM, sexoM, codigoM, tituloM, o;
	int edadM, experienciaM, xd;
	float notaM;

	bienvenida();

	do {
		cout << "Inicio" << endl;
		cout << "Usted es un profesor o un alumno?" << endl;
		cout << "1. Alumno" << endl;
		cout << "2. Profesor" << endl;
		cin >> xd;

		if (xd == 1) {
			cout << "Ingrese su nombre: ";
			cin >> nombreM;
			cout << "Ingrese su edad: ";
			cin >> edadM;
			cout << "Ingrese su sexo: ";
			cin >> sexoM;
			cout << "Ingrese su codigo: ";
			cin >> codigoM;
			cout << "Ingrese su nota: ";
			cin >> notaM;
			system("cls");

			Alumno alumno1(nombreM, edadM, sexoM, codigoM, notaM);
			alumno1.mostrarAlumno();

			ofstream datos_alumno;

			datos_alumno.open("Datos de alumnos.txt", ios::app);

			if (datos_alumno.fail()) {
				cout << "No se pudo abrir el archivo";
				exit(1);
			}
			datos_alumno << "Datos del alumno " << endl;
			datos_alumno << "Nombre: " << nombreM << endl;
			datos_alumno << "Edad: " << edadM << endl;
			datos_alumno << "Sexo: " << sexoM << endl;
			datos_alumno << "Codigo: " << codigoM << endl;
			datos_alumno << "Nota: " << notaM << endl;
			datos_alumno << " " << endl;
			datos_alumno.close();

			cout << " " << endl;

			cout << "Una vez ingresado sus datos, ingrese la letra S" << endl;
			cin >> o;

			system("cls");
		}
		else if (xd == 2) {
			cout << "Ingrese su nombre: ";
			cin >> nombreM;
			cout << "Ingrese su edad: ";
			cin >> edadM;
			cout << "Ingrese su sexo: ";
			cin >> sexoM;
			cout << "Ingrese su titulo: ";
			cin >> tituloM;
			cout << "Ingrese sus años de experiencia laboral: ";
			cin >> experienciaM;
			system("cls");


			Profesor profesor1(nombreM, edadM, sexoM, tituloM, experienciaM);
			profesor1.mostrarProfesor();

			ofstream datos_profesor;

			datos_profesor.open("Datos de profesores.txt", ios::app);

			if (datos_profesor.fail()) {
				cout << "No se pudo abrir el archivo";
				exit(1);
			}
			datos_profesor << "Datos del profesor" << endl;
			datos_profesor << "Nombre: " << nombreM << endl;
			datos_profesor << "Edad: " << edadM << endl;
			datos_profesor << "Sexo: " << sexoM << endl;
			datos_profesor << "Titulo: " << tituloM << endl;
			datos_profesor << "Años de experiencia: " << experienciaM << endl;
			datos_profesor << " " << endl;

			datos_profesor.close();

			cout << " " << endl;

			cout << "Una vez ingresado sus datos, ingrese la letra S" << endl;
			cin >> o;

			system("cls");
		}
		else {
			cout << "***Error***" << endl;
		}
	} 	while (o != "S");
	
	do {
		cout << "Calculador de fisica" << endl;
		cout << "1. Mecanica" << endl;
		cout << "2. Termodinamica" << endl;
		cout << "3. Cinematica para aceleracion constante" << endl;
		cout << "4. Circuitos electricos" << endl;
		cout << "5. Salir" << endl;

		cin >> a;
		system("cls");
	
		switch (a) {
		case 1://Case de Mecanica
			do {
				cout << "1. Fuerza" << endl;
				cout << "2. Trabajo y energia" << endl;
				cout << "3. Masa" << endl;
				cout << "4. Peso" << endl;
				cout << "5. Fuerzas en el ejer x, eje y" << endl;
				cout << "6. Salir" << endl;
				cin >> x;
				system("cls");
				
				switch (x) {//switch de Mecanica
				case 1:
					cout << "Formula de la fuerza" << endl;
					cout << "Masa del objeto: ";
					cin >> r1;
					cout << "Aceleracion: ";
					cin >> r2;
					system("cls");
					rr = r1 * r2;
					cout << "Resultado: " << rr << endl;
					break;
				case 2:
					cout << "Formula de Potencia, P (Trabajo y energia)" << endl;
					cout << "Ingrese el valor de la variable W" << endl;
					cin >> w;
					cout << "Ingrese el valor de la variable t" << endl;
					cin >> t;
					p = tye(w, t);
					system("cls");
					cout << "El valor de la Potencia P es: " << p << endl;
					break;
				case 3:
					cout << "Formula de la masa" << endl;
					cout << "Ingrese el valor de w" << endl;
					cin >> wp;
					ms = wp / *g_p;
					system("cls");
					cout << "El valor de la masa es: " << ms << endl;
					break;
				case 4:
					cout << "Formula del peso" << endl;
					cout << "Ingrese el valor de m" << endl;
					cin >> ms;
					wp = ms * g;
					system("cls");
					cout << "El valor de m es: " << wp << endl;
					break;
				case 5:
					cout << "Formula de fuerza en x,y" << endl;
					cout << "Ingrese el valor de la variable fuerza" << endl;
					cin >> F;
					cout << "Ingrese el valor del angulo en el eje x" << endl;
					cin >> fx;
					cout << "Ingrese el valor del angulo en el eje y" << endl;
					cin >> fy;
					f1 = F * cos(fx);
					f2 = F * sin(fy);
					system("cls");
					cout << "El valor de la fuerza en el eje x es: " << f1 << " y el valor de la fuerza en el eje y es: " << f2 << endl;

					Fuerza fuerza1(f1, f2);
					fuerza1.mostrarFueza();

					break;
				}
			} 			while (x != 6);
			break;

		case 2://Case de termodinamica
			do {
				cout << "1. Calidad 1.1(x=(V-Vf)/Vfg)" << endl;
				cout << "2. Calidad 1.2(x=mv/(mv+mL))" << endl;
				cout << "3. Interpolacion" << endl;
				cout << "4. Gases ideales" << endl;
				cout << "5. Trabajo" << endl;
				cout << "6. Salir" << endl;
				cin >> y;
				system("cls");
				switch (y) {//switch de termodinamica
				case 1:
					cout << "Formula de Calidad 1.1" << endl;
					cout << "Ingrese el valor de la variable V" << endl;
					cin >> V;
					cout << "Ingrese el valor de la variable Vf" << endl;
					cin >> vf;
					cout << "Ingrese el valor de la variable Vfg" << endl;
					cin >> vfg;
					xc1 = (V - vf) / vfg;
					system("cls");
					cout << "El valor de calidad es: " << xc1 << endl;
					break;
				case 2:
					cout << "Formula de calidad 1.2" << endl;
					cout << "Ingrese el valor de la variable mv" << endl;
					cin >> mv;
					cout << "Ingrese el valor de la variable ml" << endl;
					cin >> ml;
					xc2 = mv / (mv + ml);
					system("cls");
					cout << "El valor de calidad es: " << xc2 << endl;
					break;
				case 3:
					cout << "Formula de interpolacion" << endl;
					cout << "Ingrese el valor de y0" << endl;
					cin >> y0;//a1
					cout << "Ingrese el valor de X" << endl;
					cin >> X;//a2
					cout << "Ingrese el valor de x0" << endl;
					cin >> x0;//a3
					cout << "Ingrese el valor de y1" << endl;
					cin >> y1;//a4
					cout << "Ingrese el valor de x1" << endl;
					cin >> x1;//a5
					Y = inter(y0, X, x0, y1, x1);
					system("cls");
					cout << "El valor de la interpolacion es: " << Y << endl;
					break;
				case 4:
					do {
						cout << "Formula de Gases ideales" << endl;
						cout << "1. PV=nRT (n es el numero de moles)" << endl;
						cout << "2. PV=mRg T (Rg constante del gas)" << endl;
						cout << "3. PV=Rg T (se trabaja con volumen específico)" << endl;
						cout << "4. Salir" << endl;
						cin >> if1;
						system("cls");
						switch (if1) {
						case 1:
							cout << "Formula de gases ideales" << endl;
							cout << "Ingrese el valor de n" << endl;
							cin >> n;
							cout << "Ingrese el valor de R" << endl;
							cin >> R;
							cout << "Ingrese el valor de T" << endl;
							cin >> T;
							P = n * R * T;
							system("cls");
							cout << "El valor del gas ideal es: " << P << endl;
							break;
						case 2:
							cout << "Formula de gases ideales" << endl;
							cout << "Ingrese el valor de m" << endl;
							cin >> m;
							cout << "Ingrese el valor de Rg" << endl;
							cin >> Rg;
							cout << "Ingrese el valor de T" << endl;
							cin >> T;
							P = m * Rg * T;
							system("cls");
							cout << "El valor del gas ideal es: " << P << endl;
							break;
						case 3:
							cout << "Formula de gases ideales" << endl;
							cout << "Ingrese el valor de Rg" << endl;
							cin >> Rg;
							cout << "Ingrese el valor de T" << endl;
							cin >> T;
							P = Rg * T;
							system("cls");
							cout << "El valor del gas ideal es: " << P << endl;
							break;
						}
					} 					while (if1!=4);
					break;
				case 5:
					cout << "Formula de Trabajo" << endl;
					cout << "Trabajo mecanico" << endl;
					cout << "Ingrese el valor de F" << endl;
					cin >> Ft;
					cout << "Ingrese el valor de d" << endl;
					cin >> d;
					cout << "Ingrese el valor del angulo" << endl;
					cin >> ang;
					W = Ft * d * cos(ang);
					system("cls");
					cout << "El valor del trabajo mecanico es: " << W << endl;

				}
			} 			while (y != 6);
			break;
		case 3:
			do {
				cout << "1. Velocidad media" << endl;
				cout << "2. Velocidad" << endl;
				cout << "3. Posicion del objeto en el plano x, x=x_o+vot+1/2at^2" << endl;
				cout << "4. Posicion del objeto en el plano x, x=xo+1/2(v+vo)t" << endl;
				cout << "5. Salir" << endl;
				cin >> z;
				system("cls");
				switch (z) {
				case 1:
					cout << "Formula de la velocidad media" << endl;
					cout << "Ingrese el valor de v" << endl;
					cin >> v;
					cout << "Ingrese el valor de vo" << endl;
					cin >> vo;
					velm = (v + vo) / 2;
					system("cls");
					cout << "El valor de la velocidad media es: " << velm << endl;
					break;
				case 2:
					cout << "Formula de la velocidad" << endl;
					cout << "Ingrese el valor de vo" << endl;
					cin >> vo;
					cout << "Ingrese el valor de a" << endl;
					cin >> ac;
					cout << "Ingrese el valor de t" << endl;
					cin >> timp;
					velm = vo + (ac * timp);
					system("cls");
					cout << "El valor de la velocidad es: " << velm;
					break;
				case 3:
					cout << "Formula para la posicion del objeto" << endl;
					cout << "Ingrese el valor de xo" << endl;
					cin >> xo;
					cout << "Ingrese el valor de vo" << endl;
					cin >> vo;
					cout << "Ingrese el valor de t" << endl;
					cin >> timp;
					cout << "Ingrese el valor de a" << endl;
					cin >> ac;
					xp1 = xo + (vo * timp) + ((0.5) * ac * pow(timp, 2));
					system("cls");
					cout << "La posicion del objeto es: " << xp1 << endl;
					break;
				case 4:
					cout << "Formula para la posicion del objeto" << endl;
					cout << "Ingrese el valor de xo" << endl;
					cin >> xo;
					cout << "Ingrese el valor de vo" << endl;
					cin >> vo;
					cout << "Ingrese el valor de v" << endl;
					cin >> v;
					cout << "Ingrese el valor de t" << endl;
					cin >> timp;
					xp2 = xo + (1 / 2) * (v + vo)* timp;
					system("cls");
					cout << "La posicion del objeto es: " << xp2 << endl;
					break;
				}
			} 			while (z != 5);
			break;
		case 4:
			do {
				cout << "1. Resistencia resultante (en serie)" << endl;
				cout << "2. Resistencia resultante (en paralelo)" << endl;
				cout << "3. Voltaje" << endl;
				cout << "4. Intensidad" << endl;
				cout << "5. Resistencia" << endl;
				cout << "6. Salir" << endl;
				cin >> q;
				system("cls");
				switch (q) {
				case 1:
					cout << "Formula de resistencia resultante" << endl;
					cout << "Cuantas resistencias en serie tiene?" << endl;
					cin >> rs;
					for (int i = 0; i < rs; i++) {
						cout << "Ingrese el valor de la resistencia " << i + 1 << endl;
						cin >> Rs;
						rn = rn + Rs;
					}
					system("cls");
					cout << "El valor de la resistencia total es: " << rn << endl;
					break;
				case 2:
					cout << "Formula de resistencia resultante" << endl;
					cout << "Cuantas resistencias en paralelo tiene?" << endl;
					cin >> rs;
					for (int j = 0; j < rs; j++) {
						cout << "Ingrese el valor de la resistencia " << j + 1 << endl;
						cin >> Rs;
						rp = 1 / Rs;
						rn = rn + rp;
					}
					system("cls"),
						cout << "El valor de la resistencia total es: " << 1 / rn << endl;
					break;
				case 3:
					cout << "Formula de voltaje" << endl;
					cout << "Ingrese el valor de I" << endl;
					cin >> inten;
					cout << "Ingrese el valor de R" << endl;
					cin >> resis;
					vol = inten / resis;
					system("cls");
					cout << "El valor del voltaje es: " << vol << endl;
					break;
				case 4:
					cout << "Formula de intensidad" << endl;
					cout << "Ingrese el valor de v" << endl;
					cin >> vol;
					cout << "Ingrese el valor de R" << endl;
					cin >> resis;
					inten = vol / resis;
					system("cls");
					cout << "El valor de la intensidad es: " << inten << endl;
					break;
				case 5:
					cout << "Formula de resistencia" << endl;
					cout << "Ingrese el valor de v" << endl;
					cin >> vol;
					cout << "Ingrese el valor de I" << endl;
					cin >> inten;
					resis = vol / inten;
					system("cls");
					cout << "El valor de la resistencia es: " << resis << endl;
					break;
				}
			} 			while (q != 6);
			break;

		}
	}
	while (a != 5);
	despedida();
}

float tye(float x, float y) {
	float z;
	z = x / y;
	return z;
}

float inter(float a1/*y0*/, float a2/*X*/, float a3/*x0*/, float a4/*y1*/, float a5/*x1*/) {
	float a6;
	a6 = a1+((a2-a3)/(a5-a3))*(a4-a1);
	return a6;
}

void bienvenida() {
	string saludo[12] = { "B","i","e","n","v","e","n","i","d","o","s" };
	char inst[80] = "Al ingresar, proporcione sus datos, posteriormente ingresara a la calculadora";
	for (int i = 0; i < 11; i++) {
		cout << saludo[i];
		Sleep(150);
	}
	cout << " " << endl;
	cout << inst << endl;;
}

void despedida() {
	string bye[14] = { "T","e","n","g","a"," ","b","u","e","n"," ","d","i","a" };
		for (int i = 0; i < 14; i++) {
			cout << bye[i];
			Sleep(150);
	}
}
