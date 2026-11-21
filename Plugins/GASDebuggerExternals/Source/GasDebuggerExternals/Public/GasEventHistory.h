// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GasEventHistory.generated.h"

class UObject;

UENUM()
enum class EAbilityHistoryClassType : uint8
{
	Ability = 0,
	Effect = 1,
	Tag = 2,
	NumTypes = 3,
};

UENUM()
enum class EAbilityHistoryEventType : uint8
{
	Added = 0,
	Removed = 1,
	Committed = 2,
	Activated = 3,
	Cancelled = 4,
	Ended = 5,
	FailedActivation = 6,
};

USTRUCT()
struct GASDEBUGGEREXTERNALS_API FGasEventHistoryItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint16 Id;

	UPROPERTY()
	uint8 Depth;

	UPROPERTY()
	EAbilityHistoryClassType ClassType;

	UPROPERTY()
	UClass* Class;

	UPROPERTY()
	int64 Timestamp;

	UPROPERTY()
	FGameplayTag InstigatingTag;

	UPROPERTY()
	FGameplayTagContainer Reason;

	UPROPERTY()
	EAbilityHistoryEventType EventType;

	UPROPERTY(NotReplicated)
	FString BlueprintCallStack;

	UPROPERTY(NotReplicated)
	TArray<uint64> NativeCallStack;

private:
	UPROPERTY(NotReplicated)
	FString NativeCallStackAsString;

};

USTRUCT()
struct GASDEBUGGEREXTERNALS_API FGasEventHistory
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FGasEventHistoryItem> Items;

	UPROPERTY()
	int32 CurrentItemDepth;

};

