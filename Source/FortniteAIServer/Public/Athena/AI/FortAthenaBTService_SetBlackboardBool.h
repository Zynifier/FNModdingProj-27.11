// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "FortAthenaBTService_SetBlackboardBool.generated.h"

UENUM()
enum class EBTSetBlackboardBoolExitActions : uint8
{
	/** On exit, inverse the value that was set. (true becomes false, false becomes true). */
	Invert = 0,
	/** On exit, revert to the value that it was before. */
	Revert = 1,
	/** On exit, keep the value that was set (i.e. do nothing). */
	Keep = 2,
};

UCLASS(HideCategories=("Service"))
class UFortAthenaBTService_SetBlackboardBool : public UBTService
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortAthenaBTService_SetBlackboardBool")
	FBlackboardKeySelector BlackboardKey;

	UPROPERTY(EditAnywhere, Category="FortAthenaBTService_SetBlackboardBool")
	bool bBlackboardValue;

	UPROPERTY(EditAnywhere, Category="FortAthenaBTService_SetBlackboardBool")
	EBTSetBlackboardBoolExitActions ExitAction;

};

