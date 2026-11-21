// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BehaviorTree/Tasks/BTTask_Wait.h"
#include "FortAthenaBTTask_BotAmbushPlayer.generated.h"

UCLASS()
class UFortAthenaBTTask_BotAmbushPlayer : public UBTTask_Wait
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Node", meta=(ClampMax="180.0", ClampMin="0.0"))
	float FacingPrecision;

	UPROPERTY(EditAnywhere, Category="Node", meta=(ClampMin="0.0"))
	float WeaponCooldown;

	UPROPERTY(EditAnywhere, Category="Node")
	bool bClearBlackboardOnFinished;

private:
	UPROPERTY(EditAnywhere, Category="Blackboard")
	FBlackboardKeySelector TargetedPlayerKeySelector;

	UPROPERTY(EditAnywhere, Category="Blackboard")
	FBlackboardKeySelector MaxLocationErrorKeySelector;

	UPROPERTY(EditAnywhere, Category="Blackboard")
	FBlackboardKeySelector MinLocationErrorKeySelector;

};

