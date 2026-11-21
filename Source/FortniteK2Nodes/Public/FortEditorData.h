// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortEditorData.generated.h"

class UDataTable;
class UFortClientEventData;
class USkeletalMeshLODSettings;

USTRUCT()
struct FFortSkelMeshBudgetLODSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="LODSettings")
	FString BudgetName;

	UPROPERTY(EditAnywhere, Category="LODSettings")
	TSoftObjectPtr<USkeletalMeshLODSettings> LODSettings;

};

UCLASS(Config=Engine)
class UFortEditorData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="MissionAlert")
	TSoftObjectPtr<UDataTable> MissionAlertSpreadDatas;

	UPROPERTY(EditAnywhere, Category="MissionAlert")
	TSoftObjectPtr<UDataTable> MissionAlerts;

	UPROPERTY(EditAnywhere, Category="MissionAlert")
	TSoftObjectPtr<UFortClientEventData> ClientEventData;

	UPROPERTY(EditAnywhere, Category="LODSettings")
	TArray<FFortSkelMeshBudgetLODSettings> SkelMeshBudgetLODSettings;

private:
	UPROPERTY(Config)
	FString FortEditorDataPath;

};

