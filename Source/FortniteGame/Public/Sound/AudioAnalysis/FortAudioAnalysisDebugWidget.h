// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Sound/AudioAnalysis/FortAudioAnalysisTypes.h"
#include "FortAudioAnalysisDebugWidget.generated.h"

UCLASS()
class UFortAudioAnalysisDebugWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortAudioAnalysisDebugWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Setup")
	void AddScalarParameter(const FAudioAnalysisParameterScalar& Param);

	UFUNCTION(BlueprintImplementableEvent, Category="Setup")
	void AddVectorParameter(const FAudioAnalysisParameterVector& Param);

	UFUNCTION(BlueprintImplementableEvent, Category="Setup")
	void ClearParameters();

};

