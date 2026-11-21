// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortWeaponComponent.h"
#include "FortQuartzGunfireComponent.generated.h"

class AFortWeapon;
class UAudioComponent;
class UNiagaraSystem;
class UQuartzClockHandle;
class USoundBase;
enum class EQuartzGunfireState : uint8;

UENUM(BlueprintType)
enum class EQuartzGunfireState : uint8
{
	FirstShot = 0,
	Shooting = 1,
	Stopped = 2,
	Max_None = 3 UMETA(DisplayName="None"),
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnQuartzGunfireStateChanged, EQuartzGunfireState, NewState, EQuartzGunfireState, PreviousState);

USTRUCT()
struct FQuartzGunfireWeaponContext
{
	GENERATED_BODY()

};

UCLASS(HideCategories=("ComponentTick", "Tags", "AssetUserData", "ComponentReplication", "Activation", "Variable", "Collision", "Cooking", "Trigger", "PhysicsVolume"), ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortQuartzGunfireComponent : public UFortWeaponComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	EQuartzGunfireState GetGunfireState() const;

	UFUNCTION(BlueprintCallable)
	void SetGunfireSounds(USoundBase* NewFireSound1P, USoundBase* NewFireSound3P);

	UFUNCTION(BlueprintCallable)
	void SetGunfireState(EQuartzGunfireState NewGunfireState);

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	TObjectPtr<USoundBase> FireSound1P;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	TObjectPtr<USoundBase> FireSound3P;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Settings")
	TSoftObjectPtr<UNiagaraSystem> MuzzleNiagaraSystemLooping;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	float PitchOffsetMax;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMin="1", UIMin="1"))
	int32 VariationCount;

	UPROPERTY(BlueprintAssignable)
	FOnQuartzGunfireStateChanged OnGunfireStateChanged;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> AudioComponent;

	UPROPERTY(Transient)
	TObjectPtr<UQuartzClockHandle> ClockHandle;

	UPROPERTY(Transient)
	TObjectPtr<AFortWeapon> WeaponActor;

};

