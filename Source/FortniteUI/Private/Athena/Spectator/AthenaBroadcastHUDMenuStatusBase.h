// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortActorIndicatorWidget.h"
#include "AthenaBroadcastHUDMenuStatusBase.generated.h"

UCLASS(Abstract)
class UAthenaBroadcastHUDMenuStatusBase : public UFortActorIndicatorWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void InventoryActivated();

	UFUNCTION(BlueprintImplementableEvent)
	void MapActivated();

protected:
	UPROPERTY(EditAnywhere, Category="AthenaBroadcastHUDMenuStatusBase")
	float ZOffset;

};

