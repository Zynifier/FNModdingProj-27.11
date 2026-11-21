// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Athena/FortWeaponPickaxeAthena.h"
#include "Camera/FortCameraFramingTypes.h"
#include "Cosmetics/Variants/FortCosmeticVariantAction.h"
#include "FortCombatTypes.h"
#include "Weapons/Data/FortWeaponItemDefinition.h"
#include "FortWeaponPickaxeDualWieldAthena.generated.h"

class UAnimMontage;
class UFXSystemComponent;
class UFortGameplayAbility;
class UFortWeaponAdditionalData_SingleWieldState;
class UFortWeaponAnimSet;
class UNiagaraSystem;
class UParticleSystem;
class UParticleSystemComponent;
class USkeletalMesh;
class USkeletalMeshComponentBudgeted;
class USoundBase;
enum class EFortDualWieldDataSource : uint8;
enum class EFortDualWieldSwingState : uint8;

UENUM()
enum class EFortDualWieldDataSource : uint8
{
	// Using the base weapon data from the weapon item definition

	BaseConfiguration = 0,
	// Using the additional single wield weapon data from weapon item definition

	DataDriven = 1,
};

UENUM(BlueprintType)
enum class EFortDualWieldSwingState : uint8
{
	None = 0,
	MainHand = 1,
	OffHand = 2,
	BothHands = 3,
};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Actor", "Input", "Components|Clothing", "Components|Base", "Components|PhysicsVolume", "Components|Activation", "Collision", "Replication", "Rendering", "Tags"))
class AFortWeaponPickaxeDualWieldAthena : public AFortWeaponPickaxeAthena, public IRespondsToVariantAction
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FName GetAnimTrailsOffhandFirstSocketName() const;

	UFUNCTION(BlueprintPure)
	UNiagaraSystem* GetAnimTrailsOffhandNiagaraAsset() const;

	UFUNCTION(BlueprintPure)
	UFXSystemComponent* GetAnimTrailsOffhandPSC() const;

	UFUNCTION(BlueprintPure)
	UParticleSystem* GetAnimTrailsOffhandPSCTemplate() const;

	UFUNCTION(BlueprintPure)
	FName GetAnimTrailsOffhandSecondSocketName() const;

	UFUNCTION(BlueprintPure)
	float GetAnimTrailsOffhandWidth() const;

	UFUNCTION(BlueprintPure)
	EFortDualWieldSwingState GetCurrentSwingState() const;

	UFUNCTION(BlueprintPure)
	FName GetIdleFXOffhandSocketName() const;

	UFUNCTION(BlueprintPure)
	UParticleSystemComponent* GetIdleOffhandPSC() const;

	UFUNCTION(BlueprintPure)
	FName GetSwingFXOffhandSocketName() const;

	UFUNCTION(BlueprintPure)
	UParticleSystemComponent* GetSwingOffhandPSC() const;

	UFUNCTION(BlueprintPure)
	bool GetUseAnimTrailsOffhandPSC() const;

	UFUNCTION(BlueprintPure, Category="Visual")
	USkeletalMeshComponentBudgeted* GetWeaponMeshOffhand() const;

	UFUNCTION(BlueprintPure)
	EFortDualWieldDataSource GetWieldStance() const;

	UFUNCTION(BlueprintPure)
	bool IsDualWielding() const;

	UFUNCTION(BlueprintPure)
	bool IsSingleWielding() const;

	UFUNCTION(BlueprintCallable)
	void SetCurrentSwingState(EFortDualWieldSwingState NewState);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Visual", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponentBudgeted> WeaponMeshOffhand;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> SwingOffhandVFX;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> IdleOffhandVFX;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> AnimTrailsOffhandPSC;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponPickaxeDualWieldAthena")
	TObjectPtr<UParticleSystem> AnimTrailsOffhandPSCTemplate;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponPickaxeDualWieldAthena")
	TObjectPtr<UNiagaraSystem> AnimTrailsOffhandNiagaraAsset;

	UPROPERTY()
	bool bUseAnimTrailsOffhandPSC;

	UPROPERTY()
	FName AnimTrailsOffhandFirstSocketName;

	UPROPERTY()
	FName AnimTrailsOffhandSecondSocketName;

	UPROPERTY()
	float AnimTrailsOffhandWidth;

	UPROPERTY()
	FName IdleFXOffhandSocketName;

	UPROPERTY()
	FName SwingFXOffhandSocketName;

	UPROPERTY()
	TObjectPtr<USoundBase> OffhandGenericImpactSound;

	UPROPERTY(EditAnywhere, Category="WeaponAnimation")
	TObjectPtr<UAnimMontage> PickaxeOffhandHarvestingMontage;

	UPROPERTY(EditAnywhere, Category="WeaponAnimation")
	TObjectPtr<UAnimMontage> PickaxeOffhandEquipMontage;

