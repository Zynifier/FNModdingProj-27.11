// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/SkeletalMeshActor.h"
#include "ActorMetadata/FortActorMetadataInterface.h"
#include "FortSkeletalMeshActor.generated.h"

UCLASS()
class FORTNITEGAME_API AFortSkeletalMeshActor : public ASkeletalMeshActor, public IFortActorMetadataInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, SaveGame, Category="FortSkeletalMeshActor")
	FName ActorTemplateID;

};

