// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PrioritizedWidgetTypes.generated.h"

UENUM(BlueprintType)
enum class EFortPrioritizedWidgetContestedBehavior : uint8
{
	QueueBehind = 0,
	StompOther = 1,
};

UENUM(BlueprintType)
enum class EFortPrioritizedWidgetInterruptedBehavior : uint8
{
	// remain in place in the queue.

	RemainInQueue = 0,
	// simply drop

	Drop = 1,
};

UENUM(BlueprintType)
enum class EFortPrioritizedWidgetPriority : uint8
{
	Priority_0 = 0,
	Priority_1 = 1,
	Priority_2 = 2,
	Priority_3 = 3,
	Priority_4 = 4,
	Priority_5 = 5,
	//always at the end

	NumberOfPrios = 6 UMETA(Hidden),
};

USTRUCT(BlueprintType)
struct FFortPrioritizedWidgetData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPrioritizedWidgetData")
	EFortPrioritizedWidgetPriority Priority;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPrioritizedWidgetData")
	EFortPrioritizedWidgetContestedBehavior WhenContesting;

};

