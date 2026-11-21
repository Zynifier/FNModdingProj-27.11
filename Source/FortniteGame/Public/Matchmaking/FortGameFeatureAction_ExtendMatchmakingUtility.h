// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "UObject/NoExportTypes.h"
#include "FortGameFeatureAction_ExtendMatchmakingUtility.generated.h"

class UMatchmakingUtilityExtensionBase;

UCLASS(MinimalAPI, AutoExpandCategories=("Experience"), meta=(DisplayName="Matchmaking Utility Extension"))
class UFortGameFeatureAction_ExtendMatchmakingUtility : public UGameFeatureAction
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Experience")
	TSubclassOf<UMatchmakingUtilityExtensionBase> Experience;

};

UCLASS(Abstract, HideDropdown, MinimalAPI, NotBlueprintable)
class UMatchmakingUtilityExtensionBase : public UObject
{
	GENERATED_BODY()

};

UCLASS(EditInlineNew)
class UJunoMatchmakingUtilityExtension : public UMatchmakingUtilityExtensionBase
{
	GENERATED_BODY()

};

