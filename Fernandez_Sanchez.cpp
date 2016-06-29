/*
	Guillermo Fernández.	CI: V-23.751.818
	Alexandra Sánchez.		CI: V-26.239.664
*/

#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string>
#include <sstream>
#include <fstream>

namespace patch {
    template < typename T > std::string to_string(const T& n) {
        std::ostringstream stm;
        stm << n;
        return stm.str();
    }
}

using namespace std;

void heading() {
	cout << "************************************************************************************************************************" << endl;
	cout << "|\t\t\t\t\t\t   Tienda \"El Bachaquero\"\t\t\t\t\t\t       |" << endl;
	cout << "|======================================================================================================================|" << endl;
	cout << "|\t\t\t\t\t\tSistema de registro de ventas\t\t\t\t\t\t       |" << endl;
	cout << "************************************************************************************************************************" << endl;
}
void error404() {
	cout << "|\t\t\t\t\t\t ERROR 404: DATA NOT FOUND\t\t\t\t\t\t       |" << endl;
	cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
	cout << "|\t\t\t\t\t\t  No hay datos procesados\t\t\t\t\t\t       |" << endl;
	cout << "|\t\t\t     Por favor ingrese los datos a trav\202s de la opci\242n 1 del men\243 principal\t\t\t       |" << endl;
	cout << "************************************************************************************************************************" << endl;
	Sleep(3000);
}
void error101(){
	cout << "|\t\t\t\t\t\tERROR 101: OPTION NOT FOUND\t\t\t\t\t\t       |" << endl;
	cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
	cout << "|\t\t\t\t\t      Ha ingresado una opci\242n inv\240lida\t\t\t\t\t\t       |" << endl;
	cout << "|\t\t\t      Por favor ingrese una de las opciones presentes en el men\243 principal\t\t\t       |" << endl;
	cout << "************************************************************************************************************************" << endl;
	Sleep(3000);
}

