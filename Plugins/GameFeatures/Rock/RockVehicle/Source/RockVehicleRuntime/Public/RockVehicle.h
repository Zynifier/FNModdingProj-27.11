// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Math/MathFwd.h"
#include "Athena/FortAthenaSKVehicle.h"
#include "Athena/FortAthenaVehicleInputState.h"
#include "RockVehicleConfigs.h"
#include "RockVehicle.generated.h"

class AFortVehicleAudioController;
class URockVehicleAbility;
class URockVehicleAbility_Supersonic;
class URockVehicleAnalyticsComponent;
class URockVehicleAnimInstance;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Navigation"))
class ROCKVEHICLERUNTIME_API ARockVehicle : public AFortAthenaSKVehicle
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnSpringImpact, const FName, Socket, const float, ImpactSpeed, const FHitResult&, OutHit);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRockFreeCamToggledDelegate, bool, bFreeCam);

public:
	UFUNCTION(BlueprintPure)
	const FRockRuntimeConfigOverrides& GetCurrentRockRuntimeConfigOverrides() const;

	UFUNCTION(BlueprintPure)
	FFortAthenaVehicleInputState GetDriverInput() const;

	UFUNCTION(BlueprintPure)
	float GetThrottleState() const;

	UFUNCTION()
	void OnRep_FreeLookCamera();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ServerSetLegacyDamageValues(bool bDamageFriendlyVehicles, bool bDamageOtherVehicles, bool bDamageOwnVehicle, bool bDamageAllowedFromOtherVehicle);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerToggleFreeCam();

	UPROPERTY(BlueprintReadOnly, Transient, Category="Input")
	float InputSwivelPitch;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Input")
	float InputSwivelYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Input")
	uint8 bInputReverseCamera : 1;

	UPROPERTY(Transient)
	uint8 bHasDoubleJumped : 1;

	UPROPERTY(Transient)
	uint8 bHasDodged : 1;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_FreeLookCamera, Category="RockVehicle")
	bool bFreeLookCamera;

	UPROPERTY(BlueprintAssignable)
	FRockFreeCamToggledDelegate OnFreeCamToggled;

	UPROPERTY(Transient, Replicated)
	FRockRuntimeConfigOverrides RockRuntimeConfigs;

	UPROPERTY(BlueprintAssignable)
	FOnSpringImpact OnSpringImpact;

protected:
	UPROPERTY(Export, meta=(EditInline="true"))
	URockVehicleAnalyticsComponent* RockAnalyticsComp;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<URockVehicleAbility>> VehicleAbilities;

	UPROPERTY(EditAnywhere, Config, Category="RockVehicle")
	TArray<TSoftClassPtr<URockVehicleAbility>> VehicleAbilityTickOrder;

	UPROPERTY(Transient)
	TObjectPtr<AFortVehicleAudioController> CachedVehicleAudioController;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<URockVehicleAbility_Supersonic> SupersonicAbility;

	UPROPERTY(Transient)
	TObjectPtr<URockVehicleAnimInstance> RockAnimInstance;

	UPROPERTY(Transient)
	FFortAthenaVehicleInputState PendingDriverInputState;

	UPROPERTY(Transient)
	FFortAthenaVehicleInputState PrevDriverInputState;

	UPROPERTY(EditAnywhere, Category="RockVehicle")
	FVector EnterExitImpulse;

};

