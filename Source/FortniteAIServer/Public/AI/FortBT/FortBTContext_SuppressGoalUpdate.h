// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/FortBT/FortBTService_ContextOverride.h"
#include "FortBTContext_SuppressGoalUpdate.generated.h"

UCLASS(HideCategories=("Service"))
class UFortBTContext_SuppressGoalUpdate : public UFortBTService_ContextOverride
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="GoalSuppression", meta=(DisplayName="Clear Goal Info"))
	bool bUnregisterFromGoalManager;

};

