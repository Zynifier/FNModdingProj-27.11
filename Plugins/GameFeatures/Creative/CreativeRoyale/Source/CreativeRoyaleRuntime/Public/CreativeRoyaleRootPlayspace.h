// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortDataRegistry/FortDataRegistryResolverScopeInterface.h"
#include "PlayspaceUsers.h"
#include "Playspaces/FortPlayspace.h"
#include "CreativeRoyaleRootPlayspace.generated.h"

class AFortPlayerControllerAthena;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNotifyPlotLoadComplete);

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class CREATIVEROYALERUNTIME_API ACreativeRoyaleRootPlayspace : public AFortPlayspace, public IFortDataRegistryResolverScopeInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual bool BuildDataRegistryResolverScope_Implementation(TArray<FName>& InOutResolverScopes, int32& InOutPriority) const;

protected:
	UFUNCTION()
	void Cheat_LoadEditorIsland();

	UFUNCTION()
	void TeleportPlayersToPlayerStarts();

	UFUNCTION()
	void TeleportPlayerToPlayerStart(const FPlayspaceUser& AddedUser);

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerControllerAthena> EditorIslandOwnerPlayerController;

private:
	UFUNCTION()
	void OnPlotLoadComplete();

	UFUNCTION()
	void OnRep_bHasPlotLoaded();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_bHasPlotLoaded)
	bool bHasPlotLoaded;

};

