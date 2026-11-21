// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortExpeditionSummaryWidget.generated.h"

class UFortExpeditionItem;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortExpeditionSummaryWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Expedition")
	void BindInventoryDelegates();

	UFUNCTION(BlueprintCallable, Category="Expedition")
	void UnbindInventoryDelegates();

protected:
	UFUNCTION(BlueprintNativeEvent, Category="Expedition")
	void OnRefreshSummaryWidget();

	UPROPERTY(BlueprintReadOnly, Category="Expedition")
	int32 AvailableExpeditions;

	UPROPERTY(BlueprintReadOnly, Category="Expedition")
	int32 CompletedExpeditions;

	UPROPERTY(BlueprintReadOnly, Category="Expedition")
	int32 LandVehiclesTotal;

	UPROPERTY(BlueprintReadOnly, Category="Expedition")
	int32 LandVehiclesAvailable;

	UPROPERTY(BlueprintReadOnly, Category="Expedition")
	int32 AirVehiclesTotal;

	UPROPERTY(BlueprintReadOnly, Category="Expedition")
	int32 AirVehiclesAvailable;

	UPROPERTY(BlueprintReadOnly, Category="Expedition")
	int32 SeaVehiclesTotal;

	UPROPERTY(BlueprintReadOnly, Category="Expedition")
	int32 SeaVehiclesAvailable;

	UPROPERTY(BlueprintReadOnly, Category="Expedition")
	int32 LandExpeditionsTotal;

	UPROPERTY(BlueprintReadOnly, Category="Expedition")
	int32 LandExpeditionsAvailable;

	UPROPERTY(BlueprintReadOnly, Category="Expedition")
	int32 AirExpeditionsTotal;

	UPROPERTY(BlueprintReadOnly, Category="Expedition")
	int32 AirExpeditionsAvailable;

	UPROPERTY(BlueprintReadOnly, Category="Expedition")
	int32 SeaExpeditionsTotal;

	UPROPERTY(BlueprintReadOnly, Category="Expedition")
	int32 SeaExpeditionsAvailable;

	UPROPERTY(BlueprintReadOnly, Category="Expedition")
	TArray<TObjectPtr<UFortExpeditionItem>> InProgressExpeditions;

};

