// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Misc/Guid.h"
#include "ActorMetadata/FortActorMetadataInterface.h"
#include "LevelSaveSpawnableInterface.h"
#include "FortStaticMeshActor.generated.h"

class UNavLinkRenderingComponent;

UCLASS(MinimalAPI, HideCategories=("Input"), ShowCategories=("Input|MouseInput", "Input|TouchInput"), meta=(ScriptName="FortStaticMeshActor"))
class AFortStaticMeshActor : public AStaticMeshActor, public ILevelSaveSpawnable, public IFortActorMetadataInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	int32 LinkCompCount;

	UPROPERTY(EditInstanceOnly, Category="Navigation")
	bool bUseAutoNavmeshFlags;

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UNavLinkRenderingComponent> EdRenderComp;
#endif

	UPROPERTY(VisibleAnywhere, Category="FortStaticMeshActor")
	FGuid SavedActorGuid;

	UPROPERTY(VisibleAnywhere, SaveGame, Category="FortStaticMeshActor")
	FName ActorTemplateID;

};

