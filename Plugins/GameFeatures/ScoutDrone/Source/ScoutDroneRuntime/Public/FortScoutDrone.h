// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Engine/HitResult.h"
#include "GameFramework/Character.h"
#include "GameplayCueInterface.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/Markers/FortMarkableActorInterface.h"
#include "Attributes/FortAttributeInitializationKey.h"
#include "FortCombatTypes.h"
#include "FortDamageableActorInterface.h"
#include "FortTeamActorInterface.h"
#include "ScoutDroneTypes.h"
#include "FortScoutDrone.generated.h"

class AActor;
class AFortPawn;
class UAudioComponent;
class UAudioParameterComponent;
class UFortAbilitySet;
class UFortAbilitySystemComponent;
class UFortActorComponent_Affiliation;
class UFortChargingSet_ScoutDroneEnergy;
class UFortHealthSet;
class UFortScoutDronePawnOverrideComponent;
class UFortScoutDronePickupManager;
class UNiagaraComponent;
class USoundBase;
class UUserWidget;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortScoutDrone : public ACharacter, public IAbilitySystemInterface, public IFortDamageableActorInterface, public IFortMarkableActorInterface, public IFortTeamActorInterface, public IGameplayCueInterface, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Remote Control | Player")
	AFortPawn* GetControllingPlayerPawn() const;

	UFUNCTION(BlueprintPure)
	FRotator GetDeltaRotator() const;

	UFUNCTION(BlueprintPure)
	void GetForwardAndRightDotProducts_Native(float& OutForwardDot, float& OutRightDot);

	UFUNCTION(BlueprintPure, Category="Stats")
	float GetHealthPercentage() const;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Diving")
	bool bIsDiving;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Hotfix")
	FScalableFloat DivingEnabled;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="SpeedBoost")
	bool bIsSpeedBoosting;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Components", meta=(EditInline="true"))
	TObjectPtr<UNiagaraComponent> NSScoutDroneIdle_Native;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Components", meta=(EditInline="true"))
	TObjectPtr<UFortScoutDronePickupManager> PickupManagerComponent_Native;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

protected:
	UFUNCTION()
	virtual void GameplayCue_Damage(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnDamagePlayEffects(float Damage, const FGameplayTagContainer& DamageTags, FVector Momentum, const FHitResult& HitInfo, AFortPawn* InstigatedBy, AActor* DamageCauser, FGameplayEffectContextHandle EffectContext);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnDeathPlayEffects(float Damage, const FGameplayTagContainer& DamageTags, FVector Momentum, const FHitResult& HitInfo, AFortPawn* InstigatedBy, AActor* DamageCauser, FGameplayEffectContextHandle EffectContext);

	UFUNCTION(BlueprintCallable)
	void SetAffiliationAudio();

	UFUNCTION(BlueprintCallable)
	void SetTeamMatesIndicator(bool bState);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void SetupGameplayAudioParameters();

	UPROPERTY(EditAnywhere, Category="FortScoutDrone")
	TSubclassOf<UUserWidget> TeamMateIndicatorMarkerWidgetClass;

	UPROPERTY(BlueprintReadWrite, Export, Category="Components", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> DroneMotorLoopComponent;

	UPROPERTY(BlueprintReadWrite, Export, Category="Components", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> DroneThrustSoundComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Flight")
	FScalableFloat BaseMaxFlySpeed;

	UPROPERTY(EditDefaultsOnly, Category="Tags")
	FGameplayTagContainer DefaultTags;

private:
	UFUNCTION()
	void OnRep_ControllingPlayerPawn();

	UPROPERTY(VisibleAnywhere, Export, Category="AbilitySystem", meta=(EditInline="true"))
	TObjectPtr<UFortAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, Export, Category="Team", meta=(EditInline="true"))
	TObjectPtr<UFortActorComponent_Affiliation> AffiliationComponent;

	UPROPERTY(EditDefaultsOnly, Category="AbilitySystem")
	TObjectPtr<UFortAbilitySet> StartupAbilitySet;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ControllingPlayerPawn)
	TObjectPtr<AFortPawn> ControllingPlayerPawn;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortHealthSet> HealthSet;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortChargingSet_ScoutDroneEnergy> EnergySet;

	UPROPERTY(EditAnywhere, Category="FortScoutDrone")
	float LifespanAfterDeath;

	UPROPERTY(EditDefaultsOnly, Category="AbilitySystem")
	FFortAttributeInitializationKey AttributeInitKey;

	UPROPERTY(EditDefaultsOnly, Category="Damage Settings")
	TEnumAsByte<EPhysicalSurface> PrimarySurfaceType;

	UPROPERTY(EditDefaultsOnly, Category="Damage Settings")
	TEnumAsByte<EFortBaseWeaponDamage::Type> WeaponResponseType;

	UPROPERTY(Transient)
	bool bPlayedDeath;

	UPROPERTY(EditDefaultsOnly, Category="FortScoutDrone")
	FScoutDroneDeferredDestructionData OutOfHealthDismissDelayData;

	UPROPERTY(EditDefaultsOnly, Category="FortScoutDrone")
	FScoutDroneDeferredDestructionData OutOfEnergyDismissDelayData;

	UPROPERTY(BlueprintAssignable, Category="Team", meta=(AllowPrivateAccess="true"))
	FOnTeamIndexChangedDelegate OnTeamIndexChanged;

	UPROPERTY(EditDefaultsOnly, Category="Components")
	TSubclassOf<UFortScoutDronePawnOverrideComponent> PawnOverrideComponentClass;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	TObjectPtr<USoundBase> DroneMotorLoopSound;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	TObjectPtr<USoundBase> DroneThrusterSound;

	UPROPERTY(VisibleAnywhere, Export, Category="Components", meta=(EditInline="true"))
	TObjectPtr<UAudioParameterComponent> AudioParameter;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	FName LocallyViewedPawnAudioParamName;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	FName IsEnemyAudioParamName;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	FName ThrustAmountAudioParamName;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	float ThrustSoundThreshold;

};

