// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCombatTypes.h"
#include "Widgets/FortExtensionWidgetContainer.h"
#include "FortReticleExtensionContainer.generated.h"

class AFortWeapon;
class UFortWeaponReticleExtensionData;
class UFortWeaponReticleExtensionWidgetBase;
class UUserWidget;

UCLASS(MinimalAPI, meta=(DisableNativeTick))
class UFortReticleExtensionContainer : public UFortExtensionWidgetContainer
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void HandleLocalPlayerDied(const FFortPlayerDeathReport& DeathReport);

	UFUNCTION()
	void HandleWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon);

	UFUNCTION(BlueprintImplementableEvent)
	void OnReticleExtensionWidgetCreated(UUserWidget* Widget);

	UFUNCTION(BlueprintImplementableEvent)
	void OnReticleExtensionWidgetRemoved(UUserWidget* Widget);

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortWeaponReticleExtensionData>> WeaponReticleExtensionDatas;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortWeaponReticleExtensionWidgetBase> CurrentCustomReticleExtension;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortWeaponReticleExtensionWidgetBase>> RecentReticleExtensions;

};

