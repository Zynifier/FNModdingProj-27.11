// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonWidgetSwitcherLegacy.h"
#include "FortPrioritizedWidgetSwitcher.generated.h"

class UWidget;

UCLASS()
class UFortPrioritizedWidgetSwitcher : public UCommonWidgetSwitcherLegacy
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPriorityWidgetActivationEvent, UWidget*, Widget);

private:
	UPROPERTY(EditDefaultsOnly, Category="FortPrioritizedWidgetSwitcher")
	float CachingTime;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnPriorityWidgetActivationEvent OnPriorityWidgetActivatedDelegate;

};

