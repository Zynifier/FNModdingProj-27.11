// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Building/SpatialGameplay/SpatialLoadingStateContext.h"
#include "GameFramework/GameplayMessageTypes.h"
#include "Items/FortCreativeRealEstatePlotItem.h"
#include "Playspaces/Components/FortPlayspaceComponent.h"
#include "PlayspaceComponent_CreativeToolsPermission.generated.h"

class UFortCreativeActorCollection;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UPlayspaceComponent_CreativeToolsPermission : public UFortPlayspaceComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API virtual bool DoesPlayerHavePermissionToEdit(const FUniqueNetIdRepl& UserRequestingPermission) const;

protected:
	UFUNCTION()
	FORTNITEGAME_API void OnRep_PlotPermissionsChanged();

	UFUNCTION()
	FORTNITEGAME_API void OnVolumeStateChanged(FEventMessageTag Channel, const FSpatialGamePlayActorLoadingStateUpdatedContext& StateContext);

	UPROPERTY(Transient, Replicated)
	FUniqueNetIdRepl AccountIdOfOwner;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PlotPermissionsChanged)
	FFortCreativePlotPermissionData PlotPermissions;

	UPROPERTY(Transient)
	bool bPermissionsSaveInProgress;

	UPROPERTY(EditDefaultsOnly, Category="PlayspaceComponent_CreativeToolsPermission")
	bool bAllowUnrestrictedPhoneControls;

	UPROPERTY(EditDefaultsOnly, Category="PlayspaceComponent_CreativeToolsPermission")
	bool bSkipPermissionsRequirement;

	UPROPERTY(EditDefaultsOnly, Category="PlayspaceComponent_CreativeToolsPermission")
	bool bShouldRestrictMoveToolToInteractionCollection;

	UPROPERTY(EditDefaultsOnly, Category="PlayspaceComponent_CreativeToolsPermission")
	TObjectPtr<UFortCreativeActorCollection> MoveToolInteractionCollection;

private:
	UPROPERTY(Transient)
	FFortCreativePlotPermissionData OldPermissions;

};

