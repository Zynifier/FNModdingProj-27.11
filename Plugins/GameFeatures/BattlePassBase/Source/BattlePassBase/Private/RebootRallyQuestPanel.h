// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RebootRallyQuestPanel.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class URebootRallyQuestPanel : public UUserWidget
{
	GENERATED_BODY()

public:
	URebootRallyQuestPanel(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnRebootRallyEligibilityUpdated(bool bEligible);

};

