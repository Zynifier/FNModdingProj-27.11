// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortUIStateWidget_NUI.h"
#include "CampaignHUDBase.generated.h"

class AFortWeapon;
class UFortWeaponReticleExtensionWidgetBase;
class UUserWidget;
enum class EUIExtensionSlot : uint8;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UCampaignHUDBase : public UFortUIStateWidget_NUI
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void NativeHandleWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon);

	UFUNCTION(BlueprintImplementableEvent)
	void OnExtensionWidgetCreated(EUIExtensionSlot ExtensionSlot, UUserWidget* Widget);

	UFUNCTION(BlueprintImplementableEvent)
	void OnExtensionWidgetRemoved(EUIExtensionSlot ExtensionSlot, UUserWidget* Widget);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="CampaignHUD")
	void SetInputReflectorBoxVisibility(bool bVisible);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="CampaignHUD")
	void ToggleChat(bool bShow);

	UPROPERTY(EditDefaultsOnly, Category="Reticle Extensions")
	int32 ReticleExtensionSize;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortWeaponReticleExtensionWidgetBase> CurrentCustomReticleExtension;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortWeaponReticleExtensionWidgetBase>> RecentReticleExtensions;

};

