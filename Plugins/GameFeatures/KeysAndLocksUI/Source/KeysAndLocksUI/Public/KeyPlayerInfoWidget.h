// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/AthenaPlayerInfoBaseWidgetInterface.h"
#include "FortHUDElementWidget.h"
#include "KeyPlayerInfoWidget.generated.h"

class AFortPlayerStateAthena;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UKeyPlayerInfoWidget : public UFortHUDElementWidget, public IAthenaPlayerInfoBaseWidgetInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleGameplayTagEvent(const FGameplayTag UpdatedTag, int32 TagCount);

	UFUNCTION(BlueprintImplementableEvent)
	void OnKeyStatusActivated(AFortPlayerStateAthena* InPlayerState, bool bActivated);

	UPROPERTY(EditDefaultsOnly, Category="KeyPlayerInfoWidget")
	FGameplayTag KeyStatusTag;

};

