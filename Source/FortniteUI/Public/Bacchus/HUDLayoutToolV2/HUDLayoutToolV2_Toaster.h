// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "HUDLayoutToolV2_Toaster.generated.h"

class UCommonTextBlock;
class UWidgetAnimation;

UENUM()
enum class EHUDLayoutToolToasterType : uint8
{
	Success = 0,
	Failure = 1,
	LocalFailure = 2,
	CloudFailure = 3,
};

USTRUCT(BlueprintType)
struct FHUDLayoutToolV2_ToastNotificationContent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_ToastNotificationContent")
	EHUDLayoutToolToasterType ToasterType;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_ToastNotificationContent")
	FText TitleText;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_ToastNotificationContent")
	FText DescriptionText;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UHUDLayoutToolV2_Toaster : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Anim_Success;

	UPROPERTY(Transient, meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Anim_Failure;

	UPROPERTY(Transient, meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Anim_LocalFailure;

	UPROPERTY(Transient, meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Anim_CloudFailure;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> CommonText_Title;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> CommonText_Description;

};

