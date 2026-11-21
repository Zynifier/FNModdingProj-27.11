// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Bacchus/HUDLayoutToolV2/FortMobileHUDElementProxy.h"
#include "FortMovestickHUDElementProxy.generated.h"

class UOverlay;
class USizeBox;

UCLASS()
class UFortMoveStickHUDElementProxy : public UFortMobileHUDElementProxy
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_Highlights;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_AutorunLockZoneHidden;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_AutorunLockZoneSize;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_AutorunDirectionArrowSpaceSize;

	UPROPERTY(EditAnywhere, Category="Custom Properties", meta=(Categories="HUDLayout.Property"))
	FGameplayTag AutorunLockZoneSizePropertyTag;

	UPROPERTY(EditDefaultsOnly, Category="AutorunLockZone")
	float DefaultAutorunLockZoneSize;

	UPROPERTY(EditDefaultsOnly, Category="AutorunLockZone")
	float DefaultAutorunLockZoneTopPadding;

};

