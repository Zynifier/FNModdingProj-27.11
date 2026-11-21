// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator_SpawningPolicyEQS.h"
#include "FortAthenaMutator_SpawningPolicySafezone.generated.h"

class UFortAthenaMutator_SpawningPolicyData;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_SpawningPolicySafezone : public AFortAthenaMutator_SpawningPolicyEQS
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Instanced, Category="Safezone Spawning", meta=(AllowPrivateAccess="true"))
	TArray<TObjectPtr<UFortAthenaMutator_SpawningPolicyData>> ItemSpawningMutatorPerSafeZonePhase;

};

