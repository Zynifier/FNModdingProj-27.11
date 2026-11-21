// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "GameFeatureAction_AddInputContextMapping.generated.h"

class UFortInputMappingContext;

UCLASS(MinimalAPI, meta=(DisplayName="Add Input Context Mapping"))
class UGameFeatureAction_AddInputContextMapping : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="GameFeatureAction_AddInputContextMapping", meta=(DisplayName="(Optional) Feature Enhanced Input Support Cvar Name", DisplayPriority="0"))
	FString FeatureEnhancedInputSupportCvarName;

	UPROPERTY(EditAnywhere, Category="GameFeatureAction_AddInputContextMapping")
	TArray<TObjectPtr<UFortInputMappingContext>> InputContexts;

};

