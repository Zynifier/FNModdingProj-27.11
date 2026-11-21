// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FortAthenaBTTask_PlayEmote.generated.h"

class UAthenaDanceItemDefinition;

UCLASS()
class UFortAthenaBTTask_PlayEmote : public UBTTaskNode
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName PlayEmoteExecutionStatusKeyName;

	UPROPERTY(EditAnywhere, Category="FortAthenaBTTask_PlayEmote", meta=(AllowPrivateAccess="true"))
	TArray<TObjectPtr<UAthenaDanceItemDefinition>> BespokeEmotes;

};

