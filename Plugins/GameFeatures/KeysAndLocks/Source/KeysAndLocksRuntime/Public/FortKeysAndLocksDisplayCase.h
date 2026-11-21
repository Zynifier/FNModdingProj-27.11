// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingGameplayActor.h"
#include "Items/FortItemEntry.h"
#include "FortKeysAndLocksDisplayCase.generated.h"

class UChildActorComponent;
class UFortWorldItemDefinition;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AFortKeysAndLocksDisplayCase : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void GetLockChildActorsNativeHelper(TArray<UChildActorComponent*>& LockChildActors);

	UFUNCTION(BlueprintCallable)
	void NativeCalculateLockInteractStrings(const TArray<FFortItemEntry>& Loot, const TArray<FText>& RarityTexts, const UFortWorldItemDefinition* ItemDefinition, const bool bShowCount, FText& HaveKey, FText& NeedKey);

	UFUNCTION(BlueprintCallable)
	bool NativeLockChildActorsPassAllRequirements(const TArray<UChildActorComponent*>& LockChildActors, const UFortWorldItemDefinition* ItemDefinition);

};

