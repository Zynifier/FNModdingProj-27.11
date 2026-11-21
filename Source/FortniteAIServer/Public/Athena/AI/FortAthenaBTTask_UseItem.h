// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FortAthenaBTTask_UseItem.generated.h"

UENUM()
enum class EActionState : uint8
{
	TryingToEquip = 0,
	EquippingItem = 1,
	UsingItem = 2,
	WaitingItemTermination = 3,
	WaitBeforeEquippingNextItem = 4,
	ActionEndedWithNoError = 5,
	ActionEndedWithError = 6,
};

UCLASS()
class UFortAthenaBTTask_UseItem : public UBTTaskNode
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ActionObjectKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ExecutionStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true", ClampMin="0.000000", UIMin="0.000000"))
	float MinWaitTimeBetweenUses;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true", ClampMin="0.000000", UIMin="0.000000"))
	float MaxWaitTimeBetweenUses;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	bool bValidateAbility;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	bool bResetActionObjectKey;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	bool bUseAlternateMode;

};

