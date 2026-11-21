// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "Frontend/FortItemPreviewScreen.h"
#include "Frontend/ItemPreview/FortCameraTargetPedestal.h"
#include "FortItemPreviewWidget.generated.h"

class UFortItemVM;

UCLASS(Abstract, Config=Game)
class UFortItemPreviewWidget : public UFortItemPreviewScreen
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetCurrentPreviewItem(UFortItemVM* ItemVM);

	UFUNCTION(BlueprintCallable)
	void SetFallbackPreviewItem(const UFortItemVM* ItemVM);

	UFUNCTION(BlueprintCallable)
	void SetSlotIndexOverride(int32 SlotIndex);

	UFUNCTION(BlueprintCallable)
	void SetVariantOverrides(const TArray<FMcpVariantChannelInfo>& InVariantOverrides);

protected:
	UFUNCTION(BlueprintCallable)
	void UpdatePreview();

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortItemVM> CurrentItemVM;

	UPROPERTY(Transient)
	TObjectPtr<UFortItemVM> FallbackItemVM;

	UPROPERTY(Transient)
	TArray<FMcpVariantChannelInfo> VariantOverrides;

	UPROPERTY(EditAnywhere, Category="FortItemPreviewWidget", meta=(AllowPrivateAccess))
	EItemPreviewRestrictionMode RestrictionMode;

	UPROPERTY(EditAnywhere, Category="FortItemPreviewWidget", meta=(AllowPrivateAccess))
	bool bAllowPawnOverrideOnExclusiveItems;

	UPROPERTY(EditAnywhere, Category="FortItemPreviewWidget", meta=(AllowPrivateAccess))
	bool bAllowFallbackToLoadout;

	UPROPERTY(EditAnywhere, Category="FortItemPreviewWidget", meta=(AllowPrivateAccess))
	bool bAllowUpdateWhileDeactivated;

};

