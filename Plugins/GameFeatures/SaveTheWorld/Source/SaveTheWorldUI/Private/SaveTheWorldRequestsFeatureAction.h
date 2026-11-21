// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "SaveTheWorldRequestsFeatureAction.generated.h"

class UFortHeroLoadoutScreenBase;
class UFortHeroLoadoutScreenLegacy;
class UFortItemInspectionScreen;
class UFortItemManagementScreen;
class UFortItemManagementScreen_STW;
class UFortSquadManagementScreenBase;

UCLASS(MinimalAPI, meta=(DisplayName="SaveTheWorld Requests"))
class USaveTheWorldRequestsFeatureAction : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="SaveTheWorldRequestsFeatureAction")
	TSoftClassPtr<UFortItemManagementScreen> ItemManagementScreenClass;

	UPROPERTY(EditAnywhere, Category="SaveTheWorldRequestsFeatureAction")
	TSoftClassPtr<UFortItemManagementScreen_STW> ItemManagementScreenClass_STW;

	UPROPERTY(EditAnywhere, Category="SaveTheWorldRequestsFeatureAction")
	TSoftClassPtr<UFortItemInspectionScreen> ItemInspectionScreenClass;

	UPROPERTY(EditAnywhere, Category="SaveTheWorldRequestsFeatureAction")
	TSoftClassPtr<UFortHeroLoadoutScreenBase> HeroLoadoutScreenClass;

	UPROPERTY(EditAnywhere, Category="SaveTheWorldRequestsFeatureAction")
	TSoftClassPtr<UFortHeroLoadoutScreenLegacy> HeroLoadoutScreenLegacyClass;

	UPROPERTY(EditAnywhere, Category="SaveTheWorldRequestsFeatureAction")
	TSoftClassPtr<UFortSquadManagementScreenBase> SurvivorSquadManagementScreenClass;

};

