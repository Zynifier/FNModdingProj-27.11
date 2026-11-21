// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralScatterContentSettings.h"
#include "ProceduralScatterActorContentSettings.generated.h"

class AActor;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Object", "Object"))
class UProceduralScatterActorContentSettings : public UProceduralScatterContentSettings
{
	GENERATED_BODY()

public:
	/** Hide generated actors from world outliner. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Actor")
	bool bHideFromWorldOutliner;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Object"))
class UProceduralScatterActorContentVariation : public UProceduralScatterContentVariation
{
	GENERATED_BODY()

public:
	/** The actor class to use for instances.
	  * You can make a Blueprint subclass of AActor to implement custom behavior and assign that class here. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variation")
	TSubclassOf<AActor> ActorClass;

#if WITH_EDITORONLY_DATA
	// Deprecated properties yard... where old properties go to die...

	UPROPERTY(meta=(DeprecatedProperty))
	FName VariationActorTag_DEPRECATED;
#endif

};

