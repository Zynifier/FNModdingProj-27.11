// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "Building/BuildingGameplayActor.h"
#include "BuildingGameplayActorPetrol.generated.h"

class AActor;
class ABuildingGameplayActorPetrol;
class UDecalComponent;
class UGameplayEffect;
class UMaterialInstanceDynamic;
class USphereComponent;

USTRUCT()
struct FSplatterCellIndex
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	int32 X;

	UPROPERTY(Transient)
	int32 Y;

	UPROPERTY(Transient)
	int32 Z;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingGameplayActorPetrol : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Collision", meta=(EditInline="true"))
	TObjectPtr<USphereComponent> SphereCollisionComponent;

	UPROPERTY(Transient)
	FSplatterCellIndex SplatterIndices;

	UPROPERTY(Transient)
	FVector StartingPos;

	UPROPERTY(Transient)
	FVector TargetPos;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Decal")
	TObjectPtr<UMaterialInstanceDynamic> MaterialInstanceDynamic;

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void ClientOnIgnite();

	UFUNCTION(BlueprintPure)
	float GetCurrentSize() const;

	UFUNCTION(BlueprintPure)
	int32 GetProjectileCount() const;

	UFUNCTION(BlueprintPure)
	float GetTargetSize() const;

	UFUNCTION()
	void IgniteTimerExpired();

	UFUNCTION(BlueprintImplementableEvent)
	void OnGrowBigger(const int32 NewProjectileCount);

	UFUNCTION(BlueprintImplementableEvent)
	void OnIgnite();

	UFUNCTION()
	void OnRep_Ignited(bool bPrevIgnited);

	UFUNCTION()
	void OnRep_PrevPetrol();

	UFUNCTION()
	void UpdateCurrentSize();

	UPROPERTY(EditAnywhere, Category="BuildingGameplayActorPetrol")
	TSubclassOf<UGameplayEffect> DamageEffectClass;

	UPROPERTY(EditAnywhere, Category="BuildingGameplayActorPetrol")
	TArray<TObjectPtr<ABuildingGameplayActorPetrol>> Neighbors;

	UPROPERTY(EditAnywhere, Category="BuildingGameplayActorPetrol")
	float IgniteRange;

	UPROPERTY(EditAnywhere, Category="BuildingGameplayActorPetrol")
	float DamageRange;

	UPROPERTY(Transient)
	float CurrentSize;

private:
	UFUNCTION()
	void OnRep_ProjectileCount(int32 PrevProjectileCount);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Decal", meta=(AllowPrivateAccess="true", EditInline="true", ExposeFunctionCategories="Decal,Rendering|Components|Decal"))
	TObjectPtr<UDecalComponent> SplatterDecal;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PrevPetrol)
	TWeakObjectPtr<AActor> PrevPetrol;

	UPROPERTY(Transient, Replicated)
	FVector ImpactDirection;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_Ignited)
	bool bIgnited;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ProjectileCount)
	int32 ProjectileCount;

	UPROPERTY(Transient)
	float SplatterMinDecalWidth;

	UPROPERTY(Transient)
	float SplatterMaxDecalWidth;

};

UCLASS()
class USplatterGridSystem : public UObject
{
	GENERATED_BODY()

};

