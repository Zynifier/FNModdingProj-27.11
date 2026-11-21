// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Cosmetics/FortCosmeticAssetContext.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "Weapons/FortWeapon.h"
#include "FortWeaponPickaxeAthena.generated.h"

class UAnimMontage;
class UAthenaPickaxeItemDefinition;
class UCosmeticDataComponent;
class UCustomCharacterPart;
class UFXSystemComponent;
class UMaterialInstanceDynamic;
class UNiagaraSystem;
class UParticleSystem;
class UParticleSystemComponent;
class USkeletalMesh;
class USkeletalMeshComponent;
class USkeletalMeshComponentBudgeted;
class USoundBase;

USTRUCT(BlueprintType)
struct FPickaxeFXAttachmentRules
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PickaxeFXAttachmentRules")
	EAttachmentRule LocationRule;

	UPROPERTY(EditAnywhere, Category="PickaxeFXAttachmentRules")
	EAttachmentRule RotationRule;

	UPROPERTY(EditAnywhere, Category="PickaxeFXAttachmentRules")
	EAttachmentRule ScaleRule;

};

UCLASS(Config=Game, BlueprintType, Blueprintable, HideCategories=("Actor", "Input", "Components|Clothing", "Components|Base", "Components|PhysicsVolume", "Components|Activation", "Collision", "Replication", "Rendering", "Tags"))
class AFortWeaponPickaxeAthena : public AFortWeapon, public IFortCosmeticAssetContext
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool AttachesAnimTrailsToWeapon() const;

	UFUNCTION(BlueprintPure, meta=(DisplayName="Get Cosmetic Data"))
	FFortAthenaLoadout BP_GetCosmeticData() const;

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Post Pickaxe and Character Customization Initilization"))
	void BP_OnPickaxeAndCharacterCustomizationLoaded(USkeletalMeshComponent* CustomBaseMesh, const TArray<UCustomCharacterPart*>& CustomParts, const TArray<USkeletalMeshComponentBudgeted*>& CustomMeshParts);

	UFUNCTION(BlueprintPure)
	FName GetAnimTrailsFirstSocketName() const;

	UFUNCTION(BlueprintPure)
	UNiagaraSystem* GetAnimTrailsNiagaraAsset() const;

	UFUNCTION(BlueprintPure)
	UFXSystemComponent* GetAnimTrailsPSC() const;

	UFUNCTION(BlueprintPure)
	UParticleSystem* GetAnimTrailsPSCTemplate() const;

	UFUNCTION(BlueprintPure)
	FName GetAnimTrailsSecondSocketName() const;

	UFUNCTION(BlueprintPure)
	float GetAnimTrailsWidth() const;

	UFUNCTION(BlueprintPure)
	virtual UFXSystemComponent* GetAnimTrailVFXComponent() const;

	UFUNCTION(BlueprintPure)
	FName GetIdleFXSocketName() const;

	UFUNCTION(BlueprintPure)
	UParticleSystemComponent* GetIdlePSC() const;

	UFUNCTION(BlueprintPure)
	virtual UFXSystemComponent* GetIdleVFXComponent() const;

	UFUNCTION(BlueprintPure)
	FName GetSwingFXSocketName() const;

	UFUNCTION(BlueprintPure)
	UParticleSystemComponent* GetSwingPSC() const;

	UFUNCTION(BlueprintPure)
	virtual UFXSystemComponent* GetSwingVFXComponent() const;

	UFUNCTION(BlueprintPure)
	bool GetUseAnimTrailsPSC() const;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> SwingVFX;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> IdleVFX;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> AnimTrailsPSC;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponPickaxeAthena")
	TObjectPtr<UParticleSystem> AnimTrailsPSCTemplate;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponPickaxeAthena")
	TObjectPtr<UNiagaraSystem> AnimTrailsNiagaraAsset;

	UPROPERTY()
	bool bUseAnimTrailsPSC;

	UPROPERTY()
	FName AnimTrailsFirstSocketName;

	UPROPERTY()
	FName AnimTrailsSecondSocketName;

	UPROPERTY()
	float AnimTrailsWidth;

	UPROPERTY()
	FName IdleFXSocketName;

	UPROPERTY()
	FName SwingFXSocketName;

	UPROPERTY()
	TObjectPtr<USoundBase> GenericImpactSound;

	UPROPERTY(BlueprintReadOnly, Category="FortWeaponPickaxeAthena")
	TObjectPtr<UMaterialInstanceDynamic> Material0MID;

	UPROPERTY(BlueprintReadOnly, Category="FortWeaponPickaxeAthena")
	bool bWatchKills;

	UPROPERTY(BlueprintReadWrite, Category="FortWeaponPickaxeAthena")
	float WatchedKills;

	UPROPERTY(BlueprintReadOnly, Category="FortWeaponPickaxeAthena")
	bool bCandyCaneKillReaction;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponPickaxeAthena")
	TObjectPtr<USoundBase> CQCEnemyAudio;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponPickaxeAthena")
	TArray<TObjectPtr<UAnimMontage>> PokeAnimationsToCheckForOnImpact;

	UPROPERTY(EditAnywhere, Category="WeaponAnimation")
	TObjectPtr<UAnimMontage> PickaxeHarvestingMontage;

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Post Cosmetic Initialization"))
	void BP_HandlePostCosmeticInitialization();

	UFUNCTION(BlueprintCallable)
	UFXSystemComponent* CreateAnimTrailFX();

	UFUNCTION()
	void OnRep_CosmeticData();

	UPROPERTY(Transient)
	TObjectPtr<UAthenaPickaxeItemDefinition> CachedCosmeticItemDefinition;

	UPROPERTY(Transient)
	TSoftObjectPtr<USkeletalMesh> SoftFallbackMesh;

	UPROPERTY(Transient)
	TObjectPtr<USkeletalMesh> LoadedFallbackMesh;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_CosmeticData)
	FFortAthenaLoadout CosmeticData;

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UCosmeticDataComponent> CosmeticDataComponent;

	UPROPERTY(EditAnywhere, Category="Effects")
	FName FrontendFXParameterName;

	UPROPERTY(EditDefaultsOnly, Category="Effects|Idle FX")
	FPickaxeFXAttachmentRules IdleFXAttachmentRules;

	UPROPERTY(EditDefaultsOnly, Category="Effects|Swing FX")
	FPickaxeFXAttachmentRules SwingFXAttachmentRules;

};

