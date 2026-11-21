// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UIStateChartResourceCollection.generated.h"

class UObject;

UCLASS()
class UICHART_API UUIStateChartResourceCollection : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TMap<UClass*, UObject*> ResourcesByClass;

};

