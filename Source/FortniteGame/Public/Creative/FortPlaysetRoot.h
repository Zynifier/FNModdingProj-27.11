// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Misc/Guid.h"
#include "LevelSaveSpawnableInterface.h"
#include "FortPlaysetRoot.generated.h"

UCLASS()
class FORTNITEGAME_API AFortPlaysetRoot : public AActor, public ILevelSaveSpawnable
{
	GENERATED_BODY()

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	uint8 bBeingDragged : 1;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	uint8 bBeingTranslated : 1;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	uint8 bBeingRotatedOrScaled : 1;
#endif

	UPROPERTY(VisibleAnywhere, Category="FortPlaysetRoot")
	FGuid SavedActorGuid;

};

