// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MotdWidgetBase.h"
#include "FortDynamicMotdTeaserWidget.generated.h"

class UMotdViewModel;
class UMotdWidgetBase;

UCLASS(BlueprintType, Blueprintable)
class UFortDynamicMotdTeaserWidget : public UMotdWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	UMotdWidgetBase* AddFullScreenWidget(const TSubclassOf<UMotdWidgetBase> FullScreenWidget) const;

	UFUNCTION(BlueprintCallable)
	void OnMotdShown();

	UFUNCTION(BlueprintCallable)
	void SetCurrentMotd(const int32 Index);

	UPROPERTY(BlueprintReadOnly, Category="FortDynamicMotdTeaserWidget")
	TObjectPtr<UMotdViewModel> CurrentMotd;

};

