// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortAthenaLivingWorldConfigData.h"
#include "FortGameFeatureAction_AddCategoryTableToConfig.generated.h"

class UFortAthenaLivingWorldConfigData;

USTRUCT()
struct FFortAthenaLivingWorldCategoryTableDataList
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAthenaLivingWorldCategoryTableDataList")
	TArray<FFortAthenaLivingWorldCategoryTableData> CategoryTableDatas;

};

UCLASS(MinimalAPI, meta=(DisplayName="Add Category Table to Lager Config"))
class UFortGameFeatureAction_AddCategoryTableToConfig : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Config")
	TMap<TSoftObjectPtr<UFortAthenaLivingWorldConfigData>, FFortAthenaLivingWorldCategoryTableDataList> ConfigToCategoryTableDatas;

};

