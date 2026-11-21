// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "Athena/AthenaEquippedItemBase.h"
#include "AthenaEquippedItemReticleWidgetBase.generated.h"

class AFortWeapon;
class UCommonBorder;
class UMaterialInstanceDynamic;
class UWidgetAnimation;

UCLASS()
class FORTNITEUI_API UAthenaEquippedItemReticleWidgetBase : public UAthenaEquippedItemBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void DefaultFadeAmmoOut();

	UFUNCTION(BlueprintCallable)
	void FadeAmmoIn();

	UFUNCTION(BlueprintCallable)
	void FadeAmmoInOut();

	UFUNCTION(BlueprintCallable)
	void FadeAmmoOut(float PlaybackSpeed);

	UPROPERTY(BlueprintReadWrite, Transient, Category="Reticle")
	int32 MaximumAmmo;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Reticle")
	float CurrentAmmoPercentage;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Reticle")
	float LowAmmoPercentage;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Reticle")
	TObjectPtr<UMaterialInstanceDynamic> AmmoCounterMaterialInstanceDynamic;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Reticle", meta=(EditInline="true"))
	TObjectPtr<UCommonBorder> AmmoCounter;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Reticle")
	TObjectPtr<AFortWeapon> CurrentEquippedWeapon;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Reticle")
	bool bShouldHideReticleAmmoCounterWhileTargeting;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Reticle")
	bool bIsHoldingSecondaryFire;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Reticle")
	float TimeToOutroAnim;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Reticle")
	FTimerHandle FadeOutTimerHandle;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Reticle")
	bool bIsAmmoVisible;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Reticle")
	TObjectPtr<UWidgetAnimation> FadeoutAnimation;

};

