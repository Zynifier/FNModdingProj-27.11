// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "FortReticle.generated.h"

class AFortMinigame;
class AFortVolume;
class AFortWeapon;
class APlayerState;
class UMaterialInterface;
enum class EFortMinigameState : uint8;

UCLASS(BlueprintType, meta=(Category="Fortnite UI", DisableNativeTick))
class UFortReticle : public UFortHUDElementWidget
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleWeaponChanged();

	UFUNCTION()
	void OnActorEnteredVolume(APlayerState* PS, AFortVolume* Volume);

	UFUNCTION()
	void OnContextualReticleChanged();

	UFUNCTION()
	void OnMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState MinigameState);

	UFUNCTION()
	void OnPawnSet();

	UFUNCTION()
	void OnReticleColorChanged();

	UFUNCTION()
	void OnWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon);

	UPROPERTY(EditAnywhere, Category="Reticle")
	TObjectPtr<UMaterialInterface> ReticleWeaponCooldownMI;

};

