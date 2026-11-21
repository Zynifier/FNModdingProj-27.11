// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Items/FortPickupEffect.h"
#include "FortPickupsParent.generated.h"

class UForceFeedbackEffect;
class UFortItem;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UParticleSystem;
class UParticleSystemComponent;
class UPrimitiveComponent;
class USkeletalMeshComponent;
class USpotLightComponent;
class UStaticMeshComponent;
enum class EFortRarity : uint8;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Actor", "Navigation", "Replication", "Actor", "Navigation", "Replication"))
class AFortPickupsParent : public AFortPickupEffect
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	EFortRarity GetClientCosmeticRarity(const UFortItem* Item) const;

	UFUNCTION(BlueprintPure)
	UFortItem* GetCosmeticPickupItem() const;

	UFUNCTION(BlueprintCallable)
	void OnPickedUpMIDSetup();

	UFUNCTION(BlueprintCallable)
	void SetHologramPickedUpParamsInternal(bool bTierZero);

	UFUNCTION(BlueprintCallable)
	void SetRarityColor(const TArray<FLinearColor>& RarityColors);

	UFUNCTION(BlueprintCallable)
	void SetupPickupLight(UPrimitiveComponent* PrimitiveComponent, USpotLightComponent* SpotLightComponent, const FLinearColor& LightColor);

	UFUNCTION(BlueprintCallable)
	UPrimitiveComponent* SetupPickupMesh();

	UFUNCTION(BlueprintCallable)
	void SetupStretchMIDsInternal();

	UPROPERTY(BlueprintReadOnly, Category="FortPickupsParent")
	TArray<TObjectPtr<UMaterialInstanceDynamic>> MIDs;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPickupsParent")
	TArray<TObjectPtr<UMaterialInterface>> CurrentMaterials;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPickupsParent")
	TArray<TObjectPtr<UMaterialInterface>> CurrentParentMaterials;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPickupsParent")
	TObjectPtr<UMaterialInterface> DefaultBaseMaterial;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPickupsParent")
	TObjectPtr<UMaterialInterface> LootGiftMaterialSkelMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPickupsParent")
	TObjectPtr<UMaterialInterface> LootGiftMaterialStaticMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPickupsParent")
	bool bIsBluGloPickup;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortPickupsParent")
	bool bIsSkeletalMeshComponent;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPickupsParent")
	bool bHasUniqueMaterialIds;

	UPROPERTY(BlueprintReadWrite, Category="FortPickupsParent")
	bool bActivateRarityParticleSystems;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortPickupsParent")
	bool bIsLootGiftForOthers;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortPickupsParent")
	TObjectPtr<UForceFeedbackEffect> PickupForceFeedback;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPickupsParent")
	TArray<FName> NamesOfMaterialsThatShouldNotBeReparented;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortPickupsParent")
	float CurrentViewDistance;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortPickupsParent")
	int32 PickupRarityLevel;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortPickupsParent")
	FLinearColor PickupRarityColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortPickupsParent")
	TArray<float> SweepBrightness;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortPickupsParent")
	TArray<float> SweepSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Export, Category="FortPickupsParent", meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> BackgroundParticleSystem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortPickupsParent")
	TObjectPtr<UParticleSystem> PickedUpTrailPS;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, AdvancedDisplay, Category="HiddenDefault")
	TArray<float> LifetimePickedUp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, AdvancedDisplay, Category="HiddenDefault")
	TArray<float> SparkleSpawnRatePickedUp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, AdvancedDisplay, Category="HiddenDefault")
	float ComponentRadiusScaled;

	UPROPERTY(EditDefaultsOnly, Category="DrawDistance")
	float CullDistanceStW;

	UPROPERTY(EditDefaultsOnly, Category="DrawDistance")
	float CullDistanceAthena;

	UPROPERTY(EditDefaultsOnly, Category="DrawDistance")
	float CullDistanceBacchus;

	UPROPERTY(EditDefaultsOnly, Category="DrawDistance")
	float BackgroundParticleSystemComponentCullDistance;

	UPROPERTY(EditDefaultsOnly, Category="DrawDistance")
	FVector MeshPivotOffset;

	UPROPERTY(EditDefaultsOnly, Category="DrawDistance")
	FRotator MeshRotationBias;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="HologramSetup")
	float PickedUpFadeInTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="HologramSetup")
	float PickedUpHoldTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="HologramSetup")
	float PickedUpFadeOutTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="HologramSetup")
	float PickedUpSweepSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="HologramSetup")
	float PickedUpDelayBeforeGlow;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="FortPickupsParent", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> SkelMeshComponent;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="FortPickupsParent", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="FortPickupsParent", meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> MeshPrimitiveComponent;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="FortPickupsParent", meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> BackgroundParticleSystemComponent;

};

