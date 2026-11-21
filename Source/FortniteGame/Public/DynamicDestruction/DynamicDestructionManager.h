// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Subsystems/WorldSubsystem.h"
#include "DynamicDestruction/DynamicDestructionObjectInterface.h"
#include "DynamicDestructionManager.generated.h"

class AActor;
class ABuildingSMActor;
class AFortPawn;
class IDynamicDestructionObjectInterface;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UNiagaraSystem;
class UStaticMeshComponent;
enum class EDynamicDestructionResourceType : uint8;

USTRUCT(BlueprintType)
struct FDynamicDestructionDamageData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicDestructionDamageData")
	FVector HitLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicDestructionDamageData")
	FVector HitSource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicDestructionDamageData")
	FVector HitVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicDestructionDamageData")
	FGameplayTagContainer DamageTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicDestructionDamageData")
	float DamageDealt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicDestructionDamageData")
	TWeakObjectPtr<AFortPawn> PawnInstigator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicDestructionDamageData")
	TWeakObjectPtr<AActor> DamageCauser;

};

USTRUCT()
struct FDynamicDestructionStaticMeshEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UMaterialInstanceDynamic>> MIDs;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UMaterialInterface>> OldMaterials;

};

USTRUCT()
struct FDynamicDestructionEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FDynamicDestructionStaticMeshEntry> ActiveStaticMeshEntries;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UStaticMeshComponent>> VisibiltyOnlyStatMeshComps;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UStaticMeshComponent>> ShadowProxyStatMeshComps;

};

USTRUCT(BlueprintType)
struct FDynamicDestructionMeshInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> StatMeshComp;

	UPROPERTY(Transient)
	int32 InstanceIndex;

};

USTRUCT()
struct FDynamicDestructionNeighboringBuildings
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TWeakObjectPtr<ABuildingSMActor> Building;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<ABuildingSMActor>> NeighboringBuildings;

};

UCLASS()
class UDynamicDestructionManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Dynamic Destruction", meta=(DefaultToSelf="DestroyedObject", DisplayName="End Dynamic Destruction"))
	static void EndDynamicDestructionBP(const TScriptInterface<IDynamicDestructionObjectInterface> DestroyedObject, bool bCanceled = false);

	UFUNCTION(BlueprintPure, Category="Dynamic Destruction", meta=(DefaultToSelf="DestroyedObject", DisplayName="Is Dynamic Destruction Active"))
	static bool IsDynamicDestructionActiveBP(const TScriptInterface<IDynamicDestructionObjectInterface> DestroyedObject);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Dynamic Destruction", meta=(DisplayName="Spawn Standalone Dynamic Destruction FX"))
	static void SpawnStandaloneDynamicDestructionFX(const FDynamicDestructionMeshInfo& MeshInfo, const FDynamicDestructionDamageData& DamageData, EDynamicDestructionResourceType ResourceTypeOverride = EDynamicDestructionResourceType::Invalid);

	UFUNCTION(BlueprintCallable, Category="Dynamic Destruction", meta=(DefaultToSelf="DestroyedObject", DisplayName="Start Dynamic Destruction"))
	static void StartDynamicDestructionBP(const TScriptInterface<IDynamicDestructionObjectInterface> DestroyedObject, const FDynamicDestructionDamageData& DamageData);

private:
	UFUNCTION()
	void OnDestroyedActorEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason);

	UPROPERTY(Transient)
	TMap<TObjectPtr<AActor>, FDynamicDestructionEntry> ActiveDynamicDestructionMap;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInterface> DynamicDestructionMaterialInst;

	UPROPERTY(Transient)
	TObjectPtr<UNiagaraSystem> DynamicDestructionNiagaraSystemInst;

};

