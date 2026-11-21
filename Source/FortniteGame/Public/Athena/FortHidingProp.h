// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingProp.h"
#include "FortHidingProp.generated.h"

class AFortPawn;
class AFortPlayerPawn;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class AFortHidingProp : public ABuildingProp
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Hiding Prop")
	void SetInputEnabled(AFortPlayerPawn* TargetPlayerPawn, bool bEnabled);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Hiding Prop")
	bool InteractToExit;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Hiding Prop", meta=(DisplayName="Handle Exit Pressed"))
	void BP_HandleExitPressed(AFortPlayerPawn* TargetPlayerPawn);

	UFUNCTION(BlueprintPure)
	bool ShouldUseInteractionForExit() const;

	UFUNCTION(BlueprintCallable, Category="Physics Analytics")
	void UpdateHiddenPlayerStat(const TMap<AFortPawn*, double>& HiddenPlayerAndEnterTimes);

};

