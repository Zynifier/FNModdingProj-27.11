// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortReleaseVersion.h"
#include "FortGameFeatureAction_VersionedAction.generated.h"

class UGameFeatureAction;

UCLASS(MinimalAPI, meta=(DisplayName="Versioned Action"))
class UFortGameFeatureAction_VersionedAction : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Instanced, Category="FortGameFeatureAction_VersionedAction")
	TObjectPtr<UGameFeatureAction> Action;

	UPROPERTY(EditAnywhere, Category="FortGameFeatureAction_VersionedAction", meta=(InlineEditConditionToggle))
	bool bUseMinVersion;

	UPROPERTY(EditAnywhere, Category="FortGameFeatureAction_VersionedAction", meta=(EditCondition="bUseMinVersion"))
	FFortReleaseVersion MinVersion;

	UPROPERTY(EditAnywhere, Category="FortGameFeatureAction_VersionedAction", meta=(InlineEditConditionToggle))
	bool bUseMaxVersion;

	UPROPERTY(EditAnywhere, Category="FortGameFeatureAction_VersionedAction", meta=(EditCondition="bUseMaxVersion"))
	FFortReleaseVersion MaxVersion;

};

