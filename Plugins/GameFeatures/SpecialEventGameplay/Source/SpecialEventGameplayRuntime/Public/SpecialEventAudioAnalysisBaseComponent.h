// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpecialEventAudioAnalysisBaseComponent.generated.h"

class UConstantQNRT;
class ULoudnessNRT;
class UOnsetNRT;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class USpecialEventAudioAnalysisBaseComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="EventAudioAnalysis")
	UConstantQNRT* GetConstantQNRT() const;

	UFUNCTION(BlueprintPure, Category="EventAudioAnalysis")
	float GetCurrentNormalizedLoudness() const;

	UFUNCTION(BlueprintPure, Category="EventAudioAnalysis")
	ULoudnessNRT* GetLoudnessNRT() const;

	UFUNCTION(BlueprintPure, Category="EventAudioAnalysis")
	UOnsetNRT* GetOnsetNRT() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="EventAudioAnalysis")
	void UpdateTime(const float NewTime);

protected:
	UFUNCTION(BlueprintNativeEvent, Category="EventAudioAnalysis")
	void UpdateConstantQ(float Time);

	UFUNCTION(BlueprintNativeEvent, Category="EventAudioAnalysis")
	void UpdateLoudness(float Time);

	UFUNCTION(BlueprintNativeEvent, Category="EventAudioAnalysis")
	void UpdateOnset(float Time);

	UPROPERTY(BlueprintReadOnly, Category="SpecialEventAudioAnalysisBaseComponent")
	float CurrentTime;

	UPROPERTY(EditAnywhere, Category="SpecialEventAudioAnalysisBaseComponent")
	TObjectPtr<ULoudnessNRT> LoudnessNRT;

	UPROPERTY(EditAnywhere, Category="SpecialEventAudioAnalysisBaseComponent")
	TObjectPtr<UOnsetNRT> OnsetNRT;

	UPROPERTY(EditAnywhere, Category="SpecialEventAudioAnalysisBaseComponent")
	TObjectPtr<UConstantQNRT> ConstantQNRT;

};

