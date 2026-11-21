// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "FortVariantChannelVM.generated.h"

class AFortPlayerController;
class UCustomColorSwatch;
class UFortCosmeticFloatSliderVariant;
class UFortCosmeticNumericalVariant;
class UFortCosmeticRichColorVariant;
class UFortItemVM;
class UFortVariantItemVM;

UENUM(BlueprintType)
enum class ECosmeticVariantRowType : uint8
{
	Numeric = 0,
	Tiled = 1,
	RichColor = 2,
	Texture = 3,
	Slider = 4,
	Redirector = 5,
	None = 6,
};

UCLASS()
class FORTNITEUI_API UFortVariantChannelVM : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void HandleVariantEngaged(UFortVariantItemVM* InVariant);

	UPROPERTY(BlueprintReadOnly, Category="FortVariantChannelVM")
	TArray<UFortVariantItemVM*> VariantItems;

	UPROPERTY(BlueprintReadOnly, Category="FortVariantChannelVM", meta=(AllowPrivateAccess))
	FText RowDisplayName;

	UPROPERTY(Transient)
	TObjectPtr<UFortItemVM> CosmeticItem;

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortVariantChannelVM", meta=(AllowPrivateAccess))
	ECosmeticVariantRowType RowType;

	UPROPERTY(BlueprintReadOnly, Category="FortVariantChannelVM")
	FMcpVariantChannelInfo VariantChannelInfo;

	UPROPERTY(Transient)
	TObjectPtr<UFortVariantItemVM> SelectedVariantItem;

};

UCLASS()
class FORTNITEUI_API UFortVariantNumericChannelVM : public UFortVariantChannelVM
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ChangeNumericalValue(int32 NumericalDelta);

private:
	UPROPERTY(Transient)
	UFortVariantItemVM* ItemVM;

	UPROPERTY(Transient)
	TObjectPtr<UFortCosmeticNumericalVariant> NumericalVariant;

	UPROPERTY(BlueprintReadOnly, Category="FortVariantNumericChannelVM", meta=(AllowPrivateAccess))
	FText NumDisplay;

};

UCLASS()
class FORTNITEUI_API UFortVariantRichColorChannelVM : public UFortVariantChannelVM
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UCustomColorSwatch>> ColorSwatches;

	UPROPERTY(Transient)
	UFortCosmeticRichColorVariant* CachedCosmeticVariant;

};

UCLASS()
class FORTNITEUI_API UFortVariantSliderChannelVM : public UFortVariantChannelVM
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetFloatValue(const float InFloatValue, const bool bCommit);

private:
	UPROPERTY(Transient)
	UFortVariantItemVM* ItemVM;

	UPROPERTY(Transient)
	TObjectPtr<UFortCosmeticFloatSliderVariant> FloatVariant;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerController> OwningPlayer;

	UPROPERTY(BlueprintReadOnly, Category="FortVariantSliderChannelVM", meta=(AllowPrivateAccess))
	float CurrentFloatValue;

	UPROPERTY(BlueprintReadOnly, Category="FortVariantSliderChannelVM", meta=(AllowPrivateAccess))
	float CurrentProgress;

	UPROPERTY(BlueprintReadOnly, Category="FortVariantSliderChannelVM", meta=(AllowPrivateAccess))
	float CurrentProgressBar;

	UPROPERTY(BlueprintReadOnly, Category="FortVariantSliderChannelVM", meta=(AllowPrivateAccess))
	FText SliderDisplayText;

	UPROPERTY(BlueprintReadOnly, Category="FortVariantSliderChannelVM", meta=(AllowPrivateAccess))
	bool bIsLocked;

};

UCLASS()
class FORTNITEUI_API UFortVariantTextureChannelVM : public UFortVariantChannelVM
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> OwningPlayer;

	UPROPERTY(BlueprintReadOnly, Category="FortVariantTextureChannelVM", meta=(AllowPrivateAccess))
	bool bShowArchivedItems;

};

UCLASS()
class FORTNITEUI_API UFortVariantTiledChannelVM : public UFortVariantChannelVM
{
	GENERATED_BODY()

};

