// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/HUD/FortAthenaLoadingMessage.h"

UFortAthenaLoadingMessage::UFortAthenaLoadingMessage(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortAthenaLoadingMessage::HandleInGameLoadScreenChanged(AFortPlayerControllerAthena* PlayerController, bool bEnableLoadScreen, FText HUDReasonText)
{
}
