// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIEvaluator_FollowGroupLeader.generated.h"

class UFortPawnComponent_AIGroup;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIEvaluator_FollowGroupLeader : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName FollowGroupLeaderStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName FollowGroupLeaderMovementStateKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName FollowGroupLeaderDestinationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName TooFarFromLeaderKeyName;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortPawnComponent_AIGroup> CachedAIGroupComponent;

};

