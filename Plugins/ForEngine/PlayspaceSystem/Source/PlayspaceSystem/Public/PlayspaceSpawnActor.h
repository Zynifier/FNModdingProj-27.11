// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayspaceSpawnActor.generated.h"

class UArrowComponent;
class USceneComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Collision"), ClassGroup=("Common"))
class PLAYSPACESYSTEM_API APlayspaceSpawnActor : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<USceneComponent> SceneComponent;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UArrowComponent> ArrowComponent;
#endif

};

