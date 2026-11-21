// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "Engine/DataTable.h"
#include "MVVMViewModelBase.h"
#include "Types/SlateEnums.h"
#include "CreativeModalDialogOptionTypes.h"
#include "CreativeModalDialogViewmodel.generated.h"

class UDataTable;
class UTexture2D;

UENUM()
enum class ECreativeModalDialogViewmodelResponse : uint8
{
	None = 0 UMETA(Hidden),
	Button1 = 1,
	Button2 = 2,
	Button3 = 3,
	Button4 = 4,
	Button5 = 5,
	Button6 = 6,
};

UCLASS(MinimalAPI, BlueprintType, meta=(MVVMAllowedContextCreationType="Manual"))
class UCreativeModalDialogViewmodel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	ESlateVisibility GetBackgroundVisibility() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	FDataTableRowHandle GetButton1TriggeringInputAction() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	ESlateVisibility GetButton1Visibility() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	FDataTableRowHandle GetButton2TriggeringInputAction() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	ESlateVisibility GetButton2Visibility() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	FDataTableRowHandle GetButton3TriggeringInputAction() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	ESlateVisibility GetButton3Visibility() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	FDataTableRowHandle GetButton4TriggeringInputAction() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	ESlateVisibility GetButton4Visibility() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	FDataTableRowHandle GetButton5TriggeringInputAction() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	ESlateVisibility GetButton5Visibility() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	FDataTableRowHandle GetButton6TriggeringInputAction() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	ESlateVisibility GetButton6Visibility() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	EHorizontalAlignment GetHorizontalAlignment() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	float GetTimeoutProgress() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	ESlateVisibility GetTimerVisibility() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	EVerticalAlignment GetVerticalAlignment() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	bool IsButton1Visible() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	bool IsButton2Visible() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	bool IsButton3Visible() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	bool IsButton4Visible() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	bool IsButton5Visible() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	bool IsButton6Visible() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	bool IsTimerVisible() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	bool ShouldButton1UseFallbackDefaultInputAction() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	bool ShouldButton2UseFallbackDefaultInputAction() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	bool ShouldButton3UseFallbackDefaultInputAction() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	bool ShouldButton4UseFallbackDefaultInputAction() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	bool ShouldButton5UseFallbackDefaultInputAction() const;

	UFUNCTION(BlueprintPure, Category="Modal Dialog")
	bool ShouldButton6UseFallbackDefaultInputAction() const;

private:
	UPROPERTY(BlueprintReadWrite, Category="Modal Dialog", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	FText Title;

	UPROPERTY(BlueprintReadWrite, Category="Modal Dialog", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	FText Body;

	UPROPERTY(BlueprintReadWrite, Category="Modal Dialog", meta=(AllowPrivateAccess="true", ExposeOnSpawn, RequiredAssetDataTags="RowStructure=/Script/UMG.RichTextStyleRow"))
	TObjectPtr<UDataTable> TextStyleSet;

	UPROPERTY(BlueprintReadWrite, Category="Modal Dialog", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	FText Button01_MainText;

	UPROPERTY(BlueprintReadWrite, Category="Modal Dialog", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	FText Button02_MainText;

	UPROPERTY(BlueprintReadWrite, Category="Modal Dialog", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	FText Button03_MainText;

	UPROPERTY(BlueprintReadWrite, Category="Modal Dialog", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	FText Button04_MainText;

	UPROPERTY(BlueprintReadWrite, Category="Modal Dialog", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	FText Button05_MainText;

	UPROPERTY(BlueprintReadWrite, Category="Modal Dialog", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	FText Button06_MainText;

	UPROPERTY(BlueprintReadWrite, Category="Modal Dialog", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	FText Button01_SubText;

	UPROPERTY(BlueprintReadWrite, Category="Modal Dialog", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	FText Button02_SubText;

	UPROPERTY(BlueprintReadWrite, Category="Modal Dialog", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	FText Button03_SubText;

	UPROPERTY(BlueprintReadWrite, Category="Modal Dialog", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	FText Button04_SubText;

	UPROPERTY(BlueprintReadWrite, Category="Modal Dialog", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	FText Button05_SubText;

	UPROPERTY(BlueprintReadWrite, Category="Modal Dialog", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	FText Button06_SubText;

	UPROPERTY(BlueprintReadWrite, Category="Modal Dialog", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	TObjectPtr<UTexture2D> Art01_Image;

	UPROPERTY(BlueprintReadWrite, Category="Modal Dialog", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	TObjectPtr<UTexture2D> Art02_Image;

	UPROPERTY(BlueprintReadWrite, Category="Modal Dialog", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	ECreativeModalDialogAlignmentOption ContentAlignment;

	UPROPERTY(BlueprintReadWrite, Category="Modal Dialog", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	bool bShowBackground;

	UPROPERTY(BlueprintReadWrite, Category="Modal Dialog", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	float DialogBackgroundAlpha;

	UPROPERTY(BlueprintReadOnly, Category="Modal Dialog", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	ECreativeModalDialogTimerOption TimerOption;

	UPROPERTY(BlueprintReadWrite, Category="Modal Dialog", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	float Timeout;

	UPROPERTY(BlueprintReadWrite, Category="Modal Dialog", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	float RemainingTimeForTimeout;

	UPROPERTY(BlueprintReadWrite, Category="Modal Dialog", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	int32 NumberOfButtons;

	UPROPERTY(BlueprintReadWrite, Category="Modal Dialog", meta=(AllowPrivateAccess="true", ExposeOnSpawn))
	ECreativeModalBackActionBoundButtonOption BackActionBoundButton;

	UPROPERTY(BlueprintReadWrite, Category="Modal Dialog", meta=(AllowPrivateAccess="true"))
	ECreativeModalDialogViewmodelResponse Response;

};

