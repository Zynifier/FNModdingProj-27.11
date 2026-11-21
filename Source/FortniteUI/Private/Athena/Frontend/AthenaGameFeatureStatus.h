// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortGameFeatureEnum.h"
#include "AthenaGameFeatureStatus.generated.h"

class UCommonNumericTextBlock;
class UCommonTextBlock;
class UFortLazyImage;
class UObject;
enum class EAthenaGameFeatureStatus : uint8;

UENUM(BlueprintType, meta=(ScriptName="AthenaGameFeatureUIStatus"))
enum class EAthenaGameFeatureStatus : uint8
{
	InProgress = 0,
	ProgressPaused = 1,
	ErrorOccured = 2,
};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaGameFeatureStatus : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnStatusChanged(EAthenaGameFeatureStatus NewStatus);

private:
	UPROPERTY(EditAnywhere, Category="AthenaGameFeatureStatus")
	FText ProgressStatusToastTitle;

	UPROPERTY(EditAnywhere, Category="AthenaGameFeatureStatus")
	EFortGameFeature GameFeature;

	UPROPERTY(EditAnywhere, Category="AthenaGameFeatureStatus")
	bool bExtendedDisplay;

	UPROPERTY(EditAnywhere, Category="AthenaGameFeatureStatus")
	FText ExtendedDisplayText;

	UPROPERTY(EditDefaultsOnly, Category="AthenaGameFeatureStatus")
	TSoftObjectPtr<UObject> DownloadingIconAsset;

	UPROPERTY(EditDefaultsOnly, Category="AthenaGameFeatureStatus")
	TSoftObjectPtr<UObject> InitialToastNotificationIcon;

	UPROPERTY(EditDefaultsOnly, Category="AthenaGameFeatureStatus")
	FName DownloadingIconMaterialParam;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaGameFeatureStatus", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Image_DownloadingIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaGameFeatureStatus", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonNumericTextBlock> Text_ProgressPercent;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaGameFeatureStatus", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ExtendedDisplayText;

};

