// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortAIDirectorDataTrackingSettings.generated.h"

class AFortAIDirectorDataManager;

UCLASS()
class UFortAIDirectorDataTrackingSettings : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DataManager")
	TSubclassOf<AFortAIDirectorDataManager> PlayerDataManager;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DataManager")
	TSubclassOf<AFortAIDirectorDataManager> EncounterDataManager;

};

