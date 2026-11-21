// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CurieComponent.h"
#include "FortCurieComponent.generated.h"

class AActor;

USTRUCT()
struct FFortCurieVoxelReplicationData
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, HideCategories=("Activation", "Collision", "Object", "Tags"), ClassGroup=("Curie"))
class UFortCurieComponent : public UCurieComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnRep_ActiveStateBitfield();

	UFUNCTION()
	void OnRep_ActiveVoxelReplicationData();

	UPROPERTY(Transient, Replicated)
	TObjectPtr<AActor> LastElectricityPropagationParent;

	UPROPERTY(Transient, Replicated)
	float LastElectrifiedTime;

	UPROPERTY(Transient, Replicated)
	float LastFireFXRelatedStateTime;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ActiveStateBitfield)
	uint16 ActiveStateBitfield;

	UPROPERTY(Transient)
	int32 TrackedNativeFXGlowFlags;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ActiveVoxelReplicationData)
	FFortCurieVoxelReplicationData ActiveVoxelReplicationData;

};

