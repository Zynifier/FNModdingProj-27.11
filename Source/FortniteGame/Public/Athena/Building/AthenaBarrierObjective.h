// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator_Barrier.h"
#include "Building/BuildingGameplayActor.h"
#include "AthenaBarrierObjective.generated.h"

class UMaterialInterface;
class UStaticMesh;
enum class EBarrierFoodTeam : uint8;
enum class EBarrierObjectiveDamageState : uint8;

USTRUCT()
struct FBarrierObjectiveDisplayData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="BarrierObjectiveDisplayData")
	TObjectPtr<UStaticMesh> HeadMesh;

	UPROPERTY(EditAnywhere, Category="BarrierObjectiveDisplayData")
	FVector MeshScale;

	UPROPERTY(EditAnywhere, Category="BarrierObjectiveDisplayData")
	FVector MeshRelativeOffset;

	UPROPERTY(EditAnywhere, Category="BarrierObjectiveDisplayData")
	TArray<TObjectPtr<UMaterialInterface>> MaterialsToSwap;

};

UCLASS(MinimalAPI, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AAthenaBarrierObjective : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	EBarrierFoodTeam GetFoodTeam() const;

	UFUNCTION(BlueprintPure)
	EBarrierObjectiveDamageState GetObjectiveDamageState() const;

	UFUNCTION(BlueprintPure)
	bool IsFriendlyTeam() const;

	UFUNCTION(BlueprintCallable)
	void OnGeneratorDestroyed();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void ApplyTimerGE(float TimerLength);

	UFUNCTION(BlueprintImplementableEvent)
	void OnHeadRotationSet(float NewYaw);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewDamageState(EBarrierObjectiveDamageState NewState);

	UFUNCTION()
	void OnRep_FoodTeam();

	UFUNCTION()
	void OnRep_HeadRotationYaw();

	UFUNCTION()
	void OnRep_ObjectiveDamageState();

	UFUNCTION(BlueprintImplementableEvent)
	void SetHeadMesh(UStaticMesh* NewMesh, FVector NewScale, FVector NewOffset, const TArray<UMaterialInterface*>& MaterialsToSwap);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateInGameHealth(float NewHealthPercent);

	UPROPERTY(EditAnywhere, Category="Display Data", meta=(ArraySizeEnum="/Script/FortniteGame.EBarrierFoodTeam"))
	FBarrierObjectiveDisplayData FoodDisplayData[2];

	UPROPERTY(ReplicatedUsing=OnRep_FoodTeam)
	EBarrierFoodTeam FoodTeam;

	UPROPERTY(ReplicatedUsing=OnRep_ObjectiveDamageState)
	EBarrierObjectiveDamageState ObjectiveDamageState;

	UPROPERTY(ReplicatedUsing=OnRep_HeadRotationYaw)
	float HeadRotationYaw;

	UPROPERTY(EditAnywhere, Replicated, Category="Damage Data")
	bool bAllowDamage;

	UPROPERTY(EditAnywhere, Category="Damage Data")
	FScalableFloat DamageFromSword;

};

