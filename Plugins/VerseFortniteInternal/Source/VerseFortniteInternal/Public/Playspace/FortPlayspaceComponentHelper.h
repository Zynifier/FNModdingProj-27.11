// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortPlayspaceComponentHelper.generated.h"

class AFortPlayerPawnAthena;
class APawn;

UCLASS()
class UFortPlayspaceComponentHelper : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void HandlePlayerDied(AFortPlayerPawnAthena* FortPlayerPawnAthena);

	UFUNCTION()
	void HandlePlayerPawnPossessed(APawn* Pawn);

};

