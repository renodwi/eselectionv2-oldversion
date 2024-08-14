/*
	Custom Selection made by Agus Syahputra
	Created Date: 14:09 -  29/10/2016
*/

#if defined _inc_eSelectionv2
	#undef _inc_eSelectionv2
#endif

#if defined _eSelectionv2_included
	#endinput
#endif
#define _eSelectionv2_included

#if !defined MAX_CUSTOM_MODEL
	#define MAX_CUSTOM_MODEL	(400)
#endif

#define CUSTOM_RESPONSE_CANCEL	(0)
#define CUSTOM_RESPONSE_FINAL	(1)

enum g_SelectionMenuEnum {
	PlayerText:CustomSelection[11],
	Float:CustomRot[4],
	CustomModel[MAX_CUSTOM_MODEL],
	CustomShown,
	CustomExtra,
	CustomIgnore,
	CustomTime,
	CustomPage,
	CustomPages
};

static stock
	RotationData[MAX_PLAYERS][g_SelectionMenuEnum]
;

stock HideCustomSelection(playerid)
{
	if (!IsPlayerConnected(playerid) || !RotationData[playerid][CustomShown])
	    return 0;

	for(new i = 0; i != MAX_CUSTOM_MODEL; i++) {
		if (i < 11) {
			PlayerTextDrawDestroy(playerid, RotationData[playerid][CustomSelection][i]);
		}
		RotationData[playerid][CustomModel][i] = -1;
	}
	RotationData[playerid][CustomShown] = 0;
	RotationData[playerid][CustomExtra] = 0;
	RotationData[playerid][CustomPage] = 0;
	RotationData[playerid][CustomPages] = 0;
	RotationData[playerid][CustomIgnore] = 1;

	RotationData[playerid][CustomRot][0] = 0.0;
	RotationData[playerid][CustomRot][1] = 0.0;
	RotationData[playerid][CustomRot][2] = 0.0;
	RotationData[playerid][CustomRot][3] = 1.0;

	CancelSelectTextDraw(playerid);
	return 1;
}

