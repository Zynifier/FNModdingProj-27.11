// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "Athena/Modifiers/FortAthenaMutator_Barrier.h"
#include "Building/BuildingGameplayActor.h"
#include "AthenaBarrierFlag.generated.h"

class AAthenaBarrierObjective;
class UStaticMesh;
enum class EBarrierFlagState : uint8;
enum class EBarrierFoodTeam : uint8;

UENUM(BlueprintType)
enum class EBarrierFlagState : uint8
{
	FlagUp = 0,
	FlagDown = 1,
};

USTRUCT()
struct FBarrierFlagDisplayData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="BarrierFlagDisplayData")
	TObjectPtr<UStaticMesh> HeadMesh;

	UPROPERTY(EditAnywhere, Category="BarrierFlagDisplayData")
	FSlateBrush MiniMap_EnabledBrush;

	UPROPERTY(EditAnywhere, Category="BarrierFlagDisplayData")
	FSlateBrush MiniMap_DisabledBrush;

	UPROPERTY(EditAnywhere, Category="BarrierFlagDisplayData")
	FSlateBrush Compass_EnabledBrush;

	UPROPERTY(EditAnywhere, Category="BarrierFlagDisplayData")
	FSlateBrush Compass_DisabledBrush;

	UPROPERTY(EditAnywhere, Category="BarrierFlagDisplayData")
	FVector2D MapSize;

	UPROPERTY(EditAnywhere, Category="BarrierFlagDisplayData")
	FVector2D CompassSize;

	UPROPERTY(EditAnywhere, Category="BarrierFlagDisplayData")
	FVector MeshScale;

};

UCLASS(MinimalAPI, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AAthenaBarrierFlag : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UStaticMesh* GetHeadMesh() const;

	UFUNCTION(BlueprintPure)
	FVector GetMeshScale() const;

	UFUNCTION(BlueprintNativeEvent)
	AAthenaBarrierObjective* GetObjectiveActor() const;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void ClientSetIsFriendly(bool bIsFriendlyLlama);

	UFUNCTION(BlueprintImplementableEvent)
	void ClientSetLlamaRotation(FRotator NewDirection);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewFoodTeam(EBarrierFoodTeam NewFoodTeam);

	UFUNCTION()
	void OnRep_CurrentState();

	UFUNCTION()
	void OnRep_FoodTeam();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStateChange(EBarrierFlagState NewState);

	UPROPERTY(ReplicatedUsing=OnRep_CurrentState)
	EBarrierFlagState CurrentState;

	UPROPERTY(ReplicatedUsing=OnRep_FoodTeam)
	EBarrierFoodTeam FoodTeam;

	UPROPERTY(EditAnywhere, Category="AthenaBarrierFlag")
	FBarrierFlagDisplayData FoodDisplayData[2];

};

