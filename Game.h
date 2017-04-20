#ifndef GAME_H
#define GAME_H

#include "ScreenUtils.h"

/**
\mainpage Game.
*/
/**
   \file Game.h
   \brief Funciones de control de flujo del juego y TDA CGame.
}*/

/**
    \brief TDA CGame
 */
typedef struct CGame* CGame;

/**
  \brief Asigna memoria y retorna el puntero de tipo CGame.
  \param Pointer Estructura creada de �tiles de pantalla.
  \param Int Nivel de dificultad de la IA.
  \return Retorna un puntero a la direcci�n de memoria asignada por esta.
 */
CGame Game_Load(CScreen pScreenUtils, int iAILevel);

/**
  \brief Libera la memoria asignada por Game_Load.
  \param Pointer Juego a liberar.
 */
void Game_Free(CGame pGame);

/**
  \brief Obtiene la informaci�n de un agujero seg�n su �ndice.
  \param Pointer Estructura creada de juego.
  \param Int �ndice del agujero.
  \param Float* Variable en la que se asignar� la coordenada X del agujero.
  \param Float* Variable en la que se asignar� la coordenada Y del agujero.
  \param Float* Variable en la que se asignar� el radio del agujero.
 */
void Game_GetCornerDataByIndex(CGame pGame, int iIndex, float* fX, float* fY, float* fRadius);

/**
  \brief A�ade puntuaci�n al jugador si es de tipo 0 y a los dos si es de tipo 1.
  \param Pointer Estructura creada de juego.
  \param Int Tipo de puntuaci�n. 0 = puntuaci�n actual, 1 = puntuaci�n combo.
  \param Int Cantidad a sumar de puntuaci�n.
 */
void Game_AddScore(CGame pGame, int iType, int iScore);

/**
  \brief Dibuja un mensaje con colores r, g, b en medio de la pantalla.
  \param Pointer Estructura creada de juego.
  \param Int Cantidad de color rojo del mensaje.
  \param Int Cantidad de verde rojo del mensaje.
  \param Int Cantidad de azul rojo del mensaje.
 */
void Game_DrawMsg(CGame pGame, char* szMsg, int r, int g, int b);

/**
  \brief Dibuja en pantalla de qui�n es el turno en el instante de la llamada a esta.
  \param Pointer Estructura creada de juego.
 */
void Game_DrawTurn(CGame pGame);

/**
  \brief Guarda el record actual.
  \param Pointer Estructura creada de juego.
 */
void Game_SaveRecord(CGame pGame);

/**
  \brief Coloca el estado de perder en 1.
  \param Pointer Estructura creada de juego.
 */
void Game_GameOver(CGame pGame);

/**
  \brief Coloca el estado de "ganar" en 1.
  \param Pointer Estructura creada de juego.
 */
void Game_WinGame(CGame pGame);

/**
  \brief Empieza a cerrar el tablero para volver al men� principal.
  \param Pointer Estructura creada de juego.
 */
void Game_StartClosing(CGame pGame);

/**
  \brief Cambia de turno.
  \param Pointer Estructura creada de juego.
 */
void Game_ToggleTurn(CGame pGame);

/**
  \brief Dibuja en pantalla la puntuaci�n actual.
  \param Int Puntuaci�n a dibujar.
 */
void Game_DrawScore(int iScore);

/**
  \brief Renderiza el texto de ganador si el usuario gan�.
 */
void Game_DrawWinner();

/**
  \brief Renderiza el texto de perdedor si el usuario perdi�.
 */
void Game_DrawLoser();

/**
  \brief Averigua qui�n es el ganador y llama a Game_DrawWinner o Game_DrawLoser dependiendo de quien gan�.
  \param Pointer Estructura creada de juego.
 */
void Game_RenderWinner(CGame pGame);

/**
  \brief Dispara la bola, de la IA o del usuario.
  \param Pointer Estructura creada de juego.
  \return Retorna 1 si la IA o el usuario han lanzado, de lo contrario, retorna 0.
 */
int Game_ShootWhiteBall(CGame pGame);

/**
  \brief Obtiene si el usuario puede lanzar.
  \param Pointer Estructura creada de juego.
  \return Retorna 1 si puede lanzar, de lo contrario, retorna 0.
 */
int Game_CanShoot(CGame pGame);

/**
  \brief Obtiene si el juego se ha perdido (da igual si pierde la IA o el usuario).
  \param Pointer Estructura creada de juego.
  \return Retorna 1 si se ha perdido el juego, de lo contrario, retorna 0.
 */
int Game_IsGameOver(CGame pGame);

/**
  \brief Obtiene si se est� cerrando el tablero de juego para ir al men� principal.
  \param Pointer Estructura creada de juego.
  \return Retorna 1 si se est� cerrando, de lo contrario, retorna 0.
 */
int Game_IsClosing(CGame pGame);

/**
  \brief Obtiene de qui�n es el turno.
  \param Pointer Estructura creada de juego.
  \return Retorna 1 si el turno es del usuario, de lo contrario, retorna 0.
 */
int Game_GetTurn(CGame pGame);

/**
  \brief Obtiene la puntuaci�n del usuario.
  \param Pointer Estructura creada de juego.
  \param Int El tipo de puntuaci�n. 0 = puntuaci�n actual, 1 = puntuaci�n combo.
  \return Retorna la puntuaci�n del tipo dado.
 */
int Game_GetScore(CGame pGame, int iType);

/**
  \brief Renderiza el tablero y controla la mec�nica de juego.
  \param Pointer Estructura creada de juego.
  \return Retorna 1 si va se va a salir al men� principal, de lo contrario, retorna 0.
 */
int Game_Render(CGame pGame);


#endif
