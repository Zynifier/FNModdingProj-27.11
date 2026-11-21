// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UIStateChartManagerPlayer.generated.h"

class UUIStateChartManager;
class UUIStateChartManagerEntry;
class UUIStateChartResourceCollection;

USTRUCT()
struct FUIStateChartManagerChartDeactivationRequest
{
	GENERATED_BODY()

};

UCLASS()
class UICHART_API UUIStateChartManagerPlayer : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TMap<int32, UUIStateChartManagerEntry*> ActiveChartEntries;

	UPROPERTY(Transient)
	TMap<int32, UUIStateChartManagerEntry*> InactiveChartEntries;

	UPROPERTY(Transient)
	TArray<FUIStateChartManagerChartDeactivationRequest> DeactivationRequests;

	UPROPERTY(Transient)
	TObjectPtr<UUIStateChartManager> Manager;

	UPROPERTY(Instanced)
	TObjectPtr<UUIStateChartResourceCollection> PlayerResources;

};

