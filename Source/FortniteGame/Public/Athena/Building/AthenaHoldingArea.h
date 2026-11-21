// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "Building/BuildingGameplayActor.h"
#include "AthenaHoldingArea.generated.h"

class AAthenaHoldingArea;
class AFortPlayerPawnAthena;
class UStaticMeshComponent;

USTRUCT()
struct FIgnoredPlayerPawnDataEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AFortPlayerPawnAthena> IgnoredPawn;

};

USTRUCT()
struct FIgnoredPlayerPawnArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AAthenaHoldingArea> OwningHoldingArea;

	UPROPERTY()
	TArray<FIgnoredPlayerPawnDataEntry> IgnorePawnEntries;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AAthenaHoldingArea : public ABuildingGameplayActor
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_bHoldingAreaActive();

	UPROPERTY(EditAnywhere, Export, Category="Holding Area", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> MeshComp;

	UPROPERTY(ReplicatedUsing=OnRep_bHoldingAreaActive)
	uint8 bHoldingAreaActive : 1;

private:
	UFUNCTION()
	void OnRep_IgnoredPlayerPawns();

	UPROPERTY(ReplicatedUsing=OnRep_IgnoredPlayerPawns)
	FIgnoredPlayerPawnArray IgnoredPlayerPawns;

};

