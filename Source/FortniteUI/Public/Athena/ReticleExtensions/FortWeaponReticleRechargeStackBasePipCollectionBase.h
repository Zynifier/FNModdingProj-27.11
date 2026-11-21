// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Math/Color.h"
#include "FortWeaponReticleRechargeStackBasePipCollectionBase.generated.h"

class UDynamicEntryBox;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortWeaponReticleRechargeStackBasePipCollectionBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortWeaponReticleRechargeStackBasePipCollectionBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure)
	const int32 GetCurrentCount() const;

	UFUNCTION(BlueprintPure)
	const UDynamicEntryBox* GetDynamicEntryBox() const;

protected:
	UFUNCTION(BlueprintCallable)
	void SetDynamicEntryBox(UDynamicEntryBox* DynamicEntryBox);

	UFUNCTION(BlueprintCallable)
	void SetPipColor(const float Progress, const int32 Index, const FLinearColor NotReadyColor, const FLinearColor ReadyColor, const FName PipColorMatParamName);

	UFUNCTION(BlueprintCallable)
	void UpdateRemainingRechargeTime(const float TimeRemaining, const float TotalDuration, const FName PipPercentMatParamName, const bool ShouldSetPipColor, const FLinearColor NotReadyColor, const FLinearColor ReadyColor, const FName PipColorMatParamName);

	UFUNCTION(BlueprintCallable)
	void UpdateRemainingRechargeTimeAtIndex(const float FillPercent, const int32 Index, const FName PipPercentMatParamName, const bool ShouldSetPipColor, const FLinearColor NotReadyColor, const FLinearColor ReadyColor, const FName PipColorMatParamName);

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UDynamicEntryBox> PipDynamicEntryBox;

	UPROPERTY(BlueprintReadWrite, Category="FortWeaponReticleRechargeStackBasePipCollectionBase", meta=(AllowPrivateAccess="TRUE"))
	int32 CurrentCount;

};

