// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RockScalableFloat.h"
#include "RockVehicleAbility_Physics.h"
#include "RockVehicleAbility_Boost.generated.h"

class URockVehicleBoostTank;

UENUM(BlueprintType)
enum class ERockBoostLogic : uint8
{
	Standard = 0,
	Recharge = 1,
	Infinite = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRockBoostFailed);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRockBoostTankSecondsChanged, float, DeltaSeconds);

USTRUCT()
struct FRockVehicleAbilityInContinuous_Boost : public FRockVehicleAbilityInContinuous
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bHasBoost;

};

USTRUCT()
struct FRockVehicleAbilityInPersistent_Boost : public FRockVehicleAbilityInPersistent
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class URockVehicleAbility_Boost : public URockVehicleAbility_Physics
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Boost")
	FRockScalableFloat BoostAccel;

	UPROPERTY(BlueprintAssignable)
	FOnRockBoostFailed OnBoostFailed;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<URockVehicleBoostTank> BoostTank;

	UPROPERTY(Transient)
	bool bHasBoost;

};

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class URockVehicleBoostTank : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	float GetMaxBoostInSeconds() const;

	UFUNCTION(BlueprintPure)
	float GetPercentRemaining() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void GiveBoost(float Seconds);

	UFUNCTION(BlueprintPure)
	bool HasBoost() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	bool IsBoostFull() const;

	UPROPERTY(BlueprintAssignable)
	FRockBoostTankSecondsChanged OnSecondsChanged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Boost")
	FRockScalableFloat StartSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Boost")
	FRockScalableFloat MaxSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Boost")
	ERockBoostLogic BoostLogic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Boost", meta=(EditCondition="BoostLogic == ERockBoostLogic::Recharge"))
	float BoostRechargeRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Boost", meta=(EditCondition="BoostLogic == ERockBoostLogic::Recharge"))
	float BoostRechargeDelay;

protected:
	UFUNCTION()
	void OnRep_SecondsRemaining(float PrevValue);

	UPROPERTY(ReplicatedUsing=OnRep_SecondsRemaining)
	float SecondsRemaining;

};

