// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortStandaloneFrontend.h"
#include "CrewStandaloneSubscriptionContentContainer.generated.h"

class UCrewSubscriptionContentContainer;

UCLASS(Abstract, meta=(DisableNativeTick))
class UCrewStandaloneSubscriptionContentContainer : public UFortStandaloneFrontend
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="CrewStandaloneSubscriptionContentContainer", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCrewSubscriptionContentContainer> Widget_CrewContentContainer;

};

