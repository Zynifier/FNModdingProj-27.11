// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/CachedAnimData.h"
#include "Math/MathFwd.h"
#include "Animation/LayerAnimInstance/FortItemLayerAnimInstance.h"
#include "FortItemLayerAnimInstance_UncleBrolly.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortItemLayerAnimInstance_UncleBrolly : public UFortItemLayerAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Layers")
	FCachedAnimStateArray UmbrellaGliderOpenStateDataArray;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	FVector WrapTranslation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	FRotator WrapRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	FRotator RootRotationOffset;

	UPROPERTY(Transient)
	float LandingPredictedTimer;

	UPROPERTY(Transient)
	bool bShouldUpdateYawCorrection;

	UPROPERTY(Transient)
	bool bWasAcceleratingBeforeDodge;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	float UncleBrollyDeployCurveValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	float DashChargeTier;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	float DashChargeAdditivePlayrate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	bool bIsUmbrellaFailing;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	bool bIsMeleeGuarding;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	bool bIsSprinting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	bool bIsInAir;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	bool bIsLandingPredicted;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	bool bIsJumping;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	bool bIsDodging;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	bool bIsDodgingEast;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	bool bIsDodgingSouth;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	bool bIsDodgingWest;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	bool bIsDashing;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	bool bIsDashCharging;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	bool bIsDashPredictingEnd;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	bool bIsChargeTier1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	bool bIsChargeTier2;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	bool bIsChargeTier3;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	bool bMeleeGuardingOrUmbrellaFailing;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	bool bTransition_Default_to_GuardLoop;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	bool bTransition_Default_to_GuardIntro;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	bool bTransition_GuardIntro_to_Default;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	bool bUpperBodyShouldPassThrough;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_UncleBrolly")
	bool bUmbrellaGliderIsOpen;

};

