// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortEditorOnlyGameFeatureAction.h"
#include "FortGameFeatureAction_EditorTestConfig.generated.h"

class UWorld;

UCLASS(MinimalAPI, meta=(DisplayName="Editor Test Config"))
class UFortGameFeatureAction_EditorTestConfig : public UFortEditorOnlyGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="PIE")
	TArray<TSoftObjectPtr<UWorld>> AdditionalMapsToPIETest;

};

