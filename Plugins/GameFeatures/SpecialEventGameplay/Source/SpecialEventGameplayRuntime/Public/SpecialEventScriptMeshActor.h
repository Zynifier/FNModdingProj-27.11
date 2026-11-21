// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Misc/DateTime.h"
#include "SpecialEventScriptMeshActor.generated.h"

class UMeshNetworkComponent;

UCLASS(Config=Game, BlueprintType, Blueprintable, HideCategories=("Actor", "Replication", "Tick", "ActorTick", "LOD", "Cooking", "Events", "HLOD", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class ASpecialEventScriptMeshActor : public AInfo
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void MeshRootClearCalendarTimer();

	UFUNCTION(Exec)
	void MeshRootLogCalendarTimer();

	UFUNCTION(Exec)
	void MeshRootResetEvent();

	UFUNCTION(Exec)
	void MeshRootStartCalendarTimer();

	UFUNCTION(Exec)
	void MeshRootStartCalendarTimerOnly();

	UFUNCTION(Exec)
	void MeshRootStartEvent();

protected:
	UFUNCTION()
	void OnRep_RootStartTime();

	UPROPERTY(ReplicatedUsing=OnRep_RootStartTime)
	FDateTime RootStartTime;

	UPROPERTY(EditDefaultsOnly, Config, Category="SpecialEventScriptMeshActor")
	FString CalendarEventName;

	UPROPERTY(EditDefaultsOnly, Config, Category="SpecialEventScriptMeshActor")
	float CalenderEventOffsetInSeconds;

	UPROPERTY(EditDefaultsOnly, Config, AdvancedDisplay, Category="SpecialEventScriptMeshActor")
	float EncryptionKeyDeliveryTimeOffset;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UMeshNetworkComponent> MeshNetworkComponent;

};

