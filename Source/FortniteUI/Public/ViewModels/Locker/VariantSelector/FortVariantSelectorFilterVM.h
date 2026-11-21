// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "Variants/AthenaVariantPickerConfig.h"
#include "FortVariantSelectorFilterVM.generated.h"

class UFortVariantSelectorSubFilterVM;
class UObject;

UCLASS()
class FORTNITEUI_API UFortVariantSelectorFilterVM : public UMVVMViewModelBase
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Category="FortVariantSelectorFilterVM", meta=(AllowPrivateAccess))
	FText Label;

	UPROPERTY(BlueprintReadOnly, Category="FortVariantSelectorFilterVM", meta=(AllowPrivateAccess))
	TObjectPtr<UFortVariantSelectorSubFilterVM> MainFilter;

	UPROPERTY(Transient)
	FAthenaVariantFilterTabInfo_Primary PrimaryFilterInfo;

};

UCLASS()
class FORTNITEUI_API UFortVariantSelectorSubFilterVM : public UMVVMViewModelBase
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Category="FortVariantSelectorSubFilterVM", meta=(AllowedClasses="/Script/Engine.Texture2D,/Script/Engine.MaterialInterface", AllowPrivateAccess))
	TSoftObjectPtr<UObject> Icon;

	UPROPERTY(BlueprintReadOnly, Category="FortVariantSelectorSubFilterVM", meta=(AllowPrivateAccess))
	FText Label;

};

