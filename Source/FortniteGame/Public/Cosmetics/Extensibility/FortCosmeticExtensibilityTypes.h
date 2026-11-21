// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortCosmeticExtensibilityTypes.generated.h"

UENUM()
enum class ECosmeticStepOrdinality : uint8
{
	PreStep = 0,
	Default = 1,
	PostStep = 2,
	NumPhases = 3 UMETA(Hidden),
};

USTRUCT(BlueprintType)
struct FCosmeticFlowGraphKey
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FlowGraph")
	FGameplayTag CategoryTag;

	UPROPERTY(EditAnywhere, Category="FlowGraph")
	FGameplayTag FlowTag;


	FORTNITEGAME_API bool operator==(const FCosmeticFlowGraphKey& Other) const;
	friend FORTNITEGAME_API uint32 GetTypeHash(const FCosmeticFlowGraphKey& Value);
};

USTRUCT(BlueprintType)
struct FCosmeticFlowOptionSetKey
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FlowGraph")
	FGameplayTag OptionSetTag;


	FORTNITEGAME_API bool operator==(const FCosmeticFlowOptionSetKey& Other) const;
	friend FORTNITEGAME_API uint32 GetTypeHash(const FCosmeticFlowOptionSetKey& Value);
};

USTRUCT()
struct FCosmeticStepDetails
{
	GENERATED_BODY()

};

USTRUCT()
struct FCosmeticStepParentData
{
	GENERATED_BODY()

};

