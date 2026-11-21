// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "InstancedStructContainer.h"
#include "CosmeticPropertyBase.h"
#include "CosmeticDataComponent.generated.h"

UCLASS(MinimalAPI, BlueprintType, meta=(BlueprintSpawnableComponent, DisplayName="Cosmetic Data Component (Experimental)"))
class UCosmeticDataComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(CustomThunk, BlueprintCallable, meta=(CustomStructureParam="Property", DisplayName="Add Or Override Property", ExpandBoolAsExecs="ReturnValue"))
	bool BP_AddOrOverrideProperty(FGameplayTag SlotTag, const FCosmeticPropertyBase& Property);
	DECLARE_FUNCTION(execBP_AddOrOverrideProperty);

	UFUNCTION(CustomThunk, BlueprintCallable, meta=(CustomStructureParam="OutProperty", DisplayName="Find Property", ExpandBoolAsExecs="ReturnValue"))
	bool BP_FindProperty(FGameplayTag SlotTag, FGameplayTag PropertyTag, FCosmeticPropertyBase& OutProperty);
	DECLARE_FUNCTION(execBP_FindProperty);

	UFUNCTION(BlueprintCallable)
	void ResetProperties();

private:
	UPROPERTY(Transient)
	TMap<FGameplayTag, FInstancedStructContainer> PropertyContainers;

};

