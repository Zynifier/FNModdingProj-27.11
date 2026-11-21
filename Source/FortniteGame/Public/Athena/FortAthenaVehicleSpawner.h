// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/Actor.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/FortAthenaVehicle.h"
#include "FortAthenaVehicleSpawner.generated.h"

class AFortAthenaVehicle;
class UFortVehicleItemDefinition;
class UMaterialInterface;
class UObject;
class USceneComponent;
class USkeletalMeshComponent;

USTRUCT(BlueprintType)
struct FVehicleWeightedDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VehicleWeightedDef")
	TSoftObjectPtr<UFortVehicleItemDefinition> VehicleItemDef;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VehicleWeightedDef")
	FScalableFloat Weight;

};

UCLASS(MinimalAPI)
class AFortAthenaVehicleSpawner : public AActor, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UClass* GetVehicleClass() const;

	UFUNCTION(BlueprintNativeEvent)
	void OnConstructVehicle(AFortAthenaVehicle* Vehicle);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SpawnVehicle();

	UFUNCTION(BlueprintCallable)
	virtual AFortAthenaVehicle* SpawnVehicleWithConstruction(UClass* Class, const FTransform& Transform);

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<USceneComponent> DummyRoot;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> PreviewMeshComponent;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortAthenaVehicleSpawner")
	TSoftObjectPtr<UMaterialInterface> EditorPreviewMeshOverrideMaterial;
#endif

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

protected:
	UFUNCTION(BlueprintPure)
	bool GetForceSpawnAlways() const;

	UPROPERTY(EditAnywhere, Category="FortAthenaVehicleSpawner")
	TSoftObjectPtr<UFortVehicleItemDefinition> FortVehicleItemDef;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaVehicleSpawner")
	TArray<FVehicleWeightedDef> FortVehicleItemDefVariants;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAthenaVehicleSpawner")
	bool bCanSpawnWithMod;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAthenaVehicleSpawner")
	ESpawnActorCollisionHandlingMethod SpawnCollisionHandling;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAthenaVehicleSpawner")
	TEnumAsByte<EVehicleInitialOverlapBehavior::Type> InitialOverlapBehavior;

	UPROPERTY(EditInstanceOnly, Category="FortAthenaVehicleSpawner")
	bool bForceSpawnAlways;

	UPROPERTY(Transient)
	TObjectPtr<UFortVehicleItemDefinition> CachedFortVehicleItemDef;

	UPROPERTY(Transient)
	bool bIsVehicleItemDefCached;

	UPROPERTY(EditAnywhere, Category="VehicleSpawner")
	FGameplayTagContainer GameplayTags;

};

