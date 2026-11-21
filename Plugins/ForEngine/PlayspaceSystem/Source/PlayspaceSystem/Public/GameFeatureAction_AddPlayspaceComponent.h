// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Playspace.h"
#include "GameFeatureAction_AddPlayspaceComponent.generated.h"

class UPlayspaceComponent;

USTRUCT()
struct FPlayspaceComponentConfiguration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PlayspaceComponentConfiguration")
	TSoftClassPtr<UPlayspaceComponent> PlayspaceComponentClass;

	UPROPERTY(EditAnywhere, Category="PlayspaceComponentConfiguration")
	EPlayspaceComponentCreationType CreationType;

	UPROPERTY(EditAnywhere, Category="PlayspaceComponentConfiguration")
	FGameplayTagQuery TagQuery;

	UPROPERTY(EditAnywhere, Category="PlayspaceComponentConfiguration")
	FVector Location;

};

UCLASS(meta=(DisplayName="Add Component to Playspace"))
class UGameFeatureAction_AddPlayspaceComponent : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="GameFeatureAction_AddPlayspaceComponent")
	TArray<FPlayspaceComponentConfiguration> PlayspaceComponentDataList;

};

