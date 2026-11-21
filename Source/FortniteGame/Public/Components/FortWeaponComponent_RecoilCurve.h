// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Components/FortWeaponComponent.h"
#include "FortWeaponComponent_RecoilCurve.generated.h"

class AFortWeapon;
class UCurveVector;

UENUM(BlueprintType)
enum class EFortRecoilCurveType : uint8
{
	WithTime = 0,
	//OverheatAlpha will increment with time.  Call StartRecoilCurve to start.  EndRecoilCurve if it needs to stop before CurveLengthInSeconds.

	WithOverheat = 1,
};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Trigger", "Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortWeaponComponent_RecoilCurve : public UFortWeaponComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category="Default")
	void EndRecoilCurve();

	UFUNCTION(BlueprintCallable, Category="Default")
	void StartRecoilCurve();

	UPROPERTY(EditDefaultsOnly, Category="Default")
	FScalableFloat InterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Default")
	bool bRandomizeHorizFlip;

	UPROPERTY(EditDefaultsOnly, Category="Default")
	bool bRandomizeVertFlip;

	UPROPERTY(EditDefaultsOnly, Category="Default")
	FScalableFloat CurveTimeScale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Default")
	TArray<TObjectPtr<UCurveVector>> RecoilVectorCurves;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Default")
	EFortRecoilCurveType RecoilBehaviorType;

	UPROPERTY(EditDefaultsOnly, Category="Default")
	FScalableFloat TargetingMult;

	UPROPERTY(EditDefaultsOnly, Category="Default")
	FScalableFloat VertRecoilMult;

	UPROPERTY(EditDefaultsOnly, Category="Default")
	FScalableFloat HorizRecoilMult;

	UPROPERTY(EditDefaultsOnly, Category="Default")
	FScalableFloat CurveLengthInSeconds;

private:
	UFUNCTION()
	void OnPressTrigger(AFortWeapon* Weapon);

	UFUNCTION()
	void OnReleaseTrigger(AFortWeapon* Weapon);

};

