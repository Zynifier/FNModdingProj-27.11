// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "Playspace.h"
#include "GameFeatureAction_CreatePlayspacesFromConfig.generated.h"

class APlayspace;

USTRUCT()
struct FPlayspaceConfiguration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PlayspaceConfiguration")
	TSoftClassPtr<APlayspace> PlayspaceClass;

	UPROPERTY(EditAnywhere, Category="PlayspaceConfiguration")
	EPlayspaceCreationType CreationType;

};

UCLASS(meta=(DisplayName="Create Playspaces From Config"))
class UGameFeatureAction_CreatePlayspacesFromConfig : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="GameFeatureAction_CreatePlayspacesFromConfig")
	TArray<FPlayspaceConfiguration> PlayspaceDataList;

};

