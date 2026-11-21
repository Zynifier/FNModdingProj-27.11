// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Replay/FortReplaySpectatorPawnBase.h"
#include "ArenaCamPawn.generated.h"

class AFortArenaCamera;

UCLASS(HideCategories=("Navigation"))
class AArenaCamPawn : public AFortReplaySpectatorPawnBase
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortArenaCamera>> ArenaCams;

	UPROPERTY()
	int32 CurrArenaCamIdx;

};

