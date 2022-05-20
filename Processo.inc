/*
 * Progresso

 *  CRIADO POR: iShifT

 (c) 2020 - 2022
*/

#include <a_samp>

enum ProgressInfo
{
	p_callback[32],
	p_time,
	p_timer,
	Float:p_percent
}
new Progress_Info[MAX_PLAYERS][ProgressInfo], PlayerText:PlayerTD[MAX_PLAYERS][4];

#define CallProg::%0(%1) forward %0(%1); public %0(%1)

#define DEFAULT_TIMER (50) // Melhor

#define Progresso:%0(%1,%2) \
	forward Progress_%0(%1,Float:%2); public Progress_%0(%1,Float:%2)

stock CreateProgress(playerid, callback[], time = 1000)
{
	Progress_Info[playerid][p_percent] = 0;
	format(Progress_Info[playerid][p_callback], 32, "Progress_%s", callback);
	Progress_Info[playerid][p_time] = time;

	CreateTDProgress(playerid);

	for(new i = 0; i < 4; i++)
	{
		PlayerTextDrawShow(playerid, PlayerTD[playerid][i]);
	}

	Progress_Info[playerid][p_timer] = SetTimerEx("UpdateProgress", Progress_Info[playerid][p_time], true, "i", playerid);
	return 1;
}

CallProg:: UpdateProgress(playerid)
{

	if(Progress_Info[playerid][p_percent] >= 100.0)
	{
		return KillProgress(playerid);
	}

	new string[10]; 
	format(string, sizeof(string), "%.0f%", Progress_Info[playerid][p_percent]);
	PlayerTextDrawSetString(playerid, PlayerTD[playerid][2], string);

	Progress_Info[playerid][p_percent] += 1; //(100 / Progress_Info[playerid][p_percent]); //
	PlayerTextDrawTextSize(playerid, PlayerTD[playerid][1], (246)+(Progress_Info[playerid][p_percent] * (1.52)), 1.0);
	PlayerTextDrawShow(playerid, PlayerTD[playerid][1]);
	
	CallLocalFunction(Progress_Info[playerid][p_callback], "df", playerid, Progress_Info[playerid][p_percent]);
	return 1;
}

stock KillProgress(playerid)
{
	for(new i = 0; i < 4; i++)
	{
		PlayerTextDrawDestroy(playerid, PlayerTD[playerid][i]);
	}
	format(Progress_Info[playerid][p_callback], 32, "");
	KillTimer(Progress_Info[playerid][p_timer]);
	Progress_Info[playerid][p_time] = 18;
	Progress_Info[playerid][p_percent] = 0;
	return 1;
}

stock CreateTDProgress(playerid)
{
	PlayerTD[playerid][0] = CreatePlayerTextDraw(playerid, 322.000000, 351.000000, "_");
	PlayerTextDrawFont(playerid, PlayerTD[playerid][0], 1);
	PlayerTextDrawLetterSize(playerid, PlayerTD[playerid][0], 0.600000, 1.300003);
	PlayerTextDrawTextSize(playerid, PlayerTD[playerid][0], 298.500000, 155.000000);
	PlayerTextDrawSetOutline(playerid, PlayerTD[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, PlayerTD[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, PlayerTD[playerid][0], 2);
	PlayerTextDrawColor(playerid, PlayerTD[playerid][0], -1);
	PlayerTextDrawBackgroundColor(playerid, PlayerTD[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, PlayerTD[playerid][0], 245);
	PlayerTextDrawUseBox(playerid, PlayerTD[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, PlayerTD[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, PlayerTD[playerid][0], 0);

	PlayerTD[playerid][1] = CreatePlayerTextDraw(playerid, 246.000000, 352.000000, "~b~");
	PlayerTextDrawFont(playerid, PlayerTD[playerid][1], 1);
	PlayerTextDrawLetterSize(playerid, PlayerTD[playerid][1], 0.254166, 1.050000);
	PlayerTextDrawTextSize(playerid, PlayerTD[playerid][1], 246.000000, 18.000000);
	PlayerTextDrawSetOutline(playerid, PlayerTD[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, PlayerTD[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, PlayerTD[playerid][1], 1);
	PlayerTextDrawColor(playerid, PlayerTD[playerid][1], 1687547391);
	PlayerTextDrawBackgroundColor(playerid, PlayerTD[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, PlayerTD[playerid][1], 1687547376);
	PlayerTextDrawUseBox(playerid, PlayerTD[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, PlayerTD[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, PlayerTD[playerid][1], 0);

	PlayerTD[playerid][2] = CreatePlayerTextDraw(playerid, 307.000000, 352.000000, "100%");
	PlayerTextDrawFont(playerid, PlayerTD[playerid][2], 2);
	PlayerTextDrawLetterSize(playerid, PlayerTD[playerid][2], 0.254166, 1.050000);
	PlayerTextDrawTextSize(playerid, PlayerTD[playerid][2], 398.500000, 18.000000);
	PlayerTextDrawSetOutline(playerid, PlayerTD[playerid][2], 0);
	PlayerTextDrawSetShadow(playerid, PlayerTD[playerid][2], 1);
	PlayerTextDrawAlignment(playerid, PlayerTD[playerid][2], 1);
	PlayerTextDrawColor(playerid, PlayerTD[playerid][2], -1);
	PlayerTextDrawBackgroundColor(playerid, PlayerTD[playerid][2], 255);
	PlayerTextDrawBoxColor(playerid, PlayerTD[playerid][2], -16);
	PlayerTextDrawUseBox(playerid, PlayerTD[playerid][2], 0);
	PlayerTextDrawSetProportional(playerid, PlayerTD[playerid][2], 1);
	PlayerTextDrawSetSelectable(playerid, PlayerTD[playerid][2], 0);

	PlayerTD[playerid][3] = CreatePlayerTextDraw(playerid, 318.000000, 335.000000, "processando");
	PlayerTextDrawFont(playerid, PlayerTD[playerid][3], 2);
	PlayerTextDrawLetterSize(playerid, PlayerTD[playerid][3], 0.254166, 1.050000);
	PlayerTextDrawTextSize(playerid, PlayerTD[playerid][3], 398.500000, 158.000000);
	PlayerTextDrawSetOutline(playerid, PlayerTD[playerid][3], 0);
	PlayerTextDrawSetShadow(playerid, PlayerTD[playerid][3], 1);
	PlayerTextDrawAlignment(playerid, PlayerTD[playerid][3], 2);
	PlayerTextDrawColor(playerid, PlayerTD[playerid][3], -1);
	PlayerTextDrawBackgroundColor(playerid, PlayerTD[playerid][3], 255);
	PlayerTextDrawBoxColor(playerid, PlayerTD[playerid][3], -16);
	PlayerTextDrawUseBox(playerid, PlayerTD[playerid][3], 0);
	PlayerTextDrawSetProportional(playerid, PlayerTD[playerid][3], 1);
	PlayerTextDrawSetSelectable(playerid, PlayerTD[playerid][3], 0);
	return 1;
}


/*
	// Usage:
	
	public OnPlayerConnect(playerid)
	{
		CreateProgress(playerid, "Teste", 50); //   0.50 * 100 = (0.50ms)
	}

	Progresso:Teste(playerid, progress)
	{
		if(progress == 1){ SendClientMessage(playerid, -1, "Running"); }
		if(progress >= 100)
		{
			SendClientMessage(playerid, -1, "Finish");
		}
		return 1;
	}
*/