// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "FortPhysicsObjectManager.generated.h"

class AFortGameStateAthena;
class AFortPhysicsObjectManager;
class UFortPhysicsObjectComponent;
class UFortPlaylist;
class UObject;

UENUM()
enum class EFortPhysicsObjectActivationType : uint8
{
	Unset = 0,
	// Activation type has not been specified

	Normal = 1,
	// Activate as soon as perf will allow

	Lazy = 2,
	// Mark this activation as a candidate for delayed activation

	AlwaysInstant = 3,
};

USTRUCT()
struct FFortPhysicsObjectActivationData
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Actor", "Actor|Tick", "Replication", "Physics", "Events", "Cooking", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortPhysicsObjectManager : public AInfo
{
	GENERATED_BODY()

public:
	UFUNCTION()
	static bool GetPhysicsObjectManager(const UObject* WorldContextObject, AFortPhysicsObjectManager*& Manager);

private:
	UFUNCTION()
	void OnPlaylistDataLoaded(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags);

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortPhysicsObjectComponent>> PhysicsObjects;

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortPhysicsObjectComponent>> PhysicsObjectsAwake;

	UPROPERTY(Transient)
	TArray<FFortPhysicsObjectActivationData> PhysicsObjectActivationQueue;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FScalableFloat EnablePhysicsUserDataSetup;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FScalableFloat EnableUnifiedDamageModel;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FScalableFloat EnablePropsSimulateOnBuildingDetachment;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FScalableFloat EnableVehicleToObjectActivation;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FScalableFloat EnableObjectToObjectActivation;

};

