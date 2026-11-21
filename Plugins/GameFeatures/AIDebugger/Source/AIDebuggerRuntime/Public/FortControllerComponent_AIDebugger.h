// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/SpatialGameplay/SpatialEnterExitContext.h"
#include "Components/FortControllerComponent.h"
#include "GameFramework/GameplayMessageTypes.h"
#include "FortControllerComponent_AIDebugger.generated.h"

class APlayerController;
class UAIDebuggerRendererComponent;
enum class EAIDebuggerVisualization : uint8;

UENUM(BlueprintType)
enum class EAIDebuggerVisualization : uint8
{
	INVALID = 0 UMETA(hidden),
	NavMesh = 1,
};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_AIDebugger : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UAIDebuggerRendererComponent* GetOrCreateRenderer() const;

	UFUNCTION(BlueprintPure)
	bool IsVisualizationEnabled(const EAIDebuggerVisualization VisualizationType) const;

	UFUNCTION()
	void OnPlayerExitedIsland(FEventMessageTag Channel, const FPlayerExitSpatialActorContextWithPawn& PlayerExitSpatialActorContext);

	UFUNCTION()
	void OnRep_EnabledVisualizers();

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void SetVisualizationEnable(const EAIDebuggerVisualization VisualizationType, const bool bEnable);

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void VisualizeNavMeshID(const int32 NavMeshID);

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void VisualizeNextNavMesh();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortControllerComponent_AIDebugger")
	APlayerController* OwnerPC;

	UPROPERTY(EditDefaultsOnly, Category="NavMesh")
	TSubclassOf<UAIDebuggerRendererComponent> NavMeshRendererComponentClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortControllerComponent_AIDebugger", meta=(Bitmask, BitmaskEnum="/Script/AIDebuggerRuntime.EAIDebuggerVisualization"))
	uint8 DefaultEnabledVisualizers;

	UPROPERTY(EditDefaultsOnly, Category="NavMesh")
	int32 DefaultNavDataIndexToDisplay;

private:
	UPROPERTY(Transient, ReplicatedUsing=OnRep_EnabledVisualizers)
	uint8 EnabledVisualizers;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="FortControllerComponent_AIDebugger", meta=(AllowPrivateAccess))
	uint8 NumNavMeshes;

};

