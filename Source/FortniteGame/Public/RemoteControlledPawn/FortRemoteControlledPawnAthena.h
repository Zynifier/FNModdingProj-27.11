// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActiveGameplayEffectHandle.h"
#include "Engine/HitResult.h"
#include "Math/MathFwd.h"
#include "Abilities/FortGameplayEffectContainerSpec.h"
#include "Athena/FortPlayerPawnAthena.h"
#include "Attributes/FortAttributeInitializationKey.h"
#include "Movement/FortCharacterMovementTypes.h"
#include "FortRemoteControlledPawnAthena.generated.h"

class AActor;
class AFortPlayerControllerAthena;
class AFortPlayerPawnAthena;
class UFortAbilitySystemComponent;
class UFortCameraMode;
class UFortRemoteControlPawnSet;
class UGameplayEffect;
class UPrimitiveComponent;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("AI", "Movement", "AI", "Movement", "AI", "Movement", "Actor", "Movement", "Game|Damage", "Navigation"))
class AFortRemoteControlledPawnAthena : public AFortPlayerPawnAthena
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="RemoteControlledPawn")
	float GetFuseLength() const;

	UFUNCTION(BlueprintPure, Category="RemoteControlledPawn")
	float GetLaunchDelay() const;

	UFUNCTION(BlueprintPure, Category="RemoteControlledPawn")
	float GetOutOfHealthExplodeDelay() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="RemoteControlledPawn")
	bool IsCurrentlyDelayingLaunch() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCosmetic, Category="RemoteControlledPawn")
	void OnClientSetupRemoteControlPawn();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="RemoteControlledPawn")
	void SetupRemoteControlPawn(AFortPlayerControllerAthena* InFortPC, AFortPlayerPawnAthena* InControllingPawn, EFortCustomMovement::Type CustomMovementType, const TArray<FFortGameplayEffectContainerSpec>& EffectContainerSpecOnKill);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="RemoteControlledPawn")
	void TriggerDestroyRemoteControlPawn();

protected:
	UFUNCTION()
	void BeginCapsuleOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void HandleControllingPlayerOutOfHealth();

	UFUNCTION()
	void OnCapsuleTouch(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="RemoteControlledPawn")
	void OnDoKill();

	UFUNCTION()
	void OnRep_ControllingPlayerPawn();

	UFUNCTION()
	void OnRep_OverrideAbilitySystemComponent();

	UFUNCTION()
	void OnRep_TriggeredForDestroy();

	UFUNCTION()
	void OnRep_TriggeredHealthThreshold(float PreviousTriggeredHealthThreshold);

	UFUNCTION(BlueprintNativeEvent, Category="RemoteControlledPawn")
	void OnTriggeredHealthThreshold(float PreviousTriggeredHealthThreshold, float CurrentTriggeredHealthThreshold);

	UPROPERTY(Replicated)
	bool bCurrentlyDelayingLaunch;

	UPROPERTY(Replicated)
	float ServerFuseStartTime;

	UPROPERTY(Replicated)
	uint8 RCTeam;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ControllingPlayerPawn, Category="RemoteControlledPawn")
	TWeakObjectPtr<AFortPlayerPawnAthena> ControllingPlayerPawn;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerPawnAthena> SpectateReturnPlayerPawn;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_OverrideAbilitySystemComponent, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAbilitySystemComponent> OverrideAbilitySystemComponent;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_TriggeredHealthThreshold)
	float TriggeredHealthThreshold;

	UPROPERTY(BlueprintReadOnly, Category="Delivery")
	TArray<FFortGameplayEffectContainerSpec> EffectContainerSpecToApplyOnKills;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortRemoteControlPawnSet> RemoteControlPawnSet;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_TriggeredForDestroy)
	bool bTriggeredForDestroy;

	UPROPERTY(EditDefaultsOnly, Category="RemoteControlledPawn")
	FFortAttributeInitializationKey AttributeInitKey;

	UPROPERTY(EditDefaultsOnly, Category="RemoteControlledPawn")
	TSubclassOf<UFortCameraMode> RemoteControlledPawnDefaultCameraClass;

	UPROPERTY(EditDefaultsOnly, Category="RemoteControlledPawn")
	TSubclassOf<UFortCameraMode> RemoteControlledPawnTriggeredCameraClass;

	UPROPERTY(EditDefaultsOnly, Category="RemoteControlledPawn")
	TSubclassOf<UGameplayEffect> ControllingPlayerEffect;

	UPROPERTY(EditDefaultsOnly, Category="RemoteControlledPawn")
	bool bAllowSetPawnCosmeticLoadout;

	UPROPERTY(Transient)
	FActiveGameplayEffectHandle ControllingPlayerEffectHandle;

private:
	UPROPERTY(Transient)
	bool bIsKeyboardTurnPressed;

	UPROPERTY(Transient)
	bool bIsKeyboardLookPressed;

};

