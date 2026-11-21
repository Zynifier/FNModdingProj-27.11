// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingTypes.h"
#include "FortHUDElementWidget.h"
#include "AthenaSpectatorMaterialCountsBase.generated.h"

class AFortPlayerControllerSpectating;
class AFortPlayerState;

UCLASS(Abstract)
class UAthenaSpectatorMaterialCountsBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnBuildingMaterialChanged(EFortResourceType::Type BuildingMaterial);

	UFUNCTION(BlueprintImplementableEvent)
	void OnBuildModeChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnFollowedPlayerChanged(AFortPlayerControllerSpectating* SpectatingPC, AFortPlayerState* FollowedPS);

	UFUNCTION(BlueprintImplementableEvent)
	void OnReplayScrubComplete();

	UFUNCTION(BlueprintPure)
	float TimeToDisplay() const;

	UPROPERTY(BlueprintReadOnly, Category="AthenaSpectatorMaterialCountsBase")
	bool bIsInBuildMode;

};