int main() {
	system("cls");
	ifstream first;
	first.open("cache");
	if (!first.is_open()) {
		// cache no existe, se creará al final
		heading();
		cout << endl;
		cout << "\tPor favor, ajuste el ancho de la ventana de la consola a 122 para" << endl;
		cout << "\tpoder observar correctamente los datos impresos ac\240, muchas gracias." << endl << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		ofstream last;
		last.open("cache");
		system("attrib -s +h -i cache");
		last.close();
		system("pause");
	} else {
		// caché sí existe
		first.close();
	}
	int n;
	system("cls");
	heading();
	cout << "\tIngrese la cantidad de productos distribuidos = ";
	cin >> n;
	// var declaration
	int optn, j, i, acum3, highAmount, highMonth, highName, highAmount2, highMonth2, highName2, totalVentasAno, totalVentasMes, decs;
	double neto, moneyIn, moneyOut, moneyOutSrvc, moneyMadeTotal, moneyOutTax, moneyOutPay, totalPrcnt1, acum88;
	bool aux = false;
	// string declaration
	string srvcPay;
	string taxPay;
	string emplPay;
	string tMoney;
	string tSpend;
	string tEarn;
	// stringstream declaration	
	stringstream streamSrvc;
	stringstream streamTax;
	stringstream streamEmpl;
	stringstream streamTotal;
	stringstream streamSpend;
	stringstream streamEarn;
	// arrays declaration
	stringstream streamPrd[n];
	string trunc[n+1];
	string priceSymb[n];
	string priceProd[n];
	string productName[n];
	string productName2[n];
	double precios[n];
	double totalProducto[n];
	double moneyMadeProd[n];
	double prcntYearSalesPrdct[n];
	double prcntMonthSalesPrdct[n];
	double percentv2[n][12];
	double totalMes[12];
	double totalPrcnt2[12];
	int mostSoldMonth[12];
	int mostSoldName[12];
	int mostSoldQty[12];
	int product1[n][12];																			// uncomment when finished
	string meses[12] = 		{"Ene", "Feb", "Mar", "Abr", "May", "Jun", "Jul", "Ago", "Sep", "Oct", "Nov", "Dic"};
	string mesesFull[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
							"Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
	
	do {
		system("cls");
		heading();
		cout << "|\t\t\t\t\t\t Men\243 principal de opciones\t\t\t\t\t\t       |" << endl;
		cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
		cout << "\t1. Ingresar datos" << endl;
		cout << "\t2. Total de ventas de cada uno de los productos" << endl;
		cout << "\t3. Total de ventas de cada mes" << endl;
		cout << "\t4. Producto m\240s vendido en cada mes" << endl;
		cout << "\t5. Producto m\240s vendido en todo el a\244o" << endl;
		cout << "\t6. Porcentaje de productos vendido por cada mes" << endl;
		cout << "\t7. Porcentaje vendido de cada producto" << endl;
		cout << "\t8. Balance" << endl;
		cout << "\t9. Mostrar datos" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\t0. Salir del sistema" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\tEscoja su opci\242n = ";
		cin >> optn;
		switch (optn) {
			case 1:
				/************************** ZERO INIT **************************/
				/* int vars */
				i = j = acum3 = highAmount = highMonth = highName = highAmount2 = highMonth2 = highName2 = totalVentasAno = totalVentasMes = 0;
				/* float vars*/
				neto = moneyIn = moneyOut = moneyOutSrvc = moneyMadeTotal = moneyOutTax = moneyOutPay = totalPrcnt1 = acum88 = 0;
				
				/* string vars */
				srvcPay.clear();
				taxPay.clear();
				emplPay.clear();
				tMoney.clear();
				tSpend.clear();
				tEarn.clear();
				
				/* stringstream vars */
					streamSrvc.str("");
					streamTax.str("");
					streamEmpl.str("");
					streamTotal.str("");
					streamSpend.str("");
					streamEarn.str("");
				
				// n*12 matrices
				for (i=0; i<n; i++) {
					for (j=0; j<12; j++) {
						percentv2[i][j] = 0;
					}
				}
				
				// 12 arrays
				for (i=0; i<12; i++) {
						totalMes[i] = 0;
						totalPrcnt2[i] = 0;
						mostSoldMonth[i] = 0;
						mostSoldName[i] = 0;
						mostSoldQty[i] = 0;
				}
				
				// n arrays
				for (i=0; i<n; i++) {
					precios[i] = 0;
					totalProducto[i] = 0;
					moneyMadeProd[i] = 0;
					prcntYearSalesPrdct[i] = 0;
					prcntMonthSalesPrdct[i] = 0;
					streamPrd[i].str("");
					priceSymb[i].clear();
					priceProd[i].clear();
					productName[i].clear();
				}
				
				for (i=0; i<(n+1); i++) { 
					trunc[i].clear();
				}
				
				// asking data and printing
				system("cls");
				heading();
				cout << "|\t\t\t\t\t\t    Ingrese las ventas:\t\t\t\t\t\t\t       |" << endl;
				cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
				// giving value to main matrix
				for (i=0; i<n; i++) {
					cout << "\tPor favor, intente que el nombre no sea mayor a 11 caracteres" << endl;
					cout << "\tIngrese el nombre del producto \43" << (i+1) << ": ";
					cin >> productName[i];
					for (j=0; j<12; j++) {
						cout << "\tIngrese las ventas de " << productName[i] << " del mes de " << mesesFull[j] << " = ";
						cin >> product1[i][j];														// asign. de celdas de main matrix (product1[n][12])
						cout << endl;
					}
				}
				cout << "------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << "Datos de las ventas completados . . ." << endl;
				system("pause");
				system("cls");
				heading();
				cout << "|\t\t\t\t\t\t Ingrese los precios:\t\t\t\t\t\t\t       |" << endl;
				cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl << endl;
				cout << "\tNota: El precio que ingrese se le asignar\240 al primer producto." << endl;
				cout << "\t      El precio de los dem\240s ir\240 aumentando de 3 en 3." << endl << endl;
				cout << "\tIngrese el precio del primer producto = \44";
				cin >> neto;
				cout << endl << "------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << "Datos de precios completados . . ." << endl;
				system("pause");
				system("cls");
				heading();
				cout << "\t\t\t\t\tProcesando los datos ingresados" << endl;
				cout << "\t\t\t\t\t      [";
				for (i=0; i<4; i++) {
					for (j=0; j<5; j++) {
						cout << "\376";
						Sleep(50);
					}
				}
				cout << "]" << endl;
				/* procesando cálculos */
				// totales
				for (i=0; i<12; i++) {																// venta total de cada producto en todo el año
					for (j=0; j<n; j++) {
						totalProducto[j] += product1[j][i];
					}
				}
				for (i=0; i<n; i++) {																
					for (j=0; j<12; j++) {
						if (highAmount == 0) {														// busqueda de producto más vendido en todo el año
							highAmount = product1[i][j];
							highMonth = j;
							highName = i;
						}
						if (highAmount < product1[i][j]) {
							highAmount = product1[i][j];
							highMonth = j;
							highName = i;
						}
					}
				}
				for (i=0; i<n; i++) {
					for (j=0; j<12; j++) {
						totalMes[j] += product1[i][j];												// ventas totales en cada mez
					}
				}
				for (i=0; i<12; i++) {																// búsqueda de producto más vendido en cada mes
					highMonth2 = 0;
					highName2= 0;
					highAmount2 = 0;
					for (j=0; j<n; j++) {
						if (highAmount2 == 0) {
							highAmount2 = product1[j][i];
							highMonth2 = i;
							highName2 = j+1;
						}
						if (highAmount2 < product1[j][i]) {
							highAmount2 = product1[j][i];
							highMonth2 = i;
							highName2 = j+1;
						}
					}
					mostSoldMonth[i] = highMonth2;
					mostSoldName[i] = highName2;
					mostSoldQty[i] = highAmount2;
					if (mostSoldQty[i] == 0) { 
						mostSoldName[i] = 0;
					}
				}
				for (i=0; i<n; i++) {
					productName2[i] = productName[i];
				}
				
				// porcentajes
				/* v1 */
				for (i=0; i<n; i++) {
					totalVentasAno += totalProducto[i];
				}
				for (i=0; i<n; i++) {
					prcntYearSalesPrdct[i] = totalProducto[i] / totalVentasAno * 100;
				}
				for (i=0; i<n; i++) {
					totalPrcnt1 += prcntYearSalesPrdct[i];
				}
				/* v2 */
				for (i=0; i<n; i++) {
					for (j=0; j<12; j++){
						if (product1[i][j] == 0) {
							percentv2[i][j] == 0;
						} else {
							percentv2[i][j] = product1[i][j] / totalMes[j] * 100;
						}
					}
				}
				for (i=0; i<12; i++) {
					acum88 = 0;
					for (j=0; j<n; j++) {
						acum88 += percentv2[j][i];
					}
					totalPrcnt2[i] = acum88;
				}
				for (i=0; i<n; i++) {																// proceso de asignación de precios a
					precios[i] = neto;																// cada producto, tomando en cuenta que
				}																					// el precio del primer producto es x,
				for (i=1; i<n; i++) {																// el del segundo es x+3, el del tercero
					acum3 = acum3+3;																// es x+(2*3), el del cuarto es x+(3*3)
					precios[i] += acum3;															// y así sucesivamente. [x+(n*3)]
				}
				for (i=0; i<n; i++) {
					moneyMadeProd[i] = precios[i] * totalProducto[i];								// +dinero producido por cada producto
				}
				for (i=0; i<n; i++) {
					moneyMadeTotal += moneyMadeProd[i];												// +dinero producido en total
				}
				moneyOutPay = moneyMadeTotal * 0.215;												// -dinero por pago de empleados (21.5%)
				moneyOutTax = moneyMadeTotal * 0.16;												// -dinero por pago de impuestos (16%)
				moneyOutSrvc = moneyMadeTotal * 0.15;												// -dinero por pago de servicios (15%)
				moneyOut = moneyOutSrvc + moneyOutTax + moneyOutPay;
				moneyIn = moneyMadeTotal - moneyOut;
				for (i=0; i<n; i++) {
					priceSymb[i] = "\44" + patch::to_string(precios[i]);
				}
				for (i=0; i<n; i++) {
					streamPrd[i] << fixed << setprecision(2) << moneyMadeProd[i];
					priceProd[i] = "\44" + streamPrd[i].str();
				}
				streamSrvc << fixed << setprecision(2) << moneyOutSrvc;
				streamTax << fixed << setprecision(2) << moneyOutTax;
				streamEmpl << fixed << setprecision(2) << moneyOutPay;
				streamTotal << fixed << setprecision(2) << moneyMadeTotal;
				streamSpend << fixed << setprecision(2) << moneyOut;
				streamEarn << fixed << setprecision(2) << moneyIn;
				srvcPay = "\44" + streamSrvc.str();
				taxPay = "\44" + streamTax.str();
				emplPay = "\44" + streamEmpl.str();
				tMoney = "\44" + streamTotal.str();
				tSpend = "\44" + streamSpend.str();
				tEarn = "\44" + streamEarn.str();
				aux = true;
				break;
				
			case 2:
				system("cls");
				heading();
				if (aux) {
					cout << "|\t\t\t\t     Total de ventas de cada uno de los productos:\t\t\t\t\t       |" << endl;
					cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
					for (i=0; i<n; i++) {
						cout << "\t" << right << setw(30) << productName[i] << ": " << fixed << setprecision(0) << setw(15) << totalProducto[i] << endl;
					}
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "\t  " << right << setw(30) << "Total ventas en el a\244o: " << setw(15) << totalVentasAno << endl;
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
					cout << endl << left;
					system("pause");
				} else {
					error404();
				}
				break;
			
			case 3:
				system("cls");
				heading();
				if (aux) {
					cout << "|\t\t\t\t\t      Total de ventas en cada mes:\t\t\t\t\t\t       |" << endl;
					cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl << "\t\t | ";
					for (i=0; i<12; i++) {
						cout << meses[i] << "\t | ";
					}
					cout << endl << "\t\t |";
					for (i=0; i<12; i++) {
						cout << setw(6) << right << fixed << setprecision(0) << totalMes[i] << " |";
					}
					cout << endl << left;
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl << endl;
					system("pause");
				} else {
					error404();
				}
				break;

			case 4:
				system("cls");
				heading();
				trunc[0] = "NA";
				if (aux) {
					for (i=0; i<n; i++) {
						productName2[i].resize(5);
						trunc[i+1] = productName2[i];
					}
					cout << "|\t\t\t\t\t    Producto m\240s vendido en cada mes:\t\t\t\t\t\t       |" << endl;
					cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
					for (j=0; j<3; j++) {
						if (j==0) {
							cout << setw(16) << left << "Mes";
							for (i=0; i<12; i++) {
								cout << "| " << setw(6) << (meses[mostSoldMonth[i]]);
							}
							cout << "|" << endl;
						}
						if (j==1) {
							cout << setw(16) << left << "Nombre";
							for (i=0; i<12; i++) {
								cout << left << "| " << setw(6) << trunc[mostSoldName[i]];
							}
							cout << "|" << endl;
						}
						if (j==2) {
							cout << setw(16) << left << "Cantidad";
							for (i=0; i<12; i++) {
								cout << "| " << setw(6) << mostSoldQty[i];
							}
							cout << "|";
						}
					}
					cout << endl << left;
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl << endl;
					system("pause");
				} else {
					error404();
				}
				break;

			case 5:
				system("cls");
				heading();
				if (aux) {
					cout << "|\t\t\t\t\t  Producto m\240s vendido en todo el ano:\t\t\t\t\t\t       |" << endl;
					cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl << endl;
					cout << "\t\t\t\t\t            Nombre: " << productName[highName] << endl;
					cout << "\t\t\t\t\tCantidad de ventas: " << highAmount << endl;
					cout << "\t\t\t\t\t      En el mes de: " << mesesFull[highMonth] << endl << endl;
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl << endl;
					cout << left;
					system("pause");
				} else {
					error404();
				}
				break;

			case 6:
				system("cls");
				heading();
				if (aux) {
					cout << "|\t\t\t\t\tPorcentaje de productos vendido por cada mes:\t\t\t\t\t       |" << endl;
					cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
					cout << "       " << right;
					for (i=0; i<12; i++) {
						cout << setw(6) << "| "  << meses[i];
					}
					cout << "    |" << endl;
					for (i=0; i<n; i++) {
						cout << setw(11) << left << productName[i] <<"|";
						for (j=0; j<12; j++){
							cout << right << setw(6) << fixed << setprecision(2) << percentv2[i][j] << "% |";
						}
						cout << endl;
					}
					cout << "Totales(\45) |";
					for (i=0; i<12; i++) {
						cout << setw(6) << fixed << setprecision(2) << totalPrcnt2[i] << "% |";
					}
					cout << endl;
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl << endl;
					cout << left;
					system("pause");
				} else {
					error404();
				}
				break;

			case 7:
				system("cls");
				heading();
				if (aux) {
					cout << "|\t\t\t\t\t     Porcentaje vendido de cada producto:\t\t\t\t\t       |" << endl;
					cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
					for (i=0; i<n; i++) {
						cout << "\t" << setw(40) << right << productName[i] << ": " << fixed << right << setprecision(4) << setw(15) << prcntYearSalesPrdct[i] << "\45" << endl;
					}
					cout << "\t\t" << setw(34) << right << "Total: " << fixed << setprecision(4) << setw(15) << totalPrcnt1 << "\45" << endl;
					
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl << endl;
					cout << left;
					system("pause");
				} else {
					error404();
				}
				break;

			case 8:
				system("cls");
				heading();
				if (aux) {
					cout << "|\t\t\t\t\t\t\tGanancias:\t\t\t\t\t\t\t       |" << endl;
					cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
					cout << "\tDinero restado por concepto de Pago de Servicios: " << right << setw(30) << srvcPay << endl;
					cout << "\tDinero restado por concepto de Pago de Impuestos: " << setw(30) << taxPay << endl;
					cout << "\tDinero restado por concepto de Pago de Empleados: " << setw(30) << emplPay << endl;
					cout << "\tMonto total a deducir:\t\t\t\t  " << setw(30) << tSpend << endl;
					cout << "\tMonto total recaudado:\t\t\t\t  " << setw(30) << tMoney << endl;
					cout << "\tGanancia total:\t\t\t\t\t  " << setw(30) << tEarn << endl;
					cout << "************************************************************************************************************************" << endl;
					cout << "|\t\t\t\t\t\tGanancias de cada producto:\t\t\t\t\t\t       |" << endl;
					cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
					for (i=0; i<n; i++) {
						cout << "\t" << setw(39) << right << productName[i] << ": " << fixed << setprecision(2) << setw(30) << priceProd[i] << endl;
					}
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl << endl;
					cout << left;
					system("pause");
				} else {
					error404();
				}
				break;

			case 9:
				system("cls");
				heading();
				if (aux) {
					cout << "|\t\t\t\tMostrando tabla completa de datos de ventas introducidos:\t\t\t\t       |" << endl;
					cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl << "\t";
					for (i=0; i<12; i++) {
						cout << "\t | " << meses[i];
					}
					cout << "\t |" << endl << right;
					for (i=0; i<n; i++) {
						cout << setw(17) << left << productName[i] << "|" << right;
						for (j=0; j<12; j++) {
							cout << setw(6) << product1[i][j] << " |";
						}
						cout << endl;
					}
					cout << endl;
					cout << "************************************************************************************************************************" << endl;
					cout << "|\t\t\t\t\t\tPrecios de los productos:\t\t\t\t\t\t       |" << endl;
					cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
					for (i=0; i<n; i++) {
						cout << "\t\t\t" << setw(30) << right << productName[i] << ":" << setw(20) << priceSymb[i] << endl;
					}
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl << endl;
					cout << left;
					system("pause");
				} else {
					error404();
				}
				break;
				
			case 911:
				cout << "\t\50\60\57\61\51: "; 
				cin >> decs;
				if (decs==1) {
					cout << "Borrando archivo \"cache\"" << endl;
					remove("cache");
					Sleep(500);
				}
				optn = 0;
				break;
				
			case 0:
				system("cls");
				heading();
				cout << "\tAdi\242s en nombre de todos los bachaqueros" << endl;
				Sleep(1500);
				break;
				
			default:
				system("cls");
				heading();
				error101();
				break;
		}
	} while (optn != 0);
}
