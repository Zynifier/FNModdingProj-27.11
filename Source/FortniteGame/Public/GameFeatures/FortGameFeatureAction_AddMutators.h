// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortGameFeatureAction_AddMutators.generated.h"

class AFortGameplayMutator;

UENUM(BlueprintType)
enum class EMutatorAddTarget : uint8
{
	FortGameStateAthena = 0,
	FortMinigame = 1,
	FortGameModeAthena = 2,
};

USTRUCT()
struct FAddMutatorData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AddMutatorData")
	EMutatorAddTarget Target;

	UPROPERTY(EditAnywhere, Category="AddMutatorData")
	TSoftClassPtr<AFortGameplayMutator> Mutator;

};

USTRUCT()
struct FMutatorInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	EMutatorAddTarget Target;

	UPROPERTY(EditAnywhere, Category="MutatorInstanceData")
	TSoftObjectPtr<AFortGameplayMutator> MutatorInstance;

};

UCLASS(MinimalAPI, meta=(DisplayName="Add Mutators"))
class UFortGameFeatureAction_AddMutators : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Mutator Data")
	TArray<FAddMutatorData> MutatorsToAdd;

	UPROPERTY(Transient)
	TArray<FMutatorInstanceData> MutatorInstances;

};

