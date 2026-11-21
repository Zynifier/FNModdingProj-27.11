// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Abilities/FortAbilitySetHandle.h"
#include "FortMutatorContext.generated.h"

class AFortGameplayMutator;
class APlayerState;

USTRUCT()
struct FMutatorAbilitySetEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FFortAbilitySetHandle> AppliedAbilitySetHandles;

};

USTRUCT(BlueprintType)
struct FMutatorContext
{
	GENERATED_BODY()

};

UINTERFACE()
class UFortMutatorContext : public UInterface
{
	GENERATED_BODY()
};

class IFortMutatorContext
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual void GetMutatorContext(FMutatorContext& MutatorContext) const;

};

UCLASS()
class UFortMutatorContextComponent : public UActorComponent
{
	GENERATED_BODY()

};

UINTERFACE(MinimalAPI)
class UFortMutatorOwner : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortMutatorOwner
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual void AddMutatorToList(AFortGameplayMutator* Mutator);

	UFUNCTION()
	virtual void GetMutatorRelevantPlayers(TArray<APlayerState*>& OutPlayers) const;

	UFUNCTION()
	virtual void RemoveMutatorFromList(AFortGameplayMutator* Mutator);

};

