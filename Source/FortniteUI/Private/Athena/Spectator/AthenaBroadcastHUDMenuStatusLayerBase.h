// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaBroadcastHUDMenuStatusLayerBase.generated.h"

class UAthenaBroadcastHUDMenuStatusBase;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaBroadcastHUDMenuStatusLayerBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void AddHUDMenuStatus(UAthenaBroadcastHUDMenuStatusBase* HUDMenuStatusWidget);

	UFUNCTION(BlueprintCallable)
	void DeactivateHudMenuWidget();

	UFUNCTION(BlueprintImplementableEvent)
	void RemoveHUDMenuStatus(UAthenaBroadcastHUDMenuStatusBase* HUDMenuStatusWidget);

	UPROPERTY(EditAnywhere, Category="AthenaBroadcastHUDMenuStatusLayerBase")
	TSubclassOf<UAthenaBroadcastHUDMenuStatusBase> HUDMenuStatusWidgetClass;

};