protected:
	UFUNCTION(BlueprintCallable)
	UFXSystemComponent* CreateAnimTrailOffhandFX();

	UFUNCTION(BlueprintPure)
	UFXSystemComponent* GetIdleOffhandVFXComponent() const;

	UFUNCTION(BlueprintPure)
	UFXSystemComponent* GetSwingOffhandVFXComponent() const;

	UFUNCTION()
	void OnRep_WieldStance();

	UPROPERTY(Transient)
	TArray<TObjectPtr<UNiagaraSystem>> OffhandImpactNiagaraPhysicalSurfaceEffectInstances;

	UPROPERTY(meta=(ArraySizeEnum="/Script/PhysicsCore.EPhysicalSurface"))
	TObjectPtr<USoundBase> OffhandImpactPhysicalSurfaceSounds[35];

	UPROPERTY(meta=(ArraySizeEnum="/Script/PhysicsCore.EPhysicalSurface"))
	TObjectPtr<UParticleSystem> OffhandImpactPhysicalSurfaceEffects[35];

	UPROPERTY(meta=(ArraySizeEnum="/Script/PhysicsCore.EPhysicalSurface"))
	TArray<TObjectPtr<UNiagaraSystem>> OffhandImpactNiagaraPhysicalSurfaceEffects;

	UPROPERTY(ReplicatedUsing=OnRep_WieldStance)
	EFortDualWieldDataSource CurrentWieldStance;

	UPROPERTY()
	TObjectPtr<UFortWeaponAdditionalData_SingleWieldState> EffectiveSingleWieldState;

	UPROPERTY()
	TObjectPtr<UFortWeaponAdditionalData_SingleWieldState> LastAppliedWieldState;

	UPROPERTY()
	TObjectPtr<UAnimMontage> OriginalEquipAnimation;

	UPROPERTY(Transient)
	TSubclassOf<UFortGameplayAbility> PrimaryFireAbilityOverrideClass;

private:
	UPROPERTY(Transient)
	TSoftObjectPtr<USkeletalMesh> SoftDualWieldFallbackMesh;

	UPROPERTY(Transient)
	TObjectPtr<USkeletalMesh> LoadedDualWieldFallbackMesh;

};

UCLASS(meta=(DisplayName="Single Wield Data"))
class UFortWeaponAdditionalData_SingleWieldState : public UFortWeaponAdditionalData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="State")
	FGameplayTag AssociatedTagVariant;

	UPROPERTY(EditAnywhere, Category="State", meta=(AssetBundles="Equipped,ItemsInInventoryInZone,ClientAthenaPreload"))
	TSoftClassPtr<UFortGameplayAbility> PrimaryFireAbility_InState;

	UPROPERTY(EditAnywhere, Category="State", meta=(AssetBundles="Equipped,ItemsInInventoryInZone,ClientAthenaPreload"))
	TSoftObjectPtr<UFortWeaponAnimSet> AnimSet_InState;

	UPROPERTY(EditAnywhere, Category="State", meta=(AssetBundles="Equipped,ItemsInInventoryInZone,ClientAthenaPreload"))
	TSoftObjectPtr<UAnimMontage> EquipMontage_InState;

	UPROPERTY(EditAnywhere, Category="State")
	bool bHideOffhandMesh;

	UPROPERTY(EditAnywhere, Category="FortWeaponAdditionalData_SingleWieldState", meta=(InlineEditConditionToggle="WeaponHandSocketOverride"))
	bool bUseWeaponHandSocketOverride;

	UPROPERTY(EditAnywhere, Category="State", meta=(EditCondition="bUseWeaponHandSocketOverride"))
	FName WeaponHandSocketOverride;

	UPROPERTY(EditAnywhere, Category="State|Preview")
	bool bUseSeparatePreviewOffsets;

	UPROPERTY(EditAnywhere, Category="State|Preview")
	FVector ImpactFxPreviewOffset;

	UPROPERTY(EditAnywhere, Category="State|Preview")
	FVector OffHandPreviewOffset;

	UPROPERTY(EditAnywhere, Category="State|Preview")
	FRotator OffHandPreviewRotation;

	UPROPERTY(EditAnywhere, Category="State|Preview")
	FRotator InitialPreviewRotation;

	UPROPERTY(EditAnywhere, Category="State|Preview")
	float FrontendPreviewScale;

	UPROPERTY(EditAnywhere, Category="State|Preview")
	FFortUICameraFrameTargetBounds CameraFramingBounds;

	UPROPERTY(EditAnywhere, Category="State")
	TEnumAsByte<EFortWeaponCoreAnimation::Type> AnimationStyleToUse;

	UPROPERTY()
	TSubclassOf<UFortGameplayAbility> LiveAbility;

	UPROPERTY()
	TObjectPtr<UFortWeaponAnimSet> LiveAnimSet;

	UPROPERTY()
	TObjectPtr<UAnimMontage> LiveMontage;

};

