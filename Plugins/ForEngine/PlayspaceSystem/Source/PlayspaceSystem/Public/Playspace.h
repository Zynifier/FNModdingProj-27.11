// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "PlayspaceUsers.h"
#include "Playspace.generated.h"

class AGameplayVolume;
class APlayspace;
class UPlayspaceManagerComponent;

UENUM()
enum class EPlayspaceComponentCreationType : uint8
{
	// Adds itself onto the root playspace

	Root = 0,
	// Adds itself to whichever playspaces are at the specified location

	ByLocation = 1,
	// Adds itself to whichever playspaces fulfill the tag

	ByTags = 2,
};

UENUM()
enum class EPlayspaceCreationType : uint8
{
	// Adds itself as a child of the root or has logic within to insert based on its own criteria

	ChildOfRoot = 0,
	// Makes this Playspace the root and destroys the existing root

	RootDestroy = 1,
	// Makes this Playspace the root and the former root becomes its child

	RootInserted = 2,
	// Makes this playspace the root of there is no root, will not spawn if a root playspace already exists.

	RootDoNotClobber = 3,
};

UENUM()
enum class EWithinBoundsEvaluationType : uint8
{
	// Uses component overlaps. Accurate for complex shapes and uses collision profiles to determine overlaps.

	UseOverlaps = 0,
	// Use the bounds of the game play volume as a box to evaluate overlaps.

	UseBoxBounds = 1,
	// Uses box extents as a sphere to evaluate overlaps.

	UseSphereBounds = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNotifyEndMatch);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNotifyPlayspaceCreatedAndReady, APlayspace*, Playspace);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNotifyPlayspaceInitialized, APlayspace*, Playspace);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNotifyPlayspaceUserAdded, const FPlayspaceUser&, AddedUser);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNotifyPlayspaceUserRemoved, const FPlayspaceUser&, RemovedUser);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNotifyStartMatch);

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class APlayspace : public AInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category="Playspace")
	FNotifyPlayspaceUserAdded NotifyPlayspaceUserAdded;

	UPROPERTY(BlueprintAssignable, Category="Playspace")
	FNotifyPlayspaceUserRemoved NotifyPlayspaceUserRemoved;

	UPROPERTY(BlueprintAssignable, Category="Playspace")
	FNotifyPlayspaceInitialized NotifyPlayspaceInitialized;

	UPROPERTY(BlueprintAssignable, Category="Playspace")
	FNotifyPlayspaceInitialized NotifyPlayspaceCreatedAndReady;

	UPROPERTY(BlueprintAssignable, Category="Playspace")
	FNotifyStartMatch NotifyStartMatch;

	UPROPERTY(BlueprintAssignable, Category="Playspace")
	FNotifyEndMatch NotifyEndMatch;

protected:
	UFUNCTION()
	PLAYSPACESYSTEM_API void OnRep_bIsInitialized();

	UFUNCTION()
	PLAYSPACESYSTEM_API void OnRep_bMatchHasEnded();

	UFUNCTION()
	PLAYSPACESYSTEM_API virtual void OnRep_MatchStartTime();

	UFUNCTION()
	PLAYSPACESYSTEM_API void OnRep_PlayspaceUsers();

	UPROPERTY(EditDefaultsOnly, Category="Playspace")
	FGameplayTagContainer GameplayTags;

	UPROPERTY(EditDefaultsOnly, Category="Playspace")
	FGameplayTag RequestedPlayspaceParentTag;

	UPROPERTY(EditDefaultsOnly, Category="Playspace")
	TArray<TSubclassOf<APlayspace>> ChildPlayspaceClasses;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PlayspaceUsers)
	FPlayspaceUserList PlayspaceUsers;

	UPROPERTY(Transient, Replicated)
	TArray<TObjectPtr<APlayspace>> ChildPlayspaces;

	UPROPERTY(Transient)
	TArray<FUniqueNetIdRepl> PendingUsers;

	UPROPERTY(EditDefaultsOnly, Category="Playspace")
	bool bAutoStartMatchOnServerStart;

	UPROPERTY(EditDefaultsOnly, Category="Playspace")
	EWithinBoundsEvaluationType BoundsEvaluationType;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UPlayspaceManagerComponent> PlayspaceManagerCached;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="Playspace")
	TObjectPtr<AGameplayVolume> BoundGameplayVolume;

private:
	UPROPERTY(Transient, ReplicatedUsing=OnRep_bIsInitialized)
	bool bIsInitialized;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_bMatchHasEnded)
	bool bMatchHasEnded;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_MatchStartTime)
	float MatchStartTime;

};

