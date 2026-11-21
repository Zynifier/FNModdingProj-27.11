// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "Math/MathFwd.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "ViewModels/FortPerUserViewModel.h"
#include "ViewModels/Locker/VariantSelector/FortVariantChannelVM.h"
#include "FortVariantSelectorVM.generated.h"

class UAthenaVariantPickerConfig;
class UFortItemVM;
class UFortLockerCategoryItemVM;
class UFortVariantChannelVM;
class UFortVariantSelectorFilterVM;
class UFortVariantSelectorSubFilterVM;
class UFortVariantSetVM;
enum class ECosmeticVariantRowType : uint8;

USTRUCT()
struct FFortCosmeticVariantFilterContext
{
	GENERATED_BODY()

};

UCLASS()
class FORTNITEUI_API UFortVariantSelectorVM : public UFortPerUserViewModel
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRotationRequestedEvent, const FRotator&, RotationOffset, const bool, bSnap);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVariantChangedEvent, const FMcpVariantChannelInfo&, InChannelInfo);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVariantOverridesChangedEvent, const TArray<FMcpVariantChannelInfo>&, InVariantOverridesInfo);

public:
	UFUNCTION(BlueprintCallable)
	void DismissVariantChannels();

	UFUNCTION(BlueprintCallable)
	void SetConfigurationData(UAthenaVariantPickerConfig* InConfigurationData);

	UFUNCTION(BlueprintCallable)
	void SetCurrentPrimaryFilter(const UFortVariantSelectorFilterVM* InCurrentPrimaryFilter);

	UFUNCTION(BlueprintCallable)
	void SetCurrentSecondaryFilter(const UFortVariantSelectorSubFilterVM* InCurrentSecondaryFilter);

	UFUNCTION(BlueprintCallable)
	void SetSelectedCategory(UFortLockerCategoryItemVM* InSelectedCategory);

	UFUNCTION(BlueprintCallable)
	void SetSelectedItem(UFortItemVM* InSelectedItem);

	UFUNCTION(BlueprintCallable)
	void SetShowArchivedVariants(const bool bShow);

	UFUNCTION(BlueprintCallable)
	void UpdateVariantChannels();

private:
	UPROPERTY(BlueprintReadWrite, Category="FortVariantSelectorVM", meta=(AllowPrivateAccess))
	TObjectPtr<UAthenaVariantPickerConfig> ConfigurationData;

	UPROPERTY(BlueprintReadOnly, Category="FortVariantSelectorVM", meta=(AllowPrivateAccess))
	TArray<UFortVariantSelectorFilterVM*> PrimaryFilters;

	UPROPERTY(BlueprintReadOnly, Category="FortVariantSelectorVM", meta=(AllowPrivateAccess))
	TArray<UFortVariantSelectorSubFilterVM*> SecondaryFilters;

	UPROPERTY(BlueprintReadOnly, Category="FortVariantSelectorVM", meta=(AllowPrivateAccess))
	TArray<UFortVariantSetVM*> VariantSets;

	UPROPERTY(BlueprintReadOnly, Category="FortVariantSelectorVM", meta=(AllowPrivateAccess))
	TArray<FMcpVariantChannelInfo> CurrentVariantOverrides;

	UPROPERTY(Transient)
	UFortLockerCategoryItemVM* SelectedCategory;

	UPROPERTY(Transient)
	UFortItemVM* SelectedItem;

	UPROPERTY(BlueprintReadWrite, Category="FortVariantSelectorVM", meta=(AllowPrivateAccess))
	TObjectPtr<UFortVariantSelectorFilterVM> CurrentPrimaryFilter;

	UPROPERTY(BlueprintReadWrite, Category="FortVariantSelectorVM", meta=(AllowPrivateAccess))
	TObjectPtr<UFortVariantSelectorSubFilterVM> CurrentSecondaryFilter;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnVariantChangedEvent OnVariantEngagedEvent;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnVariantOverridesChangedEvent OnVariantOverridesChangedEvent;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnRotationRequestedEvent OnRotationRequestedEvent;

};

UCLASS(BlueprintType, Blueprintable)
class FORTNITEUI_API UFortVariantSetVM : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	ECosmeticVariantRowType GetRowType() const;

	UFUNCTION(BlueprintCallable)
	void HandleRotationRequested(const FRotator& RotationOffset, const bool bSnap);

private:
	UPROPERTY(BlueprintReadOnly, Category="FortVariantSetVM", meta=(AllowPrivateAccess))
	TArray<UFortVariantChannelVM*> VariantChannels;

	UPROPERTY(BlueprintReadOnly, Category="FortVariantSetVM", meta=(AllowPrivateAccess))
	ECosmeticVariantRowType RowType;

};

