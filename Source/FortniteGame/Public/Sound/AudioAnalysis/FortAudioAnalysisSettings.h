// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Sound/AudioAnalysis/FortAudioAnalysisTypes.h"
#include "FortAudioAnalysisSettings.generated.h"

class UFortAudioAnalysisDebugWidget;
class USoundSubmix;

UCLASS()
class UFortAudioAnalysisSettings : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAudioAnalysisSettings")
	TObjectPtr<USoundSubmix> AnalysisSubmix;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAudioAnalysisSettings")
	FFortSubmixAnalyzerData AnalysisData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAudioAnalysisSettings")
	TSubclassOf<UFortAudioAnalysisDebugWidget> DebugWidgetClass;

};

