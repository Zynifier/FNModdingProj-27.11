// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortProgressiveItemStateTitleWidget.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortProgressiveItemStateTitleWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortProgressiveItemStateTitleWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Set Header Info"))
	void BP_OnSetHeaderInfo(const FText& Subheading, const bool bSubscribed, const int32 UnlockedStages, const int32 MaxStages);

};

