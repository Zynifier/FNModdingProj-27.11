// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UIStateChartManagerEntry.generated.h"

class UUIStateChartManagerPlayer;
class UUIStateChartRegion;
class UUIStateChartResourceCollection;

UCLASS()
class UICHART_API UUIStateChartManagerEntry : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<UUIStateChartRegion> MainRegion;

	UPROPERTY(Transient)
	TObjectPtr<UUIStateChartManagerPlayer> ManagerPlayer;

	UPROPERTY(Instanced)
	TObjectPtr<UUIStateChartResourceCollection> StateChartResources;

};