stock ShowCustomSelection(playerid, header[], extraid, items[], size = sizeof(items), Float:fRotX = 0.0, Float:fRotY = 0.0,  Float:fRotZ = 0.0, Float:fZoom = 1.0)
{
	if (!IsPlayerConnected(playerid))
	    return 0;

	if (size > MAX_CUSTOM_MODEL)
	    return printf("** Warning: Please increase \"MAX_CUSTOM_MODEL\" if you want to create more items.");

	if (RotationData[playerid][CustomShown]) {
	    HideCustomSelection(playerid);
	}

	for(new i = 0; i < MAX_CUSTOM_MODEL; i++) {
		if (i >= size) {
			RotationData[playerid][CustomModel][i] = -1;	
		}
		else
		{
			if (items[i] != -1) {
				RotationData[playerid][CustomModel][i] = items[i];
			}
			else {
				RotationData[playerid][CustomModel][i] = -1;
			}
		}
	}


	RotationData[playerid][CustomShown] = 1;
	RotationData[playerid][CustomExtra] = extraid;
	RotationData[playerid][CustomTime] = GetTickCount();
	RotationData[playerid][CustomPage] = 0;
	RotationData[playerid][CustomPages] = size;

	RotationData[playerid][CustomRot][0] = fRotX;
	RotationData[playerid][CustomRot][1] = fRotY;
	RotationData[playerid][CustomRot][2] = fRotZ;
	RotationData[playerid][CustomRot][3] = fZoom;

	RotationData[playerid][CustomSelection][0] = CreatePlayerTextDraw(playerid, 325.000000, 73.000000, "_");
	PlayerTextDrawFont(playerid, RotationData[playerid][CustomSelection][0], 1);
	PlayerTextDrawLetterSize(playerid, RotationData[playerid][CustomSelection][0], 0.850000, 33.800003);
	PlayerTextDrawTextSize(playerid, RotationData[playerid][CustomSelection][0], 298.500000, 275.000000);
	PlayerTextDrawSetOutline(playerid, RotationData[playerid][CustomSelection][0], 1);
	PlayerTextDrawSetShadow(playerid, RotationData[playerid][CustomSelection][0], 0);
	PlayerTextDrawAlignment(playerid, RotationData[playerid][CustomSelection][0], 2);
	PlayerTextDrawColor(playerid, RotationData[playerid][CustomSelection][0], -1);
	PlayerTextDrawBackgroundColor(playerid, RotationData[playerid][CustomSelection][0], 255);
	PlayerTextDrawBoxColor(playerid, RotationData[playerid][CustomSelection][0], 572732415);
	PlayerTextDrawUseBox(playerid, RotationData[playerid][CustomSelection][0], 1);
	PlayerTextDrawSetProportional(playerid, RotationData[playerid][CustomSelection][0], 1);
	PlayerTextDrawSetSelectable(playerid, RotationData[playerid][CustomSelection][0], 0);

	RotationData[playerid][CustomSelection][1] = CreatePlayerTextDraw(playerid, 321.000000, 101.000000, "_");
	PlayerTextDrawFont(playerid, RotationData[playerid][CustomSelection][1], 1);
	PlayerTextDrawLetterSize(playerid, RotationData[playerid][CustomSelection][1], 0.850000, -0.149996);
	PlayerTextDrawTextSize(playerid, RotationData[playerid][CustomSelection][1], 283.500000, 241.000000);
	PlayerTextDrawSetOutline(playerid, RotationData[playerid][CustomSelection][1], 1);
	PlayerTextDrawSetShadow(playerid, RotationData[playerid][CustomSelection][1], 0);
	PlayerTextDrawAlignment(playerid, RotationData[playerid][CustomSelection][1], 2);
	PlayerTextDrawColor(playerid, RotationData[playerid][CustomSelection][1], -1094795521);
	PlayerTextDrawBackgroundColor(playerid, RotationData[playerid][CustomSelection][1], 255);
	PlayerTextDrawBoxColor(playerid, RotationData[playerid][CustomSelection][1], -1094795521);
	PlayerTextDrawUseBox(playerid, RotationData[playerid][CustomSelection][1], 1);
	PlayerTextDrawSetProportional(playerid, RotationData[playerid][CustomSelection][1], 1);
	PlayerTextDrawSetSelectable(playerid, RotationData[playerid][CustomSelection][1], 0);

	RotationData[playerid][CustomSelection][2] = CreatePlayerTextDraw(playerid, 199.000000, 77.000000,  header);
	PlayerTextDrawFont(playerid, RotationData[playerid][CustomSelection][2], 1);
	PlayerTextDrawLetterSize(playerid, RotationData[playerid][CustomSelection][2], 0.424999, 2.149999);
	PlayerTextDrawTextSize(playerid, RotationData[playerid][CustomSelection][2], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, RotationData[playerid][CustomSelection][2], 0);
	PlayerTextDrawSetShadow(playerid, RotationData[playerid][CustomSelection][2], 1);
	PlayerTextDrawAlignment(playerid, RotationData[playerid][CustomSelection][2], 1);
	PlayerTextDrawColor(playerid, RotationData[playerid][CustomSelection][2], -1);
	PlayerTextDrawBackgroundColor(playerid, RotationData[playerid][CustomSelection][2], 255);
	PlayerTextDrawBoxColor(playerid, RotationData[playerid][CustomSelection][2], 50);
	PlayerTextDrawUseBox(playerid, RotationData[playerid][CustomSelection][2], 0);
	PlayerTextDrawSetProportional(playerid, RotationData[playerid][CustomSelection][2], 1);
	PlayerTextDrawSetSelectable(playerid, RotationData[playerid][CustomSelection][2], 0);

	RotationData[playerid][CustomSelection][3] = CreatePlayerTextDraw(playerid, 188.000000, 68.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, RotationData[playerid][CustomSelection][3], 5);
	PlayerTextDrawLetterSize(playerid, RotationData[playerid][CustomSelection][3], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RotationData[playerid][CustomSelection][3], 272.500000, 330.000000);
	PlayerTextDrawSetOutline(playerid, RotationData[playerid][CustomSelection][3], 0);
	PlayerTextDrawSetShadow(playerid, RotationData[playerid][CustomSelection][3], 0);
	PlayerTextDrawAlignment(playerid, RotationData[playerid][CustomSelection][3], 1);
	PlayerTextDrawColor(playerid, RotationData[playerid][CustomSelection][3], -1);
	PlayerTextDrawBackgroundColor(playerid, RotationData[playerid][CustomSelection][3], 0);
	PlayerTextDrawBoxColor(playerid, RotationData[playerid][CustomSelection][3], 255);
	PlayerTextDrawUseBox(playerid, RotationData[playerid][CustomSelection][3], 0);
	PlayerTextDrawSetProportional(playerid, RotationData[playerid][CustomSelection][3], 1);
	PlayerTextDrawSetSelectable(playerid, RotationData[playerid][CustomSelection][3], 0);
	PlayerTextDrawSetPreviewModel(playerid, RotationData[playerid][CustomSelection][3], RotationData[playerid][CustomModel][RotationData[playerid][CustomPage]]);
	PlayerTextDrawSetPreviewRot(playerid, RotationData[playerid][CustomSelection][3], fRotX, fRotY, fRotZ, fZoom);

	RotationData[playerid][CustomSelection][4] = CreatePlayerTextDraw(playerid, 242.000000, 380.000000, "DONE");
	PlayerTextDrawFont(playerid, RotationData[playerid][CustomSelection][4], 1);
	PlayerTextDrawLetterSize(playerid, RotationData[playerid][CustomSelection][4], 0.391666, 2.299999);
	PlayerTextDrawTextSize(playerid, RotationData[playerid][CustomSelection][4], 16.500000, 109.000000);
	PlayerTextDrawSetOutline(playerid, RotationData[playerid][CustomSelection][4], 0);
	PlayerTextDrawSetShadow(playerid, RotationData[playerid][CustomSelection][4], 1);
	PlayerTextDrawAlignment(playerid, RotationData[playerid][CustomSelection][4], 2);
	PlayerTextDrawColor(playerid, RotationData[playerid][CustomSelection][4], -1);
	PlayerTextDrawBackgroundColor(playerid, RotationData[playerid][CustomSelection][4], 255);
	PlayerTextDrawBoxColor(playerid, RotationData[playerid][CustomSelection][4], 1097458175);
	PlayerTextDrawUseBox(playerid, RotationData[playerid][CustomSelection][4], 1);
	PlayerTextDrawSetProportional(playerid, RotationData[playerid][CustomSelection][4], 1);
	PlayerTextDrawSetSelectable(playerid, RotationData[playerid][CustomSelection][4], 1);

	RotationData[playerid][CustomSelection][5] = CreatePlayerTextDraw(playerid, 339.000000, 380.000000, "BACK");
	PlayerTextDrawFont(playerid, RotationData[playerid][CustomSelection][5], 1);
	PlayerTextDrawLetterSize(playerid, RotationData[playerid][CustomSelection][5], 0.391666, 2.299999);
	PlayerTextDrawTextSize(playerid, RotationData[playerid][CustomSelection][5], 16.500000, 80.500000);
	PlayerTextDrawSetOutline(playerid, RotationData[playerid][CustomSelection][5], 0);
	PlayerTextDrawSetShadow(playerid, RotationData[playerid][CustomSelection][5], 1);
	PlayerTextDrawAlignment(playerid, RotationData[playerid][CustomSelection][5], 2);
	PlayerTextDrawColor(playerid, RotationData[playerid][CustomSelection][5], -1);
	PlayerTextDrawBackgroundColor(playerid, RotationData[playerid][CustomSelection][5], 255);
	PlayerTextDrawBoxColor(playerid, RotationData[playerid][CustomSelection][5], 9109759);
	PlayerTextDrawUseBox(playerid, RotationData[playerid][CustomSelection][5], 1);
	PlayerTextDrawSetProportional(playerid, RotationData[playerid][CustomSelection][5], 1);
	PlayerTextDrawSetSelectable(playerid, RotationData[playerid][CustomSelection][5], 1);

	RotationData[playerid][CustomSelection][6] = CreatePlayerTextDraw(playerid, 422.000000, 380.000000, "NEXT");
	PlayerTextDrawFont(playerid, RotationData[playerid][CustomSelection][6], 1);
	PlayerTextDrawLetterSize(playerid, RotationData[playerid][CustomSelection][6], 0.391666, 2.299999);
	PlayerTextDrawTextSize(playerid, RotationData[playerid][CustomSelection][6], 16.500000, 80.500000);
	PlayerTextDrawSetOutline(playerid, RotationData[playerid][CustomSelection][6], 0);
	PlayerTextDrawSetShadow(playerid, RotationData[playerid][CustomSelection][6], 1);
	PlayerTextDrawAlignment(playerid, RotationData[playerid][CustomSelection][6], 2);
	PlayerTextDrawColor(playerid, RotationData[playerid][CustomSelection][6], -1);
	PlayerTextDrawBackgroundColor(playerid, RotationData[playerid][CustomSelection][6], 255);
	PlayerTextDrawBoxColor(playerid, RotationData[playerid][CustomSelection][6], 9109759);
	PlayerTextDrawUseBox(playerid, RotationData[playerid][CustomSelection][6], 1);
	PlayerTextDrawSetProportional(playerid, RotationData[playerid][CustomSelection][6], 1);
	PlayerTextDrawSetSelectable(playerid, RotationData[playerid][CustomSelection][6], 1);

	RotationData[playerid][CustomSelection][7] = CreatePlayerTextDraw(playerid, 481.000000, 73.000000, "RX");
	PlayerTextDrawFont(playerid, RotationData[playerid][CustomSelection][7], 1);
	PlayerTextDrawLetterSize(playerid, RotationData[playerid][CustomSelection][7], 0.391666, 2.299999);
	PlayerTextDrawTextSize(playerid, RotationData[playerid][CustomSelection][7], 16.500000, 30.000000);
	PlayerTextDrawSetOutline(playerid, RotationData[playerid][CustomSelection][7], 0);
	PlayerTextDrawSetShadow(playerid, RotationData[playerid][CustomSelection][7], 1);
	PlayerTextDrawAlignment(playerid, RotationData[playerid][CustomSelection][7], 2);
	PlayerTextDrawColor(playerid, RotationData[playerid][CustomSelection][7], -1);
	PlayerTextDrawBackgroundColor(playerid, RotationData[playerid][CustomSelection][7], 255);
	PlayerTextDrawBoxColor(playerid, RotationData[playerid][CustomSelection][7], 9109759);
	PlayerTextDrawUseBox(playerid, RotationData[playerid][CustomSelection][7], 1);
	PlayerTextDrawSetProportional(playerid, RotationData[playerid][CustomSelection][7], 1);
	PlayerTextDrawSetSelectable(playerid, RotationData[playerid][CustomSelection][7], 1);

	RotationData[playerid][CustomSelection][8] = CreatePlayerTextDraw(playerid, 481.000000, 99.000000, "RY");
	PlayerTextDrawFont(playerid, RotationData[playerid][CustomSelection][8], 1);
	PlayerTextDrawLetterSize(playerid, RotationData[playerid][CustomSelection][8], 0.391666, 2.299999);
	PlayerTextDrawTextSize(playerid, RotationData[playerid][CustomSelection][8], 16.500000, 30.000000);
	PlayerTextDrawSetOutline(playerid, RotationData[playerid][CustomSelection][8], 0);
	PlayerTextDrawSetShadow(playerid, RotationData[playerid][CustomSelection][8], 1);
	PlayerTextDrawAlignment(playerid, RotationData[playerid][CustomSelection][8], 2);
	PlayerTextDrawColor(playerid, RotationData[playerid][CustomSelection][8], -1);
	PlayerTextDrawBackgroundColor(playerid, RotationData[playerid][CustomSelection][8], 255);
	PlayerTextDrawBoxColor(playerid, RotationData[playerid][CustomSelection][8], -65281);
	PlayerTextDrawUseBox(playerid, RotationData[playerid][CustomSelection][8], 1);
	PlayerTextDrawSetProportional(playerid, RotationData[playerid][CustomSelection][8], 1);
	PlayerTextDrawSetSelectable(playerid, RotationData[playerid][CustomSelection][8], 1);

	RotationData[playerid][CustomSelection][9] = CreatePlayerTextDraw(playerid, 481.000000, 125.000000, "RZ");
	PlayerTextDrawFont(playerid, RotationData[playerid][CustomSelection][9], 1);
	PlayerTextDrawLetterSize(playerid, RotationData[playerid][CustomSelection][9], 0.391666, 2.299999);
	PlayerTextDrawTextSize(playerid, RotationData[playerid][CustomSelection][9], 16.500000, 30.000000);
	PlayerTextDrawSetOutline(playerid, RotationData[playerid][CustomSelection][9], 0);
	PlayerTextDrawSetShadow(playerid, RotationData[playerid][CustomSelection][9], 1);
	PlayerTextDrawAlignment(playerid, RotationData[playerid][CustomSelection][9], 2);
	PlayerTextDrawColor(playerid, RotationData[playerid][CustomSelection][9], -1);
	PlayerTextDrawBackgroundColor(playerid, RotationData[playerid][CustomSelection][9], 255);
	PlayerTextDrawBoxColor(playerid, RotationData[playerid][CustomSelection][9], 1687547391);
	PlayerTextDrawUseBox(playerid, RotationData[playerid][CustomSelection][9], 1);
	PlayerTextDrawSetProportional(playerid, RotationData[playerid][CustomSelection][9], 1);
	PlayerTextDrawSetSelectable(playerid, RotationData[playerid][CustomSelection][9], 1);

	RotationData[playerid][CustomSelection][10] = CreatePlayerTextDraw(playerid, 481.000000, 152.000000, "Z+");
	PlayerTextDrawFont(playerid, RotationData[playerid][CustomSelection][10], 1);
	PlayerTextDrawLetterSize(playerid, RotationData[playerid][CustomSelection][10], 0.391666, 2.299999);
	PlayerTextDrawTextSize(playerid, RotationData[playerid][CustomSelection][10], 16.500000, 30.000000);
	PlayerTextDrawSetOutline(playerid, RotationData[playerid][CustomSelection][10], 0);
	PlayerTextDrawSetShadow(playerid, RotationData[playerid][CustomSelection][10], 1);
	PlayerTextDrawAlignment(playerid, RotationData[playerid][CustomSelection][10], 2);
	PlayerTextDrawColor(playerid, RotationData[playerid][CustomSelection][10], -1);
	PlayerTextDrawBackgroundColor(playerid, RotationData[playerid][CustomSelection][10], 255);
	PlayerTextDrawBoxColor(playerid, RotationData[playerid][CustomSelection][10], -1962934017);
	PlayerTextDrawUseBox(playerid, RotationData[playerid][CustomSelection][10], 1);
	PlayerTextDrawSetProportional(playerid, RotationData[playerid][CustomSelection][10], 1);
	PlayerTextDrawSetSelectable(playerid, RotationData[playerid][CustomSelection][10], 1);

	for(new i = 0; i < 11; i++) {
		PlayerTextDrawShow(playerid, RotationData[playerid][CustomSelection][i]);
	}
	SelectTextDraw(playerid, 0xC0C0C0FF);
	return 1;
}

