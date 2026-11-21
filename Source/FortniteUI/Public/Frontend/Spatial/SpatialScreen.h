// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "GameplayTagContainer.h"
#include "SpatialScreen.generated.h"

class UCommonButtonLegacy;

UCLASS(Abstract, meta=(DisableNativeTick))
class FORTNITEUI_API UAthenaSpatialScreen : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void OnInputSuspensionChanged();

protected:
	UFUNCTION(BlueprintCallable)
	void AddSpatialScreenSessionCounter(const FString& Entry, int32 Count = 1);

	UFUNCTION(BlueprintCallable)
	void FireSpatialScreenAnalytic(const FString& Interaction);

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialScreen")
	bool bEnableSpatialInputPreprocessing;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialScreen")
	bool bEnableAnalytics;

	UPROPERTY(Transient)
	FGameplayTag OverrideScreenTag;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Back;

private:
	UPROPERTY(EditAnywhere, Category="AthenaSpatialScreen", meta=(AllowPrivateAccess, Categories="ERG.Screen"))
	FGameplayTag ScreenTag;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_TouchBack;

	UPROPERTY(EditAnywhere, Category="AthenaSpatialScreen", meta=(AllowPrivateAccess))
	bool bNeedsBottomBar;

};

