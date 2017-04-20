#ifndef MAINMENU_H
#define MAINMENU_H

#include "ScreenUtils.h"

/**
\mainpage Menu Principal
*/
/**
   \file MainMenu.h
   \brief Utilizado para controlar el men� principal y todas sus interacciones: Empezar a jugar, mirar los records, cambiar configuraciones y salir.
}*/

/**
    \brief TDA Menu Principal
 */
typedef struct CMainMenu* CMainMenu;

/**
  \brief Asigna memoria y retorna un puntero de tipo CMainMenu.
  \param Pointer Estructura de �tiles de pantalla.
  \param Int Utilizada para especificar si se carga por segunda vez sin cerrar el juego. Sirve para no cargar recursos que no se necesitan m�s.
  \return Retorna un puntero a la direcci�n de memoria asignada por esta.
 */
CMainMenu MainMenu_Load(CScreen pScreenUtils, int iRecursiveLoad);

/**
  \brief Libera la memoria asignada por MainMenu_Load.
  \param Pointer Men� principal a liberar.
 */
void MainMenu_Free(CMainMenu pMenu);

/**
  \brief Controla las teclas pulsadas en el men� principal para las acciones.
  \param Pointer Estructura creada del men� principal.
  \param Pointer Estructura creada de �tiles de pantalla.
  \return Retorna la siguiente acci�n a cumplir. 0 = nada/entrar a records/entrar a configuraciones, -1 = salir del juego, -2 = jugar.
 */
int MainMenu_DispatchKeys(CMainMenu pMenu, CScreen pScreenUtils);

/**
  \brief Actualiza el men� completo: Renderiza las im�genes y llama las dem�s funciones para su funcionamiento.
  \param Pointer Estructura creada del men� principal.
  \param Pointer Estructura creada de �tiles de pantalla.
  \return Retorna la siguiente acci�n a cumplir. 0 = nada/entrar a records/entrar a configuraciones, -1 = salir del juego, -2 = jugar.
 */
int MainMenu_UpdateMenu(CMainMenu pMenu, CScreen pScreenUtils);

/**
  \brief Actualiza la secci�n del men� principal.
  \param Pointer Estructura creada del men� principal.
  \param Pointer Estructura creada de �tiles de pantalla.
  \return Retorna varios valores. 0 = nada, -2 = inicia transici�n del men� principal al tablero de juego, -1 = salir del juego, mayor o igual que 1 = entrada directa al tablero de juego.
 */
int MainMenu_UpdateGeneral(CMainMenu pMenu, CScreen pScreenUtils);

/**
  \brief Actualiza la secci�n de records.
  \param Pointer Estructura creada del men� principal.
  \param Pointer Estructura creada de �tiles de pantalla.
  \return Retorna -1 si los records no se cargaron, de lo contrario, retorna 0.
 */
int MainMenu_UpdateRecords(CMainMenu pMenu, CScreen pScreenUtils);

/**
  \brief Actualiza la secci�n de settings.
  \param Pointer Estructura creada del men� principal.
  \param Pointer Estructura creada de �tiles de pantalla.
  \return Retorna -1 si los records no se cargaron, de lo contrario, retorna 0.
 */
int MainMenu_UpdateSettings(CMainMenu pMenu, CScreen pScreenUtils);

/**
  \brief Guarda las configuraciones editadas por el usuario.
  \param Pointer Estructura creada del men� principal.
  \return Retorna 1 si se guardo correctamente, de lo contrario, retorna 0.
 */
int MainMenu_SaveConfigs(CMainMenu pMenu);

/**
  \brief Carga las configuraciones editadas por el usuario.
  \param Pointer Estructura creada del men� principal.
  \return Retorna 1 si se guardo correctamente, de lo contrario, retorna 0.
 */
int MainMenu_LoadConfigs(CMainMenu pMenu);

/**
  \brief Sale del juego.
  \param Pointer Estructura creada del men� principal.
  \return Retorna -1 para cerrar el juego.
 */
int MainMenu_ExitGame(CMainMenu pMenu);

/**
  \brief Interpola la posici�n de la flecha.
  \param Pointer Estructura creada del men� principal.
  \param Float Velocidad de interpolaci�n.
 */
void MainMenu_InterpolateArrow(CMainMenu pMenu, float fVel);

/**
  \brief Aplica las configuraciones seg�n eliga el usuario.
  \param Pointer Estructura creada del men� principal.
  \param Pointer Estructura de �tiles de pantalla.
 */
void MainMenu_ChangeConfigs(CMainMenu pMenu, CScreen pScreenUtils);

/**
  \brief Restringe las IDs de las configuraciones.
  \param Pointer Estructura creada del men� principal.
 */
void MainMenu_ClampConfigs(CMainMenu pMenu);

#endif
