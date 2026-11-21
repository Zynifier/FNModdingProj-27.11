// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "WorldConditionBase.h"
#include "FortWorldConditionWorldState.generated.h"

USTRUCT(meta=(DisplayName="(Fortnite) World State"))
struct FFortWorldConditionWorldState : public FWorldConditionCommonBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortWorldConditionWorldState")
	FGameplayTagQuery WorldStateQuery;

};

UCLASS()
class UFortWorldConditionWorldState_State : public UObject
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleWorldStateChanged();

};

