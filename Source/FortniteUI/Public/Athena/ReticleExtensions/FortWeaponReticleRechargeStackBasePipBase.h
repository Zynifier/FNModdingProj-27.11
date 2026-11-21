// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Math/Color.h"
#include "FortWeaponReticleRechargeStackBasePipBase.generated.h"

class UImage;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortWeaponReticleRechargeStackBasePipBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortWeaponReticleRechargeStackBasePipBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetFillPercent(const float FillPercent, const FName PipPercentMatParamName);

	UFUNCTION(BlueprintCallable)
	void SetPipProgressColor(const FLinearColor Color, const FName PipColorMatParamName);

protected:
	UFUNCTION(BlueprintCallable)
	void SetImagePip(UImage* Image);

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UImage> ImagePip;

};

