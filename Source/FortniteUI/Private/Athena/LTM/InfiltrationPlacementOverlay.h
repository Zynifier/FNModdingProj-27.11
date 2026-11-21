// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/HUD/EndGame/PostGamePlacementOverlay.h"
#include "InfiltrationPlacementOverlay.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UInfiltrationPlacementOverlay : public UPostGamePlacementOverlay
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	uint8 GetAttackingTeam() const;

	UFUNCTION(BlueprintPure)
	uint8 GetDefendingTeam() const;

	UFUNCTION(BlueprintPure)
	int32 GetIntelCaptured() const;

	UFUNCTION(BlueprintPure)
	int32 GetIntelDownloaded() const;

	UFUNCTION(BlueprintPure)
	uint8 GetLocalPlayerTeam() const;

};

