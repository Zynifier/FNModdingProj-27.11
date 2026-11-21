// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "FortLocalizationServiceTypes.h"
#include "FortLocalizationService.generated.h"

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortLocalizationService : public AInfo
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TSet<FString> DocumentLoadInProgress;

	UPROPERTY(Transient)
	TMap<FString, FReplicatedLocalizedDocument> TranslationsReadyToSendToTheClient;

};

