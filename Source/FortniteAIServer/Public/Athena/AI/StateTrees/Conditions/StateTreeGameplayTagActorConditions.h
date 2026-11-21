// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StateTreeConditionBase.h"
#include "StateTreeGameplayTagActorConditions.generated.h"

class AActor;

UENUM()
enum class EHasMatchingGameplayTagContainerTestType : uint8
{
	Any = 0,
	All = 1,
};

USTRUCT(meta=(DisplayName="(Fortnite) Actor's tags matches Gameplay Tag Container"))
struct FGameplayTagActorHasMatchingGameplayContainerTagCondition : public FStateTreeConditionCommonBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Condition")
	EHasMatchingGameplayTagContainerTestType TestType;

	UPROPERTY(EditAnywhere, Category="Condition")
	bool bInvert;

};

USTRUCT(meta=(DisplayName="(Fortnite) Actor Has Matching Gameplay Tag"))
struct FGameplayTagActorHasMatchingGameplayTagCondition : public FStateTreeConditionCommonBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Condition")
	bool bInvert;

};

USTRUCT()
struct FGameplayTagActorHasMatchingGameplayTagContainerInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> Actor;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTagContainer TagContainerToCheck;

};

USTRUCT()
struct FGameplayTagActorHasMatchingGameplayTagInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> Actor;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTag TagToCheck;

};

