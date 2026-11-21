// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/FortMovementComp_CharacterAthena.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_JumpPenalty.generated.h"

class AFortPawn;

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_JumpPenalty : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="JumpPenalty")
	bool bApplyJumpPenalty;

	UPROPERTY(EditDefaultsOnly, Category="JumpPenalty")
	FScalableFloat bOverridePenalties;

	UPROPERTY(EditDefaultsOnly, Category="JumpPenalty")
	TArray<FAthenaJumpPenalty> Penalties;

	UPROPERTY(EditDefaultsOnly, Category="JumpPenalty")
	FScalableFloat bOverrideResetTime;

	UPROPERTY(EditDefaultsOnly, Category="JumpPenalty")
	FScalableFloat ResetTime;

private:
	UFUNCTION()
	void OnFortPawnChanged(AFortPawn* NewPawn);

};

