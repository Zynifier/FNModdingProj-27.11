// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/FortSTWUIDataBase.h"
#include "FortSTWUIData.generated.h"

class UDataTable;

UCLASS()
class UFortSTWUIData : public UFortSTWUIDataBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Skill Tree", meta=(AssetBundles="Menu"))
	TSoftObjectPtr<UDataTable> UpgradesDisplayDataTable;

};