public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
	if (RotationData[playerid][CustomIgnore] || (GetTickCount() - RotationData[playerid][CustomTime]) < 200)
	{
	    RotationData[playerid][CustomIgnore] = false;
	    return CallLocalFunction("cs_OnPlayerClickTextDraw", "dd", playerid, _:clickedid);
	}
	else if ((clickedid == Text:INVALID_TEXT_DRAW && RotationData[playerid][CustomShown]))
	{
	    CallLocalFunction("OnCustomSelectionResponse", "dddd", playerid, RotationData[playerid][CustomExtra], 0, CUSTOM_RESPONSE_CANCEL);
	    HideCustomSelection(playerid);
	}
	return CallLocalFunction("cs_OnPlayerClickTextDraw", "dd", playerid, _:clickedid);
}

stock Select_Page(playerid, page)
{
	if (RotationData[playerid][CustomShown])
	{
	    if (page < 0 || page == RotationData[playerid][CustomPages])
		    return 0;

	    RotationData[playerid][CustomPage] = page;
		PlayerTextDrawSetPreviewModel(playerid, RotationData[playerid][CustomSelection][3], RotationData[playerid][CustomModel][RotationData[playerid][CustomPage]]);
		ShowingUpdate(playerid, true);
	}
	return 1;
}

stock ShowingUpdate(playerid, bool:update) {
	PlayerTextDrawHide(playerid, RotationData[playerid][CustomSelection][3]);
    PlayerTextDrawShow(playerid, RotationData[playerid][CustomSelection][3]);

    if(update) {
    	PlayerTextDrawSetPreviewRot(playerid, RotationData[playerid][CustomSelection][3], RotationData[playerid][CustomRot][0], RotationData[playerid][CustomRot][1], RotationData[playerid][CustomRot][2], RotationData[playerid][CustomRot][3]);
    }
    return 1;
}

