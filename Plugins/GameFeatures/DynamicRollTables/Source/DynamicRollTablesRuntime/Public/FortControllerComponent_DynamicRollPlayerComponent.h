// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/RandomStream.h"
#include "ScalableFloat.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_DynamicRollPlayerComponent.generated.h"

class UFortGamestateComponent_DynamicRollTableManager;
class UFortItemDefinition;

USTRUCT(BlueprintType)
struct FFortDynamicRollResult
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortDynamicRollResult")
	TObjectPtr<UFortItemDefinition> Item;

};

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class DYNAMICROLLTABLESRUNTIME_API UFortControllerComponent_DynamicRollPlayerComponent : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	TArray<FFortDynamicRollResult> AuthorityRollChoices(const int32 NumChoices, const TArray<UFortItemDefinition*>& IgnoreItems);

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortControllerComponent_DynamicRollPlayerComponent")
	TSubclassOf<UFortGamestateComponent_DynamicRollTableManager> AssociatedManagerClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortControllerComponent_DynamicRollPlayerComponent")
	FScalableFloat Enabled;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortGamestateComponent_DynamicRollTableManager> TableManager;

	UPROPERTY(Transient)
	FRandomStream SeededRNG;

};

