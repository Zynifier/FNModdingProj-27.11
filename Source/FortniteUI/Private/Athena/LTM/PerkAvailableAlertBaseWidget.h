// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "PerkAvailableAlertBaseWidget.generated.h"

class AFortAthenaMutator_PerkSystemMutator;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UPerkAvailableAlertBaseWidget : public ULTMWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPerkAvailibilityChanged(int32 TagCount);

protected:
	UPROPERTY()
	TWeakObjectPtr<AFortAthenaMutator_PerkSystemMutator> CachedMutator;

};

