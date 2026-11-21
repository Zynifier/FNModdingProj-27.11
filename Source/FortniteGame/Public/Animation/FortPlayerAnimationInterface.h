// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Animation/AnimInputs/FortAnimInput_SpringGlider.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/FortPlayerAnimAssets.h"
#include "FortCombatTypes.h"
#include "FortPlayerAnimationInterface.generated.h"

class UFortPlayerAnimationComponent;

UCLASS(DefaultToInstanced, BlueprintType, Blueprintable)
class UFortPlayerAnimationInterface : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const FFortAnimInput_BowWeapon& GetBowWeaponInput() const;

	UFUNCTION(BlueprintPure)
	const FFortAnimInput_JackalVehicle& GetJackalVehicleInput() const;

	UFUNCTION(BlueprintPure)
	float GetMeleeTwistCurveValue() const;

	UFUNCTION(BlueprintPure)
	const FFortAnimInput_Skydiving& GetSkydivingInput() const;

	UFUNCTION(BlueprintPure)
	const FFortAnimInput_SpringGlider& GetSpringGliderInput() const;

	UFUNCTION(BlueprintPure)
	const FFortAnimInput_TurnInPlace& GetTurnInPlaceInput() const;

	UFUNCTION(BlueprintPure)
	EFortWeaponCoreAnimation::Type GetWeaponCoreAnim() const;

	UFUNCTION(BlueprintPure)
	const FFortAnimInput_Zipline& GetZiplineInput() const;

	UFUNCTION(BlueprintPure, Category="Grind Rails")
	bool IsOnGrindRails() const;

	UFUNCTION(BlueprintPure)
	bool IsOnGround() const;

	UFUNCTION(BlueprintPure)
	bool IsPlayingEmote() const;

	UFUNCTION(BlueprintPure)
	bool IsPlayingMeleeAnim() const;

	UFUNCTION(BlueprintPure)
	bool IsRiding() const;

	UFUNCTION(BlueprintCallable)
	void OnAnimNotifyOpenGlider();

	UFUNCTION(BlueprintCallable, Category="AnimSets")
	void ResetWeaponCoreAnimAssetsOverride(EFortWeaponCoreAnimation::Type WeaponCoreAnim);

	UFUNCTION(BlueprintCallable)
	void SetUseAltGliderCamera(bool bUseAltGliderCamera);

	UFUNCTION(BlueprintCallable, Category="AnimSets")
	void SetWeaponCoreAnimAssetsOverride(FFortPlayerAnimAssets PlayerAnimAssetsOverride, EFortWeaponCoreAnimation::Type WeaponCoreAnim);

	UFUNCTION(BlueprintCallable)
	void SetWeaponFireBlendTimeOverride(float BlendTime);

	UFUNCTION(BlueprintPure)
	bool ShouldForceOpenGlider() const;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortPlayerAnimationComponent> AnimComp;

};