public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
	if (!RotationData[playerid][CustomShown] || (GetTickCount() - RotationData[playerid][CustomTime]) < 600)
	{
		return CallLocalFunction("cs_OnPlayerClickPlayerTextDraw", "ii", playerid, _:playertextid);
	}

	//Next
	if (playertextid == RotationData[playerid][CustomSelection][6]) {
		if (RotationData[playerid][CustomPage] >= RotationData[playerid][CustomPages]) {
		    PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
		    return 0;
		}
		else {
			Select_Page(playerid, RotationData[playerid][CustomPage] + 1);
			PlayerPlaySound(playerid, 1083, 0.0, 0.0, 0.0);
		}
	}
	//Back
	else if (playertextid == RotationData[playerid][CustomSelection][5]) {
		if (RotationData[playerid][CustomPage] < 0) {
		    PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
		    return 0;
		}
        else {
            PlayerPlaySound(playerid, 1083, 0.0, 0.0, 0.0);
			Select_Page(playerid, RotationData[playerid][CustomPage] - 1);
		}
	}
	//Done
	else if (playertextid == RotationData[playerid][CustomSelection][4])
	{
		new model = RotationData[playerid][CustomModel][RotationData[playerid][CustomPage]],
			extraid = RotationData[playerid][CustomExtra];

		HideCustomSelection(playerid);
        CallLocalFunction("OnCustomSelectionResponse", "dddd", playerid, extraid, model, CUSTOM_RESPONSE_FINAL);	
	}
	//Rot Kiri
	else if (playertextid == RotationData[playerid][CustomSelection][7]) {
		RotationData[playerid][CustomRot][0] += 2.0;
		ShowingUpdate(playerid, true);
	}
	//Rot Kanan
	else if (playertextid == RotationData[playerid][CustomSelection][8]) {
		RotationData[playerid][CustomRot][1] += 2.0;
		ShowingUpdate(playerid, true);
	}
	//Rot Kanan
	else if (playertextid == RotationData[playerid][CustomSelection][9]) {
		RotationData[playerid][CustomRot][2] += 2.0;
		ShowingUpdate(playerid, true);
	}
	//Zoom in
	else if (playertextid == RotationData[playerid][CustomSelection][10]) {
		RotationData[playerid][CustomRot][3] += 0.3;
		ShowingUpdate(playerid, true);
	}
	return CallLocalFunction("cs_OnPlayerClickPlayerTextDraw", "dd", playerid, _:playertextid);
}

#if defined _ALS_OnPlayerClickTextDraw
	#undef OnPlayerClickTextDraw
#else
	#define _ALS_OnPlayerClickTextDraw
#endif

#if defined _ALS_OnPlayerClickPlayerTD
	#undef OnPlayerClickPlayerTextDraw
#else
	#define _ALS_OnPlayerClickPlayerTD
#endif

#define OnPlayerClickTextDraw cs_OnPlayerClickTextDraw
#define OnPlayerClickPlayerTextDraw cs_OnPlayerClickPlayerTextDraw

forward cs_OnPlayerClickTextDraw(playerid, Text:clickedid);
forward cs_OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid);

forward OnCustomSelectionResponse(playerid, extraid, modelid, response);
