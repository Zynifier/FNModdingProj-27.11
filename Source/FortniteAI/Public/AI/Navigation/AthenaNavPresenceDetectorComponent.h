// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AI/Navigation/AthenaNavMesh.h"
#include "AthenaNavPresenceDetectorComponent.generated.h"

class AActor;
class AAthenaNavMesh;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNavMeshPresenceDetected, AActor*, NavActor, bool, bWasUndetectedBefore);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FNavMeshPresenceUndetected, AActor*, NavActor, bool, bWasDetectedBefore);

USTRUCT()
struct FNavMeshDetectedInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	AAthenaNavMesh* NavMesh;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UAthenaNavPresenceDetectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool HasValidNavMeshLocation() const;

protected:
	UFUNCTION()
	void OnNavMeshTilesUpdated(const FUpdatedNavMeshTiles& UpdatedNavMeshTiles);

	UPROPERTY(EditAnywhere, Category="AthenaNavPresenceDetectorComponent")
	bool bDisableUponNavMeshPresence;

	UPROPERTY(BlueprintReadOnly, Category="AthenaNavPresenceDetectorComponent")
	bool bHasValidNavMesh;

	UPROPERTY(EditAnywhere, Category="AthenaNavPresenceDetectorComponent")
	FName NavMeshNameToUse;

	UPROPERTY(Transient)
	TArray<FNavMeshDetectedInfo> NavMeshesInfo;

	UPROPERTY(BlueprintAssignable, meta=(DisplayName="On Nav Mesh Presence Detected Event"))
	FNavMeshPresenceDetected NavMeshPresenceDetected;

	UPROPERTY(BlueprintAssignable, meta=(DisplayName="On Nav Mesh Presence Undetected Event"))
	FNavMeshPresenceUndetected NavMeshPresenceUndetected;

};

