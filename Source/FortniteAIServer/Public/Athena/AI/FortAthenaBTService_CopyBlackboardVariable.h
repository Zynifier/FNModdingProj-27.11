// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "FortAthenaBTService_CopyBlackboardVariable.generated.h"

UCLASS()
class UFortAthenaBTService_CopyBlackboardVariable : public UBTService
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Blackboard")
	FBlackboardKeySelector SourceBlackboardKey;

	UPROPERTY(EditAnywhere, Category="Blackboard")
	FBlackboardKeySelector DestinationBlackboardKey;

	UPROPERTY(EditAnywhere, Category="FortAthenaBTService_CopyBlackboardVariable", meta=(AllowPrivateAccess="true"))
	uint8 bCopyOnBecomeRelevant : 1;

	UPROPERTY(EditAnywhere, Category="FortAthenaBTService_CopyBlackboardVariable", meta=(AllowPrivateAccess="true"))
	uint8 bCopyOnCeaseRelevant : 1;

	UPROPERTY(EditAnywhere, Category="FortAthenaBTService_CopyBlackboardVariable", meta=(AllowPrivateAccess="true"))
	uint8 bCopyWhenSourceValueChange : 1;

};

