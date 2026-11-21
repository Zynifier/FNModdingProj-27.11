// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortEditorOnlyGameFeatureAction.h"
#include "FortGameFeatureAction_AddEditorPaks.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Add Editor Paks"))
class UFortGameFeatureAction_AddEditorPaks : public UFortEditorOnlyGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Paks")
	TArray<FString> PakFolders;

};

