// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "GameData/FortGameDataSubsystem.h"
#include "FortGameFeatureAction_AddUnableToPerformActionText.generated.h"

UCLASS(meta=(DisplayName="Add Unable To Perform Action Text"))
class UFortGameFeatureAction_AddUnableToPerformActionText : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortGameFeatureAction_AddUnableToPerformActionText")
	TArray<FFortUnableToPerformData> TagsToUnableToPerformMessageTable;

};

