// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Player/FortCheatManager_Coupled.h"
#include "FortAthenaMutator_MatchConditionManager.generated.h"

class AFortAthenaMutator_MatchCondition;
enum class EMatchConditionMutatorTimingType : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMatchConditionManagerTimingSatisfied, const EMatchConditionMutatorTimingType, TimingType);

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_MatchConditionManager : public AFortAthenaMutator
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnSatisfied(const AFortAthenaMutator_MatchCondition* MatchConditionMutator, const bool bSatisfied);

	UPROPERTY(Replicated)
	TArray<uint8> TeamNums;

	UPROPERTY(Replicated)
	TArray<TObjectPtr<AFortAthenaMutator_MatchCondition>> MatchConditionMutators;

};

UCLASS()
class UFortCheatManager_MatchConditionManagerMutator : public UFortCheatManager_Coupled
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void MatchConditionManagerMutatorDebug(const float TextScale = 1.000000f);

};

