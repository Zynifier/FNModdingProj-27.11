// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "UI/FrontEnd/FortLockerConfig.h"
#include "FortItemVM.generated.h"

class AFortPlayerController;
class UFortItemDetailsVM;
class UFortLockerCategoryConfig;

UCLASS(Abstract)
class UFortItemVM : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool CanEquip() const;

	UFUNCTION(BlueprintPure)
	const UFortLockerCategoryConfig* GetItemCategory() const;

	UFUNCTION(BlueprintPure)
	const FFortLockerCategorySlotInfo& GetItemSlotInfo() const;

	UFUNCTION(BlueprintPure)
	FString GetItemTemplateId() const;

	UFUNCTION(BlueprintPure)
	bool IsItemNew() const;

	UFUNCTION(BlueprintPure)
	bool IsItemVisible() const;

	UFUNCTION(BlueprintCallable)
	virtual void MarkAsSeen(bool bShouldDeferMarking);

protected:
	UPROPERTY()
	TArray<FMcpVariantReader> Variants;

	UPROPERTY(Transient)
	AFortPlayerController* PlayerController;

	UPROPERTY(Transient)
	UFortLockerCategoryConfig* Category;

	UPROPERTY(BlueprintReadOnly, Category="FortItemVM", meta=(AllowPrivateAccess))
	TObjectPtr<UFortItemDetailsVM> ItemDetails;

	UPROPERTY(BlueprintReadOnly, Category="FortItemVM", meta=(AllowPrivateAccess))
	int32 SlotIndex;

	UPROPERTY(BlueprintReadWrite, Category="FortItemVM", meta=(AllowPrivateAccess))
	uint8 bIsFavorite : 1;

	UPROPERTY(BlueprintReadOnly, Category="FortItemVM", meta=(AllowPrivateAccess))
	uint8 bCanFavorite : 1;

	UPROPERTY(BlueprintReadWrite, Category="FortItemVM", meta=(AllowPrivateAccess))
	uint8 bIsArchived : 1;

	UPROPERTY(BlueprintReadOnly, Category="FortItemVM", meta=(AllowPrivateAccess))
	uint8 bCanArchive : 1;

	UPROPERTY(BlueprintReadOnly, Category="FortItemVM", meta=(AllowPrivateAccess))
	uint8 bHasBeenSeen : 1;

	UPROPERTY(BlueprintReadOnly, Category="FortItemVM", meta=(AllowPrivateAccess))
	uint8 bIsSubscriptionTemporary : 1;

	UPROPERTY(BlueprintReadOnly, Category="FortItemVM", meta=(AllowPrivateAccess))
	uint8 bIsSlotModified : 1;

	UPROPERTY(BlueprintReadOnly, Category="FortItemVM", meta=(AllowPrivateAccess))
	uint8 bCanEquip : 1;

	UPROPERTY(BlueprintReadOnly, Category="FortItemVM", meta=(AllowPrivateAccess))
	uint8 bIsEquipped : 1;

	UPROPERTY(BlueprintReadOnly, Category="FortItemVM", meta=(AllowPrivateAccess))
	uint8 bIsEnhanced : 1;

	UPROPERTY(BlueprintReadOnly, Category="FortItemVM", meta=(AllowPrivateAccess))
	uint8 bIsExclusive : 1;

	UPROPERTY(BlueprintReadOnly, Category="FortItemVM", meta=(AllowPrivateAccess))
	uint8 bIsShuffleTile : 1;

	UPROPERTY(BlueprintReadOnly, Category="FortItemVM", meta=(AllowPrivateAccess))
	uint8 bIsValid : 1;

	UPROPERTY(BlueprintReadWrite, Category="FortItemVM", meta=(AllowPrivateAccess))
	uint8 bIsMarked : 1;

};

