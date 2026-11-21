// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "UObject/NoExportTypes.h"
#include "FortVehicleModConfig.generated.h"

class ABuildingGameplayActor;
class UFortVehicleModConfig;
class UGameplayEffect;
class UStaticMesh;

USTRUCT(BlueprintType)
struct FVehicleModBuildingGameplayActorAttachmentData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="VehicleModBuildingGameplayActorAttachmentData")
	TSubclassOf<ABuildingGameplayActor> AttachBGA;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="VehicleModBuildingGameplayActorAttachmentData")
	FName AttachSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="VehicleModBuildingGameplayActorAttachmentData")
	EAttachmentRule LocationRule;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="VehicleModBuildingGameplayActorAttachmentData")
	EAttachmentRule RotationRule;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="VehicleModBuildingGameplayActorAttachmentData")
	EAttachmentRule ScaleRule;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="VehicleModBuildingGameplayActorAttachmentData")
	bool bWeldSimulatedBodies;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="VehicleModBuildingGameplayActorAttachmentData")
	bool bBuildingGameplayActorDestroyedDisablesMod;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="VehicleModBuildingGameplayActorAttachmentData", meta=(ScriptName="OverrideScaleEnabled"))
	bool bOverrideScale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="VehicleModBuildingGameplayActorAttachmentData", meta=(EditCondition="bOverrideScale"))
	FVector OverrideScale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="VehicleModBuildingGameplayActorAttachmentData")
	TArray<FName> ToggleablePhysicsShapeNames;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="VehicleModBuildingGameplayActorAttachmentData")
	TSet<FName> ToggleablePhysicsShapeNamesIgnoringLandscape;

};

USTRUCT()
struct FVehicleModPhysicsShapeModifiers
{
	GENERATED_BODY()

public:
	UPROPERTY(NotReplicated)
	int32 BGAIndex;

	UPROPERTY(NotReplicated)
	FName PhysicsShapeName;

	UPROPERTY()
	int32 ShapeIndex;

	UPROPERTY()
	bool bShapeEnabled;

	UPROPERTY()
	bool bIgnoreLandscapeCollisions;

};

USTRUCT(BlueprintType)
struct FVehicleModStaticMeshAttachmentData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="VehicleModStaticMeshAttachmentData")
	TObjectPtr<UStaticMesh> StaticMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="VehicleModStaticMeshAttachmentData")
	FName AttachSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="VehicleModStaticMeshAttachmentData")
	FTransform RelativeTransform;

};

UCLASS()
class UFortVehicleModCollectedData : public UObject
{
	GENERATED_BODY()

};

UCLASS(Abstract, Config=Game, MinimalAPI, BlueprintType, Blueprintable)
class UFortVehicleModConfig : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="FortVehicleModConfig")
	FGameplayTag ModTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="FortVehicleModConfig")
	FScalableFloat ModEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="FortVehicleModConfig")
	TArray<FVehicleModBuildingGameplayActorAttachmentData> AttachedBuildingGameplayActors;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="FortVehicleModConfig")
	TArray<FVehicleModStaticMeshAttachmentData> AttachedStaticMeshes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="FortVehicleModConfig")
	bool bCanModBeReapplied;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Destruction|Collision")
	float AdditionalMaxHealthToDestroyProp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Destruction|Collision")
	float AdditionalMaxHealthToDestroyPropFast;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="FortVehicleModConfig")
	TSubclassOf<UGameplayEffect> AppliedGameplayEffect;

};

UCLASS()
class UFortVehicleModInstanceDataComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnRep_ModConfig();

	UFUNCTION()
	void OnRep_ModEnabled();

	UFUNCTION()
	void OnRep_PhysicsShapeModifiers();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ModConfig)
	TObjectPtr<UFortVehicleModConfig> ModConfig;

	UPROPERTY(Transient, Replicated)
	TArray<TWeakObjectPtr<ABuildingGameplayActor>> SpawnedBGAs;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PhysicsShapeModifiers)
	TArray<FVehicleModPhysicsShapeModifiers> PhysicsShapeModifiers;

	UPROPERTY(ReplicatedUsing=OnRep_ModEnabled)
	bool bModEnabled;

};

