// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "MVVMViewModelBase.h"
#include "Styling/SlateColor.h"
#include "FortVariantItemVM.generated.h"

class UAthenaCosmeticItemDefinition;
class UFortApplyVarianceToInterfaceMaterialFlow;
class UFortItemVM;
class UImage;
class UMaterialInterface;
class UTexture2D;

USTRUCT(BlueprintType)
struct FVariantDisplayInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="VariantDisplayInfo")
	TSoftObjectPtr<UTexture2D> Texture;

	UPROPERTY(BlueprintReadOnly, Category="VariantDisplayInfo")
	FSlateColor TintColor;

	UPROPERTY(BlueprintReadOnly, Category="VariantDisplayInfo")
	uint8 bApplyTexture : 1;

	UPROPERTY(BlueprintReadOnly, Category="VariantDisplayInfo")
	uint8 bApplyTint : 1;

};

UCLASS()
class FORTNITEUI_API UFortVariantItemVM : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ApplyMaterialVariance(UImage* Image);

protected:
	UPROPERTY(Transient)
	TObjectPtr<UFortItemVM> CosmeticItem;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortApplyVarianceToInterfaceMaterialFlow> MaterialVarianceFlowUI;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInterface> OriginalMaterial;

	UPROPERTY(BlueprintReadOnly, Category="FortVariantItemVM", meta=(AllowPrivateAccess))
	bool bOwned;

	UPROPERTY(BlueprintReadOnly, Category="FortVariantItemVM", meta=(AllowPrivateAccess))
	bool bEquipped;

	UPROPERTY(BlueprintReadOnly, Category="FortVariantItemVM", meta=(AllowPrivateAccess))
	bool bHasConflict;

	UPROPERTY(BlueprintReadOnly, Category="FortVariantItemVM", meta=(AllowPrivateAccess))
	FGameplayTag VariantChannel;

	UPROPERTY(BlueprintReadOnly, Category="FortVariantItemVM", meta=(AllowPrivateAccess))
	FGameplayTag VariantTag;

	UPROPERTY(BlueprintReadOnly, Category="FortVariantItemVM", meta=(AllowPrivateAccess))
	FString VariantCustomData;

	UPROPERTY(BlueprintReadOnly, Category="FortVariantItemVM", meta=(AllowPrivateAccess))
	FVariantDisplayInfo VariantDisplayInfo;

	UPROPERTY(BlueprintReadOnly, Category="FortVariantItemVM", meta=(AllowPrivateAccess))
	FText ConflictingText;

	UPROPERTY(BlueprintReadOnly, Category="FortVariantItemVM", meta=(AllowPrivateAccess))
	bool bIsConflicting;

};

UCLASS()
class FORTNITEUI_API UFortVariantRichColorItemVM : public UFortVariantItemVM
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Category="FortVariantRichColorItemVM", meta=(AllowPrivateAccess))
	FText ColorName;

};

UCLASS()
class FORTNITEUI_API UFortVariantTextureItemVM : public UFortVariantItemVM
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	UAthenaCosmeticItemDefinition* VariantCosmeticDef;

};

