// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_ProximityChat.generated.h"

class AFortMinigame;

UENUM(BlueprintType)
enum class EFortAthenaMutator_AttenuationState : uint8
{
	Disabled = 0,
	Enabled = 1,
	None = 2,
};

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_ProximityChat : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mutator")
	float Distance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mutator")
	EFortAthenaMutator_AttenuationState Attenuation;

private:
	UPROPERTY(Transient)
	TObjectPtr<AFortMinigame> OwnerMinigame;

};

