// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaTeamMemberDBNOState.generated.h"

class AFortPlayerStateAthena;
class UCommonLazyImage;
class UCommonLazyWidget;
class UCommonVisibilitySwitcher;
class UImage;
class UObject;
class UPanelWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaTeamMemberDBNOState : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void RefreshVisuals(const int32 InteractingActorCount, const float InteractingMultiplier, const float InteractDuration);

	UFUNCTION(BlueprintCallable)
	void SetPlayerState(AFortPlayerStateAthena* InPlayerState);

private:
	UPROPERTY(EditAnywhere, Category="AthenaTeamMemberDBNOState")
	TSoftObjectPtr<UObject> DBNOIndicatorVisual;

	UPROPERTY(EditAnywhere, Category="AthenaTeamMemberDBNOState")
	TSoftObjectPtr<UObject> RevivingIndicatorVisual;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_Indicator;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_DefaultIndicator;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_CustomIndicator;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLazyImage> LazyImage_Indicator;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Timer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLazyWidget> LazyWidget_CustomWidgetContainer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLazyImage> LazyImage_CustomWidgetTimer;

	UPROPERTY(EditDefaultsOnly, Category="TimerMaterialParameter")
	FName StartTimeName;

	UPROPERTY(EditDefaultsOnly, Category="TimerMaterialParameter")
	FName BaseDurationName;

	UPROPERTY(EditDefaultsOnly, Category="TimerMaterialParameter")
	FName InteractingMultiplierName;

	UPROPERTY(EditDefaultsOnly, Category="TimerMaterialParameter")
	FName TotalDurationName;

	UPROPERTY(EditDefaultsOnly, Category="TimerMaterialParameter")
	FName NewMethodWeightName;

};

