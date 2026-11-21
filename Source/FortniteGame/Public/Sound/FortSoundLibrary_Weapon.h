// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/WorldSubsystem.h"
#include "Sound/FortSoundLibraryComponents.h"
#include "Sound/FortSoundLibraryContexts.h"
#include "FortSoundLibrary_Weapon.generated.h"

class AFortWeapon;
class UAudioComponent;
class UFortSoundIndicatorComponent;
class UFortWeaponModAudioData;
class UMetaSoundSource;
class USoundAttenuation;
class USoundBase;
class USoundClass;
class USoundConcurrency;

UCLASS()
class UFortWeaponModMetaSoundCache : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TMap<uint32, TObjectPtr<UMetaSoundSource>> MetaSoundCache1P;

	UPROPERTY(Transient)
	TMap<uint32, TObjectPtr<UMetaSoundSource>> MetaSoundCache3P;

};

UCLASS(BlueprintType, HideCategories=("Tags", "ComponentReplication", "Sockets", "Activation", "Cooking", "Collision", "ComponentTick", "AssetUserData", "Replication", "Variable", "Navigation"))
class UFortWeaponSoundLibraryComponent : public UFortSoundLibraryComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void CacheMetaSound(UMetaSoundSource* InMetaSound);

	UFUNCTION(BlueprintPure)
	UMetaSoundSource* GetCachedMetaSound() const;

	UFUNCTION(BlueprintPure)
	UFortSoundIndicatorComponent* GetSoundIndicatorComponent() const;

	UFUNCTION(BlueprintPure)
	AFortWeapon* GetWeaponActor() const;

	UFUNCTION(BlueprintPure)
	bool IsLocallyViewed() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnModApplied(const UFortWeaponModAudioData* InModAudioData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnModRemoved(const UFortWeaponModAudioData* InModAudioData);

	UFUNCTION()
	void ShowWeaponFireSoundIndicator();

	UPROPERTY(BlueprintReadOnly, Category="FortWeaponSoundLibraryComponent")
	TMap<FGameplayTag, TObjectPtr<UFortWeaponModAudioData>> ActiveMods;

	UPROPERTY(Transient)
	TObjectPtr<AFortWeapon> WeaponActor;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortSoundIndicatorComponent> SoundIndicatorComponent;

	UPROPERTY(Transient)
	TObjectPtr<USoundBase> CachedMaxDistanceFireSound;

};

UCLASS(BlueprintType)
class UFortWeaponSoundLibraryContext : public UFortSoundLibraryContext
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Weapon")
	void ConfigureMetaSoundSource(UMetaSoundSource* MetaSoundSource, USoundClass* InClass, USoundAttenuation* InAttenuation, TSet<USoundConcurrency*> InConcurrency);

	UFUNCTION(BlueprintCallable, Category="Weapon")
	void SetAudioComponentSoundClass(UAudioComponent* InAudioComponent, USoundClass* InClass);

};

