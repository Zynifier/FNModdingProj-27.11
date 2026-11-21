// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIFWidget.h"
#include "VerseFortniteUIFSlider.generated.h"

class APlayerController;

USTRUCT()
struct FVerseFortniteUIFrameworkSliderValue
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float Value;

	UPROPERTY()
	int32 ClientID;

	UPROPERTY()
	int32 ServerID;

};

UCLASS()
class UVerseFortniteUIFrameworkSlider : public UUIFrameworkWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void ExecuteServerValueChanged(float InNewValue, int32 InClientID, int32 InServerID);

	UFUNCTION(BlueprintPure, Category="UI Framework")
	float GetMaxValue() const;

	UFUNCTION(BlueprintPure, Category="UI Framework")
	float GetMinValue() const;

	UFUNCTION(BlueprintPure, Category="UI Framework")
	float GetStepSize() const;

	UFUNCTION(BlueprintPure, Category="UI Framework")
	float GetValue() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="UI Framework")
	void SetMaxValue(float InMaxValue);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="UI Framework")
	void SetMinValue(float InMinValue);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="UI Framework")
	void SetStepSize(float InMinValue);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="UI Framework")
	bool SetValue(float InValue);

private:
	UFUNCTION()
	void HandleValueChanged(float NewValue);

	UFUNCTION()
	void OnRep_MaxValue();

	UFUNCTION()
	void OnRep_MinValue();

	UFUNCTION()
	void OnRep_StepSize();

	UFUNCTION()
	void OnRep_Value();

	UFUNCTION(Server, Reliable)
	void ServerValueChanged(APlayerController* PlayerController, float InNewValue, int32 InClientID, int32 InServerID);

	UPROPERTY(ReplicatedUsing=OnRep_Value)
	FVerseFortniteUIFrameworkSliderValue Value;

	UPROPERTY(ReplicatedUsing=OnRep_MinValue)
	float MinValue;

	UPROPERTY(ReplicatedUsing=OnRep_MaxValue)
	float MaxValue;

	UPROPERTY(ReplicatedUsing=OnRep_StepSize)
	float StepSize;

};

